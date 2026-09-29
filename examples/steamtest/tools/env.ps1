# SteamTest Android build environment (session only) - dot-source with . ./tools/env.ps1
$env:JAVA_HOME = "C:\Java\jdk-17"
$env:ANDROID_HOME = "C:\Android\sdk"
$env:ANDROID_SDK_ROOT = "C:\Android\sdk"
$env:ANDROID_NDK_HOME = "C:\Android\ndk\r28c"
$bt = Get-ChildItem "$env:ANDROID_HOME\build-tools" | Sort-Object Name | Select-Object -Last 1
$env:PATH = ("{0}\bin;{1};{2}\{3};{4}\toolchains\llvm\prebuilt\windows-x86_64\bin;" +
             "{5}\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\lib;{6}") -f `
    $env:JAVA_HOME, `
    "C:\Android\platform-tools", `
    $env:ANDROID_HOME, $bt.Name, `
    $env:ANDROID_NDK_HOME, `
    $env:ANDROID_NDK_HOME, `
    $env:PATH
Write-Host "JAVA_HOME=$env:JAVA_HOME"
Write-Host "ANDROID_HOME=$env:ANDROID_HOME (build-tools: $($bt.Name))"
Write-Host "ANDROID_NDK_HOME=$env:ANDROID_NDK_HOME"
