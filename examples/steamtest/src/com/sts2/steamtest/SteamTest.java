package com.sts2.steamtest;

import android.app.Activity;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Build;
import android.widget.*;

import java.io.File;
import java.io.FileWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

public class SteamTest extends Activity {
    private static final String TAG = "SteamTest";

    static {
        System.loadLibrary("steam_api");
        System.loadLibrary("steamtest");
    }

    // Native declarations
    public static native void nativeSetup(String filesDir, int appId);
    public static native boolean nativeStartService();
    public static native int nativeInit(int appId);
    public static native void nativeRunFrame();
    public static native String nativeGetStatus();
    public static native void nativeRequestLobbyList();
    public static native String nativeGetLobbies();
    public static native void nativeCreateLobby(int lobbyType, int maxMembers);
    public static native void nativeJoinLobby(long lobbyId);
    public static native void nativeLeaveLobby();
    public static native String nativeTestP2P();
    public static native String nativePollLogs();
    public static native void nativeShutdown();

    public static native void nativeSnsStart(int role);
    public static native void nativeSnsStartDirect(long hostSteamId);
    public static native int nativeSnsTick();
    public static native void nativeSnsStop();
    public static native int nativeFriendLobbies();
    public static native void nativeFriendLobbyDump();

    private final Handler handler = new Handler(Looper.getMainLooper());
    private boolean running = true;
    private int currentAppId = 480; // Default: Spacewar (Valve test AppID)
    private volatile boolean snsActive = false;

