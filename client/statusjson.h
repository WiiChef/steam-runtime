// statusjson.h - minimal reader for the host's status.json (flat top-level keys only). MIT.
//
// The host writes <host files dir>/status.json (see host/README.md). This file only needs a handful
// of scalar values, so it uses a tiny key scanner instead of a JSON library.
#ifndef STEAM_STATUSJSON_H
#define STEAM_STATUSJSON_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SJ_PATH "/data/user/0/com.steamruntime.dev/files/status.json"

// Reads the file into buf (NUL-terminated). Returns the length, or -1 if it cannot be read.
static int sj_read(char *buf, size_t cap, const char *path) {
    FILE *f = fopen(path ? path : SJ_PATH, "r");
    if (!f) return -1;
    size_t n = fread(buf, 1, cap - 1, f);
    fclose(f);
    buf[n] = 0;
    return (int)n;
}

// Copies the scalar value of top-level "key" into out (strings unquoted; true/false/null/numbers as
// written). Returns 1 if the key exists, 0 otherwise. Does not handle keys nested in objects with the
// same name; the host emits unique key names.
static int sj_get(const char *json, const char *key, char *out, size_t cap) {
    char pat[80];
    snprintf(pat, sizeof(pat), "\"%s\"", key);
    const char *p = strstr(json, pat);
    if (!p) return 0;
    p += strlen(pat);
    while (*p && isspace((unsigned char)*p)) p++;
    if (*p != ':') return 0;
    p++;
    while (*p && isspace((unsigned char)*p)) p++;
    size_t n = 0;
    if (*p == '"') {
        p++;
        while (*p && *p != '"' && n + 1 < cap) {
            if (*p == '\\' && p[1]) p++;
            out[n++] = *p++;
        }
    } else {
        while (*p && *p != ',' && *p != '}' && !isspace((unsigned char)*p) && n + 1 < cap) out[n++] = *p++;
    }
    out[n] = 0;
    return 1;
}

#endif
