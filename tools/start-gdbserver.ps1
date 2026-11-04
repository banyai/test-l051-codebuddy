<#
.SYNOPSIS
    为 Cortex-Debug 启动 pyOCD gdbserver（端口 3333），并等待端口真正进入监听。

.DESCRIPTION
    由 .vscode/tasks.json 的 pyocd-gdbserver 任务在按 F5 前调用。
    1. 先结束仍占用 3333 / 4444 的旧实例（Windows 允许多个 socket 重复 bind，
       残留实例会让 GDB 连到失效的一侧，表现为 Remote connection closed）；
    2. 以隐藏窗口启动 pyocd gdbserver，标准输出/错误写入
       firmware/LIST/gdbserver.log 与 .err，便于事后排查；
    3. 轮询 3333 是否监听，最多等 10 秒，成功退出码 0，超时退出码 1。

.NOTES
    进程名不是 pyocd.exe 而是 python.exe（setuptools 启动器），
    所以清理只能按端口归属 PID 做，不能按进程名 kill。
#>

$ErrorActionPreference = 'Continue'

try {
    Get-NetTCPConnection -LocalPort 3333, 4444 -State Listen -ErrorAction SilentlyContinue |
        ForEach-Object { Stop-Process -Id $_.OwningProcess -Force -ErrorAction SilentlyContinue }
} catch {
}

$root   = Split-Path -Parent $PSScriptRoot
$pyocd  = 'C:\Users\lisa\AppData\Roaming\Python\Python314\Scripts\pyocd.exe'
$pack   = Join-Path $root 'docs\vendor\HED\dfp\HED.CIU32L0xx_DFP.1.2.6.pack'
$logDir = Join-Path $root 'firmware\LIST'

New-Item -ItemType Directory -Force $logDir | Out-Null

$log    = Join-Path $logDir 'gdbserver.log'
$logErr = Join-Path $logDir 'gdbserver.err.log'

# Start-Process 不会替参数加引号，本项目路径含空格（My Documents），
# --pack 的路径必须自己带引号，否则会被拆成多个参数。
$argList = @(
    'gdbserver'
    '--port', '3333'
    '--telnet-port', '4444'
    '--persist'
    '--target', 'CIU32L051R8Tx'
    '--pack', "`"$pack`""
    '-f', '100k'
)

Start-Process -FilePath $pyocd `
    -ArgumentList $argList `
    -WindowStyle Hidden `
    -RedirectStandardOutput $log `
    -RedirectStandardError $logErr

for ($i = 0; $i -lt 40; $i++) {
    Start-Sleep -Milliseconds 250
    if (Get-NetTCPConnection -LocalPort 3333 -State Listen -ErrorAction SilentlyContinue) {
        Write-Host 'gdbserver ready on port 3333'
        exit 0
    }
}

Write-Host 'gdbserver 未在 10 秒内监听 3333，详见 firmware/LIST/gdbserver.log'
exit 1
