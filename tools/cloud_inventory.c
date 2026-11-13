/* Read-only cloud inventory through the logged-in companion client. No credentials or uploads. */
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FN(type,name) type name = (type)dlsym(h,#name)
typedef int (*init_t)(const char*,char*);
typedef void* (*iface_t)(void);
typedef int (*count_t)(void*);
typedef const char* (*name_t)(void*,int,int*);
typedef int64_t (*time_t_fn)(void*,const char*);
int main(int argc,char **argv) {
 if(argc!=2)return 2;
 void*h=dlopen(argv[1],RTLD_NOW|RTLD_GLOBAL);if(!h){fprintf(stderr,"shim load failed: %s\n",dlerror());return 3;}
 FN(init_t,SteamInternal_SteamAPI_Init);FN(iface_t,SteamAPI_SteamRemoteStorage_v016);
 FN(count_t,SteamAPI_ISteamRemoteStorage_GetFileCount);FN(name_t,SteamAPI_ISteamRemoteStorage_GetFileNameAndSize);FN(time_t_fn,SteamAPI_ISteamRemoteStorage_GetFileTimestamp);
 if(!SteamInternal_SteamAPI_Init||!SteamAPI_SteamRemoteStorage_v016||!SteamAPI_ISteamRemoteStorage_GetFileCount||!SteamAPI_ISteamRemoteStorage_GetFileNameAndSize||!SteamAPI_ISteamRemoteStorage_GetFileTimestamp)return 4;
 char err[1024]={0};if(SteamInternal_SteamAPI_Init(NULL,err)){fprintf(stderr,"SteamAPI_Init failed\n");return 5;}
 void*s=SteamAPI_SteamRemoteStorage_v016();if(!s)return 6;
 sleep(10);int n=SteamAPI_ISteamRemoteStorage_GetFileCount(s);printf("files=%d\n",n);
 for(int i=0;i<n;i++){int size=0;const char*name=SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(s,i,&size);if(name)printf("%lld\t%d\t%s\n",(long long)SteamAPI_ISteamRemoteStorage_GetFileTimestamp(s,name),size,name);}
 void(*shutdown_fn)(void)=dlsym(h,"SteamAPI_Shutdown");if(shutdown_fn)shutdown_fn();return 0;
}
