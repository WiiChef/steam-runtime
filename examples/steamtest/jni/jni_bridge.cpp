// JNI bridge for Steam Multiplayer Diagnostic App.
// Probes real Valve Steamworks SDK 1.65 (androidarm64) native behavior,
// including ISteamMatchmaking, ISteamNetworkingSockets, and ISteamFriends.

#include <jni.h>
#include <android/log.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <mutex>
#include <deque>
#include <sstream>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <cerrno>

#include "steam/steam_api.h"
#include "patchconf.h"

#define LOG_TAG "SteamTest"
#define LOGI(...) do { __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__); AddLog(__VA_ARGS__); } while(0)
#define LOGE(...) do { __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__); AddLog(__VA_ARGS__); } while(0)

// Thread-safe log message queue
static std::mutex g_logMutex;
static std::deque<std::string> g_logQueue;

static void AddLog(const char* fmt, ...) {
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    std::lock_guard<std::mutex> lock(g_logMutex);
    if (g_logQueue.size() > 500) {
        g_logQueue.pop_front();
    }
    g_logQueue.push_back(std::string(buf));
}

static JavaVM* g_jvm = nullptr;
static int g_initResult = -1;
static int g_currentAppId = 2868840;
static void* g_steamservice_handle = nullptr;

// Intercept system property check so Valve SDK finds libsteamclient.so
extern "C" int __system_property_get(const char *name, char *value) {
    if (name && strcmp(name, "lepton.steamclient.path") == 0) {
        LOGI("__system_property_get(lepton.steamclient.path) -> libsteamclient.so");
        strcpy(value, "libsteamclient.so");
        return (int)strlen(value);
    }
    typedef int (*real_prop_fn)(const char *, char *);
    static real_prop_fn real_prop = nullptr;
    if (!real_prop) {
        void* libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_prop = (real_prop_fn)dlsym(libc, "__system_property_get");
    }
    return real_prop ? real_prop(name, value) : 0;
}

#ifndef O_TMPFILE
#define O_TMPFILE 020200000
#endif

extern "C" uid_t getuid(void) {
    return 0;
}

extern "C" uid_t geteuid(void) {
    return 0;
}

#ifndef __NR_memfd_create
#define __NR_memfd_create 435 // aarch64
#endif

// Returns 1 when STEAMRT_IPC_SHM == "memfd" (checked at hook time via getenv).
static int ipc_shm_memfd_mode(void) {
    const char* v = getenv("STEAMRT_IPC_SHM");
    return (v && strcmp(v, "memfd") == 0) ? 1 : 0;
}

// Returns a dup() of the single process-wide memfd backing the Valve IPC shm,
// or -1 on failure. Created with flags 0, truncated to 2 MiB and seeded.
static int ipc_shm_memfd_fd(void) {
    static int fd = -1;
    if (fd >= 0) return dup(fd);
    long mfd = syscall(__NR_memfd_create, "ValveIPCSharedObj-Steam", 0);
    if (mfd < 0) {
        LOGE("[!] memfd_create failed (errno=%d)", errno);
        return -1;
    }
    if (ftruncate(mfd, 2 * 1024 * 1024) != 0) {
        LOGE("[!] ftruncate memfd failed (errno=%d)", errno);
        close((int)mfd);
        return -1;
    }
    // Seed first 12 bytes: {0x04,0,0,0, 0,0x01,0,0, 0,0,0x20,0}
    unsigned char seed[12] = {0x04,0,0,0, 0,0x01,0,0, 0,0,0x20,0};
    ssize_t w = write((int)mfd, seed, sizeof(seed));
    if (w != (ssize_t)sizeof(seed)) {
        LOGE("[!] memfd seed write incomplete (%zd/%zu)", (size_t)w, sizeof(seed));
    }
    lseek((int)mfd, 0, SEEK_SET);
    fd = (int)mfd;
    LOGI("[+] IPC shm -> memfd fd=%d", fd);
    return dup(fd);
}

