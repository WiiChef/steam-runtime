# steam-runtime

A **Steam services host for Android ports**. It keeps a real, logged-in Steam client running on an Android device
(arm64) so native ports of PC games can use genuine Steam identity, friends, lobbies, matchmaking and networking,
with no x86 translation and no Steam emulation. First port: Slay the Spire 2 (Steamworks.NET).

| Directory | What | Role |
|---|---|---|
| [`host/`](host) | The Steam Runtime app (`com.steamruntime.dev`, a Termux:X11 fork, GPLv3) | **The product.** One install, shared by all ports |
| [`client/`](client) | `libsteam_api.so` shim for ports | What each port bundles to attach to the host |
| [`examples/steamtest/`](examples/steamtest) | Standalone JNI test app | Verifies the connection without a game |

> **Status:** working prototype extracted from the StS2 port. Read
> [Proprietary / Steam-provided components](#proprietary--steam-provided-components) before distributing binaries.

## How it works

```
+---------------------------- Android device (arm64) --------------------------------+
|  Port app (native ARM64: Godot/.NET, ...)                                          |
|    game --P/Invoke--> libsteam_api.so  (client/ shim)                              |
|                          | forwards to Valve's libsteam_api_real.so                |
|                          v                                                         |
|                       libsteamclient.so  (Valve, Bionic ARM64, patched in memory)  |
|                          |  Valve IPC: shared-memory file + TCP loopback           |
|  Steam Runtime host app (host/, foreground service)                                |
|    PRoot (fake root) -> Debian ARM64 rootfs -> Xvfb/X11 + openbox + dbus           |
|      Valve's Linux ARM64 Steam client (steamrtarm64)                               |
+---------------------------------|--------------------------------------------------+
                                  v
                       Steam backend (login, matchmaking, relay)
```

**Host.** Boots a Debian userspace under PRoot (no root needed) and runs Valve's native Linux ARM64 Steam client
in it as a resident daemon; you log in once through an in-app X display. The client's IPC shared-memory file
`u0-ValveIPCSharedObj-Steam` lands in the host's `files/ipc/`, which ports read via a shared Android UID
(same `sharedUserId` + signing key). Details: [`host/README.md`](host/README.md).

**Client shim.** The port loads our `libsteam_api.so` (Valve's real one is bundled as `libsteam_api_real.so`):

- `trampolines.c` exports the flat `SteamAPI_*` symbols Steamworks.NET expects (some were dropped in SDK 1.65) as
  ARM64 stubs forwarding to the real library.
- `shim.c` spoofs `getuid()`/`geteuid()` to 0 (matching the daemon's fake root, so the client asks for `u0-...`
  IPC), redirects `open`/`openat`/`shm_open` for `ValveIPCSharedObj-Steam` to the host's IPC path, answers the
  `lepton.steamclient.path` system property, writes `steam_appid.txt`, and wraps init/shutdown so repeated
  init cycles are safe.
- It applies small in-memory patches to the Valve client library so a separate process can attach to the host's
  Steam client. The patch data (offsets and instruction words) is **not in this repo**: it is read at runtime from a
  private `steamclient_patches.conf` that you create for your exact library build (`docs/PATCH_CONF.md`). Without it the
  shim still loads but won't attach.

The game then calls Steamworks normally; calls go through Valve's client library and IPC to the host, which does
the real network work.

## Building

- **Host:** see [`host/README.md`](host/README.md) (`host/apply.sh` applies our patch to upstream Termux:X11).
- **Client shim:** arm64 shared object built with the NDK from `client/shim.c` + `client/trampolines.c`. No build
  script yet. AppID (`2868840`), package names and IPC paths are hard-coded in `shim.c`.
- **Test app:** `examples/steamtest/` (`BUILD_NOTES.md`, `build_apk.py`, `tools/env.ps1`): NDK r28c, JDK 17, Android SDK
  35, a debug keystore, plus Valve's libs in `prebuilt/`.

## Proprietary / Steam-provided components

**Not in this repo; must come from Valve/Steam or the game (`.gitignore` excludes `*.so`, `prebuilt/`, `build/`):**

| Component | Source |
|---|---|
| `libsteam_api.so` (bundled as `libsteam_api_real.so`) | Steamworks SDK `redistributable_bin/androidarm64` |
| `libsteamclient.so`, `steamservice.so`, `libtier0_s.so`, `libvstdlib_s.so`, `libsteamnetworkingsockets.so` | Valve's Android Steam client redistributable |
| Steamworks SDK headers | Steamworks SDK 1.65 (needs a Steamworks partner account / SDK licence) |
| **The Steam client itself** (Linux ARM64 `steamrtarm64`, CEF/webhelper, Steam runtime) run inside the host | Valve; provisioned into the rootfs by you, never redistributed here |
| Debian ARM64 rootfs, PRoot / talloc binaries | Debian, PRoot projects (own licences) |
| Termux:X11 (the host is derived from it) | github.com/termux/termux-x11, GPLv3 |
| Steam account, ownership of the game, Steam Guard | The player |
| Game binaries and assets | The publisher, via Steam |

**Deliberately not in this repo:** Valve binaries, the Steamworks SDK/headers, and any offsets, instruction words or
internal symbol names of Valve's libraries (they are loaded from a private, git-ignored `steamclient_patches.conf`).
The only Valve-related content here is the public Steamworks API/interface names used for interoperability
(see [`NOTICE.md`](NOTICE.md)). Whether running Valve's client this way is permitted by the Steamworks SDK Access
Agreement / Steam Subscriber Agreement is **unverified**; that is your responsibility before distributing binaries.

## Limitations

- Requires a provisioned rootfs and a logged-in Steam client in the host.
- Patches are specific to one build of Valve's library (your private conf); Steam self-update can break it (the host blocks updates via `steam.cfg`).
- Hard-coded AppID / package names / IPC paths; not generalised for additional ports yet.
- arm64-v8a only; Windows-oriented example tooling.

## Licensing

`host/` is GPLv3 (Termux:X11 derivative, see `host/LICENSE`). Everything else is MIT (see [`LICENSE`](LICENSE)).
See [`NOTICE.md`](NOTICE.md) for what this repo does and does not license (no Valve software or non-public Valve data).
