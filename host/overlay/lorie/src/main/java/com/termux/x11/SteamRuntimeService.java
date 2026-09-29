package com.termux.x11;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ServiceInfo;
import android.os.Build;
import android.os.IBinder;
import android.system.Os;
import android.util.Log;

import org.apache.commons.compress.archivers.tar.TarArchiveEntry;
import org.apache.commons.compress.archivers.tar.TarArchiveInputStream;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.RandomAccessFile;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import android.os.FileObserver;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.zip.CRC32;

public class SteamRuntimeService extends Service {
    public static final String TAG = "SteamRuntimeService";
    public static final String CHANNEL_ID = "steam_runtime_channel";
    public static final String SIGNIN_CHANNEL_ID = "steam_signin";
    public static final int NOTIF_ID = 57343;
    public static final int SIGNIN_NOTIF_ID = 57344;
    public static final String ACTION_EXIT = "com.steamruntime.dev.EXIT";
    public static final String ACTION_CLEAR_PLAYING = "com.steamruntime.dev.CLEAR_PLAYING";
    private volatile boolean isShuttingDown = false;
    private volatile boolean isClearPlayingInProgress = false;

    private static volatile SteamRuntimeService sInstance = null;

    public static SteamRuntimeService getInstance() {
        return sInstance;
    }

    public static volatile int sLastExitCode = -1;
    public static volatile long sLastExitTime = 0;
    public static volatile String sSteamLoginState = "Unknown";

    private Process xServerProcess = null;
    private volatile Process steamProcess = null;
    private volatile boolean isRunning = false;
    private volatile boolean stopRequested = false;
    private final Object supervisorLock = new Object();

    private Thread workerThread = null;
    private Thread tailerThread = null;

    private int lastExitCode = -1;
    private long lastExitTime = 0;
    private String steamLoginState = "Unknown";
    private volatile long steamLaunchTime = 0;
    private volatile boolean hasSeenLogon = false;
    private volatile long gpuBlackSince = 0;
    private volatile String renderMode = "software";
    private int quickGpuExitCount = 0;

    private final List<Long> restartTimestamps = new ArrayList<>();
    private int backoffIndex = 0;

    @Override
    public void onCreate() {
        super.onCreate();
        sInstance = this;
        createNotificationChannel();
        startForegroundInternal("Steam: Initializing...");
    }

    private void startForegroundInternal(String text) {
        Notification notification = buildNotification(text);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
            try {
                startForeground(NOTIF_ID, notification, ServiceInfo.FOREGROUND_SERVICE_TYPE_SPECIAL_USE);
            } catch (Throwable t) {
                Log.w(TAG, "Failed startForeground with FOREGROUND_SERVICE_TYPE_SPECIAL_USE: " + t.getMessage());
                startForeground(NOTIF_ID, notification);
            }
        } else {
            startForeground(NOTIF_ID, notification);
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        String action = intent != null ? intent.getAction() : null;
        Log.i(TAG, "onStartCommand with action: " + action);

        if (ACTION_EXIT.equalsIgnoreCase(action) || "EXIT".equalsIgnoreCase(action) || "STOP".equalsIgnoreCase(action)) {
            Log.i(TAG, "Exit/Stop action received: " + action);
            performFullShutdown();
            return START_NOT_STICKY;
        }

        if (ACTION_CLEAR_PLAYING.equalsIgnoreCase(action) || "CLEAR_PLAYING".equalsIgnoreCase(action)) {
            Log.i(TAG, "Clear playing action received: " + action);
            clearPlayingStatus();
            return START_NOT_STICKY;
        }

        if (isShuttingDown) {
            Log.w(TAG, "onStartCommand ignored during shutdown");
            return START_NOT_STICKY;
        }

        if ("STATUS".equalsIgnoreCase(action)) {
            updateStatus();
            return START_NOT_STICKY;
        }

        if ("START".equalsIgnoreCase(action) || action == null) {
            stopRequested = false;
            if (!isRunning || workerThread == null || !workerThread.isAlive()) {
                startRuntime();
            } else {
                Log.i(TAG, "START received while supervisor active - waking supervisor");
                synchronized (supervisorLock) {
                    supervisorLock.notifyAll();
                }
                updateStatus();
            }
        }
        return START_NOT_STICKY;
    }

