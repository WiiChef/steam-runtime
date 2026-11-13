package com.termux.x11;

import android.content.Context;
import android.util.Log;
import java.io.*;
import java.nio.file.*;
import java.security.MessageDigest;
import java.util.*;
import java.util.regex.*;
import org.json.*;

/** Reconciles a port with Steam's downloaded Auto-Cloud tree, never a Web API/token.
 * Steam owns network synchronization. Upload staging is opt-in after a download-only report.
 */
public final class PortAutoCloud {
    private static final File HOST = new File("/data/user/0/com.steamruntime.dev/files");
    private static final String PREFIX = "Shiny Shoe/MonsterTrain2/";
    private static final Pattern BLOCK = Pattern.compile("\"([^\"]+)\"\\s*\\{([^{}]*)\\}");
    private static final Pattern FIELD = Pattern.compile("\"([^\"]+)\"\\s*\"([^\"]*)\"");
    private static String read(File f) throws IOException { return new String(Files.readAllBytes(f.toPath()), java.nio.charset.StandardCharsets.UTF_8); }
    private static String hash(File f, String algorithm) throws Exception {
        MessageDigest d = MessageDigest.getInstance(algorithm);
        try(InputStream in = new FileInputStream(f)) { byte[] b = new byte[65536]; int n; while((n=in.read(b))!=-1)d.update(b,0,n); }
        StringBuilder out = new StringBuilder(); for(byte b:d.digest())out.append(String.format(Locale.ROOT,"%02x",b&255)); return out.toString();
    }
    private static File safe(File root,String relative) throws IOException {
        File f = new File(root, relative);
        if(!f.getCanonicalPath().startsWith(root.getCanonicalPath()+File.separator))throw new IOException("Unsafe cloud path"); return f;
    }
    private static void copy(File source,File target,long timestamp) throws IOException {
        target.getParentFile().mkdirs(); File tmp=new File(target.getPath()+".steam-sync-tmp-"+UUID.randomUUID());
        try {
            Files.copy(source.toPath(),tmp.toPath());
            if(!tmp.setLastModified(timestamp*1000L))throw new IOException("Cannot preserve save timestamp");
            try { Files.move(tmp.toPath(),target.toPath(),StandardCopyOption.ATOMIC_MOVE,StandardCopyOption.REPLACE_EXISTING); }
            catch(AtomicMoveNotSupportedException e){ Files.move(tmp.toPath(),target.toPath(),StandardCopyOption.REPLACE_EXISTING); }
        } finally { tmp.delete(); }
    }
    private static String conflict(File loser,File root,String relative,long timestamp) throws Exception {
        String suffix=new java.text.SimpleDateFormat("yyyyMMdd'T'HHmmss'Z'",Locale.ROOT) {{ setTimeZone(TimeZone.getTimeZone("UTC")); }}.format(new Date(timestamp*1000L));
        File saved=safe(root,relative+".conflict-"+suffix+"-"+hash(loser,"SHA-256").substring(0,12));
        if(!saved.exists())copy(loser,saved,timestamp);
        Log.i("PortAutoCloud","Conflict preserved: "+saved.getName());return saved.getName();
    }
    private static boolean eligible(String name) {
        String n=name.replaceFirst("^(development-save|staging-save)/", "");
        return n.equals("metagameSave.json")||n.equals("metagameSave.json.backup")||n.equals("preferences.json")||n.equals("preferences-local.json")||
            (n.startsWith("saves/")&&n.endsWith(".json"))||(n.startsWith("run-history/")&&n.endsWith(".json"));
    }
    private static void collect(File root,File dir,Set<String> names) {
        File[] files=dir.listFiles();if(files==null)return;
        for(File f:files) { if(f.isDirectory())collect(root,f,names); else { String n=root.toPath().relativize(f.toPath()).toString().replace(File.separatorChar,'/');if(eligible(n))names.add(n); } }
    }
    public static synchronized JSONObject sync(Context context,int appid,File quest,String phase) {
        JSONObject report=new JSONObject();JSONArray rows=new JSONArray();
        try {
            report.put("appid",appid).put("phase",phase).put("created",System.currentTimeMillis()/1000L).put("files",rows);
            if(appid!=2742830)throw new IOException("No cloud mapping for this AppID");
            JSONObject status=new JSONObject(read(new File(HOST,"status.json")));
            boolean online=status.optBoolean("logged_on",false) && "Logged On".equals(status.optString("steam_login_state")); report.put("cloud_online",online);
            File steam=new File(HOST,"rootfs/debian-trixie-aarch64/root/steamrtarm64");
            File[] users=new File(steam,"userdata").listFiles();File cache=null;
            if(users!=null)for(File user:users) { File candidate=new File(user,appid+"/remotecache.vdf");if(candidate.isFile()){if(cache!=null)throw new IOException("Ambiguous cloud account");cache=candidate;} }
            if(cache==null)throw new IOException("No downloaded Auto-Cloud inventory; refusing writes");
            String snapshot=read(cache);
            // Root 12 is WinAppDataLocalLow, as recorded in Steam's own downloaded inventory.
            File mirror=new File(steam,"steamapps/compatdata/"+appid+"/pfx/drive_c/users/steamuser/AppData/LocalLow/Shiny Shoe/MonsterTrain2");
            Map<String,Map<String,String>> remote=new TreeMap<>();Matcher blocks=BLOCK.matcher(snapshot);
            while(blocks.find())if(blocks.group(1).startsWith(PREFIX)) {
                Map<String,String> fields=new HashMap<>();Matcher pairs=FIELD.matcher(blocks.group(2));while(pairs.find())fields.put(pairs.group(1),pairs.group(2));
                if(!"12".equals(fields.get("root")))throw new IOException("Unexpected Auto-Cloud root");
                String name=blocks.group(1).substring(PREFIX.length());if(eligible(name))remote.put(name,fields);
            }
            if(remote.isEmpty())throw new IOException("Empty cloud inventory is not proof of an empty cloud");
            boolean upload=phase.equals("after-exit") && new File(HOST,"autocloud/"+appid+".allow-uploads").isFile();report.put("uploads_enabled",upload);
            Set<String> names=new TreeSet<>(remote.keySet());collect(quest,quest,names);
            // Validate the entire downloaded snapshot before any mutation.
            for(String name:remote.keySet()) { Map<String,String> meta=remote.get(name);File cloud=safe(mirror,name);
                if(!cloud.isFile()||!hash(cloud,"SHA-1").equalsIgnoreCase(meta.get("sha")))throw new IOException("Cloud cache hash mismatch: "+name);
            }
            if(!read(cache).equals(snapshot))throw new IOException("Cloud inventory changed during validation");
            for(String name:names) {
                File local=safe(quest,name), cloud=safe(mirror,name);Map<String,String> meta=remote.get(name);
                long qt=local.isFile()?local.lastModified()/1000L:0, ct=meta==null?0:Long.parseLong(meta.get("remotetime"));
                JSONObject row=new JSONObject().put("file",name).put("quest_time",qt).put("cloud_time",meta==null?JSONObject.NULL:ct);rows.put(row);
                if(name.endsWith("preferences-local.json")) { row.put("action","local-only; excluded by Steam Auto-Cloud rules"); continue; }
                if(!online) { row.put("action","blocked; logged off, cloud freshness unknown"); continue; }
                boolean same=meta!=null&&local.isFile()&&hash(local,"SHA-1").equalsIgnoreCase(meta.get("sha"));
                if(same)row.put("action","identical");
                else if(meta!=null&&(!local.isFile()||ct>qt)) {
                    if(local.isFile())row.put("conflict",conflict(local,quest,name,qt));
                    copy(cloud,local,ct);row.put("action","downloaded newer cloud");
                } else if(meta!=null&&qt==ct) {
                    row.put("conflict",conflict(cloud,quest,name,ct)).put("action","equal-time conflict; upload blocked");
                } else {
                    row.put("action",upload?"staged safe upload":"would upload newer Quest (disabled)");
                    if(meta!=null)row.put("conflict",conflict(cloud,quest,name,ct));
                    if(upload) {
                        if(!read(cache).equals(snapshot))throw new IOException("Cloud inventory changed before upload staging");
                        if(meta!=null&&qt<ct)throw new IOException("Older upload blocked");
                        copy(local,cloud,qt);
                    }
                }
            }
            report.put("ok",online); if(!online)report.put("error","Steam logged off; cached timestamps only, no writes");
        } catch(Exception e) { try{report.put("ok",false).put("error",e.getMessage());}catch(JSONException ignored){} Log.w("PortAutoCloud","Sync blocked: "+e.getMessage()); }
        try { File reports=new File(HOST,"autocloud");reports.mkdirs();Files.write(new File(reports,appid+"-"+phase+".json").toPath(),report.toString(2).getBytes(java.nio.charset.StandardCharsets.UTF_8)); }
        catch(Exception e){Log.w("PortAutoCloud","Cannot write sync report");}
        return report;
    }
}