extern "C" int open(const char* pathname, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = (mode_t)va_arg(args, int);
        va_end(args);
    }

    const char* real_path = pathname;
    if (pathname && strstr(pathname, "steam_appid.txt") != nullptr) {
        real_path = "/data/user/0/com.sts2.steamtest/files/steam_appid.txt";
        LOGI("[HOOK] open('%s') redirected -> '%s'", pathname, real_path);
    } else if (pathname && strstr(pathname, "ValveIPCSharedObj-Steam") != nullptr) {
        if (access("/data/user/0/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam", F_OK) == 0) {
            real_path = "/data/user/0/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam";
        } else if (access("/data/data/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam", F_OK) == 0) {
            real_path = "/data/data/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam";
        } else {
            real_path = "/data/local/tmp/u0-ValveIPCSharedObj-Steam";
        }
        LOGI("[HOOK] open('%s') redirected -> '%s'", pathname, real_path);
    } else if (pathname && strcmp(pathname, ".") == 0 && (flags & O_TMPFILE)) {
        real_path = "/data/user/0/com.sts2.steamtest/cache";
        LOGI("[HOOK] open('.', O_TMPFILE) redirected -> '%s'", real_path);
    }

    typedef int (*real_open_fn)(const char*, int, ...);
    static real_open_fn real_open = nullptr;
    if (!real_open) {
        void* libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_open = (real_open_fn)dlsym(libc, "open");
    }
    return real_open ? real_open(real_path, flags, mode) : -1;
}

extern "C" int openat(int dirfd, const char* pathname, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = (mode_t)va_arg(args, int);
        va_end(args);
    }

    const char* real_path = pathname;
    if (pathname && strstr(pathname, "steam_appid.txt") != nullptr) {
        real_path = "/data/user/0/com.sts2.steamtest/files/steam_appid.txt";
        LOGI("[HOOK] openat('%s') redirected -> '%s'", pathname, real_path);
    } else if (pathname && strstr(pathname, "ValveIPCSharedObj-Steam") != nullptr) {
        if (access("/data/user/0/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam", F_OK) == 0) {
            real_path = "/data/user/0/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam";
        } else if (access("/data/data/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam", F_OK) == 0) {
            real_path = "/data/data/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam";
        } else {
            real_path = "/data/local/tmp/u0-ValveIPCSharedObj-Steam";
        }
        LOGI("[HOOK] openat('%s') redirected -> '%s'", pathname, real_path);
    }

    typedef int (*real_openat_fn)(int, const char*, int, ...);
    static real_openat_fn real_openat = nullptr;
    if (!real_openat) {
        void* libc = dlopen("libc.so", RTLD_NOW);
        if (libc) real_openat = (real_openat_fn)dlsym(libc, "openat");
    }
    return real_openat ? real_openat(dirfd, real_path, flags, mode) : -1;
}

// Struct to store discovered lobbies
struct LobbyInfo {
    uint64_t id;
    std::string name;
    std::string hostName;
    int memberCount;
    int maxMembers;
};

static std::mutex g_lobbyMutex;
static std::vector<LobbyInfo> g_discoveredLobbies;
static uint64_t g_currentLobbyId = 0;

class SteamDiagnosticsManager {
public:
    SteamDiagnosticsManager() {}

    // Callbacks
    STEAM_CALLBACK(SteamDiagnosticsManager, OnSteamServersConnected, SteamServersConnected_t) {
        LOGI("[CALLBACK] SteamServersConnected: Connected to Steam servers successfully!");
    }

    STEAM_CALLBACK(SteamDiagnosticsManager, OnSteamServersDisconnected, SteamServersDisconnected_t) {
        LOGE("[CALLBACK] SteamServersDisconnected: Result=%d", (int)pParam->m_eResult);
    }

    STEAM_CALLBACK(SteamDiagnosticsManager, OnSteamServerConnectFailure, SteamServerConnectFailure_t) {
        LOGE("[CALLBACK] SteamServerConnectFailure: Result=%d, StillRetrying=%d",
             (int)pParam->m_eResult, (int)pParam->m_bStillRetrying);
    }

