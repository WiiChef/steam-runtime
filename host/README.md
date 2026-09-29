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