    @Override
    public void onTaskRemoved(Intent rootIntent) {
        Log.i(TAG, "onTaskRemoved: task swiped away, initiating full shutdown");
        performFullShutdown();
    }

    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            NotificationManager nm = getSystemService(NotificationManager.class);
            if (nm != null) {
                NotificationChannel channel = new NotificationChannel(
                        CHANNEL_ID,
                        "Steam Runtime Service",
                        NotificationManager.IMPORTANCE_LOW
                );
                channel.setDescription("Background Steam Runtime & X11 Server Layer");
                nm.createNotificationChannel(channel);

                NotificationChannel signinChannel = new NotificationChannel(
                        SIGNIN_CHANNEL_ID,
                        "Steam Sign-in",
                        NotificationManager.IMPORTANCE_HIGH
                );
                signinChannel.setDescription("Steam sign-in and session alerts");
                nm.createNotificationChannel(signinChannel);
            }
        }
    }

    private Notification buildNotification(String contentText) {
        Notification.Builder builder;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            builder = new Notification.Builder(this, CHANNEL_ID);
        } else {
            builder = new Notification.Builder(this);
        }

        Intent exitIntent = new Intent(this, SteamRuntimeService.class);
        exitIntent.setAction(ACTION_EXIT);
        int pendingFlags = PendingIntent.FLAG_UPDATE_CURRENT;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            pendingFlags |= PendingIntent.FLAG_IMMUTABLE;
        }
        PendingIntent exitPendingIntent = PendingIntent.getService(this, 1001, exitIntent, pendingFlags);
        Notification.Action exitAction = new Notification.Action.Builder(
                android.R.drawable.ic_menu_close_clear_cancel,
                "Exit Steam",
                exitPendingIntent
        ).build();
        builder.addAction(exitAction);

        Intent clearIntent = new Intent(this, SteamRuntimeService.class);
        clearIntent.setAction(ACTION_CLEAR_PLAYING);
        PendingIntent clearPendingIntent = PendingIntent.getService(this, 1002, clearIntent, pendingFlags);
        Notification.Action clearAction = new Notification.Action.Builder(
                android.R.drawable.ic_menu_rotate,
                "Clear Playing status",
                clearPendingIntent
        ).build();
        builder.addAction(clearAction);

        return builder
                .setContentTitle("Steam Services Host")
                .setContentText(contentText)
                .setSmallIcon(android.R.drawable.stat_notify_sync)
                .setOngoing(true)
                .setAutoCancel(false)
                .build();
    }

    private void updateNotification(String text) {
        if (isClearPlayingInProgress) {
            text = "Steam: restarting to clear Playing status\u2026";
        }
        NotificationManager nm = getSystemService(NotificationManager.class);
        if (nm != null) {
            nm.notify(NOTIF_ID, buildNotification(text));
        }
    }

    private synchronized void setSteamLoginState(String newState) {
        if (newState == null || newState.equals(steamLoginState)) {
            return;
        }
        String oldState = steamLoginState;
        steamLoginState = newState;
        sSteamLoginState = newState;
        Log.i(TAG, "steamLoginState changed: " + oldState + " -> " + newState);

        int steamPid = findSteamPid();
        boolean steamAlive = steamPid > 0;
        updateNotification("Steam: " + (steamAlive ? "RUNNING" : (isRunning ? "STARTING" : "Stopped")) + " (" + steamLoginState + ")");
        updateStatus();

        if ("Needs sign-in".equals(newState)) {
            postSigninNotification(
                    "Tap to sign in to Steam",
                    false
            );
        } else if ("Logged In Elsewhere".equals(newState)) {
            postSigninNotification(
                    "Steam was signed out because this account is playing on another device. Tap to reconnect.",
                    true
            );
        } else if ("Logged On".equals(newState)) {
            cancelSigninNotification();
        }
    }

    private void postSigninNotification(String text, boolean restartSteam) {
        NotificationManager nm = getSystemService(NotificationManager.class);
        if (nm == null) return;

        Intent tapIntent = new Intent(this, MainActivity.class);
        tapIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        if (restartSteam) {
            tapIntent.putExtra("RESTART_STEAM", true);
        }

        int flags = PendingIntent.FLAG_UPDATE_CURRENT;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            flags |= PendingIntent.FLAG_IMMUTABLE;
        }
        PendingIntent pi = PendingIntent.getActivity(this, restartSteam ? 2 : 1, tapIntent, flags);

        Notification.Builder builder;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            builder = new Notification.Builder(this, SIGNIN_CHANNEL_ID);
        } else {
            builder = new Notification.Builder(this);
        }

        builder.setContentTitle("Steam needs you")
                .setContentText(text)
                .setSmallIcon(android.R.drawable.stat_notify_error)
                .setContentIntent(pi)
                .setAutoCancel(true);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            builder.setPriority(Notification.PRIORITY_HIGH);
        }

        nm.notify(SIGNIN_NOTIF_ID, builder.build());
    }

    private void cancelSigninNotification() {
        NotificationManager nm = getSystemService(NotificationManager.class);
        if (nm != null) {
            nm.cancel(SIGNIN_NOTIF_ID);
        }
    }

    private static long getProcessPid(Process process) {
        if (process == null) return -1;
        try {
            if (Build.VERSION.SDK_INT >= 31) {
                return (long) Process.class.getMethod("pid").invoke(process);
            }
            java.lang.reflect.Field f = process.getClass().getDeclaredField("pid");
            f.setAccessible(true);
            return f.getLong(process);
        } catch (Throwable ignored) {
            return -1;
        }
    }

    public static int findSteamPid() {
        int myUid = android.os.Process.myUid();
        File procDir = new File("/proc");
        File[] entries = procDir.listFiles();
        if (entries == null) return -1;

        for (File entry : entries) {
            int pid;
            try {
                pid = Integer.parseInt(entry.getName());
            } catch (NumberFormatException e) {
                continue;
            }

            try {
                android.system.StructStat st = Os.stat(entry.getAbsolutePath());
                if (st.st_uid != myUid) {
                    continue;
                }

                File cmdlineFile = new File(entry, "cmdline");
                if (!cmdlineFile.canRead()) continue;

                byte[] buf = new byte[1024];
                int n;
                try (FileInputStream fis = new FileInputStream(cmdlineFile)) {
                    n = fis.read(buf);
                }
                if (n > 0) {
                    int end = 0;
                    while (end < n && buf[end] != 0) {
                        end++;
                    }
                    String argv0 = new String(buf, 0, end, java.nio.charset.StandardCharsets.UTF_8);
                    if (argv0.endsWith("/steamrtarm64/steam")) {
                        return pid;
                    }
                }
            } catch (Throwable ignored) {
            }
        }
        return -1;
    }

    public static int checkProcNetReadable() {
        File tcpFile = new File("/proc/net/tcp");
        if (!tcpFile.exists() || !tcpFile.canRead()) {
            return 0;
        }
        int count = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(tcpFile))) {
            while (br.readLine() != null) {
                count++;
            }
            return count;
        } catch (Exception e) {
            return 0;
        }
    }

    public static void ensureValveIpcObject(File filesDir) {
        try {
            File ipcDir = new File(filesDir, "ipc");
            if (!ipcDir.exists()) {
                ipcDir.mkdirs();
            }
            ipcDir.setReadable(true, false);
            ipcDir.setExecutable(true, false);

            File ipcFile = new File(ipcDir, "u0-ValveIPCSharedObj-Steam");
            final long targetSize = 2097152L;

            if (!ipcFile.exists() || ipcFile.length() != targetSize) {
                byte[] header = new byte[] {
                        (byte) 0x04, 0x00, 0x00, 0x00,
                        0x00, 0x01, 0x00, 0x00,
                        0x00, 0x00, 0x20, 0x00
                };
                try (FileOutputStream fos = new FileOutputStream(ipcFile)) {
                    fos.write(header);
                    byte[] zeros = new byte[8192];
                    long remaining = targetSize - header.length;
                    while (remaining > 0) {
                        int toWrite = (int) Math.min(zeros.length, remaining);
                        fos.write(zeros, 0, toWrite);
                        remaining -= toWrite;
                    }
                }
                ipcFile.setReadable(true, false);
                Log.i(TAG, "Created Valve IPC shared object: " + ipcFile.getAbsolutePath() + " (" + targetSize + " bytes)");
            }
        } catch (Exception e) {
            Log.w(TAG, "Failed ensuring Valve IPC shared object: " + e.getMessage());
        }
    }

    public static synchronized void writeStatus(Context context, SteamRuntimeService serviceInstance) {
        File filesDir = context.getFilesDir();
        File rootfsTarget = new File(filesDir, "rootfs/debian-trixie-aarch64");
        File provisionMarker = new File(filesDir, "rootfs/.provision_complete");
        boolean rootfsReady = rootfsTarget.exists() && (provisionMarker.exists() || new File(rootfsTarget, "bin/bash").exists());

        boolean shuttingDown = serviceInstance != null && serviceInstance.isShuttingDown;
        boolean running = !shuttingDown && (serviceInstance != null && serviceInstance.isRunning);
        Process xp = serviceInstance != null ? serviceInstance.xServerProcess : null;
        boolean xAlive = !shuttingDown && (xp != null && xp.isAlive());
        long xPid = xAlive ? getProcessPid(xp) : -1;

        int steamProcPid = findSteamPid();
        boolean steamAlive = !shuttingDown && (steamProcPid > 0);
        long steamPid = steamAlive ? steamProcPid : -1;

        int procNetLines = checkProcNetReadable();
        boolean procNetReadable = procNetLines > 0;

        int lastExitCode = serviceInstance != null ? serviceInstance.lastExitCode : sLastExitCode;
        long lastExitTime = serviceInstance != null ? serviceInstance.lastExitTime : sLastExitTime;
        String steamLoginState = shuttingDown ? "Stopped" : (serviceInstance != null ? serviceInstance.steamLoginState : sSteamLoginState);
        String renderMode = serviceInstance != null ? serviceInstance.renderMode : "software";

        String state;
        if (shuttingDown || (!running && !steamAlive)) {
            state = "STOPPED";
        } else if (steamAlive && xAlive) {
            state = "RUNNING";
        } else if (xAlive) {
            state = "X_SERVER_READY";
        } else {
            state = "STARTING";
        }

        File ipcFile = new File(filesDir, "ipc/u0-ValveIPCSharedObj-Steam");
        boolean ipcObjectReady = ipcFile.exists() && ipcFile.length() == 2097152L;

        String json = "{\n"
                + "  \"service_running\": " + running + ",\n"
                + "  \"rootfs_ready\": " + rootfsReady + ",\n"
                + "  \"x_server_alive\": " + xAlive + ",\n"
                + "  \"x_server_pid\": " + xPid + ",\n"
                + "  \"steam_alive\": " + steamAlive + ",\n"
                + "  \"steam_pid\": " + steamPid + ",\n"
                + "  \"last_exit_code\": " + lastExitCode + ",\n"
                + "  \"last_exit_time\": " + lastExitTime + ",\n"
                + "  \"steam_login_state\": \"" + steamLoginState + "\",\n"
                + "  \"render_mode\": \"" + renderMode + "\",\n"
                + "  \"proc_net_readable\": " + procNetReadable + ",\n"
                + "  \"proc_net_lines\": " + procNetLines + ",\n"
                + "  \"ipc_object\": " + ipcObjectReady + ",\n"
                + "  \"state\": \"" + state + "\"\n"
                + "}\n";

        try {
            File statusFile = new File(filesDir, "status.json");
            FileWriter fw = new FileWriter(statusFile, false);
            fw.write(json);
            fw.close();
            statusFile.setReadable(true, false);
            Log.i(TAG, "status.json updated:\n" + json.trim());
        } catch (Exception e) {
            Log.e(TAG, "Failed writing status.json: " + e.getMessage());
        }
    }

    private void updateStatus() {
        writeStatus(this, this);
    }

    private void extractRootfsIfNeeded() {
        File rootfsDir = new File(getFilesDir(), "rootfs");
        File rootfsTarget = new File(rootfsDir, "debian-trixie-aarch64");
        File provisionMarker = new File(rootfsDir, ".provision_complete");

        if (rootfsTarget.exists() && provisionMarker.exists()) {
            Log.i(TAG, "Rootfs already provisioned at " + rootfsTarget.getAbsolutePath());
            return;
        }

        File externalDir = getExternalFilesDir(null);
        File tarFile = externalDir != null ? new File(externalDir, "rootfs.tar") : null;
        if (tarFile == null || !tarFile.exists() || tarFile.length() == 0) {
            File fallbackTar = new File("/sdcard/Android/data/" + getPackageName() + "/files/rootfs.tar");
            if (fallbackTar.exists() && fallbackTar.length() > 0) {
                tarFile = fallbackTar;
            }
        }

        if (tarFile == null || !tarFile.exists() || tarFile.length() == 0) {
            Log.w(TAG, "No rootfs.tar found at " + (tarFile != null ? tarFile.getAbsolutePath() : "null") + ", skipping extraction");
            return;
        }

        Log.i(TAG, "Provisioning rootfs from " + tarFile.getAbsolutePath() + " (" + tarFile.length() + " bytes)");
        updateNotification("Extracting rootfs archive...");
        if (!rootfsDir.exists()) rootfsDir.mkdirs();

        long totalSize = tarFile.length();
        long lastUpdate = 0;

        try (FileInputStream fis = new FileInputStream(tarFile);
             BufferedInputStream bis = new BufferedInputStream(fis);
             TarArchiveInputStream tis = new TarArchiveInputStream(bis)) {

            TarArchiveEntry entry;
            byte[] buf = new byte[65536];

            while ((entry = tis.getNextEntry()) != null) {
                File target = new File(rootfsDir, entry.getName());
                // Traversal guard
                if (!target.getCanonicalPath().startsWith(rootfsDir.getCanonicalPath())) {
                    continue;
                }

                if (entry.isDirectory()) {
                    target.mkdirs();
                } else if (entry.isSymbolicLink()) {
                    if (target.exists() || Files.isSymbolicLink(target.toPath())) {
                        target.delete();
                    }
                    if (target.getParentFile() != null) target.getParentFile().mkdirs();
                    try {
                        Os.symlink(entry.getLinkName(), target.getAbsolutePath());
                    } catch (Exception e) {
                        Log.w(TAG, "symlink failed: " + target + " -> " + entry.getLinkName() + ": " + e.getMessage());
                    }
                } else if (entry.isLink()) { // Hardlink
                    File linkTarget = new File(rootfsDir, entry.getLinkName());
                    if (target.exists()) target.delete();
                    if (target.getParentFile() != null) target.getParentFile().mkdirs();
                    try {
                        Os.link(linkTarget.getAbsolutePath(), target.getAbsolutePath());
                    } catch (Exception e) {
                        try {
                            Files.copy(linkTarget.toPath(), target.toPath(), StandardCopyOption.REPLACE_EXISTING);
                        } catch (Exception ignored) {}
                    }
                } else {
                    if (target.getParentFile() != null) target.getParentFile().mkdirs();
                    try (FileOutputStream fos = new FileOutputStream(target)) {
                        int r;
                        while ((r = tis.read(buf)) != -1) {
                            fos.write(buf, 0, r);
                        }
                    }
                }

                int mode = entry.getMode();
                if (mode > 0 && !entry.isSymbolicLink()) {
                    try {
                        Os.chmod(target.getAbsolutePath(), mode);
                    } catch (Exception ignored) {}
                }

                long now = System.currentTimeMillis();
                if (now - lastUpdate > 1000) {
                    lastUpdate = now;
                    long bytesRead = fis.getChannel().position();
                    int pct = totalSize > 0 ? (int) ((bytesRead * 100) / totalSize) : 0;
                    updateNotification("Extracting rootfs: " + pct + "%");
                }
            }

            provisionMarker.createNewFile();
            Log.i(TAG, "Rootfs provisioning completed successfully");
            updateNotification("Rootfs ready");
        } catch (Exception e) {
            Log.e(TAG, "Error provisioning rootfs: " + e.getMessage(), e);
        }
    }

    private void cleanStaleCrashSentinels(File rootfsDir) {
        File crash1 = new File(rootfsDir, "root/.crash");
        if (crash1.exists()) {
            if (crash1.delete()) {
                Log.i(TAG, "Deleted stale crash sentinel: " + crash1.getAbsolutePath());
            }
        }

        File crash2 = new File(rootfsDir, "root/steamrtarm64/.crash");
        if (crash2.exists()) {
            if (crash2.delete()) {
                Log.i(TAG, "Deleted stale crash sentinel: " + crash2.getAbsolutePath());
            }
        }

        File steamSymlink = new File(rootfsDir, "root/.steam/steam");
        try {
            if (Files.isSymbolicLink(steamSymlink.toPath())) {
                Path target = Files.readSymbolicLink(steamSymlink.toPath());
                String targetStr = target.toString();
                File resolvedTargetDir;
                if (targetStr.startsWith("/")) {
                    resolvedTargetDir = new File(rootfsDir, targetStr.substring(1));
                } else {
                    resolvedTargetDir = new File(steamSymlink.getParentFile(), targetStr);
                }
                File symlinkCrash = new File(resolvedTargetDir, ".crash");
                if (symlinkCrash.exists()) {
                    if (symlinkCrash.delete()) {
                        Log.i(TAG, "Deleted stale crash sentinel: " + symlinkCrash.getAbsolutePath());
                    }
                }
            } else if (steamSymlink.isDirectory()) {
                File symlinkCrash = new File(steamSymlink, ".crash");
                if (symlinkCrash.exists()) {
                    if (symlinkCrash.delete()) {
                        Log.i(TAG, "Deleted stale crash sentinel: " + symlinkCrash.getAbsolutePath());
                    }
                }
            }
        } catch (Exception e) {
            Log.w(TAG, "Error cleaning symlink crash sentinel: " + e.getMessage());
        }

        File steamPidFile = new File(rootfsDir, "root/.steam/steam.pid");
        if (steamPidFile.exists()) {
            if (steamPidFile.delete()) {
                Log.i(TAG, "Deleted stale steam.pid file");
            }
        }
    }

    private void installRobustShimIfNeeded(File rootfsDir) {
        try {
            File targetDir = new File(rootfsDir, "usr/local/lib");
            if (!targetDir.exists()) targetDir.mkdirs();
            File targetFile = new File(targetDir, "librobustshim.so");

            byte[] assetBytes;
            try (InputStream is = getAssets().open("rootfs-shims/librobustshim.so")) {
                java.io.ByteArrayOutputStream baos = new java.io.ByteArrayOutputStream();
                byte[] buf = new byte[8192];
                int r;
                while ((r = is.read(buf)) != -1) {
                    baos.write(buf, 0, r);
                }
                assetBytes = baos.toByteArray();
            }

            boolean needWrite = false;
            if (!targetFile.exists() || targetFile.length() != assetBytes.length) {
                needWrite = true;
            } else {
                byte[] existing = Files.readAllBytes(targetFile.toPath());
                if (!java.util.Arrays.equals(existing, assetBytes)) {
                    needWrite = true;
                }
            }

            if (needWrite) {
                Files.write(targetFile.toPath(), assetBytes);
                try {
                    Os.chmod(targetFile.getAbsolutePath(), 0755);
                } catch (Exception ignored) {}
                Log.i(TAG, "Installed librobustshim.so to " + targetFile.getAbsolutePath() + " (" + assetBytes.length + " bytes)");
            }
        } catch (Exception e) {
            Log.w(TAG, "Failed installing librobustshim.so asset: " + e.getMessage());
        }
    }

    private File installFakeLsofIfNeeded(File filesDir) {
        try {
            File targetDir = new File(filesDir, "rootfs-shims");
            if (!targetDir.exists()) targetDir.mkdirs();
            File targetFile = new File(targetDir, "fakelsof");

            byte[] assetBytes;
            try (InputStream is = getAssets().open("rootfs-shims/fakelsof")) {
                java.io.ByteArrayOutputStream baos = new java.io.ByteArrayOutputStream();
                byte[] buf = new byte[8192];
                int r;
                while ((r = is.read(buf)) != -1) {
                    baos.write(buf, 0, r);
                }
                assetBytes = baos.toByteArray();
            }

            boolean needWrite = false;
            if (!targetFile.exists() || targetFile.length() != assetBytes.length) {
                needWrite = true;
            } else {
                byte[] existing = Files.readAllBytes(targetFile.toPath());
                if (!java.util.Arrays.equals(existing, assetBytes)) {
                    needWrite = true;
                }
            }

            if (needWrite) {
                Files.write(targetFile.toPath(), assetBytes);
                try {
                    Os.chmod(targetFile.getAbsolutePath(), 0755);
                } catch (Exception ignored) {}
                targetFile.setExecutable(true, false);
                targetFile.setReadable(true, false);
                Log.i(TAG, "Installed fakelsof to " + targetFile.getAbsolutePath() + " (" + assetBytes.length + " bytes)");
            }
            return targetFile;
        } catch (Exception e) {
            Log.w(TAG, "Failed installing fakelsof asset: " + e.getMessage());
            return new File(filesDir, "rootfs-shims/fakelsof");
        }
    }

    public static class KnownPort {
        public final String name;
        public final String packageName;
        public final int steamAppId;

        public KnownPort(String name, String packageName, int steamAppId) {
            this.name = name;
            this.packageName = packageName;
            this.steamAppId = steamAppId;
        }
    }

    public static final List<KnownPort> KNOWN_PORTS = Arrays.asList(
            new KnownPort("Slay the Spire 2", "com.game.sts2launcher.modmanager", 2868840)
    );

    public static boolean isPackageInstalled(Context context, String pkg) {
        try {
            context.getPackageManager().getPackageInfo(pkg, 0);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static long computeShortcutAppId(KnownPort port) {
        String fullExeAppName = "/usr/local/bin/android-launch" + port.name;
        CRC32 crc = new CRC32();
        crc.update(fullExeAppName.getBytes(StandardCharsets.UTF_8));
        return (crc.getValue() | 0x80000000L) & 0xFFFFFFFFL;
    }

    public static class VdfParser {
        private final byte[] data;
        private int pos = 0;

        public VdfParser(byte[] data) {
            this.data = data;
        }

        public String readString() {
            int start = pos;
            while (pos < data.length && data[pos] != 0) {
                pos++;
            }
            String s = new String(data, start, pos - start, StandardCharsets.UTF_8);
            if (pos < data.length && data[pos] == 0) pos++;
            return s;
        }

        public int readInt32() {
            if (pos + 4 > data.length) return 0;
            int b0 = data[pos++] & 0xFF;
            int b1 = data[pos++] & 0xFF;
            int b2 = data[pos++] & 0xFF;
            int b3 = data[pos++] & 0xFF;
            return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
        }

        public Map<String, Object> readObject() {
            Map<String, Object> map = new LinkedHashMap<>();
            while (pos < data.length) {
                int type = data[pos++] & 0xFF;
                if (type == 0x08) {
                    break;
                } else if (type == 0x00) {
                    String key = readString();
                    map.put(key, readObject());
                } else if (type == 0x01) {
                    String key = readString();
                    map.put(key, readString());
                } else if (type == 0x02) {
                    String key = readString();
                    map.put(key, readInt32());
                } else {
                    break;
                }
            }
            return map;
        }
    }

    public static void writeVdfMap(ByteArrayOutputStream out, Map<String, Object> map) throws IOException {
        for (Map.Entry<String, Object> entry : map.entrySet()) {
            String key = entry.getKey();
            Object val = entry.getValue();
            if (val instanceof Map) {
                out.write(0x00);
                out.write(key.getBytes(StandardCharsets.UTF_8));
                out.write(0x00);
                //noinspection unchecked
                writeVdfMap(out, (Map<String, Object>) val);
                out.write(0x08);
            } else if (val instanceof String) {
                out.write(0x01);
                out.write(key.getBytes(StandardCharsets.UTF_8));
                out.write(0x00);
                out.write(((String) val).getBytes(StandardCharsets.UTF_8));
                out.write(0x00);
            } else if (val instanceof Integer) {
                out.write(0x02);
                out.write(key.getBytes(StandardCharsets.UTF_8));
                out.write(0x00);
                int v = (Integer) val;
                out.write(v & 0xFF);
                out.write((v >> 8) & 0xFF);
                out.write((v >> 16) & 0xFF);
                out.write((v >> 24) & 0xFF);
            }
        }
    }

    private void installLauncherScript(File rootfsDir) {
        try {
            File localBinDir = new File(rootfsDir, "usr/local/bin");
            if (!localBinDir.exists()) localBinDir.mkdirs();
            File launcherScript = new File(localBinDir, "android-launch");
            String scriptContent = "#!/bin/sh\necho \"$1\" > /tmp/android_launch_request.$$ && mv /tmp/android_launch_request.$$ /tmp/android_launch_request\n";
            Files.write(launcherScript.toPath(), scriptContent.getBytes(StandardCharsets.UTF_8));
            launcherScript.setExecutable(true, false);
            launcherScript.setReadable(true, false);
            try {
                Os.chmod(launcherScript.getAbsolutePath(), 0755);
            } catch (Exception ignored) {}
            Log.i(TAG, "Installed android-launch script at " + launcherScript.getAbsolutePath());
        } catch (Exception e) {
            Log.e(TAG, "Failed installing android-launch script: " + e.getMessage(), e);
        }
    }

    @SuppressWarnings("unchecked")
    private Map<String, Object> loadOrCreateShortcuts(File shortcutsFile) {
        if (shortcutsFile.exists() && shortcutsFile.length() > 0) {
            try {
                byte[] bytes = Files.readAllBytes(shortcutsFile.toPath());
                VdfParser parser = new VdfParser(bytes);
                Map<String, Object> root = parser.readObject();
                if (root.containsKey("shortcuts") && root.get("shortcuts") instanceof Map) {
                    return (Map<String, Object>) root.get("shortcuts");
                }
            } catch (Exception e) {
                Log.e(TAG, "Failed parsing shortcuts.vdf: " + e.getMessage() + ", backing up to shortcuts.vdf.bak");
                try {
                    Files.copy(shortcutsFile.toPath(), new File(shortcutsFile.getParentFile(), "shortcuts.vdf.bak").toPath(), StandardCopyOption.REPLACE_EXISTING);
                } catch (Exception ignored) {}
            }
        }
        return new LinkedHashMap<>();
    }

    private void saveShortcuts(File shortcutsFile, Map<String, Object> shortcuts) {
        try {
            Map<String, Object> root = new LinkedHashMap<>();
            root.put("shortcuts", shortcuts);

            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            writeVdfMap(baos, root);
            baos.write(0x08);

            File tmpFile = new File(shortcutsFile.getParentFile(), "shortcuts.vdf.tmp");
            Files.write(tmpFile.toPath(), baos.toByteArray());
            tmpFile.setReadable(true, false);
            Files.move(tmpFile.toPath(), shortcutsFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
            shortcutsFile.setReadable(true, false);
            Log.i(TAG, "Saved shortcuts.vdf (" + shortcuts.size() + " shortcuts)");
        } catch (Exception e) {
            Log.e(TAG, "Failed saving shortcuts.vdf: " + e.getMessage(), e);
        }
    }

    private void collectFiles(File dir, List<File> out, int depth) {
        if (dir == null || !dir.exists() || depth > 3) return;
        File[] list = dir.listFiles();
        if (list != null) {
            for (File f : list) {
                if (f.isDirectory()) {
                    collectFiles(f, out, depth + 1);
                } else if (f.isFile()) {
                    out.add(f);
                }
            }
        }
    }

    private void copyGameArtwork(File rootfsDir, KnownPort port, File gridDir, long shortcutAppId) {
        File appcacheDir = new File(rootfsDir, "root/steamrtarm64/appcache/librarycache/" + port.steamAppId);
        if (!appcacheDir.exists() || !appcacheDir.isDirectory()) {
            File alt = new File(rootfsDir, "root/.steam/steam/appcache/librarycache/" + port.steamAppId);
            if (alt.exists() && alt.isDirectory()) {
                appcacheDir = alt;
            } else {
                Log.i(TAG, "No librarycache art found for steamAppId " + port.steamAppId + " at " + appcacheDir.getAbsolutePath());
                return;
            }
        }

        List<File> files = new ArrayList<>();
        collectFiles(appcacheDir, files, 0);

        File portraitFile = null;
        File headerFile = null;
        File heroFile = null;
        File logoFile = null;

        for (File f : files) {
            String n = f.getName().toLowerCase();
            if (portraitFile == null && (n.startsWith("library_600x900") || n.contains("600x900")) && (n.endsWith(".jpg") || n.endsWith(".jpeg"))) {
                portraitFile = f;
            }
            if (headerFile == null && (n.startsWith("library_header") || n.startsWith("header")) && (n.endsWith(".jpg") || n.endsWith(".jpeg"))) {
                headerFile = f;
            }
            if (heroFile == null && (n.startsWith("library_hero") || n.contains("hero")) && (n.endsWith(".jpg") || n.endsWith(".jpeg"))) {
                heroFile = f;
            }
            if (logoFile == null && (n.startsWith("logo") || n.contains("logo")) && n.endsWith(".png")) {
                logoFile = f;
            }
        }

        Log.i(TAG, "Artwork search for " + port.name + " (" + port.steamAppId + ") in " + appcacheDir.getAbsolutePath() + ":\n"
                + "  portrait: " + (portraitFile != null ? portraitFile.getAbsolutePath() : "NOT FOUND") + "\n"
                + "  header: " + (headerFile != null ? headerFile.getAbsolutePath() : "NOT FOUND") + "\n"
                + "  hero: " + (heroFile != null ? heroFile.getAbsolutePath() : "NOT FOUND") + "\n"
                + "  logo: " + (logoFile != null ? logoFile.getAbsolutePath() : "NOT FOUND"));

        String unsignedId = Long.toString(shortcutAppId & 0xFFFFFFFFL);
        String signedId = Integer.toString((int) shortcutAppId);

        // Delete any stale signed-name files
        if (!signedId.equals(unsignedId)) {
            File[] staleFiles = gridDir.listFiles((d, name) -> name.startsWith(signedId));
            if (staleFiles != null) {
                for (File sf : staleFiles) {
                    if (sf.delete()) {
                        Log.i(TAG, "Deleted stale signed grid file: " + sf.getName());
                    }
                }
            }
        }

        try {
            if (portraitFile != null) {
                File dst = new File(gridDir, unsignedId + "p.jpg");
                Files.copy(portraitFile.toPath(), dst.toPath(), StandardCopyOption.REPLACE_EXISTING);
                dst.setReadable(true, false);
                Log.i(TAG, "Copied portrait art -> " + dst.getName());
            }
            if (headerFile != null) {
                File dst = new File(gridDir, unsignedId + ".jpg");
                Files.copy(headerFile.toPath(), dst.toPath(), StandardCopyOption.REPLACE_EXISTING);
                dst.setReadable(true, false);
                Log.i(TAG, "Copied header art -> " + dst.getName());
            }
            if (heroFile != null) {
                File dst = new File(gridDir, unsignedId + "_hero.jpg");
                Files.copy(heroFile.toPath(), dst.toPath(), StandardCopyOption.REPLACE_EXISTING);
                dst.setReadable(true, false);
                Log.i(TAG, "Copied hero art -> " + dst.getName());
            }
            if (logoFile != null) {
                File dst = new File(gridDir, unsignedId + "_logo.png");
                Files.copy(logoFile.toPath(), dst.toPath(), StandardCopyOption.REPLACE_EXISTING);
                dst.setReadable(true, false);
                Log.i(TAG, "Copied logo art -> " + dst.getName());
            }
        } catch (Exception e) {
            Log.w(TAG, "Failed copying artwork files for " + port.name + ": " + e.getMessage());
        }
    }

    @SuppressWarnings("unchecked")
    private void updateShortcutsAndArtwork(File rootfsDir) {
        List<KnownPort> installedPorts = new ArrayList<>();
        for (KnownPort p : KNOWN_PORTS) {
            if (isPackageInstalled(this, p.packageName)) {
                installedPorts.add(p);
            }
        }
        if (installedPorts.isEmpty()) {
            Log.i(TAG, "No known game ports installed on device");
            return;
        }

        File userdataDir = new File(rootfsDir, "root/steamrtarm64/userdata");
        if (!userdataDir.exists() || !userdataDir.isDirectory()) {
            Log.i(TAG, "Userdata dir does not exist yet at " + userdataDir.getAbsolutePath());
            return;
        }

        File[] userDirs = userdataDir.listFiles(f -> f.isDirectory() && f.getName().matches("\\d+"));
        if (userDirs == null || userDirs.length == 0) {
            Log.i(TAG, "No user account directories found in " + userdataDir.getAbsolutePath());
            return;
        }

        for (File userDir : userDirs) {
            File configDir = new File(userDir, "config");
            if (!configDir.exists()) configDir.mkdirs();
            File shortcutsFile = new File(configDir, "shortcuts.vdf");

            Map<String, Object> shortcuts = loadOrCreateShortcuts(shortcutsFile);

            for (KnownPort port : installedPorts) {
                long shortcutAppIdUnsigned = computeShortcutAppId(port);
                int shortcutAppId = (int) shortcutAppIdUnsigned;
                Log.i(TAG, "Computed shortcut appid for " + port.name + ": unsigned=" + shortcutAppIdUnsigned + ", signed=" + shortcutAppId);

                Map<String, Object> existingEntry = null;
                for (Object obj : shortcuts.values()) {
                    if (obj instanceof Map) {
                        Map<String, Object> entry = (Map<String, Object>) obj;
                        Object opts = entry.get("LaunchOptions");
                        Object name = entry.get("AppName");
                        if (port.packageName.equals(opts) || port.name.equals(name)) {
                            existingEntry = entry;
                            break;
                        }
                    }
                }

                if (existingEntry == null) {
                    existingEntry = new LinkedHashMap<>();
                    shortcuts.put(String.valueOf(shortcuts.size()), existingEntry);
                }

                existingEntry.put("appid", shortcutAppId);
                existingEntry.put("AppName", port.name);
                existingEntry.put("Exe", "/usr/local/bin/android-launch");
                existingEntry.put("StartDir", "/root");
                existingEntry.put("icon", "");
                existingEntry.put("ShortcutPath", "");
                existingEntry.put("LaunchOptions", port.packageName);
                existingEntry.put("IsHidden", 0);
                existingEntry.put("AllowDesktopConfig", 1);
                existingEntry.put("AllowOverlay", 0);
                existingEntry.put("OpenVR", 0);
                existingEntry.put("Devkit", 0);
                existingEntry.put("DevkitGameID", "");
                existingEntry.put("DevkitOverrideAppID", 0);
                existingEntry.put("LastPlayTime", 0);
                existingEntry.put("FlatpakAppID", "");
                Map<String, Object> tags = new LinkedHashMap<>();
                tags.put("0", "Android");
                existingEntry.put("tags", tags);

                File gridDir = new File(configDir, "grid");
                if (!gridDir.exists()) gridDir.mkdirs();
                copyGameArtwork(rootfsDir, port, gridDir, shortcutAppIdUnsigned);
            }

            Map<String, Object> reindexed = new LinkedHashMap<>();
            int idx = 0;
            for (Object sc : shortcuts.values()) {
                reindexed.put(String.valueOf(idx++), sc);
            }

            saveShortcuts(shortcutsFile, reindexed);
        }
    }

    private FileObserver launchRequestObserver = null;
    private Thread launchPollerThread = null;

    private synchronized void startLaunchRequestWatcher(File tmpDir) {
        if (launchPollerThread != null && launchPollerThread.isAlive()) {
            return;
        }
        if (!tmpDir.exists()) tmpDir.mkdirs();

        try {
            if (Build.VERSION.SDK_INT >= 29) {
                launchRequestObserver = new FileObserver(tmpDir, FileObserver.CLOSE_WRITE | FileObserver.MOVED_TO) {
                    @Override
                    public void onEvent(int event, String path) {
                        if ("android_launch_request".equals(path)) {
                            checkAndHandleLaunchRequest(tmpDir);
                        }
                    }
                };
            } else {
                launchRequestObserver = new FileObserver(tmpDir.getAbsolutePath(), FileObserver.CLOSE_WRITE | FileObserver.MOVED_TO) {
                    @Override
                    public void onEvent(int event, String path) {
                        if ("android_launch_request".equals(path)) {
                            checkAndHandleLaunchRequest(tmpDir);
                        }
                    }
                };
            }
            launchRequestObserver.startWatching();
        } catch (Exception e) {
            Log.w(TAG, "Failed starting FileObserver: " + e.getMessage());
        }

        launchPollerThread = new Thread(() -> {
            while (!stopRequested) {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    if (stopRequested) break;
                }
                if (stopRequested) break;
                checkAndHandleLaunchRequest(tmpDir);
            }
        }, "launch-request-poller");
        launchPollerThread.setDaemon(true);
        launchPollerThread.start();
    }

    private synchronized void checkAndHandleLaunchRequest(File tmpDir) {
        File reqFile = new File(tmpDir, "android_launch_request");
        if (!reqFile.exists() || !reqFile.canRead()) {
            return;
        }
        String pkgName = null;
        try (BufferedReader br = new BufferedReader(new FileReader(reqFile))) {
            String line = br.readLine();
            if (line != null) {
                pkgName = line.trim();
            }
        } catch (Exception e) {
            Log.w(TAG, "Error reading android_launch_request: " + e.getMessage());
        }
        reqFile.delete();

        if (pkgName == null || pkgName.isEmpty()) {
            return;
        }

        Log.i(TAG, "Received android_launch_request for package: " + pkgName);
        KnownPort matchedPort = null;
        for (KnownPort p : KNOWN_PORTS) {
            if (p.packageName.equals(pkgName)) {
                matchedPort = p;
                break;
            }
        }

        if (matchedPort == null) {
            Log.w(TAG, "Ignored launch request: package " + pkgName + " is not in the known ports table");
            return;
        }

        launchGamePort(matchedPort);
    }

    private void launchGamePort(KnownPort port) {
        Log.i(TAG, "Launching known game port: " + port.name + " (" + port.packageName + ")");
        Intent launchIntent = getPackageManager().getLaunchIntentForPackage(port.packageName);
        if (launchIntent == null) {
            Log.w(TAG, "No launch intent found for package: " + port.packageName);
            return;
        }
        launchIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);

        try {
            startActivity(launchIntent);
            Log.i(TAG, "startActivity invoked for " + port.packageName);
        } catch (Throwable t) {
            Log.w(TAG, "startActivity from service failed: " + t.getMessage());
        }

        postPlayGameNotification(port, launchIntent);
    }

    private void postPlayGameNotification(KnownPort port, Intent launchIntent) {
        NotificationManager nm = getSystemService(NotificationManager.class);
        if (nm == null) return;

        int flags = PendingIntent.FLAG_UPDATE_CURRENT;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            flags |= PendingIntent.FLAG_IMMUTABLE;
        }
        PendingIntent pi = PendingIntent.getActivity(this, port.steamAppId, launchIntent, flags);

        Notification.Builder builder;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            builder = new Notification.Builder(this, SIGNIN_CHANNEL_ID);
        } else {
            builder = new Notification.Builder(this);
        }

        builder.setContentTitle(port.name)
                .setContentText("Tap to play " + port.name)
                .setSmallIcon(android.R.drawable.stat_notify_sync)
                .setContentIntent(pi)
                .setAutoCancel(true);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            builder.setPriority(Notification.PRIORITY_HIGH);
        }

        nm.notify(port.steamAppId, builder.build());
    }

    private void startXServer(File filesDir, File tmpDir, File rootfsDir, File nativeLibDir) {
        File x11UnixDir = new File(tmpDir, ".X11-unix");
        if (!x11UnixDir.exists()) x11UnixDir.mkdirs();
        File x0Socket = new File(x11UnixDir, "X0");
        if (x0Socket.exists()) x0Socket.delete();
        File x0Lock = new File(tmpDir, ".X0-lock");
        if (x0Lock.exists()) x0Lock.delete();

        File sigresetBin = new File(nativeLibDir, "libsigreset.so");
        File xkbDir = new File(rootfsDir, "usr/share/X11/xkb");
        List<String> xCmd = new ArrayList<>();
        if (sigresetBin.exists()) {
            xCmd.add(sigresetBin.getAbsolutePath());
        } else {
            Log.w(TAG, "libsigreset.so not found at " + sigresetBin.getAbsolutePath() + ", launching X server directly");
        }
        xCmd.add("/system/bin/app_process");
        xCmd.add("-Xnoimage-dex2oat");
        xCmd.add("/");
        xCmd.add("com.termux.x11.CmdEntryPoint");
        xCmd.add(":0");
        xCmd.add("-nocursor");
        ProcessBuilder xpb = new ProcessBuilder(xCmd);
        xpb.directory(filesDir);
        xpb.redirectErrorStream(true);
        Map<String, String> xenv = xpb.environment();
        xenv.put("CLASSPATH", getApplicationInfo().sourceDir);
        xenv.put("TMPDIR", tmpDir.getAbsolutePath());
        xenv.put("PACKAGE_NAME", getPackageName());
        if (xkbDir.exists()) {
            xenv.put("XKB_CONFIG_ROOT", xkbDir.getAbsolutePath());
        }
        xenv.put("LD_LIBRARY_PATH", nativeLibDir.getAbsolutePath() + ":" + xenv.getOrDefault("LD_LIBRARY_PATH", ""));
        try {
            xServerProcess = xpb.start();
            Log.i(TAG, "Started X server child process (CmdEntryPoint :0)");
            new Thread(() -> {
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(xServerProcess.getInputStream()))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        Log.d(TAG, "[X11] " + line);
                    }
                } catch (Exception ignored) {}
            }, "x11-log-thread").start();

            // Wait for X0 socket
            for (int i = 0; i < 20; i++) {
                if (x0Socket.exists()) {
                    Log.i(TAG, "X0 socket ready at " + x0Socket.getAbsolutePath());
                    break;
                }
                try {
                    Thread.sleep(250);
                } catch (InterruptedException ignored) {}
            }
        } catch (Exception e) {
            Log.e(TAG, "Failed starting X server: " + e.getMessage(), e);
        }
    }

    private List<String> buildSteamCmd(File filesDir, File nativeLibDir, File rootfsDir, File tmpDir,
                                       File steamShm, File hostsFile, File resolvFile,
                                       File fakeLsofFile, boolean isProcNetTcpReadable, boolean useGpu,
                                       String customBashCmd) {
        File steamArgsFile = new File(filesDir, "steam_args.txt");
        String extraArgs = "-gamepadui -steamdeck";
        if (steamArgsFile.exists() && steamArgsFile.canRead()) {
            try (BufferedReader br = new BufferedReader(new FileReader(steamArgsFile))) {
                String line = br.readLine();
                if (line != null && !line.trim().isEmpty()) {
                    extraArgs = line.trim();
                }
            } catch (Exception e) {
                Log.w(TAG, "Failed reading steam_args.txt: " + e.getMessage());
            }
        }
        Log.i(TAG, "Steam extra launch args: " + extraArgs);

        File sigresetBin = new File(nativeLibDir, "libsigreset.so");
        File prootBin = new File(nativeLibDir, "libproot.so");
        List<String> steamCmd = new ArrayList<>();

            if (sigresetBin.exists()) {
                steamCmd.add(sigresetBin.getAbsolutePath());
            } else {
                Log.w(TAG, "libsigreset.so not found at " + sigresetBin.getAbsolutePath() + ", launching PRoot directly");
            }
            steamCmd.add(prootBin.getAbsolutePath());
            steamCmd.add("--link2symlink");
            steamCmd.add("--sysvipc");
            steamCmd.add("-0");
            steamCmd.add("-r");
            steamCmd.add(rootfsDir.getAbsolutePath());
            steamCmd.add("-b"); steamCmd.add("/dev");
            steamCmd.add("-b"); steamCmd.add("/proc");
            steamCmd.add("-b"); steamCmd.add("/sys");

            if (isProcNetTcpReadable) {
                Log.i(TAG, "proc_net_tcp is readable directly from host, skipping /proc/net binds");
            } else {
                Log.i(TAG, "proc_net_tcp is not readable directly from host, creating fallback fakeproc/net binds");
                File fakeProcNetDir = new File(filesDir, "fakeproc/net");
                if (!fakeProcNetDir.exists()) fakeProcNetDir.mkdirs();
                File fakeTcp = new File(fakeProcNetDir, "tcp");
                File fakeTcp6 = new File(fakeProcNetDir, "tcp6");
                final String defaultHeader = "  sl  local_address rem_address   st tx_queue rx_queue tr tm->when retrnsmt   uid  timeout inode\n";
                try (FileWriter fw = new FileWriter(fakeTcp, false)) {
                    fw.write(defaultHeader);
                } catch (Exception e) {
                    Log.w(TAG, "Failed writing fake tcp: " + e.getMessage());
                }
                fakeTcp.setReadable(true, false);

                try (FileWriter fw = new FileWriter(fakeTcp6, false)) {
                    fw.write(defaultHeader);
                } catch (Exception e) {
                    Log.w(TAG, "Failed writing fake tcp6: " + e.getMessage());
                }
                fakeTcp6.setReadable(true, false);

                steamCmd.add("-b"); steamCmd.add(fakeTcp.getAbsolutePath() + ":/proc/net/tcp");
                steamCmd.add("-b"); steamCmd.add(fakeTcp6.getAbsolutePath() + ":/proc/net/tcp6");
            }

            steamCmd.add("-b"); steamCmd.add(tmpDir.getAbsolutePath() + ":/tmp");
            steamCmd.add("-b"); steamCmd.add(steamShm.getAbsolutePath() + ":/dev/shm");
            steamCmd.add("-b"); steamCmd.add(hostsFile.getAbsolutePath() + ":/etc/hosts");
            steamCmd.add("-b"); steamCmd.add(resolvFile.getAbsolutePath() + ":/etc/resolv.conf");
            steamCmd.add("-b"); steamCmd.add(fakeLsofFile.getAbsolutePath() + ":/usr/bin/lsof");
            steamCmd.add("-w"); steamCmd.add("/root");
            steamCmd.add("/usr/bin/env");
            steamCmd.add("-i");
            steamCmd.add("HOME=/root");
            steamCmd.add("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
            steamCmd.add("DISPLAY=:0");
            steamCmd.add("STEAM_RUNTIME=0");
            String mesa = "/opt/mesa-kgsl";
            String ldPreload = "/usr/local/lib/librobustshim.so";
            if (useGpu) {
                ldPreload += ":" + mesa + "/lib/aarch64-linux-gnu/libGLX_mesa.so.0"
                        + ":" + mesa + "/lib/aarch64-linux-gnu/libEGL_mesa.so.0";
            }
            steamCmd.add("LD_PRELOAD=" + ldPreload);
            steamCmd.add("LANG=C.UTF-8");
            steamCmd.add("LC_ALL=C.UTF-8");
            // This headless Android host has no udev. Disable HIDAPI joystick probing
            // and keep SDL's udev monitor enabled to avoid its polling fallback.
            steamCmd.add("SDL_JOYSTICK_HIDAPI=0");
            steamCmd.add("SDL_HIDAPI_UDEV=1");
            String tzId = java.util.TimeZone.getDefault().getID();
            steamCmd.add("TZ=" + (tzId != null && !tzId.isEmpty() ? tzId : "UTC"));
            String ldLibraryPath = "/root/steamrtarm64:/root/steamrtarm64/libs";
            if (useGpu) {
                ldLibraryPath += ":" + mesa + "/lib/aarch64-linux-gnu:/opt/mesa-builddeps/usr/lib/aarch64-linux-gnu"
                        + ":/opt/mesa-builddeps/usr/lib/llvm-19/lib:/opt/mesa-builddeps/usr/lib";
                steamCmd.set(steamCmd.indexOf("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"),
                        "PATH=/opt/mesa-tools/usr/bin:/opt/mesa-builddeps/usr/lib/llvm-19/bin:/opt/mesa-builddeps/usr/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
                steamCmd.add("LIBGL_DRIVERS_PATH=" + mesa + "/lib/aarch64-linux-gnu/dri");
                steamCmd.add("MESA_LOADER_DRIVER_OVERRIDE=zink");
                steamCmd.add("GALLIUM_DRIVER=zink");
                steamCmd.add("VK_ICD_FILENAMES=" + mesa + "/share/vulkan/icd.d/freedreno_icd.aarch64.json");
                steamCmd.add("VK_DRIVER_FILES=" + mesa + "/share/vulkan/icd.d/freedreno_icd.aarch64.json");
                steamCmd.add("__GLX_VENDOR_LIBRARY_NAME=mesa");
                steamCmd.add("__EGL_VENDOR_LIBRARY_FILENAMES=" + mesa + "/share/glvnd/egl_vendor.d/50_mesa.json");
                steamCmd.add("EGL_PLATFORM=x11");
                steamCmd.add("MESA_SHADER_CACHE_DIR=/tmp/mesa-cache");
                steamCmd.add("XDG_CACHE_HOME=/tmp/.cache");
            }
            steamCmd.add("LD_LIBRARY_PATH=" + ldLibraryPath);
            steamCmd.add("/bin/bash");
            steamCmd.add("-c");
            if (customBashCmd != null) {
                steamCmd.add(customBashCmd);
            } else {
                String gpuFlag = useGpu ? "" : "-cef-disable-gpu ";
                String steamLaunchCmd = "openbox & sleep 1; exec /usr/bin/env -u LIBGL_ALWAYS_SOFTWARE /root/steamrtarm64/steam -no-cef-sandbox " + gpuFlag + "-chromeosnopreallocate -noverifyfiles " + extraArgs;
                steamCmd.add("dbus-run-session -- /bin/bash -c \"" + steamLaunchCmd + "\"");
            }
        Log.i(TAG, "Final Steam command line: " + steamCmd);
        return steamCmd;
    }

    private List<String> buildSteamCmd(File filesDir, File nativeLibDir, File rootfsDir, File tmpDir,
                                       File steamShm, File hostsFile, File resolvFile,
                                       File fakeLsofFile, boolean isProcNetTcpReadable, boolean useGpu) {
        return buildSteamCmd(filesDir, nativeLibDir, rootfsDir, tmpDir, steamShm, hostsFile, resolvFile,
                fakeLsofFile, isProcNetTcpReadable, useGpu, null);
    }

    private List<String> buildProotSteamCmd(String customBashCmd) {
        File filesDir = getFilesDir();
        File nativeLibDir = new File(getApplicationInfo().nativeLibraryDir);
        File rootfsDir = new File(filesDir, "rootfs/debian-trixie-aarch64");
        File tmpDir = new File(filesDir, "tmp");
        File steamShm = new File(tmpDir, "steam-shm");
        File hostsFile = new File(filesDir, "hosts");
        File resolvFile = new File(filesDir, "resolv.conf");
        File fakeLsofFile = new File(filesDir, "rootfs-shims/fakelsof");
        boolean isProcNetTcpReadable = false;
        File hostTcp = new File("/proc/net/tcp");
        if (hostTcp.canRead()) {
            try (BufferedReader br = new BufferedReader(new FileReader(hostTcp))) {
                if (br.readLine() != null) isProcNetTcpReadable = true;
            } catch (Exception ignored) {}
        }
        File gpuDisabled = new File(filesDir, "gpu_disabled");
        boolean gpuAvailable = new File(rootfsDir, "opt/mesa-kgsl").exists()
                && new File("/dev/kgsl-3d0").exists() && !gpuDisabled.exists();
        return buildSteamCmd(filesDir, nativeLibDir, rootfsDir, tmpDir, steamShm, hostsFile,
                resolvFile, fakeLsofFile, isProcNetTcpReadable, gpuAvailable, customBashCmd);
    }

    private Process startProotSteamProcess(List<String> cmd) throws IOException {
        File filesDir = getFilesDir();
        File tmpDir = new File(filesDir, "tmp");
        File nativeLibDir = new File(getApplicationInfo().nativeLibraryDir);
        File binDir = new File(filesDir, "bin");
        File loaderBin = new File(nativeLibDir, "libproot-loader.so");
        File loader32Bin = new File(nativeLibDir, "libproot-loader32.so");

        ProcessBuilder pb = new ProcessBuilder(cmd);
        pb.directory(filesDir);
        Map<String, String> senv = pb.environment();
        senv.put("PROOT_TMP_DIR", tmpDir.getAbsolutePath());
        if (loaderBin.exists()) senv.put("PROOT_LOADER", loaderBin.getAbsolutePath());
        if (loader32Bin.exists()) senv.put("PROOT_LOADER_32", loader32Bin.getAbsolutePath());
        senv.put("LD_LIBRARY_PATH", binDir.getAbsolutePath() + ":" + nativeLibDir.getAbsolutePath() + ":" + senv.getOrDefault("LD_LIBRARY_PATH", ""));
        return pb.start();
    }

    private synchronized void startLogTailer(File rootfsDir) {
        if (tailerThread != null && tailerThread.isAlive()) {
            return;
        }
        tailerThread = new Thread(() -> {
            File connLog = new File(rootfsDir, "root/steamrtarm64/logs/connection_log.txt");
            long logOffset = 0;
            if (connLog.exists()) {
                logOffset = connLog.length();
            }
            while (!stopRequested) {
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    if (stopRequested) break;
                }
                if (stopRequested) break;

                if ("gpu".equals(renderMode) && hasSeenLogon
                        && !new File(getFilesDir(), "gpu_disabled").exists()) {
                    long now = System.currentTimeMillis();
                    if (isXRootWindowAllBlack(rootfsDir)) {
                        if (gpuBlackSince == 0) {
                            gpuBlackSince = now;
                            Log.w(TAG, "GPU mode: X root window is black; starting 60s fallback timer");
                        } else if (now - gpuBlackSince >= 60000L) {
                            File gpuDisabled = new File(getFilesDir(), "gpu_disabled");
                            try {
                                if (gpuDisabled.createNewFile()) {
                                    Log.e(TAG, "GPU mode stayed black in X root window for 60s after logon; switching to software mode");
                                    int pid = findSteamPid();
                                    if (pid > 0) android.os.Process.sendSignal(pid, 15);
                                    stopGpuRuntimeProcessAfterFallback();
                                }
                            } catch (Exception e) {
                                Log.e(TAG, "Failed enabling software fallback after black X root window: " + e.getMessage(), e);
                            }
                            gpuBlackSince = 0;
                        }
                    } else {
                        gpuBlackSince = 0;
                    }
                } else {
                    gpuBlackSince = 0;
                }

                // Check 90s logon timeout
                if (steamLaunchTime > 0 && !hasSeenLogon) {
                    long runDuration = System.currentTimeMillis() - steamLaunchTime;
                    if (runDuration > 90000L && !"Logged In Elsewhere".equals(steamLoginState)) {
                        setSteamLoginState("Needs sign-in");
                    }
                }

                // Read only new bytes from connection_log.txt
                if (connLog.exists() && connLog.canRead()) {
                    long len = connLog.length();
                    if (len < logOffset) {
                        logOffset = 0;
                    }
                    if (len > logOffset) {
                        try (RandomAccessFile raf = new RandomAccessFile(connLog, "r")) {
                            raf.seek(logOffset);
                            String line;
                            while ((line = raf.readLine()) != null) {
                                if (line.contains("RecvMsgClientLogOnResponse() : processing complete") || line.contains("[Logged On")) {
                                    hasSeenLogon = true;
                                    setSteamLoginState("Logged On");
                                } else if (line.contains("Logged In Elsewhere")) {
                                    setSteamLoginState("Logged In Elsewhere");
                                } else if (line.contains("InvalidPassword") || line.contains("Expired")
                                        || line.contains("AccessDenied") || line.contains("LogonSessionReplaced")) {
                                    setSteamLoginState("Needs sign-in");
                                }
                            }
                            logOffset = raf.getFilePointer();
                        } catch (Exception e) {
                            Log.w(TAG, "Error tailing connection_log.txt: " + e.getMessage());
                        }
                    }
                }
            }
        }, "steam-log-tailer");
        tailerThread.setDaemon(true);
        tailerThread.start();
    }

    private boolean isXRootWindowAllBlack(File rootfsDir) {
        File filesDir = getFilesDir();
        File tmpDir = new File(filesDir, "tmp");
        File capture = new File(tmpDir, "steam-root-window.xwd");
        File nativeLibDir = new File(getApplicationInfo().nativeLibraryDir);
        File prootBin = new File(nativeLibDir, "libproot.so");
        File loaderBin = new File(nativeLibDir, "libproot-loader.so");
        File loader32Bin = new File(nativeLibDir, "libproot-loader32.so");
        File prootTmp = new File(tmpDir, "proot-tmp");
        prootTmp.mkdirs();
        capture.delete();

        List<String> cmd = new ArrayList<>();
        cmd.add(prootBin.getAbsolutePath());
        cmd.add("--link2symlink");
        cmd.add("--sysvipc");
        cmd.add("-0");
        cmd.add("-r"); cmd.add(rootfsDir.getAbsolutePath());
        cmd.add("-b"); cmd.add("/dev");
        cmd.add("-b"); cmd.add("/proc");
        cmd.add("-b"); cmd.add("/sys");
        cmd.add("-b"); cmd.add(tmpDir.getAbsolutePath() + ":/tmp");
        cmd.add("-b"); cmd.add(new File(tmpDir, "steam-shm").getAbsolutePath() + ":/dev/shm");
        cmd.add("-w"); cmd.add("/root");
        cmd.add("/usr/bin/env");
        cmd.add("DISPLAY=:0");
        cmd.add("LD_LIBRARY_PATH=/opt/mesa-builddeps/usr/lib/aarch64-linux-gnu:/usr/lib/aarch64-linux-gnu:/opt/mesa-tools/usr/lib/aarch64-linux-gnu");
        cmd.add("/opt/mesa-tools/usr/bin/xwd");
        cmd.add("-root");
        cmd.add("-silent");
        cmd.add("-out");
        cmd.add("/tmp/steam-root-window.xwd");

        try {
            ProcessBuilder pb = new ProcessBuilder(cmd);
            pb.directory(filesDir);
            pb.redirectErrorStream(true);
            pb.redirectOutput(new File(filesDir, "root_capture.log"));
            Map<String, String> env = pb.environment();
            env.put("PROOT_TMP_DIR", prootTmp.getAbsolutePath());
            env.put("LD_LIBRARY_PATH", new File(filesDir, "bin").getAbsolutePath() + ":" + nativeLibDir.getAbsolutePath()
                    + ":" + env.getOrDefault("LD_LIBRARY_PATH", ""));
            if (loaderBin.exists()) env.put("PROOT_LOADER", loaderBin.getAbsolutePath());
            if (loader32Bin.exists()) env.put("PROOT_LOADER_32", loader32Bin.getAbsolutePath());
            Process p = pb.start();
            if (!p.waitFor(8, java.util.concurrent.TimeUnit.SECONDS)) {
                p.destroyForcibly();
                return false;
            }
            if (p.exitValue() != 0 || !capture.isFile() || capture.length() < 100) return false;
            try (java.io.DataInputStream in = new java.io.DataInputStream(new BufferedInputStream(new FileInputStream(capture)))) {
                int[] h = new int[25];
                for (int i = 0; i < h.length; i++) h[i] = in.readInt();
                int headerSize = h[0], width = h[4], height = h[5], byteOrder = h[7];
                int bitsPerPixel = h[11], bytesPerLine = h[12], nColors = h[19];
                long redMask = Integer.toUnsignedLong(h[14]);
                long greenMask = Integer.toUnsignedLong(h[15]);
                long blueMask = Integer.toUnsignedLong(h[16]);
                if (headerSize < 100 || width <= 0 || height <= 0 || bitsPerPixel != 32
                        || bytesPerLine < width * 4 || nColors < 0 || nColors > 65536) return false;
                long extraHeader = headerSize - 100L;
                while (extraHeader > 0) {
                    long skipped = in.skip(extraHeader);
                    if (skipped <= 0) throw new IOException("Incomplete XWD header");
                    extraHeader -= skipped;
                }
                for (int i = 0; i < nColors; i++) {
                    byte[] color = new byte[12];
                    in.readFully(color);
                }
                byte[] row = new byte[bytesPerLine];
                long rgbMask = redMask | greenMask | blueMask;
                for (int y = 0; y < height; y++) {
                    in.readFully(row);
                    for (int x = 0; x < width; x++) {
                        int off = x * 4;
                        long pixel;
                        if (byteOrder == 0) {
                            pixel = (row[off] & 255L) | ((row[off + 1] & 255L) << 8)
                                    | ((row[off + 2] & 255L) << 16) | ((row[off + 3] & 255L) << 24);
                        } else {
                            pixel = ((row[off] & 255L) << 24) | ((row[off + 1] & 255L) << 16)
                                    | ((row[off + 2] & 255L) << 8) | (row[off + 3] & 255L);
                        }
                        if ((pixel & rgbMask) != 0) return false;
                    }
                }
                return true;
            }
        } catch (Exception e) {
            Log.w(TAG, "X root-window capture failed; skipping black-frame fallback sample: " + e.getMessage());
            return false;
        } finally {
            capture.delete();
        }
    }

    private void stopGpuRuntimeProcessAfterFallback() {
        if (steamProcess == null) return;
        Thread stopper = new Thread(() -> {
            try {
                Thread.sleep(12000L);
                int pid = findProotProcessPid();
                if (pid > 0) {
                    Log.w(TAG, "GPU Steam shut down but PRoot is still alive; sending SIGTERM to pid " + pid + " for software restart");
                    android.os.Process.sendSignal(pid, 15);
                    long deadline = System.currentTimeMillis() + 5000L;
                    while (System.currentTimeMillis() < deadline && findProotProcessPid() == pid) Thread.sleep(250L);
                }
                pid = findProotProcessPid();
                if (pid > 0) {
                    Log.w(TAG, "PRoot did not exit after SIGTERM; sending SIGKILL to pid " + pid);
                    android.os.Process.sendSignal(pid, 9);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } catch (Exception e) {
                Log.e(TAG, "Failed stopping GPU PRoot wrapper after software fallback: " + e.getMessage(), e);
            }
        }, "gpu-fallback-stopper");
        stopper.setDaemon(true);
        stopper.start();
    }

    private int findProotProcessPid() {
        int myUid = android.os.Process.myUid();
        File procDir = new File("/proc");
        File[] entries = procDir.listFiles();
        if (entries == null) return -1;
        for (File entry : entries) {
            int pid;
            try {
                pid = Integer.parseInt(entry.getName());
            } catch (NumberFormatException e) {
                continue;
            }
            try {
                if (Os.stat(entry.getAbsolutePath()).st_uid != myUid) continue;
                byte[] buf = new byte[4096];
                int n;
                try (FileInputStream in = new FileInputStream(new File(entry, "cmdline"))) {
                    n = in.read(buf);
                }
                if (n <= 0) continue;
                String cmdline = new String(buf, 0, n, StandardCharsets.UTF_8);
                if (cmdline.contains("libproot.so") && cmdline.contains("--link2symlink")) return pid;
            } catch (Exception ignored) {}
        }
        return -1;
    }

    public void clearPlayingStatus() {
        synchronized (this) {
            if (isClearPlayingInProgress || isShuttingDown) {
                Log.i(TAG, "clearPlayingStatus ignored: already in progress or shutting down");
                return;
            }
            isClearPlayingInProgress = true;
        }

        new Thread(() -> {
            try {
                Log.i(TAG, "Starting clearPlayingStatus sequence");
                updateNotification("Steam: restarting to clear Playing status\u2026");

                // Stop the supervisor worker loop gracefully so it doesn't fight the restart
                stopRequested = true;
                synchronized (supervisorLock) {
                    supervisorLock.notifyAll();
                }
                Thread supervisor = workerThread;
                if (supervisor != null && supervisor.isAlive()) {
                    supervisor.interrupt();
                }

                // 1. run /root/steamrtarm64/steam -shutdown inside proot and wait up to 20 s
                int initialSteamPid = findSteamPid();
                if (initialSteamPid > 0) {
                    Log.i(TAG, "Running steam -shutdown inside proot (pid=" + initialSteamPid + ")");
                    try {
                        List<String> shutdownCmd = buildProotSteamCmd("/root/steamrtarm64/steam -shutdown");
                        Process p = startProotSteamProcess(shutdownCmd);
                        if (p != null) {
                            try {
                                p.waitFor(5, java.util.concurrent.TimeUnit.SECONDS);
                            } catch (Exception ignored) {}
                        }
                    } catch (Exception e) {
                        Log.w(TAG, "Error executing steam -shutdown: " + e.getMessage());
                    }

                    // Wait up to 20s for steam to exit
                    long deadline = System.currentTimeMillis() + 20000L;
                    while (System.currentTimeMillis() < deadline) {
                        if (findSteamPid() <= 0) {
                            Log.i(TAG, "Steam process exited gracefully within 20s");
                            break;
                        }
                        try {
                            Thread.sleep(500L);
                        } catch (InterruptedException ignored) {}
                    }
                }

                // If still running after 20s, send SIGTERM
                int pidAfterGrace = findSteamPid();
                if (pidAfterGrace > 0) {
                    Log.w(TAG, "Steam process " + pidAfterGrace + " still alive after 20s; sending SIGTERM");
                    try {
                        android.os.Process.sendSignal(pidAfterGrace, 15);
                    } catch (Throwable t) {
                        Log.w(TAG, "Failed sending SIGTERM to steam PID: " + t.getMessage());
                    }
                }
                if (steamProcess != null) {
                    try {
                        steamProcess.destroy();
                    } catch (Exception ignored) {}
                }
                try {
                    Runtime.getRuntime().exec(new String[]{"/system/bin/sh", "-c",
                            "pkill -15 steam; pkill -15 steamwebhelper; pkill -15 openbox; pkill -15 libproot.so; pkill -15 proot"}).waitFor();
                } catch (Exception ignored) {}

                // Wait up to 5s after SIGTERM
                long termDeadline = System.currentTimeMillis() + 5000L;
                while (System.currentTimeMillis() < termDeadline) {
                    if (findSteamPid() <= 0 && findProotProcessPid() <= 0) {
                        Log.i(TAG, "Steam and proot processes exited after SIGTERM");
                        break;
                    }
                    try {
                        Thread.sleep(500L);
                    } catch (InterruptedException ignored) {}
                }

                // Then after 5s SIGKILL the proot/steam process tree
                Log.i(TAG, "Sending SIGKILL to proot/steam process tree");
                int remainingPid = findSteamPid();
                if (remainingPid > 0) {
                    try {
                        android.os.Process.sendSignal(remainingPid, 9);
                    } catch (Throwable ignored) {}
                }
                int prootPid = findProotProcessPid();
                if (prootPid > 0) {
                    try {
                        android.os.Process.sendSignal(prootPid, 9);
                    } catch (Throwable ignored) {}
                }
                if (steamProcess != null) {
                    try {
                        steamProcess.destroyForcibly();
                    } catch (Exception ignored) {}
                    steamProcess = null;
                }
                try {
                    Runtime.getRuntime().exec(new String[]{"/system/bin/sh", "-c",
                            "pkill -9 steam; pkill -9 steamwebhelper; pkill -9 openbox; pkill -9 libproot.so; pkill -9 proot; pkill -9 dbus-daemon; pkill -9 dbus-launch; pkill -9 dbus-run-session"}).waitFor();
                } catch (Exception ignored) {}

                // Wait for old supervisor thread to finish
                if (supervisor != null && supervisor.isAlive()) {
                    try {
                        supervisor.join(5000L);
                    } catch (InterruptedException ignored) {}
                }

                // 2. delete root/.crash and STEAMROOT/.crash
                File rootfsDir = new File(getFilesDir(), "rootfs/debian-trixie-aarch64");
                cleanStaleCrashSentinels(rootfsDir);
                try {
                    File crash1 = new File(rootfsDir, "root/.crash");
                    if (crash1.exists()) crash1.delete();
                    File crash2 = new File(rootfsDir, "root/steamrtarm64/.crash");
                    if (crash2.exists()) crash2.delete();
                } catch (Exception ignored) {}

                // 3. relaunch Steam through normal start path
                if (!isShuttingDown) {
                    isRunning = false;
                    stopRequested = false;
                    startRuntime();
                }
            } catch (Exception e) {
                Log.e(TAG, "Error during clearPlayingStatus: " + e.getMessage(), e);
            } finally {
                isClearPlayingInProgress = false;
            }
        }, "steam-clear-playing").start();
    }

    private synchronized void startRuntime() {
        if (isRunning && workerThread != null && workerThread.isAlive()) {
            Log.i(TAG, "Steam runtime worker already active");
            synchronized (supervisorLock) {
                supervisorLock.notifyAll();
            }
            updateStatus();
            return;
        }
        isRunning = true;
        stopRequested = false;
        updateNotification("Steam: Starting...");
        updateStatus();
        // Do not restart Steam when a game process exits. The SDK IPC socket is
        // process-owned and should close with the game; restarting Steam can
        // republish a stale persona record and turn a transient record into a loop.

        workerThread = new Thread(() -> {
            try {
                File filesDir = getFilesDir();
                ensureValveIpcObject(filesDir);
                File binDir = new File(filesDir, "bin");
                if (!binDir.exists()) binDir.mkdirs();
                File tmpDir = new File(filesDir, "tmp");
                if (!tmpDir.exists()) tmpDir.mkdirs();

                File rootfsDir = new File(filesDir, "rootfs/debian-trixie-aarch64");
                File nativeLibDir = new File(getApplicationInfo().nativeLibraryDir);

                // Step 1: Provision rootfs if needed
                extractRootfsIfNeeded();

                // Setup hosts and resolv.conf
                File resolvFile = new File(filesDir, "resolv.conf");
                try (FileWriter fw = new FileWriter(resolvFile, false)) {
                    fw.write("nameserver 8.8.8.8\nnameserver 1.1.1.1\n");
                }
                resolvFile.setReadable(true, false);

                File hostsFile = new File(filesDir, "hosts");
                try (FileWriter fw = new FileWriter(hostsFile, false)) {
                    fw.write("127.0.0.1 localhost\n::1 localhost ip6-localhost ip6-loopback\n");
                }
                hostsFile.setReadable(true, false);

                // Ensure libtalloc.so.2 is available for proot binary
                File tallocSrc = new File(nativeLibDir, "libtalloc.so");
                File tallocDst = new File(binDir, "libtalloc.so.2");
                if (tallocSrc.exists() && !tallocDst.exists()) {
                    try {
                        Files.copy(tallocSrc.toPath(), tallocDst.toPath(), StandardCopyOption.REPLACE_EXISTING);
                        tallocDst.setExecutable(true, false);
                        Log.i(TAG, "Copied libtalloc.so -> bin/libtalloc.so.2");
                    } catch (Exception e) {
                        Log.w(TAG, "Failed copying libtalloc.so.2: " + e.getMessage());
                    }
                }

                File steamShm = new File(tmpDir, "steam-shm");
                if (!steamShm.exists()) steamShm.mkdirs();

                File loaderBin = new File(nativeLibDir, "libproot-loader.so");
                File loader32Bin = new File(nativeLibDir, "libproot-loader32.so");

                // Start X server child process (runs continuously across Steam restarts)
                if (xServerProcess == null || !xServerProcess.isAlive()) {
                    startXServer(filesDir, tmpDir, rootfsDir, nativeLibDir);
                }

                // The runtime now selects Steam's renderer natively.
                File overrideScript = new File(filesDir, "launch_override.sh");
                if (overrideScript.exists() && overrideScript.delete()) {
                    Log.i(TAG, "Removed obsolete launch_override.sh; Steam GPU selection is native");
                }

                // Start connection log tailer thread
                startLogTailer(rootfsDir);

                // Start launcher request watcher
                startLaunchRequestWatcher(tmpDir);

                // Supervisor loop
                while (!stopRequested) {
                    if (xServerProcess == null || !xServerProcess.isAlive()) {
                        startXServer(filesDir, tmpDir, rootfsDir, nativeLibDir);
                    }

                    cleanStaleCrashSentinels(rootfsDir);
                    installRobustShimIfNeeded(rootfsDir);
                    File fakeLsofFile = installFakeLsofIfNeeded(filesDir);

                    // Install launcher script & update shortcuts before Steam launches
                    installLauncherScript(rootfsDir);
                    updateShortcutsAndArtwork(rootfsDir);

                    boolean isProcNetTcpReadable = false;
                    File hostTcp = new File("/proc/net/tcp");
                    if (hostTcp.canRead()) {
                        try (BufferedReader br = new BufferedReader(new FileReader(hostTcp))) {
                            if (br.readLine() != null) {
                                isProcNetTcpReadable = true;
                            }
                        } catch (Exception ignored) {}
                    }

                    File gpuDisabled = new File(filesDir, "gpu_disabled");
                    boolean gpuAvailable = new File(rootfsDir, "opt/mesa-kgsl").exists()
                            && new File("/dev/kgsl-3d0").exists() && !gpuDisabled.exists();
                    renderMode = gpuAvailable ? "gpu" : "software";
                    updateStatus();
                    List<String> steamCmd = buildSteamCmd(filesDir, nativeLibDir, rootfsDir, tmpDir,
                            steamShm, hostsFile, resolvFile, fakeLsofFile, isProcNetTcpReadable, gpuAvailable);

                    ProcessBuilder spb = new ProcessBuilder(steamCmd);
                    spb.directory(filesDir);
                    File logFile = new File(filesDir, "steam_runtime.log");
                    spb.redirectOutput(ProcessBuilder.Redirect.appendTo(logFile));
                    spb.redirectError(ProcessBuilder.Redirect.appendTo(logFile));

                    Map<String, String> senv = spb.environment();
                    senv.put("PROOT_TMP_DIR", tmpDir.getAbsolutePath());
                    if (loaderBin.exists()) senv.put("PROOT_LOADER", loaderBin.getAbsolutePath());
                    if (loader32Bin.exists()) senv.put("PROOT_LOADER_32", loader32Bin.getAbsolutePath());
                    senv.put("LD_LIBRARY_PATH", binDir.getAbsolutePath() + ":" + nativeLibDir.getAbsolutePath() + ":" + senv.getOrDefault("LD_LIBRARY_PATH", ""));

                    try {
                        File envFile = new File(filesDir, "steam_child_env.txt");
                        try (FileWriter envFw = new FileWriter(envFile, false)) {
                            for (Map.Entry<String, String> entry : senv.entrySet()) {
                                envFw.write(entry.getKey() + "=" + entry.getValue() + "\n");
                            }
                        }
                        envFile.setReadable(true, false);
                    } catch (Exception e) {
                        Log.w(TAG, "Failed dumping steam_child_env.txt: " + e.getMessage());
                    }

                    steamProcess = spb.start();
                    long currentRunStartTime = System.currentTimeMillis();
                    steamLaunchTime = currentRunStartTime;
                    hasSeenLogon = false;
                    gpuBlackSince = 0;
                    if (!"Logged On".equals(steamLoginState)) {
                        setSteamLoginState("Connecting");
                    }
                    Log.i(TAG, "PRoot Steam process launched (pid=" + getProcessPid(steamProcess) + ")");
                    updateNotification("Steam: RUNNING (" + steamLoginState + ")");
                    updateStatus();

                    int exitCode = -1;
                    try {
                        exitCode = steamProcess.waitFor();
                    } catch (InterruptedException e) {
                        Log.i(TAG, "steamProcess.waitFor interrupted");
                    }
                    long exitTime = System.currentTimeMillis();
                    lastExitCode = exitCode;
                    sLastExitCode = exitCode;
                    lastExitTime = exitTime;
                    sLastExitTime = exitTime;
                    steamProcess = null;

                    Log.i(TAG, "Steam process exited with code " + exitCode);
                    // Update status.json immediately (steam_alive=false, last_exit_code, last_exit_time)
                    updateStatus();

                    if (stopRequested) {
                        Log.i(TAG, "stopRequested is true, exiting supervisor loop");
                        break;
                    }

                    // Two short GPU runs within the existing supervisor cycle disable GPU until manually cleared.
                    long uptime = exitTime - currentRunStartTime;
                    if (gpuAvailable) {
                        if (uptime < 180000L) {
                            quickGpuExitCount++;
                            if (quickGpuExitCount >= 2) {
                                try {
                                    if (gpuDisabled.createNewFile()) {
                                        Log.e(TAG, "GPU Steam exited twice within 3 minutes; created gpu_disabled and falling back to software mode");
                                    }
                                } catch (Exception e) {
                                    Log.e(TAG, "Failed to create gpu_disabled fallback marker: " + e.getMessage(), e);
                                }
                            }
                        } else {
                            quickGpuExitCount = 0;
                        }
                    }
                    if (uptime >= 600000L) {
                        Log.i(TAG, "Steam ran for >= 10 minutes (" + (uptime / 1000) + "s). Resetting restart backoff.");
                        restartTimestamps.clear();
                        backoffIndex = 0;
                    }

                    // Filter timestamps to last 10 minutes
                    long windowStart = exitTime - 600000L;
                    restartTimestamps.removeIf(t -> t < windowStart);

                    if (restartTimestamps.size() >= 5) {
                        Log.w(TAG, "Max 5 restarts reached within 10 minutes. Pausing restarts.");
                        updateNotification("Steam: Paused (max restarts reached)");
                        long waitTime = (restartTimestamps.get(0) + 600000L) - System.currentTimeMillis();
                        if (waitTime > 0) {
                            synchronized (supervisorLock) {
                                try {
                                    supervisorLock.wait(Math.min(waitTime, 60000L));
                                } catch (InterruptedException ignored) {}
                            }
                        }
                        continue;
                    }

                    long backoffMs;
                    if (backoffIndex == 0) backoffMs = 5000L;
                    else if (backoffIndex == 1) backoffMs = 15000L;
                    else backoffMs = 60000L;
                    backoffIndex++;

                    restartTimestamps.add(exitTime);

                    Log.i(TAG, "Restarting Steam in " + (backoffMs / 1000) + "s (restart " + restartTimestamps.size() + "/5 in 10m)...Code: " + exitCode);
                    updateNotification("Steam: Restarting in " + (backoffMs / 1000) + "s...");

                    synchronized (supervisorLock) {
                        try {
                            if (!stopRequested) {
                                supervisorLock.wait(backoffMs);
                            }
                        } catch (InterruptedException ignored) {}
                    }
                }
            } catch (Exception e) {
                Log.e(TAG, "Error in SteamRuntimeService worker: " + e.getMessage(), e);
            } finally {
                isRunning = false;
                updateNotification("Steam: Stopped");
                updateStatus();
            }
        }, "steam-runtime-worker");
        workerThread.start();
    }

    public synchronized void stopSteam() {
        performFullShutdown();
    }

    public synchronized void performFullShutdown() {
        if (isShuttingDown) {
            Log.i(TAG, "Shutdown already in progress");
            return;
        }
        isShuttingDown = true;
        new Thread(this::doShutdown, "shutdown-worker").start();
    }

    private void doShutdown() {
        Log.i(TAG, "Starting full graceful shutdown sequence");

        // 1. Disable supervisor first so nothing auto-restarts
        stopRequested = true;
        synchronized (supervisorLock) {
            supervisorLock.notifyAll();
        }
        isRunning = false;

        if (launchRequestObserver != null) {
            try {
                launchRequestObserver.stopWatching();
            } catch (Exception ignored) {}
            launchRequestObserver = null;
        }
        cancelSigninNotification();

        // 2. Update status.json to steam state "Stopped"
        setSteamLoginState("Stopped");
        updateNotification("Steam: Stopped");
        updateStatus();

        // 3. Stop Steam gracefully: run /root/steamrtarm64/steam -shutdown inside proot
        int initialSteamPid = findSteamPid();
        if (initialSteamPid > 0) {
            Log.i(TAG, "Running steam -shutdown inside proot (steam pid=" + initialSteamPid + ")");
            try {
                List<String> shutdownCmd = buildProotSteamCmd("/root/steamrtarm64/steam -shutdown");
                Process p = startProotSteamProcess(shutdownCmd);
                if (p != null) {
                    try {
                        p.waitFor(5, java.util.concurrent.TimeUnit.SECONDS);
                    } catch (Exception ignored) {}
                }
            } catch (Exception e) {
                Log.w(TAG, "Error executing steam -shutdown: " + e.getMessage());
            }

            // Wait up to 15s for the steam process to exit
            long deadline = System.currentTimeMillis() + 15000L;
            while (System.currentTimeMillis() < deadline) {
                if (findSteamPid() <= 0) {
                    Log.i(TAG, "Steam process exited gracefully within 15s");
                    break;
                }
                try {
                    Thread.sleep(500L);
                } catch (InterruptedException ignored) {}
            }

            // If still running after 15s, send SIGTERM
            int pidAfterGrace = findSteamPid();
            if (pidAfterGrace > 0) {
                Log.w(TAG, "Steam process " + pidAfterGrace + " still alive after 15s; sending SIGTERM");
                try {
                    android.os.Process.sendSignal(pidAfterGrace, 15);
                } catch (Throwable t) {
                    Log.w(TAG, "Failed sending SIGTERM to steam PID: " + t.getMessage());
                }
            }
            if (steamProcess != null) {
                try {
                    steamProcess.destroy();
                } catch (Exception ignored) {}
            }
            try {
                Runtime.getRuntime().exec(new String[]{"/system/bin/sh", "-c",
                        "pkill -15 steam; pkill -15 steamwebhelper; pkill -15 openbox; pkill -15 libproot.so; pkill -15 proot"}).waitFor();
            } catch (Exception ignored) {}

            // Wait up to 5s after SIGTERM
            long termDeadline = System.currentTimeMillis() + 5000L;
            while (System.currentTimeMillis() < termDeadline) {
                if (findSteamPid() <= 0 && findProotProcessPid() <= 0) {
                    Log.i(TAG, "Steam and proot processes exited after SIGTERM");
                    break;
                }
                try {
                    Thread.sleep(500L);
                } catch (InterruptedException ignored) {}
            }

            // Then after 5s SIGKILL the proot/steam process tree
            Log.i(TAG, "Sending SIGKILL to proot/steam process tree");
            int remainingPid = findSteamPid();
            if (remainingPid > 0) {
                try {
                    android.os.Process.sendSignal(remainingPid, 9);
                } catch (Throwable ignored) {}
            }
            int prootPid = findProotProcessPid();
            if (prootPid > 0) {
                try {
                    android.os.Process.sendSignal(prootPid, 9);
                } catch (Throwable ignored) {}
            }
            if (steamProcess != null) {
                try {
                    steamProcess.destroyForcibly();
                } catch (Exception ignored) {}
                steamProcess = null;
            }
            try {
                Runtime.getRuntime().exec(new String[]{"/system/bin/sh", "-c",
                        "pkill -9 steam; pkill -9 steamwebhelper; pkill -9 openbox; pkill -9 libproot.so; pkill -9 proot; pkill -9 dbus-daemon; pkill -9 dbus-launch; pkill -9 dbus-run-session"}).waitFor();
            } catch (Exception ignored) {}
        } else {
            Log.i(TAG, "Steam was not running, ensuring any lingering processes are terminated");
            if (steamProcess != null) {
                try {
                    steamProcess.destroyForcibly();
                } catch (Exception ignored) {}
                steamProcess = null;
            }
            try {
                Runtime.getRuntime().exec(new String[]{"/system/bin/sh", "-c",
                        "pkill -9 steam; pkill -9 steamwebhelper; pkill -9 openbox; pkill -9 libproot.so; pkill -9 proot; pkill -9 dbus-daemon; pkill -9 dbus-launch; pkill -9 dbus-run-session"}).waitFor();
            } catch (Exception ignored) {}
        }

        // 4. Delete the rootfs root/.crash and STEAMROOT/.crash files
        File rootfsDir = new File(getFilesDir(), "rootfs/debian-trixie-aarch64");
        cleanStaleCrashSentinels(rootfsDir);
        try {
            File crash1 = new File(rootfsDir, "root/.crash");
            if (crash1.exists()) crash1.delete();
            File crash2 = new File(rootfsDir, "root/steamrtarm64/.crash");
            if (crash2.exists()) crash2.delete();
        } catch (Exception ignored) {}

        // 5. Stop the X server process (CmdEntryPoint)
        if (xServerProcess != null) {
            try {
                xServerProcess.destroy();
            } catch (Exception ignored) {}
            xServerProcess = null;
        }
        try {
            Runtime.getRuntime().exec(new String[]{"/system/bin/sh", "-c",
                    "pkill -9 -f com.termux.x11.CmdEntryPoint"}).waitFor();
        } catch (Exception ignored) {}

        try {
            File tmpDir = new File(getFilesDir(), "tmp");
            new File(tmpDir, ".X0-lock").delete();
            new File(tmpDir, ".X11-unix/X0").delete();
        } catch (Exception ignored) {}

        // 6. stopForeground(true) and stopSelf()
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            stopForeground(STOP_FOREGROUND_REMOVE);
        } else {
            stopForeground(true);
        }
        NotificationManager nm = getSystemService(NotificationManager.class);
        if (nm != null) {
            nm.cancel(NOTIF_ID);
            nm.cancel(SIGNIN_NOTIF_ID);
        }
        stopSelf();

        // 7. Finish any MainActivity task (finishAndRemoveTask via broadcast, or let it die)
        try {
            MainActivity act = MainActivity.getInstance();
            if (act != null) {
                act.runOnUiThread(() -> {
                    try {
                        act.finishAndRemoveTask();
                    } catch (Throwable t) {
                        act.finishAffinity();
                    }
                });
            }
        } catch (Throwable ignored) {}

        try {
            Intent stopBroadcast = new Intent(MainActivity.ACTION_STOP);
            stopBroadcast.setPackage(getPackageName());
            sendBroadcast(stopBroadcast);
        } catch (Throwable ignored) {}

        // 8. Finally call System.exit(0) or Process.killProcess(myPid), after the service has stopped
        try {
            Thread.sleep(600L);
        } catch (InterruptedException ignored) {}

        Log.i(TAG, "Full shutdown complete, killing process " + android.os.Process.myPid());
        android.os.Process.killProcess(android.os.Process.myPid());
        System.exit(0);
    }

    @Override
    public void onDestroy() {
        performFullShutdown();
        sInstance = null;
        super.onDestroy();
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}
