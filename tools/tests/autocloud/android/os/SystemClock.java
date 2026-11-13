package android.os;

/** Host-only compile stub. */
public class SystemClock {
    public static long elapsedRealtime() { return System.nanoTime() / 1000000L; }
}
