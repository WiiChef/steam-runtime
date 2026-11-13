package com.termux.x11;

import android.app.ActivityManager;
import android.content.Context;
import android.os.SystemClock;
import android.util.Log;
import java.io.*;
import java.util.*;
import java.util.function.LongSupplier;
import java.util.function.Supplier;

/** Registered PID checks never enumerate procfs. Unobservable exits have a bounded grace period. */
final class PortProcessLiveness {
    static final long UNKNOWN_TIMEOUT_MS = 15000L;
    private final File registrations;
    private final File proc;
    private final Supplier<List<ActivityManager.RunningAppProcessInfo>> runningProcesses;
    private final LongSupplier elapsed;
    private final Map<String, Long> uncertainSince = new HashMap<>();
    private final Set<String> timedOut = new HashSet<>();

    PortProcessLiveness(Context context) {
        this(new File(context.getFilesDir(), "port-processes"), new File("/proc"), () -> {
            ActivityManager manager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
            return manager == null ? null : manager.getRunningAppProcesses();
        }, SystemClock::elapsedRealtime);
    }

    PortProcessLiveness(File registrations, File proc,
                        Supplier<List<ActivityManager.RunningAppProcessInfo>> runningProcesses,
                        LongSupplier elapsed) {
        this.registrations = registrations;
        this.proc = proc;
        this.runningProcesses = runningProcesses;
        this.elapsed = elapsed;
    }

    // Caller holds the lifecycle lock when this result authorizes reconciliation/release.
    boolean hasLiveProcess(String appid, String packageName) {
        List<ActivityManager.RunningAppProcessInfo> processes = null;
        try { processes = runningProcesses.get(); } catch (RuntimeException ignored) { }
        Set<Integer> visiblePids = new HashSet<>();
        if (processes != null) for (ActivityManager.RunningAppProcessInfo process : processes) {
            if (process.uid != android.os.Process.myUid()) continue;
            visiblePids.add(process.pid);
            if (packageName != null && process.processName != null &&
                    (process.processName.equals(packageName) || process.processName.startsWith(packageName + ":"))) {
                uncertainSince.keySet().removeIf(key -> key.startsWith(appid + ":"));
                timedOut.retainAll(uncertainSince.keySet());
                return true;
            }
        }

        File[] entries = registrations.listFiles();
        String directoryKey = appid + ":registrations";
        if (entries == null) return uncertain(directoryKey);
        clearUncertainty(directoryKey);
        boolean live = false;
        Set<String> currentKeys = new HashSet<>();
        for (File file : entries) {
            if (!file.getName().matches("[0-9]+")) continue;
            String[] data = readRegistration(file);
            if (data == null || !appid.equals(data[0])) continue;
            int pid;
            long registeredStart;
            try {
                pid = Integer.parseInt(file.getName());
                registeredStart = Long.parseLong(data[1]);
            } catch (NumberFormatException ignored) { continue; }
            String key = appid + ":" + pid + ":" + registeredStart;
            currentKeys.add(key);
            File process = new File(proc, Integer.toString(pid));
            long start = processStartTime(process);
            if (start >= 0) {
                clearUncertainty(key);
                live |= start == registeredStart;
            } else if (visiblePids.contains(pid) || process.exists()) {
                clearUncertainty(key);
                live = true;
            } else {
                live |= uncertain(key);
            }
        }
        // Discard timers for registrations removed or replaced since the last observation.
        uncertainSince.keySet().removeIf(key -> key.startsWith(appid + ":") && !currentKeys.contains(key));
        timedOut.retainAll(uncertainSince.keySet());
        return live;
    }

    private void clearUncertainty(String key) {
        uncertainSince.remove(key);
        timedOut.remove(key);
    }

    private boolean uncertain(String key) {
        long now = elapsed.getAsLong();
        Long since = uncertainSince.get(key);
        if (since == null) {
            uncertainSince.put(key, now);
            Log.w("PortProcessLiveness", "Cannot determine port liveness " + key + "; waiting up to " + UNKNOWN_TIMEOUT_MS + "ms");
            return true;
        }
        if (now - since < UNKNOWN_TIMEOUT_MS) return true;
        if (timedOut.add(key))
            Log.w("PortProcessLiveness", "Port liveness timeout " + key + "; treating as not alive");
        return false;
    }

    static String[] readRegistration(File file) {
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String[] fields = reader.readLine().trim().split("\\s+");
            if (fields.length != 2 || !fields[0].matches("[0-9]{1,10}") || !fields[1].matches("[0-9]+")) return null;
            return fields;
        } catch (Exception ignored) { return null; }
    }

    private static long processStartTime(File process) {
        try (BufferedReader reader = new BufferedReader(new FileReader(new File(process, "stat")))) {
            String line = reader.readLine();
            int end = line == null ? -1 : line.lastIndexOf(')');
            if (end < 0) return -1L;
            String[] fields = line.substring(end + 2).trim().split("\\s+");
            return fields.length > 19 ? Long.parseLong(fields[19]) : -1L;
        } catch (Exception ignored) { return -1L; }
    }
}
