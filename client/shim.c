// libsteam_api.so — SHIM over Valve's real androidarm64 bootstrap.
//
// The real SDK 1.65 library (bundled as libsteam_api_real.so) dropped a set of
// legacy flat trampoline symbols that StS2's Steamworks.NET P/Invokes still expect.
// This shim:
//   - loads the real lib and forwards the symbols to it
//   - applies in-memory runtime patches (from a private config, see patchconf.h) to libsteamclient.so
//   - spoofs getuid()/geteuid() -> 0
//   - redirects open()/openat()/shm_open() to /data/user/0/com.steamruntime.dev/files/ipc/u0-ValveIPCSharedObj-Steam (fallback /data/local/tmp)
//   - writes steam_appid.txt (2868840) into likely CWDs at load time
//   - stubs legacy/unused flat interface functions safely

#include <dlfcn.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <android/log.h>
#include "patchconf.h"

#define APPID "2868840"
#define LOG_TAG "StS2Shim"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static void install_steam_lifecycle_hooks(void);

static void *real_handle(void) {
    static void *h = NULL;
    if (!h) {
        h = dlopen("libsteam_api.so", RTLD_NOW | RTLD_GLOBAL);
        if (!h) {
            h = dlopen("./libsteam_api.so", RTLD_NOW | RTLD_GLOBAL);
        }
        if (h) {
            LOGI("libsteam_api.so dlopened successfully: %p", h);
        } else {
            LOGE("Failed to dlopen libsteam_api.so: %s", dlerror());
        }
    }
    return h;
}

// Module base helper
static uintptr_t GetModuleBase(const char* module_name) {
    FILE* fp = fopen("/proc/self/maps", "r");
    if (!fp) return 0;
    char line[512];
    uintptr_t base = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, module_name)) {
            base = (uintptr_t)strtoull(line, NULL, 16);
            break;
        }
    }
    fclose(fp);
    return base;
}

static char s_steamInstallPath[256] = "/data/local/tmp";

// Runtime patches to the locally supplied libsteamclient.so. The offsets and instruction words are
// not part of this repo; they are read from a private steamclient_patches.conf (see patchconf.h).
static void PatchSteamClientPaths(void) {
    uintptr_t clientBase = GetModuleBase("libsteamclient.so");
    if (!clientBase) {
        LOGW("Cannot find libsteamclient.so base in /proc/self/maps yet");
        return;
    }
    LOGI("[+] libsteamclient.so base: %p", (void*)clientBase);
    int n = pc_apply(clientBase, s_steamInstallPath);
    if (n == 0) LOGW("No patches applied (steamclient_patches.conf missing or empty)");
    else LOGI("[+] Applied %d patch entries; install path '%s'", n, s_steamInstallPath);
}

// Hook getuid/geteuid to always return 0 so Valve IPC uses UID 0
uid_t getuid(void) {
    return 0;
}

uid_t geteuid(void) {
    return 0;
}

// Hook open & openat to redirect Valve IPC shared memory to /data/user/0/com.steamruntime.dev/files/ipc/u0-ValveIPCSharedObj-Steam (fallback /data/local/tmp)
int open(const char* pathname, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = (mode_t)va_arg(args, int);
        va_end(args);
    }

    const char* real_path = pathname;
    if (pathname && strstr(pathname, "ValveIPCSharedObj-Steam") != NULL) {
        static const char new_path[] = "/data/user/0/com.steamruntime.dev/files/ipc/u0-ValveIPCSharedObj-Steam";
        static const char old_path[] = "/data/local/tmp/u0-ValveIPCSharedObj-Steam";
        real_path = (access(new_path, 0) != 0) ? old_path : new_path;
        LOGI("[HOOK] open('%s') redirected -> '%s'", pathname, real_path);
    }

    typedef int (*real_open_fn)(const char*, int, ...);
    static real_open_fn real_open = NULL;
    if (!real_open) {
        void* libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_open = (real_open_fn)dlsym(libc, "open");
    }
    return real_open ? real_open(real_path, flags, mode) : -1;
}

