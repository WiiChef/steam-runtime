# DroidDeck vs steam-runtime: research and comparison

Research date: 2026-11-11. Nothing in the repo was changed except this file.

**Evidence tags:** **[V]** = read directly from a primary source (GitHub API, repo files/docs, our own repo).
**[S]** = from web-search summaries only (the search tool returns LLM-written summaries with redirect URLs; not independently opened).
**[I]** = my inference.

## 1. What DroidDeck is

**Droid-Deck/DroidDeck** [V]: "brings the SteamOS experience to Android": Steam Gaming Mode, Linux desktop,
GOG/Epic/Xbox/itch/Amazon stores, SteamVR, smart-glasses and VR support.

| Fact | Value | Source |
|---|---|---|
| Repo | https://github.com/Droid-Deck/DroidDeck | [V] GitHub API |
| Latest release | **0.7.1, published 2026-11-10** (0.7.0 on 11-08, 0.6.9 on 10-31). Repo created 2026-09-24, pushed 2026-11-11 | [V] |
| Popularity | ~19.4k stars, language Kotlin (plus Rust, C, shell, Python) | [V] |
| License | **GPL-3.0** (`LICENSE`; README says "100% open source, no proprietary components, no source withheld") | [V] |
| Distribution | APK from GitHub Releases only ("DroidDeck has no website"; there are other `droiddeck.app` lookalikes, so be careful) | [V] README; [S] droiddeck.app |
| Components repo | Droid-Deck/DroidDeck-Components (GPL-3.0): prebuilt FEX, rootfs and esync packs, sha256-pinned | [V] |
| Docs worth reading | `docs/development/arm64-steam-client.md`, `proot-performance.md`, `x86-64-steam-client.md`, `low-memory.md`, `docs/quest.md`, `tools/proot/PATCHES.md` | [V] |
| Hardware | Android 9+, Adreno 730+ or any 8xx; Adreno 6xx, Mali, Xclipse and PowerVR experimental; 3 GB runtime plus 1.1 GB desktop. No root. Android 14+ needs "Disable child process restrictions" | [V] README |
| Builds on | WinNative and Bannerlator (maxjivi05) for runtime, shim and input; FEX, Proton ARM64, Mesa Turnip, gamescope, PRoot | [V] README credits |

**Similarly named or comparable projects**

| Project | What it is | License / status | Tag |
|---|---|---|---|
| GameNative (utkarshdalal) | Pluvia fork; reimplemented Steam protocol (JavaSteam) plus Winlator-style Wine; also Epic/GOG/Amazon. Native Android ARM64, not a real client | GPL-3.0, v1.4.0 on 2026-11-05, pushed 2026-11-11 | [V] repo and license; [S] JavaSteam use |
| Pluvia (oxters168) | Original JavaSteam-based Android Steam client | GPL-3.0, retired (last push 2026-02) | [V] |
| JavaSteam (Longi94) | Java/Kotlin port of SteamKit2: auth, library, cloud, depot download. **No Steamworks game API** | MIT, pushed 2026-10-29 | [V] license and date |
| Winlator (brunodev85) | Wine plus Box64 containers; many forks (cmod, bionic). Windows Steam under translation | LGPL-2.1, pushed 2026-11-02 | [V] |
| FEX-Emu | x86/x64 user-mode emulator for ARM64, used by DroidDeck and Proton ARM64 | MIT | [V] |
| PRoot (proot-me) | ptrace-based rootless chroot; used by DroidDeck and us | GPL-2.0 | [V] |
| Valve ARM64 Steam client / Steam Frame / Lepton | Valve publishes `steamrtarm64` on the Steam Deck client channels (confirmed by DroidDeck docs). Steam Frame (Snapdragon) and "Lepton" (Android APK compatibility) are only from search summaries | proprietary | [V] channel; [S] Frame/Lepton |
| GameHub forks | Not found or verified with the available tools | n/a | not verified |

## 2. How DroidDeck works technically

