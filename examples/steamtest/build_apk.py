import os
import sys
import shutil
import subprocess
import zipfile
def _env_or(name, *fallbacks):
    v = os.environ.get(name)
    if v and os.path.isdir(v):
        return v
    for f in fallbacks:
        if os.path.exists(f):
            return f
    raise FileNotFoundError(name + " not set and no fallback found: " + ", ".join(fallbacks))

WORK = os.path.dirname(os.path.abspath(__file__))
SDK = _env_or("ANDROID_HOME", "ANDROID_SDK_ROOT", r"C:\Android\sdk")
NDK = _env_or("ANDROID_NDK_HOME", r"C:\Android\ndk\r28c")
JDK = _env_or("JAVA_HOME", r"C:\Java\jdk-17")
_bt = os.path.join(SDK, "build-tools")
BT = sorted(os.path.join(_bt, d) for d in os.listdir(_bt) if os.path.isdir(os.path.join(_bt, d)))[-1]
PLAT = os.path.join(SDK, "platforms", "android-35", "android.jar")
JDK_BIN = os.path.join(JDK, "bin")

AAPT2 = os.path.join(BT, "aapt2.exe")
ZIPALIGN = os.path.join(BT, "zipalign.exe")
APKSIGNER = os.path.join(BT, "apksigner.bat")
KEYSTORE = r"C:\Android\debug.keystore"

STEAM_LIB = os.environ.get("STEAM_LIB") or r"C:\steamworks-sdk\sdk\redistributable_bin\androidarm64\libsteam_api.so"
if not os.path.exists(STEAM_LIB):
    STEAM_LIB = os.path.join(WORK, "prebuilt", "libsteam_api.so")
os.environ.setdefault("STEAMWORKS_HEADERS", r"C:\steamworks-sdk\sdk\public")
SO_DIR = os.path.join(WORK, "prebuilt")  # Valve libs extracted from original SteamTest-signed.apk
LIBCXX = os.path.join(NDK, "toolchains", "llvm", "prebuilt", "windows-x86_64", "sysroot", "usr", "lib", "aarch64-linux-android", "libc++_shared.so")

SRC = WORK
OUT = os.path.join(SRC, "build")
APK_LIB_DIR = os.path.join(OUT, "apk", "lib", "arm64-v8a")
CLASSES_DIR = os.path.join(OUT, "classes")
DEX_DIR = os.path.join(OUT, "dex")
NATIVE_DIR = os.path.join(OUT, "native")

def run(cmd, cwd=None):
    print("Running:", " ".join(cmd) if isinstance(cmd, list) else cmd)
    res = subprocess.run(cmd, cwd=cwd, check=True)

def main():
    print("=== [1/5] Setting up build directories ===")
    if os.path.exists(OUT):
        shutil.rmtree(OUT)
    os.makedirs(APK_LIB_DIR, exist_ok=True)
    os.makedirs(CLASSES_DIR, exist_ok=True)
    os.makedirs(DEX_DIR, exist_ok=True)
    os.makedirs(NATIVE_DIR, exist_ok=True)

    print("=== [2/5] Compiling native JNI bridge (CMake + Ninja) ===")
    cmake_cmd = [
        "cmake",
        "-S", SRC,
        "-B", NATIVE_DIR,
        "-G", "Ninja",
        f"-DCMAKE_TOOLCHAIN_FILE={os.path.join(NDK, 'build', 'cmake', 'android.toolchain.cmake')}",
        "-DANDROID_ABI=arm64-v8a",
        "-DANDROID_PLATFORM=android-29",
        "-DANDROID_STL=c++_shared",
        "-DCMAKE_BUILD_TYPE=Release",
        f"-DSTEAMWORKS_LIB={STEAM_LIB}",
    ]
    run(cmake_cmd)
    run(["ninja"], cwd=NATIVE_DIR)

    # Copy native libraries
    shutil.copy(os.path.join(NATIVE_DIR, "libsteamtest.so"), APK_LIB_DIR)
    shutil.copy(STEAM_LIB, os.path.join(APK_LIB_DIR, "libsteam_api.so"))
    shutil.copy(LIBCXX, APK_LIB_DIR)
    for f in os.listdir(SO_DIR):
        if f.endswith(".so"):
            shutil.copy(os.path.join(SO_DIR, f), APK_LIB_DIR)
    print(f"  Copied {len(os.listdir(APK_LIB_DIR))} native libraries to {APK_LIB_DIR}")

    print("=== [3/5] aapt2: Compiling Manifest and Resources ===")
    manifest = os.path.join(SRC, "AndroidManifest.xml")
    base_apk = os.path.join(OUT, "base.apk")
    aapt_cmd = [
        AAPT2, "link",
        "-o", base_apk,
        "--manifest", manifest,
        "-I", PLAT,
        "--min-sdk-version", "29",
        "--target-sdk-version", "35"
    ]
    run(aapt_cmd)

    print("=== [4/5] Compiling Java code and building DEX ===")
    javac = os.path.join(JDK_BIN, "javac.exe")
    java = os.path.join(JDK_BIN, "java.exe")
    d8_jar = os.path.join(BT, "lib", "d8.jar")

    java_src = os.path.join(SRC, "src", "com", "sts2", "steamtest", "SteamTest.java")
    javac_cmd = [
        javac,
        "--release", "8",
        "-classpath", PLAT,
        "-d", CLASSES_DIR,
        java_src
    ]
    run(javac_cmd)

    class_files = []
    for root, _, files in os.walk(CLASSES_DIR):
        for f in files:
            if f.endswith(".class"):
                class_files.append(os.path.join(root, f))

    d8_cmd = [
        java, "-cp", d8_jar,
        "com.android.tools.r8.D8",
        "--lib", PLAT,
        "--min-api", "29",
        "--output", DEX_DIR
    ] + class_files
    run(d8_cmd)

    print("=== [5/5] Packaging, Aligning, and Signing APK ===")
    unsigned_apk = os.path.join(OUT, "unsigned.apk")
    shutil.copy(base_apk, unsigned_apk)

    with zipfile.ZipFile(unsigned_apk, "a", zipfile.ZIP_DEFLATED) as z:
        z.write(os.path.join(DEX_DIR, "classes.dex"), "classes.dex")
        for f in sorted(os.listdir(APK_LIB_DIR)):
            p = os.path.join(APK_LIB_DIR, f)
            arc = f"lib/arm64-v8a/{f}"
            z.write(p, arc)

    aligned_apk = os.path.join(OUT, "SteamTest-aligned.apk")
    final_apk = os.path.join(OUT, "SteamTest.apk")

    run([ZIPALIGN, "-f", "4", unsigned_apk, aligned_apk])
    apksigner_jar = os.path.join(BT, "lib", "apksigner.jar")
    run([java, "-jar", apksigner_jar, "sign", "--ks", KEYSTORE, "--ks-pass", "pass:android", "--key-pass", "pass:android", "--out", final_apk, aligned_apk])

    print(f"\n==========================================")
    print(f"SUCCESS! Output APK: {final_apk}")
    print(f"Size: {os.path.getsize(final_apk)} bytes")
    print(f"==========================================")

if __name__ == "__main__":
    main()
