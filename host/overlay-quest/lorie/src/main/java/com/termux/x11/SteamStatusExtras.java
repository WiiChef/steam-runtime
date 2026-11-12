package com.termux.x11;

import android.content.Context;
import android.util.Log;

import org.json.JSONObject;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Extra status.json fields:
 *  - client_build / client_build_source / client_builddate: identity of the Steam client in the rootfs,
 *    so the client shim can refuse to patch a mismatching libsteamclient.so.
 *  - logged_on / account_present / owned_apps / login_probe: result of the bounded in-PRoot
 *    {@code steamstate} helper (rootfs-shims/steamstate.c). The SteamID is never published.
 */
final class SteamStatusExtras {
    private static final String TAG = "SteamStatusExtras";
    private static final long PROBE_INTERVAL_MS = 30_000L;
    private static final int PROBE_TIMEOUT_SEC = 12;
    private static final int MAX_APPIDS = 16;

    private static final AtomicBoolean sProbeRunning = new AtomicBoolean(false);
    private static volatile JSONObject sProbeResult = null;
    private static volatile String sProbeStatus = "pending";
    private static volatile long sProbeTime = 0L;

    private SteamStatusExtras() {}

    private static String clean(String s) {
        return s == null ? "" : s.replaceAll("[^0-9A-Za-z _:.\\-]", "").trim();
    }

    private static String firstLine(File f) {
        try {
            List<String> lines = Files.readAllLines(f.toPath(), StandardCharsets.UTF_8);
            return lines.isEmpty() ? "" : clean(lines.get(0));
        } catch (Exception e) {
            return "";
        }
    }

    /** Extracts the numeric "version" value of a Valve package manifest, or "". */
    private static String manifestVersion(File f) {
        try {
            for (String line : Files.readAllLines(f.toPath(), StandardCharsets.UTF_8)) {
                String t = line.trim();
                if (t.startsWith("\"version\"")) {
                    String digits = t.substring(9).replaceAll("[^0-9]", "");
                    if (!digits.isEmpty()) return digits;
                }
            }
        } catch (Exception ignored) {}
        return "";
    }

    /** Returns {build, source, builddate}. build is "" when unknown. */
    static String[] readClientBuild(File rootfsDir) {
        File steamDir = new File(rootfsDir, "root/steamrtarm64");
        String best = "";
        File[] packageDirs = {new File(rootfsDir, "root/package"), new File(steamDir, "package")};
        for (File packageDir : packageDirs) {
            File[] manifests = packageDir.listFiles(
                    (d, n) -> n.startsWith("steam_client_") && n.endsWith(".manifest"));
            if (manifests != null) {
                for (File m : manifests) {
                    String v = manifestVersion(m);
                    if (v.length() > best.length() || (v.length() == best.length() && v.compareTo(best) > 0)) best = v;
                }
            }
        }
        String date = firstLine(new File(steamDir, "builddate.txt"));
        if (!best.isEmpty()) return new String[]{best, "manifest", date};
        if (!date.isEmpty()) return new String[]{date, "builddate.txt", date};
        return new String[]{"", "none", ""};
    }

    private static List<String> readAppIds(Context ctx) {
        List<String> ids = new ArrayList<>();
        try {
            File f = new File(ctx.getFilesDir(), "probe_appids.txt");
            if (!f.exists()) return ids;
            for (String tok : new String(Files.readAllBytes(f.toPath()), StandardCharsets.UTF_8).split("[\\s,]+")) {
                if (tok.matches("[0-9]{1,10}") && !ids.contains(tok) && ids.size() < MAX_APPIDS) ids.add(tok);
            }
        } catch (Exception e) {
            Log.w(TAG, "Failed reading probe_appids.txt: " + e.getMessage());
        }
        return ids;
    }

    /** Persists the appids to query (comma/space separated, digits only) and forces a re-probe. */
    static void setAppIds(Context ctx, String csv) {
        StringBuilder sb = new StringBuilder();
        int n = 0;
        for (String tok : csv.split("[\\s,]+")) {
            if (tok.matches("[0-9]{1,10}") && n < MAX_APPIDS) { sb.append(tok).append('\n'); n++; }
        }
        try {
            Files.write(new File(ctx.getFilesDir(), "probe_appids.txt").toPath(),
                    sb.toString().getBytes(StandardCharsets.UTF_8));
            sProbeTime = 0L;
        } catch (Exception e) {
            Log.w(TAG, "Failed writing probe_appids.txt: " + e.getMessage());
        }
    }

    private static boolean installHelper(SteamRuntimeService svc, File rootfsDir) {
        try {
            byte[] asset;
            try (InputStream is = svc.getAssets().open("rootfs-shims/steamstate")) {
                ByteArrayOutputStream baos = new ByteArrayOutputStream();
                byte[] buf = new byte[8192];
                int r;
                while ((r = is.read(buf)) != -1) baos.write(buf, 0, r);
                asset = baos.toByteArray();
            }
            File dir = new File(rootfsDir, "usr/local/bin");
            if (!dir.exists()) dir.mkdirs();
            File target = new File(dir, "steamstate");
            if (!target.exists() || !java.util.Arrays.equals(Files.readAllBytes(target.toPath()), asset)) {
                Files.write(target.toPath(), asset);
                target.setExecutable(true, false);
                target.setReadable(true, false);
            }
            return true;
        } catch (Exception e) {
            Log.w(TAG, "steamstate helper asset unavailable: " + e.getMessage());
            return false;
        }
    }