int openat(int dirfd, const char* pathname, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = (mode_t)va_arg(args, int);
        va_end(args);
    }

    const char* real_path = pathname;
    if (pathname && strstr(pathname, "ValveIPCSharedObj-Steam") != NULL) {
        static const char new_path[] = "/data/user/0/com.steamruntime.dev/files/ipc/u0-ValveIPCSharedObj-Steam";
        static const char old_path[] = "/data/local/tmp/u0-ValveIPCSharedObj-Steam";
        real_path = (access(new_path, 0) != 0) ? old_path : new_path;
        LOGI("[HOOK] openat('%s') redirected -> '%s'", pathname, real_path);
    }

    typedef int (*real_openat_fn)(int, const char*, int, ...);
    static real_openat_fn real_openat = NULL;
    if (!real_openat) {
        void* libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_openat = (real_openat_fn)dlsym(libc, "openat");
    }
    return real_openat ? real_openat(dirfd, real_path, flags, mode) : -1;
}

// Hook __system_property_get to feed "lepton.steamclient.path" to Valve's SDK
int __system_property_get(const char *name, char *value) {
    if (name && strcmp(name, "lepton.steamclient.path") == 0) {
        LOGI("__system_property_get(lepton.steamclient.path) intercepted -> libsteamclient.so");
        strcpy(value, "libsteamclient.so");
        return (int)strlen(value);
    }
    typedef int (*real_prop_fn)(const char *, char *);
    static real_prop_fn real_prop = NULL;
    if (!real_prop) {
        void *libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_prop = (real_prop_fn)dlsym(libc, "__system_property_get");
    }
    return real_prop ? real_prop(name, value) : 0;
}

// Hook shm_open so libsteamclient.so can discover the IPC TCP port.
int shm_open(const char *name, int oflag, mode_t mode) {
    if (name && strstr(name, "ValveIPCSharedObj-Steam") != NULL) {
        static const char new_path[] = "/data/user/0/com.steamruntime.dev/files/ipc/u0-ValveIPCSharedObj-Steam";
        static const char old_path[] = "/data/local/tmp/u0-ValveIPCSharedObj-Steam";
        const char *mirror = (access(new_path, 0) != 0) ? old_path : new_path;
        LOGI("shm_open('%s') -> mirror '%s'", name, mirror);
        int fd = open(mirror, O_RDONLY);
        if (fd >= 0) {
            LOGI("shm_open mirror opened OK fd=%d", fd);
            return fd;
        }
        LOGW("shm_open mirror open failed (errno=%d), falling through", fd);
    }
    typedef int (*real_shm_open_fn)(const char *, int, mode_t);
    static real_shm_open_fn real_shm = NULL;
    if (!real_shm) {
        void *libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_shm = (real_shm_open_fn)dlsym(libc, "shm_open");
    }
    if (real_shm) return real_shm(name, oflag, mode);
    return -1;
}

#include <malloc.h>
#ifndef M_BIONIC_SET_HEAP_TAGGING_LEVEL
#define M_BIONIC_SET_HEAP_TAGGING_LEVEL (-204)
#endif
#ifndef M_HEAP_TAGGING_LEVEL_NONE
#define M_HEAP_TAGGING_LEVEL_NONE 0
#endif
extern int mallopt(int __param, int __val);

void free(void *ptr) {
    static void (*real_free)(void*) = NULL;
    if (!real_free) {
        real_free = (void (*)(void*))dlsym(RTLD_NEXT, "free");
    }
    if (!ptr) return;
    uintptr_t u = (uintptr_t)ptr;
    if ((u >> 56) != 0) {
        void *clean = (void*)(u & 0x00ffffffffffffffULL);
        LOGW("[HOOK free] Stripping top byte tag: %p -> %p", ptr, clean);
        ptr = clean;
    }
    if (real_free) real_free(ptr);
}

void *realloc(void *ptr, size_t size) {
    static void *(*real_realloc)(void*, size_t) = NULL;
    if (!real_realloc) {
        real_realloc = (void *(*)(void*, size_t))dlsym(RTLD_NEXT, "realloc");
    }
    if (ptr) {
        uintptr_t u = (uintptr_t)ptr;
        if ((u >> 56) != 0) {
            void *clean = (void*)(u & 0x00ffffffffffffffULL);
            LOGW("[HOOK realloc] Stripping top byte tag: %p -> %p", ptr, clean);
            ptr = clean;
        }
    }
    return real_realloc ? real_realloc(ptr, size) : NULL;
}

