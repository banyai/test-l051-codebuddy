<#
.SYNOPSIS
    用板载 CMSIS-DAP（HED-Link）配合 pyOCD 烧录固件。

.DESCRIPTION
    前置条件：
      1. 已安装 pyOCD（python -m pip install pyocd）；
      2. 核心板 DAPEN 跳线置 ON，USB-TypeC 连接 PC，电源指示灯 LED2 点亮；
      3. JP1（BOOT0）保持 OFF，程序从 Flash 正常启动。

.PARAMETER Image
    待烧录镜像，默认 firmware/OBJ/firmware.hex。

.PARAMETER Target
    器件名，取自 docs/vendor/HED/dfp/HED.CIU32L0xx_DFP.1.2.6.pack 中的 Dname。

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File tools\flash.ps1
#>
param(
    [string]$Image  = (Join-Path $PSScriptRoot '..\firmware\OBJ\firmware.hex'),
    [string]$Target = 'CIU32L051R8Tx',
    [string]$Pack   = (Join-Path $PSScriptRoot '..\docs\vendor\HED\dfp\HED.CIU32L0xx_DFP.1.2.6.pack'),
    [string]$Freq   = '100k'
)

python -m pyocd flash --pack $Pack --target $Target -f $Freq $Image
exit $LASTEXITCODE
