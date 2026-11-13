package com.termux.x11;

import android.content.Context;
import android.util.Log;
import java.io.*;
import java.nio.ByteBuffer;
import java.nio.channels.FileLock;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.security.MessageDigest;
import java.util.*;
import java.util.regex.*;
import java.util.function.BooleanSupplier;
import org.json.*;

/** Steam owns network synchronization. This bridge only reconciles its downloaded tree. */
public final class PortAutoCloud {
    private static final File HOST = new File("/data/user/0/com.steamruntime.dev/files");
    private static final String PREFIX = "Shiny Shoe/MonsterTrain2/";
    private static final Pattern BLOCK = Pattern.compile("\"([^\"]+)\"\\s*\\{([^{}]*)\\}");
    private static final Pattern FIELD = Pattern.compile("\"([^\"]+)\"\\s*\"([^\"]*)\"");
    static final long STABILITY_MS = 250;
    static final long TIME_MARGIN = 120;
    static final long MAX_SKEW = 24 * 60 * 60;

    interface LockedTask<T> { T run() throws Exception; }

    /** The monitor handles threads in one VM, the file lock handles the separate port APK. */
    static synchronized <T> T withLifecycleLock(File host, int appid, LockedTask<T> task) throws Exception {
        File dir = new File(host, "autocloud");
        if (!dir.isDirectory() && !dir.mkdirs()) throw new IOException("Cannot create autocloud directory");
        try (RandomAccessFile file = new RandomAccessFile(new File(dir, appid + ".lock"), "rw");
             FileLock lock = file.getChannel().lock()) {
            return task.run();
        }
    }

    static <T> T withLifecycleLock(int appid, LockedTask<T> task) throws Exception {
        return withLifecycleLock(HOST, appid, task);
    }

    static void afterExit(File host, int appid, BooleanSupplier live, LockedTask<?> reconcile,
                          LockedTask<?> release) throws Exception {
        withLifecycleLock(host, appid, () -> {
            if (live.getAsBoolean()) return null;
            reconcile.run();
            if (!live.getAsBoolean()) release.run();
            return null;
        });
    }