    STEAM_CALLBACK(SteamDiagnosticsManager, OnLobbyDataUpdate, LobbyDataUpdate_t) {
        LOGI("[CALLBACK] LobbyDataUpdate: LobbyID=%llu Success=%d",
             (unsigned long long)pParam->m_ulSteamIDLobby, (int)pParam->m_bSuccess);
    }

    STEAM_CALLBACK(SteamDiagnosticsManager, OnLobbyChatUpdate, LobbyChatUpdate_t) {
        LOGI("[CALLBACK] LobbyChatUpdate: LobbyID=%llu UserChanged=%llu ChatState=%d",
             (unsigned long long)pParam->m_ulSteamIDLobby,
             (unsigned long long)pParam->m_ulSteamIDUserChanged,
             (int)pParam->m_rgfChatMemberStateChange);
    }

    // CallResults
    void RequestLobbyList() {
        ISteamMatchmaking* mm = SteamMatchmaking();
        if (!mm) {
            LOGE("[-] SteamMatchmaking() is null!");
            return;
        }
        LOGI("[LOBBY] Requesting lobby list from Valve...");
        mm->AddRequestLobbyListDistanceFilter(k_ELobbyDistanceFilterWorldwide);
        SteamAPICall_t call = mm->RequestLobbyList();
        m_CallResultLobbyMatchList.Set(call, this, &SteamDiagnosticsManager::OnLobbyMatchList);
    }

    void OnLobbyMatchList(LobbyMatchList_t* pLobbyMatchList, bool bIOFailure) {
        if (bIOFailure) {
            LOGE("[-] OnLobbyMatchList: IO Failure!");
            return;
        }
        uint32 count = pLobbyMatchList->m_nLobbiesMatching;
        LOGI("[+] OnLobbyMatchList: Found %u lobbies matching filter!", count);

        std::lock_guard<std::mutex> lock(g_lobbyMutex);
        g_discoveredLobbies.clear();

        ISteamMatchmaking* mm = SteamMatchmaking();
        if (!mm) return;

        for (uint32 i = 0; i < count; i++) {
            CSteamID lobbyID = mm->GetLobbyByIndex(i);
            const char* name = mm->GetLobbyData(lobbyID, "game_name");
            const char* host = mm->GetLobbyData(lobbyID, "host_persona");
            int numMembers = mm->GetNumLobbyMembers(lobbyID);
            int maxMembers = mm->GetLobbyMemberLimit(lobbyID);

            LobbyInfo info;
            info.id = (uint64_t)lobbyID.ConvertToUint64();
            info.name = (name && strlen(name) > 0) ? name : "StS2 Match";
            info.hostName = (host && strlen(host) > 0) ? host : "(unknown host)";
            info.memberCount = numMembers;
            info.maxMembers = maxMembers > 0 ? maxMembers : 4;

            LOGI("    -> Lobby #%u: ID=%llu Host='%s' Name='%s' Members=%d/%d",
                 i + 1, (unsigned long long)info.id, info.hostName.c_str(), info.name.c_str(),
                 info.memberCount, info.maxMembers);
            g_discoveredLobbies.push_back(info);
        }
    }

    void CreateLobby(ELobbyType lobbyType, int maxMembers) {
        ISteamMatchmaking* mm = SteamMatchmaking();
        if (!mm) {
            LOGE("[-] SteamMatchmaking() is null!");
            return;
        }
        LOGI("[LOBBY] Creating lobby (Type=%d, MaxMembers=%d)...", (int)lobbyType, maxMembers);
        SteamAPICall_t call = mm->CreateLobby(lobbyType, maxMembers);
        m_CallResultLobbyCreated.Set(call, this, &SteamDiagnosticsManager::OnLobbyCreated);
    }

