#!/usr/bin/env python3
"""Convert the ATO shim's inline libsteamclient writes to a private patch conf."""

import argparse
import hashlib
import re
from pathlib import Path


def convert(source: Path, library: Path, client_build: str) -> list[str]:
    text = source.read_text(encoding="utf-8")
    text = re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)
    entries: list[tuple[str, int, int | None]] = []

    for match in re.finditer(
        r"\*\s*\(\s*uint8_t\s*\*\s*\)\s*\(\s*clientBase\s*\+\s*(0x[0-9a-fA-F]+)\s*\)\s*=\s*(0x[0-9a-fA-F]+|\d+)",
        text,
    ):
        entries.append(("u8", int(match.group(1), 16), int(match.group(2), 0)))

    for match in re.finditer(
        r"\*\s*\(\s*const\s+char\s*\*\s*\*\s*\)\s*\(\s*clientBase\s*\+\s*(0x[0-9a-fA-F]+)\s*\)\s*=\s*s_steamInstallPath",
        text,
    ):
        entries.append(("ptr", int(match.group(1), 16), None))

    pointers = {
        name: int(offset, 16)
        for name, offset in re.findall(
            r"uint32_t\s*\*\s*(p\w+)\s*=\s*\(\s*uint32_t\s*\*\s*\)\s*\(\s*clientBase\s*\+\s*(0x[0-9a-fA-F]+)\s*\)",
            text,
        )
    }
    for match in re.finditer(r"\*(p\w+)\s*=\s*(0x[0-9a-fA-F]+)", text):
        if match.group(1) in pointers:
            entries.append(("u32", pointers[match.group(1)], int(match.group(2), 16)))
    for match in re.finditer(r"(p\w+)\[(\d+)\]\s*=\s*(0x[0-9a-fA-F]+)", text):
        if match.group(1) in pointers:
            entries.append(("u32", pointers[match.group(1)] + 4 * int(match.group(2)), int(match.group(3), 16)))

    # The ATO source logs the words present before overwriting them but does not
    # declare expected originals. Verify each patch site against the exact
    # library selected from the installed port and reject an already patched
    # or truncated target before writing any config.
    image = library.read_bytes()
    code = [entry for entry in entries if entry[0] == "u32"]
    if len(entries) != 20 or len(code) != 16 or sum(e[0] == "u8" for e in entries) != 2 or sum(e[0] == "ptr" for e in entries) != 2:
        raise ValueError(f"unexpected patch shape: {len(entries)} entries")
    for kind, offset, value in entries:
        width = 1 if kind == "u8" else 4 if kind == "u32" else 8
        if offset < 0 or offset + width > len(image):
            raise ValueError("patch site lies outside selected libsteamclient.so")
        if kind == "u32" and int.from_bytes(image[offset : offset + 4], "little") == value:
            raise ValueError("selected library already contains a replacement instruction")
    return [f"client_build={client_build}"] + [
        f"{kind} {offset:x}" if value is None else f"{kind} {offset:x} {value:x}"
        for kind, offset, value in sorted(entries, key=lambda item: item[1])
    ]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("ato_shim", type=Path)
    parser.add_argument("libsteamclient", type=Path, help="exact library extracted from selected port APK")
    parser.add_argument("output", type=Path, help="private steamclient_patches.conf destination")
    parser.add_argument("--client-build", required=True)
    args = parser.parse_args()
    lines = convert(args.ato_shim, args.libsteamclient, args.client_build)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("# Private runtime patch config; do not commit.\n" + "\n".join(lines) + "\n", encoding="ascii")
    print(f"validated {len(lines) - 1} patch entries; library SHA-256 {hashlib.sha256(args.libsteamclient.read_bytes()).hexdigest()[:16]}")


if __name__ == "__main__":
    main()
