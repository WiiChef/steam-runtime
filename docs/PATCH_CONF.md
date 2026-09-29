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
```

Names the test app looks up with `fn`: `get_ipc_server`, `start_ipc_server`, `init_interfaces`, `start_thread`,
`get_engine`, `connect_global_user`, `associate_user_pipe`.

If the file is missing or empty the shim loads and forwards calls but applies no patches, so it will not attach
to the host.