static int64_t dummy_vtable_noop(void) {
    return 0;
}

static void *dummy_vtable[128] = {0};
static void *dummy_obj = dummy_vtable;

__attribute__((constructor)) static void shim_ctor(void) {
    for (int i = 0; i < 128; i++) {
        dummy_vtable[i] = (void*)dummy_vtable_noop;
    }

    // Disable Android heap pointer tagging (TBI / Scudo tagged pointers)
    // so desktop ARM64 libraries (libsteamclient.so) don't trigger tag truncation aborts
    mallopt(M_BIONIC_SET_HEAP_TAGGING_LEVEL, M_HEAP_TAGGING_LEVEL_NONE);
    mallopt(-201, 0);
    LOGI("shim_ctor: disabled heap pointer tagging via mallopt");
    LOGI("shim_ctor initializing native Steam dependencies...");

    setenv("SteamAppId", APPID, 1);
    setenv("SteamGameId", APPID, 1);

    // Preload companion Steam libraries
    dlopen("libtier0_s.so", RTLD_NOW | RTLD_GLOBAL);
    dlopen("libvstdlib_s.so", RTLD_NOW | RTLD_GLOBAL);
    dlopen("libsteamnetworkingsockets.so", RTLD_NOW | RTLD_GLOBAL);
    dlopen("steamservice.so", RTLD_NOW | RTLD_GLOBAL);
    void *client_h = dlopen("libsteamclient.so", RTLD_NOW | RTLD_GLOBAL);
    if (client_h) {
        LOGI("libsteamclient.so preloaded successfully: %p", client_h);
        PatchSteamClientPaths();
    } else {
        LOGW("libsteamclient.so preload deferred: %s", dlerror());
    }

    const char *candidates[] = {
        "./steam_appid.txt",
        "steam_appid.txt",
        "/data/data/com.game.sts2launcher/files/steam_appid.txt",
        "/data/data/com.game.sts2launcher/files/game/steam_appid.txt",
        "/data/user/0/com.game.sts2launcher/files/steam_appid.txt",
        "/data/user/0/com.game.sts2launcher/files/game/steam_appid.txt",
        "/sdcard/Android/data/com.game.sts2launcher/files/steam_appid.txt",
        "/sdcard/Android/data/com.game.sts2launcher/files/game/steam_appid.txt",
        "/storage/emulated/0/StS2Launcher/Game/steam_appid.txt",
        "/storage/emulated/0/StS2Launcher/steam_appid.txt",
        "/data/data/com.game.sts2launcher.modmanager/files/steam_appid.txt",
        "/data/data/com.game.sts2launcher.modmanager/files/game/steam_appid.txt",
        "/data/user/0/com.game.sts2launcher.modmanager/files/steam_appid.txt",
        "/data/user/0/com.game.sts2launcher.modmanager/files/game/steam_appid.txt",
        "/sdcard/Android/data/com.game.sts2launcher.modmanager/files/steam_appid.txt",
        "/sdcard/Android/data/com.game.sts2launcher.modmanager/files/game/steam_appid.txt",
        "/storage/emulated/0/StS2LauncherMM/Game/steam_appid.txt",
        "/storage/emulated/0/StS2LauncherMM/steam_appid.txt",
        0
    };
    for (int i = 0; candidates[i]; i++) {
        FILE *f = fopen(candidates[i], "w");
        if (f) { fputs(APPID, f); fclose(f); }
    }

    void *api_h = real_handle();
    if (api_h) {
        extern void init_all_trampolines(void *h);
        init_all_trampolines(api_h);
        install_steam_lifecycle_hooks();
        LOGI("init_all_trampolines: initialized SDK trampolines");
    }
}

// ---- forwarded to the real library -----------------------------------------

typedef int (*InternalInitFn)(const char *, char *);