    private static String read(File f) throws IOException {
        return new String(Files.readAllBytes(f.toPath()), StandardCharsets.UTF_8);
    }

    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-1").digest(bytes);
        StringBuilder result = new StringBuilder();
        for (byte b : digest) result.append(String.format(Locale.ROOT, "%02x", b & 255));
        return result.toString();
    }

    private static File safe(File root, String relative) throws IOException {
        File f = new File(root, relative);
        if (!f.getCanonicalPath().startsWith(root.getCanonicalPath() + File.separator))
            throw new IOException("Unsafe cloud path");
        return f;
    }

    private static void write(File target, byte[] bytes, long seconds) throws IOException {
        target.getParentFile().mkdirs();
        File tmp = new File(target.getPath() + ".steam-sync-tmp-" + UUID.randomUUID());
        try {
            try (FileOutputStream out = new FileOutputStream(tmp)) {
                out.write(bytes);
                out.getFD().sync();
            }
            if (!tmp.setLastModified(Math.multiplyExact(seconds, 1000L)))
                throw new IOException("Cannot preserve save timestamp");
            try {
                Files.move(tmp.toPath(), target.toPath(), StandardCopyOption.ATOMIC_MOVE, StandardCopyOption.REPLACE_EXISTING);
            } catch (AtomicMoveNotSupportedException e) {
                Files.move(tmp.toPath(), target.toPath(), StandardCopyOption.REPLACE_EXISTING);
            }
        } finally { tmp.delete(); }
    }

    private static String conflict(File root, String name, byte[] bytes, long timestamp) throws Exception {
        File saved = safe(root, name + ".conflict-" + timestamp + "-" + hash(bytes).substring(0, 12));
        if (!saved.exists()) write(saved, bytes, timestamp);
        return saved.getName();
    }

    static boolean eligible(String name) {
        String n = name.replaceFirst("^(development-save|staging-save)/", "");
        return n.equals("metagameSave.json") || n.equals("metagameSave.json.backup") ||
            n.equals("preferences.json") || n.equals("preferences-local.json") ||
            (n.startsWith("saves/") && n.endsWith(".json")) ||
            (n.startsWith("run-history/") && n.endsWith(".json"));
    }

    private static void collect(File root, File dir, Set<String> names) {
        File[] files = dir.listFiles();
        if (files == null) return;
        for (File f : files) {
            if (f.isDirectory()) collect(root, f, names);
            else {
                String n = root.toPath().relativize(f.toPath()).toString().replace(File.separatorChar, '/');
                if (eligible(n)) names.add(n);
            }
        }
    }

    /** Snapshot bytes are used for staging so a subsequent writer cannot change the upload payload. */
    static final class Save {
        final byte[] bytes;
        final String sha;
        final long modified;
        Save(File file) throws Exception {
            long size = file.length();
            modified = file.lastModified();
            bytes = Files.readAllBytes(file.toPath());
            Thread.sleep(STABILITY_MS);
            if (!file.isFile() || size != bytes.length || size != file.length() || modified != file.lastModified() ||
                    !Arrays.equals(bytes, Files.readAllBytes(file.toPath())))
                throw new IOException("Save is being written; retry on next pass");
            validateJson(bytes);
            sha = hash(bytes);
        }
        void unchanged(File file) throws Exception {
            if (!file.isFile() || modified != file.lastModified() || !Arrays.equals(bytes, Files.readAllBytes(file.toPath())))
                throw new IOException("Save changed before mutation; retry on next pass");
        }
    }

    // Android's JSONTokener accepts truncated/lenient JSON (single quotes, missing values, etc.).
    // Require the strict JSON object format used by MT2's JsonUtility saves and backups.
    static void validateJson(byte[] bytes) throws Exception {
        String text = StandardCharsets.UTF_8.newDecoder().decode(ByteBuffer.wrap(bytes)).toString();
        new StrictJson(text).parse();
    }

    private static final class StrictJson {
        final String text;
        int pos;
        StrictJson(String text) { this.text = text; }
        void fail() throws IOException { throw new IOException("Empty or invalid JSON save"); }
        void whitespace() { while (pos < text.length() && " \r\n\t".indexOf(text.charAt(pos)) >= 0) pos++; }
        boolean take(char c) { whitespace(); if (pos < text.length() && text.charAt(pos) == c) { pos++; return true; } return false; }
        void require(char c) throws IOException { if (!take(c)) fail(); }
        void parse() throws IOException {
            if (!take('{')) fail();
            object(0);
            whitespace();
            if (pos != text.length()) fail();
        }
        void object(int depth) throws IOException {
            if (take('}')) return;
            do { string(); require(':'); value(depth + 1); } while (take(','));
            require('}');
        }
        void string() throws IOException {
            require('"');
            while (pos < text.length()) {
                char c = text.charAt(pos++);
                if (c == '"') return;
                if (c < 32) fail();
                if (c == '\\') {
                    if (pos == text.length()) fail();
                    c = text.charAt(pos++);
                    if (c == 'u') {
                        for (int i = 0; i < 4; i++) {
                            if (pos == text.length() || "0123456789abcdefABCDEF".indexOf(text.charAt(pos++)) < 0) fail();
                        }
                    } else if ("\"\\/bfnrt".indexOf(c) < 0) fail();
                }
            }
            fail();
        }
        void value(int depth) throws IOException {
            if (depth > 256) fail();
            whitespace();
            if (pos == text.length()) fail();
            char c = text.charAt(pos);
            if (c == '"') { string(); return; }
            if (take('{')) { object(depth); return; }
            if (take('[')) {
                if (take(']')) return;
                do { value(depth + 1); } while (take(','));
                require(']'); return;
            }
            for (String literal : new String[] {"true", "false", "null"}) {
                if (text.startsWith(literal, pos)) { pos += literal.length(); return; }
            }
            Matcher number = Pattern.compile("-?(?:0|[1-9][0-9]*)(?:\\.[0-9]+)?(?:[eE][+-]?[0-9]+)?").matcher(text);
            number.region(pos, text.length());
            if (!number.lookingAt()) fail();
            pos = number.end();
        }
    }

    static String decide(String local, String cloud, JSONObject previous, String change,
                         long qt, long ct, long now, boolean upload) {
        // A durable deletion intent may precede removal of the old mirror bytes.
        // Only those exact bytes belong to the deletion we staged.
        if (previous != null && previous.has("deleted_cloud_sha") && previous.isNull("cloud_sha") &&
            Objects.equals(cloud, previous.optString("deleted_cloud_sha"))) cloud = null;
        if (local == null) {
            if (previous != null) {
                // App-wide ChangeNumber cannot identify a change to this file.
                // Unreconciled history compares against the last validated local bytes.
                String baseline = previous.has("cloud_sha") ? previous.optString("cloud_sha", null) :
                    previous.optString("seen_local_sha", previous.optString("local_sha", null));
                boolean cloudChanged = cloud != null && (previous.has("cloud_sha") || baseline != null) &&
                    !cloud.equals(baseline);
                if (!cloudChanged) return "local deletion";
            }
            return ct > now || ct < 0 ? "clock conflict" : "download";
        }
        if (local.equals(cloud)) return "identical";
        if (qt > now || ct > now || qt < 0 || ct < 0) return "clock conflict";
        if (previous != null && previous.has("local_sha")) {
            boolean localChanged = !local.equals(previous.optString("local_sha"));
            String previousCloud = previous.isNull("cloud_sha") ? null : previous.optString("cloud_sha");
            boolean cloudChanged = !Objects.equals(cloud, previousCloud);
            if (localChanged && cloudChanged) return "content conflict";
            if (cloudChanged) return "download";
            if (localChanged) return upload ? "upload" : "upload disabled";
            return "pending Steam acknowledgement";
        }
        if (cloud == null) return upload ? "upload" : "upload disabled";
        long delta = qt - ct;
        if (Math.abs(delta) > MAX_SKEW || Math.abs(delta) <= TIME_MARGIN) return "clock conflict";
        return delta < 0 ? "download" : (upload ? "upload" : "upload disabled");
    }

    // RunHistoryDataJson.RunEntry embeds the full submitted RunAggregateData as JSON.
    // For single-player runs this is recorded on end/abandon, before the local save is removed.
    private static Save completedRunHistory(File quest, Save cloud) throws Exception {
        String id = new JSONObject(new String(cloud.bytes, StandardCharsets.UTF_8)).optString("id");
        File file = safe(quest, "run-history/RunHistory.json");
        if (id.isEmpty() || !file.isFile()) return null;
        Save history = new Save(file);
        JSONArray entries = new JSONObject(new String(history.bytes, StandardCharsets.UTF_8)).optJSONArray("_runEntries");
        if (entries == null) return null;
        for (int i = 0; i < entries.length(); i++) {
            JSONObject entry = entries.optJSONObject(i);
            if (entry == null || !id.equals(entry.optString("runId")) || !entry.optBoolean("isFull")) continue;
            JSONObject run = new JSONObject(entry.getString("runDataJson"));
            if (id.equals(run.optString("id")) && run.optBoolean("isFull") &&
                run.has("endless") && !run.getBoolean("endless")) return history;
        }
        return null;
    }

    public static JSONObject sync(Context context, int appid, File quest, String phase) {
        try { return withLifecycleLock(appid, () -> syncLocked(HOST, appid, quest, phase)); }
        catch (Exception e) {
            Log.w("PortAutoCloud", "Cannot acquire cloud lifecycle lock");
            JSONObject report = new JSONObject();
            try { report.put("ok", false).put("error", "Cloud lifecycle lock unavailable"); } catch (JSONException ignored) { }
            return report;
        }
    }

    /** Caller holds the same lock through process checks, reconciliation and session release. */
    static JSONObject syncLocked(File host, int appid, File quest, String phase) {
        JSONObject report = new JSONObject();
        JSONArray rows = new JSONArray();
        File dir = new File(host, "autocloud");
        try {
            long now = System.currentTimeMillis() / 1000L;
            report.put("appid", appid).put("phase", phase).put("created", now).put("files", rows);
            if (appid != 2742830) throw new IOException("No cloud mapping for this AppID");
            JSONObject status = new JSONObject(read(new File(host, "status.json")));
            boolean online = status.optBoolean("logged_on", false) && "Logged On".equals(status.optString("steam_login_state"));
            report.put("cloud_online", online);
            File steam = new File(host, "rootfs/debian-trixie-aarch64/root/steamrtarm64");
            File[] users = new File(steam, "userdata").listFiles();
            File cache = null;
            if (users != null) for (File user : users) {
                File candidate = new File(user, appid + "/remotecache.vdf");
                if (candidate.isFile()) {
                    if (cache != null) throw new IOException("Ambiguous cloud account");
                    cache = candidate;
                }
            }
            if (cache == null) throw new IOException("No downloaded Auto-Cloud inventory; refusing writes");
            String snapshot = read(cache);
            File mirror = new File(steam, "steamapps/compatdata/" + appid + "/pfx/drive_c/users/steamuser/AppData/LocalLow/Shiny Shoe/MonsterTrain2");
            Map<String, Map<String, String>> remote = new TreeMap<>();
            Matcher blocks = BLOCK.matcher(snapshot);
            while (blocks.find()) if (blocks.group(1).startsWith(PREFIX)) {
                Map<String, String> fields = new HashMap<>();
                Matcher pairs = FIELD.matcher(blocks.group(2));
                while (pairs.find()) fields.put(pairs.group(1), pairs.group(2));
                if (!"12".equals(fields.get("root"))) throw new IOException("Unexpected Auto-Cloud root");
                String name = blocks.group(1).substring(PREFIX.length());
                if (eligible(name)) remote.put(name, fields);
            }
            if (remote.isEmpty()) throw new IOException("Empty cloud inventory is not proof of an empty cloud");
            String change = "";
            Matcher fields = FIELD.matcher(snapshot);
            while (fields.find()) if ("ChangeNumber".equalsIgnoreCase(fields.group(1))) { change = fields.group(2); break; }
            File stateFile = new File(dir, appid + "-state.json");
            JSONObject state = stateFile.isFile() ? new JSONObject(read(stateFile)) : new JSONObject();
            String account = cache.getParentFile().getParentFile().getName();
            if (state.has("account") && !account.equals(state.getString("account")))
                throw new IOException("Cloud account changed; sync history belongs to another account");
            state.put("account", account);
            JSONObject history = state.optJSONObject("files");
            if (history == null) { history = new JSONObject(); state.put("files", history); }
            boolean upload = "after-exit".equals(phase) && new File(dir, appid + ".allow-uploads").isFile();
            report.put("uploads_enabled", upload);
            Set<String> names = new TreeSet<>(remote.keySet());
            collect(quest, quest, names);
            Iterator<String> keys = history.keys();
            while (keys.hasNext()) names.add(keys.next());
            for (String name : names) {
                JSONObject row = new JSONObject().put("file", name);
                rows.put(row);
                try {
                    if (name.endsWith("preferences-local.json")) { row.put("action", "local-only"); continue; }
                    if (!online) { row.put("action", "blocked; logged off"); continue; }
                    File local = safe(quest, name), cloud = safe(mirror, name);
                    Map<String, String> meta = remote.get(name);
                    if (meta == null && cloud.exists()) {
                        row.put("action", "blocked; untracked mirror file awaits Steam inventory"); continue;
                    }
                    // Missing mirror entries (including Steam tombstones) are isolated per file.
                    // syncstate values are undocumented, so never infer deletion from a numeric value alone.
                    if (meta != null && (!cloud.isFile() || "2".equals(meta.get("persiststate"))) && !local.isFile()) {
                        row.put("action", "skipped deleted/absent cloud entry"); continue;
                    }
                    // Record existence before validating or changing bytes. An invalid save must
                    // still leave deletion history if the game later removes it.
                    if (local.isFile() && !history.has(name)) {
                        history.put(name, new JSONObject().put("seen_local", true));
                        write(stateFile, state.toString(2).getBytes(StandardCharsets.UTF_8), now);
                    }
                    Save localSave = local.isFile() ? new Save(local) : null;
                    JSONObject previous = history.optJSONObject(name);
                    if (localSave != null && previous != null && !previous.has("cloud_sha")) {
                        previous.put("seen_local_sha", localSave.sha);
                        write(stateFile, state.toString(2).getBytes(StandardCharsets.UTF_8), now);
                    }
                    Save remoteSave = meta == null || !cloud.isFile() ? null : new Save(cloud);
                    if (remoteSave != null && !remoteSave.sha.equalsIgnoreCase(meta.get("sha")))
                        throw new IOException("Cloud cache hash mismatch");
                    long qt = localSave == null ? 0 : localSave.modified / 1000L;
                    long ct = remoteSave == null ? 0 : Long.parseLong(meta.get("remotetime"));
                    String action = decide(localSave == null ? null : localSave.sha,
                        remoteSave == null ? null : remoteSave.sha, previous, change, qt, ct, now, upload);
                    row.put("action", action).put("quest_time", qt).put("cloud_time", ct);
                    if (!read(cache).equals(snapshot)) throw new IOException("Cloud inventory changed");
                    if (localSave != null) localSave.unchanged(local);
                    if (remoteSave != null) remoteSave.unchanged(cloud);
                    if (action.equals("local deletion")) {
                        row.put("action", "local deletion retained; cloud deletion not staged");
                        // All other missing files retain delete-and-rename crash protection.
                        if (upload && name.equals("saves/save-singlePlayer.json") && remoteSave != null &&
                            previous != null && remoteSave.sha.equals(previous.optString("cloud_sha",
                                previous.optString("deleted_cloud_sha"))) &&
                            ct >= 0 && ct <= now) {
                            Save completion = completedRunHistory(quest, remoteSave);
                            if (completion != null) {
                                row.put("conflict", conflict(quest, name, remoteSave.bytes, ct));
                                // Persist intent before removing bytes so a crash can safely retry.
                                history.put(name, record(null, null, change, ct).put("deleted_cloud_sha", remoteSave.sha));
                                write(stateFile, state.toString(2).getBytes(StandardCharsets.UTF_8), now);
                                if (!new File(dir, appid + ".allow-uploads").isFile()) throw new IOException("Upload marker removed");
                                completion.unchanged(safe(quest, "run-history/RunHistory.json"));
                                if (local.exists()) throw new IOException("Local save appeared before deletion");
                                remoteSave.unchanged(cloud);
                                if (!read(cache).equals(snapshot)) throw new IOException("Cloud inventory changed");
                                Files.delete(cloud.toPath());
                                row.put("action", "completed run cloud deletion staged");
                            }
                        }
                        Log.i("PortAutoCloud", row.getString("action"));
                    } else if (action.equals("download") && remoteSave != null) {
                        if (localSave != null) row.put("conflict", conflict(quest, name, localSave.bytes, qt));
                        if (localSave == null && local.exists()) throw new IOException("Local save appeared before download");
                        if (localSave != null) localSave.unchanged(local);
                        remoteSave.unchanged(cloud);
                        if (!read(cache).equals(snapshot)) throw new IOException("Cloud inventory changed");
                        if (localSave == null && previous == null) {
                            // Persist existence intent first. A failed history write must never
                            // leave a new local save that could later be resurrected after deletion.
                            history.put(name, new JSONObject().put("seen_local", true).put("seen_local_sha", remoteSave.sha));
                            write(stateFile, state.toString(2).getBytes(StandardCharsets.UTF_8), now);
                        }
                        write(local, remoteSave.bytes, ct);
                        history.put(name, record(remoteSave.sha, remoteSave.sha, change, ct));
                    } else if (action.equals("upload")) {
                        if (remoteSave != null) row.put("conflict", conflict(quest, name, remoteSave.bytes, ct));
                        // Recheck the opt-in at the mutation boundary too.
                        if (!new File(dir, appid + ".allow-uploads").isFile()) throw new IOException("Upload marker removed");
                        localSave.unchanged(local);
                        if (remoteSave != null) remoteSave.unchanged(cloud);
                        if (remoteSave == null && cloud.exists()) throw new IOException("Cloud save appeared before upload");
                        if (!read(cache).equals(snapshot)) throw new IOException("Cloud inventory changed");
                        write(cloud, localSave.bytes, qt);
                        // Steam must acknowledge these staged bytes in its next inventory.
                        // A different validated cloud hash is a subsequent cloud change.
                        history.put(name, record(localSave.sha, localSave.sha, change, qt));
                    } else if (action.equals("identical")) {
                        history.put(name, record(localSave.sha, remoteSave.sha, change, ct));
                    } else if (action.contains("conflict")) {
                        if (remoteSave != null) row.put("conflict", conflict(quest, name, remoteSave.bytes, ct));
                        Log.i("PortAutoCloud", "Divergent saves retained; " + action);
                    }
                    write(stateFile, state.toString(2).getBytes(StandardCharsets.UTF_8), now);
                } catch (Exception e) {
                    row.put("action", "blocked; " + e.getMessage());
                    Log.w("PortAutoCloud", "File reconciliation blocked; " + e.getMessage());
                }
            }
            report.put("ok", online);
        } catch (Exception e) {
            try { report.put("ok", false).put("error", e.getMessage()); } catch (JSONException ignored) { }
            Log.w("PortAutoCloud", "Sync blocked; " + e.getMessage());
        }
        try { write(new File(dir, appid + "-" + phase + ".json"), report.toString(2).getBytes(StandardCharsets.UTF_8), System.currentTimeMillis() / 1000L); }
        catch (Exception e) { Log.w("PortAutoCloud", "Cannot write sync report"); }
        return report;
    }

    private static JSONObject record(String local, String cloud, String change, long ct) throws JSONException {
        return new JSONObject().put("local_sha", local == null ? JSONObject.NULL : local)
            .put("cloud_sha", cloud == null ? JSONObject.NULL : cloud)
            .put("cloud_change_number", change).put("cloud_time", ct);
    }
}