    // UI elements
    private TextView tvStatusHeader;
    private TextView tvAccountInfo;
    private TextView tvLobbyInfo;
    private LinearLayout layoutLobbies;
    private TextView tvLogConsole;
    private ScrollView svLogs;
    private final SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm:ss.SSS", Locale.US);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (getIntent().hasExtra("appid")) {
            try {
                currentAppId = Integer.parseInt(getIntent().getStringExtra("appid"));
            } catch (Exception ignored) {}
        }

        if (checkSelfPermission("com.termux.permission.RUN_COMMAND") != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[]{"com.termux.permission.RUN_COMMAND"}, 101);
        }

        IntentFilter filter = new IntentFilter("com.sts2.steamtest.CMD");
        if (Build.VERSION.SDK_INT >= 33) {
            registerReceiver(cmdReceiver, filter, Context.RECEIVER_EXPORTED);
        } else {
            registerReceiver(cmdReceiver, filter);
        }

        // Dev: "ipc=memfd" backs the Valve IPC shared object with a private memfd instead of a
        // shared file, to prove the client only needs loopback TCP to reach the Steam runtime.
        if (getIntent() != null && "memfd".equals(getIntent().getStringExtra("ipc"))) {
            try {
                android.system.Os.setenv("STEAMRT_IPC_SHM", "memfd", true);
                appendLog("[IPC] STEAMRT_IPC_SHM=memfd");
            } catch (Exception e) {
                appendLog("[IPC] setenv failed: " + e);
            }
        }

        if (getIntent() != null && getIntent().hasExtra("cmd")) {
            handleCommand(getIntent().getStringExtra("cmd"));
        }

        // Build UI programmatically for zero-resource dependency
        LinearLayout root = new LinearLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setBackgroundColor(Color.parseColor("#121418"));
        root.setPadding(24, 24, 24, 24);

        // Header Title
        TextView tvTitle = new TextView(this);
        tvTitle.setText("Steamworks Multiplayer Diagnostics");
        tvTitle.setTextSize(18f);
        tvTitle.setTypeface(Typeface.DEFAULT_BOLD);
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setPadding(0, 0, 0, 16);
        root.addView(tvTitle);

        // Top Status Card
        LinearLayout cardStatus = new LinearLayout(this);
        cardStatus.setOrientation(LinearLayout.VERTICAL);
        cardStatus.setBackgroundColor(Color.parseColor("#1e222b"));
        cardStatus.setPadding(20, 20, 20, 20);

        tvStatusHeader = new TextView(this);
        tvStatusHeader.setText("SteamAPI: NOT INITIALIZED (AppID: " + currentAppId + ")");
        tvStatusHeader.setTextColor(Color.parseColor("#ffaa00"));
        tvStatusHeader.setTextSize(14f);
        tvStatusHeader.setTypeface(Typeface.DEFAULT_BOLD);
        cardStatus.addView(tvStatusHeader);

        tvAccountInfo = new TextView(this);
        tvAccountInfo.setText("User: Not connected | Universe: Unknown");
        tvAccountInfo.setTextColor(Color.parseColor("#cccccc"));
        tvAccountInfo.setTextSize(12f);
        tvAccountInfo.setPadding(0, 6, 0, 6);
        cardStatus.addView(tvAccountInfo);

        tvLobbyInfo = new TextView(this);
        tvLobbyInfo.setText("Active Lobby: None");
        tvLobbyInfo.setTextColor(Color.parseColor("#88aaff"));
        tvLobbyInfo.setTextSize(12f);
        cardStatus.addView(tvLobbyInfo);

        root.addView(cardStatus);

        // Action Buttons Grid / Rows
        LinearLayout row1 = new LinearLayout(this);
        row1.setOrientation(LinearLayout.HORIZONTAL);
        row1.setPadding(0, 16, 0, 8);

        Button btnStartTermux = makeButton("Start Steam (Termux)", v -> startSteamTermux());
        Button btnStopTermux = makeButton("Stop Steam (Termux)", v -> stopSteamTermux());
        Button btnInitSpace = makeButton("Init Spacewar (480)", v -> initSteam(480));
        Button btnInitStS2 = makeButton("Init StS2 (2868840)", v -> initSteam(2868840));
        Button btnShutdown = makeButton("Shutdown", v -> shutdownSteam());

        row1.addView(btnStartTermux);
        row1.addView(btnStopTermux);
        row1.addView(btnInitSpace);
        row1.addView(btnInitStS2);
        row1.addView(btnShutdown);
        root.addView(row1);

        LinearLayout row2 = new LinearLayout(this);
        row2.setOrientation(LinearLayout.HORIZONTAL);
        row2.setPadding(0, 0, 0, 16);

        Button btnListLobbies = makeButton("Search Lobbies", v -> requestLobbies());
        Button btnCreateFriends = makeButton("Create Friends Lobby", v -> createLobby(1)); // k_ELobbyTypeFriendsOnly
        Button btnCreatePublic = makeButton("Create Public Lobby", v -> createLobby(2)); // k_ELobbyTypePublic
        Button btnTestP2P = makeButton("Test P2P Socket", v -> testP2P());
        Button btnLeaveLobby = makeButton("Leave Lobby", v -> leaveLobby());

        row2.addView(btnListLobbies);
        row2.addView(btnCreateFriends);
        row2.addView(btnCreatePublic);
        row2.addView(btnTestP2P);
        row2.addView(btnLeaveLobby);
        root.addView(row2);

        // Lobbies List Header & Container
        TextView tvLobbyHeader = new TextView(this);
        tvLobbyHeader.setText("Discovered Matchmaking Lobbies:");
        tvLobbyHeader.setTextColor(Color.WHITE);
        tvLobbyHeader.setTextSize(13f);
        tvLobbyHeader.setTypeface(Typeface.DEFAULT_BOLD);
        root.addView(tvLobbyHeader);

        layoutLobbies = new LinearLayout(this);
        layoutLobbies.setOrientation(LinearLayout.VERTICAL);
        layoutLobbies.setBackgroundColor(Color.parseColor("#161920"));
        layoutLobbies.setPadding(12, 12, 12, 12);
        TextView tvNoLobbies = new TextView(this);
        tvNoLobbies.setText("No lobbies discovered yet. Tap 'Search Lobbies' or host on PC Steam.");
        tvNoLobbies.setTextColor(Color.GRAY);
        tvNoLobbies.setTextSize(11f);
        layoutLobbies.addView(tvNoLobbies);
        root.addView(layoutLobbies);

        // Console Log View
        TextView tvLogHeader = new TextView(this);
        tvLogHeader.setText("Live Event Log Console:");
        tvLogHeader.setTextColor(Color.WHITE);
        tvLogHeader.setTextSize(13f);
        tvLogHeader.setTypeface(Typeface.DEFAULT_BOLD);
        tvLogHeader.setPadding(0, 16, 0, 4);
        root.addView(tvLogHeader);

        svLogs = new ScrollView(this);
        LinearLayout.LayoutParams svParams = new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, 0, 1.0f);
        svLogs.setLayoutParams(svParams);
        svLogs.setBackgroundColor(Color.BLACK);
        svLogs.setPadding(12, 12, 12, 12);

        tvLogConsole = new TextView(this);
        tvLogConsole.setTextSize(10f);
        tvLogConsole.setTextColor(Color.parseColor("#00ff88"));
        tvLogConsole.setTypeface(Typeface.MONOSPACE);
        svLogs.addView(tvLogConsole);
        root.addView(svLogs);

        setContentView(root);

        // Initial setup
        new Thread(() -> {
            nativeSetup(getFilesDir().getAbsolutePath(), currentAppId);
            appendLog("Ready. Tap 'Init StS2' or 'Start IPC Service' to test connection.");
        }, "setup-thread").start();

        // Start 100ms frame & log polling loop
        handler.post(pollRunnable);
    }

    private Button makeButton(String text, View.OnClickListener listener) {
        Button b = new Button(this);
        b.setText(text);
        b.setTextSize(11f);
        b.setTextColor(Color.WHITE);
        b.setBackgroundColor(Color.parseColor("#2a3240"));
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                0, ViewGroup.LayoutParams.WRAP_CONTENT, 1.0f);
        lp.setMargins(6, 4, 6, 4);
        b.setLayoutParams(lp);
        b.setOnClickListener(listener);
        return b;
    }

    private final Runnable pollRunnable = new Runnable() {
        @Override
        public void run() {
            if (!running) return;

            nativeRunFrame();
            if (snsActive) {
                int sns = nativeSnsTick();
                if (sns == 1 || sns == 2) {
                    snsActive = false;
                    appendLog("SNSTEST java_done status=" + (sns == 1 ? "PASS" : "FAIL"));
                    Log.i(TAG, "SNSTEST java_done status=" + (sns == 1 ? "PASS" : "FAIL"));
                    nativeSnsStop();
                }
            }
            updateStatusDisplay();
            pollNativeLogs();

            handler.postDelayed(this, 100);
        }
    };

    private void updateStatusDisplay() {
        String status = nativeGetStatus();
        if (status == null || status.isEmpty()) return;

        int initCode = -1;
        boolean loggedOn = false;
        String steamId = "";
        String persona = "";
        String serverTime = "";
        int friendCount = 0;
        long activeLobby = 0;

        String[] parts = status.split(";");
        for (String p : parts) {
            String[] kv = p.split("=", 2);
            if (kv.length == 2) {
                switch (kv[0]) {
                    case "init_code":
                        try { initCode = Integer.parseInt(kv[1]); } catch (Exception ignored) {}
                        break;
                    case "logged_on":
                        loggedOn = "1".equals(kv[1]);
                        break;
                    case "steam_id":
                        steamId = kv[1];
                        break;
                    case "persona":
                        persona = kv[1];
                        break;
                    case "server_time":
                        serverTime = kv[1];
                        break;
                    case "friend_count":
                        try { friendCount = Integer.parseInt(kv[1]); } catch (Exception ignored) {}
                        break;
                    case "active_lobby":
                        try { activeLobby = Long.parseLong(kv[1]); } catch (Exception ignored) {}
                        break;
                }
            }
        }

        if (initCode == 0) {
            tvStatusHeader.setText("SteamAPI: INITIALIZED [OK] (AppID: " + currentAppId + ")");
            tvStatusHeader.setTextColor(Color.parseColor("#00ff66"));
        } else if (initCode > 0) {
            String err = initCode == 1 ? "Generic Failure" : initCode == 2 ? "No Steam Client (IPC)" : initCode == 3 ? "Version Mismatch" : "Code " + initCode;
            tvStatusHeader.setText("SteamAPI: FAILED (" + err + ")");
            tvStatusHeader.setTextColor(Color.parseColor("#ff4444"));
        }

        if (loggedOn) {
            tvAccountInfo.setText("User: " + persona + " (" + steamId + ") | Friends: " + friendCount + " | Server: " + serverTime);
            tvAccountInfo.setTextColor(Color.parseColor("#aaccff"));
        } else if (initCode == 0) {
            tvAccountInfo.setText("SteamAPI Active, waiting for Steam User logon...");
            tvAccountInfo.setTextColor(Color.YELLOW);
        }

        if (activeLobby != 0) {
            tvLobbyInfo.setText("Active Lobby ID: " + activeLobby + " [HOST/MEMBER]");
            tvLobbyInfo.setTextColor(Color.parseColor("#00ffcc"));
        } else {
            tvLobbyInfo.setText("Active Lobby: None");
            tvLobbyInfo.setTextColor(Color.GRAY);
        }

        // Export JSON status file for headless programmatic CLI verification
        try {
            String json = "{\n"
                    + "  \"app_id\": " + currentAppId + ",\n"
                    + "  \"init_code\": " + initCode + ",\n"
                    + "  \"logged_on\": " + (loggedOn ? "true" : "false") + ",\n"
                    + "  \"steam_id\": \"" + steamId + "\",\n"
                    + "  \"persona\": \"" + persona.replace("\"", "\\\"") + "\",\n"
                    + "  \"friend_count\": " + friendCount + ",\n"
                    + "  \"active_lobby\": " + activeLobby + ",\n"
                    + "  \"server_time\": \"" + serverTime + "\"\n"
                    + "}\n";
            File f = new File(getFilesDir(), "steam_mp_status.json");
            FileWriter fw = new FileWriter(f, false);
            fw.write(json);
            fw.close();
            f.setReadable(true, false);
            f.setWritable(true, false);
        } catch (Exception ignored) {}
    }

    private void writeToLogFile(String text) {
        try {
            File ext = getExternalFilesDir(null);
            if (ext != null) {
                File f = new File(ext, "steamtest.log");
                FileWriter fw = new FileWriter(f, true);
                fw.write(text);
                fw.close();
            }
            File tmpLog = new File("/data/local/tmp/steamtest.log");
            FileWriter fwTmp = new FileWriter(tmpLog, true);
            fwTmp.write(text);
            fwTmp.close();
            tmpLog.setReadable(true, false);
            tmpLog.setWritable(true, false);
        } catch (Exception ignored) {}
    }

    private void pollNativeLogs() {
        String logs = nativePollLogs();
        if (logs != null && !logs.isEmpty()) {
            for (String l : logs.split("\n")) {
                if (!l.trim().isEmpty()) {
                    Log.i(TAG, l);
                }
            }
            writeToLogFile(logs);
            if (tvLogConsole != null && svLogs != null) {
                tvLogConsole.append(logs);
                svLogs.post(() -> svLogs.fullScroll(View.FOCUS_DOWN));
            }
        }
    }

    private void appendLog(String msg) {
        String timestamp = timeFormat.format(new Date());
        final String line = "[" + timestamp + "] " + msg + "\n";
        Log.i(TAG, msg);
        writeToLogFile(line);
        runOnUiThread(() -> {
            if (tvLogConsole == null || svLogs == null) return; // UI not ready yet (e.g. headless cmd in onCreate)
            tvLogConsole.append(line);
            svLogs.post(() -> svLogs.fullScroll(View.FOCUS_DOWN));
        });
    }

    private void writeAppIdFile(int appId) {
        try {
            File ext = getExternalFilesDir(null);
            File[] targets = new File[] {
                new File(getFilesDir(), "steam_appid.txt"),
                ext != null ? new File(ext, "steam_appid.txt") : null,
                ext != null && ext.getParentFile() != null ? new File(ext.getParentFile(), "steam_appid.txt") : null
            };
            for (File target : targets) {
                if (target == null) continue;
                java.io.FileOutputStream fos = new java.io.FileOutputStream(target);
                fos.write((String.valueOf(appId) + "\n").getBytes());
                fos.close();
                target.setReadable(true, false);
                target.setWritable(true, false);
            }
        } catch (Exception e) {
            Log.e(TAG, "Failed writing steam_appid.txt: " + e.getMessage());
        }
    }

    private void initSteam(int appId) {
        currentAppId = appId;
        new Thread(() -> {
            appendLog("--- Initializing SteamAPI for AppID " + appId + " ---");
            writeAppIdFile(appId);
            nativeSetup(getFilesDir().getAbsolutePath(), appId);
            int res = nativeInit(appId);
            appendLog("Result: " + res + (res == 0 ? " (SUCCESS)" : " (FAILED)"));
        }, "init-thread").start();
    }

    private void snsStart(int role) {
        int appId = 480; // same init path as init_spacewar
        new Thread(() -> {
            appendLog("--- SNS test starting (role=" + (role == 0 ? "host" : "client") + ", AppID 480) ---");
            writeAppIdFile(appId);
            nativeSetup(getFilesDir().getAbsolutePath(), appId);
            int res = nativeInit(appId);
            if (res != 0) {
                appendLog("SNSTEST java_init_failed code=" + res);
                return;
            }
            appendLog("SteamAPI initialized for AppID 480, starting SNS test...");
            nativeSnsStart(role);
            snsActive = true;
        }, "sns-start-thread").start();
    }

    private void snsStartDirect(long hostSid) {
        int appId = 480; // same init path as sns_client
        new Thread(() -> {
            appendLog("--- SNS direct client starting (host_sid=" + hostSid + ", AppID 480) ---");
            writeAppIdFile(appId);
            nativeSetup(getFilesDir().getAbsolutePath(), appId);
            int res = nativeInit(appId);
            if (res != 0) {
                appendLog("SNSTEST java_init_failed code=" + res);
                return;
            }
            appendLog("SteamAPI initialized for AppID 480, connecting directly to " + hostSid + "...");
            nativeSnsStartDirect(hostSid);
            snsActive = true; // ticked by pollRunnable exactly like sns_client
        }, "sns-direct-start-thread").start();
    }

    private void friendLobbies() {
        int appId = 2868840; // same init path as init_sts2
        new Thread(() -> {
            appendLog("--- Friend lobbies scan starting (AppID " + appId + ") ---");
            writeAppIdFile(appId);
            nativeSetup(getFilesDir().getAbsolutePath(), appId);
            int res = nativeInit(appId);
            if (res != 0) {
                appendLog("FRIENDLOBBY java_init_failed code=" + res);
                return;
            }
            appendLog("SteamAPI initialized for AppID " + appId + ", scanning friend lobbies...");
            final int found = nativeFriendLobbies();
            appendLog("FRIENDLOBBY found=" + found + ", dumping lobby data in ~5s...");
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    nativeFriendLobbyDump();
                    appendLog("FRIENDLOBBY dump complete.");
                }
            }, 5000);
        }, "friend-lobbies-thread").start();
    }

    private void startSteamTermux() {
        new Thread(() -> {
            appendLog("--- Starting Steam Daemon via Termux ---");
            Intent intent = new Intent();
            intent.setClassName("com.termux", "com.termux.app.RunCommandService");
            intent.setAction("com.termux.RUN_COMMAND");
            intent.putExtra("com.termux.RUN_COMMAND_PATH", "/data/data/com.termux/files/usr/bin/steam-start");
            intent.putExtra("com.termux.RUN_COMMAND_BACKGROUND", true);
            try {
                startService(intent);
                appendLog("Dispatched steam-start to Termux.");
            } catch (Exception e) {
                appendLog("Error launching Termux service: " + e.getMessage());
            }
        }, "termux-start-thread").start();
    }

    private void stopSteamTermux() {
        new Thread(() -> {
            appendLog("--- Stopping Steam Daemon via Termux ---");
            shutdownSteam();
            Intent intent = new Intent();
            intent.setClassName("com.termux", "com.termux.app.RunCommandService");
            intent.setAction("com.termux.RUN_COMMAND");
            intent.putExtra("com.termux.RUN_COMMAND_PATH", "/data/data/com.termux/files/usr/bin/steam-stop");
            intent.putExtra("com.termux.RUN_COMMAND_BACKGROUND", true);
            try {
                startService(intent);
                appendLog("Dispatched steam-stop to Termux.");
            } catch (Exception e) {
                appendLog("Error stopping Termux service: " + e.getMessage());
            }
        }, "termux-stop-thread").start();
    }

    private void requestLobbies() {
        new Thread(() -> {
            appendLog("--- Requesting Lobby List ---");
            nativeRequestLobbyList();
            try { Thread.sleep(1000); } catch (InterruptedException ignored) {}
            String lobbies = nativeGetLobbies();
            runOnUiThread(() -> refreshLobbyUI(lobbies));
        }, "lobby-query-thread").start();
    }

    private void refreshLobbyUI(String lobbiesStr) {
        layoutLobbies.removeAllViews();

        // Export discovered lobbies to /data/local/tmp/steam_lobbies.json
        try {
            StringBuilder sb = new StringBuilder("[\n");
            if (lobbiesStr != null && !lobbiesStr.trim().isEmpty()) {
                String[] lines = lobbiesStr.split("\n");
                boolean first = true;
                for (String line : lines) {
                    String[] cols = line.split("\t");
                    if (cols.length >= 4) {
                        if (!first) sb.append(",\n");
                        first = false;
                        sb.append("  {\n")
                          .append("    \"lobby_id\": \"").append(cols[0]).append("\",\n")
                          .append("    \"host\": \"").append(cols[1].replace("\"", "\\\"")).append("\",\n")
                          .append("    \"name\": \"").append(cols[2].replace("\"", "\\\"")).append("\",\n")
                          .append("    \"members\": \"").append(cols[3]).append("\"\n")
                          .append("  }");
                    }
                }
            }
            sb.append("\n]\n");
            File f = new File(getFilesDir(), "steam_lobbies.json");
            FileWriter fw = new FileWriter(f, false);
            fw.write(sb.toString());
            fw.close();
            f.setReadable(true, false);
            f.setWritable(true, false);
        } catch (Exception ignored) {}

        if (lobbiesStr == null || lobbiesStr.trim().isEmpty()) {
            TextView tv = new TextView(this);
            tv.setText("No lobbies currently discovered.");
            tv.setTextColor(Color.GRAY);
            tv.setTextSize(11f);
            layoutLobbies.addView(tv);
            return;
        }

        String[] lines = lobbiesStr.split("\n");
        for (String line : lines) {
            String[] cols = line.split("\t");
            if (cols.length >= 4) {
                final long lobbyId = Long.parseLong(cols[0]);
                String host = cols[1];
                String name = cols[2];
                String members = cols[3];

                LinearLayout row = new LinearLayout(this);
                row.setOrientation(LinearLayout.HORIZONTAL);
                row.setPadding(0, 6, 0, 6);
                row.setGravity(Gravity.CENTER_VERTICAL);

                TextView tvDesc = new TextView(this);
                tvDesc.setText(host + " - " + name + " (" + members + ")");
                tvDesc.setTextColor(Color.WHITE);
                tvDesc.setTextSize(12f);
                LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                        0, ViewGroup.LayoutParams.WRAP_CONTENT, 1.0f);
                tvDesc.setLayoutParams(lp);
                row.addView(tvDesc);

                Button btnJoin = new Button(this);
                btnJoin.setText("Join");
                btnJoin.setTextSize(10f);
                btnJoin.setOnClickListener(v -> joinLobby(lobbyId));
                row.addView(btnJoin);

                layoutLobbies.addView(row);
            }
        }
    }

    private void createLobby(int type) {
        new Thread(() -> {
            appendLog("--- Creating Lobby (type=" + type + ", max=4) ---");
            nativeCreateLobby(type, 4);
        }, "lobby-create-thread").start();
    }

    private void joinLobby(long lobbyId) {
        new Thread(() -> {
            appendLog("--- Joining Lobby ID: " + lobbyId + " ---");
            nativeJoinLobby(lobbyId);
        }, "lobby-join-thread").start();
    }

    private void leaveLobby() {
        new Thread(() -> {
            appendLog("--- Leaving Lobby ---");
            nativeLeaveLobby();
        }, "lobby-leave-thread").start();
    }

    private void testP2P() {
        new Thread(() -> {
            appendLog("--- Testing ISteamNetworkingSockets P2P ---");
            String res = nativeTestP2P();
            appendLog("P2P Result: " + res);
        }, "p2p-thread").start();
    }

    private void shutdownSteam() {
        new Thread(() -> {
            appendLog("--- Shutting Down SteamAPI ---");
            nativeShutdown();
            appendLog("Shutdown complete.");
        }, "shutdown-thread").start();
    }

    private final BroadcastReceiver cmdReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if ("com.sts2.steamtest.CMD".equals(intent.getAction())) {
                String cmd = intent.getStringExtra("cmd");
                long lobbyId = intent.getLongExtra("lobby_id", 0);
                if (lobbyId != 0 && (cmd == null || !cmd.contains(" "))) {
                    cmd = (cmd == null ? "join_lobby" : cmd) + " " + lobbyId;
                }
                handleCommand(cmd);
            }
        }
    };

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        if (intent != null && intent.hasExtra("cmd")) {
            handleCommand(intent.getStringExtra("cmd"));
        }
    }

    public void handleCommand(String cmd) {
        if (cmd == null || cmd.isEmpty()) return;
        appendLog("[CMD] Executing headless command: " + cmd);
        String c = cmd.toLowerCase().trim();

        if (c.startsWith("join_lobby")) {
            String[] parts = c.split("\\s+");
            if (parts.length >= 2) {
                try {
                    long lid = Long.parseLong(parts[1]);
                    joinLobby(lid);
                    return;
                } catch (Exception e) {
                    appendLog("[CMD] Invalid lobby ID: " + parts[1]);
                    return;
                }
            }
        }

        switch (c) {
            case "start_termux":
                startSteamTermux();
                break;
            case "stop_termux":
                stopSteamTermux();
                break;
            case "init":
            case "init_spacewar":
                initSteam(480);
                break;
            case "sns_host":
                snsStart(0);
                break;
            case "sns_client":
                snsStart(1);
                break;
            case "sns_client_direct": {
                String sidStr = getIntent() != null ? getIntent().getStringExtra("host_sid") : null;
                if (sidStr == null || sidStr.isEmpty()) {
                    appendLog("[CMD] sns_client_direct requires extra host_sid (decimal SteamID)");
                    break;
                }
                try {
                    long sid = Long.parseUnsignedLong(sidStr);
                    snsStartDirect(sid);
                } catch (Exception e) {
                    appendLog("[CMD] Invalid host_sid: " + sidStr);
                }
                break;
            }
            case "friend_lobbies":
                friendLobbies();
                break;
            case "init_sts2":
                initSteam(2868840);
                break;
            case "search_lobbies":
            case "list_lobbies":
                requestLobbies();
                break;
            case "create_friends_lobby":
                createLobby(1);
                break;
            case "create_public_lobby":
            case "create_lobby":
            case "host":
                createLobby(2);
                break;
            case "test_p2p":
                testP2P();
                break;
            case "leave_lobby":
                leaveLobby();
                break;
            case "shutdown":
                shutdownSteam();
                break;
            case "dump_status":
            case "status":
                appendLog("[STATUS] " + nativeGetStatus());
                break;
            case "clear_log":
                runOnUiThread(() -> tvLogConsole.setText(""));
                try {
                    new File("/data/local/tmp/steamtest.log").delete();
                } catch (Exception ignored) {}
                break;
            default:
                appendLog("[CMD] Unknown command: " + cmd);
                break;
        }
    }

    @Override
    protected void onDestroy() {
        running = false;
        try {
            unregisterReceiver(cmdReceiver);
        } catch (Exception ignored) {}
        handler.removeCallbacksAndMessages(null);
        nativeShutdown();
        super.onDestroy();
    }
}