// Steamworks.NET can initialize through both the launcher and the game in the
// same process. Keep one underlying Steam client registration and make a
// single lifecycle shutdown release it.
static pthread_mutex_t g_steam_lifecycle_lock = PTHREAD_MUTEX_INITIALIZER;
static int g_steam_initialized = 0;
static unsigned int g_init_calls = 0;
static unsigned int g_steamapi_init_calls = 0;
static unsigned int g_init_real_calls = 0;
static unsigned int g_shutdown_calls = 0;
static unsigned int g_release_user_calls = 0;
static unsigned int g_release_pipe_calls = 0;
static void *g_real_shutdown = NULL;
static void *g_real_release_user = NULL;
static void *g_real_release_pipe = NULL;
static void *g_steam_client_self = NULL;
static int g_steam_user = 0;
static int g_steam_pipe = 0;
extern void *p_SteamAPI_Shutdown;
extern void *p_SteamAPI_ISteamClient_ReleaseUser;
extern void *p_SteamAPI_ISteamClient_BReleaseSteamPipe;
extern void *p_SteamAPI_GetHSteamUser;
extern void *p_SteamAPI_GetHSteamPipe;

static void shim_steam_shutdown(void) {
    unsigned int n = __sync_add_and_fetch(&g_shutdown_calls, 1);
    pthread_mutex_lock(&g_steam_lifecycle_lock);
    int do_shutdown = g_steam_initialized;
    g_steam_initialized = 0;
    pthread_mutex_unlock(&g_steam_lifecycle_lock);
    LOGI("SteamAPI_Shutdown #%u pid=%d initialized=%d forward=%d", n, (int)getpid(), do_shutdown, do_shutdown && g_real_shutdown != NULL);
    if (do_shutdown) {
        // StS2's managed Steamworks layer can leave the user/pipe handle live
        // when the Activity is removed from Recents. The global Shutdown call
        // alone closes the transport but does not send the client's LCT=0
        // update in that path. Explicitly release the same client handles
        // first; SteamAPI_Shutdown remains responsible for global SDK cleanup.
        if (p_SteamAPI_GetHSteamUser) g_steam_user = ((int (*)(void))p_SteamAPI_GetHSteamUser)();
        if (p_SteamAPI_GetHSteamPipe) g_steam_pipe = ((int (*)(void))p_SteamAPI_GetHSteamPipe)();
        if (g_steam_client_self && g_steam_user && g_steam_pipe && g_real_release_user) {
            LOGI("Explicit Steam user release pid=%d user=%d pipe=%d", (int)getpid(), g_steam_user, g_steam_pipe);
            ((void (*)(void *, int, int))g_real_release_user)(g_steam_client_self, g_steam_pipe, g_steam_user);
        } else {
            LOGW("Skipping explicit Steam user release client=%d user=%d pipe=%d release=%d",
                 g_steam_client_self != NULL, g_steam_user, g_steam_pipe, g_real_release_user != NULL);
        }
        if (g_steam_client_self && g_steam_pipe && g_real_release_pipe) {
            int released = ((int (*)(void *, int))g_real_release_pipe)(g_steam_client_self, g_steam_pipe);
            LOGI("Explicit Steam pipe release pid=%d pipe=%d result=%d", (int)getpid(), g_steam_pipe, released);
        } else {
            LOGW("Skipping explicit Steam pipe release client=%d pipe=%d release=%d",
                 g_steam_client_self != NULL, g_steam_pipe, g_real_release_pipe != NULL);
        }
        if (g_real_shutdown) ((void (*)(void))g_real_shutdown)();
    }
}

static void shim_steam_release_user(void *self, int user, int pipe) {
    unsigned int n = __sync_add_and_fetch(&g_release_user_calls, 1);
    LOGI("SteamAPI_ISteamClient_ReleaseUser #%u pid=%d user=%d pipe=%d", n, (int)getpid(), user, pipe);
    if (g_real_release_user) ((void (*)(void *, int, int))g_real_release_user)(self, user, pipe);
}

static int shim_steam_release_pipe(void *self, int pipe) {
    unsigned int n = __sync_add_and_fetch(&g_release_pipe_calls, 1);
    LOGI("SteamAPI_ISteamClient_BReleaseSteamPipe #%u pid=%d pipe=%d", n, (int)getpid(), pipe);
    if (g_real_release_pipe) return ((int (*)(void *, int))g_real_release_pipe)(self, pipe);
    return 0;
}

