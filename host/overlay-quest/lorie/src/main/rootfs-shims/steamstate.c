/* steamstate: one-shot login/ownership probe, run INSIDE the PRoot rootfs (glibc aarch64).
 * Part of the Steam Runtime host (GPLv3).
 *
 * Connects to the running Steam client through versioned interfaces and prints ONE line of JSON:
 *   {"ok":true,"logged_on":true,"account_present":true,"client_iface":"SteamClient021",
 *    "user_iface":"SteamUser023","apps_iface":"STEAMAPPS_INTERFACE_VERSION008",
 *    "owned":{"2868840":true},"error":""}
 * The SteamID itself is never printed (only whether an account is present).
 *
 * Usage: steamstate <steam_dir> [appid ...]
 * Build (inside the rootfs, or any aarch64-linux-gnu cross compiler):
 *   gcc -O2 -Wall -o steamstate steamstate.c -ldl
 *
 * Versions differ between client builds, so every interface is tried newest -> oldest and the one
 * that worked is reported. Method slots used (stable across the versions tried):
 *   ISteamClient: 0 CreateSteamPipe, 1 BReleaseSteamPipe, 2 ConnectToGlobalUser, 4 ReleaseUser,
 *                 12 GetISteamGenericInterface
 *   ISteamUser:   1 BLoggedOn, 2 GetSteamID
 *   ISteamApps:   6 BIsSubscribedApp
 * Bounded by alarm(); the caller additionally wraps it in timeout(1).
 */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TIMEOUT_SEC 10
#define MAX_APPS 16

typedef void *(*create_interface_fn)(const char *, int *);
#define VT(obj, idx) (((void ***)(obj))[0][idx])

static const char *k_client_ver[] = {"SteamClient021", "SteamClient020", "SteamClient019",
                                     "SteamClient018", "SteamClient017", NULL};
static const char *k_user_ver[] = {"SteamUser023", "SteamUser022", "SteamUser021",
                                   "SteamUser020", "SteamUser019", NULL};
static const char *k_apps_ver[] = {"STEAMAPPS_INTERFACE_VERSION009", "STEAMAPPS_INTERFACE_VERSION008",
                                   "STEAMAPPS_INTERFACE_VERSION007", NULL};

static void emit(int ok, int logged_on, int account, const char *ci, const char *ui, const char *ai,
                 int napps, const unsigned *appids, const int *owned, const char *err) {
    printf("{\"ok\":%s,\"logged_on\":%s,\"account_present\":%s,\"client_iface\":\"%s\","
           "\"user_iface\":\"%s\",\"apps_iface\":\"%s\",\"owned\":{",
           ok ? "true" : "false", logged_on ? "true" : "false", account ? "true" : "false",
           ci ? ci : "", ui ? ui : "", ai ? ai : "");
    for (int i = 0; i < napps; i++)
        printf("%s\"%u\":%s", i ? "," : "", appids[i], owned[i] ? "true" : "false");
    printf("},\"error\":\"%s\"}\n", err ? err : "");
    fflush(stdout);
}

static void *load_client(const char *dir) {
    static const char *rel[] = {"linuxarm64/steamclient.so", "steamclient.so", "linux64/steamclient.so",
                                "ubuntu12_64/steamclient.so", NULL};
    char path[512];
    for (int i = 0; rel[i]; i++) {
        snprintf(path, sizeof(path), "%s/%s", dir, rel[i]);
        if (access(path, R_OK) != 0) continue;
        void *h = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
        if (h) return h;
    }
    snprintf(path, sizeof(path), "%s", "/root/.steam/sdk64/steamclient.so");
    return access(path, R_OK) == 0 ? dlopen(path, RTLD_NOW | RTLD_GLOBAL) : NULL;
}

int main(int argc, char **argv) {
    unsigned appids[MAX_APPS] = {0};
    int owned[MAX_APPS] = {0};
    int napps = 0;
    for (int i = 2; i < argc && napps < MAX_APPS; i++) {
        unsigned long v = strtoul(argv[i], NULL, 10);
        if (v) appids[napps++] = (unsigned)v;
    }
    if (argc < 2) {
        emit(0, 0, 0, NULL, NULL, NULL, 0, appids, owned, "usage");
        return 2;
    }
    alarm(TIMEOUT_SEC);

    void *lib = load_client(argv[1]);
    if (!lib) {
        emit(0, 0, 0, NULL, NULL, NULL, napps, appids, owned, "steamclient_not_found");
        return 1;
    }
    create_interface_fn create = (create_interface_fn)dlsym(lib, "CreateInterface");
    if (!create) {
        emit(0, 0, 0, NULL, NULL, NULL, napps, appids, owned, "no_CreateInterface");
        return 1;
    }

    void *client = NULL;
    const char *client_ver = NULL;
    for (int i = 0; k_client_ver[i] && !client; i++) {
        client = create(k_client_ver[i], NULL);
        if (client) client_ver = k_client_ver[i];
    }
    if (!client) {
        emit(0, 0, 0, NULL, NULL, NULL, napps, appids, owned, "no_supported_SteamClient_version");
        return 1;
    }

    int pipe = ((int (*)(void *))VT(client, 0))(client);
    if (pipe <= 0) {
        emit(0, 0, 0, client_ver, NULL, NULL, napps, appids, owned, "CreateSteamPipe_failed");
        return 1;
    }
    int user = ((int (*)(void *, int))VT(client, 2))(client, pipe);

    typedef void *(*generic_fn)(void *, int, int, const char *);
    generic_fn generic = (generic_fn)VT(client, 12);

    void *iuser = NULL;
    const char *user_ver = NULL;
    if (user) {
        for (int i = 0; k_user_ver[i] && !iuser; i++) {
            iuser = generic(client, user, pipe, k_user_ver[i]);
            if (iuser) user_ver = k_user_ver[i];
        }
    }

    int logged_on = 0, account = 0;
    const char *err = "";
    if (!user) {
        err = "ConnectToGlobalUser_failed";
    } else if (!iuser) {
        err = "no_supported_SteamUser_version";
    } else {
        logged_on = (((int (*)(void *))VT(iuser, 1))(iuser) & 0xff) != 0;
        uint64_t sid = ((uint64_t (*)(void *))VT(iuser, 2))(iuser);
        account = (uint32_t)sid != 0;
    }

    const char *apps_ver = NULL;
    if (logged_on && napps > 0) {
        void *iapps = NULL;
        for (int i = 0; k_apps_ver[i] && !iapps; i++) {
            iapps = generic(client, user, pipe, k_apps_ver[i]);
            if (iapps) apps_ver = k_apps_ver[i];
        }
        if (iapps) {
            for (int i = 0; i < napps; i++)
                owned[i] = (((int (*)(void *, uint32_t))VT(iapps, 6))(iapps, appids[i]) & 0xff) != 0;
        } else {
            err = "no_supported_SteamApps_version";
        }
    }

    if (user) ((void (*)(void *, int, int))VT(client, 4))(client, pipe, user);
    ((int (*)(void *, int))VT(client, 1))(client, pipe);

    emit(iuser != NULL, logged_on, account, client_ver, user_ver, apps_ver, napps, appids, owned, err);
    return 0;
}
