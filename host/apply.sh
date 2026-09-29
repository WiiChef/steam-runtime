#!/usr/bin/env bash
# Build the Steam Runtime host from upstream Termux:X11 + our patch/overlay.
set -euo pipefail
UPSTREAM_COMMIT=9c23bd3   # termux/termux-x11 this patch was made against
DEST="${1:-steamrt}"
HERE="$(cd "$(dirname "$0")" && pwd)"
git clone https://github.com/termux/termux-x11 "$DEST"
git -C "$DEST" checkout "$UPSTREAM_COMMIT"
git -C "$DEST" apply "$HERE/steam-runtime.patch"
cp -r "$HERE/overlay/." "$DEST/"
echo "Done. Next: add bundled arm64 libs (see host/README.md), create a signing keystore, then ./gradlew assembleStandaloneDebug in $DEST"
