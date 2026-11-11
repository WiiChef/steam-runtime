# steamclient_patches.conf

The shim (`client/`) and test app (`examples/steamtest/`) read runtime patches for the locally supplied Steam
client library from a **private** file. This repo ships no values for it. Create the file yourself for the exact
library build you use, and never commit it (it is git-ignored).

Search order: `$STEAM_PATCH_CONF`, `/data/user/0/com.steamruntime.dev/files/steamclient_patches.conf`,
`/data/local/tmp/steamclient_patches.conf`.

Format: one entry per line, `#` starts a comment, numbers are hex, offsets are relative to the module base.

```
u8  <offset> <value>      write one byte
u32 <offset> <value>      write one 32-bit word (code page made writable, icache flushed)
ptr <offset>              write a pointer to the shim's install-path string
fn  <name> <offset>       named function offset (test app service start; see below)
client_build=<id>         optional: the Steam client build these patches were made for (build-ID guard)
```

Names the test app looks up with `fn`: `get_ipc_server`, `start_ipc_server`, `init_interfaces`, `start_thread`,
`get_engine`, `connect_global_user`, `associate_user_pipe`.

## Build-ID guard (`client_build=`)

Patch offsets are only valid for one client build. The host publishes the running client's identity in
`files/status.json` as `client_build` (the numeric `version` from the client's `package/steam_client_*.manifest`,
else the `builddate.txt` text; `client_build_source` says which). Set `client_build=` to that value, for example
the value shown by `am broadcast -a com.steamruntime.dev.CMD --es cmd status` followed by reading `status.json`.

Before patching and in `SteamAPI_Init`, the shim compares the two:

- **Mismatch**: nothing is patched, the shim does not attach, logcat tag `StS2Shim` logs
  `Steam client build mismatch: running client is X but steamclient_patches.conf is for Y`, and `SteamAPI_Init`
  returns failure with that text as the error message (no crash). It is re-checked on each init, so fixing the conf
  or the client and retrying works without restarting the process.
- **Key missing in the conf, or no `client_build` in `status.json`** (old host, unreadable file): old behaviour
  (patches applied) plus a logcat warning.

## Login state

`status.json` also carries `logged_on` (`true`/`false`/`null` = unknown), `account_present`, `owned_apps` and
`login_probe` from the host's login probe (see `host/README.md`). If `SteamAPI_Init` fails while `logged_on` is
`false`, the shim logs and returns `Steam is not logged in: log in to Steam in the Steam Runtime app, ...`.

If the file is missing or empty the shim loads and forwards calls but applies no patches, so it will not attach
to the host.