    private static void runProbe(SteamRuntimeService svc) {
        try {
            File rootfsDir = new File(svc.getFilesDir(), "rootfs/debian-trixie-aarch64");
            if (!installHelper(svc, rootfsDir)) {
                sProbeStatus = "unavailable";
                sProbeResult = null;
                return;
            }
            StringBuilder cmd = new StringBuilder("timeout -k 2 " + (PROBE_TIMEOUT_SEC - 2)
                    + " /usr/local/bin/steamstate /root/steamrtarm64");
            for (String id : readAppIds(svc)) cmd.append(' ').append(id);
            cmd.append(" 2>/dev/null");
            String out = svc.runInProot(cmd.toString(), PROBE_TIMEOUT_SEC);
            String line = out == null ? "" : out.trim();
            int nl = line.lastIndexOf('\n');
            if (nl >= 0) line = line.substring(nl + 1).trim();
            if (line.length() > 4096 || !line.startsWith("{") || !line.endsWith("}")) {
                sProbeStatus = out == null ? "timeout" : "no_output";
                sProbeResult = null;
            } else {
                sProbeResult = new JSONObject(line);
                sProbeStatus = sProbeResult.optBoolean("ok", false) ? "ok" : "failed";
            }
        } catch (Exception e) {
            Log.w(TAG, "Login probe failed: " + e.getMessage());
            sProbeStatus = "error";
            sProbeResult = null;
        } finally {
            sProbeTime = System.currentTimeMillis();
            sProbeRunning.set(false);
            // Publish the fresh result.
            SteamRuntimeService.writeStatus(svc, svc);
        }
    }

    /** Starts a background probe when due. Never blocks the caller. */
    private static void refreshProbe(SteamRuntimeService svc, boolean steamUp) {
        if (svc == null || !steamUp) return;
        if (System.currentTimeMillis() - sProbeTime < PROBE_INTERVAL_MS) return;
        if (!sProbeRunning.compareAndSet(false, true)) return;
        sProbeTime = System.currentTimeMillis(); // avoid a restart loop while running
        Thread t = new Thread(() -> runProbe(svc), "steam-login-probe");
        t.setDaemon(true);
        t.start();
    }

    /**
     * Returns JSON object members (without braces, leading comma included) to splice into status.json.
     * @param steamUp true when the client process is alive and its IPC object exists
     */
    static String fragment(Context ctx, SteamRuntimeService svc, File rootfsDir, boolean steamUp) {
        String[] build = readClientBuild(rootfsDir);
        refreshProbe(svc, steamUp);
        JSONObject probe = steamUp ? sProbeResult : null;
        StringBuilder sb = new StringBuilder();
        sb.append(",\n  \"client_build\": ").append(JSONObject.quote(build[0]));
        sb.append(",\n  \"client_build_source\": ").append(JSONObject.quote(build[1]));
        sb.append(",\n  \"client_builddate\": ").append(JSONObject.quote(build[2]));
        if (probe != null && probe.optBoolean("ok", false)) {
            sb.append(",\n  \"logged_on\": ").append(probe.optBoolean("logged_on", false));
            sb.append(",\n  \"account_present\": ").append(probe.optBoolean("account_present", false));
            JSONObject owned = probe.optJSONObject("owned");
            sb.append(",\n  \"owned_apps\": ").append(owned != null ? owned.toString() : "{}");
            sb.append(",\n  \"probe_ifaces\": ").append(JSONObject.quote(
                    clean(probe.optString("client_iface")) + "/" + clean(probe.optString("user_iface"))
                            + "/" + clean(probe.optString("apps_iface"))));
        } else {
            // null = unknown (probe pending/failed); consumers must not treat it as "logged out".
            sb.append(",\n  \"logged_on\": null,\n  \"account_present\": null,\n  \"owned_apps\": {}");
        }
        String pstatus = steamUp ? sProbeStatus : "steam_not_running";
        String perr = probe != null ? clean(probe.optString("error")) : "";
        sb.append(",\n  \"login_probe\": ").append(JSONObject.quote(pstatus));
        sb.append(",\n  \"login_probe_error\": ").append(JSONObject.quote(perr));
        sb.append(",\n  \"login_probe_time\": ").append(sProbeTime);
        return sb.toString();
    }

    /** Runs a process command, returning stdout or null on timeout. */
    static String collect(Process p, int timeoutSec) throws Exception {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        Thread reader = new Thread(() -> {
            try (InputStream is = p.getInputStream()) {
                byte[] buf = new byte[4096];
                int r;
                while ((r = is.read(buf)) != -1) {
                    if (out.size() < 16384) out.write(buf, 0, r);
                }
            } catch (Exception ignored) {}
        }, "steam-login-probe-out");
        reader.setDaemon(true);
        reader.start();
        if (!p.waitFor(timeoutSec, TimeUnit.SECONDS)) {
            p.destroyForcibly();
            return null;
        }
        reader.join(1000);
        return new String(out.toByteArray(), StandardCharsets.UTF_8);
    }
}
