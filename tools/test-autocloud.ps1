param(
    [string]$JavaHome = 'D:\tools\jdk17\jdk-17.0.19+10',
    [string]$JsonJar
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
if (!$JsonJar) {
    $cached = Join-Path $env:USERPROFILE '.gradle\caches\modules-2\files-2.1\org.json\json'
    $JsonJar = Get-ChildItem -LiteralPath $cached -Recurse -Filter 'json-*.jar' |
        Select-Object -First 1 -ExpandProperty FullName
}
if (!$JsonJar -or !(Test-Path -LiteralPath $JsonJar)) { throw 'Pass -JsonJar with an offline org.json JAR.' }
$classes = Join-Path ([IO.Path]::GetTempPath()) ('mt2-autocloud-tests-' + [guid]::NewGuid())
New-Item -ItemType Directory -Path $classes | Out-Null
$sources = @(Get-ChildItem (Join-Path $PSScriptRoot 'tests\autocloud') -Recurse -Filter '*.java' |
    Select-Object -ExpandProperty FullName)
$sources += Join-Path $repo 'host\overlay-quest\lorie\src\main\java\com\termux\x11\PortAutoCloud.java'
& (Join-Path $JavaHome 'bin\javac.exe') -encoding UTF-8 -cp $JsonJar -d $classes @sources
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
& (Join-Path $JavaHome 'bin\java.exe') -cp "$classes;$JsonJar" com.termux.x11.PortAutoCloudTest
exit $LASTEXITCODE
