param(
    [string]$JavaHome = 'D:\tools\jdk17\jdk-17.0.19+10',
    [string]$JsonJar
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
if ($JsonJar) { throw 'Maven JSON overrides are unsupported; tests require the vendored Android libcore JSON sources.' }
$classes = Join-Path ([IO.Path]::GetTempPath()) ('mt2-autocloud-tests-' + [guid]::NewGuid())
New-Item -ItemType Directory -Path $classes | Out-Null
$sources = @(Get-ChildItem (Join-Path $PSScriptRoot 'tests\autocloud') -Recurse -Filter '*.java' |
    Select-Object -ExpandProperty FullName)
$sources += @(Get-ChildItem (Join-Path $PSScriptRoot 'tests\android-json') -Recurse -Filter '*.java' | Select-Object -ExpandProperty FullName)
$sources += Join-Path $repo 'host\overlay-quest\lorie\src\main\java\com\termux\x11\PortAutoCloud.java'
$sources += Join-Path $repo 'host\overlay-quest\lorie\src\main\java\com\termux\x11\PortProcessLiveness.java'
& (Join-Path $JavaHome 'bin\javac.exe') -encoding UTF-8 -d $classes @sources
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
& (Join-Path $JavaHome 'bin\java.exe') -cp $classes com.termux.x11.PortAutoCloudTest
exit $LASTEXITCODE