**Login and Steam client [V].** DroidDeck runs the **real Valve client**: `droiddeck-steam-install` fetches the
`steamrtarm64` build from Valve's CDN (manifest `steam_client_steamdeck_publicbeta_linuxarm64`, stable as fallback).
The session starts `~/.local/share/Steam/steamrtarm64/steam` with `STEAM_RUNTIME=1`. It is **not** a SteamKit/JavaSteam
reimplementation. The user signs in inside Steam's own UI (Big Picture, shown by gamescope and a Vulkan Wayland
compositor). Token/cookie reading is limited to the helper `SteamWebLogin.kt`, which decrypts Chromium cookies for the
web session.

**Steamworks services [V/I].** Games run **inside the same PRoot session** as the client. Proton's own `lsteamclient`
talks to the real client over Valve IPC, so friends, lobbies, matchmaking, SDR/P2P networking, achievements and cloud all
come from Valve's client unchanged **[I]**. `droiddeck-steam-games` shows the app also talks to the running client
through the versioned interfaces (SteamClient020, SteamUser021, STEAMAPPS_INTERFACE_VERSION008, `BIsSubscribedApp`) from
a helper subprocess to read ownership. No native Android port attaches from a separate APK (no sharedUserId design
found).

**Emulation [V].** Windows games: Valve ARM64 **Proton** (arm64ec Wine with **FEX loaded in-process as a DLL**) plus DXVK/VKD3D
over **Turnip** (open-source Adreno Vulkan). x86 Linux games: FEX with an x86 rootfs. An optional x86-64 Steam client
(SteamRT3 `steamrt64`) runs under FEX. Native ARM64 Linux games run directly.

**Container [V].** **PRoot is kept on purpose.** `proot-performance.md` ("Don't drop proot") says PRoot also answers the
syscalls Android's app seccomp blocks (`rseq`, `set_robust_list`, `faccessat2`, `openat2`, `set*id`, ...). Glibc dies
with SIGSYS on the first `pthread_create` without it. Path syscalls cost 15-60 µs each through a single tracer
thread (~75-95k traps/s). They carry a patch series (0004-0014) and an in-process fast path (`stat` 25 µs to 0.6 µs).
`libblsession.so` is preloaded into every guest process through `/etc/ld.so.preload`.

**Display [V].** gamescope in a Vulkan Wayland compositor; GPU-accelerated for Steam and games. Desktop compositing is
software-rendered. **Root [V]:** none.

**Performance and resources [V].** Measured on SM8850 (Snapdragon 8 Elite Gen 5): PRoot is near-native in gameplay
and costly at startup and asset loading. They have a low-memory reclaim monitor (PSI and `MemAvailable`, page-out
requests for the launcher after game focus) and a VRAM budget doc. Battery cost is not documented.

**Quest 3 [V].** `docs/quest.md`: a Quest build with a bundled `turnip25.1.0-quest1` driver plus `kgsl_compat.c`.
SELinux denies the `KGSL_GPUOBJ_*` and `CMDSTREAM_READTIMESTAMP_CTXTID` ioctls; the adapter retries through
`GPUOBJ_ALLOC` and answers the timestamp ioctl from `WAITTIMESTAMP`. "Quest 3 testers have successfully launched
games." Whether this is stable is not established by the docs.

## 3. Comparison with steam-runtime

Our side is from `README.md`, `host/README.md`, `docs/QUEST.md`, `docs/PATCH_CONF.md` and `client/shim.c` [V].

