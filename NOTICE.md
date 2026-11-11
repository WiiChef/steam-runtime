# Notice: third-party and Valve materials

This project is independent and is not affiliated with, endorsed by, or sponsored by Valve Corporation.
"Steam", "Steamworks" and related marks belong to Valve Corporation.

**This repository contains no Valve software and no non-public Valve information.** In particular it does not
contain, and its licence does not grant any rights to:

- Valve binaries (`libsteam_api.so`, `libsteamclient.so`, `steamservice.so`, `libtier0_s.so`, `libvstdlib_s.so`,
  `libsteamnetworkingsockets.so`, the Steam client or runtime);
- the Steamworks SDK or its headers (obtain them from Valve under the Steamworks SDK Access Agreement);
- offsets, instruction words or internal symbol names of any Valve binary. Runtime patches are read from a
  private file you create yourself (see `docs/PATCH_CONF.md`) and are never committed here.

You are responsible for obtaining Valve materials lawfully and for complying with the Steamworks SDK Access
Agreement and Steam Subscriber Agreement. The Steamworks API function and interface names that appear in
`client/trampolines.c` are those of the publicly distributed SDK and are used only for interoperability.

Other components keep their own licences: `host/` derives from Termux:X11 (GPLv3); PRoot, talloc and the
Debian rootfs used by the host are separate projects and are not included.

**DroidDeck attribution.** host/overlay/lorie-app/src/main/assets/rootfs-shims/sr-steam-install and sr-steamrt-shim (and the overlay-quest copies) are adapted from droiddeck-steam-install and droiddeck-steamrt-shim of DroidDeck (https://github.com/Droid-Deck/DroidDeck, 	ools/linuxfs/overlay/usr/local/bin/, docs/development/arm64-steam-client.md), licensed GPL-3.0, and are distributed here under GPL-3.0 (compatible with the GPLv3 host/). They download Valve's client from Valve's public client CDN at run time; no Valve binaries are included.
