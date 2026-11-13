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
            put(cache, "\"2742830\" {\n\"ChangeNumber\" \"12\"\n" + String.join("", entries.values()) + "}\n", NOW);
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
        test("marker permits revision-checked deletion", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); Files.delete(f.local(RUN).toPath());
            check(f.action(f.sync("after-exit"), RUN).equals("staged local deletion"), "deletion not staged");
            check(!f.cloud(RUN).exists() && !f.local(RUN).exists(), "deletion");
            check(new File(f.local, "saves").listFiles((dir, name) -> name.contains(".conflict-")).length == 1, "deleted cloud loser missing");
        });
        test("changed cloud revision blocks deletion", () -> {
            Fixture f = new Fixture(); f.baseline(); f.marker(); Files.delete(f.local(RUN).toPath());
            f.remote(RUN, NEW, NOW - 500);
            check(f.action(f.sync("after-exit"), RUN).startsWith("local deletion"), "unsafe deletion staged");
            check(get(f.cloud(RUN)).equals(NEW) && !f.local(RUN).exists(), "changed cloud lost or resurrected");
        });
        test("observed unsynced file deletion", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); put(f.local(RUN), NEW, NOW - 100);
            f.sync("before-start"); Files.delete(f.local(RUN).toPath()); f.marker(); f.sync("after-exit");
            check(!f.local(RUN).exists() && get(f.cloud(RUN)).equals(OLD), "unsynced deletion changed cloud");
        });
        test("new cloud file downloads", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000);
            check(f.action(f.sync("before-start"), RUN).equals("download"), "new cloud not downloaded");
            check(get(f.local(RUN)).equals(OLD), "wrong download");
        });
        test("clock skew refuses time winner", () -> {
            Fixture f = new Fixture(); f.remote(RUN, OLD, NOW - 1000); put(f.local(RUN), NEW, NOW - 200000); f.marker();
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
            check(f.action(result, META).startsWith("skipped deleted/absent"), "missing file not skipped");
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
        System.out.println("AutoCloud tests passed=" + passed + " failed=" + failed);
        if (failed > 0) System.exit(1);
    }
}