static void install_steam_lifecycle_hooks(void) {
    g_real_shutdown = p_SteamAPI_Shutdown;
    g_real_release_user = p_SteamAPI_ISteamClient_ReleaseUser;
    g_real_release_pipe = p_SteamAPI_ISteamClient_BReleaseSteamPipe;
    p_SteamAPI_Shutdown = (void *)shim_steam_shutdown;
    p_SteamAPI_ISteamClient_ReleaseUser = (void *)shim_steam_release_user;
    p_SteamAPI_ISteamClient_BReleaseSteamPipe = (void *)shim_steam_release_pipe;
    LOGI("Steam lifecycle hooks installed shutdown=%d release_user=%d release_pipe=%d",
         g_real_shutdown != NULL, g_real_release_user != NULL, g_real_release_pipe != NULL);
}

int SteamInternal_SteamAPI_Init(const char *version, char *err) {
    unsigned int n = __sync_add_and_fetch(&g_init_calls, 1);
    pthread_mutex_lock(&g_steam_lifecycle_lock);
    int already_initialized = g_steam_initialized;
    pthread_mutex_unlock(&g_steam_lifecycle_lock);
    LOGI("SteamAPI_Init request #%u pid=%d version=%s already_initialized=%d", n, (int)getpid(), version ? version : "NULL", already_initialized);
    if (already_initialized) return 0;
    setenv("SteamAppId", APPID, 1);
    setenv("SteamGameId", APPID, 1);

    PatchSteamClientPaths();

    void *h = real_handle();
    if (!h) {
        if (err) strcpy(err, "Failed to load libsteam_api_real.so");
        return 1;
    }
    InternalInitFn fn = (InternalInitFn)dlsym(h, "SteamInternal_SteamAPI_Init");
    if (!fn) {
        LOGE("SteamInternal_SteamAPI_Init not found in real lib: %s", dlerror());
        if (err) strcpy(err, "SteamInternal_SteamAPI_Init not found in real lib");
        return 1;
    }
    char local_err[1024] = {0};
    int r = fn(version, local_err);
    unsigned int real_n = __sync_add_and_fetch(&g_init_real_calls, 1);
    if (r == 0) {
        pthread_mutex_lock(&g_steam_lifecycle_lock);
        g_steam_initialized = 1;
        pthread_mutex_unlock(&g_steam_lifecycle_lock);
    }
    LOGI("SteamAPI_Init real call #%u returned=%d pid=%d err=%s", real_n, r, (int)getpid(), local_err);
    if (err && local_err[0]) {
        strncpy(err, local_err, 1024);
    }
    return r;
}

int SteamAPI_InitFlat(char *err) {
    LOGI("*** SteamAPI_InitFlat() CALLED ***");
    return SteamInternal_SteamAPI_Init(NULL, err);
}

int SteamAPI_Init(void) {
    unsigned int n = __sync_add_and_fetch(&g_steamapi_init_calls, 1);
    LOGI("SteamAPI_Init #%u pid=%d", n, (int)getpid());
    char err[1024] = {0};
    int r = SteamInternal_SteamAPI_Init(NULL, err);
    return r == 0 ? 1 : 0;
}

int SteamAPI_RestartAppIfNecessary(uint32_t appid) {
    (void)appid;
    LOGI("SteamAPI_RestartAppIfNecessary(%u) -> returning 0 (no-op)", appid);
    return 0; // false = do not restart
}

int SteamAPI_IsSteamRunning(void) {
    return 1;
}

int SteamAPI_ISteamUtils_GetEnteredGamepadTextInput(void *s, char *pchText, uint32_t cchText) {
    (void)s; (void)pchText; (void)cchText;
    return 0;
}

uint32_t SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(void *s) {
    (void)s;
    return 0;
}

int SteamAPI_ISteamUtils_ShowGamepadTextInput(void *s, int eInputMode, int eLineInputMode, const char *pchDescription, uint32_t unCharMax, const char *pchExistingText) {
    (void)s; (void)eInputMode; (void)eLineInputMode; (void)pchDescription; (void)unCharMax; (void)pchExistingText;
    return 0;
}

int SteamAPI_ISteamUtils_ShowFloatingGamepadTextInput(void *s, int eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight) {
    (void)s; (void)eKeyboardMode; (void)nTextFieldXPosition; (void)nTextFieldYPosition; (void)nTextFieldWidth; (void)nTextFieldHeight;
    return 0;
}

int SteamAPI_ISteamUtils_DismissGamepadTextInput(void *s) {
    (void)s;
    return 0;
}

int SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput(void *s) {
    (void)s;
    return 0;
}

// The game's Steamworks.NET asks for older interface versions (e.g. SteamFriends017,
// SteamNetworkingSockets012, SteamUtils010) than the Android libsteam_api.so flat layer was
// compiled against (SteamFriends018, ...Sockets013, SteamUtils011). The flat functions call
// through the newer vtable layout, so an older interface object yields garbage from every
// method past the shared prefix. Hand out the version the flat layer expects instead.
static const struct { const char *base; const char *flat_version; } k_flat_versions[] = {
    { "SteamFriends",               "SteamFriends018" },
    { "SteamNetworkingSockets",     "SteamNetworkingSockets013" },
    { "SteamNetworkingUtils",       "SteamNetworkingUtils004" },
    { "SteamNetworkingMessages",    "SteamNetworkingMessages002" },
    { "SteamNetworking",            "SteamNetworking006" },
    { "SteamUtils",                 "SteamUtils011" },
    { "SteamUser",                  "SteamUser023" },
    { "SteamMatchMaking",           "SteamMatchMaking009" },
    { "STEAMAPPS_INTERFACE_VERSION",        "STEAMAPPS_INTERFACE_VERSION009" },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION", "STEAMREMOTESTORAGE_INTERFACE_VERSION016" },
    { "STEAMUSERSTATS_INTERFACE_VERSION",   "STEAMUSERSTATS_INTERFACE_VERSION013" },
};

static const char *flat_version(const char *requested) {
    if (!requested) return requested;
    size_t n = strlen(requested);
    // Version strings are <base><3 digits>; compare the base exactly so that
    // "SteamNetworking" does not swallow "SteamNetworkingSockets".
    if (n < 4) return requested;
    for (size_t i = 0; i < sizeof(k_flat_versions) / sizeof(k_flat_versions[0]); i++) {
        size_t bl = strlen(k_flat_versions[i].base);
        if (bl == n - 3 && strncmp(requested, k_flat_versions[i].base, bl) == 0) {
            if (strcmp(requested, k_flat_versions[i].flat_version) != 0)
                LOGI("[+] interface version remap '%s' -> '%s'", requested, k_flat_versions[i].flat_version);
            return k_flat_versions[i].flat_version;
        }
    }
    return requested;
}

static void *call_client_getter(const char *name, void *self, int32_t a, int32_t b, const char *c) {
    if (self) g_steam_client_self = self;
    if (strcmp(name, "SteamAPI_ISteamClient_GetISteamUser") == 0) {
        g_steam_user = a;
        g_steam_pipe = b;
    }
    c = flat_version(c);
    void *h = real_handle();
    typedef void *(*GetterFn)(void*, int32_t, int32_t, const char*);
    GetterFn fn = h ? (GetterFn)dlsym(h, name) : NULL;
    void *res = fn ? fn(self, a, b, c) : NULL;
    LOGI("[+] %s('%s') -> %p", name, c ? c : "NULL", res);
    if (!res) {
        LOGW("[!] %s('%s') returned NULL, returning safe dummy fallback", name, c ? c : "NULL");
        return &dummy_obj;
    }
    return res;
}

// SteamUtils is the one client getter whose flat API takes only hSteamPipe
// before the interface-version string. Keep its ABI separate from the
// four-argument user/pipe/version getters above.
static void *call_client_getter_utils(void *self, int32_t hSteamPipe, const char *version) {
    version = flat_version(version);
    void *h = real_handle();
    typedef void *(*GetterFn)(void*, int32_t, const char*);
    GetterFn fn = h ? (GetterFn)dlsym(h, "SteamAPI_ISteamClient_GetISteamUtils") : NULL;
    void *res = fn ? fn(self, hSteamPipe, version) : NULL;
    LOGI("[+] SteamAPI_ISteamClient_GetISteamUtils('%s') -> %p", version ? version : "NULL", res);
    if (!res) {
        LOGW("[!] SteamAPI_ISteamClient_GetISteamUtils('%s') returned NULL, returning safe dummy fallback",
             version ? version : "NULL");
        return &dummy_obj;
    }
    return res;
}

