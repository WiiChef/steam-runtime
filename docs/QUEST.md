# Meta Quest 3 build (stable)

Stable as of 2026-11-11: on a Quest 3 (Horizon OS, Android 14) the host keeps Steam logged on and Slay the Spire 2's `SteamAPI_Init` succeeds.

## Build

```powershell
powershell -ExecutionPolicy Bypass -File build-quest.ps1
```

Copies `host/overlay-quest` over the upstream Termux:X11 checkout in `quest-build/`, runs `./gradlew assembleStandaloneDebug`, and copies the APK out. Install with `adb install -r` only: the rootfs (about 8.7 GB) lives in the app data, so never uninstall.

## Quest differences from `host/overlay`

- **Software rendering by default** (`Build.MANUFACTURER == Oculus` or `oculus.hardware.vr.headtracking`). GPU mode fails on Quest: Zink/Turnip `VK_ERROR_OUT_OF_DEVICE_MEMORY`.
- **Steam stdout/stderr** go to `files/steam-stdout.log`; the exit code is recorded in `status.json`.
- **Openbox is killed after Steam returns**, so PRoot exits with Steam.
- **`steam.pipe` guard** (`removeNonFifoSteamPipe`): Steam's single-instance handoff uses the FIFO `/root/.steam/steam.pipe`. The Java rootfs extractor does not create FIFOs, so the host's `steam -shutdown` created a regular file containing `'.../steam' '-shutdown'`. Every later Steam start read it and quit cleanly (exit 0) about 6 s after launch. The host now deletes a non-FIFO `steam.pipe` before each launch and after each `steam -shutdown`.

## Steam client version pin

The port's bundled `libsteamclient.so` must match the client running in the host. The Quest rootfs is pinned to client **1788652215** (`builddate.txt`: Sep 1 2026). Client 1792618285 (Oct 21 2026) breaks the port with `IClientUtils::GetSteamEnvironmentForApp returned failure code 12`. The pin is set in both `/root/steam.cfg` and `/root/steamrtarm64/steam.cfg`:

```
BootStrapperInhibitAll=enable
BootStrapperForceSelfUpdate=disable
```

When the pin works, the bootstrap log says `Suppressing Steam update`. To move to a newer client, remove the pin, let Steam update, rebuild the port with the new `/root/androidarm64` libs, and re-check the shim's interface remap.

## Rootfs

Source: `rootfs-v955.tar` (Debian trixie aarch64 + Valve `steamrtarm64`), not in this repo. Push it to `/sdcard/Android/data/com.steamruntime.dev/files/rootfs.tar`, then start the service: `am start-foreground-service -n com.steamruntime.dev/com.termux.x11.SteamRuntimeService -a START`. Also open `MainActivity` so the X display has a surface.

The pin is also the default of the manifest installer (sr-steam-install, see [host/README.md](../host/README.md#steam-client-install-manifest-installer-pinned-build)). As of 2026-11-11 Valve's CDN no longer serves 1788652215: the live channels carry 1793740892 (steamdeck_publicbeta) and 1792618285 (steamdeck_stable), so a fresh manifest install of the pin needs an archived manifest; the prebuilt rootfs path is unaffected.
