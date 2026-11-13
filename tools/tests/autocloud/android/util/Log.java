package android.util;

/** Keep host test output limited to the pass/fail summary. */
public class Log {
    public static final java.util.List<String> warnings = new java.util.ArrayList<>();
    public static int i(String tag, String message) { return 0; }
    public static int w(String tag, String message) { warnings.add(message); return 0; }
}