    void OnLobbyCreated(LobbyCreated_t* pLobbyCreated, bool bIOFailure) {
        if (bIOFailure) {
            LOGE("[-] OnLobbyCreated: IO Failure!");
            return;
        }
        if (pLobbyCreated->m_eResult != k_EResultOK) {
            LOGE("[-] OnLobbyCreated failed with EResult: %d", (int)pLobbyCreated->m_eResult);
            return;
        }
        CSteamID lobbyID(pLobbyCreated->m_ulSteamIDLobby);
        g_currentLobbyId = (uint64_t)lobbyID.ConvertToUint64();
        LOGI("[+] OnLobbyCreated: SUCCESS! Lobby ID = %llu", (unsigned long long)g_currentLobbyId);

        ISteamMatchmaking* mm = SteamMatchmaking();
        ISteamFriends* friends = SteamFriends();
        if (mm) {
            const char* myPersona = friends ? friends->GetPersonaName() : "AndroidHost";
            mm->SetLobbyData(lobbyID, "game_name", "Slay the Spire 2 Co-op");
            mm->SetLobbyData(lobbyID, "game_version", "v0.4.1-online");
            mm->SetLobbyData(lobbyID, "host_persona", myPersona);
            mm->SetLobbyData(lobbyID, "max_players", "4");
            mm->SetLobbyMemberData(lobbyID, "player_ready", "true");
            LOGI("[LOBBY] Metadata published: game_name='Slay the Spire 2 Co-op', host='%s'", myPersona);
        }
    }

    void JoinLobby(uint64_t lobbyID64) {
        ISteamMatchmaking* mm = SteamMatchmaking();
        if (!mm) {
            LOGE("[-] SteamMatchmaking() is null!");
            return;
        }
        CSteamID lobbyID((uint64)lobbyID64);
        LOGI("[LOBBY] Joining lobby ID: %llu...", (unsigned long long)lobbyID64);
        SteamAPICall_t call = mm->JoinLobby(lobbyID);
        m_CallResultLobbyEnter.Set(call, this, &SteamDiagnosticsManager::OnLobbyEntered);
    }

    void OnLobbyEntered(LobbyEnter_t* pLobbyEnter, bool bIOFailure) {
        if (bIOFailure) {
            LOGE("[-] OnLobbyEntered: IO Failure!");
            return;
        }
        if (pLobbyEnter->m_EChatRoomEnterResponse != k_EChatRoomEnterResponseSuccess) {
            LOGE("[-] OnLobbyEntered failed with response: %d", (int)pLobbyEnter->m_EChatRoomEnterResponse);
            return;
        }
        g_currentLobbyId = (uint64_t)pLobbyEnter->m_ulSteamIDLobby;
        LOGI("[+] OnLobbyEntered: Successfully joined lobby %llu!", (unsigned long long)g_currentLobbyId);

        ISteamMatchmaking* mm = SteamMatchmaking();
        if (mm) {
            CSteamID lobbyID((uint64)g_currentLobbyId);
            CSteamID ownerID = mm->GetLobbyOwner(lobbyID);
            int count = mm->GetNumLobbyMembers(lobbyID);
            LOGI("[LOBBY] Lobby Owner ID: %llu, Member Count: %d",
                 (unsigned long long)ownerID.ConvertToUint64(), count);
        }
    }

    void LeaveLobby() {
        if (g_currentLobbyId != 0) {
            ISteamMatchmaking* mm = SteamMatchmaking();
            if (mm) {
                mm->LeaveLobby(CSteamID((uint64)g_currentLobbyId));
                LOGI("[LOBBY] Left lobby %llu", (unsigned long long)g_currentLobbyId);
            }
            g_currentLobbyId = 0;
        }
    }

private:
    CCallResult<SteamDiagnosticsManager, LobbyMatchList_t> m_CallResultLobbyMatchList;
    CCallResult<SteamDiagnosticsManager, LobbyCreated_t> m_CallResultLobbyCreated;
    CCallResult<SteamDiagnosticsManager, LobbyEnter_t> m_CallResultLobbyEnter;
};

static SteamDiagnosticsManager* g_mgr = nullptr;

