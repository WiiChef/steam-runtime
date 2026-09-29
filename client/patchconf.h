// patchconf.h - data-driven runtime patches for a locally supplied Steam client library.
//
// This repo deliberately contains NO offsets, instruction words or internal symbol names for Valve's
// libsteamclient.so. Those are derived from a non-public binary, so they are read at runtime from a
// private file that you create yourself (see docs/PATCH_CONF.md for the format). Without that file the
// shim still loads and forwards calls, but performs no patching and will not attach to the host.
//
// File search order: $STEAM_PATCH_CONF, <host files dir>/steamclient_patches.conf,
// /data/local/tmp/steamclient_patches.conf
//
// Line format ('#' starts a comment, numbers are hex, offsets are relative to the module base):
//   u8  <off> <val>        write one byte
//   u32 <off> <val>        write one 32-bit word (code pages made writable, icache flushed)
//   ptr <off>              write the shim's install-path string pointer (8 bytes)
//   fn  <name> <off>       named function offset, looked up with pc_fn()
#ifndef STEAM_PATCHCONF_H
#define STEAM_PATCHCONF_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define PC_MAX 128

typedef struct {
    char kind[8];
    char name[40];
    uint64_t off;
    uint64_t val;
} pc_entry;

static pc_entry g_pc[PC_MAX];
static int g_pc_n = -1;

static void pc_load(void) {
    if (g_pc_n >= 0) return;
    g_pc_n = 0;
    const char *env = getenv("STEAM_PATCH_CONF");
    const char *cands[] = {
        env,
        "/data/user/0/com.steamruntime.dev/files/steamclient_patches.conf",
        "/data/local/tmp/steamclient_patches.conf",
    };
    FILE *f = NULL;
    for (unsigned i = 0; i < sizeof(cands) / sizeof(cands[0]) && !f; i++)
        if (cands[i] && cands[i][0]) f = fopen(cands[i], "r");
    if (!f) return;
    char line[256];
    while (g_pc_n < PC_MAX && fgets(line, sizeof(line), f)) {
        char *hash = strchr(line, '#');
        if (hash) *hash = 0;
        pc_entry e;
        memset(&e, 0, sizeof(e));
        char a[40] = {0}, b[40] = {0}, c[40] = {0};
        int n = sscanf(line, "%39s %39s %39s", a, b, c);
        if (n < 2) continue;
        if (!strcmp(a, "u8") || !strcmp(a, "u32")) {
            if (n < 3) continue;
            strncpy(e.kind, a, sizeof(e.kind) - 1);
            e.off = strtoull(b, NULL, 16);
            e.val = strtoull(c, NULL, 16);
        } else if (!strcmp(a, "ptr")) {
            strncpy(e.kind, a, sizeof(e.kind) - 1);
            e.off = strtoull(b, NULL, 16);
        } else if (!strcmp(a, "fn")) {
            if (n < 3) continue;
            strncpy(e.kind, a, sizeof(e.kind) - 1);
            strncpy(e.name, b, sizeof(e.name) - 1);
            e.off = strtoull(c, NULL, 16);
        } else {
            continue;
        }
        g_pc[g_pc_n++] = e;
    }
    fclose(f);
}

// Returns the number of patches applied.
static int pc_apply(uintptr_t base, const char *install_path) {
    pc_load();
    int applied = 0;
    for (int i = 0; i < g_pc_n; i++) {
        pc_entry *e = &g_pc[i];
        if (!strcmp(e->kind, "fn")) continue;
        uintptr_t addr = base + (uintptr_t)e->off;
        uintptr_t page = addr & ~(uintptr_t)4095;
        int prot = PROT_READ | PROT_WRITE | (!strcmp(e->kind, "u32") ? PROT_EXEC : 0);
        if (mprotect((void *)page, 8192, prot) != 0) continue;
        if (!strcmp(e->kind, "u8")) {
            *(uint8_t *)addr = (uint8_t)e->val;
        } else if (!strcmp(e->kind, "u32")) {
            *(uint32_t *)addr = (uint32_t)e->val;
            __builtin___clear_cache((char *)page, (char *)(page + 8192));
        } else if (!strcmp(e->kind, "ptr")) {
            *(const char **)addr = install_path;
        }
        applied++;
    }
    return applied;
}

// Offset of a named function from the config, or 0 if absent.
static uint64_t pc_fn(const char *name) {
    pc_load();
    for (int i = 0; i < g_pc_n; i++)
        if (!strcmp(g_pc[i].kind, "fn") && !strcmp(g_pc[i].name, name)) return g_pc[i].off;
    return 0;
}

#endif
