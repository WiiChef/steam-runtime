package com.termux.x11;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.security.MessageDigest;
import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.*;
import org.json.*;

/** Offline integration tests compile the production bridge using host-only Android stubs. */
public class PortAutoCloudTest {
    private static int passed;
    private static int failed;
    private static final String RUN = "saves/save-singlePlayer.json";
    private static final String META = "metagameSave.json";
    private static final String OLD = "{\"saveVersion\":1,\"cards\":[1,2]}";
    private static final String NEW = "{\"saveVersion\":2,\"cards\":[3]}";
    private static final long NOW = System.currentTimeMillis() / 1000L;

    interface Test { void run() throws Exception; }
    private static void test(String name, Test test) {
        try { test.run(); passed++; }
        catch (Throwable error) { failed++; System.out.println("FAIL " + name + " " + error); }
    }
    private static void check(boolean condition, String message) {
        if (!condition) throw new AssertionError(message);
    }
    private static void put(File file, String text, long time) throws Exception {
        file.getParentFile().mkdirs();
        Files.write(file.toPath(), text.getBytes(StandardCharsets.UTF_8));
        check(file.setLastModified(time * 1000L), "set timestamp");
    }
    private static String get(File file) throws Exception {
        return new String(Files.readAllBytes(file.toPath()), StandardCharsets.UTF_8);
    }
    private static String sha(String text) throws Exception {
        StringBuilder result = new StringBuilder();
        for (byte b : MessageDigest.getInstance("SHA-1").digest(text.getBytes(StandardCharsets.UTF_8)))
            result.append(String.format(Locale.ROOT, "%02x", b & 255));
        return result.toString();
    }

    private static class Fixture {
        final File host = Files.createTempDirectory("mt2-cloud-fixture-").toFile();
        final File local = new File(host, "quest");
        final File steam = new File(host, "rootfs/debian-trixie-aarch64/root/steamrtarm64");
        final File mirror = new File(steam, "steamapps/compatdata/2742830/pfx/drive_c/users/steamuser/AppData/LocalLow/Shiny Shoe/MonsterTrain2");
        final File cache = new File(steam, "userdata/123/2742830/remotecache.vdf");
        final Map<String, String> entries = new TreeMap<>();
        String change = "12";
        Fixture() throws Exception {
            put(new File(host, "status.json"), "{\"logged_on\":true,\"steam_login_state\":\"Logged On\"}", NOW);
        }
        File local(String name) { return new File(local, name); }
        File cloud(String name) { return new File(mirror, name); }
        void remote(String name, String text, long time) throws Exception {
            put(cloud(name), text, time);
            entry(name, sha(text), time, "0");
        }
        void entry(String name, String hash, long time, String persist) throws Exception {
            entries.put(name, "\"Shiny Shoe/MonsterTrain2/" + name + "\" {\n\"root\" \"12\"\n\"sha\" \"" + hash +
                "\"\n\"remotetime\" \"" + time + "\"\n\"persiststate\" \"" + persist + "\"\n\"syncstate\" \"1\"\n}\n");
            inventory();
        }
        void inventory() throws Exception {
            put(cache, "\"2742830\" {\n\"ChangeNumber\" \"" + change + "\"\n" + String.join("", entries.values()) + "}\n", NOW);
        }
        void marker() throws Exception { put(new File(host, "autocloud/2742830.allow-uploads"), "", NOW); }
        JSONObject sync(String phase) throws Exception {
            return PortAutoCloud.withLifecycleLock(host, 2742830,
                () -> PortAutoCloud.syncLocked(host, 2742830, local, phase));
        }
        String action(JSONObject report, String name) throws Exception {
            JSONArray rows = report.getJSONArray("files");
            for (int i = 0; i < rows.length(); i++) {
                JSONObject row = rows.getJSONObject(i);
                if (row.getString("file").equals(name)) return row.getString("action");
            }
            throw new AssertionError("Missing row " + name + " " + report);
        }
        void baseline() throws Exception {
            remote(RUN, OLD, NOW - 1000);
            put(local(RUN), OLD, NOW - 1000);
            check(action(sync("before-start"), RUN).equals("identical"), "baseline");
        }
    }

    private static class LivenessFixture {
        final File host = Files.createTempDirectory("mt2-liveness-").toFile();
        final File registrations = new File(host, "port-processes");
        final AtomicInteger procListings = new AtomicInteger();
        final File proc = new File(host, "proc") {
            @Override public File[] listFiles() { procListings.incrementAndGet(); return null; }
        };
        final AtomicLong elapsed = new AtomicLong(1000L);
        final AtomicReference<List<android.app.ActivityManager.RunningAppProcessInfo>> processes = new AtomicReference<>();
        final PortProcessLiveness liveness = new PortProcessLiveness(registrations, proc, processes::get, elapsed::get);
        LivenessFixture() throws Exception { registrations.mkdirs(); register(123, 456); }
        void register(int pid, long start) throws Exception {
            put(new File(registrations, Integer.toString(pid)), "2742830 " + start, NOW);
        }
        void stat(long start) throws Exception {
            put(new File(proc, "123/stat"), "123 (game process) S " + "0 ".repeat(18) + start, NOW);
        }
        void visible(int pid, String name, int uid) {
            android.app.ActivityManager.RunningAppProcessInfo info = new android.app.ActivityManager.RunningAppProcessInfo();
            info.pid = pid; info.processName = name; info.uid = uid;
            processes.set(Collections.singletonList(info));
        }
        boolean live() { return liveness.hasLiveProcess("2742830", "com.game.monstertrain2"); }
        void timeout() { elapsed.addAndGet(PortProcessLiveness.UNKNOWN_TIMEOUT_MS); }
    }