| Dimension | steam-runtime (ours) | DroidDeck | GameNative / JavaSteam (for contrast) |
|---|---|---|---|
| Architecture | Resident Valve ARM64 client in PRoot + Debian + Xvfb/X11 (Termux:X11 fork) as a foreground service. **Android-native ports** attach from a separate APK via `libsteam_api.so` shim, Valve IPC shared memory and sharedUserId | Same real client in PRoot, plus gamescope and a Vulkan compositor. Games run **inside** the session (Proton/FEX). It is a launcher/OS-in-an-app | Reimplemented protocol (JavaSteam) in the Android app; games in Wine/Box64 containers |
| Steamworks coverage | Full via Valve's real client and library (friends, lobbies, matchmaking, SDR, achievements, cloud); the shim only bridges IPC. The UID spoof and patches are fragile | Full inside the session via real client + `lsteamclient` **[I]**; not exposed to external Android apps | Partial. Login/library/cloud/download; the game API is emulated or Goldberg-style. No SDR **[I]** |
| Native ARM64 vs translated | **Native ARM64 game ports** (first: StS2 Godot/.NET). No emulation | Mostly translated (Proton + FEX), native ARM64 Linux games supported | Translated (Box64/Wine) |
| Resource / battery | Steam + CEF + Xvfb + openbox + dbus run permanently. Rootfs ~8.7 GB; software-rendered X; Quest 3 uses software rendering | Same resident client, but GPU path (Turnip) and a memory-reclaim monitor. Heavier when a game runs | Light idle (no CEF); heavy in game |
| Login UX | One-time interactive login in the in-app X display (Steam Guard) | Login inside Steam UI in a GPU compositor; docs target handheld/touch | In-app login form (JavaSteam auth, QR/2FA) |
| Robustness to client updates | **Weak.** Offsets/instruction words per client build (private `steamclient_patches.conf`). Pinned to build 1788652215 via `steam.cfg`; build 1792618285 broke the port (`GetSteamEnvironmentForApp` code 12) | Moderate [V]. No patching of libsteamclient; channel pinning (`package/beta` must match `-clientbeta`), automatic fallback to stable, manifest-based installer, `STEAM_STEAMRT_RECURSION_GUARD`, steamrt shim | Strong (protocol is stable) but needs SteamKit updates |
| Distribution / license | Host GPLv3 (Termux:X11 derivative); shim and rest MIT. Valve binaries not redistributed; Steam SDK/SSA compliance unverified | GPL-3.0, APK via GitHub; downloads Valve client from Valve's CDN on the device | GPL-3.0 (GameNative), MIT (JavaSteam); needs no Valve binary |
| Device support | arm64 only; Pixel/Android 16 + Quest 3 (software GL) | Adreno 730+ / 8xx; Mali etc. experimental; Quest bundle | Broad Android |
| Root | none | none | none |

Net: DroidDeck is the same "real arm64 client under PRoot" design, 3-4x further along in the engineering around it
(performance, updates, GPU, Quest). The main difference is that **our product is a service that external
native Android apps attach to**, while DroidDeck keeps everything inside its own proot **[I]**.

## 4. Leverage list

License rule of thumb: DroidDeck is GPL-3.0, so its code **can** go into our GPLv3 `host/`. Copying it into the MIT
shim/client would force that part to GPLv3 (or a separate GPLv3 component). Ideas and documentation are free to
reuse. PRoot patches inherit PRoot's GPL-2.0-or-later and fit a GPLv3 host as a separate binary.
All items below should be treated as hypotheses until prototyped on our devices.

