$ErrorActionPreference = 'Stop'
$overlayQuest = 'D:\Claude\steam-runtime\host\overlay-quest'
$questBuild = 'D:\Claude\steam-runtime\quest-build'
Copy-Item -Path (Join-Path $overlayQuest '*') -Destination $questBuild -Recurse -Force
$env:JAVA_HOME = 'D:\tools\jdk17\jdk-17.0.19+10'
$env:ANDROID_HOME = 'D:\tools\sdk'
$env:ANDROID_SDK_ROOT = 'D:\tools\sdk'
$gradleTmp = 'D:\tmp\gradle'
New-Item -ItemType Directory -Path $gradleTmp -Force | Out-Null
$env:TEMP = $gradleTmp
$env:TMP = $gradleTmp
$env:JAVA_TOOL_OPTIONS = "-Djdk.net.unixdomain.tmpdir=$($gradleTmp.Replace('\','/'))"
$env:PATH = "C:\Program Files\Git\usr\bin;D:\tools\winflexbison;$env:JAVA_HOME\bin;$env:PATH"
Set-Location $questBuild
& .\gradlew --stop
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
& .\gradlew assembleStandaloneDebug --no-daemon
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
$apk = Join-Path $questBuild 'lorie-app\build\outputs\apk\standalone\debug\steam-runtime-dev-universal-debug.apk'
Copy-Item -LiteralPath $apk -Destination 'D:\Claude\sts2_port\work\steamruntime_quest.apk' -Force