    public static void main(String[] args) throws Exception {
        if (args.length > 0 && args[0].equals("lock-worker")) {
            File host = new File(args[1]);
            put(new File(host, "worker-ready"), "ready", NOW);
            PortAutoCloud.withLifecycleLock(host, 2742830, () -> {
                put(new File(host, "worker-acquired"), "acquired", NOW); return null;
            });
            return;
        }
        for (String invalid : new String[] {"", "{\"saveVersion\":", "garbage", "{'x':1}", "{\"x\":1,}",
                "{\"x\":01}", "{} trailing", "[]", "{\"x\":NaN}", "{\"x\":\"bad\nstring\"}", "{\"x\":\"\\uＦＦＦＦ\"}"}) {
            test("invalid JSON " + invalid.length(), () -> {
                Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); f.marker();
                put(f.local(RUN), invalid, NOW - 100);
                check(f.action(f.sync("after-exit"), RUN).startsWith("blocked;"), "invalid upload blocked");
                check(get(f.cloud(RUN)).equals(OLD), "cloud preserved");
            });
        }
        test("valid save formats", () -> {
            PortAutoCloud.validateJson("{\"saveVersion\":1,\"history\":[true,false,null,-1.25e+3],\"escaped\":\"\\u0041\\n\"}".getBytes(StandardCharsets.UTF_8));
            check(PortAutoCloud.eligible("metagameSave.json.backup"), "backup mapping");
            check(PortAutoCloud.eligible("run-history/RunHistory.json"), "run history mapping");
        });
        test("malformed UTF-8", () -> {
            try { PortAutoCloud.validateJson(new byte[] {123,34,120,34,58,34,(byte)0xff,34,125}); }
            catch (Exception expected) { return; }
            throw new AssertionError("invalid UTF-8 accepted");
        });
        test("file being written", () -> {
            File file = Files.createTempFile("mt2-writing-", ".json").toFile(); put(file, OLD, NOW - 1000);
            Thread writer = new Thread(() -> {
                try { for (int i = 0; i < 10; i++) { Thread.sleep(20); put(file, NEW + " ".repeat(i), NOW - 100); } }
                catch (Exception e) { throw new RuntimeException(e); }
            });
            writer.start();
            boolean blocked = false;
            try { new PortAutoCloud.Save(file); } catch (IOException expected) { blocked = true; }
            writer.join(); check(blocked, "unstable snapshot accepted");
        });
        test("deleted run stays deleted across passes", () -> {
            Fixture f = new Fixture(); f.baseline(); Files.delete(f.local(RUN).toPath());
            for (int i = 0; i < 2; i++) {
                check(f.action(f.sync("before-start"), RUN).startsWith("local deletion"), "tombstone");
                check(!f.local(RUN).exists(), "run resurrected");
            }
            check(get(f.cloud(RUN)).equals(OLD), "download-only deletion changed cloud");
            JSONObject state = new JSONObject(get(new File(f.host, "autocloud/2742830-state.json")));
            check(state.getJSONObject("files").getJSONObject(RUN).getString("cloud_change_number").equals("12"), "cloud revision missing");
        });
        test("marker never propagates run deletion", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); Files.delete(f.local(RUN).toPath());
            for (int i = 0; i < 2; i++) {
                check(f.action(f.sync("after-exit"), RUN).startsWith("local deletion"), "deletion action");
                check(get(f.cloud(RUN)).equals(OLD) && !f.local(RUN).exists(), "cloud deletion or resurrection");
            }
        });
        String finished = new JSONObject(OLD).put("id", "completed-run").toString();
        String completedHistory = new JSONObject().put("_runEntries", new JSONArray().put(new JSONObject()
            .put("runId", "completed-run").put("isFull", true).put("runDataJson", new JSONObject()
                .put("id", "completed-run").put("isFull", true).put("endless", false).toString()))).toString();
        for (String inventory : new String[] {"old", "dropped", "deleted", "deleted bytes"}) {
            for (String mode : new String[] {"upload", "disabled", "startup", "PC changed", "corrupt"}) {
                test("new Quest run after completed deletion " + inventory + " " + mode, () -> {
                    Fixture f = new Fixture();
                    f.remote(META, OLD, NOW - 1000);
                    f.remote(RUN, finished, NOW - 1000); put(f.local(RUN), finished, NOW - 1000);
                    f.sync("before-start"); f.marker(); Files.delete(f.local(RUN).toPath());
                    put(f.local("run-history/RunHistory.json"), completedHistory, NOW - 100);
                    check(f.action(f.sync("after-exit"), RUN).equals("completed run cloud deletion staged"), "deletion setup");
                    if (inventory.equals("dropped")) { f.entries.remove(RUN); f.inventory(); }
                    if (inventory.startsWith("deleted")) f.entry(RUN, sha(finished), NOW - 1000, "2");
                    if (inventory.equals("deleted bytes")) put(f.cloud(RUN), finished, NOW - 1000);
                    String next = "{\"id\":\"quest-C\"}";
                    put(f.local(RUN), mode.equals("corrupt") ? "{" : next, NOW - 10);
                    if (mode.equals("disabled")) Files.delete(new File(f.host, "autocloud/2742830.allow-uploads").toPath());
                    String pc = "{\"id\":\"pc-B\"}";
                    if (mode.equals("PC changed")) f.remote(RUN, pc, NOW - 20);
                    String action = f.action(f.sync(mode.equals("startup") ? "before-start" : "after-exit"), RUN);
                    String expected = mode.equals("PC changed") ? "content conflict" :
                        mode.equals("disabled") || mode.equals("startup") ? "upload disabled" : "upload";
                    boolean missingLive = inventory.equals("old") && !mode.equals("PC changed");
                    boolean lingeringDeleted = inventory.equals("deleted bytes") && mode.equals("upload");
                    check(mode.equals("corrupt") || missingLive || lingeringDeleted ? action.startsWith("blocked;") : action.equals(expected), "unexpected action " + action);
                    check(get(f.local(RUN)).equals(mode.equals("corrupt") ? "{" : next), "Quest save changed");
                    if (mode.equals("upload") && !missingLive && !lingeringDeleted) check(get(f.cloud(RUN)).equals(next), "new Quest run missing");
                    else if (mode.equals("PC changed")) {
                        check(get(f.cloud(RUN)).equals(pc), "PC run overwritten");
                        check(new File(f.local(RUN).getPath() + ".conflict-" + (NOW - 20) + "-" + sha(pc).substring(0, 12)).isFile(), "PC conflict missing");
                    } else check(inventory.equals("deleted bytes") ? get(f.cloud(RUN)).equals(finished) : !f.cloud(RUN).exists(), "unexpected upload");
                });
            }
        }
        for (boolean dropped : new boolean[] {false, true}) {
            test("unexplained cloud deletion still conflicts " + dropped, () -> {
                Fixture f = new Fixture(); f.baseline(); f.remote(META, OLD, NOW - 1000); f.marker();
                Files.delete(f.cloud(RUN).toPath());
                if (dropped) { f.entries.remove(RUN); f.inventory(); }
                put(f.local(RUN), NEW, NOW - 10);
                check(f.action(f.sync("after-exit"), RUN).equals(dropped ? "content conflict" : "blocked; cloud not materialized"), "unexplained cloud deletion ignored");
                check(!f.cloud(RUN).exists() && get(f.local(RUN)).equals(NEW), "conflicting deletion overwritten");
            });
        }
        test("completed run deletion stages only acknowledged single-player save", () -> {
            Fixture f = new Fixture(); f.remote(RUN, finished, NOW - 1000); put(f.local(RUN), finished, NOW - 1000);
            f.sync("before-start"); f.marker(); Files.delete(f.local(RUN).toPath());
            put(f.local("run-history/RunHistory.json"), completedHistory, NOW - 100);
            JSONObject report = f.sync("after-exit");
            check(f.action(report, RUN).equals("completed run cloud deletion staged"), "completion not deleted");
            check(!f.cloud(RUN).exists() && !f.local(RUN).exists(), "completed run survived");
            JSONObject tombstone = new JSONObject(get(new File(f.host, "autocloud/2742830-state.json")))
                .getJSONObject("files").getJSONObject(RUN);
            check(tombstone.optBoolean("reconciled") && !tombstone.has("local_sha") && !tombstone.has("cloud_sha") && tombstone.getString("deleted_cloud_sha").equals(sha(finished)), "deletion tombstone missing");
            check(f.action(f.sync("after-exit"), RUN).equals("blocked; cloud not materialized"), "live inventory must await Steam acknowledgement");
            // Simulate interruption between durable intent and mirror removal.
            put(f.cloud(RUN), finished, NOW - 1000);
            check(f.action(f.sync("after-exit"), RUN).equals("completed run cloud deletion staged"), "deletion intent retry failed");
            check(!f.cloud(RUN).exists() && !f.local(RUN).exists(), "intent retry resurrected run");
            f.remote(RUN, NEW, NOW - 10);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "new PC run blocked after deletion");
        });
        for (String guard : new String[] {"startup", "no marker", "different run", "partial entry", "partial data",
                "endless", "malformed history", "no baseline", "PC changed", "other file", "staging copy"}) {
            test("completed run deletion guard " + guard, () -> {
                Fixture f = new Fixture();
                String name = guard.equals("other file") ? META : guard.equals("staging copy") ? "staging-save/" + RUN : RUN;
                f.remote(name, finished, NOW - 1000); put(f.local(name), finished, NOW - 1000);
                if (!guard.equals("no baseline")) f.sync("before-start");
                if (!guard.equals("no marker")) f.marker();
                Files.delete(f.local(name).toPath());
                JSONObject history = new JSONObject(completedHistory);
                JSONObject entry = history.getJSONArray("_runEntries").getJSONObject(0);
                JSONObject data = new JSONObject(entry.getString("runDataJson"));
                if (guard.equals("different run")) entry.put("runId", "another-run");
                if (guard.equals("partial entry")) entry.put("isFull", false);
                if (guard.equals("partial data")) data.put("isFull", false);
                if (guard.equals("endless")) data.put("endless", true);
                entry.put("runDataJson", data.toString());
                put(f.local("run-history/RunHistory.json"), guard.equals("malformed history") ? "{" : history.toString(), NOW - 100);
                if (guard.equals("PC changed")) f.remote(name, new JSONObject(finished).put("score", 999).toString(), NOW - 10);
                String cloud = get(f.cloud(name));
                f.sync(guard.equals("startup") ? "before-start" : "after-exit");
                check(f.cloud(name).isFile() && get(f.cloud(name)).equals(cloud), "guard deleted cloud " + guard);
            });
        }
        test("deleted run then new PC run downloads", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); Files.delete(f.local(RUN).toPath());
            f.sync("after-exit"); f.remote(RUN, NEW, NOW - 500);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "new PC run suppressed");
            check(get(f.cloud(RUN)).equals(NEW) && get(f.local(RUN)).equals(NEW), "new PC run lost");
            check(f.action(f.sync("before-start"), RUN).equals("identical"), "revision not reconciled");
        });
        test("deleted run with changed hash and older mtime downloads", () -> {
            Fixture f = new Fixture(); f.baseline(); Files.delete(f.local(RUN).toPath());
            f.remote(RUN, NEW, NOW - 2000);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "mtime overrode changed revision");
            check(get(f.local(RUN)).equals(NEW), "new content missing");
        });
        test("PC preference change cannot resurrect deleted run", () -> {
            Fixture f = new Fixture(); f.baseline(); Files.delete(f.local(RUN).toPath());
            f.change = "13"; f.remote("preferences.json", NEW, NOW - 100);
            JSONObject report = f.sync("before-start");
            check(f.action(report, RUN).startsWith("local deletion"), "unrelated revision resurrected run");
            check(!f.local(RUN).exists(), "finished run downloaded");
            check(get(f.local("preferences.json")).equals(NEW), "PC preferences missing");
        });
        for (String cloud : new String[] {OLD, NEW}) {
            test("seen-local-only deleted run " + cloud, () -> {
                Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000);
                put(f.local(RUN), OLD, NOW + 3600);
                check(f.action(f.sync("before-start"), RUN).equals("identical"), "initial baseline");
                // Seed the state shape written when validation succeeds but reconciliation cannot finish.
                JSONObject previous = new JSONObject().put("seen_local", true).put("seen_local_sha", sha(OLD));
                put(new File(f.host, "autocloud/2742830-state.json"),
                    new JSONObject().put("account", "123").put("files", new JSONObject().put(RUN, previous)).toString(), NOW);
                Files.delete(f.local(RUN).toPath()); f.remote(RUN, cloud, NOW - 100);
                String action = f.action(f.sync("before-start"), RUN);
                check(cloud.equals(NEW) ? action.equals("download") : action.startsWith("local deletion"), "seen-local decision");
                check(cloud.equals(NEW) ? get(f.local(RUN)).equals(NEW) : !f.local(RUN).exists(), "seen-local bytes");
            });
        }
        test("seen-local hash recorded with uploads disabled then newer PC run downloads", () -> {
            Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000); put(f.local(RUN), OLD, NOW - 500);
            check(f.action(f.sync("before-start"), RUN).equals("upload disabled"), "unreconciled local file");
            JSONObject previous = new JSONObject(get(new File(f.host, "autocloud/2742830-state.json")))
                .getJSONObject("files").getJSONObject(RUN);
            check(!previous.has("cloud_sha") && previous.getString("seen_local_sha").equals(sha(OLD)), "observed hash missing");
            Files.delete(f.local(RUN).toPath()); f.remote(RUN, NEW, NOW - 100);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "new PC save blocked");
            check(get(f.local(RUN)).equals(NEW), "PC bytes missing");
        });
        for (long time : new long[] {NOW + 3600, -1}) {
            test("seen-local history rejects invalid PC time " + time, () -> {
                Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000); put(f.local(RUN), OLD, NOW - 500);
                f.sync("before-start"); Files.delete(f.local(RUN).toPath());
                f.remote(RUN, NEW, NOW - 100); f.entry(RUN, sha(NEW), time, "0");
                String action = f.action(f.sync("before-start"), RUN);
                check(action.equals("clock conflict") || action.startsWith("blocked;"), "invalid time downloaded " + action);
                check(!f.local(RUN).exists(), "invalid revision resurrected");
            });
        }
        test("failed changed-revision download retains baseline for retry", () -> {
            Fixture f = new Fixture(); f.baseline(); Files.delete(f.local(RUN).toPath());
            f.remote(RUN, NEW, NOW - 500);
            File parent = f.local(RUN).getParentFile(); Files.delete(parent.toPath());
            put(parent, "parent temporarily unavailable", NOW);
            check(f.action(f.sync("before-start"), RUN).startsWith("blocked;"), "write failure ignored");
            Files.delete(parent.toPath()); parent.mkdirs();
            check(f.action(f.sync("before-start"), RUN).equals("download"), "failed download lost previous revision");
            check(get(f.local(RUN)).equals(NEW), "retry lost PC save");
        });
        test("deleted run with future PC revision stays blocked", () -> {
            Fixture f = new Fixture(); f.baseline(); Files.delete(f.local(RUN).toPath());
            f.remote(RUN, NEW, NOW + 3600);
            check(f.action(f.sync("before-start"), RUN).equals("clock conflict"), "future revision accepted");
            check(!f.local(RUN).exists() && get(f.cloud(RUN)).equals(NEW), "future revision changed");
        });
        for (String name : new String[] {META, "metagameSave.json.backup", "preferences.json",
                RUN, "run-history/RunHistory.json", "development-save/metagameSave.json", "staging-save/" + RUN}) {
            test("crash mid delete-rename never changes cloud " + name, () -> {
                Fixture f = new Fixture(); f.remote(name, OLD, NOW - 1000);
                put(f.local(name), OLD, NOW - 1000); f.sync("before-start"); f.marker();
                File temporary = new File(f.local(name).getPath() + ".tmp"); put(temporary, NEW, NOW - 100);
                Files.delete(f.local(name).toPath());
                String inventory = get(f.cache); long modified = f.cloud(name).lastModified();
                // Simulate a crash before rename, then repeated exit/startup passes after restart.
                for (String phase : new String[] {"after-exit", "before-start", "after-exit"}) {
                    check(f.action(f.sync(phase), name).startsWith("local deletion"), "missing local file downloaded");
                    check(get(f.cloud(name)).equals(OLD) && f.cloud(name).lastModified() == modified,
                        "cloud bytes or timestamp changed");
                    check(get(f.cache).equals(inventory), "cloud inventory changed");
                }
                check(!f.local(name).exists() && get(temporary).equals(NEW), "crash snapshot changed");
            });
        }
        test("observed unsynced file deletion", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); put(f.local(RUN), NEW, NOW - 100);
            f.sync("before-start"); Files.delete(f.local(RUN).toPath()); f.marker();
            check(f.action(f.sync("after-exit"), RUN).equals("download"), "different cloud hash suppressed");
            check(get(f.local(RUN)).equals(OLD) && get(f.cloud(RUN)).equals(OLD), "different cloud copy lost");
        });
        test("cache mismatch preserves observed local hash for later PC run", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); put(f.local(RUN), OLD, NOW - 500);
            f.entry(RUN, sha(NEW), NOW - 100, "0");
            check(f.action(f.sync("before-start"), RUN).startsWith("blocked;"), "cache mismatch accepted");
            Files.delete(f.local(RUN).toPath()); f.remote(RUN, NEW, NOW - 100);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "local observation lost on remote failure");
            check(get(f.local(RUN)).equals(NEW), "new PC revision missing");
        });
        test("legacy hashless seen-local history retains deletion protection", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000);
            put(new File(f.host, "autocloud/2742830-state.json"), new JSONObject().put("account", "123")
                .put("files", new JSONObject().put(RUN, new JSONObject().put("seen_local", true))).toString(), NOW);
            check(f.action(f.sync("before-start"), RUN).startsWith("local deletion"), "unproven revision downloaded");
            check(!f.local(RUN).exists(), "hashless legacy run resurrected");
        });
        test("new cloud file downloads", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "new cloud not downloaded");
            check(get(f.local(RUN)).equals(OLD), "wrong download");
        });
        test("near simultaneous timestamps refuse time winner", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); put(f.local(RUN), NEW, NOW - 1050); f.marker();
            check(f.action(f.sync("after-exit"), RUN).equals("clock conflict"), "skew allowed");
            check(get(f.local(RUN)).equals(NEW) && get(f.cloud(RUN)).equals(OLD), "skew overwrote save");
        });
        test("future local refuses upload", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); put(f.local(RUN), NEW, NOW + 3600);
            check(f.action(f.sync("after-exit"), RUN).equals("clock conflict"), "future upload allowed");
            check(get(f.cloud(RUN)).equals(OLD), "future save staged");
        });
        test("future cloud refuses download", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW + 3600);
            check(f.action(f.sync("before-start"), RUN).equals("clock conflict"), "future download allowed");
            check(!f.local(RUN).exists(), "future downloaded");
        });
        test("timestamp margin retains both", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); put(f.local(RUN), NEW, NOW - 950); f.marker();
            check(f.action(f.sync("after-exit"), RUN).equals("clock conflict"), "small time gap chose winner");
        });
        test("baseline content beats mtime", () -> {
            Fixture f = new Fixture(); f.baseline(); f.remote(RUN, NEW, NOW - 2000);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "content baseline ignored");
            check(get(f.local(RUN)).equals(NEW), "cloud content not applied");
        });
        test("both sides changed retains both", () -> {
            Fixture f = new Fixture(); f.baseline(); f.remote(RUN, NEW, NOW - 700); put(f.local(RUN), "{\"saveVersion\":3}", NOW - 100); f.marker();
            check(f.action(f.sync("after-exit"), RUN).equals("content conflict"), "concurrent change overwrote");
            check(get(f.cloud(RUN)).equals(NEW), "cloud overwritten");
        });
        for (boolean mirrorExists : new boolean[] {false, true}) {
            test("deleted cloud entry isolated " + mirrorExists, () -> {
                Fixture f = new Fixture();
                if (mirrorExists) f.remote(META, OLD, NOW - 1000);
                f.entry(META, sha(OLD), NOW - 1000, "2"); f.remote(RUN, NEW, NOW - 1000);
                JSONObject result = f.sync("before-start");
                check(f.action(result, META).startsWith("skipped deleted/absent"), "deleted entry not skipped");
                check(get(f.local(RUN)).equals(NEW), "deleted entry aborted other files");
            });
        }
        test("no marker blocks uploads", () -> {
            Fixture f = new Fixture(); f.baseline(); put(f.local(RUN), NEW, NOW - 100);
            check(f.action(f.sync("after-exit"), RUN).equals("upload disabled"), "marker bypass");
            check(get(f.cloud(RUN)).equals(OLD), "unapproved upload");
        });
        test("before-start never uploads with marker", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); put(f.local(RUN), NEW, NOW - 100);
            check(f.action(f.sync("before-start"), RUN).equals("upload disabled"), "startup upload");
        });
        for (boolean newFile : new boolean[] {false, true}) {
            test("upload acknowledgement then local change uploads again " + newFile, () -> {
                Fixture f = new Fixture();
                if (newFile) f.remote(META, OLD, NOW - 1000); else f.baseline();
                f.marker(); put(f.local(RUN), NEW, NOW - 100);
                check(f.action(f.sync("after-exit"), RUN).equals("upload"), "first upload");
                JSONObject previous = new JSONObject(get(new File(f.host, "autocloud/2742830-state.json")))
                    .getJSONObject("files").getJSONObject(RUN);
                check(previous.getString("cloud_sha").equals(sha(NEW)), "expected cloud hash is stale");
                check(f.action(f.sync("before-start"), RUN).startsWith("blocked;"), "unacknowledged mirror accepted");
                f.change = "13"; f.entry(RUN, sha(NEW), NOW - 100, "0");
                String next = "{\"saveVersion\":3}"; put(f.local(RUN), next, NOW - 10);
                check(f.action(f.sync("after-exit"), RUN).equals("upload"), "second upload falsely conflicted");
                check(get(f.cloud(RUN)).equals(next), "second upload bytes");
            });
        }
        for (boolean localChanged : new boolean[] {false, true}) {
            test("different cloud revision after staging " + localChanged, () -> {
                Fixture f = new Fixture(); f.baseline(); f.marker(); put(f.local(RUN), NEW, NOW - 100);
                f.sync("after-exit"); String pc = "{\"saveVersion\":4}"; f.remote(RUN, pc, NOW - 50);
                if (localChanged) put(f.local(RUN), "{\"saveVersion\":3}", NOW - 10);
                check(f.action(f.sync("after-exit"), RUN).equals(localChanged ? "content conflict" : "download"),
                    "real cloud change ignored");
                check(get(f.cloud(RUN)).equals(pc), "PC change overwritten");
            });
        }
        test("validated upload retains loser", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); put(f.local(RUN), NEW, NOW - 100);
            JSONObject result = f.sync("after-exit");
            check(f.action(result, RUN).equals("upload") && get(f.cloud(RUN)).equals(NEW), "valid upload failed");
            check(new File(f.local, "saves").listFiles((dir, name) -> name.contains(".conflict-")).length == 1, "cloud loser missing");
        });
        test("relaunch suppresses sync and release under lock", () -> {
            File host = Files.createTempDirectory("mt2-relaunch-").toFile();
            AtomicBoolean live = new AtomicBoolean(); AtomicInteger calls = new AtomicInteger();
            ExecutorService executor = Executors.newSingleThreadExecutor();
            CountDownLatch attempting = new CountDownLatch(1);
            try {
                Future<?>[] watcher = new Future<?>[1];
                PortAutoCloud.withLifecycleLock(host, 2742830, () -> {
                    watcher[0] = executor.submit(() -> {
                        attempting.countDown();
                        try { PortAutoCloud.afterExit(host, 2742830, live::get, calls::incrementAndGet, calls::incrementAndGet); }
                        catch (Exception e) { throw new RuntimeException(e); }
                    });
                    check(attempting.await(2, TimeUnit.SECONDS), "watcher not started");
                    check(calls.get() == 0, "overlapping lifecycle passes");
                    live.set(true); return null;
                });
                watcher[0].get(3, TimeUnit.SECONDS);
                check(calls.get() == 0, "live relaunch was synced/released");
            } finally { executor.shutdownNow(); }
        });
        test("relaunch during sync suppresses release", () -> {
            File host = Files.createTempDirectory("mt2-release-").toFile();
            AtomicBoolean live = new AtomicBoolean(); AtomicInteger releases = new AtomicInteger();
            PortAutoCloud.afterExit(host, 2742830, live::get, () -> { live.set(true); return null; }, releases::incrementAndGet);
            check(releases.get() == 0, "released live session");
        });
        test("cross-process lifecycle lock", () -> {
            File host = Files.createTempDirectory("mt2-lock-").toFile();
            Process[] worker = new Process[1];
            PortAutoCloud.withLifecycleLock(host, 2742830, () -> {
                String java = new File(System.getProperty("java.home"), "bin/java.exe").getPath();
                worker[0] = new ProcessBuilder(java, "-cp", System.getProperty("java.class.path"),
                    PortAutoCloudTest.class.getName(), "lock-worker", host.getPath()).inheritIO().start();
                long deadline = System.currentTimeMillis() + 5000;
                while (!new File(host, "worker-ready").isFile() && System.currentTimeMillis() < deadline) Thread.sleep(10);
                check(new File(host, "worker-ready").isFile(), "child not ready");
                check(!new File(host, "worker-acquired").exists(), "cross-process lock overlapped");
                return null;
            });
            check(worker[0].waitFor(5, TimeUnit.SECONDS) && worker[0].exitValue() == 0, "child lock failed");
            check(new File(host, "worker-acquired").isFile(), "child never acquired lock");
        });
        test("new local file can upload", () -> {
            Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000); f.marker(); put(f.local(RUN), NEW, NOW - 100);
            check(f.action(f.sync("after-exit"), RUN).equals("upload"), "new local upload blocked");
            check(get(f.cloud(RUN)).equals(NEW), "new local not staged");
        });
        test("invalid new local file cannot upload", () -> {
            Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000); f.marker(); put(f.local(RUN), "{", NOW - 100);
            check(f.action(f.sync("after-exit"), RUN).startsWith("blocked;"), "invalid new local allowed");
            check(!f.cloud(RUN).exists(), "invalid new local staged");
        });
        test("untracked mirror bytes are retained", () -> {
            Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000); f.marker();
            put(f.local(RUN), NEW, NOW - 100); put(f.cloud(RUN), OLD, NOW - 1000);
            check(f.action(f.sync("after-exit"), RUN).startsWith("blocked; untracked"), "untracked mirror overwritten");
            check(get(f.cloud(RUN)).equals(OLD), "untracked mirror lost");
        });
        test("initial download retains local loser", () -> {
            Fixture f = new Fixture(); f.remote(RUN, NEW, NOW - 100); put(f.local(RUN), OLD, NOW - 1000);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "newer cloud download failed");
            File[] losers = new File(f.local, "saves").listFiles((dir, name) -> name.contains(".conflict-"));
            check(losers.length == 1 && get(losers[0]).equals(OLD), "local loser not preserved");
        });
        test("missing non-tombstone entry is isolated", () -> {
            Fixture f = new Fixture(); f.entry(META, sha(OLD), NOW - 1000, "0"); f.remote(RUN, NEW, NOW - 1000);
            JSONObject result = f.sync("before-start");
            check(f.action(result, META).equals("blocked; cloud not materialized"), "missing live cloud not blocked");
            check(!result.getBoolean("start_allowed") && !result.getBoolean("ok"), "startup danger not reported");
            check(get(f.local(RUN)).equals(NEW), "missing entry aborted other files");
        });
        test("startup cannot stage deletion", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); Files.delete(f.local(RUN).toPath());
            check(f.action(f.sync("before-start"), RUN).startsWith("local deletion"), "startup deletion staged");
            check(get(f.cloud(RUN)).equals(OLD), "startup removed cloud file");
        });
        test("idle exit reconciles then releases", () -> {
            File host = Files.createTempDirectory("mt2-idle-").toFile(); List<String> calls = new ArrayList<>();
            PortAutoCloud.afterExit(host, 2742830, () -> false,
                () -> { calls.add("sync"); return null; }, () -> { calls.add("release"); return null; });
            check(calls.equals(Arrays.asList("sync", "release")), "idle exit order");
        });
        test("downloaded run deletion survives next pass", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); f.sync("before-start");
            Files.delete(f.local(RUN).toPath()); f.sync("before-start");
            check(!f.local(RUN).exists(), "downloaded run resurrected");
        });
        test("invalid observed save deletion stays local", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); f.marker(); put(f.local(RUN), "{", NOW - 100);
            f.sync("after-exit"); Files.delete(f.local(RUN).toPath()); f.sync("after-exit");
            check(!f.local(RUN).exists() && get(f.cloud(RUN)).equals(OLD), "invalid observed save caused resurrection/deletion");
        });
        test("history failure prevents first download", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000);
            check(new File(f.host, "autocloud/2742830-state.json").mkdirs(), "create history failure");
            check(f.action(f.sync("before-start"), RUN).startsWith("blocked;"), "history failure allowed mutation");
            check(!f.local(RUN).exists(), "downloaded without durable history");
        });
        test("proc listing null still syncs and releases after bounded uncertainty", () -> {
            LivenessFixture f = new LivenessFixture(); AtomicInteger calls = new AtomicInteger();
            android.util.Log.warnings.clear();
            check(f.proc.listFiles() == null, "proc null fixture");
            f.procListings.set(0);
            PortAutoCloud.afterExit(f.host, 2742830, f::live, calls::incrementAndGet, calls::incrementAndGet);
            check(calls.get() == 0, "uncertain process skipped grace");
            f.elapsed.addAndGet(PortProcessLiveness.UNKNOWN_TIMEOUT_MS - 1);
            check(f.live(), "uncertainty expired early");
            f.elapsed.incrementAndGet();
            PortAutoCloud.afterExit(f.host, 2742830, f::live, calls::incrementAndGet, calls::incrementAndGet);
            check(calls.get() == 2 && !f.live(), "unknown PID blocked exit forever");
            check(f.procListings.get() == 0, "production enumerated procfs");
            check(android.util.Log.warnings.stream().filter(message -> message.contains("liveness timeout")).count() == 1,
                "timeout not logged exactly once");
        });
        test("registered start time keeps live port protected", () -> {
            LivenessFixture f = new LivenessFixture(); f.stat(456); f.timeout();
            check(f.live(), "live registered process missed");
        });
        test("PID reuse does not protect exited registration", () -> {
            LivenessFixture f = new LivenessFixture(); f.stat(789);
            check(!f.live(), "reused PID treated as original port");
        });
        test("registered PID exists with unreadable stat", () -> {
            LivenessFixture f = new LivenessFixture(); new File(f.proc, "123").mkdirs();
            check(f.live(), "visible registered PID missed"); f.timeout();
            check(f.live(), "positive PID evidence timed out");
        });
        test("ActivityManager sees registered PID without proc visibility", () -> {
            LivenessFixture f = new LivenessFixture(); f.visible(123, "native-port", android.os.Process.myUid());
            check(f.live(), "ActivityManager registered PID missed"); f.timeout();
            check(f.live(), "ActivityManager evidence timed out");
        });
        test("ActivityManager sees pre-registration relaunch", () -> {
            LivenessFixture f = new LivenessFixture(); f.timeout();
            f.visible(999, "com.game.monstertrain2:unity", android.os.Process.myUid());
            AtomicInteger calls = new AtomicInteger();
            PortAutoCloud.afterExit(f.host, 2742830, f::live, calls::incrementAndGet, calls::incrementAndGet);
            check(calls.get() == 0, "pre-registration relaunch synced/released");
        });
        test("ActivityManager evidence resets uncertainty grace", () -> {
            LivenessFixture f = new LivenessFixture(); check(f.live(), "initial grace"); f.timeout();
            check(!f.live(), "initial timeout");
            f.visible(123, "com.game.monstertrain2", android.os.Process.myUid()); check(f.live(), "relaunch");
            f.processes.set(null); check(f.live(), "relaunch did not reset grace");
            f.timeout(); check(!f.live(), "second timeout");
        });
        test("other UID ActivityManager entry cannot block reaping", () -> {
            LivenessFixture f = new LivenessFixture(); f.visible(123, "com.game.monstertrain2", 99999);
            check(f.live(), "initial unknown grace"); f.timeout();
            check(!f.live(), "unrelated UID blocked reaping");
        });
        test("ActivityManager failure has bounded fallback", () -> {
            LivenessFixture f = new LivenessFixture();
            PortProcessLiveness liveness = new PortProcessLiveness(f.registrations, f.proc,
                () -> { throw new SecurityException("denied"); }, f.elapsed::get);
            check(liveness.hasLiveProcess("2742830", "com.game.monstertrain2"), "initial failure grace");
            f.timeout();
            check(!liveness.hasLiveProcess("2742830", "com.game.monstertrain2"), "failure blocked forever");
        });
        test("registration listing failure has bounded fallback", () -> {
            LivenessFixture f = new LivenessFixture();
            File denied = new File(f.host, "denied") { @Override public File[] listFiles() { return null; } };
            PortProcessLiveness liveness = new PortProcessLiveness(denied, f.proc, () -> null, f.elapsed::get);
            check(liveness.hasLiveProcess("2742830", "com.game.monstertrain2"), "initial directory grace");
            f.timeout();
            check(!liveness.hasLiveProcess("2742830", "com.game.monstertrain2"), "directory failure blocked forever");
        });
        test("Android JSON null semantics are active", () -> {
            JSONObject object = new JSONObject().put("value", JSONObject.NULL);
            check(object.optString("value", "fallback").equals("null"), "tests are not using Android org.json");
        });
        test("legacy Android null tombstone retries exact deleted run", () -> {
            Fixture f = new Fixture(); f.remote(RUN, finished, NOW - 1000); f.marker();
            put(f.local("run-history/RunHistory.json"), completedHistory, NOW - 100);
            JSONObject previous = new JSONObject().put("local_sha", JSONObject.NULL).put("cloud_sha", JSONObject.NULL)
                .put("deleted_cloud_sha", sha(finished));
            put(new File(f.host, "autocloud/2742830-state.json"), new JSONObject().put("account", "123")
                .put("files", new JSONObject().put(RUN, previous)).toString(), NOW);
            check(f.action(f.sync("after-exit"), RUN).equals("completed run cloud deletion staged"), "legacy null fallback lost deleted hash");
            check(!f.cloud(RUN).exists(), "deleted run survived retry");
        });
        for (boolean reconciled : new boolean[] {false, true}) {
            test("live missing metagame cannot upload fresh save " + reconciled, () -> {
                Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000);
                if (reconciled) { put(f.local(META), OLD, NOW - 1000); f.sync("before-start"); }
                Files.delete(f.cloud(META).toPath()); f.marker();
                JSONObject startup = f.sync("before-start");
                check(!startup.getBoolean("start_allowed"), "launcher not warned");
                put(f.local(META), "{}", NOW - 10);
                check(f.action(f.sync("after-exit"), META).equals("blocked; cloud not materialized"), "fresh save upload allowed");
                check(!f.cloud(META).exists() && get(f.local(META)).equals("{}"), "missing cloud was overwritten");
            });
            test("tombstone mirror never downloads over local " + reconciled, () -> {
                Fixture f = new Fixture(); f.remote(META, OLD, NOW - 1000); put(f.local(META), OLD, NOW - 1000);
                if (reconciled) f.sync("before-start");
                f.remote(META, NEW, NOW - 100); f.entry(META, sha(NEW), NOW - 100, "2");
                String action = f.action(f.sync("before-start"), META);
                check(!action.equals("download") && get(f.local(META)).equals(OLD), "deleted mirror was treated as live");
            });
        }
        test("unchanged local and unexplained remote deletion conflict", () -> {
            Fixture f = new Fixture(); f.baseline(); f.remote(META, OLD, NOW - 1000);
            Files.delete(f.cloud(RUN).toPath()); f.entries.remove(RUN); f.inventory();
            check(f.action(f.sync("before-start"), RUN).equals("content conflict"), "null download silently ignored");
            check(get(f.local(RUN)).equals(OLD), "local lost on deletion conflict");
        });
        for (boolean newerQuest : new boolean[] {true, false}) {
            test("unreconciled three day gap " + newerQuest, () -> {
                Fixture f = new Fixture(); f.marker();
                f.remote(META, OLD, NOW - (newerQuest ? 3 * 86400 + 10 : 10));
                put(f.local(META), NEW, NOW - (newerQuest ? 10 : 3 * 86400 + 10));
                check(f.action(f.sync("after-exit"), META).equals(newerQuest ? "upload" : "download"), "session gap treated as skew");
            });
        }
        test("after-exit transient failure retains registration until successful retry", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); put(f.local(RUN), NEW, NOW - 10);
            File registration = new File(f.host, "port-processes/123"); put(registration, "2742830 456", NOW);
            AtomicInteger releases = new AtomicInteger();
            PortAutoCloud.LockedTask<Object> release = () -> { releases.incrementAndGet(); Files.delete(registration.toPath()); return null; };
            put(new File(f.host, "status.json"), "{", NOW);
            PortAutoCloud.afterExit(f.host, 2742830, () -> false, () -> PortAutoCloud.syncLocked(f.host, 2742830, f.local, "after-exit"), release);
            check(registration.exists() && releases.get() == 0, "failed sync released registration");
            PortAutoCloud.writeStatusSnapshot(new File(f.host, "status.json"), "{\"logged_on\":true,\"steam_login_state\":\"Logged On\"}");
            PortAutoCloud.afterExit(f.host, 2742830, () -> false, () -> PortAutoCloud.syncLocked(f.host, 2742830, f.local, "after-exit"), release);
            check(!registration.exists() && releases.get() == 1 && get(f.cloud(RUN)).equals(NEW), "successful retry did not upload and release");
        });
        test("blocked file retries are bounded", () -> {
            File host = Files.createTempDirectory("mt2-exit-retry-").toFile(); AtomicInteger releases = new AtomicInteger();
            JSONObject blocked = new JSONObject().put("ok", true).put("files", new JSONArray()
                .put(new JSONObject().put("action", "blocked; Save is being written; retry on next pass")));
            for (int i = 1; i <= PortAutoCloud.MAX_EXIT_ATTEMPTS; i++) {
                PortAutoCloud.afterExit(host, 2742830, () -> false, () -> blocked, releases::incrementAndGet);
                check(releases.get() == (i == PortAutoCloud.MAX_EXIT_ATTEMPTS ? 1 : 0), "wrong retry bound");
            }
            check(!new File(host, "autocloud/2742830-exit-retries").exists(), "retry counter not cleared");
        });
        test("atomic status readers always see complete JSON", () -> {
            File target = new File(Files.createTempDirectory("mt2-status-").toFile(), "status.json");
            PortAutoCloud.writeStatusSnapshot(target, "{\"generation\":0}");
            AtomicBoolean done = new AtomicBoolean(); AtomicReference<Throwable> error = new AtomicReference<>();
            Thread reader = new Thread(() -> {
                try { while (!done.get()) new JSONObject(get(target)).getInt("generation"); }
                catch (Throwable e) { error.set(e); }
            });
            reader.start();
            try { for (int i = 1; i <= 50; i++) PortAutoCloud.writeStatusSnapshot(target, "{\"generation\":" + i + "}"); }
            finally { done.set(true); reader.join(); }
            check(error.get() == null, "reader observed partial status: " + error.get());
            check(new JSONObject(get(target)).getInt("generation") == 50, "last status missing");
        });
        System.out.println("AutoCloud tests passed=" + passed + " failed=" + failed);
        if (failed > 0) System.exit(1);
    }
}
