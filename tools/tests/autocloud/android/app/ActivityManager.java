package android.app;

/** Host-only compile stub. Tests inject ActivityManager observations. */
public class ActivityManager {
    public static class RunningAppProcessInfo {
        public int pid;
        public int uid;
        public String processName;
    }
    public java.util.List<RunningAppProcessInfo> getRunningAppProcesses() {
        throw new UnsupportedOperationException();
    }
}
