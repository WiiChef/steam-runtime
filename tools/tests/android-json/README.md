# Android JSON test runtime

Unmodified AOSP libcore JSON sources from `android-12.0.0_r1`, matching Quest Android 12 semantics:
https://android.googlesource.com/platform/libcore/+/refs/tags/android-12.0.0_r1/json/src/main/java/org/json/

Apache 2.0 notices are retained in each source. Adjacent Android/libcore annotation stubs only enable host compilation; they do not alter JSON behavior. The runner compiles these sources directly, offline, with no Maven JSON dependency. Android SDK android.jar contains method stubs and cannot execute these tests.