| # | Technique | Source of idea | Expected benefit | Effort | License fit | Risk | Tag |
|---|---|---|---|---|---|---|---|
| 1 | **Manifest-based client install + pinned channel.** Fetch `steamrtarm64` from Valve's CDN by manifest/build ID (sha256, resumable) instead of a hand-built `rootfs.tar`. Use `-clientbeta` and `package/beta` consistently. Pin by build ID. Keep `BootStrapperInhibitAll` | `arm64-steam-client.md`, `droiddeck-steam-install` | Reproducible builds; smaller shipped rootfs (we don't ship Valve files); update policy under our control; fixes the ~8.7 GB rootfs problem partly | M | Idea: free. Code: GPLv3 host OK | Valve may drop `*_linuxarm64_linuxarm64`; the installer must log the block list. SSA/ToS | V (docs) |
| 2 | **Pin the client and the port's `libsteamclient.so` together.** Our rootfs pin (1788652215) mirrors this. Add a startup check comparing `builddate`/build ID in `status.json` to the port's expected build and refuse to attach instead of crashing | our QUEST.md plus DroidDeck pinning | Fewer "code 12" failures; clearer errors | S | ours | low | I |
| 3 | **PRoot patch series + in-process fast path** (`tools/proot/patches` 0004-0014, `fastpath/`, `libblsession.so` preload through `/etc/ld.so.preload`) | `proot-performance.md`, `PATCHES.md` | Faster Steam startup and CEF loads (path syscalls 25 µs to ~1 µs; ~75-95k traps/s limit lifted). Directly helps Quest/Pixel boot time and battery | M-L | PRoot GPL-2.0+; fits our host as a separate binary. Their glue code GPL-3.0 | Subtle path-equivalence bugs; verify with their equivalence suite; tied to our PRoot build | V (docs); gains on our devices unmeasured |
| 4 | **Keep PRoot; don't drop it** (documented analysis). Do not spend effort on a pure-glibc setup | `proot-performance.md` | Avoids a large dead-end; our own seccomp issues (`get_robust_list` shim in `robustshim.c`) are the same class of problem | S (decision) | n/a | none | V |
| 5 | **Replace Xvfb/X11 with a GPU path (gamescope or Wayland compositor + Turnip)** for the *Steam UI* only. Login needs the UI occasionally; the Steam client can run with `-cef-disable-gpu` hidden after login | `SessionDisplay`, `waylandcomp`, gamescope | Better login UX/battery; our Quest 3 is software-only | L | GPLv3 compat; Mesa MIT; gamescope BSD-2 | Large. Our X server is the Termux:X11 fork; a compositor swap is a new project. Not needed for ports that render in the Android app | I |
| 6 | **Quest 3 GPU enablement via `kgsl_compat.c` + bundled Quest Turnip** to remove the "software rendering by default" limit (Zink/Turnip `OUT_OF_DEVICE_MEMORY`) | `docs/quest.md`, `tools/quest/` | GPU Steam UI on Quest; less CPU load when a port is also running | M | GPL-3.0 code into GPLv3 host: OK | Their claim is "testers launched games", not stable. Quest/Horizon OS updates can break SELinux assumptions. Our OOM may be a different cause | V (docs); fit for us I |
| 7 | **Container-shim for pressure-vessel** (`STEAM_STEAMRT_RECURSION_GUARD=1`, steamrt shim with the probe replaced) so a containerized arm64 client still starts if Valve ships it | `arm64-steam-client.md` | Future-proofing for the next client build | S-M | GPLv3 host OK | Only relevant if Valve containerizes the arm64 client | V |
| 8 | **Low-memory reclaim** (PSI/`MemAvailable` monitor, page-out request for launcher processes) | `low-memory.md` | Frees RAM for the game on 8-12 GB devices; our client + CEF stays resident | M | uses their `libblsession` page-out; GPLv3 OK | Android may kill the foreground service anyway | V (docs) |
| 9 | **Ownership/identity helper via versioned interfaces** (`SteamClient020/SteamUser021/BIsSubscribedApp` through a bounded subprocess) to detect login state / ownership before starting a port, without parsing UI/logs | `droiddeck-steam-games` | Real login-state signal for `status.json`; ports start only when ready | S-M | Python script GPL-3.0; reimplement in our host (GPLv3) | Interface versions vary per client build | V (docs) |
| 10 | **Headless login** options: (a) read the saved token/cookies from the client's config (their `SteamWebLogin` decrypts the Chromium cookie store) to detect a logged-in session; (b) a protocol login with JavaSteam (MIT) to obtain a refresh token the real client can reuse. (b) is **not** shown to work with the client | `SteamWebLogin.kt`; JavaSteam (MIT) | (a) cheap login detection; (b) could remove the X11 login but only if the client accepts an externally minted token | (a) S; (b) L, research | JavaSteam MIT; (a) GPLv3 host | (b) speculative: Steam Guard/anti-abuse; ToS. Do not rely on it | (a) V; (b) I |
| 11 | **Reimplemented protocol client as a fallback for logged-out state** (JavaSteam/SteamKit: library, cloud, depot download) | GameNative/JavaSteam | Browse library/download without the client | L | MIT/GPLv3 OK | Does **not** provide Steamworks API for games (no IPC), so it does not replace our design | I |
| 12 | **Preload shim pattern (`libblsession`)** for blocked syscalls (`openat2`, `faccessat2`, `futex_waitv`) beyond `robustshim.c` | `tools/linuxfs/preload/*.c` | Fewer crashes in Steam helpers under seccomp | S-M | GPLv3 host OK (code); shim MIT can't take it | low | V (existence); fit I |
| 13 | **Tracer hiding** (tier0 sees PRoot as a debugger and `int3`s; hide it only for opens from `libtier0_s.so`) | `x86-64-steam-client.md` | Avoids SIGTRAP on web helpers; check whether we hit it | S | GPLv3 host OK | low | V (doc) |
| 14 | **Run the game inside the session (DroidDeck model) as a fallback to the shared-UID IPC** | DroidDeck session layout | Removes the sharedUserId/signing constraint and the 3rd-party signature coupling | L; breaks "native Android app" model | n/a | Our value proposition is native Android ports; not recommended | I |