extern "C" {

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*) {
    g_jvm = vm;
    LOGI("=== JNI_OnLoad: Preloading Steam companion libraries ===");

    dlopen("libtier0_s.so", RTLD_NOW | RTLD_GLOBAL);
    dlopen("libvstdlib_s.so", RTLD_NOW | RTLD_GLOBAL);
    dlopen("libsteamnetworkingsockets.so", RTLD_NOW | RTLD_GLOBAL);
    g_steamservice_handle = dlopen("steamservice.so", RTLD_NOW | RTLD_GLOBAL);
    void* client = dlopen("libsteamclient.so", RTLD_NOW | RTLD_GLOBAL);

    LOGI("  libsteamclient.so: %s", client ? "LOADED" : "FAILED");
    LOGI("  steamservice.so:   %s", g_steamservice_handle ? "LOADED" : "FAILED");

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeSetup(JNIEnv* env, jclass, jstring jdir, jint appId) {
    g_currentAppId = appId;
    const char* dir = env->GetStringUTFChars(jdir, nullptr);

    if (chdir(dir) == 0) {
        LOGI("chdir -> %s OK", dir);
    }
    std::string path = std::string(dir) + "/steam_appid.txt";
    FILE* f = fopen(path.c_str(), "w");
    if (f) {
        fprintf(f, "%d\n", appId);
        fclose(f);
        LOGI("Wrote %s (AppID=%d)", path.c_str(), appId);
    }
    FILE* f_cwd = fopen("./steam_appid.txt", "w");
    if (f_cwd) {
        fprintf(f_cwd, "%d\n", appId);
        fclose(f_cwd);
    }
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", appId);
    setenv("SteamAppId", buf, 1);
    setenv("SteamGameId", buf, 1);
    LOGI("Environment set: SteamAppId=%s, SteamGameId=%s", buf, buf);

    env->ReleaseStringUTFChars(jdir, dir);
}

static uintptr_t GetModuleBase(const char* module_name) {
    FILE* fp = fopen("/proc/self/maps", "r");
    if (!fp) return 0;
    char line[512];
    uintptr_t base = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, module_name)) {
            base = (uintptr_t)strtoull(line, nullptr, 16);
            break;
        }
    }
    fclose(fp);
    return base;
}

static char s_steamInstallPath[256] = "/data/local/tmp";

static void PatchSteamClientPaths() {
    if (access("/data/user/0/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam", F_OK) == 0) {
        snprintf(s_steamInstallPath, sizeof(s_steamInstallPath), "/data/user/0/com.sts2.steamservice/files");
    } else if (access("/data/data/com.sts2.steamservice/files/u0-ValveIPCSharedObj-Steam", F_OK) == 0) {
        snprintf(s_steamInstallPath, sizeof(s_steamInstallPath), "/data/data/com.sts2.steamservice/files");
    } else {
        snprintf(s_steamInstallPath, sizeof(s_steamInstallPath), "/data/local/tmp");
    }

    uintptr_t clientBase = GetModuleBase("libsteamclient.so");
    if (!clientBase) {
        LOGE("[-] Cannot find libsteamclient.so base in /proc/self/maps");
        return;
    }
    LOGI("[+] libsteamclient.so base: %p", (void*)clientBase);
    int n = pc_apply(clientBase, s_steamInstallPath);
    if (n == 0) LOGW("No patches applied (steamclient_patches.conf missing or empty)");
    else LOGI("[+] Applied %d patch entries; install path '%s'", n, s_steamInstallPath);
}

