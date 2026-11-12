# SteamTest Android APK Build Notes

## Toolchain (on disk)
- NDK: C:\Android\ndk\r28c (CMake + Ninja bundled in toolchains/llvm/prebuilt/windows-x86_64/bin)
- JDK: C:\Java\jdk-17
- SDK: C:\Android\sdk (build-tools 35.0.0, platforms android-35)
- Keystore: C:\Android\debug.keystore (pass: android)
- Steamworks headers: C:\steamworks-sdk\sdk\public
- libsteam_api.so: C:\steamworks-sdk\sdk\redistributable_bin\androidarm64\libsteam_api.so

## Valve libs to package
Original SteamTest-signed.apk (sources/gemini_unmodified/binaries) contains lib/arm64-v8a:
libc++_shared.so, libsteam_api.so, libsteamclient.so, libsteamnetworkingsockets.so,
libsteamtest.so, libtier0_s.so, libvstdlib_s.so, steamservice.so

Extracted the Valve libs (all except libsteamtest.so and libc++_shared.so which the build
produces) into work/steamtest/prebuilt/.

## Changes to build_apk.py (work copy only)
- Paths now prefer env vars (JAVA_HOME, ANDROID_NDK_HOME, ANDROID_HOME/ANDROID_SDK_ROOT)
  with fallback to default paths.
- SRC changed from the original project dir to the work dir (script location).
- SO_DIR changed to <work>/prebuilt (Valve libs extracted from original APK).
- cmake/ninja resolved from NDK's prebuilt windows-x86_64 bin; falls back to PATH.

## Status
- [x] env.ps1 written
- [x] prebuilt/ extracted
- [ ] build

## Build result (success)
- New APK: build/SteamTest.apk, 20,710,393 bytes
- libs in new APK == original list exactly (8 .so files, same names)
- apksigner verify: OK (signed with C:\Android\debug.keystore, CN=Android Debug)
- Compile: only 1 warning (pointer-bool-conversion at sns_test.cpp:338), no errors; no source fixes needed.

## Shim build (2026-11-11)
- The APK bundles OUR shim (client/shim.c) as `libsteam_api.so` and Valve's library as `libsteam_api_real.so`;
  Valve libs come from `prebuilt/` (extract them from an installed port APK; never commit them).
- Headers: `tools/env.ps1` sets `STEAMWORKS_HEADERS` (checks `C:\steamworks-sdk\sdk\public`, then
  `D:\tmp\steamworks_headers`); set it yourself if your SDK lives elsewhere.
- Build: `. .\tools\env.ps1; python build_apk.py` -> `build/SteamTest.apk` (package `com.sts2.steamtest.guard`,
  sharedUserId `com.steamruntime.shared`; must be signed with the same key as the installed host).
- Headless test: `adb shell am start -n com.sts2.steamtest.guard/com.sts2.steamtest.SteamTest --es cmd init`, then
  `adb logcat -s StS2Shim SteamTest`. On Quest the headset must be awake (`am broadcast -a
  com.oculus.vrpowermanager.prox_close`; undo with `...automation_disable`), otherwise launches are ignored.
- Verified on Quest 3, host client 1788652215: guard match -> `SteamAPI_InitEx returned OK`, `logged_on=1`;
  `client_build=0000000` -> `Steam client build mismatch ...`, init code 1, no crash.