#define DEFINE_CLIENT_GETTER(name) \
    void *name(void *self, int32_t a, int32_t b, const char *c) { \
        return call_client_getter(#name, self, a, b, c); \
    }

DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamApps)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamController)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamFriends)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamGameSearch)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamGameServer)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamGameServerStats)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamGenericInterface)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamHTMLSurface)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamHTTP)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamInput)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamInventory)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamMatchmaking)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamMatchmakingServers)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamMusic)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamMusicRemote)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamNetworking)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamNetworkingMessages)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamNetworkingSockets)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamNetworkingUtils)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamParentalSettings)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamParties)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamRemotePlay)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamRemoteStorage)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamScreenshots)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamUGC)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamUser)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamUserStats)
DEFINE_CLIENT_GETTER(SteamAPI_ISteamClient_GetISteamVideo)

void *SteamAPI_ISteamClient_GetISteamUtils(void *self, int32_t hSteamPipe, const char *version) {
    return call_client_getter_utils(self, hSteamPipe, version);
}

uint32_t SteamAPI_ISteamClient_GetIPCCallCount(void *self) {
    void *h = real_handle();
    typedef uint32_t (*GetterFn)(void*);
    GetterFn fn = h ? (GetterFn)dlsym(h, "SteamAPI_ISteamClient_GetIPCCallCount") : NULL;
    uint32_t count = fn ? fn(self) : 0;
    LOGI("[+] SteamAPI_ISteamClient_GetIPCCallCount() -> %u", count);
    return count;
}

typedef void *(*CreateInterfaceFn)(const char *);
void *SteamInternal_CreateInterface(const char *ver) {
    void *h = real_handle();
    CreateInterfaceFn fn = (CreateInterfaceFn)dlsym(h, "SteamInternal_CreateInterface");
    void *res = fn ? fn(ver) : NULL;
    LOGI("[+] SteamInternal_CreateInterface('%s') -> %p", ver ? ver : "NULL", res);
    if (!res) {
        LOGW("[!] SteamInternal_CreateInterface('%s') returned NULL, fallback dummy", ver ? ver : "NULL");
        return &dummy_obj;
    }
    return res;
}

typedef void *(*FindOrCreateUserInterfaceFn)(int32_t, const char *);
void *SteamInternal_FindOrCreateUserInterface(int32_t hUser, const char *ver) {
    ver = flat_version(ver);
    void *h = real_handle();
    FindOrCreateUserInterfaceFn fn = (FindOrCreateUserInterfaceFn)dlsym(h, "SteamInternal_FindOrCreateUserInterface");
    void *res = fn ? fn(hUser, ver) : NULL;
    LOGI("[+] SteamInternal_FindOrCreateUserInterface(%d, '%s') -> %p", hUser, ver ? ver : "NULL", res);
    if (!res) {
        LOGW("[!] SteamInternal_FindOrCreateUserInterface(%d, '%s') returned NULL, fallback dummy", hUser, ver ? ver : "NULL");
        return &dummy_obj;
    }
    return res;
}

typedef void *(*FindOrCreateGameServerInterfaceFn)(int32_t, const char *);
void *SteamInternal_FindOrCreateGameServerInterface(int32_t hUser, const char *ver) {
    ver = flat_version(ver);
    void *h = real_handle();
    FindOrCreateGameServerInterfaceFn fn = (FindOrCreateGameServerInterfaceFn)dlsym(h, "SteamInternal_FindOrCreateGameServerInterface");
    void *res = fn ? fn(hUser, ver) : NULL;
    LOGI("[+] SteamInternal_FindOrCreateGameServerInterface(%d, '%s') -> %p", hUser, ver ? ver : "NULL", res);
    if (!res) {
        LOGW("[!] SteamInternal_FindOrCreateGameServerInterface(%d, '%s') returned NULL, fallback dummy", hUser, ver ? ver : "NULL");
        return &dummy_obj;
    }
    return res;
}

// ---------------------------------------------------------------------------
// Callback struct repacking.
// StS2 ships the Windows build of Steamworks.NET, which marshals callback structs
// with VALVE_CALLBACK_PACK_LARGE (pack 8). Valve's Android/Linux libraries emit them
// with VALVE_CALLBACK_PACK_SMALL (pack 4). Structs whose first 64-bit-aligned member
// follows a 32-bit one land at different offsets, so convert them on the way out.
// Layouts verified against the Steamworks SDK headers compiled both ways.
// ---------------------------------------------------------------------------
typedef struct {
    int32_t  m_hSteamUser;
    int32_t  m_iCallback;
    uint8_t *m_pubParam;
    int32_t  m_cubParam;
} CallbackMsg_t;