### Recommended order
1. **#2 and #9** (small, ours): build-ID guard and a real login-state signal.
2. **#1** (manifest/CDN install with channel pin) and **#7** to reduce shipped Valve content and breakage per update.
3. **#3** and **#6** if startup time or Quest software rendering become the limiting factor (measure first).
4. **#5**, **#10(b)**, **#11**, **#14**: larger research bets; only #5 has a clear path.

## 5. Limits and verification notes

- Everything marked [V] was fetched from GitHub (API metadata, README, docs, selected scripts) on 2026-11-11.
  I did **not** read DroidDeck's Rust/Kotlin internals in depth, so Steamworks behaviour for games is **[I]**
  (derived from "Proton inside the same PRoot with the real client").
- I found **no evidence** that DroidDeck exposes Steamworks to external native Android apps, patches
  `libsteamclient.so`, or uses sharedUserId IPC. Absence in the files I read is not proof.
- Web-search results for Steam Frame, Lepton and GameHub are summaries with redirect URLs. Treat them as [S] and unverified.
- Legal: DroidDeck downloads Valve's client on-device and calls it unsupported by Valve. Whether that satisfies Valve's SSA is
  unverified for both projects (same caveat as our README).
- Quest comparisons use DroidDeck's own docs (self-reported) vs our own measured software-rendering note.

## Sources (primary)

- https://github.com/Droid-Deck/DroidDeck (README, LICENSE, releases: 0.7.1 on 2026-11-10)
- https://github.com/Droid-Deck/DroidDeck/blob/HEAD/docs/development/arm64-steam-client.md
- https://github.com/Droid-Deck/DroidDeck/blob/HEAD/docs/development/proot-performance.md
- https://github.com/Droid-Deck/DroidDeck/blob/HEAD/docs/development/x86-64-steam-client.md
- https://github.com/Droid-Deck/DroidDeck/blob/HEAD/docs/development/low-memory.md
- https://github.com/Droid-Deck/DroidDeck/blob/HEAD/docs/development/steam-game-imports.md
- https://github.com/Droid-Deck/DroidDeck/blob/HEAD/docs/quest.md
- https://github.com/Droid-Deck/DroidDeck-Components
- https://github.com/utkarshdalal/GameNative, https://github.com/oxters168/Pluvia, https://github.com/Longi94/JavaSteam
- https://github.com/brunodev85/winlator, https://github.com/FEX-Emu/FEX, https://github.com/proot-me/proot