JNIEXPORT jboolean JNICALL
Java_com_sts2_steamtest_SteamTest_nativeStartService(JNIEnv*, jclass) {
    PatchSteamClientPaths();

    uintptr_t clientBase = GetModuleBase("libsteamclient.so");
    if (!clientBase) {
        LOGE("[-] libsteamclient.so not loaded!");
        return JNI_FALSE;
    }
    LOGI("[+] libsteamclient.so base: %p", (void*)clientBase);

    // Function offsets come from the private steamclient_patches.conf ("fn <name> <off>").
    uint64_t oServer = pc_fn("get_ipc_server"), oStart = pc_fn("start_ipc_server"),
             oInit = pc_fn("init_interfaces"), oThread = pc_fn("start_thread"),
             oEngine = pc_fn("get_engine"), oConnect = pc_fn("connect_global_user"),
             oAssoc = pc_fn("associate_user_pipe");
    if (!oServer || !oStart || !oInit || !oThread || !oEngine || !oConnect || !oAssoc) {
        LOGE("[-] steamclient_patches.conf lacks the fn entries needed to start the service");
        return JNI_FALSE;
    }

    typedef void* (*GetServerFn)();
    void* pServer = ((GetServerFn)(clientBase + oServer))();
    LOGI("[+] IPC server instance at: %p", pServer);
    if (!pServer) {
        LOGE("[-] Failed to get IPC server instance!");
        return JNI_FALSE;
    }

    typedef void (*StartIPCServerFn)(void* server, const char* name, int bListen, int bCrossSession, int bCrossProcess);
    ((StartIPCServerFn)(clientBase + oStart))(pServer, "Steam3Master", 1, 0, 1);

    typedef void (*InitFn)(void*);
    ((InitFn)(clientBase + oInit))(pServer);

    typedef bool (*StartThreadFn)(void*);
    bool started = ((StartThreadFn)(clientBase + oThread))(pServer);
    LOGI("[+] IPC dispatch thread started: %s", started ? "TRUE" : "FALSE");

    typedef void* (*GetEngineFn)();
    void* pEngine = ((GetEngineFn)(clientBase + oEngine))();
    LOGI("[+] Engine at: %p", pEngine);

    if (pEngine) {
        typedef int (*ConnectFn)(void* pEngine, int* phPipe);
        int hPipe = 0;
        int hUser = ((ConnectFn)(clientBase + oConnect))(pEngine, &hPipe);
        LOGI("[+] Connected global user: hUser=%d, hPipe=%d", hUser, hPipe);

        typedef void (*AssocFn)(void* pServer, int hPipe, int hUser, int flag);
        ((AssocFn)(clientBase + oAssoc))(pServer, hPipe, hUser, 0);
    }

    return JNI_TRUE;
}

