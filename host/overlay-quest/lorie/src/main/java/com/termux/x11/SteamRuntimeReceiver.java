package com.termux.x11;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.util.Log;

public class SteamRuntimeReceiver extends BroadcastReceiver {
    private static final String TAG = "SteamRuntimeReceiver";

    @Override
    public void onReceive(Context context, Intent intent) {
        String cmd = intent != null ? intent.getStringExtra("cmd") : null;
        if (cmd == null) {
            Log.w(TAG, "Received broadcast without 'cmd' extra");
            return;
        }
        Log.i(TAG, "Received CMD broadcast: " + cmd);

        if ("status".equalsIgnoreCase(cmd)) {
            SteamRuntimeService.writeStatus(context, SteamRuntimeService.getInstance());
        } else if ("start".equalsIgnoreCase(cmd)) {
            Intent serviceIntent = new Intent(context, SteamRuntimeService.class);
            serviceIntent.setAction("START");
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                context.startForegroundService(serviceIntent);
            } else {
                context.startService(serviceIntent);
            }
        } else if ("stop".equalsIgnoreCase(cmd)) {
            Intent serviceIntent = new Intent(context, SteamRuntimeService.class);
            serviceIntent.setAction("STOP");
            context.startService(serviceIntent);
        } else {
            Log.w(TAG, "Unknown CMD: " + cmd);
        }
    }
}
