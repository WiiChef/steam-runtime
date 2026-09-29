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
