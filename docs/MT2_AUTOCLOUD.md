# Quest port Auto-Cloud bridge

Monster Train 2 (2742830) is registered alongside StS2. Shared UID and matching signing are required.
`PortAutoCloud.java` is shared with the port APK. The port invokes it before Unity starts; the service invokes it after registered process death, before releasing the Steam app session.

Steam itself downloads/uploads Auto-Cloud through its existing logged-in session. The bridge maps root 12 (WinAppDataLocalLow) to the Quest external files directory, using the Proton-prefix save tree Steam actually downloads. It verifies every downloaded SHA1 against `remotecache.vdf` before changes. It never reads login files or handles credentials.

Default mode is download-only, with reports under runtime `files/autocloud/2742830-before-start.json` and `2742830-after-exit.json`. Older local saves are preserved with `.conflict-<UTC timestamp>-<hash>` before downloading. Newer Quest saves are reported as would-upload. Equal-time divergent saves keep both and block upload. `preferences-local.json` is local-only according to the actual Steam rules.

After reviewing the first report, create runtime `files/autocloud/2742830.allow-uploads` to permit staging at process exit. Each staged file must be newer than its cloud metadata; unchanged files are skipped. Cloud losers are retained on Quest. The Steam client performs the network upload on app-session exit; staging alone is not proof of an upload. Verify `cloud_log.txt` and refreshed cache hashes. Remove the marker to disable staging.

Logged-off state produces a read-only report of cached timestamps and blocks changes. Missing, ambiguous, changing or hash-mismatched cloud inventory blocks writes. Empty RemoteStorage enumeration is not proof of an empty Auto-Cloud account. There is no cloud deletion propagation.

## Quest verification (2026-11-12)
Game SteamAPI_Init returned 0, the game queried the logged-in SteamID, and runtime port_games identified AppID 2742830. Steam downloaded Auto-Cloud ChangeNumber 12. The first bridge pass compared nine saves: five identical, one newer backup downloaded with conflict preservation, two newer Quest files would upload, one local-only preference. Uploads remain disabled because Steam reports the account playing elsewhere. Game hub verified; battle unverified. The temporary test save was rolled back with all 42 files SHA256-verified, and the restored active run matches the original import. Both APKs compile and were updated in place after the one authorized UID migration.
