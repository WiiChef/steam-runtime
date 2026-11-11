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

## Steam client install (manifest installer, pinned build)

Two ways to get Valve's Linux ARM64 client (`/root/steamrtarm64`) into the rootfs:

1. **Prebuilt rootfs (fallback, unchanged).** If `/root/steamrtarm64/steam` is already in the rootfs, the host does not
   touch the client. At service start it only runs `sr-steam-install --pin-only`, which makes sure `steam.cfg` has the
   inhibit flags (`BootStrapperInhibitAll=enable`, `BootStrapperForceSelfUpdate=disable`, in `/root` and the client dir)
   and records the client's build ID in `/root/steamrtarm64/pinned_build_id` if that file does not exist yet.
2. **Manifest install.** If the client is missing, the host runs `sr-steam-install --if-missing` inside PRoot (needs
   `curl`, `awk`, `sha256sum` and `unzip` or `python3` in the rootfs). It fetches Valve's channel manifest
   `steam_client_<channel>_linuxarm64` from the client CDN (`client-update.steamstatic.com`, with Akamai and Fastly as
   mirrors), requires the manifest build ID to equal the pin, keeps the arm64 blocks (`*_linuxarm64_linuxarm64`,
   `*_androidarm64_linuxarm64`) and shared blocks (`*_all`), downloads each zip resumably (`curl -C -`, retries, size and
   sha256 checked against the manifest, partial files kept in `/root/.sr-steam-install/parts-<pin>`), unpacks into
   `/root`, then writes `package/beta` (must match the channel), the `steam.cfg` flags and `pinned_build_id`. If the
   manifest has no arm64 blocks it logs `has no arm64 client package` with the block names and exits 4.

`pinned_build_id` is published as `"pinned_build_id"` in `files/status.json`. Log: `files/tmp/sr-steam-install.log`.
No client binaries are stored here; the client comes from Valve's CDN at run time. `host/pins/` holds the small text
manifest for build 1788652215, recovered from SteamTracking's archived `steam_client_linuxarm64` history (commit
[`bbc717da8d`](https://github.com/SteamTracking/SteamTracking/commit/bbc717da8d)). The installer uses this pin when
the live channel has moved on. Pass `--manifest FILE` or `--manifest-url URL` for other archived manifests.

On demand (Steam must be stopped; `flags` may contain `--force`, `--allow-newer`, `--dry-run`):

```
am broadcast -a com.steamruntime.dev.CMD --es cmd install [--es pin 1788652215] [--es channel steamdeck_publicbeta] [--es flags "--dry-run"]
```

### Pins and how to bump them

The default pin is **1788652215** (docs/QUEST.md); it is `DEFAULT_PIN` in `sr-steam-install`. Override with `--pin`,
`SR_STEAM_PIN`, or the `pin` extra above. Channel defaults to `steamdeck_publicbeta` (`steamdeck_stable` is also tried).

**Valve serves only the current manifest per channel.** Older manifests can be recovered from tracker history or the
Wayback/Internet Archive captures described in [Lightwo's Steam client downgrades survival kit](https://blog.lightwo.net/steam-client-downgrades-survival-kit.html).
The table pairs build IDs with archived manifest captures; package zips use the manifest's hashed filenames. Zips may
disappear from Valve's CDN over time, so check availability with `--dry-run` (it sends `HEAD` for each package). The
installer archives pins it sees in `/root/.sr-steam-install/manifests/`; alternatively supply a local manifest or URL.
Manifests are text metadata only; package downloads are still size and SHA-256 checked.

To bump the pin:

1. Check what Valve serves: `sr-steam-install --dry-run` (reads a manifest and sends `HEAD` for each package). For an
   older pin, see `host/pins/` or use `--manifest FILE` / `--manifest-url URL`. Lightwo's
   [downgrade table](https://blog.lightwo.net/steam-client-downgrades-survival-kit.html) maps build IDs to archived
   manifests; package zips use hashed filenames and may expire from Valve's CDN.
2. Rebuild the port against the new build's `androidarm64` libs and check the shim's interface remap (docs/QUEST.md:
   build 1792618285 broke the port with `GetSteamEnvironmentForApp` code 12).
3. Change `DEFAULT_PIN` in `host/overlay/.../rootfs-shims/sr-steam-install` and the copy under `host/overlay-quest/`,
   update docs/QUEST.md, then on the device run `install` with `--es pin <id> --es flags "--force"`.
   (`--allow-newer` installs whatever the channel serves now and re-pins to it.)

### Container guard (pressure-vessel)

If a future arm64 client ships containerized (Valve's `steamrt` with pressure-vessel, which needs bwrap, user
namespaces and a session bus), the host stays defensive: every PRoot environment gets
`STEAM_STEAMRT_RECURSION_GUARD=1` (the client then does not re-exec itself through `pressure-vessel-wrap`), and the
launch line runs `sr-steamrt-shim --quiet`. The shim does nothing unless the client carries
`pv-runtime/steam-runtime-steamrt` or a `steam-runtime-check-requirements` probe. In that case it builds
`/root/.sr-steamrt-shim` (Valve's runtime symlinked file by file, the probe replaced by `exit 0`,
`steam-runtime-launch-client` running commands directly) and the launcher sources its `env`
(`STEAM_RUNTIME_STEAMRT`, `PATH`). The current client is not containerized, so this is a no-op today.
Not exercised on a device yet.
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
