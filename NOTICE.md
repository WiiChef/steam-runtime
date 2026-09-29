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
