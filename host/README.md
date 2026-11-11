# Steam Runtime host (Android app)

The host is an Android app (`com.steamruntime.dev`) that keeps a **real, logged-in Steam client** running on the
device so native Android ports can use Steam (identity, friends, lobbies, matchmaking, networking) through the
[client shim](../client). One host serves every port.

It is a modified [Termux:X11](https://github.com/termux/termux-x11) (GPLv3), so this directory is GPLv3
(see `LICENSE`). We do not vendor Termux:X11: `steam-runtime.patch` + `overlay/` apply on top of upstream commit
`9c23bd3`.

## What it does

- `SteamRuntimeService` (foreground service, `specialUse`) unpacks a Debian trixie aarch64 rootfs, starts an
  in-app X server (`com.termux.x11.CmdEntryPoint :0`), then runs PRoot (`--link2symlink --sysvipc -0`, fake root)
  and launches Valve's Linux ARM64 Steam client inside it with `dbus-run-session`, openbox and
  `-no-cef-sandbox -cef-disable-gpu -chromeosnopreallocate -noverifyfiles`.
- `SteamRuntimeReceiver` handles `am broadcast -a com.steamruntime.dev.CMD --es cmd start|stop|status`; `status`
  is written to `files/status.json`.
- Bind mounts: `files/ipc` over `/dev/shm` (Valve IPC creates `u0-ValveIPCSharedObj-Steam` there, readable by ports),
  and a refreshed copy of `/proc/net/tcp` over `/proc/net` (Android 16 hides it and Steam's CEF hangs without it).
- Cleans stale `.crash` sentinels, X11 locks and old IPC files at start (a leftover `.crash` made Steam exit 139).
- Login is interactive once through the in-app X display (Steam Guard etc.); credentials persist in Steam's own config.
- `overlay/lorie/src/main/rootfs-shims/`: `robustshim.c` (answers `get_robust_list`, which Android's seccomp blocks
  and Steam checks) and `fakelsof.c`, built for arm64 and shipped as assets.
- `sigreset.c`: signal handling fix for the embedded X server.
- Ports run in a **separate APK** with the same `android:sharedUserId` and signing key so they can read the host's
  `files/ipc`. Ports never run inside the container.

## Status: client build and login state

`status.json` (written by `SteamStatusExtras`, same in `overlay/` and `overlay-quest/`) additionally contains:

- `client_build`, `client_build_source`, `client_builddate`: identity of the Steam client in the rootfs (manifest
  `version` in `/root/steamrtarm64/package/steam_client_*.manifest`, else `builddate.txt`). The shim compares it with
  `client_build=` in `steamclient_patches.conf` (see `docs/PATCH_CONF.md`).
- `logged_on`, `account_present`, `owned_apps`, `probe_ifaces`, `login_probe`, `login_probe_error`,
  `login_probe_time`: result of `steamstate` (`rootfs-shims/steamstate.c`), a one-shot helper run inside PRoot
  (bounded by `timeout` and `alarm`, at most every 30 s, only once Steam and its IPC object are up). It tries
  `SteamClient021..017`, `SteamUser023..019`, `STEAMAPPS_INTERFACE_VERSION009..007` newest first and reports the
  versions that worked. `logged_on` is `null` while unknown. The SteamID is never published.
- Appids to check ownership of: `am broadcast -a com.steamruntime.dev.CMD --es cmd status --es appids 2868840,480`
  (stored in `files/probe_appids.txt`).

Build the helper like the other rootfs shims and place it in `lorie-app/src/main/assets/rootfs-shims/steamstate`:
`gcc -O2 -Wall -o steamstate steamstate.c -ldl` (aarch64 glibc, e.g. inside the rootfs). If the asset is absent
the probe reports `login_probe: "unavailable"` and everything else works as before.

## Building

```bash
./apply.sh steamrt          # clone upstream, apply patch + overlay
cd steamrt
```

Then, which this repo deliberately does not contain:

1. Put PRoot's arm64 native libs in `lorie-app/src/main/jniLibs/arm64-v8a/`: `libproot.so`, `libproot-loader.so`,
   `libproot-loader32.so`, `libtalloc.so`, `libandroid-shmem.so` (from a Termux/PRoot build).
2. Build `robustshim.c` and `fakelsof.c` for aarch64 and place them in `lorie-app/src/main/assets/rootfs-shims/`
   (`librobustshim.so`, `fakelsof`); the compile line is in the header of `robustshim.c`.
3. Create your own keystore (the patch expects `lorie-app/shared-debug.keystore`, alias `androiddebugkey`,
   password `android`; use the same key to sign every port so `sharedUserId` works).
4. `./gradlew assembleStandaloneDebug` (JDK 17, Android SDK/NDK). Output: `steam-runtime-dev-universal-*.apk`.
5. Provision the rootfs: a Debian trixie aarch64 tarball with Valve's Steam ARM64 client (`steamrtarm64`) and
   dependencies, placed at `<app external files>/rootfs.tar` (first run extracts it). Not included; see below.

Changing `sharedUserId` on an installed app requires uninstalling first (`INSTALL_FAILED_SHARED_USER_ID_INCOMPATIBLE`).

## Not in this repo (Valve / third-party)

Valve's Steam client and runtime, the Debian rootfs, PRoot/talloc binaries, and your Steam account. The host does
not redistribute any of them.
