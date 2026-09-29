// Auto-generated ARM64 safe trampolines forwarding to real libsteam_api.so
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>

void *p_SteamAPI_GetHSteamPipe = NULL;
__attribute__((naked)) void SteamAPI_GetHSteamPipe(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_GetHSteamPipe\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_GetHSteamPipe]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_GetHSteamUser = NULL;
__attribute__((naked)) void SteamAPI_GetHSteamUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_GetHSteamUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_GetHSteamUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_GetSteamInstallPath = NULL;
__attribute__((naked)) void SteamAPI_GetSteamInstallPath(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_GetSteamInstallPath\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_GetSteamInstallPath]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BGetDLCDataByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BGetDLCDataByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BGetDLCDataByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BGetDLCDataByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsAppInstalled = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsAppInstalled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsAppInstalled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsAppInstalled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsCybercafe = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsCybercafe(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsCybercafe\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsCybercafe]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsDlcInstalled = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsDlcInstalled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsDlcInstalled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsDlcInstalled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsLowViolence = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsLowViolence(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsLowViolence\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsLowViolence]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsSubscribed = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsSubscribed(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsSubscribed\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsSubscribed]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsSubscribedApp = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsSubscribedApp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsSubscribedApp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsSubscribedApp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsTimedTrial = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsTimedTrial(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsTimedTrial\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsTimedTrial]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_BIsVACBanned = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_BIsVACBanned(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_BIsVACBanned\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_BIsVACBanned]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetAppBuildId = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetAppBuildId(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetAppBuildId\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetAppBuildId]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetAppInstallDir = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetAppInstallDir(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetAppInstallDir\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetAppInstallDir]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetAppOwner = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetAppOwner(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetAppOwner\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetAppOwner]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetAvailableGameLanguages = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetAvailableGameLanguages(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetAvailableGameLanguages\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetAvailableGameLanguages]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetBetaInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetBetaInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetBetaInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetBetaInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetCurrentBetaName = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetCurrentBetaName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetCurrentBetaName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetCurrentBetaName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetCurrentGameLanguage = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetCurrentGameLanguage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetCurrentGameLanguage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetCurrentGameLanguage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetDLCCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetDLCCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetDLCCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetDLCCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetDlcDownloadProgress = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetDlcDownloadProgress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetDlcDownloadProgress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetDlcDownloadProgress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetFileDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetFileDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetFileDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetFileDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetInstalledDepots = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetInstalledDepots(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetInstalledDepots\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetInstalledDepots]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetLaunchCommandLine = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetLaunchCommandLine(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetLaunchCommandLine\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetLaunchCommandLine]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetLaunchQueryParam = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetLaunchQueryParam(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetLaunchQueryParam\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetLaunchQueryParam]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_GetNumBetas = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_GetNumBetas(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_GetNumBetas\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_GetNumBetas]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_InstallDLC = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_InstallDLC(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_InstallDLC\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_InstallDLC]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_MarkContentCorrupt = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_MarkContentCorrupt(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_MarkContentCorrupt\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_MarkContentCorrupt]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_SetActiveBeta = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_SetActiveBeta(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_SetActiveBeta\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_SetActiveBeta]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_SetDlcContext = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_SetDlcContext(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_SetDlcContext\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_SetDlcContext]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamApps_UninstallDLC = NULL;
__attribute__((naked)) void SteamAPI_ISteamApps_UninstallDLC(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamApps_UninstallDLC\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamApps_UninstallDLC]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_BReleaseSteamPipe = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_BReleaseSteamPipe(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_BReleaseSteamPipe\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_BReleaseSteamPipe]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_BShutdownIfAllPipesClosed = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_BShutdownIfAllPipesClosed(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_BShutdownIfAllPipesClosed\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_BShutdownIfAllPipesClosed]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_ConnectToGlobalUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_ConnectToGlobalUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_ConnectToGlobalUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_ConnectToGlobalUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_CreateLocalUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_CreateLocalUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_CreateLocalUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_CreateLocalUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_CreateSteamPipe = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_CreateSteamPipe(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_CreateSteamPipe\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_CreateSteamPipe]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_ReleaseUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_ReleaseUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_ReleaseUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_ReleaseUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_SetLocalIPBinding = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_SetLocalIPBinding(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_SetLocalIPBinding\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_SetLocalIPBinding]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamClient_SetWarningMessageHook = NULL;
__attribute__((naked)) void SteamAPI_ISteamClient_SetWarningMessageHook(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamClient_SetWarningMessageHook\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamClient_SetWarningMessageHook]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlay = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlay(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlay\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlay]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlayToStore = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlayToStore(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlayToStore\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlayToStore]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlayToUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlayToUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlayToUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlayToUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_BHasEquippedProfileItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_BHasEquippedProfileItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_BHasEquippedProfileItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_BHasEquippedProfileItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ClearRichPresence = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ClearRichPresence(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ClearRichPresence\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ClearRichPresence]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_CloseClanChatWindowInSteam = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_CloseClanChatWindowInSteam(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_CloseClanChatWindowInSteam\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_CloseClanChatWindowInSteam]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_DownloadClanActivityCounts = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_DownloadClanActivityCounts(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_DownloadClanActivityCounts\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_DownloadClanActivityCounts]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_EnumerateFollowingList = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_EnumerateFollowingList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_EnumerateFollowingList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_EnumerateFollowingList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetChatMemberByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetChatMemberByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetChatMemberByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetChatMemberByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanActivityCounts = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanActivityCounts(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanActivityCounts\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanActivityCounts]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanChatMemberCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanChatMemberCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanChatMemberCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanChatMemberCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanChatMessage = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanChatMessage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanChatMessage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanChatMessage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanName = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanOfficerByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanOfficerByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanOfficerByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanOfficerByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanOfficerCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanOfficerCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanOfficerCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanOfficerCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanOwner = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanOwner(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanOwner\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanOwner]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetClanTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetClanTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetClanTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetClanTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetCoplayFriend = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetCoplayFriend(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetCoplayFriend\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetCoplayFriend]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetCoplayFriendCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetCoplayFriendCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetCoplayFriendCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetCoplayFriendCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFollowerCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFollowerCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFollowerCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFollowerCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendCoplayGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendCoplayGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendCoplayGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendCoplayGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendCoplayTime = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendCoplayTime(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendCoplayTime\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendCoplayTime]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendCountFromSource = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendCountFromSource(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendCountFromSource\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendCountFromSource]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendFromSourceByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendFromSourceByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendFromSourceByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendFromSourceByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendGamePlayed = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendGamePlayed(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendGamePlayed\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendGamePlayed]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendMessage = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendMessage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendMessage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendMessage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendPersonaName = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendPersonaName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendPersonaName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendPersonaName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendPersonaNameHistory = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendPersonaNameHistory(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendPersonaNameHistory\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendPersonaNameHistory]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendPersonaState = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendPersonaState(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendPersonaState\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendPersonaState]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendRelationship = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendRelationship(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendRelationship\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendRelationship]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendRichPresence = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendRichPresence(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendRichPresence\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendRichPresence]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendSteamLevel = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendSteamLevel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendSteamLevel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendSteamLevel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendsGroupCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendsGroupCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendsGroupCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendsGroupCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendsGroupMembersCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendsGroupMembersCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendsGroupMembersCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendsGroupMembersCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendsGroupMembersList = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendsGroupMembersList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendsGroupMembersList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendsGroupMembersList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetFriendsGroupName = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetFriendsGroupName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetFriendsGroupName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetFriendsGroupName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetLargeFriendAvatar = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetLargeFriendAvatar(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetLargeFriendAvatar\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetLargeFriendAvatar]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetMediumFriendAvatar = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetMediumFriendAvatar(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetMediumFriendAvatar\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetMediumFriendAvatar]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetPersonaName = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetPersonaName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetPersonaName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetPersonaName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetPersonaState = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetPersonaState(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetPersonaState\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetPersonaState]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetPlayerNickname = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetPlayerNickname(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetPlayerNickname\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetPlayerNickname]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetProfileItemPropertyString = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetProfileItemPropertyString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetProfileItemPropertyString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetProfileItemPropertyString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetProfileItemPropertyUint = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetProfileItemPropertyUint(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetProfileItemPropertyUint\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetProfileItemPropertyUint]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetSmallFriendAvatar = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetSmallFriendAvatar(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetSmallFriendAvatar\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetSmallFriendAvatar]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_GetUserRestrictions = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_GetUserRestrictions(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_GetUserRestrictions\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_GetUserRestrictions]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_HasFriend = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_HasFriend(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_HasFriend\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_HasFriend]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_InviteUserToGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_InviteUserToGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_InviteUserToGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_InviteUserToGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_IsClanChatAdmin = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_IsClanChatAdmin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_IsClanChatAdmin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_IsClanChatAdmin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_IsClanOfficialGameGroup = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_IsClanOfficialGameGroup(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_IsClanOfficialGameGroup\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_IsClanOfficialGameGroup]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_IsClanPublic = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_IsClanPublic(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_IsClanPublic\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_IsClanPublic]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_IsFollowing = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_IsFollowing(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_IsFollowing\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_IsFollowing]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_IsUserInSource = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_IsUserInSource(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_IsUserInSource\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_IsUserInSource]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_JoinClanChatRoom = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_JoinClanChatRoom(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_JoinClanChatRoom\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_JoinClanChatRoom]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_LeaveClanChatRoom = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_LeaveClanChatRoom(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_LeaveClanChatRoom\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_LeaveClanChatRoom]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_OpenClanChatWindowInSteam = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_OpenClanChatWindowInSteam(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_OpenClanChatWindowInSteam\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_OpenClanChatWindowInSteam]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_ReplyToFriendMessage = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_ReplyToFriendMessage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_ReplyToFriendMessage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_ReplyToFriendMessage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_RequestClanOfficerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_RequestClanOfficerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_RequestClanOfficerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_RequestClanOfficerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_RequestEquippedProfileItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_RequestEquippedProfileItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_RequestEquippedProfileItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_RequestEquippedProfileItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_RequestFriendRichPresence = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_RequestFriendRichPresence(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_RequestFriendRichPresence\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_RequestFriendRichPresence]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_RequestUserInformation = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_RequestUserInformation(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_RequestUserInformation\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_RequestUserInformation]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_SendClanChatMessage = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_SendClanChatMessage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_SendClanChatMessage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_SendClanChatMessage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_SetInGameVoiceSpeaking = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_SetInGameVoiceSpeaking(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_SetInGameVoiceSpeaking\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_SetInGameVoiceSpeaking]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_SetListenForFriendsMessages = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_SetListenForFriendsMessages(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_SetListenForFriendsMessages\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_SetListenForFriendsMessages]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_SetPersonaName = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_SetPersonaName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_SetPersonaName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_SetPersonaName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_SetPlayedWith = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_SetPlayedWith(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_SetPlayedWith\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_SetPlayedWith]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamFriends_SetRichPresence = NULL;
__attribute__((naked)) void SteamAPI_ISteamFriends_SetRichPresence(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamFriends_SetRichPresence\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamFriends_SetRichPresence]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_AcceptGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_AcceptGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_AcceptGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_AcceptGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_AddGameSearchParams = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_AddGameSearchParams(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_AddGameSearchParams\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_AddGameSearchParams]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_DeclineGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_DeclineGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_DeclineGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_DeclineGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_EndGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_EndGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_EndGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_EndGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_EndGameSearch = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_EndGameSearch(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_EndGameSearch\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_EndGameSearch]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_HostConfirmGameStart = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_HostConfirmGameStart(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_HostConfirmGameStart\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_HostConfirmGameStart]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_RequestPlayersForGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_RequestPlayersForGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_RequestPlayersForGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_RequestPlayersForGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_RetrieveConnectionDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_RetrieveConnectionDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_RetrieveConnectionDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_RetrieveConnectionDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_SearchForGameSolo = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_SearchForGameSolo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_SearchForGameSolo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_SearchForGameSolo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_SearchForGameWithLobby = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_SearchForGameWithLobby(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_SearchForGameWithLobby\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_SearchForGameWithLobby]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_SetConnectionDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_SetConnectionDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_SetConnectionDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_SetConnectionDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_SetGameHostParams = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_SetGameHostParams(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_SetGameHostParams\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_SetGameHostParams]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameSearch_SubmitPlayerResult = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameSearch_SubmitPlayerResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameSearch_SubmitPlayerResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameSearch_SubmitPlayerResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_ClearUserAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_ClearUserAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_ClearUserAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_ClearUserAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_GetUserAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_GetUserAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_GetUserAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_GetUserAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_GetUserStatFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_GetUserStatFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_GetUserStatFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_GetUserStatFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_GetUserStatInt32 = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_GetUserStatInt32(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_GetUserStatInt32\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_GetUserStatInt32]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_RequestUserStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_RequestUserStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_RequestUserStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_RequestUserStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_SetUserAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_SetUserAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_SetUserAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_SetUserAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_SetUserStatFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_SetUserStatFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_SetUserStatFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_SetUserStatFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_SetUserStatInt32 = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_SetUserStatInt32(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_SetUserStatInt32\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_SetUserStatInt32]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_StoreUserStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_StoreUserStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_StoreUserStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_StoreUserStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_AssociateWithClan = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_AssociateWithClan(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_AssociateWithClan\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_AssociateWithClan]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_BLoggedOn = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_BLoggedOn(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_BLoggedOn\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_BLoggedOn]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_BSecure = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_BSecure(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_BSecure\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_BSecure]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_BUpdateUserData = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_BUpdateUserData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_BUpdateUserData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_BUpdateUserData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_BeginAuthSession = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_BeginAuthSession(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_BeginAuthSession\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_BeginAuthSession]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_CancelAuthTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_CancelAuthTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_CancelAuthTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_CancelAuthTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_ClearAllKeyValues = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_ClearAllKeyValues(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_ClearAllKeyValues\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_ClearAllKeyValues]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_EndAuthSession = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_EndAuthSession(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_EndAuthSession\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_EndAuthSession]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_GetAuthSessionTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_GetAuthSessionTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_GetAuthSessionTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_GetAuthSessionTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_GetGameplayStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_GetGameplayStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_GetGameplayStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_GetGameplayStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_GetNextOutgoingPacket = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_GetNextOutgoingPacket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_GetNextOutgoingPacket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_GetNextOutgoingPacket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_GetPublicIP = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_GetPublicIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_GetPublicIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_GetPublicIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_GetServerReputation = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_GetServerReputation(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_GetServerReputation\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_GetServerReputation]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_GetSteamID = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_GetSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_GetSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_GetSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_HandleIncomingPacket = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_HandleIncomingPacket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_HandleIncomingPacket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_HandleIncomingPacket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_LogOff = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_LogOff(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_LogOff\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_LogOff]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_LogOn = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_LogOn(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_LogOn\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_LogOn]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_LogOnAnonymous = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_LogOnAnonymous(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_LogOnAnonymous\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_LogOnAnonymous]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_RequestUserGroupStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_RequestUserGroupStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_RequestUserGroupStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_RequestUserGroupStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetAdvertiseServerActive = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetAdvertiseServerActive(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetAdvertiseServerActive\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetAdvertiseServerActive]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetBotPlayerCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetBotPlayerCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetBotPlayerCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetBotPlayerCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetDedicatedServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetDedicatedServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetDedicatedServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetDedicatedServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetGameData = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetGameData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetGameData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetGameData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetGameDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetGameDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetGameDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetGameDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetGameTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetGameTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetGameTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetGameTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetKeyValue = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetKeyValue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetKeyValue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetKeyValue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetMapName = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetMapName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetMapName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetMapName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetMaxPlayerCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetMaxPlayerCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetMaxPlayerCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetMaxPlayerCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetModDir = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetModDir(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetModDir\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetModDir]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetPasswordProtected = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetPasswordProtected(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetPasswordProtected\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetPasswordProtected]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetProduct = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetProduct(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetProduct\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetProduct]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetRegion = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetRegion(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetRegion\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetRegion]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetServerName = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetServerName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetServerName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetServerName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetSpectatorPort = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetSpectatorPort(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetSpectatorPort\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetSpectatorPort]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_SetSpectatorServerName = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_SetSpectatorServerName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_SetSpectatorServerName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_SetSpectatorServerName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_UserHasLicenseForApp = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_UserHasLicenseForApp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_UserHasLicenseForApp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_UserHasLicenseForApp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamGameServer_WasRestartRequested = NULL;
__attribute__((naked)) void SteamAPI_ISteamGameServer_WasRestartRequested(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamGameServer_WasRestartRequested\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamGameServer_WasRestartRequested]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_AddHeader = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_AddHeader(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_AddHeader\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_AddHeader]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_AllowStartRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_AllowStartRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_AllowStartRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_AllowStartRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_CopyToClipboard = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_CopyToClipboard(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_CopyToClipboard\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_CopyToClipboard]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_CreateBrowser = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_CreateBrowser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_CreateBrowser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_CreateBrowser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_ExecuteJavascript = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_ExecuteJavascript(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_ExecuteJavascript\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_ExecuteJavascript]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_Find = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_Find(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_Find\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_Find]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_GetLinkAtPosition = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_GetLinkAtPosition(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_GetLinkAtPosition\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_GetLinkAtPosition]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_GoBack = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_GoBack(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_GoBack\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_GoBack]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_GoForward = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_GoForward(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_GoForward\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_GoForward]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_Init = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_Init(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_Init\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_Init]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_JSDialogResponse = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_JSDialogResponse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_JSDialogResponse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_JSDialogResponse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_KeyChar = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_KeyChar(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_KeyChar\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_KeyChar]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_KeyDown = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_KeyDown(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_KeyDown\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_KeyDown]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_KeyUp = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_KeyUp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_KeyUp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_KeyUp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_LoadURL = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_LoadURL(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_LoadURL\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_LoadURL]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_MouseDoubleClick = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_MouseDoubleClick(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_MouseDoubleClick\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_MouseDoubleClick]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_MouseDown = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_MouseDown(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_MouseDown\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_MouseDown]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_MouseMove = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_MouseMove(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_MouseMove\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_MouseMove]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_MouseUp = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_MouseUp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_MouseUp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_MouseUp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_MouseWheel = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_MouseWheel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_MouseWheel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_MouseWheel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_OpenDeveloperTools = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_OpenDeveloperTools(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_OpenDeveloperTools\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_OpenDeveloperTools]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_PasteFromClipboard = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_PasteFromClipboard(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_PasteFromClipboard\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_PasteFromClipboard]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_Reload = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_Reload(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_Reload\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_Reload]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_RemoveBrowser = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_RemoveBrowser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_RemoveBrowser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_RemoveBrowser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetBackgroundMode = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetBackgroundMode(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetBackgroundMode\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetBackgroundMode]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetCookie = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetCookie(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetCookie\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetCookie]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetHorizontalScroll = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetHorizontalScroll(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetHorizontalScroll\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetHorizontalScroll]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetKeyFocus = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetKeyFocus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetKeyFocus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetKeyFocus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetPageScaleFactor = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetPageScaleFactor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetPageScaleFactor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetPageScaleFactor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetSize = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetSize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetSize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetSize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_SetVerticalScroll = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_SetVerticalScroll(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_SetVerticalScroll\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_SetVerticalScroll]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_Shutdown = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_Shutdown(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_Shutdown\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_Shutdown]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_StopFind = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_StopFind(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_StopFind\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_StopFind]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_StopLoad = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_StopLoad(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_StopLoad\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_StopLoad]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTMLSurface_ViewSource = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTMLSurface_ViewSource(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTMLSurface_ViewSource\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTMLSurface_ViewSource]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_CreateCookieContainer = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_CreateCookieContainer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_CreateCookieContainer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_CreateCookieContainer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_CreateHTTPRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_CreateHTTPRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_CreateHTTPRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_CreateHTTPRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_DeferHTTPRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_DeferHTTPRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_DeferHTTPRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_DeferHTTPRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPResponseBodyData = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPResponseBodyData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPResponseBodyData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPResponseBodyData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPResponseBodySize = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPResponseBodySize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPResponseBodySize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPResponseBodySize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_ReleaseCookieContainer = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_ReleaseCookieContainer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_ReleaseCookieContainer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_ReleaseCookieContainer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_ReleaseHTTPRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_ReleaseHTTPRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_ReleaseHTTPRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_ReleaseHTTPRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SendHTTPRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SendHTTPRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SendHTTPRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SendHTTPRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetCookie = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetCookie(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetCookie\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetCookie]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_ActivateActionSet = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_ActivateActionSet(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_ActivateActionSet\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_ActivateActionSet]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_ActivateActionSetLayer = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_ActivateActionSetLayer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_ActivateActionSetLayer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_ActivateActionSetLayer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_BNewDataAvailable = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_BNewDataAvailable(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_BNewDataAvailable\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_BNewDataAvailable]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_BWaitForData = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_BWaitForData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_BWaitForData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_BWaitForData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_DeactivateActionSetLayer = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_DeactivateActionSetLayer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_DeactivateActionSetLayer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_DeactivateActionSetLayer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_DeactivateAllActionSetLayers = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_DeactivateAllActionSetLayers(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_DeactivateAllActionSetLayers\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_DeactivateAllActionSetLayers]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_EnableActionEventCallbacks = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_EnableActionEventCallbacks(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_EnableActionEventCallbacks\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_EnableActionEventCallbacks]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_EnableDeviceCallbacks = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_EnableDeviceCallbacks(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_EnableDeviceCallbacks\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_EnableDeviceCallbacks]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetActionSetHandle = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetActionSetHandle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetActionSetHandle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetActionSetHandle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetActiveActionSetLayers = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetActiveActionSetLayers(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetActiveActionSetLayers\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetActiveActionSetLayers]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetAnalogActionData = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetAnalogActionData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetAnalogActionData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetAnalogActionData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetAnalogActionHandle = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetAnalogActionHandle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetAnalogActionHandle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetAnalogActionHandle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetAnalogActionOrigins = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetAnalogActionOrigins(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetAnalogActionOrigins\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetAnalogActionOrigins]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetConnectedControllers = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetConnectedControllers(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetConnectedControllers\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetConnectedControllers]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetControllerForGamepadIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetControllerForGamepadIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetControllerForGamepadIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetControllerForGamepadIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetCurrentActionSet = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetCurrentActionSet(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetCurrentActionSet\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetCurrentActionSet]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetDeviceBindingRevision = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetDeviceBindingRevision(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetDeviceBindingRevision\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetDeviceBindingRevision]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetDigitalActionData = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetDigitalActionData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetDigitalActionData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetDigitalActionData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetDigitalActionHandle = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetDigitalActionHandle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetDigitalActionHandle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetDigitalActionHandle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetDigitalActionOrigins = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetDigitalActionOrigins(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetDigitalActionOrigins\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetDigitalActionOrigins]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetGamepadIndexForController = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetGamepadIndexForController(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetGamepadIndexForController\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetGamepadIndexForController]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetGlyphForXboxOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetGlyphForXboxOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetGlyphForXboxOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetGlyphForXboxOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetInputTypeForHandle = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetInputTypeForHandle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetInputTypeForHandle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetInputTypeForHandle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetMotionData = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetMotionData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetMotionData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetMotionData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetRemotePlaySessionID = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetRemotePlaySessionID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetRemotePlaySessionID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetRemotePlaySessionID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetSessionInputConfigurationSettings(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetStringForActionOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetStringForActionOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetStringForActionOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetStringForActionOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetStringForAnalogActionName = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetStringForAnalogActionName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetStringForAnalogActionName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetStringForAnalogActionName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetStringForDigitalActionName = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetStringForDigitalActionName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetStringForDigitalActionName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetStringForDigitalActionName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_GetStringForXboxOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_GetStringForXboxOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_GetStringForXboxOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_GetStringForXboxOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_Init = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_Init(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_Init\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_Init]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_Legacy_TriggerHapticPulse = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_Legacy_TriggerHapticPulse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_Legacy_TriggerHapticPulse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_Legacy_TriggerHapticPulse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_RunFrame = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_RunFrame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_RunFrame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_RunFrame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_SetDualSenseTriggerEffect = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_SetDualSenseTriggerEffect(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_SetDualSenseTriggerEffect\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_SetDualSenseTriggerEffect]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_SetInputActionManifestFilePath = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_SetInputActionManifestFilePath(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_SetInputActionManifestFilePath\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_SetInputActionManifestFilePath]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_SetLEDColor = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_SetLEDColor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_SetLEDColor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_SetLEDColor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_ShowBindingPanel = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_ShowBindingPanel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_ShowBindingPanel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_ShowBindingPanel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_Shutdown = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_Shutdown(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_Shutdown\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_Shutdown]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_StopAnalogActionMomentum = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_StopAnalogActionMomentum(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_StopAnalogActionMomentum\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_StopAnalogActionMomentum]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_TranslateActionOrigin = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_TranslateActionOrigin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_TranslateActionOrigin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_TranslateActionOrigin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_TriggerSimpleHapticEvent = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_TriggerSimpleHapticEvent(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_TriggerSimpleHapticEvent\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_TriggerSimpleHapticEvent]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_TriggerVibration = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_TriggerVibration(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_TriggerVibration\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_TriggerVibration]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInput_TriggerVibrationExtended = NULL;
__attribute__((naked)) void SteamAPI_ISteamInput_TriggerVibrationExtended(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInput_TriggerVibrationExtended\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInput_TriggerVibrationExtended]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_AddPromoItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_AddPromoItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_AddPromoItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_AddPromoItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_AddPromoItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_AddPromoItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_AddPromoItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_AddPromoItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_CheckResultSteamID = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_CheckResultSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_CheckResultSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_CheckResultSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_ConsumeItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_ConsumeItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_ConsumeItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_ConsumeItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_DeserializeResult = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_DeserializeResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_DeserializeResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_DeserializeResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_DestroyResult = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_DestroyResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_DestroyResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_DestroyResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_ExchangeItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_ExchangeItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_ExchangeItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_ExchangeItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GenerateItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GenerateItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GenerateItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GenerateItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetAllItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetAllItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetAllItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetAllItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetItemDefinitionIDs = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetItemDefinitionIDs(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetItemDefinitionIDs\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetItemDefinitionIDs]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetItemDefinitionProperty = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetItemDefinitionProperty(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetItemDefinitionProperty\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetItemDefinitionProperty]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetItemPrice = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetItemPrice(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetItemPrice\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetItemPrice]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetItemsByID = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetItemsByID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetItemsByID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetItemsByID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetItemsWithPrices = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetItemsWithPrices(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetItemsWithPrices\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetItemsWithPrices]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetNumItemsWithPrices = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetNumItemsWithPrices(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetNumItemsWithPrices\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetNumItemsWithPrices]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetResultItemProperty = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetResultItemProperty(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetResultItemProperty\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetResultItemProperty]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetResultItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetResultItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetResultItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetResultItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetResultStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetResultStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetResultStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetResultStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GetResultTimestamp = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GetResultTimestamp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GetResultTimestamp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GetResultTimestamp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_GrantPromoItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_GrantPromoItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_GrantPromoItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_GrantPromoItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_InspectItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_InspectItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_InspectItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_InspectItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_LoadItemDefinitions = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_LoadItemDefinitions(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_LoadItemDefinitions\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_LoadItemDefinitions]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_RemoveProperty = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_RemoveProperty(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_RemoveProperty\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_RemoveProperty]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_RequestPrices = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_RequestPrices(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_RequestPrices\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_RequestPrices]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SendItemDropHeartbeat = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SendItemDropHeartbeat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SendItemDropHeartbeat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SendItemDropHeartbeat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SerializeResult = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SerializeResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SerializeResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SerializeResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SetPropertyBool = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SetPropertyBool(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SetPropertyBool\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SetPropertyBool]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SetPropertyFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SetPropertyFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SetPropertyFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SetPropertyFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SetPropertyInt64 = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SetPropertyInt64(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SetPropertyInt64\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SetPropertyInt64]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SetPropertyString = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SetPropertyString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SetPropertyString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SetPropertyString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_StartPurchase = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_StartPurchase(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_StartPurchase\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_StartPurchase]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_StartUpdateProperties = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_StartUpdateProperties(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_StartUpdateProperties\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_StartUpdateProperties]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_SubmitUpdateProperties = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_SubmitUpdateProperties(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_SubmitUpdateProperties\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_SubmitUpdateProperties]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_TradeItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_TradeItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_TradeItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_TradeItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_TransferItemQuantity = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_TransferItemQuantity(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_TransferItemQuantity\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_TransferItemQuantity]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamInventory_TriggerItemDrop = NULL;
__attribute__((naked)) void SteamAPI_ISteamInventory_TriggerItemDrop(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamInventory_TriggerItemDrop\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamInventory_TriggerItemDrop]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_CancelQuery = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_CancelQuery(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_CancelQuery\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_CancelQuery]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_CancelServerQuery = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_CancelServerQuery(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_CancelServerQuery\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_CancelServerQuery]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_GetServerCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_GetServerCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_GetServerCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_GetServerCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_GetServerDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_GetServerDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_GetServerDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_GetServerDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_IsRefreshing = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_IsRefreshing(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_IsRefreshing\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_IsRefreshing]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_PingServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_PingServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_PingServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_PingServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_PlayerDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_PlayerDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_PlayerDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_PlayerDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RefreshQuery = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RefreshQuery(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RefreshQuery\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RefreshQuery]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RefreshServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RefreshServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RefreshServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RefreshServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_ReleaseRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_ReleaseRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_ReleaseRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_ReleaseRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RequestInternetServerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RequestInternetServerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RequestInternetServerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RequestInternetServerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RequestLANServerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RequestLANServerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RequestLANServerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RequestLANServerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmakingServers_ServerRules = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmakingServers_ServerRules(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmakingServers_ServerRules\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmakingServers_ServerRules]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddFavoriteGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddFavoriteGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddFavoriteGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddFavoriteGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_CreateLobby = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_CreateLobby(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_CreateLobby\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_CreateLobby]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_DeleteLobbyData = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_DeleteLobbyData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_DeleteLobbyData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_DeleteLobbyData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetFavoriteGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetFavoriteGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetFavoriteGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetFavoriteGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetFavoriteGameCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetFavoriteGameCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetFavoriteGameCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetFavoriteGameCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyChatEntry = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyChatEntry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyChatEntry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyChatEntry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyData = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyDataCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyDataCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyDataCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyDataCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyGameServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyGameServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyGameServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyGameServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyMemberData = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyMemberData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyMemberData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyMemberData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetLobbyOwner = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetLobbyOwner(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetLobbyOwner\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetLobbyOwner]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_GetNumLobbyMembers = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_GetNumLobbyMembers(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_GetNumLobbyMembers\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_GetNumLobbyMembers]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_InviteUserToLobby = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_InviteUserToLobby(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_InviteUserToLobby\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_InviteUserToLobby]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_JoinLobby = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_JoinLobby(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_JoinLobby\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_JoinLobby]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_LeaveLobby = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_LeaveLobby(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_LeaveLobby\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_LeaveLobby]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_RemoveFavoriteGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_RemoveFavoriteGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_RemoveFavoriteGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_RemoveFavoriteGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_RequestLobbyData = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_RequestLobbyData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_RequestLobbyData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_RequestLobbyData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_RequestLobbyList = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_RequestLobbyList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_RequestLobbyList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_RequestLobbyList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SendLobbyChatMsg = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SendLobbyChatMsg(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SendLobbyChatMsg\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SendLobbyChatMsg]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLinkedLobby = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLinkedLobby(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLinkedLobby\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLinkedLobby]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyData = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyGameServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyGameServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyGameServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyGameServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyJoinable = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyJoinable(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyJoinable\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyJoinable]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyMemberData = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyMemberData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyMemberData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyMemberData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyOwner = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyOwner(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyOwner\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyOwner]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMatchmaking_SetLobbyType = NULL;
__attribute__((naked)) void SteamAPI_ISteamMatchmaking_SetLobbyType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMatchmaking_SetLobbyType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMatchmaking_SetLobbyType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_BActivationSuccess = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_BActivationSuccess(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_BActivationSuccess\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_BActivationSuccess]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_CurrentEntryDidChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_CurrentEntryDidChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_CurrentEntryDidChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_CurrentEntryDidChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_CurrentEntryWillChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_CurrentEntryWillChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_CurrentEntryWillChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_CurrentEntryWillChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_EnableLooped = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_EnableLooped(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_EnableLooped\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_EnableLooped]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_EnablePlayNext = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_EnablePlayNext(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_EnablePlayNext\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_EnablePlayNext]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_EnablePlayPrevious = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_EnablePlayPrevious(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_EnablePlayPrevious\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_EnablePlayPrevious]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_EnablePlaylists = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_EnablePlaylists(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_EnablePlaylists\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_EnablePlaylists]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_EnableQueue = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_EnableQueue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_EnableQueue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_EnableQueue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_EnableShuffled = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_EnableShuffled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_EnableShuffled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_EnableShuffled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_PlaylistDidChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_PlaylistDidChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_PlaylistDidChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_PlaylistDidChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_PlaylistWillChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_PlaylistWillChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_PlaylistWillChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_PlaylistWillChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_QueueDidChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_QueueDidChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_QueueDidChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_QueueDidChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_QueueWillChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_QueueWillChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_QueueWillChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_QueueWillChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_ResetPlaylistEntries = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_ResetPlaylistEntries(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_ResetPlaylistEntries\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_ResetPlaylistEntries]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_ResetQueueEntries = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_ResetQueueEntries(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_ResetQueueEntries\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_ResetQueueEntries]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_SetDisplayName = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_SetDisplayName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_SetDisplayName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_SetDisplayName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64 = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_SetPlaylistEntry = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_SetPlaylistEntry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_SetPlaylistEntry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_SetPlaylistEntry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_SetQueueEntry = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_SetQueueEntry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_SetQueueEntry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_SetQueueEntry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdateLooped = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdateLooped(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdateLooped\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdateLooped]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdateShuffled = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdateShuffled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdateShuffled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdateShuffled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusicRemote_UpdateVolume = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusicRemote_UpdateVolume(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusicRemote_UpdateVolume\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusicRemote_UpdateVolume]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_BIsEnabled = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_BIsEnabled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_BIsEnabled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_BIsEnabled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_BIsPlaying = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_BIsPlaying(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_BIsPlaying\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_BIsPlaying]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_GetPlaybackStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_GetPlaybackStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_GetPlaybackStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_GetPlaybackStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_GetVolume = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_GetVolume(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_GetVolume\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_GetVolume]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_Pause = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_Pause(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_Pause\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_Pause]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_Play = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_Play(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_Play\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_Play]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_PlayNext = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_PlayNext(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_PlayNext\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_PlayNext]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_PlayPrevious = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_PlayPrevious(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_PlayPrevious\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_PlayPrevious]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamMusic_SetVolume = NULL;
__attribute__((naked)) void SteamAPI_ISteamMusic_SetVolume(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamMusic_SetVolume\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamMusic_SetVolume]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingConnectionSignaling_Release = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingConnectionSignaling_Release(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingConnectionSignaling_Release\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingConnectionSignaling_Release]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingMessages_SendMessageToUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingMessages_SendMessageToUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingMessages_SendMessageToUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingMessages_SendMessageToUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_AcceptConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_AcceptConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_AcceptConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_AcceptConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CloseConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CloseConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CloseConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CloseConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CloseListenSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CloseListenSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CloseListenSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CloseListenSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ConnectP2P = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ConnectP2P(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ConnectP2P\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ConnectP2P]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreatePollGroup = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreatePollGroup(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreatePollGroup\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreatePollGroup]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_CreateSocketPair = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_CreateSocketPair(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_CreateSocketPair\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_CreateSocketPair]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_DestroyPollGroup = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_DestroyPollGroup(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_DestroyPollGroup\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_DestroyPollGroup]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetCertificateRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetCertificateRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetCertificateRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetCertificateRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetConnectionInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetConnectionInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetConnectionInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetConnectionInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetConnectionName = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetConnectionName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetConnectionName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetConnectionName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetConnectionUserData = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetConnectionUserData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetConnectionUserData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetConnectionUserData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetFakeIP = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetFakeIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetFakeIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetFakeIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetIdentity = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetIdentity(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetIdentity\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetIdentity]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_InitAuthentication = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_InitAuthentication(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_InitAuthentication\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_InitAuthentication]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_ResetIdentity = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_ResetIdentity(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_ResetIdentity\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_ResetIdentity]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_RunCallbacks = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_RunCallbacks(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_RunCallbacks\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_RunCallbacks]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_SendMessageToConnection = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_SendMessageToConnection(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_SendMessageToConnection\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_SendMessageToConnection]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_SendMessages = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_SendMessages(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_SendMessages\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_SendMessages]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_SetCertificate = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_SetCertificate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_SetCertificate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_SetCertificate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_SetConnectionName = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_SetConnectionName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_SetConnectionName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_SetConnectionName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingSockets_SetConnectionUserData = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingSockets_SetConnectionUserData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingSockets_SetConnectionUserData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingSockets_SetConnectionUserData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_AllocateMessage = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_AllocateMessage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_AllocateMessage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_AllocateMessage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetConfigValue = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetConfigValue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetConfigValue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetConfigValue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetPOPCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetPOPCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetPOPCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetPOPCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetPOPList = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetPOPList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetPOPList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetPOPList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4 = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_IsFakeIPv4(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_ParsePingLocationString = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_ParsePingLocationString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_ParsePingLocationString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_ParsePingLocationString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SetConfigValue = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SetConfigValue(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SetConfigValue\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SetConfigValue]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_AllowP2PPacketRelay = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_AllowP2PPacketRelay(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_AllowP2PPacketRelay\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_AllowP2PPacketRelay]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_CloseP2PChannelWithUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_CloseP2PChannelWithUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_CloseP2PChannelWithUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_CloseP2PChannelWithUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_CloseP2PSessionWithUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_CloseP2PSessionWithUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_CloseP2PSessionWithUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_CloseP2PSessionWithUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_CreateConnectionSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_CreateConnectionSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_CreateConnectionSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_CreateConnectionSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_CreateListenSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_CreateListenSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_CreateListenSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_CreateListenSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_CreateP2PConnectionSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_CreateP2PConnectionSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_CreateP2PConnectionSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_CreateP2PConnectionSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_DestroyListenSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_DestroyListenSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_DestroyListenSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_DestroyListenSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_DestroySocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_DestroySocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_DestroySocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_DestroySocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_GetListenSocketInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_GetListenSocketInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_GetListenSocketInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_GetListenSocketInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_GetMaxPacketSize = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_GetMaxPacketSize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_GetMaxPacketSize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_GetMaxPacketSize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_GetP2PSessionState = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_GetP2PSessionState(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_GetP2PSessionState\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_GetP2PSessionState]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_GetSocketConnectionType = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_GetSocketConnectionType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_GetSocketConnectionType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_GetSocketConnectionType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_GetSocketInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_GetSocketInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_GetSocketInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_GetSocketInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_IsDataAvailable = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_IsDataAvailable(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_IsDataAvailable\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_IsDataAvailable]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_IsDataAvailableOnSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_IsDataAvailableOnSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_IsDataAvailableOnSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_IsDataAvailableOnSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_IsP2PPacketAvailable = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_IsP2PPacketAvailable(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_IsP2PPacketAvailable\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_IsP2PPacketAvailable]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_ReadP2PPacket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_ReadP2PPacket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_ReadP2PPacket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_ReadP2PPacket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_RetrieveData = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_RetrieveData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_RetrieveData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_RetrieveData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_RetrieveDataFromSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_RetrieveDataFromSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_RetrieveDataFromSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_RetrieveDataFromSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_SendDataOnSocket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_SendDataOnSocket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_SendDataOnSocket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_SendDataOnSocket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamNetworking_SendP2PPacket = NULL;
__attribute__((naked)) void SteamAPI_ISteamNetworking_SendP2PPacket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamNetworking_SendP2PPacket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamNetworking_SendP2PPacket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParentalSettings_BIsAppBlocked = NULL;
__attribute__((naked)) void SteamAPI_ISteamParentalSettings_BIsAppBlocked(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParentalSettings_BIsAppBlocked\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParentalSettings_BIsAppBlocked]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParentalSettings_BIsAppInBlockList = NULL;
__attribute__((naked)) void SteamAPI_ISteamParentalSettings_BIsAppInBlockList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParentalSettings_BIsAppInBlockList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParentalSettings_BIsAppInBlockList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParentalSettings_BIsFeatureBlocked = NULL;
__attribute__((naked)) void SteamAPI_ISteamParentalSettings_BIsFeatureBlocked(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParentalSettings_BIsFeatureBlocked\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParentalSettings_BIsFeatureBlocked]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList = NULL;
__attribute__((naked)) void SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled = NULL;
__attribute__((naked)) void SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked = NULL;
__attribute__((naked)) void SteamAPI_ISteamParentalSettings_BIsParentalLockLocked(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_CancelReservation = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_CancelReservation(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_CancelReservation\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_CancelReservation]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_ChangeNumOpenSlots = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_ChangeNumOpenSlots(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_ChangeNumOpenSlots\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_ChangeNumOpenSlots]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_CreateBeacon = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_CreateBeacon(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_CreateBeacon\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_CreateBeacon]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_DestroyBeacon = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_DestroyBeacon(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_DestroyBeacon\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_DestroyBeacon]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_GetAvailableBeaconLocations = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_GetAvailableBeaconLocations(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_GetAvailableBeaconLocations\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_GetAvailableBeaconLocations]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_GetBeaconByIndex = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_GetBeaconByIndex(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_GetBeaconByIndex\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_GetBeaconByIndex]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_GetBeaconDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_GetBeaconDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_GetBeaconDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_GetBeaconDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_GetBeaconLocationData = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_GetBeaconLocationData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_GetBeaconLocationData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_GetBeaconLocationData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_GetNumActiveBeacons = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_GetNumActiveBeacons(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_GetNumActiveBeacons\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_GetNumActiveBeacons]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_GetNumAvailableBeaconLocations = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_GetNumAvailableBeaconLocations(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_GetNumAvailableBeaconLocations\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_GetNumAvailableBeaconLocations]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_JoinParty = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_JoinParty(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_JoinParty\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_JoinParty]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamParties_OnReservationCompleted = NULL;
__attribute__((naked)) void SteamAPI_ISteamParties_OnReservationCompleted(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamParties_OnReservationCompleted\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamParties_OnReservationCompleted]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_BGetSessionClientResolution = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_BGetSessionClientResolution(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_BGetSessionClientResolution\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_BGetSessionClientResolution]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_BStartRemotePlayTogether = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_BStartRemotePlayTogether(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_BStartRemotePlayTogether\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_BStartRemotePlayTogether]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_GetSessionClientName = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_GetSessionClientName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_GetSessionClientName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_GetSessionClientName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_GetSessionCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_GetSessionCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_GetSessionCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_GetSessionCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_GetSessionID = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_GetSessionID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_GetSessionID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_GetSessionID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemotePlay_GetSessionSteamID = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemotePlay_GetSessionSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemotePlay_GetSessionSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemotePlay_GetSessionSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_DeletePublishedFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_DeletePublishedFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_DeletePublishedFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_DeletePublishedFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_EndFileWriteBatch = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_EndFileWriteBatch(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_EndFileWriteBatch\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_EndFileWriteBatch]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileDelete = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileDelete(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileDelete\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileDelete]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileExists = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileExists(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileExists\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileExists]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileForget = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileForget(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileForget\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileForget]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FilePersisted = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FilePersisted(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FilePersisted\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FilePersisted]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileRead = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileRead(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileRead\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileRead]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileReadAsync = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileReadAsync(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileReadAsync\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileReadAsync]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileShare = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileShare(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileShare\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileShare]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileWrite = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileWrite(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileWrite\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileWrite]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileWriteAsync = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileWriteAsync(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileWriteAsync\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileWriteAsync]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileWriteStreamClose = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamClose\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamClose]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetCachedUGCCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetCachedUGCCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetCachedUGCCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetFileCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetFileCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetFileCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetFileCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetFileNameAndSize = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetFileNameAndSize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetFileNameAndSize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetFileSize = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetFileSize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetFileSize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetFileSize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetFileTimestamp = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetFileTimestamp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetFileTimestamp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetFileTimestamp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetLocalFileChange = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetLocalFileChange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetLocalFileChange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetLocalFileChange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetQuota = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetQuota(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetQuota\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetQuota]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetSyncPlatforms = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetSyncPlatforms(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetSyncPlatforms\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetSyncPlatforms]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetUGCDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetUGCDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetUGCDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetUGCDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_PublishVideo = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_PublishVideo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_PublishVideo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_PublishVideo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_PublishWorkshopFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_PublishWorkshopFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_PublishWorkshopFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_PublishWorkshopFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_SetSyncPlatforms = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_SetSyncPlatforms(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_SetSyncPlatforms\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_SetSyncPlatforms]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_SubscribePublishedFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_SubscribePublishedFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_SubscribePublishedFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_SubscribePublishedFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UGCDownload = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UGCDownload(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UGCDownload\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UGCDownload]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UGCRead = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UGCRead(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UGCRead\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UGCRead]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote = NULL;
__attribute__((naked)) void SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_AddScreenshotToLibrary = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_AddScreenshotToLibrary(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_AddScreenshotToLibrary\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_AddScreenshotToLibrary]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_HookScreenshots = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_HookScreenshots(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_HookScreenshots\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_HookScreenshots]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_IsScreenshotsHooked = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_IsScreenshotsHooked(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_IsScreenshotsHooked\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_IsScreenshotsHooked]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_SetLocation = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_SetLocation(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_SetLocation\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_SetLocation]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_TagPublishedFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_TagPublishedFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_TagPublishedFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_TagPublishedFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_TagUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_TagUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_TagUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_TagUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_TriggerScreenshot = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_TriggerScreenshot(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_TriggerScreenshot\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_TriggerScreenshot]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamScreenshots_WriteScreenshot = NULL;
__attribute__((naked)) void SteamAPI_ISteamScreenshots_WriteScreenshot(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamScreenshots_WriteScreenshot\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamScreenshots_WriteScreenshot]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamTimeline_AddTimelineEvent = NULL;
__attribute__((naked)) void SteamAPI_ISteamTimeline_AddTimelineEvent(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamTimeline_AddTimelineEvent\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamTimeline_AddTimelineEvent]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamTimeline_ClearTimelineStateDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamTimeline_ClearTimelineStateDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamTimeline_ClearTimelineStateDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamTimeline_ClearTimelineStateDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamTimeline_SetTimelineGameMode = NULL;
__attribute__((naked)) void SteamAPI_ISteamTimeline_SetTimelineGameMode(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamTimeline_SetTimelineGameMode\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamTimeline_SetTimelineGameMode]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamTimeline_SetTimelineStateDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamTimeline_SetTimelineStateDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamTimeline_SetTimelineStateDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamTimeline_SetTimelineStateDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddAppDependency = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddAppDependency(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddAppDependency\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddAppDependency]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddContentDescriptor = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddContentDescriptor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddContentDescriptor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddContentDescriptor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddDependency = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddDependency(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddDependency\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddDependency]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddExcludedTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddExcludedTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddExcludedTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddExcludedTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddItemKeyValueTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddItemKeyValueTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddItemKeyValueTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddItemKeyValueTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddItemPreviewFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddItemPreviewFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddItemPreviewFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddItemPreviewFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddItemPreviewVideo = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddItemPreviewVideo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddItemPreviewVideo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddItemPreviewVideo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddItemToFavorites = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddItemToFavorites(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddItemToFavorites\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddItemToFavorites]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddRequiredKeyValueTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddRequiredKeyValueTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddRequiredKeyValueTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddRequiredKeyValueTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddRequiredTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddRequiredTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddRequiredTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddRequiredTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_AddRequiredTagGroup = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_AddRequiredTagGroup(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_AddRequiredTagGroup\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_AddRequiredTagGroup]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_BInitWorkshopForGameServer = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_BInitWorkshopForGameServer(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_BInitWorkshopForGameServer\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_BInitWorkshopForGameServer]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_CreateItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_CreateItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_CreateItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_CreateItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_CreateQueryUserUGCRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_CreateQueryUserUGCRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_CreateQueryUserUGCRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_CreateQueryUserUGCRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_DeleteItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_DeleteItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_DeleteItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_DeleteItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_DownloadItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_DownloadItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_DownloadItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_DownloadItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetAppDependencies = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetAppDependencies(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetAppDependencies\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetAppDependencies]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetItemDownloadInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetItemDownloadInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetItemDownloadInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetItemDownloadInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetItemInstallInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetItemInstallInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetItemInstallInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetItemInstallInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetItemState = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetItemState(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetItemState\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetItemState]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetItemUpdateProgress = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetItemUpdateProgress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetItemUpdateProgress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetItemUpdateProgress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetNumSubscribedItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetNumSubscribedItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetNumSubscribedItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetNumSubscribedItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetNumSupportedGameVersions = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetNumSupportedGameVersions(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetNumSupportedGameVersions\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetNumSupportedGameVersions]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCChildren = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCChildren(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCChildren\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCChildren]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCMetadata = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCMetadata(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCMetadata\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCMetadata]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCNumTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCNumTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCNumTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCNumTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCPreviewURL = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCPreviewURL(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCPreviewURL\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCPreviewURL]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCResult = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCStatistic = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCStatistic(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCStatistic\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCStatistic]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetSubscribedItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetSubscribedItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetSubscribedItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetSubscribedItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetSupportedGameVersionData = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetSupportedGameVersionData(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetSupportedGameVersionData\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetSupportedGameVersionData]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetUserContentDescriptorPreferences = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetUserContentDescriptorPreferences(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetUserContentDescriptorPreferences\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetUserContentDescriptorPreferences]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetUserItemVote = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetUserItemVote(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetUserItemVote\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetUserItemVote]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_GetWorkshopEULAStatus = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_GetWorkshopEULAStatus(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_GetWorkshopEULAStatus\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_GetWorkshopEULAStatus]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_ReleaseQueryUGCRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_ReleaseQueryUGCRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_ReleaseQueryUGCRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_ReleaseQueryUGCRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveAppDependency = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveAppDependency(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveAppDependency\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveAppDependency]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveContentDescriptor = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveContentDescriptor(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveContentDescriptor\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveContentDescriptor]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveDependency = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveDependency(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveDependency\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveDependency]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveItemFromFavorites = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveItemFromFavorites(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveItemFromFavorites\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveItemFromFavorites]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveItemKeyValueTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveItemKeyValueTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveItemKeyValueTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveItemKeyValueTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RemoveItemPreview = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RemoveItemPreview(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RemoveItemPreview\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RemoveItemPreview]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_RequestUGCDetails = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_RequestUGCDetails(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_RequestUGCDetails\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_RequestUGCDetails]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SendQueryUGCRequest = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SendQueryUGCRequest(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SendQueryUGCRequest\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SendQueryUGCRequest]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetAdminQuery = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetAdminQuery(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetAdminQuery\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetAdminQuery]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetAllowCachedResponse = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetAllowCachedResponse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetAllowCachedResponse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetAllowCachedResponse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetAllowLegacyUpload = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetAllowLegacyUpload(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetAllowLegacyUpload\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetAllowLegacyUpload]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetCloudFileNameFilter = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetCloudFileNameFilter(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetCloudFileNameFilter\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetCloudFileNameFilter]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemContent = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemContent(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemContent\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemContent]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemMetadata = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemMetadata(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemMetadata\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemMetadata]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemPreview = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemPreview(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemPreview\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemPreview]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemTitle = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemTitle(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemTitle\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemTitle]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemUpdateLanguage = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemUpdateLanguage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemUpdateLanguage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemUpdateLanguage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetItemVisibility = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetItemVisibility(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetItemVisibility\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetItemVisibility]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetLanguage = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetLanguage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetLanguage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetLanguage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetMatchAnyTag = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetMatchAnyTag(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetMatchAnyTag\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetMatchAnyTag]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetRankedByTrendDays = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetRankedByTrendDays(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetRankedByTrendDays\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetRankedByTrendDays]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetRequiredGameVersions = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetRequiredGameVersions(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetRequiredGameVersions\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetRequiredGameVersions]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnAdditionalPreviews = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnAdditionalPreviews(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnAdditionalPreviews\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnAdditionalPreviews]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnChildren = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnChildren(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnChildren\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnChildren]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnKeyValueTags = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnKeyValueTags(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnKeyValueTags\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnKeyValueTags]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnLongDescription = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnLongDescription(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnLongDescription\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnLongDescription]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnMetadata = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnMetadata(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnMetadata\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnMetadata]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnOnlyIDs = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnOnlyIDs(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnOnlyIDs\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnOnlyIDs]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnPlaytimeStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnPlaytimeStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnPlaytimeStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnPlaytimeStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetReturnTotalOnly = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetReturnTotalOnly(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetReturnTotalOnly\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetReturnTotalOnly]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetSearchText = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetSearchText(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetSearchText\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetSearchText]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetTimeCreatedDateRange = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetTimeCreatedDateRange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetTimeCreatedDateRange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetTimeCreatedDateRange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetTimeUpdatedDateRange = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetTimeUpdatedDateRange(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetTimeUpdatedDateRange\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetTimeUpdatedDateRange]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SetUserItemVote = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SetUserItemVote(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SetUserItemVote\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SetUserItemVote]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_ShowWorkshopEULA = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_ShowWorkshopEULA(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_ShowWorkshopEULA\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_ShowWorkshopEULA]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_StartItemUpdate = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_StartItemUpdate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_StartItemUpdate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_StartItemUpdate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_StartPlaytimeTracking = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_StartPlaytimeTracking(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_StartPlaytimeTracking\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_StartPlaytimeTracking]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_StopPlaytimeTracking = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_StopPlaytimeTracking(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_StopPlaytimeTracking\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_StopPlaytimeTracking]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SubmitItemUpdate = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SubmitItemUpdate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SubmitItemUpdate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SubmitItemUpdate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SubscribeItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SubscribeItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SubscribeItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SubscribeItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_SuspendDownloads = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_SuspendDownloads(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_SuspendDownloads\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_SuspendDownloads]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_UnsubscribeItem = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_UnsubscribeItem(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_UnsubscribeItem\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_UnsubscribeItem]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_UpdateItemPreviewFile = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_UpdateItemPreviewFile(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_UpdateItemPreviewFile\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_UpdateItemPreviewFile]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUGC_UpdateItemPreviewVideo = NULL;
__attribute__((naked)) void SteamAPI_ISteamUGC_UpdateItemPreviewVideo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUGC_UpdateItemPreviewVideo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUGC_UpdateItemPreviewVideo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_AttachLeaderboardUGC = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_AttachLeaderboardUGC(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_AttachLeaderboardUGC\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_AttachLeaderboardUGC]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_ClearAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_ClearAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_ClearAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_ClearAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntries = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntries\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntries]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_FindLeaderboard = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_FindLeaderboard(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_FindLeaderboard\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_FindLeaderboard]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_FindOrCreateLeaderboard = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_FindOrCreateLeaderboard\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_FindOrCreateLeaderboard]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementAchievedPercent = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementAchievedPercent(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementAchievedPercent\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementAchievedPercent]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementIcon = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementIcon(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementIcon\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementIcon]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementName = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32 = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetGlobalStatDouble = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetGlobalStatDouble(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetGlobalStatDouble\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetGlobalStatDouble]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64 = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetGlobalStatInt64 = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetGlobalStatInt64(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetGlobalStatInt64\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetGlobalStatInt64]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetLeaderboardDisplayType = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetLeaderboardDisplayType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetLeaderboardDisplayType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetLeaderboardDisplayType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetLeaderboardEntryCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetLeaderboardEntryCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetLeaderboardEntryCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetLeaderboardEntryCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetLeaderboardName = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetLeaderboardName(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetLeaderboardName\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetLeaderboardName]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetLeaderboardSortMethod = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetLeaderboardSortMethod(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetLeaderboardSortMethod\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetLeaderboardSortMethod]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetNumAchievements = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetNumAchievements(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetNumAchievements\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetNumAchievements]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetStatFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetStatFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetStatFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetStatFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetStatInt32 = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetStatInt32(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetStatInt32\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetStatInt32]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetUserAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetUserAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetUserAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetUserAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetUserStatFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetUserStatFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetUserStatFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetUserStatFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_GetUserStatInt32 = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_GetUserStatInt32(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_GetUserStatInt32\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_GetUserStatInt32]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_IndicateAchievementProgress = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_IndicateAchievementProgress(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_IndicateAchievementProgress\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_IndicateAchievementProgress]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_RequestGlobalStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_RequestGlobalStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_RequestGlobalStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_RequestGlobalStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_RequestUserStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_RequestUserStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_RequestUserStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_RequestUserStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_ResetAllStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_ResetAllStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_ResetAllStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_ResetAllStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_SetAchievement = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_SetAchievement(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_SetAchievement\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_SetAchievement]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_SetStatFloat = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_SetStatFloat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_SetStatFloat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_SetStatFloat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_SetStatInt32 = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_SetStatInt32(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_SetStatInt32\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_SetStatInt32]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_StoreStats = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_StoreStats(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_StoreStats\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_StoreStats]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_UpdateAvgRateStat = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_UpdateAvgRateStat(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_UpdateAvgRateStat\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_UpdateAvgRateStat]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUserStats_UploadLeaderboardScore = NULL;
__attribute__((naked)) void SteamAPI_ISteamUserStats_UploadLeaderboardScore(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUserStats_UploadLeaderboardScore\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUserStats_UploadLeaderboardScore]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_AdvertiseGame = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_AdvertiseGame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_AdvertiseGame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_AdvertiseGame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BIsBehindNAT = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BIsBehindNAT(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BIsBehindNAT\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BIsBehindNAT]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BIsPhoneIdentifying = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BIsPhoneIdentifying(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BIsPhoneIdentifying\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BIsPhoneIdentifying]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BIsPhoneRequiringVerification = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BIsPhoneRequiringVerification(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BIsPhoneRequiringVerification\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BIsPhoneRequiringVerification]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BIsPhoneVerified = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BIsPhoneVerified(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BIsPhoneVerified\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BIsPhoneVerified]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BIsTwoFactorEnabled = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BIsTwoFactorEnabled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BIsTwoFactorEnabled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BIsTwoFactorEnabled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BLoggedOn = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BLoggedOn(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BLoggedOn\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BLoggedOn]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BSetDurationControlOnlineState = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BSetDurationControlOnlineState(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BSetDurationControlOnlineState\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BSetDurationControlOnlineState]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_BeginAuthSession = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_BeginAuthSession(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_BeginAuthSession\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_BeginAuthSession]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_CancelAuthTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_CancelAuthTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_CancelAuthTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_CancelAuthTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_DecompressVoice = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_DecompressVoice(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_DecompressVoice\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_DecompressVoice]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_EndAuthSession = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_EndAuthSession(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_EndAuthSession\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_EndAuthSession]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetAuthSessionTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetAuthSessionTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetAuthSessionTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetAuthSessionTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetAuthTicketForWebApi = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetAuthTicketForWebApi(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetAuthTicketForWebApi\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetAuthTicketForWebApi]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetAvailableVoice = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetAvailableVoice(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetAvailableVoice\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetAvailableVoice]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetDurationControl = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetDurationControl(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetDurationControl\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetDurationControl]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetEncryptedAppTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetEncryptedAppTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetEncryptedAppTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetEncryptedAppTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetGameBadgeLevel = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetGameBadgeLevel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetGameBadgeLevel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetGameBadgeLevel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetHSteamUser = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetHSteamUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetHSteamUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetHSteamUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetMarketEligibility = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetMarketEligibility(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetMarketEligibility\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetMarketEligibility]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetPlayerSteamLevel = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetPlayerSteamLevel(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetPlayerSteamLevel\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetPlayerSteamLevel]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetSteamID = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetUserDataFolder = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetUserDataFolder(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetUserDataFolder\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetUserDataFolder]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetVoice = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetVoice(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetVoice\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetVoice]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_GetVoiceOptimalSampleRate = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_GetVoiceOptimalSampleRate\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_GetVoiceOptimalSampleRate]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_RequestEncryptedAppTicket = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_RequestEncryptedAppTicket(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_RequestEncryptedAppTicket\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_RequestEncryptedAppTicket]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_RequestStoreAuthURL = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_RequestStoreAuthURL(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_RequestStoreAuthURL\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_RequestStoreAuthURL]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_StartVoiceRecording = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_StartVoiceRecording(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_StartVoiceRecording\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_StartVoiceRecording]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_StopVoiceRecording = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_StopVoiceRecording(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_StopVoiceRecording\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_StopVoiceRecording]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_TrackAppUsageEvent = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_TrackAppUsageEvent(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_TrackAppUsageEvent\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_TrackAppUsageEvent]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUser_UserHasLicenseForApp = NULL;
__attribute__((naked)) void SteamAPI_ISteamUser_UserHasLicenseForApp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUser_UserHasLicenseForApp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUser_UserHasLicenseForApp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_BOverlayNeedsPresent = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_BOverlayNeedsPresent(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_BOverlayNeedsPresent\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_BOverlayNeedsPresent]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_CheckFileSignature = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_CheckFileSignature(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_CheckFileSignature\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_CheckFileSignature]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_FilterText = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_FilterText(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_FilterText\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_FilterText]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetAPICallFailureReason = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetAPICallFailureReason(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetAPICallFailureReason\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetAPICallFailureReason]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetAPICallResult = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetAPICallResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetAPICallResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetAPICallResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetAppID = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetAppID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetAppID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetAppID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetConnectedUniverse = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetConnectedUniverse(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetConnectedUniverse\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetConnectedUniverse]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetCurrentBatteryPower = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetCurrentBatteryPower(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetCurrentBatteryPower\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetCurrentBatteryPower]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetIPCCallCount = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetIPCCallCount(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetIPCCallCount\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetIPCCallCount]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetIPCountry = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetIPCountry(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetIPCountry\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetIPCountry]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetIPv6ConnectivityState = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetIPv6ConnectivityState(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetIPv6ConnectivityState\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetIPv6ConnectivityState]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetImageRGBA = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetImageRGBA(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetImageRGBA\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetImageRGBA]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetImageSize = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetImageSize(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetImageSize\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetImageSize]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetSecondsSinceAppActive = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetSecondsSinceAppActive(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetSecondsSinceAppActive\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetSecondsSinceAppActive]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetSecondsSinceComputerActive = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetSecondsSinceComputerActive\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetSecondsSinceComputerActive]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetServerRealTime = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetServerRealTime(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetServerRealTime\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetServerRealTime]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_GetSteamUILanguage = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_GetSteamUILanguage(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_GetSteamUILanguage\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_GetSteamUILanguage]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_InitFilterText = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_InitFilterText(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_InitFilterText\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_InitFilterText]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsAPICallCompleted = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsAPICallCompleted(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsAPICallCompleted\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsAPICallCompleted]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsOverlayEnabled = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsOverlayEnabled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsOverlayEnabled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsOverlayEnabled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsSteamChinaLauncher = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsSteamChinaLauncher(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsSteamChinaLauncher\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsSteamChinaLauncher]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsSteamInBigPictureMode = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsSteamInBigPictureMode(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsSteamInBigPictureMode\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsSteamInBigPictureMode]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsSteamRunningInVR = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsSteamRunningInVR(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsSteamRunningInVR\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsSteamRunningInVR]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_SetGameLauncherMode = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_SetGameLauncherMode(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_SetGameLauncherMode\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_SetGameLauncherMode]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_SetOverlayNotificationInset = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_SetOverlayNotificationInset(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_SetOverlayNotificationInset\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_SetOverlayNotificationInset]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_SetOverlayNotificationPosition = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_SetOverlayNotificationPosition(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_SetOverlayNotificationPosition\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_SetOverlayNotificationPosition]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_SetWarningMessageHook = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_SetWarningMessageHook(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_SetWarningMessageHook\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_SetWarningMessageHook]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamUtils_StartVRDashboard = NULL;
__attribute__((naked)) void SteamAPI_ISteamUtils_StartVRDashboard(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamUtils_StartVRDashboard\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamUtils_StartVRDashboard]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamVideo_GetOPFSettings = NULL;
__attribute__((naked)) void SteamAPI_ISteamVideo_GetOPFSettings(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamVideo_GetOPFSettings\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamVideo_GetOPFSettings]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamVideo_GetOPFStringForApp = NULL;
__attribute__((naked)) void SteamAPI_ISteamVideo_GetOPFStringForApp(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamVideo_GetOPFStringForApp\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamVideo_GetOPFStringForApp]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamVideo_GetVideoURL = NULL;
__attribute__((naked)) void SteamAPI_ISteamVideo_GetVideoURL(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamVideo_GetVideoURL\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamVideo_GetVideoURL]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ISteamVideo_IsBroadcasting = NULL;
__attribute__((naked)) void SteamAPI_ISteamVideo_IsBroadcasting(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ISteamVideo_IsBroadcasting\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ISteamVideo_IsBroadcasting]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ManualDispatch_FreeLastCallback = NULL;
__attribute__((naked)) void SteamAPI_ManualDispatch_FreeLastCallback(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ManualDispatch_FreeLastCallback\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ManualDispatch_FreeLastCallback]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ManualDispatch_GetAPICallResult = NULL;
__attribute__((naked)) void __tramp_SteamAPI_ManualDispatch_GetAPICallResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ManualDispatch_GetAPICallResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ManualDispatch_GetAPICallResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ManualDispatch_GetNextCallback = NULL;
__attribute__((naked)) void __tramp_SteamAPI_ManualDispatch_GetNextCallback(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ManualDispatch_GetNextCallback\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ManualDispatch_GetNextCallback]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ManualDispatch_Init = NULL;
__attribute__((naked)) void SteamAPI_ManualDispatch_Init(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ManualDispatch_Init\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ManualDispatch_Init]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ManualDispatch_RunFrame = NULL;
__attribute__((naked)) void SteamAPI_ManualDispatch_RunFrame(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ManualDispatch_RunFrame\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ManualDispatch_RunFrame]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_RegisterCallResult = NULL;
__attribute__((naked)) void SteamAPI_RegisterCallResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_RegisterCallResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_RegisterCallResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_RegisterCallback = NULL;
__attribute__((naked)) void SteamAPI_RegisterCallback(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_RegisterCallback\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_RegisterCallback]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_ReleaseCurrentThreadMemory = NULL;
__attribute__((naked)) void SteamAPI_ReleaseCurrentThreadMemory(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_ReleaseCurrentThreadMemory\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_ReleaseCurrentThreadMemory]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_RunCallbacks = NULL;
__attribute__((naked)) void SteamAPI_RunCallbacks(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_RunCallbacks\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_RunCallbacks]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SetBreakpadAppID = NULL;
__attribute__((naked)) void SteamAPI_SetBreakpadAppID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SetBreakpadAppID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SetBreakpadAppID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SetMiniDumpComment = NULL;
__attribute__((naked)) void SteamAPI_SetMiniDumpComment(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SetMiniDumpComment\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SetMiniDumpComment]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SetTryCatchCallbacks = NULL;
__attribute__((naked)) void SteamAPI_SetTryCatchCallbacks(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SetTryCatchCallbacks\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SetTryCatchCallbacks]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_Shutdown = NULL;
__attribute__((naked)) void SteamAPI_Shutdown(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_Shutdown\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_Shutdown]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_Clear = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_Clear(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_Clear\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_Clear]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_GetFakeIPType = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_GetFakeIPType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_GetFakeIPType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_GetFakeIPType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_GetIPv4 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_GetIPv4(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_GetIPv4\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_GetIPv4]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_IsEqualTo = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_IsEqualTo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_IsEqualTo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_IsEqualTo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_IsFakeIP = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_IsFakeIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_IsFakeIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_IsFakeIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_IsIPv4 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_IsIPv4(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_IsIPv4\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_IsIPv4]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_IsLocalHost = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_IsLocalHost(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_IsLocalHost\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_IsLocalHost]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_ParseString = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_ParseString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_ParseString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_ParseString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_SetIPv4 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_SetIPv4(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_SetIPv4\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_SetIPv4]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_SetIPv6 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_SetIPv6(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_SetIPv6\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_SetIPv6]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIPAddr_ToString = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIPAddr_ToString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIPAddr_ToString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIPAddr_ToString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_Clear = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_Clear(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_Clear\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_Clear]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetFakeIPType = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetFakeIPType(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetFakeIPType\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetFakeIPType]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetGenericBytes = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetGenericBytes(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetGenericBytes\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetGenericBytes]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetGenericString = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetGenericString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetGenericString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetGenericString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetIPAddr = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetIPAddr(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetIPAddr\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetIPAddr]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetIPv4 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetIPv4(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetIPv4\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetIPv4]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetPSNID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetPSNID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetPSNID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetPSNID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetStadiaID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetStadiaID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetStadiaID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetStadiaID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetSteamID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetSteamID64 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetSteamID64(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetSteamID64\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetSteamID64]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_IsEqualTo = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_IsEqualTo(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_IsEqualTo\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_IsEqualTo]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_IsFakeIP = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_IsFakeIP(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_IsFakeIP\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_IsFakeIP]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_IsInvalid = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_IsInvalid(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_IsInvalid\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_IsInvalid]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_IsLocalHost = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_IsLocalHost(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_IsLocalHost\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_IsLocalHost]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_ParseString = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_ParseString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_ParseString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_ParseString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetGenericBytes = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetGenericBytes(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetGenericBytes\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetGenericBytes]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetGenericString = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetGenericString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetGenericString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetGenericString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetIPAddr = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetIPAddr(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetIPAddr\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetIPAddr]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetIPv4Addr = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetIPv4Addr(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetIPv4Addr\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetIPv4Addr]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetLocalHost = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetLocalHost(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetLocalHost\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetLocalHost]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetPSNID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetPSNID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetPSNID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetPSNID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetStadiaID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetStadiaID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetStadiaID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetStadiaID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetSteamID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetSteamID64 = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetSteamID64(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetSteamID64\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetSteamID64]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingIdentity_ToString = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingIdentity_ToString(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingIdentity_ToString\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingIdentity_ToString]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_SteamNetworkingMessage_t_Release = NULL;
__attribute__((naked)) void SteamAPI_SteamNetworkingMessage_t_Release(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_SteamNetworkingMessage_t_Release\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_SteamNetworkingMessage_t_Release]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_UnregisterCallResult = NULL;
__attribute__((naked)) void SteamAPI_UnregisterCallResult(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_UnregisterCallResult\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_UnregisterCallResult]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_UnregisterCallback = NULL;
__attribute__((naked)) void SteamAPI_UnregisterCallback(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_UnregisterCallback\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_UnregisterCallback]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_UseBreakpadCrashHandler = NULL;
__attribute__((naked)) void SteamAPI_UseBreakpadCrashHandler(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_UseBreakpadCrashHandler\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_UseBreakpadCrashHandler]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamAPI_WriteMiniDump = NULL;
__attribute__((naked)) void SteamAPI_WriteMiniDump(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamAPI_WriteMiniDump\n"
        "ldr x16, [x16, :got_lo12:p_SteamAPI_WriteMiniDump]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamClient = NULL;
__attribute__((naked)) void SteamClient(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamClient\n"
        "ldr x16, [x16, :got_lo12:p_SteamClient]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServerClient = NULL;
__attribute__((naked)) void SteamGameServerClient(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServerClient\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServerClient]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_BSecure = NULL;
__attribute__((naked)) void SteamGameServer_BSecure(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_BSecure\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_BSecure]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_GetHSteamPipe = NULL;
__attribute__((naked)) void SteamGameServer_GetHSteamPipe(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_GetHSteamPipe\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_GetHSteamPipe]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_GetHSteamUser = NULL;
__attribute__((naked)) void SteamGameServer_GetHSteamUser(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_GetHSteamUser\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_GetHSteamUser]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_GetSteamID = NULL;
__attribute__((naked)) void SteamGameServer_GetSteamID(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_GetSteamID\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_GetSteamID]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_ReleaseCurrentThreadMemory = NULL;
__attribute__((naked)) void SteamGameServer_ReleaseCurrentThreadMemory(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_ReleaseCurrentThreadMemory\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_ReleaseCurrentThreadMemory]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_RunCallbacks = NULL;
__attribute__((naked)) void SteamGameServer_RunCallbacks(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_RunCallbacks\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_RunCallbacks]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamGameServer_Shutdown = NULL;
__attribute__((naked)) void SteamGameServer_Shutdown(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamGameServer_Shutdown\n"
        "ldr x16, [x16, :got_lo12:p_SteamGameServer_Shutdown]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamInternal_ContextInit = NULL;
__attribute__((naked)) void SteamInternal_ContextInit(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamInternal_ContextInit\n"
        "ldr x16, [x16, :got_lo12:p_SteamInternal_ContextInit]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void *p_SteamInternal_GameServer_Init_V2 = NULL;
__attribute__((naked)) void SteamInternal_GameServer_Init_V2(void) {
    __asm__ volatile(
        "adrp x16, :got:p_SteamInternal_GameServer_Init_V2\n"
        "ldr x16, [x16, :got_lo12:p_SteamInternal_GameServer_Init_V2]\n"
        "ldr x16, [x16]\n"
        "cbz x16, 1f\n"
        "br x16\n"
        "1:\n"
        "mov x0, #0\n"
        "ret\n"
    );
}

void init_all_trampolines(void *h) {
    if (!h) return;
    p_SteamAPI_GetHSteamPipe = dlsym(h, "SteamAPI_GetHSteamPipe");
    p_SteamAPI_GetHSteamUser = dlsym(h, "SteamAPI_GetHSteamUser");
    p_SteamAPI_GetSteamInstallPath = dlsym(h, "SteamAPI_GetSteamInstallPath");
    p_SteamAPI_ISteamApps_BGetDLCDataByIndex = dlsym(h, "SteamAPI_ISteamApps_BGetDLCDataByIndex");
    p_SteamAPI_ISteamApps_BIsAppInstalled = dlsym(h, "SteamAPI_ISteamApps_BIsAppInstalled");
    p_SteamAPI_ISteamApps_BIsCybercafe = dlsym(h, "SteamAPI_ISteamApps_BIsCybercafe");
    p_SteamAPI_ISteamApps_BIsDlcInstalled = dlsym(h, "SteamAPI_ISteamApps_BIsDlcInstalled");
    p_SteamAPI_ISteamApps_BIsLowViolence = dlsym(h, "SteamAPI_ISteamApps_BIsLowViolence");
    p_SteamAPI_ISteamApps_BIsSubscribed = dlsym(h, "SteamAPI_ISteamApps_BIsSubscribed");
    p_SteamAPI_ISteamApps_BIsSubscribedApp = dlsym(h, "SteamAPI_ISteamApps_BIsSubscribedApp");
    p_SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing = dlsym(h, "SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing");
    p_SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend = dlsym(h, "SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend");
    p_SteamAPI_ISteamApps_BIsTimedTrial = dlsym(h, "SteamAPI_ISteamApps_BIsTimedTrial");
    p_SteamAPI_ISteamApps_BIsVACBanned = dlsym(h, "SteamAPI_ISteamApps_BIsVACBanned");
    p_SteamAPI_ISteamApps_GetAppBuildId = dlsym(h, "SteamAPI_ISteamApps_GetAppBuildId");
    p_SteamAPI_ISteamApps_GetAppInstallDir = dlsym(h, "SteamAPI_ISteamApps_GetAppInstallDir");
    p_SteamAPI_ISteamApps_GetAppOwner = dlsym(h, "SteamAPI_ISteamApps_GetAppOwner");
    p_SteamAPI_ISteamApps_GetAvailableGameLanguages = dlsym(h, "SteamAPI_ISteamApps_GetAvailableGameLanguages");
    p_SteamAPI_ISteamApps_GetBetaInfo = dlsym(h, "SteamAPI_ISteamApps_GetBetaInfo");
    p_SteamAPI_ISteamApps_GetCurrentBetaName = dlsym(h, "SteamAPI_ISteamApps_GetCurrentBetaName");
    p_SteamAPI_ISteamApps_GetCurrentGameLanguage = dlsym(h, "SteamAPI_ISteamApps_GetCurrentGameLanguage");
    p_SteamAPI_ISteamApps_GetDLCCount = dlsym(h, "SteamAPI_ISteamApps_GetDLCCount");
    p_SteamAPI_ISteamApps_GetDlcDownloadProgress = dlsym(h, "SteamAPI_ISteamApps_GetDlcDownloadProgress");
    p_SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime = dlsym(h, "SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime");
    p_SteamAPI_ISteamApps_GetFileDetails = dlsym(h, "SteamAPI_ISteamApps_GetFileDetails");
    p_SteamAPI_ISteamApps_GetInstalledDepots = dlsym(h, "SteamAPI_ISteamApps_GetInstalledDepots");
    p_SteamAPI_ISteamApps_GetLaunchCommandLine = dlsym(h, "SteamAPI_ISteamApps_GetLaunchCommandLine");
    p_SteamAPI_ISteamApps_GetLaunchQueryParam = dlsym(h, "SteamAPI_ISteamApps_GetLaunchQueryParam");
    p_SteamAPI_ISteamApps_GetNumBetas = dlsym(h, "SteamAPI_ISteamApps_GetNumBetas");
    p_SteamAPI_ISteamApps_InstallDLC = dlsym(h, "SteamAPI_ISteamApps_InstallDLC");
    p_SteamAPI_ISteamApps_MarkContentCorrupt = dlsym(h, "SteamAPI_ISteamApps_MarkContentCorrupt");
    p_SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys = dlsym(h, "SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys");
    p_SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey = dlsym(h, "SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey");
    p_SteamAPI_ISteamApps_SetActiveBeta = dlsym(h, "SteamAPI_ISteamApps_SetActiveBeta");
    p_SteamAPI_ISteamApps_SetDlcContext = dlsym(h, "SteamAPI_ISteamApps_SetDlcContext");
    p_SteamAPI_ISteamApps_UninstallDLC = dlsym(h, "SteamAPI_ISteamApps_UninstallDLC");
    p_SteamAPI_ISteamClient_BReleaseSteamPipe = dlsym(h, "SteamAPI_ISteamClient_BReleaseSteamPipe");
    p_SteamAPI_ISteamClient_BShutdownIfAllPipesClosed = dlsym(h, "SteamAPI_ISteamClient_BShutdownIfAllPipesClosed");
    p_SteamAPI_ISteamClient_ConnectToGlobalUser = dlsym(h, "SteamAPI_ISteamClient_ConnectToGlobalUser");
    p_SteamAPI_ISteamClient_CreateLocalUser = dlsym(h, "SteamAPI_ISteamClient_CreateLocalUser");
    p_SteamAPI_ISteamClient_CreateSteamPipe = dlsym(h, "SteamAPI_ISteamClient_CreateSteamPipe");
    p_SteamAPI_ISteamClient_ReleaseUser = dlsym(h, "SteamAPI_ISteamClient_ReleaseUser");
    p_SteamAPI_ISteamClient_SetLocalIPBinding = dlsym(h, "SteamAPI_ISteamClient_SetLocalIPBinding");
    p_SteamAPI_ISteamClient_SetWarningMessageHook = dlsym(h, "SteamAPI_ISteamClient_SetWarningMessageHook");
    p_SteamAPI_ISteamFriends_ActivateGameOverlay = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlay");
    p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog");
    p_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString");
    p_SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog");
    p_SteamAPI_ISteamFriends_ActivateGameOverlayToStore = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlayToStore");
    p_SteamAPI_ISteamFriends_ActivateGameOverlayToUser = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlayToUser");
    p_SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage = dlsym(h, "SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage");
    p_SteamAPI_ISteamFriends_BHasEquippedProfileItem = dlsym(h, "SteamAPI_ISteamFriends_BHasEquippedProfileItem");
    p_SteamAPI_ISteamFriends_ClearRichPresence = dlsym(h, "SteamAPI_ISteamFriends_ClearRichPresence");
    p_SteamAPI_ISteamFriends_CloseClanChatWindowInSteam = dlsym(h, "SteamAPI_ISteamFriends_CloseClanChatWindowInSteam");
    p_SteamAPI_ISteamFriends_DownloadClanActivityCounts = dlsym(h, "SteamAPI_ISteamFriends_DownloadClanActivityCounts");
    p_SteamAPI_ISteamFriends_EnumerateFollowingList = dlsym(h, "SteamAPI_ISteamFriends_EnumerateFollowingList");
    p_SteamAPI_ISteamFriends_GetChatMemberByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetChatMemberByIndex");
    p_SteamAPI_ISteamFriends_GetClanActivityCounts = dlsym(h, "SteamAPI_ISteamFriends_GetClanActivityCounts");
    p_SteamAPI_ISteamFriends_GetClanByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetClanByIndex");
    p_SteamAPI_ISteamFriends_GetClanChatMemberCount = dlsym(h, "SteamAPI_ISteamFriends_GetClanChatMemberCount");
    p_SteamAPI_ISteamFriends_GetClanChatMessage = dlsym(h, "SteamAPI_ISteamFriends_GetClanChatMessage");
    p_SteamAPI_ISteamFriends_GetClanCount = dlsym(h, "SteamAPI_ISteamFriends_GetClanCount");
    p_SteamAPI_ISteamFriends_GetClanName = dlsym(h, "SteamAPI_ISteamFriends_GetClanName");
    p_SteamAPI_ISteamFriends_GetClanOfficerByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetClanOfficerByIndex");
    p_SteamAPI_ISteamFriends_GetClanOfficerCount = dlsym(h, "SteamAPI_ISteamFriends_GetClanOfficerCount");
    p_SteamAPI_ISteamFriends_GetClanOwner = dlsym(h, "SteamAPI_ISteamFriends_GetClanOwner");
    p_SteamAPI_ISteamFriends_GetClanTag = dlsym(h, "SteamAPI_ISteamFriends_GetClanTag");
    p_SteamAPI_ISteamFriends_GetCoplayFriend = dlsym(h, "SteamAPI_ISteamFriends_GetCoplayFriend");
    p_SteamAPI_ISteamFriends_GetCoplayFriendCount = dlsym(h, "SteamAPI_ISteamFriends_GetCoplayFriendCount");
    p_SteamAPI_ISteamFriends_GetFollowerCount = dlsym(h, "SteamAPI_ISteamFriends_GetFollowerCount");
    p_SteamAPI_ISteamFriends_GetFriendByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetFriendByIndex");
    p_SteamAPI_ISteamFriends_GetFriendCoplayGame = dlsym(h, "SteamAPI_ISteamFriends_GetFriendCoplayGame");
    p_SteamAPI_ISteamFriends_GetFriendCoplayTime = dlsym(h, "SteamAPI_ISteamFriends_GetFriendCoplayTime");
    p_SteamAPI_ISteamFriends_GetFriendCount = dlsym(h, "SteamAPI_ISteamFriends_GetFriendCount");
    p_SteamAPI_ISteamFriends_GetFriendCountFromSource = dlsym(h, "SteamAPI_ISteamFriends_GetFriendCountFromSource");
    p_SteamAPI_ISteamFriends_GetFriendFromSourceByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetFriendFromSourceByIndex");
    p_SteamAPI_ISteamFriends_GetFriendGamePlayed = dlsym(h, "SteamAPI_ISteamFriends_GetFriendGamePlayed");
    p_SteamAPI_ISteamFriends_GetFriendMessage = dlsym(h, "SteamAPI_ISteamFriends_GetFriendMessage");
    p_SteamAPI_ISteamFriends_GetFriendPersonaName = dlsym(h, "SteamAPI_ISteamFriends_GetFriendPersonaName");
    p_SteamAPI_ISteamFriends_GetFriendPersonaNameHistory = dlsym(h, "SteamAPI_ISteamFriends_GetFriendPersonaNameHistory");
    p_SteamAPI_ISteamFriends_GetFriendPersonaState = dlsym(h, "SteamAPI_ISteamFriends_GetFriendPersonaState");
    p_SteamAPI_ISteamFriends_GetFriendRelationship = dlsym(h, "SteamAPI_ISteamFriends_GetFriendRelationship");
    p_SteamAPI_ISteamFriends_GetFriendRichPresence = dlsym(h, "SteamAPI_ISteamFriends_GetFriendRichPresence");
    p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex");
    p_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount = dlsym(h, "SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount");
    p_SteamAPI_ISteamFriends_GetFriendSteamLevel = dlsym(h, "SteamAPI_ISteamFriends_GetFriendSteamLevel");
    p_SteamAPI_ISteamFriends_GetFriendsGroupCount = dlsym(h, "SteamAPI_ISteamFriends_GetFriendsGroupCount");
    p_SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex = dlsym(h, "SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex");
    p_SteamAPI_ISteamFriends_GetFriendsGroupMembersCount = dlsym(h, "SteamAPI_ISteamFriends_GetFriendsGroupMembersCount");
    p_SteamAPI_ISteamFriends_GetFriendsGroupMembersList = dlsym(h, "SteamAPI_ISteamFriends_GetFriendsGroupMembersList");
    p_SteamAPI_ISteamFriends_GetFriendsGroupName = dlsym(h, "SteamAPI_ISteamFriends_GetFriendsGroupName");
    p_SteamAPI_ISteamFriends_GetLargeFriendAvatar = dlsym(h, "SteamAPI_ISteamFriends_GetLargeFriendAvatar");
    p_SteamAPI_ISteamFriends_GetMediumFriendAvatar = dlsym(h, "SteamAPI_ISteamFriends_GetMediumFriendAvatar");
    p_SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages = dlsym(h, "SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages");
    p_SteamAPI_ISteamFriends_GetPersonaName = dlsym(h, "SteamAPI_ISteamFriends_GetPersonaName");
    p_SteamAPI_ISteamFriends_GetPersonaState = dlsym(h, "SteamAPI_ISteamFriends_GetPersonaState");
    p_SteamAPI_ISteamFriends_GetPlayerNickname = dlsym(h, "SteamAPI_ISteamFriends_GetPlayerNickname");
    p_SteamAPI_ISteamFriends_GetProfileItemPropertyString = dlsym(h, "SteamAPI_ISteamFriends_GetProfileItemPropertyString");
    p_SteamAPI_ISteamFriends_GetProfileItemPropertyUint = dlsym(h, "SteamAPI_ISteamFriends_GetProfileItemPropertyUint");
    p_SteamAPI_ISteamFriends_GetSmallFriendAvatar = dlsym(h, "SteamAPI_ISteamFriends_GetSmallFriendAvatar");
    p_SteamAPI_ISteamFriends_GetUserRestrictions = dlsym(h, "SteamAPI_ISteamFriends_GetUserRestrictions");
    p_SteamAPI_ISteamFriends_HasFriend = dlsym(h, "SteamAPI_ISteamFriends_HasFriend");
    p_SteamAPI_ISteamFriends_InviteUserToGame = dlsym(h, "SteamAPI_ISteamFriends_InviteUserToGame");
    p_SteamAPI_ISteamFriends_IsClanChatAdmin = dlsym(h, "SteamAPI_ISteamFriends_IsClanChatAdmin");
    p_SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam = dlsym(h, "SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam");
    p_SteamAPI_ISteamFriends_IsClanOfficialGameGroup = dlsym(h, "SteamAPI_ISteamFriends_IsClanOfficialGameGroup");
    p_SteamAPI_ISteamFriends_IsClanPublic = dlsym(h, "SteamAPI_ISteamFriends_IsClanPublic");
    p_SteamAPI_ISteamFriends_IsFollowing = dlsym(h, "SteamAPI_ISteamFriends_IsFollowing");
    p_SteamAPI_ISteamFriends_IsUserInSource = dlsym(h, "SteamAPI_ISteamFriends_IsUserInSource");
    p_SteamAPI_ISteamFriends_JoinClanChatRoom = dlsym(h, "SteamAPI_ISteamFriends_JoinClanChatRoom");
    p_SteamAPI_ISteamFriends_LeaveClanChatRoom = dlsym(h, "SteamAPI_ISteamFriends_LeaveClanChatRoom");
    p_SteamAPI_ISteamFriends_OpenClanChatWindowInSteam = dlsym(h, "SteamAPI_ISteamFriends_OpenClanChatWindowInSteam");
    p_SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser = dlsym(h, "SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser");
    p_SteamAPI_ISteamFriends_ReplyToFriendMessage = dlsym(h, "SteamAPI_ISteamFriends_ReplyToFriendMessage");
    p_SteamAPI_ISteamFriends_RequestClanOfficerList = dlsym(h, "SteamAPI_ISteamFriends_RequestClanOfficerList");
    p_SteamAPI_ISteamFriends_RequestEquippedProfileItems = dlsym(h, "SteamAPI_ISteamFriends_RequestEquippedProfileItems");
    p_SteamAPI_ISteamFriends_RequestFriendRichPresence = dlsym(h, "SteamAPI_ISteamFriends_RequestFriendRichPresence");
    p_SteamAPI_ISteamFriends_RequestUserInformation = dlsym(h, "SteamAPI_ISteamFriends_RequestUserInformation");
    p_SteamAPI_ISteamFriends_SendClanChatMessage = dlsym(h, "SteamAPI_ISteamFriends_SendClanChatMessage");
    p_SteamAPI_ISteamFriends_SetInGameVoiceSpeaking = dlsym(h, "SteamAPI_ISteamFriends_SetInGameVoiceSpeaking");
    p_SteamAPI_ISteamFriends_SetListenForFriendsMessages = dlsym(h, "SteamAPI_ISteamFriends_SetListenForFriendsMessages");
    p_SteamAPI_ISteamFriends_SetPersonaName = dlsym(h, "SteamAPI_ISteamFriends_SetPersonaName");
    p_SteamAPI_ISteamFriends_SetPlayedWith = dlsym(h, "SteamAPI_ISteamFriends_SetPlayedWith");
    p_SteamAPI_ISteamFriends_SetRichPresence = dlsym(h, "SteamAPI_ISteamFriends_SetRichPresence");
    p_SteamAPI_ISteamGameSearch_AcceptGame = dlsym(h, "SteamAPI_ISteamGameSearch_AcceptGame");
    p_SteamAPI_ISteamGameSearch_AddGameSearchParams = dlsym(h, "SteamAPI_ISteamGameSearch_AddGameSearchParams");
    p_SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame = dlsym(h, "SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame");
    p_SteamAPI_ISteamGameSearch_DeclineGame = dlsym(h, "SteamAPI_ISteamGameSearch_DeclineGame");
    p_SteamAPI_ISteamGameSearch_EndGame = dlsym(h, "SteamAPI_ISteamGameSearch_EndGame");
    p_SteamAPI_ISteamGameSearch_EndGameSearch = dlsym(h, "SteamAPI_ISteamGameSearch_EndGameSearch");
    p_SteamAPI_ISteamGameSearch_HostConfirmGameStart = dlsym(h, "SteamAPI_ISteamGameSearch_HostConfirmGameStart");
    p_SteamAPI_ISteamGameSearch_RequestPlayersForGame = dlsym(h, "SteamAPI_ISteamGameSearch_RequestPlayersForGame");
    p_SteamAPI_ISteamGameSearch_RetrieveConnectionDetails = dlsym(h, "SteamAPI_ISteamGameSearch_RetrieveConnectionDetails");
    p_SteamAPI_ISteamGameSearch_SearchForGameSolo = dlsym(h, "SteamAPI_ISteamGameSearch_SearchForGameSolo");
    p_SteamAPI_ISteamGameSearch_SearchForGameWithLobby = dlsym(h, "SteamAPI_ISteamGameSearch_SearchForGameWithLobby");
    p_SteamAPI_ISteamGameSearch_SetConnectionDetails = dlsym(h, "SteamAPI_ISteamGameSearch_SetConnectionDetails");
    p_SteamAPI_ISteamGameSearch_SetGameHostParams = dlsym(h, "SteamAPI_ISteamGameSearch_SetGameHostParams");
    p_SteamAPI_ISteamGameSearch_SubmitPlayerResult = dlsym(h, "SteamAPI_ISteamGameSearch_SubmitPlayerResult");
    p_SteamAPI_ISteamGameServerStats_ClearUserAchievement = dlsym(h, "SteamAPI_ISteamGameServerStats_ClearUserAchievement");
    p_SteamAPI_ISteamGameServerStats_GetUserAchievement = dlsym(h, "SteamAPI_ISteamGameServerStats_GetUserAchievement");
    p_SteamAPI_ISteamGameServerStats_GetUserStatFloat = dlsym(h, "SteamAPI_ISteamGameServerStats_GetUserStatFloat");
    p_SteamAPI_ISteamGameServerStats_GetUserStatInt32 = dlsym(h, "SteamAPI_ISteamGameServerStats_GetUserStatInt32");
    p_SteamAPI_ISteamGameServerStats_RequestUserStats = dlsym(h, "SteamAPI_ISteamGameServerStats_RequestUserStats");
    p_SteamAPI_ISteamGameServerStats_SetUserAchievement = dlsym(h, "SteamAPI_ISteamGameServerStats_SetUserAchievement");
    p_SteamAPI_ISteamGameServerStats_SetUserStatFloat = dlsym(h, "SteamAPI_ISteamGameServerStats_SetUserStatFloat");
    p_SteamAPI_ISteamGameServerStats_SetUserStatInt32 = dlsym(h, "SteamAPI_ISteamGameServerStats_SetUserStatInt32");
    p_SteamAPI_ISteamGameServerStats_StoreUserStats = dlsym(h, "SteamAPI_ISteamGameServerStats_StoreUserStats");
    p_SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat = dlsym(h, "SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat");
    p_SteamAPI_ISteamGameServer_AssociateWithClan = dlsym(h, "SteamAPI_ISteamGameServer_AssociateWithClan");
    p_SteamAPI_ISteamGameServer_BLoggedOn = dlsym(h, "SteamAPI_ISteamGameServer_BLoggedOn");
    p_SteamAPI_ISteamGameServer_BSecure = dlsym(h, "SteamAPI_ISteamGameServer_BSecure");
    p_SteamAPI_ISteamGameServer_BUpdateUserData = dlsym(h, "SteamAPI_ISteamGameServer_BUpdateUserData");
    p_SteamAPI_ISteamGameServer_BeginAuthSession = dlsym(h, "SteamAPI_ISteamGameServer_BeginAuthSession");
    p_SteamAPI_ISteamGameServer_CancelAuthTicket = dlsym(h, "SteamAPI_ISteamGameServer_CancelAuthTicket");
    p_SteamAPI_ISteamGameServer_ClearAllKeyValues = dlsym(h, "SteamAPI_ISteamGameServer_ClearAllKeyValues");
    p_SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility = dlsym(h, "SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility");
    p_SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection = dlsym(h, "SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection");
    p_SteamAPI_ISteamGameServer_EndAuthSession = dlsym(h, "SteamAPI_ISteamGameServer_EndAuthSession");
    p_SteamAPI_ISteamGameServer_GetAuthSessionTicket = dlsym(h, "SteamAPI_ISteamGameServer_GetAuthSessionTicket");
    p_SteamAPI_ISteamGameServer_GetGameplayStats = dlsym(h, "SteamAPI_ISteamGameServer_GetGameplayStats");
    p_SteamAPI_ISteamGameServer_GetNextOutgoingPacket = dlsym(h, "SteamAPI_ISteamGameServer_GetNextOutgoingPacket");
    p_SteamAPI_ISteamGameServer_GetPublicIP = dlsym(h, "SteamAPI_ISteamGameServer_GetPublicIP");
    p_SteamAPI_ISteamGameServer_GetServerReputation = dlsym(h, "SteamAPI_ISteamGameServer_GetServerReputation");
    p_SteamAPI_ISteamGameServer_GetSteamID = dlsym(h, "SteamAPI_ISteamGameServer_GetSteamID");
    p_SteamAPI_ISteamGameServer_HandleIncomingPacket = dlsym(h, "SteamAPI_ISteamGameServer_HandleIncomingPacket");
    p_SteamAPI_ISteamGameServer_LogOff = dlsym(h, "SteamAPI_ISteamGameServer_LogOff");
    p_SteamAPI_ISteamGameServer_LogOn = dlsym(h, "SteamAPI_ISteamGameServer_LogOn");
    p_SteamAPI_ISteamGameServer_LogOnAnonymous = dlsym(h, "SteamAPI_ISteamGameServer_LogOnAnonymous");
    p_SteamAPI_ISteamGameServer_RequestUserGroupStatus = dlsym(h, "SteamAPI_ISteamGameServer_RequestUserGroupStatus");
    p_SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED = dlsym(h, "SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED");
    p_SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED = dlsym(h, "SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED");
    p_SteamAPI_ISteamGameServer_SetAdvertiseServerActive = dlsym(h, "SteamAPI_ISteamGameServer_SetAdvertiseServerActive");
    p_SteamAPI_ISteamGameServer_SetBotPlayerCount = dlsym(h, "SteamAPI_ISteamGameServer_SetBotPlayerCount");
    p_SteamAPI_ISteamGameServer_SetDedicatedServer = dlsym(h, "SteamAPI_ISteamGameServer_SetDedicatedServer");
    p_SteamAPI_ISteamGameServer_SetGameData = dlsym(h, "SteamAPI_ISteamGameServer_SetGameData");
    p_SteamAPI_ISteamGameServer_SetGameDescription = dlsym(h, "SteamAPI_ISteamGameServer_SetGameDescription");
    p_SteamAPI_ISteamGameServer_SetGameTags = dlsym(h, "SteamAPI_ISteamGameServer_SetGameTags");
    p_SteamAPI_ISteamGameServer_SetKeyValue = dlsym(h, "SteamAPI_ISteamGameServer_SetKeyValue");
    p_SteamAPI_ISteamGameServer_SetMapName = dlsym(h, "SteamAPI_ISteamGameServer_SetMapName");
    p_SteamAPI_ISteamGameServer_SetMaxPlayerCount = dlsym(h, "SteamAPI_ISteamGameServer_SetMaxPlayerCount");
    p_SteamAPI_ISteamGameServer_SetModDir = dlsym(h, "SteamAPI_ISteamGameServer_SetModDir");
    p_SteamAPI_ISteamGameServer_SetPasswordProtected = dlsym(h, "SteamAPI_ISteamGameServer_SetPasswordProtected");
    p_SteamAPI_ISteamGameServer_SetProduct = dlsym(h, "SteamAPI_ISteamGameServer_SetProduct");
    p_SteamAPI_ISteamGameServer_SetRegion = dlsym(h, "SteamAPI_ISteamGameServer_SetRegion");
    p_SteamAPI_ISteamGameServer_SetServerName = dlsym(h, "SteamAPI_ISteamGameServer_SetServerName");
    p_SteamAPI_ISteamGameServer_SetSpectatorPort = dlsym(h, "SteamAPI_ISteamGameServer_SetSpectatorPort");
    p_SteamAPI_ISteamGameServer_SetSpectatorServerName = dlsym(h, "SteamAPI_ISteamGameServer_SetSpectatorServerName");
    p_SteamAPI_ISteamGameServer_UserHasLicenseForApp = dlsym(h, "SteamAPI_ISteamGameServer_UserHasLicenseForApp");
    p_SteamAPI_ISteamGameServer_WasRestartRequested = dlsym(h, "SteamAPI_ISteamGameServer_WasRestartRequested");
    p_SteamAPI_ISteamHTMLSurface_AddHeader = dlsym(h, "SteamAPI_ISteamHTMLSurface_AddHeader");
    p_SteamAPI_ISteamHTMLSurface_AllowStartRequest = dlsym(h, "SteamAPI_ISteamHTMLSurface_AllowStartRequest");
    p_SteamAPI_ISteamHTMLSurface_CopyToClipboard = dlsym(h, "SteamAPI_ISteamHTMLSurface_CopyToClipboard");
    p_SteamAPI_ISteamHTMLSurface_CreateBrowser = dlsym(h, "SteamAPI_ISteamHTMLSurface_CreateBrowser");
    p_SteamAPI_ISteamHTMLSurface_ExecuteJavascript = dlsym(h, "SteamAPI_ISteamHTMLSurface_ExecuteJavascript");
    p_SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse = dlsym(h, "SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse");
    p_SteamAPI_ISteamHTMLSurface_Find = dlsym(h, "SteamAPI_ISteamHTMLSurface_Find");
    p_SteamAPI_ISteamHTMLSurface_GetLinkAtPosition = dlsym(h, "SteamAPI_ISteamHTMLSurface_GetLinkAtPosition");
    p_SteamAPI_ISteamHTMLSurface_GoBack = dlsym(h, "SteamAPI_ISteamHTMLSurface_GoBack");
    p_SteamAPI_ISteamHTMLSurface_GoForward = dlsym(h, "SteamAPI_ISteamHTMLSurface_GoForward");
    p_SteamAPI_ISteamHTMLSurface_Init = dlsym(h, "SteamAPI_ISteamHTMLSurface_Init");
    p_SteamAPI_ISteamHTMLSurface_JSDialogResponse = dlsym(h, "SteamAPI_ISteamHTMLSurface_JSDialogResponse");
    p_SteamAPI_ISteamHTMLSurface_KeyChar = dlsym(h, "SteamAPI_ISteamHTMLSurface_KeyChar");
    p_SteamAPI_ISteamHTMLSurface_KeyDown = dlsym(h, "SteamAPI_ISteamHTMLSurface_KeyDown");
    p_SteamAPI_ISteamHTMLSurface_KeyUp = dlsym(h, "SteamAPI_ISteamHTMLSurface_KeyUp");
    p_SteamAPI_ISteamHTMLSurface_LoadURL = dlsym(h, "SteamAPI_ISteamHTMLSurface_LoadURL");
    p_SteamAPI_ISteamHTMLSurface_MouseDoubleClick = dlsym(h, "SteamAPI_ISteamHTMLSurface_MouseDoubleClick");
    p_SteamAPI_ISteamHTMLSurface_MouseDown = dlsym(h, "SteamAPI_ISteamHTMLSurface_MouseDown");
    p_SteamAPI_ISteamHTMLSurface_MouseMove = dlsym(h, "SteamAPI_ISteamHTMLSurface_MouseMove");
    p_SteamAPI_ISteamHTMLSurface_MouseUp = dlsym(h, "SteamAPI_ISteamHTMLSurface_MouseUp");
    p_SteamAPI_ISteamHTMLSurface_MouseWheel = dlsym(h, "SteamAPI_ISteamHTMLSurface_MouseWheel");
    p_SteamAPI_ISteamHTMLSurface_OpenDeveloperTools = dlsym(h, "SteamAPI_ISteamHTMLSurface_OpenDeveloperTools");
    p_SteamAPI_ISteamHTMLSurface_PasteFromClipboard = dlsym(h, "SteamAPI_ISteamHTMLSurface_PasteFromClipboard");
    p_SteamAPI_ISteamHTMLSurface_Reload = dlsym(h, "SteamAPI_ISteamHTMLSurface_Reload");
    p_SteamAPI_ISteamHTMLSurface_RemoveBrowser = dlsym(h, "SteamAPI_ISteamHTMLSurface_RemoveBrowser");
    p_SteamAPI_ISteamHTMLSurface_SetBackgroundMode = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetBackgroundMode");
    p_SteamAPI_ISteamHTMLSurface_SetCookie = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetCookie");
    p_SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor");
    p_SteamAPI_ISteamHTMLSurface_SetHorizontalScroll = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetHorizontalScroll");
    p_SteamAPI_ISteamHTMLSurface_SetKeyFocus = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetKeyFocus");
    p_SteamAPI_ISteamHTMLSurface_SetPageScaleFactor = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetPageScaleFactor");
    p_SteamAPI_ISteamHTMLSurface_SetSize = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetSize");
    p_SteamAPI_ISteamHTMLSurface_SetVerticalScroll = dlsym(h, "SteamAPI_ISteamHTMLSurface_SetVerticalScroll");
    p_SteamAPI_ISteamHTMLSurface_Shutdown = dlsym(h, "SteamAPI_ISteamHTMLSurface_Shutdown");
    p_SteamAPI_ISteamHTMLSurface_StopFind = dlsym(h, "SteamAPI_ISteamHTMLSurface_StopFind");
    p_SteamAPI_ISteamHTMLSurface_StopLoad = dlsym(h, "SteamAPI_ISteamHTMLSurface_StopLoad");
    p_SteamAPI_ISteamHTMLSurface_ViewSource = dlsym(h, "SteamAPI_ISteamHTMLSurface_ViewSource");
    p_SteamAPI_ISteamHTTP_CreateCookieContainer = dlsym(h, "SteamAPI_ISteamHTTP_CreateCookieContainer");
    p_SteamAPI_ISteamHTTP_CreateHTTPRequest = dlsym(h, "SteamAPI_ISteamHTTP_CreateHTTPRequest");
    p_SteamAPI_ISteamHTTP_DeferHTTPRequest = dlsym(h, "SteamAPI_ISteamHTTP_DeferHTTPRequest");
    p_SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct");
    p_SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut");
    p_SteamAPI_ISteamHTTP_GetHTTPResponseBodyData = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPResponseBodyData");
    p_SteamAPI_ISteamHTTP_GetHTTPResponseBodySize = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPResponseBodySize");
    p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize");
    p_SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue");
    p_SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData = dlsym(h, "SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData");
    p_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest = dlsym(h, "SteamAPI_ISteamHTTP_PrioritizeHTTPRequest");
    p_SteamAPI_ISteamHTTP_ReleaseCookieContainer = dlsym(h, "SteamAPI_ISteamHTTP_ReleaseCookieContainer");
    p_SteamAPI_ISteamHTTP_ReleaseHTTPRequest = dlsym(h, "SteamAPI_ISteamHTTP_ReleaseHTTPRequest");
    p_SteamAPI_ISteamHTTP_SendHTTPRequest = dlsym(h, "SteamAPI_ISteamHTTP_SendHTTPRequest");
    p_SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse = dlsym(h, "SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse");
    p_SteamAPI_ISteamHTTP_SetCookie = dlsym(h, "SteamAPI_ISteamHTTP_SetCookie");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestContextValue");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate");
    p_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo = dlsym(h, "SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo");
    p_SteamAPI_ISteamInput_ActivateActionSet = dlsym(h, "SteamAPI_ISteamInput_ActivateActionSet");
    p_SteamAPI_ISteamInput_ActivateActionSetLayer = dlsym(h, "SteamAPI_ISteamInput_ActivateActionSetLayer");
    p_SteamAPI_ISteamInput_BNewDataAvailable = dlsym(h, "SteamAPI_ISteamInput_BNewDataAvailable");
    p_SteamAPI_ISteamInput_BWaitForData = dlsym(h, "SteamAPI_ISteamInput_BWaitForData");
    p_SteamAPI_ISteamInput_DeactivateActionSetLayer = dlsym(h, "SteamAPI_ISteamInput_DeactivateActionSetLayer");
    p_SteamAPI_ISteamInput_DeactivateAllActionSetLayers = dlsym(h, "SteamAPI_ISteamInput_DeactivateAllActionSetLayers");
    p_SteamAPI_ISteamInput_EnableActionEventCallbacks = dlsym(h, "SteamAPI_ISteamInput_EnableActionEventCallbacks");
    p_SteamAPI_ISteamInput_EnableDeviceCallbacks = dlsym(h, "SteamAPI_ISteamInput_EnableDeviceCallbacks");
    p_SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin = dlsym(h, "SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin");
    p_SteamAPI_ISteamInput_GetActionSetHandle = dlsym(h, "SteamAPI_ISteamInput_GetActionSetHandle");
    p_SteamAPI_ISteamInput_GetActiveActionSetLayers = dlsym(h, "SteamAPI_ISteamInput_GetActiveActionSetLayers");
    p_SteamAPI_ISteamInput_GetAnalogActionData = dlsym(h, "SteamAPI_ISteamInput_GetAnalogActionData");
    p_SteamAPI_ISteamInput_GetAnalogActionHandle = dlsym(h, "SteamAPI_ISteamInput_GetAnalogActionHandle");
    p_SteamAPI_ISteamInput_GetAnalogActionOrigins = dlsym(h, "SteamAPI_ISteamInput_GetAnalogActionOrigins");
    p_SteamAPI_ISteamInput_GetConnectedControllers = dlsym(h, "SteamAPI_ISteamInput_GetConnectedControllers");
    p_SteamAPI_ISteamInput_GetControllerForGamepadIndex = dlsym(h, "SteamAPI_ISteamInput_GetControllerForGamepadIndex");
    p_SteamAPI_ISteamInput_GetCurrentActionSet = dlsym(h, "SteamAPI_ISteamInput_GetCurrentActionSet");
    p_SteamAPI_ISteamInput_GetDeviceBindingRevision = dlsym(h, "SteamAPI_ISteamInput_GetDeviceBindingRevision");
    p_SteamAPI_ISteamInput_GetDigitalActionData = dlsym(h, "SteamAPI_ISteamInput_GetDigitalActionData");
    p_SteamAPI_ISteamInput_GetDigitalActionHandle = dlsym(h, "SteamAPI_ISteamInput_GetDigitalActionHandle");
    p_SteamAPI_ISteamInput_GetDigitalActionOrigins = dlsym(h, "SteamAPI_ISteamInput_GetDigitalActionOrigins");
    p_SteamAPI_ISteamInput_GetGamepadIndexForController = dlsym(h, "SteamAPI_ISteamInput_GetGamepadIndexForController");
    p_SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy = dlsym(h, "SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy");
    p_SteamAPI_ISteamInput_GetGlyphForXboxOrigin = dlsym(h, "SteamAPI_ISteamInput_GetGlyphForXboxOrigin");
    p_SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin = dlsym(h, "SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin");
    p_SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin = dlsym(h, "SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin");
    p_SteamAPI_ISteamInput_GetInputTypeForHandle = dlsym(h, "SteamAPI_ISteamInput_GetInputTypeForHandle");
    p_SteamAPI_ISteamInput_GetMotionData = dlsym(h, "SteamAPI_ISteamInput_GetMotionData");
    p_SteamAPI_ISteamInput_GetRemotePlaySessionID = dlsym(h, "SteamAPI_ISteamInput_GetRemotePlaySessionID");
    p_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings = dlsym(h, "SteamAPI_ISteamInput_GetSessionInputConfigurationSettings");
    p_SteamAPI_ISteamInput_GetStringForActionOrigin = dlsym(h, "SteamAPI_ISteamInput_GetStringForActionOrigin");
    p_SteamAPI_ISteamInput_GetStringForAnalogActionName = dlsym(h, "SteamAPI_ISteamInput_GetStringForAnalogActionName");
    p_SteamAPI_ISteamInput_GetStringForDigitalActionName = dlsym(h, "SteamAPI_ISteamInput_GetStringForDigitalActionName");
    p_SteamAPI_ISteamInput_GetStringForXboxOrigin = dlsym(h, "SteamAPI_ISteamInput_GetStringForXboxOrigin");
    p_SteamAPI_ISteamInput_Init = dlsym(h, "SteamAPI_ISteamInput_Init");
    p_SteamAPI_ISteamInput_Legacy_TriggerHapticPulse = dlsym(h, "SteamAPI_ISteamInput_Legacy_TriggerHapticPulse");
    p_SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse = dlsym(h, "SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse");
    p_SteamAPI_ISteamInput_RunFrame = dlsym(h, "SteamAPI_ISteamInput_RunFrame");
    p_SteamAPI_ISteamInput_SetDualSenseTriggerEffect = dlsym(h, "SteamAPI_ISteamInput_SetDualSenseTriggerEffect");
    p_SteamAPI_ISteamInput_SetInputActionManifestFilePath = dlsym(h, "SteamAPI_ISteamInput_SetInputActionManifestFilePath");
    p_SteamAPI_ISteamInput_SetLEDColor = dlsym(h, "SteamAPI_ISteamInput_SetLEDColor");
    p_SteamAPI_ISteamInput_ShowBindingPanel = dlsym(h, "SteamAPI_ISteamInput_ShowBindingPanel");
    p_SteamAPI_ISteamInput_Shutdown = dlsym(h, "SteamAPI_ISteamInput_Shutdown");
    p_SteamAPI_ISteamInput_StopAnalogActionMomentum = dlsym(h, "SteamAPI_ISteamInput_StopAnalogActionMomentum");
    p_SteamAPI_ISteamInput_TranslateActionOrigin = dlsym(h, "SteamAPI_ISteamInput_TranslateActionOrigin");
    p_SteamAPI_ISteamInput_TriggerSimpleHapticEvent = dlsym(h, "SteamAPI_ISteamInput_TriggerSimpleHapticEvent");
    p_SteamAPI_ISteamInput_TriggerVibration = dlsym(h, "SteamAPI_ISteamInput_TriggerVibration");
    p_SteamAPI_ISteamInput_TriggerVibrationExtended = dlsym(h, "SteamAPI_ISteamInput_TriggerVibrationExtended");
    p_SteamAPI_ISteamInventory_AddPromoItem = dlsym(h, "SteamAPI_ISteamInventory_AddPromoItem");
    p_SteamAPI_ISteamInventory_AddPromoItems = dlsym(h, "SteamAPI_ISteamInventory_AddPromoItems");
    p_SteamAPI_ISteamInventory_CheckResultSteamID = dlsym(h, "SteamAPI_ISteamInventory_CheckResultSteamID");
    p_SteamAPI_ISteamInventory_ConsumeItem = dlsym(h, "SteamAPI_ISteamInventory_ConsumeItem");
    p_SteamAPI_ISteamInventory_DeserializeResult = dlsym(h, "SteamAPI_ISteamInventory_DeserializeResult");
    p_SteamAPI_ISteamInventory_DestroyResult = dlsym(h, "SteamAPI_ISteamInventory_DestroyResult");
    p_SteamAPI_ISteamInventory_ExchangeItems = dlsym(h, "SteamAPI_ISteamInventory_ExchangeItems");
    p_SteamAPI_ISteamInventory_GenerateItems = dlsym(h, "SteamAPI_ISteamInventory_GenerateItems");
    p_SteamAPI_ISteamInventory_GetAllItems = dlsym(h, "SteamAPI_ISteamInventory_GetAllItems");
    p_SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs = dlsym(h, "SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs");
    p_SteamAPI_ISteamInventory_GetItemDefinitionIDs = dlsym(h, "SteamAPI_ISteamInventory_GetItemDefinitionIDs");
    p_SteamAPI_ISteamInventory_GetItemDefinitionProperty = dlsym(h, "SteamAPI_ISteamInventory_GetItemDefinitionProperty");
    p_SteamAPI_ISteamInventory_GetItemPrice = dlsym(h, "SteamAPI_ISteamInventory_GetItemPrice");
    p_SteamAPI_ISteamInventory_GetItemsByID = dlsym(h, "SteamAPI_ISteamInventory_GetItemsByID");
    p_SteamAPI_ISteamInventory_GetItemsWithPrices = dlsym(h, "SteamAPI_ISteamInventory_GetItemsWithPrices");
    p_SteamAPI_ISteamInventory_GetNumItemsWithPrices = dlsym(h, "SteamAPI_ISteamInventory_GetNumItemsWithPrices");
    p_SteamAPI_ISteamInventory_GetResultItemProperty = dlsym(h, "SteamAPI_ISteamInventory_GetResultItemProperty");
    p_SteamAPI_ISteamInventory_GetResultItems = dlsym(h, "SteamAPI_ISteamInventory_GetResultItems");
    p_SteamAPI_ISteamInventory_GetResultStatus = dlsym(h, "SteamAPI_ISteamInventory_GetResultStatus");
    p_SteamAPI_ISteamInventory_GetResultTimestamp = dlsym(h, "SteamAPI_ISteamInventory_GetResultTimestamp");
    p_SteamAPI_ISteamInventory_GrantPromoItems = dlsym(h, "SteamAPI_ISteamInventory_GrantPromoItems");
    p_SteamAPI_ISteamInventory_InspectItem = dlsym(h, "SteamAPI_ISteamInventory_InspectItem");
    p_SteamAPI_ISteamInventory_LoadItemDefinitions = dlsym(h, "SteamAPI_ISteamInventory_LoadItemDefinitions");
    p_SteamAPI_ISteamInventory_RemoveProperty = dlsym(h, "SteamAPI_ISteamInventory_RemoveProperty");
    p_SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs = dlsym(h, "SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs");
    p_SteamAPI_ISteamInventory_RequestPrices = dlsym(h, "SteamAPI_ISteamInventory_RequestPrices");
    p_SteamAPI_ISteamInventory_SendItemDropHeartbeat = dlsym(h, "SteamAPI_ISteamInventory_SendItemDropHeartbeat");
    p_SteamAPI_ISteamInventory_SerializeResult = dlsym(h, "SteamAPI_ISteamInventory_SerializeResult");
    p_SteamAPI_ISteamInventory_SetPropertyBool = dlsym(h, "SteamAPI_ISteamInventory_SetPropertyBool");
    p_SteamAPI_ISteamInventory_SetPropertyFloat = dlsym(h, "SteamAPI_ISteamInventory_SetPropertyFloat");
    p_SteamAPI_ISteamInventory_SetPropertyInt64 = dlsym(h, "SteamAPI_ISteamInventory_SetPropertyInt64");
    p_SteamAPI_ISteamInventory_SetPropertyString = dlsym(h, "SteamAPI_ISteamInventory_SetPropertyString");
    p_SteamAPI_ISteamInventory_StartPurchase = dlsym(h, "SteamAPI_ISteamInventory_StartPurchase");
    p_SteamAPI_ISteamInventory_StartUpdateProperties = dlsym(h, "SteamAPI_ISteamInventory_StartUpdateProperties");
    p_SteamAPI_ISteamInventory_SubmitUpdateProperties = dlsym(h, "SteamAPI_ISteamInventory_SubmitUpdateProperties");
    p_SteamAPI_ISteamInventory_TradeItems = dlsym(h, "SteamAPI_ISteamInventory_TradeItems");
    p_SteamAPI_ISteamInventory_TransferItemQuantity = dlsym(h, "SteamAPI_ISteamInventory_TransferItemQuantity");
    p_SteamAPI_ISteamInventory_TriggerItemDrop = dlsym(h, "SteamAPI_ISteamInventory_TriggerItemDrop");
    p_SteamAPI_ISteamMatchmakingServers_CancelQuery = dlsym(h, "SteamAPI_ISteamMatchmakingServers_CancelQuery");
    p_SteamAPI_ISteamMatchmakingServers_CancelServerQuery = dlsym(h, "SteamAPI_ISteamMatchmakingServers_CancelServerQuery");
    p_SteamAPI_ISteamMatchmakingServers_GetServerCount = dlsym(h, "SteamAPI_ISteamMatchmakingServers_GetServerCount");
    p_SteamAPI_ISteamMatchmakingServers_GetServerDetails = dlsym(h, "SteamAPI_ISteamMatchmakingServers_GetServerDetails");
    p_SteamAPI_ISteamMatchmakingServers_IsRefreshing = dlsym(h, "SteamAPI_ISteamMatchmakingServers_IsRefreshing");
    p_SteamAPI_ISteamMatchmakingServers_PingServer = dlsym(h, "SteamAPI_ISteamMatchmakingServers_PingServer");
    p_SteamAPI_ISteamMatchmakingServers_PlayerDetails = dlsym(h, "SteamAPI_ISteamMatchmakingServers_PlayerDetails");
    p_SteamAPI_ISteamMatchmakingServers_RefreshQuery = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RefreshQuery");
    p_SteamAPI_ISteamMatchmakingServers_RefreshServer = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RefreshServer");
    p_SteamAPI_ISteamMatchmakingServers_ReleaseRequest = dlsym(h, "SteamAPI_ISteamMatchmakingServers_ReleaseRequest");
    p_SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList");
    p_SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList");
    p_SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList");
    p_SteamAPI_ISteamMatchmakingServers_RequestInternetServerList = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RequestInternetServerList");
    p_SteamAPI_ISteamMatchmakingServers_RequestLANServerList = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RequestLANServerList");
    p_SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList = dlsym(h, "SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList");
    p_SteamAPI_ISteamMatchmakingServers_ServerRules = dlsym(h, "SteamAPI_ISteamMatchmakingServers_ServerRules");
    p_SteamAPI_ISteamMatchmaking_AddFavoriteGame = dlsym(h, "SteamAPI_ISteamMatchmaking_AddFavoriteGame");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter");
    p_SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter = dlsym(h, "SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter");
    p_SteamAPI_ISteamMatchmaking_CreateLobby = dlsym(h, "SteamAPI_ISteamMatchmaking_CreateLobby");
    p_SteamAPI_ISteamMatchmaking_DeleteLobbyData = dlsym(h, "SteamAPI_ISteamMatchmaking_DeleteLobbyData");
    p_SteamAPI_ISteamMatchmaking_GetFavoriteGame = dlsym(h, "SteamAPI_ISteamMatchmaking_GetFavoriteGame");
    p_SteamAPI_ISteamMatchmaking_GetFavoriteGameCount = dlsym(h, "SteamAPI_ISteamMatchmaking_GetFavoriteGameCount");
    p_SteamAPI_ISteamMatchmaking_GetLobbyByIndex = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyByIndex");
    p_SteamAPI_ISteamMatchmaking_GetLobbyChatEntry = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyChatEntry");
    p_SteamAPI_ISteamMatchmaking_GetLobbyData = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyData");
    p_SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex");
    p_SteamAPI_ISteamMatchmaking_GetLobbyDataCount = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyDataCount");
    p_SteamAPI_ISteamMatchmaking_GetLobbyGameServer = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyGameServer");
    p_SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex");
    p_SteamAPI_ISteamMatchmaking_GetLobbyMemberData = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyMemberData");
    p_SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit");
    p_SteamAPI_ISteamMatchmaking_GetLobbyOwner = dlsym(h, "SteamAPI_ISteamMatchmaking_GetLobbyOwner");
    p_SteamAPI_ISteamMatchmaking_GetNumLobbyMembers = dlsym(h, "SteamAPI_ISteamMatchmaking_GetNumLobbyMembers");
    p_SteamAPI_ISteamMatchmaking_InviteUserToLobby = dlsym(h, "SteamAPI_ISteamMatchmaking_InviteUserToLobby");
    p_SteamAPI_ISteamMatchmaking_JoinLobby = dlsym(h, "SteamAPI_ISteamMatchmaking_JoinLobby");
    p_SteamAPI_ISteamMatchmaking_LeaveLobby = dlsym(h, "SteamAPI_ISteamMatchmaking_LeaveLobby");
    p_SteamAPI_ISteamMatchmaking_RemoveFavoriteGame = dlsym(h, "SteamAPI_ISteamMatchmaking_RemoveFavoriteGame");
    p_SteamAPI_ISteamMatchmaking_RequestLobbyData = dlsym(h, "SteamAPI_ISteamMatchmaking_RequestLobbyData");
    p_SteamAPI_ISteamMatchmaking_RequestLobbyList = dlsym(h, "SteamAPI_ISteamMatchmaking_RequestLobbyList");
    p_SteamAPI_ISteamMatchmaking_SendLobbyChatMsg = dlsym(h, "SteamAPI_ISteamMatchmaking_SendLobbyChatMsg");
    p_SteamAPI_ISteamMatchmaking_SetLinkedLobby = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLinkedLobby");
    p_SteamAPI_ISteamMatchmaking_SetLobbyData = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyData");
    p_SteamAPI_ISteamMatchmaking_SetLobbyGameServer = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyGameServer");
    p_SteamAPI_ISteamMatchmaking_SetLobbyJoinable = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyJoinable");
    p_SteamAPI_ISteamMatchmaking_SetLobbyMemberData = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyMemberData");
    p_SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit");
    p_SteamAPI_ISteamMatchmaking_SetLobbyOwner = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyOwner");
    p_SteamAPI_ISteamMatchmaking_SetLobbyType = dlsym(h, "SteamAPI_ISteamMatchmaking_SetLobbyType");
    p_SteamAPI_ISteamMusicRemote_BActivationSuccess = dlsym(h, "SteamAPI_ISteamMusicRemote_BActivationSuccess");
    p_SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote = dlsym(h, "SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote");
    p_SteamAPI_ISteamMusicRemote_CurrentEntryDidChange = dlsym(h, "SteamAPI_ISteamMusicRemote_CurrentEntryDidChange");
    p_SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable = dlsym(h, "SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable");
    p_SteamAPI_ISteamMusicRemote_CurrentEntryWillChange = dlsym(h, "SteamAPI_ISteamMusicRemote_CurrentEntryWillChange");
    p_SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote = dlsym(h, "SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote");
    p_SteamAPI_ISteamMusicRemote_EnableLooped = dlsym(h, "SteamAPI_ISteamMusicRemote_EnableLooped");
    p_SteamAPI_ISteamMusicRemote_EnablePlayNext = dlsym(h, "SteamAPI_ISteamMusicRemote_EnablePlayNext");
    p_SteamAPI_ISteamMusicRemote_EnablePlayPrevious = dlsym(h, "SteamAPI_ISteamMusicRemote_EnablePlayPrevious");
    p_SteamAPI_ISteamMusicRemote_EnablePlaylists = dlsym(h, "SteamAPI_ISteamMusicRemote_EnablePlaylists");
    p_SteamAPI_ISteamMusicRemote_EnableQueue = dlsym(h, "SteamAPI_ISteamMusicRemote_EnableQueue");
    p_SteamAPI_ISteamMusicRemote_EnableShuffled = dlsym(h, "SteamAPI_ISteamMusicRemote_EnableShuffled");
    p_SteamAPI_ISteamMusicRemote_PlaylistDidChange = dlsym(h, "SteamAPI_ISteamMusicRemote_PlaylistDidChange");
    p_SteamAPI_ISteamMusicRemote_PlaylistWillChange = dlsym(h, "SteamAPI_ISteamMusicRemote_PlaylistWillChange");
    p_SteamAPI_ISteamMusicRemote_QueueDidChange = dlsym(h, "SteamAPI_ISteamMusicRemote_QueueDidChange");
    p_SteamAPI_ISteamMusicRemote_QueueWillChange = dlsym(h, "SteamAPI_ISteamMusicRemote_QueueWillChange");
    p_SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote = dlsym(h, "SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote");
    p_SteamAPI_ISteamMusicRemote_ResetPlaylistEntries = dlsym(h, "SteamAPI_ISteamMusicRemote_ResetPlaylistEntries");
    p_SteamAPI_ISteamMusicRemote_ResetQueueEntries = dlsym(h, "SteamAPI_ISteamMusicRemote_ResetQueueEntries");
    p_SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry = dlsym(h, "SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry");
    p_SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry = dlsym(h, "SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry");
    p_SteamAPI_ISteamMusicRemote_SetDisplayName = dlsym(h, "SteamAPI_ISteamMusicRemote_SetDisplayName");
    p_SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64 = dlsym(h, "SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64");
    p_SteamAPI_ISteamMusicRemote_SetPlaylistEntry = dlsym(h, "SteamAPI_ISteamMusicRemote_SetPlaylistEntry");
    p_SteamAPI_ISteamMusicRemote_SetQueueEntry = dlsym(h, "SteamAPI_ISteamMusicRemote_SetQueueEntry");
    p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt");
    p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds");
    p_SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText");
    p_SteamAPI_ISteamMusicRemote_UpdateLooped = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdateLooped");
    p_SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus");
    p_SteamAPI_ISteamMusicRemote_UpdateShuffled = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdateShuffled");
    p_SteamAPI_ISteamMusicRemote_UpdateVolume = dlsym(h, "SteamAPI_ISteamMusicRemote_UpdateVolume");
    p_SteamAPI_ISteamMusic_BIsEnabled = dlsym(h, "SteamAPI_ISteamMusic_BIsEnabled");
    p_SteamAPI_ISteamMusic_BIsPlaying = dlsym(h, "SteamAPI_ISteamMusic_BIsPlaying");
    p_SteamAPI_ISteamMusic_GetPlaybackStatus = dlsym(h, "SteamAPI_ISteamMusic_GetPlaybackStatus");
    p_SteamAPI_ISteamMusic_GetVolume = dlsym(h, "SteamAPI_ISteamMusic_GetVolume");
    p_SteamAPI_ISteamMusic_Pause = dlsym(h, "SteamAPI_ISteamMusic_Pause");
    p_SteamAPI_ISteamMusic_Play = dlsym(h, "SteamAPI_ISteamMusic_Play");
    p_SteamAPI_ISteamMusic_PlayNext = dlsym(h, "SteamAPI_ISteamMusic_PlayNext");
    p_SteamAPI_ISteamMusic_PlayPrevious = dlsym(h, "SteamAPI_ISteamMusic_PlayPrevious");
    p_SteamAPI_ISteamMusic_SetVolume = dlsym(h, "SteamAPI_ISteamMusic_SetVolume");
    p_SteamAPI_ISteamNetworkingConnectionSignaling_Release = dlsym(h, "SteamAPI_ISteamNetworkingConnectionSignaling_Release");
    p_SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal = dlsym(h, "SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal");
    p_SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser = dlsym(h, "SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser");
    p_SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser = dlsym(h, "SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser");
    p_SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser = dlsym(h, "SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser");
    p_SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo = dlsym(h, "SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo");
    p_SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel = dlsym(h, "SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel");
    p_SteamAPI_ISteamNetworkingMessages_SendMessageToUser = dlsym(h, "SteamAPI_ISteamNetworkingMessages_SendMessageToUser");
    p_SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest = dlsym(h, "SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest");
    p_SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal = dlsym(h, "SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal");
    p_SteamAPI_ISteamNetworkingSockets_AcceptConnection = dlsym(h, "SteamAPI_ISteamNetworkingSockets_AcceptConnection");
    p_SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP = dlsym(h, "SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP");
    p_SteamAPI_ISteamNetworkingSockets_CloseConnection = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CloseConnection");
    p_SteamAPI_ISteamNetworkingSockets_CloseListenSocket = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CloseListenSocket");
    p_SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes");
    p_SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress");
    p_SteamAPI_ISteamNetworkingSockets_ConnectP2P = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ConnectP2P");
    p_SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling");
    p_SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer");
    p_SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort");
    p_SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket");
    p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP");
    p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P");
    p_SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP");
    p_SteamAPI_ISteamNetworkingSockets_CreatePollGroup = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreatePollGroup");
    p_SteamAPI_ISteamNetworkingSockets_CreateSocketPair = dlsym(h, "SteamAPI_ISteamNetworkingSockets_CreateSocketPair");
    p_SteamAPI_ISteamNetworkingSockets_DestroyPollGroup = dlsym(h, "SteamAPI_ISteamNetworkingSockets_DestroyPollGroup");
    p_SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer = dlsym(h, "SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer");
    p_SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection = dlsym(h, "SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection");
    p_SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus");
    p_SteamAPI_ISteamNetworkingSockets_GetCertificateRequest = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetCertificateRequest");
    p_SteamAPI_ISteamNetworkingSockets_GetConnectionInfo = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetConnectionInfo");
    p_SteamAPI_ISteamNetworkingSockets_GetConnectionName = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetConnectionName");
    p_SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus");
    p_SteamAPI_ISteamNetworkingSockets_GetConnectionUserData = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetConnectionUserData");
    p_SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus");
    p_SteamAPI_ISteamNetworkingSockets_GetFakeIP = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetFakeIP");
    p_SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin");
    p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress");
    p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID");
    p_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort");
    p_SteamAPI_ISteamNetworkingSockets_GetIdentity = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetIdentity");
    p_SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress");
    p_SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection = dlsym(h, "SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection");
    p_SteamAPI_ISteamNetworkingSockets_InitAuthentication = dlsym(h, "SteamAPI_ISteamNetworkingSockets_InitAuthentication");
    p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection");
    p_SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup");
    p_SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal");
    p_SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket");
    p_SteamAPI_ISteamNetworkingSockets_ResetIdentity = dlsym(h, "SteamAPI_ISteamNetworkingSockets_ResetIdentity");
    p_SteamAPI_ISteamNetworkingSockets_RunCallbacks = dlsym(h, "SteamAPI_ISteamNetworkingSockets_RunCallbacks");
    p_SteamAPI_ISteamNetworkingSockets_SendMessageToConnection = dlsym(h, "SteamAPI_ISteamNetworkingSockets_SendMessageToConnection");
    p_SteamAPI_ISteamNetworkingSockets_SendMessages = dlsym(h, "SteamAPI_ISteamNetworkingSockets_SendMessages");
    p_SteamAPI_ISteamNetworkingSockets_SetCertificate = dlsym(h, "SteamAPI_ISteamNetworkingSockets_SetCertificate");
    p_SteamAPI_ISteamNetworkingSockets_SetConnectionName = dlsym(h, "SteamAPI_ISteamNetworkingSockets_SetConnectionName");
    p_SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup = dlsym(h, "SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup");
    p_SteamAPI_ISteamNetworkingSockets_SetConnectionUserData = dlsym(h, "SteamAPI_ISteamNetworkingSockets_SetConnectionUserData");
    p_SteamAPI_ISteamNetworkingUtils_AllocateMessage = dlsym(h, "SteamAPI_ISteamNetworkingUtils_AllocateMessage");
    p_SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate = dlsym(h, "SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate");
    p_SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString = dlsym(h, "SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString");
    p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations = dlsym(h, "SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations");
    p_SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost = dlsym(h, "SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost");
    p_SteamAPI_ISteamNetworkingUtils_GetConfigValue = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetConfigValue");
    p_SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo");
    p_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP");
    p_SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType");
    p_SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation");
    p_SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp");
    p_SteamAPI_ISteamNetworkingUtils_GetPOPCount = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetPOPCount");
    p_SteamAPI_ISteamNetworkingUtils_GetPOPList = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetPOPList");
    p_SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter");
    p_SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP");
    p_SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus = dlsym(h, "SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus");
    p_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess = dlsym(h, "SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess");
    p_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4 = dlsym(h, "SteamAPI_ISteamNetworkingUtils_IsFakeIPv4");
    p_SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues = dlsym(h, "SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues");
    p_SteamAPI_ISteamNetworkingUtils_ParsePingLocationString = dlsym(h, "SteamAPI_ISteamNetworkingUtils_ParsePingLocationString");
    p_SteamAPI_ISteamNetworkingUtils_SetConfigValue = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SetConfigValue");
    p_SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction");
    p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType");
    p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString");
    p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString");
    p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString");
    p_SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString = dlsym(h, "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString");
    p_SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser = dlsym(h, "SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser");
    p_SteamAPI_ISteamNetworking_AllowP2PPacketRelay = dlsym(h, "SteamAPI_ISteamNetworking_AllowP2PPacketRelay");
    p_SteamAPI_ISteamNetworking_CloseP2PChannelWithUser = dlsym(h, "SteamAPI_ISteamNetworking_CloseP2PChannelWithUser");
    p_SteamAPI_ISteamNetworking_CloseP2PSessionWithUser = dlsym(h, "SteamAPI_ISteamNetworking_CloseP2PSessionWithUser");
    p_SteamAPI_ISteamNetworking_CreateConnectionSocket = dlsym(h, "SteamAPI_ISteamNetworking_CreateConnectionSocket");
    p_SteamAPI_ISteamNetworking_CreateListenSocket = dlsym(h, "SteamAPI_ISteamNetworking_CreateListenSocket");
    p_SteamAPI_ISteamNetworking_CreateP2PConnectionSocket = dlsym(h, "SteamAPI_ISteamNetworking_CreateP2PConnectionSocket");
    p_SteamAPI_ISteamNetworking_DestroyListenSocket = dlsym(h, "SteamAPI_ISteamNetworking_DestroyListenSocket");
    p_SteamAPI_ISteamNetworking_DestroySocket = dlsym(h, "SteamAPI_ISteamNetworking_DestroySocket");
    p_SteamAPI_ISteamNetworking_GetListenSocketInfo = dlsym(h, "SteamAPI_ISteamNetworking_GetListenSocketInfo");
    p_SteamAPI_ISteamNetworking_GetMaxPacketSize = dlsym(h, "SteamAPI_ISteamNetworking_GetMaxPacketSize");
    p_SteamAPI_ISteamNetworking_GetP2PSessionState = dlsym(h, "SteamAPI_ISteamNetworking_GetP2PSessionState");
    p_SteamAPI_ISteamNetworking_GetSocketConnectionType = dlsym(h, "SteamAPI_ISteamNetworking_GetSocketConnectionType");
    p_SteamAPI_ISteamNetworking_GetSocketInfo = dlsym(h, "SteamAPI_ISteamNetworking_GetSocketInfo");
    p_SteamAPI_ISteamNetworking_IsDataAvailable = dlsym(h, "SteamAPI_ISteamNetworking_IsDataAvailable");
    p_SteamAPI_ISteamNetworking_IsDataAvailableOnSocket = dlsym(h, "SteamAPI_ISteamNetworking_IsDataAvailableOnSocket");
    p_SteamAPI_ISteamNetworking_IsP2PPacketAvailable = dlsym(h, "SteamAPI_ISteamNetworking_IsP2PPacketAvailable");
    p_SteamAPI_ISteamNetworking_ReadP2PPacket = dlsym(h, "SteamAPI_ISteamNetworking_ReadP2PPacket");
    p_SteamAPI_ISteamNetworking_RetrieveData = dlsym(h, "SteamAPI_ISteamNetworking_RetrieveData");
    p_SteamAPI_ISteamNetworking_RetrieveDataFromSocket = dlsym(h, "SteamAPI_ISteamNetworking_RetrieveDataFromSocket");
    p_SteamAPI_ISteamNetworking_SendDataOnSocket = dlsym(h, "SteamAPI_ISteamNetworking_SendDataOnSocket");
    p_SteamAPI_ISteamNetworking_SendP2PPacket = dlsym(h, "SteamAPI_ISteamNetworking_SendP2PPacket");
    p_SteamAPI_ISteamParentalSettings_BIsAppBlocked = dlsym(h, "SteamAPI_ISteamParentalSettings_BIsAppBlocked");
    p_SteamAPI_ISteamParentalSettings_BIsAppInBlockList = dlsym(h, "SteamAPI_ISteamParentalSettings_BIsAppInBlockList");
    p_SteamAPI_ISteamParentalSettings_BIsFeatureBlocked = dlsym(h, "SteamAPI_ISteamParentalSettings_BIsFeatureBlocked");
    p_SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList = dlsym(h, "SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList");
    p_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled = dlsym(h, "SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled");
    p_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked = dlsym(h, "SteamAPI_ISteamParentalSettings_BIsParentalLockLocked");
    p_SteamAPI_ISteamParties_CancelReservation = dlsym(h, "SteamAPI_ISteamParties_CancelReservation");
    p_SteamAPI_ISteamParties_ChangeNumOpenSlots = dlsym(h, "SteamAPI_ISteamParties_ChangeNumOpenSlots");
    p_SteamAPI_ISteamParties_CreateBeacon = dlsym(h, "SteamAPI_ISteamParties_CreateBeacon");
    p_SteamAPI_ISteamParties_DestroyBeacon = dlsym(h, "SteamAPI_ISteamParties_DestroyBeacon");
    p_SteamAPI_ISteamParties_GetAvailableBeaconLocations = dlsym(h, "SteamAPI_ISteamParties_GetAvailableBeaconLocations");
    p_SteamAPI_ISteamParties_GetBeaconByIndex = dlsym(h, "SteamAPI_ISteamParties_GetBeaconByIndex");
    p_SteamAPI_ISteamParties_GetBeaconDetails = dlsym(h, "SteamAPI_ISteamParties_GetBeaconDetails");
    p_SteamAPI_ISteamParties_GetBeaconLocationData = dlsym(h, "SteamAPI_ISteamParties_GetBeaconLocationData");
    p_SteamAPI_ISteamParties_GetNumActiveBeacons = dlsym(h, "SteamAPI_ISteamParties_GetNumActiveBeacons");
    p_SteamAPI_ISteamParties_GetNumAvailableBeaconLocations = dlsym(h, "SteamAPI_ISteamParties_GetNumAvailableBeaconLocations");
    p_SteamAPI_ISteamParties_JoinParty = dlsym(h, "SteamAPI_ISteamParties_JoinParty");
    p_SteamAPI_ISteamParties_OnReservationCompleted = dlsym(h, "SteamAPI_ISteamParties_OnReservationCompleted");
    p_SteamAPI_ISteamRemotePlay_BGetSessionClientResolution = dlsym(h, "SteamAPI_ISteamRemotePlay_BGetSessionClientResolution");
    p_SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite = dlsym(h, "SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite");
    p_SteamAPI_ISteamRemotePlay_BStartRemotePlayTogether = dlsym(h, "SteamAPI_ISteamRemotePlay_BStartRemotePlayTogether");
    p_SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor = dlsym(h, "SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor");
    p_SteamAPI_ISteamRemotePlay_GetSessionClientName = dlsym(h, "SteamAPI_ISteamRemotePlay_GetSessionClientName");
    p_SteamAPI_ISteamRemotePlay_GetSessionCount = dlsym(h, "SteamAPI_ISteamRemotePlay_GetSessionCount");
    p_SteamAPI_ISteamRemotePlay_GetSessionID = dlsym(h, "SteamAPI_ISteamRemotePlay_GetSessionID");
    p_SteamAPI_ISteamRemotePlay_GetSessionSteamID = dlsym(h, "SteamAPI_ISteamRemotePlay_GetSessionSteamID");
    p_SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch = dlsym(h, "SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch");
    p_SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate = dlsym(h, "SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate");
    p_SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest = dlsym(h, "SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest");
    p_SteamAPI_ISteamRemoteStorage_DeletePublishedFile = dlsym(h, "SteamAPI_ISteamRemoteStorage_DeletePublishedFile");
    p_SteamAPI_ISteamRemoteStorage_EndFileWriteBatch = dlsym(h, "SteamAPI_ISteamRemoteStorage_EndFileWriteBatch");
    p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction = dlsym(h, "SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction");
    p_SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles = dlsym(h, "SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles");
    p_SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles = dlsym(h, "SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles");
    p_SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles = dlsym(h, "SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles");
    p_SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles = dlsym(h, "SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles");
    p_SteamAPI_ISteamRemoteStorage_FileDelete = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileDelete");
    p_SteamAPI_ISteamRemoteStorage_FileExists = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileExists");
    p_SteamAPI_ISteamRemoteStorage_FileForget = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileForget");
    p_SteamAPI_ISteamRemoteStorage_FilePersisted = dlsym(h, "SteamAPI_ISteamRemoteStorage_FilePersisted");
    p_SteamAPI_ISteamRemoteStorage_FileRead = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileRead");
    p_SteamAPI_ISteamRemoteStorage_FileReadAsync = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileReadAsync");
    p_SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete");
    p_SteamAPI_ISteamRemoteStorage_FileShare = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileShare");
    p_SteamAPI_ISteamRemoteStorage_FileWrite = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileWrite");
    p_SteamAPI_ISteamRemoteStorage_FileWriteAsync = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileWriteAsync");
    p_SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel");
    p_SteamAPI_ISteamRemoteStorage_FileWriteStreamClose = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileWriteStreamClose");
    p_SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen");
    p_SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk = dlsym(h, "SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk");
    p_SteamAPI_ISteamRemoteStorage_GetCachedUGCCount = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetCachedUGCCount");
    p_SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle");
    p_SteamAPI_ISteamRemoteStorage_GetFileCount = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetFileCount");
    p_SteamAPI_ISteamRemoteStorage_GetFileNameAndSize = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetFileNameAndSize");
    p_SteamAPI_ISteamRemoteStorage_GetFileSize = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetFileSize");
    p_SteamAPI_ISteamRemoteStorage_GetFileTimestamp = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetFileTimestamp");
    p_SteamAPI_ISteamRemoteStorage_GetLocalFileChange = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetLocalFileChange");
    p_SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount");
    p_SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails");
    p_SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails");
    p_SteamAPI_ISteamRemoteStorage_GetQuota = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetQuota");
    p_SteamAPI_ISteamRemoteStorage_GetSyncPlatforms = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetSyncPlatforms");
    p_SteamAPI_ISteamRemoteStorage_GetUGCDetails = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetUGCDetails");
    p_SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress");
    p_SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails = dlsym(h, "SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails");
    p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount = dlsym(h, "SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount");
    p_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp = dlsym(h, "SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp");
    p_SteamAPI_ISteamRemoteStorage_PublishVideo = dlsym(h, "SteamAPI_ISteamRemoteStorage_PublishVideo");
    p_SteamAPI_ISteamRemoteStorage_PublishWorkshopFile = dlsym(h, "SteamAPI_ISteamRemoteStorage_PublishWorkshopFile");
    p_SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp = dlsym(h, "SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp");
    p_SteamAPI_ISteamRemoteStorage_SetSyncPlatforms = dlsym(h, "SteamAPI_ISteamRemoteStorage_SetSyncPlatforms");
    p_SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction = dlsym(h, "SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction");
    p_SteamAPI_ISteamRemoteStorage_SubscribePublishedFile = dlsym(h, "SteamAPI_ISteamRemoteStorage_SubscribePublishedFile");
    p_SteamAPI_ISteamRemoteStorage_UGCDownload = dlsym(h, "SteamAPI_ISteamRemoteStorage_UGCDownload");
    p_SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation = dlsym(h, "SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation");
    p_SteamAPI_ISteamRemoteStorage_UGCRead = dlsym(h, "SteamAPI_ISteamRemoteStorage_UGCRead");
    p_SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile = dlsym(h, "SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle");
    p_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility");
    p_SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote = dlsym(h, "SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote");
    p_SteamAPI_ISteamScreenshots_AddScreenshotToLibrary = dlsym(h, "SteamAPI_ISteamScreenshots_AddScreenshotToLibrary");
    p_SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary = dlsym(h, "SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary");
    p_SteamAPI_ISteamScreenshots_HookScreenshots = dlsym(h, "SteamAPI_ISteamScreenshots_HookScreenshots");
    p_SteamAPI_ISteamScreenshots_IsScreenshotsHooked = dlsym(h, "SteamAPI_ISteamScreenshots_IsScreenshotsHooked");
    p_SteamAPI_ISteamScreenshots_SetLocation = dlsym(h, "SteamAPI_ISteamScreenshots_SetLocation");
    p_SteamAPI_ISteamScreenshots_TagPublishedFile = dlsym(h, "SteamAPI_ISteamScreenshots_TagPublishedFile");
    p_SteamAPI_ISteamScreenshots_TagUser = dlsym(h, "SteamAPI_ISteamScreenshots_TagUser");
    p_SteamAPI_ISteamScreenshots_TriggerScreenshot = dlsym(h, "SteamAPI_ISteamScreenshots_TriggerScreenshot");
    p_SteamAPI_ISteamScreenshots_WriteScreenshot = dlsym(h, "SteamAPI_ISteamScreenshots_WriteScreenshot");
    p_SteamAPI_ISteamTimeline_AddTimelineEvent = dlsym(h, "SteamAPI_ISteamTimeline_AddTimelineEvent");
    p_SteamAPI_ISteamTimeline_ClearTimelineStateDescription = dlsym(h, "SteamAPI_ISteamTimeline_ClearTimelineStateDescription");
    p_SteamAPI_ISteamTimeline_SetTimelineGameMode = dlsym(h, "SteamAPI_ISteamTimeline_SetTimelineGameMode");
    p_SteamAPI_ISteamTimeline_SetTimelineStateDescription = dlsym(h, "SteamAPI_ISteamTimeline_SetTimelineStateDescription");
    p_SteamAPI_ISteamUGC_AddAppDependency = dlsym(h, "SteamAPI_ISteamUGC_AddAppDependency");
    p_SteamAPI_ISteamUGC_AddContentDescriptor = dlsym(h, "SteamAPI_ISteamUGC_AddContentDescriptor");
    p_SteamAPI_ISteamUGC_AddDependency = dlsym(h, "SteamAPI_ISteamUGC_AddDependency");
    p_SteamAPI_ISteamUGC_AddExcludedTag = dlsym(h, "SteamAPI_ISteamUGC_AddExcludedTag");
    p_SteamAPI_ISteamUGC_AddItemKeyValueTag = dlsym(h, "SteamAPI_ISteamUGC_AddItemKeyValueTag");
    p_SteamAPI_ISteamUGC_AddItemPreviewFile = dlsym(h, "SteamAPI_ISteamUGC_AddItemPreviewFile");
    p_SteamAPI_ISteamUGC_AddItemPreviewVideo = dlsym(h, "SteamAPI_ISteamUGC_AddItemPreviewVideo");
    p_SteamAPI_ISteamUGC_AddItemToFavorites = dlsym(h, "SteamAPI_ISteamUGC_AddItemToFavorites");
    p_SteamAPI_ISteamUGC_AddRequiredKeyValueTag = dlsym(h, "SteamAPI_ISteamUGC_AddRequiredKeyValueTag");
    p_SteamAPI_ISteamUGC_AddRequiredTag = dlsym(h, "SteamAPI_ISteamUGC_AddRequiredTag");
    p_SteamAPI_ISteamUGC_AddRequiredTagGroup = dlsym(h, "SteamAPI_ISteamUGC_AddRequiredTagGroup");
    p_SteamAPI_ISteamUGC_BInitWorkshopForGameServer = dlsym(h, "SteamAPI_ISteamUGC_BInitWorkshopForGameServer");
    p_SteamAPI_ISteamUGC_CreateItem = dlsym(h, "SteamAPI_ISteamUGC_CreateItem");
    p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor = dlsym(h, "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor");
    p_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage = dlsym(h, "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage");
    p_SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest = dlsym(h, "SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest");
    p_SteamAPI_ISteamUGC_CreateQueryUserUGCRequest = dlsym(h, "SteamAPI_ISteamUGC_CreateQueryUserUGCRequest");
    p_SteamAPI_ISteamUGC_DeleteItem = dlsym(h, "SteamAPI_ISteamUGC_DeleteItem");
    p_SteamAPI_ISteamUGC_DownloadItem = dlsym(h, "SteamAPI_ISteamUGC_DownloadItem");
    p_SteamAPI_ISteamUGC_GetAppDependencies = dlsym(h, "SteamAPI_ISteamUGC_GetAppDependencies");
    p_SteamAPI_ISteamUGC_GetItemDownloadInfo = dlsym(h, "SteamAPI_ISteamUGC_GetItemDownloadInfo");
    p_SteamAPI_ISteamUGC_GetItemInstallInfo = dlsym(h, "SteamAPI_ISteamUGC_GetItemInstallInfo");
    p_SteamAPI_ISteamUGC_GetItemState = dlsym(h, "SteamAPI_ISteamUGC_GetItemState");
    p_SteamAPI_ISteamUGC_GetItemUpdateProgress = dlsym(h, "SteamAPI_ISteamUGC_GetItemUpdateProgress");
    p_SteamAPI_ISteamUGC_GetNumSubscribedItems = dlsym(h, "SteamAPI_ISteamUGC_GetNumSubscribedItems");
    p_SteamAPI_ISteamUGC_GetNumSupportedGameVersions = dlsym(h, "SteamAPI_ISteamUGC_GetNumSupportedGameVersions");
    p_SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag = dlsym(h, "SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag");
    p_SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview");
    p_SteamAPI_ISteamUGC_GetQueryUGCChildren = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCChildren");
    p_SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors");
    p_SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag");
    p_SteamAPI_ISteamUGC_GetQueryUGCMetadata = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCMetadata");
    p_SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews");
    p_SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags");
    p_SteamAPI_ISteamUGC_GetQueryUGCNumTags = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCNumTags");
    p_SteamAPI_ISteamUGC_GetQueryUGCPreviewURL = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCPreviewURL");
    p_SteamAPI_ISteamUGC_GetQueryUGCResult = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCResult");
    p_SteamAPI_ISteamUGC_GetQueryUGCStatistic = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCStatistic");
    p_SteamAPI_ISteamUGC_GetQueryUGCTag = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCTag");
    p_SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName = dlsym(h, "SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName");
    p_SteamAPI_ISteamUGC_GetSubscribedItems = dlsym(h, "SteamAPI_ISteamUGC_GetSubscribedItems");
    p_SteamAPI_ISteamUGC_GetSupportedGameVersionData = dlsym(h, "SteamAPI_ISteamUGC_GetSupportedGameVersionData");
    p_SteamAPI_ISteamUGC_GetUserContentDescriptorPreferences = dlsym(h, "SteamAPI_ISteamUGC_GetUserContentDescriptorPreferences");
    p_SteamAPI_ISteamUGC_GetUserItemVote = dlsym(h, "SteamAPI_ISteamUGC_GetUserItemVote");
    p_SteamAPI_ISteamUGC_GetWorkshopEULAStatus = dlsym(h, "SteamAPI_ISteamUGC_GetWorkshopEULAStatus");
    p_SteamAPI_ISteamUGC_ReleaseQueryUGCRequest = dlsym(h, "SteamAPI_ISteamUGC_ReleaseQueryUGCRequest");
    p_SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags = dlsym(h, "SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags");
    p_SteamAPI_ISteamUGC_RemoveAppDependency = dlsym(h, "SteamAPI_ISteamUGC_RemoveAppDependency");
    p_SteamAPI_ISteamUGC_RemoveContentDescriptor = dlsym(h, "SteamAPI_ISteamUGC_RemoveContentDescriptor");
    p_SteamAPI_ISteamUGC_RemoveDependency = dlsym(h, "SteamAPI_ISteamUGC_RemoveDependency");
    p_SteamAPI_ISteamUGC_RemoveItemFromFavorites = dlsym(h, "SteamAPI_ISteamUGC_RemoveItemFromFavorites");
    p_SteamAPI_ISteamUGC_RemoveItemKeyValueTags = dlsym(h, "SteamAPI_ISteamUGC_RemoveItemKeyValueTags");
    p_SteamAPI_ISteamUGC_RemoveItemPreview = dlsym(h, "SteamAPI_ISteamUGC_RemoveItemPreview");
    p_SteamAPI_ISteamUGC_RequestUGCDetails = dlsym(h, "SteamAPI_ISteamUGC_RequestUGCDetails");
    p_SteamAPI_ISteamUGC_SendQueryUGCRequest = dlsym(h, "SteamAPI_ISteamUGC_SendQueryUGCRequest");
    p_SteamAPI_ISteamUGC_SetAdminQuery = dlsym(h, "SteamAPI_ISteamUGC_SetAdminQuery");
    p_SteamAPI_ISteamUGC_SetAllowCachedResponse = dlsym(h, "SteamAPI_ISteamUGC_SetAllowCachedResponse");
    p_SteamAPI_ISteamUGC_SetAllowLegacyUpload = dlsym(h, "SteamAPI_ISteamUGC_SetAllowLegacyUpload");
    p_SteamAPI_ISteamUGC_SetCloudFileNameFilter = dlsym(h, "SteamAPI_ISteamUGC_SetCloudFileNameFilter");
    p_SteamAPI_ISteamUGC_SetItemContent = dlsym(h, "SteamAPI_ISteamUGC_SetItemContent");
    p_SteamAPI_ISteamUGC_SetItemDescription = dlsym(h, "SteamAPI_ISteamUGC_SetItemDescription");
    p_SteamAPI_ISteamUGC_SetItemMetadata = dlsym(h, "SteamAPI_ISteamUGC_SetItemMetadata");
    p_SteamAPI_ISteamUGC_SetItemPreview = dlsym(h, "SteamAPI_ISteamUGC_SetItemPreview");
    p_SteamAPI_ISteamUGC_SetItemTags = dlsym(h, "SteamAPI_ISteamUGC_SetItemTags");
    p_SteamAPI_ISteamUGC_SetItemTitle = dlsym(h, "SteamAPI_ISteamUGC_SetItemTitle");
    p_SteamAPI_ISteamUGC_SetItemUpdateLanguage = dlsym(h, "SteamAPI_ISteamUGC_SetItemUpdateLanguage");
    p_SteamAPI_ISteamUGC_SetItemVisibility = dlsym(h, "SteamAPI_ISteamUGC_SetItemVisibility");
    p_SteamAPI_ISteamUGC_SetLanguage = dlsym(h, "SteamAPI_ISteamUGC_SetLanguage");
    p_SteamAPI_ISteamUGC_SetMatchAnyTag = dlsym(h, "SteamAPI_ISteamUGC_SetMatchAnyTag");
    p_SteamAPI_ISteamUGC_SetRankedByTrendDays = dlsym(h, "SteamAPI_ISteamUGC_SetRankedByTrendDays");
    p_SteamAPI_ISteamUGC_SetRequiredGameVersions = dlsym(h, "SteamAPI_ISteamUGC_SetRequiredGameVersions");
    p_SteamAPI_ISteamUGC_SetReturnAdditionalPreviews = dlsym(h, "SteamAPI_ISteamUGC_SetReturnAdditionalPreviews");
    p_SteamAPI_ISteamUGC_SetReturnChildren = dlsym(h, "SteamAPI_ISteamUGC_SetReturnChildren");
    p_SteamAPI_ISteamUGC_SetReturnKeyValueTags = dlsym(h, "SteamAPI_ISteamUGC_SetReturnKeyValueTags");
    p_SteamAPI_ISteamUGC_SetReturnLongDescription = dlsym(h, "SteamAPI_ISteamUGC_SetReturnLongDescription");
    p_SteamAPI_ISteamUGC_SetReturnMetadata = dlsym(h, "SteamAPI_ISteamUGC_SetReturnMetadata");
    p_SteamAPI_ISteamUGC_SetReturnOnlyIDs = dlsym(h, "SteamAPI_ISteamUGC_SetReturnOnlyIDs");
    p_SteamAPI_ISteamUGC_SetReturnPlaytimeStats = dlsym(h, "SteamAPI_ISteamUGC_SetReturnPlaytimeStats");
    p_SteamAPI_ISteamUGC_SetReturnTotalOnly = dlsym(h, "SteamAPI_ISteamUGC_SetReturnTotalOnly");
    p_SteamAPI_ISteamUGC_SetSearchText = dlsym(h, "SteamAPI_ISteamUGC_SetSearchText");
    p_SteamAPI_ISteamUGC_SetTimeCreatedDateRange = dlsym(h, "SteamAPI_ISteamUGC_SetTimeCreatedDateRange");
    p_SteamAPI_ISteamUGC_SetTimeUpdatedDateRange = dlsym(h, "SteamAPI_ISteamUGC_SetTimeUpdatedDateRange");
    p_SteamAPI_ISteamUGC_SetUserItemVote = dlsym(h, "SteamAPI_ISteamUGC_SetUserItemVote");
    p_SteamAPI_ISteamUGC_ShowWorkshopEULA = dlsym(h, "SteamAPI_ISteamUGC_ShowWorkshopEULA");
    p_SteamAPI_ISteamUGC_StartItemUpdate = dlsym(h, "SteamAPI_ISteamUGC_StartItemUpdate");
    p_SteamAPI_ISteamUGC_StartPlaytimeTracking = dlsym(h, "SteamAPI_ISteamUGC_StartPlaytimeTracking");
    p_SteamAPI_ISteamUGC_StopPlaytimeTracking = dlsym(h, "SteamAPI_ISteamUGC_StopPlaytimeTracking");
    p_SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems = dlsym(h, "SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems");
    p_SteamAPI_ISteamUGC_SubmitItemUpdate = dlsym(h, "SteamAPI_ISteamUGC_SubmitItemUpdate");
    p_SteamAPI_ISteamUGC_SubscribeItem = dlsym(h, "SteamAPI_ISteamUGC_SubscribeItem");
    p_SteamAPI_ISteamUGC_SuspendDownloads = dlsym(h, "SteamAPI_ISteamUGC_SuspendDownloads");
    p_SteamAPI_ISteamUGC_UnsubscribeItem = dlsym(h, "SteamAPI_ISteamUGC_UnsubscribeItem");
    p_SteamAPI_ISteamUGC_UpdateItemPreviewFile = dlsym(h, "SteamAPI_ISteamUGC_UpdateItemPreviewFile");
    p_SteamAPI_ISteamUGC_UpdateItemPreviewVideo = dlsym(h, "SteamAPI_ISteamUGC_UpdateItemPreviewVideo");
    p_SteamAPI_ISteamUserStats_AttachLeaderboardUGC = dlsym(h, "SteamAPI_ISteamUserStats_AttachLeaderboardUGC");
    p_SteamAPI_ISteamUserStats_ClearAchievement = dlsym(h, "SteamAPI_ISteamUserStats_ClearAchievement");
    p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntries = dlsym(h, "SteamAPI_ISteamUserStats_DownloadLeaderboardEntries");
    p_SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers = dlsym(h, "SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers");
    p_SteamAPI_ISteamUserStats_FindLeaderboard = dlsym(h, "SteamAPI_ISteamUserStats_FindLeaderboard");
    p_SteamAPI_ISteamUserStats_FindOrCreateLeaderboard = dlsym(h, "SteamAPI_ISteamUserStats_FindOrCreateLeaderboard");
    p_SteamAPI_ISteamUserStats_GetAchievement = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievement");
    p_SteamAPI_ISteamUserStats_GetAchievementAchievedPercent = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementAchievedPercent");
    p_SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime");
    p_SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute");
    p_SteamAPI_ISteamUserStats_GetAchievementIcon = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementIcon");
    p_SteamAPI_ISteamUserStats_GetAchievementName = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementName");
    p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat");
    p_SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32 = dlsym(h, "SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32");
    p_SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry = dlsym(h, "SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry");
    p_SteamAPI_ISteamUserStats_GetGlobalStatDouble = dlsym(h, "SteamAPI_ISteamUserStats_GetGlobalStatDouble");
    p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble = dlsym(h, "SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble");
    p_SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64 = dlsym(h, "SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64");
    p_SteamAPI_ISteamUserStats_GetGlobalStatInt64 = dlsym(h, "SteamAPI_ISteamUserStats_GetGlobalStatInt64");
    p_SteamAPI_ISteamUserStats_GetLeaderboardDisplayType = dlsym(h, "SteamAPI_ISteamUserStats_GetLeaderboardDisplayType");
    p_SteamAPI_ISteamUserStats_GetLeaderboardEntryCount = dlsym(h, "SteamAPI_ISteamUserStats_GetLeaderboardEntryCount");
    p_SteamAPI_ISteamUserStats_GetLeaderboardName = dlsym(h, "SteamAPI_ISteamUserStats_GetLeaderboardName");
    p_SteamAPI_ISteamUserStats_GetLeaderboardSortMethod = dlsym(h, "SteamAPI_ISteamUserStats_GetLeaderboardSortMethod");
    p_SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo = dlsym(h, "SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo");
    p_SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo = dlsym(h, "SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo");
    p_SteamAPI_ISteamUserStats_GetNumAchievements = dlsym(h, "SteamAPI_ISteamUserStats_GetNumAchievements");
    p_SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers = dlsym(h, "SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers");
    p_SteamAPI_ISteamUserStats_GetStatFloat = dlsym(h, "SteamAPI_ISteamUserStats_GetStatFloat");
    p_SteamAPI_ISteamUserStats_GetStatInt32 = dlsym(h, "SteamAPI_ISteamUserStats_GetStatInt32");
    p_SteamAPI_ISteamUserStats_GetUserAchievement = dlsym(h, "SteamAPI_ISteamUserStats_GetUserAchievement");
    p_SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime = dlsym(h, "SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime");
    p_SteamAPI_ISteamUserStats_GetUserStatFloat = dlsym(h, "SteamAPI_ISteamUserStats_GetUserStatFloat");
    p_SteamAPI_ISteamUserStats_GetUserStatInt32 = dlsym(h, "SteamAPI_ISteamUserStats_GetUserStatInt32");
    p_SteamAPI_ISteamUserStats_IndicateAchievementProgress = dlsym(h, "SteamAPI_ISteamUserStats_IndicateAchievementProgress");
    p_SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages = dlsym(h, "SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages");
    p_SteamAPI_ISteamUserStats_RequestGlobalStats = dlsym(h, "SteamAPI_ISteamUserStats_RequestGlobalStats");
    p_SteamAPI_ISteamUserStats_RequestUserStats = dlsym(h, "SteamAPI_ISteamUserStats_RequestUserStats");
    p_SteamAPI_ISteamUserStats_ResetAllStats = dlsym(h, "SteamAPI_ISteamUserStats_ResetAllStats");
    p_SteamAPI_ISteamUserStats_SetAchievement = dlsym(h, "SteamAPI_ISteamUserStats_SetAchievement");
    p_SteamAPI_ISteamUserStats_SetStatFloat = dlsym(h, "SteamAPI_ISteamUserStats_SetStatFloat");
    p_SteamAPI_ISteamUserStats_SetStatInt32 = dlsym(h, "SteamAPI_ISteamUserStats_SetStatInt32");
    p_SteamAPI_ISteamUserStats_StoreStats = dlsym(h, "SteamAPI_ISteamUserStats_StoreStats");
    p_SteamAPI_ISteamUserStats_UpdateAvgRateStat = dlsym(h, "SteamAPI_ISteamUserStats_UpdateAvgRateStat");
    p_SteamAPI_ISteamUserStats_UploadLeaderboardScore = dlsym(h, "SteamAPI_ISteamUserStats_UploadLeaderboardScore");
    p_SteamAPI_ISteamUser_AdvertiseGame = dlsym(h, "SteamAPI_ISteamUser_AdvertiseGame");
    p_SteamAPI_ISteamUser_BIsBehindNAT = dlsym(h, "SteamAPI_ISteamUser_BIsBehindNAT");
    p_SteamAPI_ISteamUser_BIsPhoneIdentifying = dlsym(h, "SteamAPI_ISteamUser_BIsPhoneIdentifying");
    p_SteamAPI_ISteamUser_BIsPhoneRequiringVerification = dlsym(h, "SteamAPI_ISteamUser_BIsPhoneRequiringVerification");
    p_SteamAPI_ISteamUser_BIsPhoneVerified = dlsym(h, "SteamAPI_ISteamUser_BIsPhoneVerified");
    p_SteamAPI_ISteamUser_BIsTwoFactorEnabled = dlsym(h, "SteamAPI_ISteamUser_BIsTwoFactorEnabled");
    p_SteamAPI_ISteamUser_BLoggedOn = dlsym(h, "SteamAPI_ISteamUser_BLoggedOn");
    p_SteamAPI_ISteamUser_BSetDurationControlOnlineState = dlsym(h, "SteamAPI_ISteamUser_BSetDurationControlOnlineState");
    p_SteamAPI_ISteamUser_BeginAuthSession = dlsym(h, "SteamAPI_ISteamUser_BeginAuthSession");
    p_SteamAPI_ISteamUser_CancelAuthTicket = dlsym(h, "SteamAPI_ISteamUser_CancelAuthTicket");
    p_SteamAPI_ISteamUser_DecompressVoice = dlsym(h, "SteamAPI_ISteamUser_DecompressVoice");
    p_SteamAPI_ISteamUser_EndAuthSession = dlsym(h, "SteamAPI_ISteamUser_EndAuthSession");
    p_SteamAPI_ISteamUser_GetAuthSessionTicket = dlsym(h, "SteamAPI_ISteamUser_GetAuthSessionTicket");
    p_SteamAPI_ISteamUser_GetAuthTicketForWebApi = dlsym(h, "SteamAPI_ISteamUser_GetAuthTicketForWebApi");
    p_SteamAPI_ISteamUser_GetAvailableVoice = dlsym(h, "SteamAPI_ISteamUser_GetAvailableVoice");
    p_SteamAPI_ISteamUser_GetDurationControl = dlsym(h, "SteamAPI_ISteamUser_GetDurationControl");
    p_SteamAPI_ISteamUser_GetEncryptedAppTicket = dlsym(h, "SteamAPI_ISteamUser_GetEncryptedAppTicket");
    p_SteamAPI_ISteamUser_GetGameBadgeLevel = dlsym(h, "SteamAPI_ISteamUser_GetGameBadgeLevel");
    p_SteamAPI_ISteamUser_GetHSteamUser = dlsym(h, "SteamAPI_ISteamUser_GetHSteamUser");
    p_SteamAPI_ISteamUser_GetMarketEligibility = dlsym(h, "SteamAPI_ISteamUser_GetMarketEligibility");
    p_SteamAPI_ISteamUser_GetPlayerSteamLevel = dlsym(h, "SteamAPI_ISteamUser_GetPlayerSteamLevel");
    p_SteamAPI_ISteamUser_GetSteamID = dlsym(h, "SteamAPI_ISteamUser_GetSteamID");
    p_SteamAPI_ISteamUser_GetUserDataFolder = dlsym(h, "SteamAPI_ISteamUser_GetUserDataFolder");
    p_SteamAPI_ISteamUser_GetVoice = dlsym(h, "SteamAPI_ISteamUser_GetVoice");
    p_SteamAPI_ISteamUser_GetVoiceOptimalSampleRate = dlsym(h, "SteamAPI_ISteamUser_GetVoiceOptimalSampleRate");
    p_SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED = dlsym(h, "SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED");
    p_SteamAPI_ISteamUser_RequestEncryptedAppTicket = dlsym(h, "SteamAPI_ISteamUser_RequestEncryptedAppTicket");
    p_SteamAPI_ISteamUser_RequestStoreAuthURL = dlsym(h, "SteamAPI_ISteamUser_RequestStoreAuthURL");
    p_SteamAPI_ISteamUser_StartVoiceRecording = dlsym(h, "SteamAPI_ISteamUser_StartVoiceRecording");
    p_SteamAPI_ISteamUser_StopVoiceRecording = dlsym(h, "SteamAPI_ISteamUser_StopVoiceRecording");
    p_SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED = dlsym(h, "SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED");
    p_SteamAPI_ISteamUser_TrackAppUsageEvent = dlsym(h, "SteamAPI_ISteamUser_TrackAppUsageEvent");
    p_SteamAPI_ISteamUser_UserHasLicenseForApp = dlsym(h, "SteamAPI_ISteamUser_UserHasLicenseForApp");
    p_SteamAPI_ISteamUtils_BOverlayNeedsPresent = dlsym(h, "SteamAPI_ISteamUtils_BOverlayNeedsPresent");
    p_SteamAPI_ISteamUtils_CheckFileSignature = dlsym(h, "SteamAPI_ISteamUtils_CheckFileSignature");
    p_SteamAPI_ISteamUtils_FilterText = dlsym(h, "SteamAPI_ISteamUtils_FilterText");
    p_SteamAPI_ISteamUtils_GetAPICallFailureReason = dlsym(h, "SteamAPI_ISteamUtils_GetAPICallFailureReason");
    p_SteamAPI_ISteamUtils_GetAPICallResult = dlsym(h, "SteamAPI_ISteamUtils_GetAPICallResult");
    p_SteamAPI_ISteamUtils_GetAppID = dlsym(h, "SteamAPI_ISteamUtils_GetAppID");
    p_SteamAPI_ISteamUtils_GetConnectedUniverse = dlsym(h, "SteamAPI_ISteamUtils_GetConnectedUniverse");
    p_SteamAPI_ISteamUtils_GetCurrentBatteryPower = dlsym(h, "SteamAPI_ISteamUtils_GetCurrentBatteryPower");
    p_SteamAPI_ISteamUtils_GetIPCCallCount = dlsym(h, "SteamAPI_ISteamUtils_GetIPCCallCount");
    p_SteamAPI_ISteamUtils_GetIPCountry = dlsym(h, "SteamAPI_ISteamUtils_GetIPCountry");
    p_SteamAPI_ISteamUtils_GetIPv6ConnectivityState = dlsym(h, "SteamAPI_ISteamUtils_GetIPv6ConnectivityState");
    p_SteamAPI_ISteamUtils_GetImageRGBA = dlsym(h, "SteamAPI_ISteamUtils_GetImageRGBA");
    p_SteamAPI_ISteamUtils_GetImageSize = dlsym(h, "SteamAPI_ISteamUtils_GetImageSize");
    p_SteamAPI_ISteamUtils_GetSecondsSinceAppActive = dlsym(h, "SteamAPI_ISteamUtils_GetSecondsSinceAppActive");
    p_SteamAPI_ISteamUtils_GetSecondsSinceComputerActive = dlsym(h, "SteamAPI_ISteamUtils_GetSecondsSinceComputerActive");
    p_SteamAPI_ISteamUtils_GetServerRealTime = dlsym(h, "SteamAPI_ISteamUtils_GetServerRealTime");
    p_SteamAPI_ISteamUtils_GetSteamUILanguage = dlsym(h, "SteamAPI_ISteamUtils_GetSteamUILanguage");
    p_SteamAPI_ISteamUtils_InitFilterText = dlsym(h, "SteamAPI_ISteamUtils_InitFilterText");
    p_SteamAPI_ISteamUtils_IsAPICallCompleted = dlsym(h, "SteamAPI_ISteamUtils_IsAPICallCompleted");
    p_SteamAPI_ISteamUtils_IsOverlayEnabled = dlsym(h, "SteamAPI_ISteamUtils_IsOverlayEnabled");
    p_SteamAPI_ISteamUtils_IsSteamChinaLauncher = dlsym(h, "SteamAPI_ISteamUtils_IsSteamChinaLauncher");
    p_SteamAPI_ISteamUtils_IsSteamInBigPictureMode = dlsym(h, "SteamAPI_ISteamUtils_IsSteamInBigPictureMode");
    p_SteamAPI_ISteamUtils_IsSteamRunningInVR = dlsym(h, "SteamAPI_ISteamUtils_IsSteamRunningInVR");
    p_SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck = dlsym(h, "SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck");
    p_SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled = dlsym(h, "SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled");
    p_SteamAPI_ISteamUtils_SetGameLauncherMode = dlsym(h, "SteamAPI_ISteamUtils_SetGameLauncherMode");
    p_SteamAPI_ISteamUtils_SetOverlayNotificationInset = dlsym(h, "SteamAPI_ISteamUtils_SetOverlayNotificationInset");
    p_SteamAPI_ISteamUtils_SetOverlayNotificationPosition = dlsym(h, "SteamAPI_ISteamUtils_SetOverlayNotificationPosition");
    p_SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled = dlsym(h, "SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled");
    p_SteamAPI_ISteamUtils_SetWarningMessageHook = dlsym(h, "SteamAPI_ISteamUtils_SetWarningMessageHook");
    p_SteamAPI_ISteamUtils_StartVRDashboard = dlsym(h, "SteamAPI_ISteamUtils_StartVRDashboard");
    p_SteamAPI_ISteamVideo_GetOPFSettings = dlsym(h, "SteamAPI_ISteamVideo_GetOPFSettings");
    p_SteamAPI_ISteamVideo_GetOPFStringForApp = dlsym(h, "SteamAPI_ISteamVideo_GetOPFStringForApp");
    p_SteamAPI_ISteamVideo_GetVideoURL = dlsym(h, "SteamAPI_ISteamVideo_GetVideoURL");
    p_SteamAPI_ISteamVideo_IsBroadcasting = dlsym(h, "SteamAPI_ISteamVideo_IsBroadcasting");
    p_SteamAPI_ManualDispatch_FreeLastCallback = dlsym(h, "SteamAPI_ManualDispatch_FreeLastCallback");
    p_SteamAPI_ManualDispatch_GetAPICallResult = dlsym(h, "SteamAPI_ManualDispatch_GetAPICallResult");
    p_SteamAPI_ManualDispatch_GetNextCallback = dlsym(h, "SteamAPI_ManualDispatch_GetNextCallback");
    p_SteamAPI_ManualDispatch_Init = dlsym(h, "SteamAPI_ManualDispatch_Init");
    p_SteamAPI_ManualDispatch_RunFrame = dlsym(h, "SteamAPI_ManualDispatch_RunFrame");
    p_SteamAPI_RegisterCallResult = dlsym(h, "SteamAPI_RegisterCallResult");
    p_SteamAPI_RegisterCallback = dlsym(h, "SteamAPI_RegisterCallback");
    p_SteamAPI_ReleaseCurrentThreadMemory = dlsym(h, "SteamAPI_ReleaseCurrentThreadMemory");
    p_SteamAPI_RunCallbacks = dlsym(h, "SteamAPI_RunCallbacks");
    p_SteamAPI_SetBreakpadAppID = dlsym(h, "SteamAPI_SetBreakpadAppID");
    p_SteamAPI_SetMiniDumpComment = dlsym(h, "SteamAPI_SetMiniDumpComment");
    p_SteamAPI_SetTryCatchCallbacks = dlsym(h, "SteamAPI_SetTryCatchCallbacks");
    p_SteamAPI_Shutdown = dlsym(h, "SteamAPI_Shutdown");
    p_SteamAPI_SteamNetworkingIPAddr_Clear = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_Clear");
    p_SteamAPI_SteamNetworkingIPAddr_GetFakeIPType = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_GetFakeIPType");
    p_SteamAPI_SteamNetworkingIPAddr_GetIPv4 = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_GetIPv4");
    p_SteamAPI_SteamNetworkingIPAddr_IsEqualTo = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_IsEqualTo");
    p_SteamAPI_SteamNetworkingIPAddr_IsFakeIP = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_IsFakeIP");
    p_SteamAPI_SteamNetworkingIPAddr_IsIPv4 = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_IsIPv4");
    p_SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros");
    p_SteamAPI_SteamNetworkingIPAddr_IsLocalHost = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_IsLocalHost");
    p_SteamAPI_SteamNetworkingIPAddr_ParseString = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_ParseString");
    p_SteamAPI_SteamNetworkingIPAddr_SetIPv4 = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_SetIPv4");
    p_SteamAPI_SteamNetworkingIPAddr_SetIPv6 = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_SetIPv6");
    p_SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost");
    p_SteamAPI_SteamNetworkingIPAddr_ToString = dlsym(h, "SteamAPI_SteamNetworkingIPAddr_ToString");
    p_SteamAPI_SteamNetworkingIdentity_Clear = dlsym(h, "SteamAPI_SteamNetworkingIdentity_Clear");
    p_SteamAPI_SteamNetworkingIdentity_GetFakeIPType = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetFakeIPType");
    p_SteamAPI_SteamNetworkingIdentity_GetGenericBytes = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetGenericBytes");
    p_SteamAPI_SteamNetworkingIdentity_GetGenericString = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetGenericString");
    p_SteamAPI_SteamNetworkingIdentity_GetIPAddr = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetIPAddr");
    p_SteamAPI_SteamNetworkingIdentity_GetIPv4 = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetIPv4");
    p_SteamAPI_SteamNetworkingIdentity_GetPSNID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetPSNID");
    p_SteamAPI_SteamNetworkingIdentity_GetStadiaID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetStadiaID");
    p_SteamAPI_SteamNetworkingIdentity_GetSteamID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetSteamID");
    p_SteamAPI_SteamNetworkingIdentity_GetSteamID64 = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetSteamID64");
    p_SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID");
    p_SteamAPI_SteamNetworkingIdentity_IsEqualTo = dlsym(h, "SteamAPI_SteamNetworkingIdentity_IsEqualTo");
    p_SteamAPI_SteamNetworkingIdentity_IsFakeIP = dlsym(h, "SteamAPI_SteamNetworkingIdentity_IsFakeIP");
    p_SteamAPI_SteamNetworkingIdentity_IsInvalid = dlsym(h, "SteamAPI_SteamNetworkingIdentity_IsInvalid");
    p_SteamAPI_SteamNetworkingIdentity_IsLocalHost = dlsym(h, "SteamAPI_SteamNetworkingIdentity_IsLocalHost");
    p_SteamAPI_SteamNetworkingIdentity_ParseString = dlsym(h, "SteamAPI_SteamNetworkingIdentity_ParseString");
    p_SteamAPI_SteamNetworkingIdentity_SetGenericBytes = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetGenericBytes");
    p_SteamAPI_SteamNetworkingIdentity_SetGenericString = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetGenericString");
    p_SteamAPI_SteamNetworkingIdentity_SetIPAddr = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetIPAddr");
    p_SteamAPI_SteamNetworkingIdentity_SetIPv4Addr = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetIPv4Addr");
    p_SteamAPI_SteamNetworkingIdentity_SetLocalHost = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetLocalHost");
    p_SteamAPI_SteamNetworkingIdentity_SetPSNID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetPSNID");
    p_SteamAPI_SteamNetworkingIdentity_SetStadiaID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetStadiaID");
    p_SteamAPI_SteamNetworkingIdentity_SetSteamID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetSteamID");
    p_SteamAPI_SteamNetworkingIdentity_SetSteamID64 = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetSteamID64");
    p_SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID = dlsym(h, "SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID");
    p_SteamAPI_SteamNetworkingIdentity_ToString = dlsym(h, "SteamAPI_SteamNetworkingIdentity_ToString");
    p_SteamAPI_SteamNetworkingMessage_t_Release = dlsym(h, "SteamAPI_SteamNetworkingMessage_t_Release");
    p_SteamAPI_UnregisterCallResult = dlsym(h, "SteamAPI_UnregisterCallResult");
    p_SteamAPI_UnregisterCallback = dlsym(h, "SteamAPI_UnregisterCallback");
    p_SteamAPI_UseBreakpadCrashHandler = dlsym(h, "SteamAPI_UseBreakpadCrashHandler");
    p_SteamAPI_WriteMiniDump = dlsym(h, "SteamAPI_WriteMiniDump");
    p_SteamClient = dlsym(h, "SteamClient");
    p_SteamGameServerClient = dlsym(h, "SteamGameServerClient");
    p_SteamGameServer_BSecure = dlsym(h, "SteamGameServer_BSecure");
    p_SteamGameServer_GetHSteamPipe = dlsym(h, "SteamGameServer_GetHSteamPipe");
    p_SteamGameServer_GetHSteamUser = dlsym(h, "SteamGameServer_GetHSteamUser");
    p_SteamGameServer_GetSteamID = dlsym(h, "SteamGameServer_GetSteamID");
    p_SteamGameServer_ReleaseCurrentThreadMemory = dlsym(h, "SteamGameServer_ReleaseCurrentThreadMemory");
    p_SteamGameServer_RunCallbacks = dlsym(h, "SteamGameServer_RunCallbacks");
    p_SteamGameServer_Shutdown = dlsym(h, "SteamGameServer_Shutdown");
    p_SteamInternal_ContextInit = dlsym(h, "SteamInternal_ContextInit");
    p_SteamInternal_GameServer_Init_V2 = dlsym(h, "SteamInternal_GameServer_Init_V2");
}