#define k_iSteamNetConnectionStatusChangedCallback 1221
#define k_iLobbyCreated 513
#define SNCI_SIZE 696              /* sizeof(SteamNetConnectionInfo_t), same in both packs */
#define SNCSC_SIZE_PACK4 704       /* hConn@0 info@4 oldState@700 */
#define SNCSC_SIZE_PACK8 712       /* hConn@0 info@8 oldState@704 */
#define LOBBYCREATED_SIZE_PACK4 12 /* eResult@0 lobby@4 */
#define LOBBYCREATED_SIZE_PACK8 16 /* eResult@0 lobby@8 */

extern void *p_SteamAPI_ManualDispatch_GetNextCallback;
extern void *p_SteamAPI_ManualDispatch_GetAPICallResult;

static __thread uint8_t g_repacked_cb[SNCSC_SIZE_PACK8];

int SteamAPI_ManualDispatch_GetNextCallback(int32_t hSteamPipe, CallbackMsg_t *msg) {
    typedef int (*Fn)(int32_t, CallbackMsg_t *);
    Fn fn = (Fn)p_SteamAPI_ManualDispatch_GetNextCallback;
    if (!fn) return 0;
    int ok = fn(hSteamPipe, msg);
    if (ok && msg && msg->m_iCallback == k_iSteamNetConnectionStatusChangedCallback &&
        msg->m_cubParam == SNCSC_SIZE_PACK4) {
        const uint8_t *in = msg->m_pubParam;
        memset(g_repacked_cb, 0, sizeof(g_repacked_cb));
        memcpy(g_repacked_cb, in, 4);                               /* m_hConn */
        memcpy(g_repacked_cb + 8, in + 4, SNCI_SIZE);               /* m_info */
        memcpy(g_repacked_cb + 8 + SNCI_SIZE, in + 4 + SNCI_SIZE, 4); /* m_eOldState */
        msg->m_pubParam = g_repacked_cb;
        msg->m_cubParam = SNCSC_SIZE_PACK8;
    }
    return ok;
}

int SteamAPI_ManualDispatch_GetAPICallResult(int32_t hSteamPipe, uint64_t hSteamAPICall, void *pCallback,
                                             int cubCallback, int iCallbackExpected, int *pbFailed) {
    typedef int (*Fn)(int32_t, uint64_t, void *, int, int, int *);
    Fn fn = (Fn)p_SteamAPI_ManualDispatch_GetAPICallResult;
    if (!fn) return 0;
    if (iCallbackExpected == k_iLobbyCreated && cubCallback == LOBBYCREATED_SIZE_PACK8) {
        uint8_t tmp[LOBBYCREATED_SIZE_PACK4] = {0};
        int ok = fn(hSteamPipe, hSteamAPICall, tmp, sizeof(tmp), iCallbackExpected, pbFailed);
        if (ok) {
            uint8_t *out = (uint8_t *)pCallback;
            memset(out, 0, LOBBYCREATED_SIZE_PACK8);
            memcpy(out, tmp, 4);         /* m_eResult */
            memcpy(out + 8, tmp + 4, 8); /* m_ulSteamIDLobby */
        }
        return ok;
    }
    int ok = fn(hSteamPipe, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
    if (!ok && cubCallback > 4) {
        // Same-offset structs that are merely 4 bytes shorter in pack 4 (e.g. LobbyEnter_t 20 vs 24):
        // retry with the native size so the size check passes.
        ok = fn(hSteamPipe, hSteamAPICall, pCallback, cubCallback - 4, iCallbackExpected, pbFailed);
        if (ok) LOGI("[+] GetAPICallResult(%d) accepted with native size %d", iCallbackExpected, cubCallback - 4);
    }
    return ok;
}

int SteamAPI_ISteamUserStats_RequestCurrentStats(void *s) {
    (void)s;
    LOGI("[+] SteamAPI_ISteamUserStats_RequestCurrentStats intercepted -> returning 0");
    return 0;
}