JNIEXPORT jint JNICALL
Java_com_sts2_steamtest_SteamTest_nativeInit(JNIEnv*, jclass, jint appId) {
    g_currentAppId = appId;
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", appId);
    setenv("SteamAppId", buf, 1);
    setenv("SteamGameId", buf, 1);

    PatchSteamClientPaths();

    LOGI("=== Initializing Steamworks API for AppID %d ===", appId);
    SteamErrMsg err = {0};
    ESteamAPIInitResult r = SteamAPI_InitEx(&err);
    g_initResult = (int)r;

    if (r == k_ESteamAPIInitResult_OK) {
        LOGI("[+] SteamAPI_InitEx returned OK (0)!");
        if (!g_mgr) {
            g_mgr = new SteamDiagnosticsManager();
        }
    } else {
        LOGE("[-] SteamAPI_InitEx failed! Code: %d, Error: %s", (int)r, err);
    }
    return (jint)r;
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeRunFrame(JNIEnv*, jclass) {
    SteamAPI_RunCallbacks();
}

JNIEXPORT jstring JNICALL
Java_com_sts2_steamtest_SteamTest_nativeGetStatus(JNIEnv* env, jclass) {
    std::ostringstream ss;
    ss << "init_code=" << g_initResult;

    if (g_initResult == k_ESteamAPIInitResult_OK) {
        ISteamUser* user = SteamUser();
        ISteamFriends* friends = SteamFriends();
        ISteamUtils* utils = SteamUtils();

        if (user) {
            bool logged = user->BLoggedOn();
            ss << ";logged_on=" << (logged ? "1" : "0");
            if (logged) {
                CSteamID id = user->GetSteamID();
                ss << ";steam_id=" << id.ConvertToUint64();
            }
        }
        if (friends) {
            const char* persona = friends->GetPersonaName();
            ss << ";persona=" << (persona ? persona : "(unknown)");
            int friendCount = friends->GetFriendCount(k_EFriendFlagImmediate);
            ss << ";friend_count=" << friendCount;
        }
        if (utils) {
            uint32 serverTime = utils->GetServerRealTime();
            ss << ";server_time=" << (serverTime > 0 ? "OK" : "UNREACHABLE");
            ss << ";universe=" << (int)utils->GetConnectedUniverse();
        }
        ss << ";active_lobby=" << g_currentLobbyId;
    }
    return env->NewStringUTF(ss.str().c_str());
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeRequestLobbyList(JNIEnv*, jclass) {
    if (g_mgr) {
        g_mgr->RequestLobbyList();
    } else {
        LOGE("Steam not initialized!");
    }
}

JNIEXPORT jstring JNICALL
Java_com_sts2_steamtest_SteamTest_nativeGetLobbies(JNIEnv* env, jclass) {
    std::lock_guard<std::mutex> lock(g_lobbyMutex);
    std::ostringstream ss;

    for (size_t i = 0; i < g_discoveredLobbies.size(); i++) {
        const LobbyInfo& l = g_discoveredLobbies[i];
        if (i > 0) ss << "\n";
        ss << l.id << "\t" << l.hostName << "\t" << l.name << "\t"
           << l.memberCount << "/" << l.maxMembers;
    }
    return env->NewStringUTF(ss.str().c_str());
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeCreateLobby(JNIEnv*, jclass, jint lobbyType, jint maxMembers) {
    if (g_mgr) {
        g_mgr->CreateLobby((ELobbyType)lobbyType, maxMembers);
    } else {
        LOGE("Steam not initialized!");
    }
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeJoinLobby(JNIEnv*, jclass, jlong lobbyId) {
    if (g_mgr) {
        g_mgr->JoinLobby((uint64_t)lobbyId);
    } else {
        LOGE("Steam not initialized!");
    }
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeLeaveLobby(JNIEnv*, jclass) {
    if (g_mgr) {
        g_mgr->LeaveLobby();
    }
}

JNIEXPORT jstring JNICALL
Java_com_sts2_steamtest_SteamTest_nativeTestP2P(JNIEnv* env, jclass) {
    ISteamNetworkingSockets* sockets = SteamNetworkingSockets();
    if (!sockets) {
        LOGE("[-] SteamNetworkingSockets() is null!");
        return env->NewStringUTF("FAILED: SteamNetworkingSockets() null");
    }

    HSteamListenSocket listenSocket = sockets->CreateListenSocketP2P(0, 0, nullptr);

    char buf[128];
    if (listenSocket != k_HSteamListenSocket_Invalid) {
        LOGI("[+] P2P Listen Socket created successfully: handle=%u", (unsigned int)listenSocket);
        sockets->CloseListenSocket(listenSocket);
        snprintf(buf, sizeof(buf), "SUCCESS (listen handle=%u)", (unsigned int)listenSocket);
    } else {
        LOGE("[-] Failed to create P2P Listen Socket!");
        snprintf(buf, sizeof(buf), "FAILED to create listen socket");
    }
    return env->NewStringUTF(buf);
}

JNIEXPORT jstring JNICALL
Java_com_sts2_steamtest_SteamTest_nativePollLogs(JNIEnv* env, jclass) {
    std::lock_guard<std::mutex> lock(g_logMutex);
    if (g_logQueue.empty()) {
        return nullptr;
    }
    std::ostringstream ss;
    while (!g_logQueue.empty()) {
        ss << g_logQueue.front() << "\n";
        g_logQueue.pop_front();
    }
    return env->NewStringUTF(ss.str().c_str());
}

JNIEXPORT void JNICALL
Java_com_sts2_steamtest_SteamTest_nativeShutdown(JNIEnv*, jclass) {
    LOGI("Shutting down SteamAPI...");
    if (g_mgr) {
        delete g_mgr;
        g_mgr = nullptr;
    }
    if (g_initResult == k_ESteamAPIInitResult_OK) {
        SteamAPI_Shutdown();
        g_initResult = -1;
    }
}

} // extern "C"
