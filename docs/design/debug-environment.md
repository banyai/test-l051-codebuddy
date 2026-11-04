# 构建、烧录与调试环境记录

> 记录 CIU32L051 LITE-64 核心板工程的可用工具链、实测命令与踩坑结论。
> 时间：2026-11-04。所有“已验证”条目均在实板上完成，未验证项在末节单列。

## 1. 本机环境（实测）

| 组件 | 版本 | 路径 |
|---|---|---|
| arm-none-eabi-gcc | 14.3.1（GNU Tools for STM32 14.3.rel1） | `C:\Users\lisa\AppData\Local\stm32cube\bundles\gnu-tools-for-stm32\14.3.1+st.2\bin` |
| CMake | 4.4.5 | `C:\Users\lisa\scoop\apps\cmake\4.4.5\bin\cmake.exe` |
| Ninja | 1.13.2 | `C:\Users\lisa\scoop\apps\ninja\1.13.2\ninja.exe` |
| pyOCD | 0.46.1 | `C:\Users\lisa\AppData\Roaming\Python\Python314\Scripts\pyocd.exe` |
| 调试器 | 板载 HED-Link CMSIS-DAP | DAPEN 跳线置 ON，USB-TypeC 供电 |
| 调试前端 | Cortex-Debug 1.13.0-pre6 | CodeBuddy 扩展目录 `.codebuddycn\extensions` |

工具链来自 STM32Cube 附带的 Arm GCC 打包，不是 Arm 官方安装包；升级时需同步复核优化选项与 `--specs=nano.specs` 行为。

## 2. 构建

在项目根执行（`-DCMAKE_TOOLCHAIN_FILE` 必须写绝对路径，相对路径的解析基准是构建目录）：

```powershell
C:\Users\lisa\scoop\apps\cmake\4.4.5\bin\cmake.exe -S firmware -B firmware/OBJ -G Ninja `
  "-DCMAKE_TOOLCHAIN_FILE=C:/My Documents/test-l051-codebuddy/firmware/cmake/arm-none-eabi-gcc.cmake" `
  "-DARM_TOOLCHAIN_DIR=C:/Users/lisa/AppData/Local/stm32cube/bundles/gnu-tools-for-stm32/14.3.1+st.2" `
  "-DCMAKE_MAKE_PROGRAM=C:/Users/lisa/scoop/apps/ninja/1.13.2/ninja.exe"
C:\Users\lisa\scoop\apps\cmake\4.4.5\bin\cmake.exe --build firmware/OBJ
```

| 构建类型 | 参数 | text | data | bss | Flash 占用 |
|---|---|---|---|---|---|
| Debug（默认） | `-Og -g3` | 2336 B | 4 B | 212 B | 2340 B / 3.57% |
| Release | `-Os` | 2088 B | 4 B | 212 B | 2092 B / 3.19% |

查看某文件最终参数：`firmware/OBJ/compile_commands.json`（CMake 已开启导出）。

## 3. 烧录

```powershell
powershell -ExecutionPolicy Bypass -File tools\flash.ps1
```

- 默认 SWD 100 kHz、目标 `CIU32L051R8Tx`、器件包 `docs/vendor/HED/dfp/HED.CIU32L0xx_DFP.1.2.6.pack`。
- 实测输出：`Erased 2560 bytes (5 pages), programmed 2560 bytes`；重复烧同一镜像时为 `identical`。
- 板载 CMSIS-DAP 枚举名 `HED HED-Link CMSIS-DAP 54361175461a3c22`；DAPEN 置 OFF 或 SWD 被复用为普通 IO 时会报 `SWD/JTAG communication failure (No ACK)`。

## 4. 图形界面调试（F5）

### 4.1 方案

Cortex-Debug 的“由插件自己启动 pyOCD”这条路在本机不可用（原因见 §6 第 1 条），因此改为：

- pyOCD gdbserver 由 VS Code 任务独立启动，固定端口 3333，`--persist`；
- Cortex-Debug 用 `servertype: "external"` + `gdbTarget: "localhost:3333"` 连接；
- 外设视图由 SVD 驱动：`docs/vendor/HED/dfp/svd/CIU32L051x8.svd`（从 DFP 包中提取）。

### 4.2 文件

| 文件 | 作用 |
|---|---|
| `.vscode/launch.json` | 两个配置：`自动启动 pyOCD`（带 `preLaunchTask`）、`gdbserver 已在运行` |
| `.vscode/tasks.json` | 任务 `pyocd-gdbserver`，调用 `tools/start-gdbserver.ps1` |
| `tools/start-gdbserver.ps1` | 清端口 → 启动 gdbserver → 轮询 3333 监听，最多 10 s；日志写 `firmware/LIST/gdbserver{,.err}.log` |
| `docs/vendor/HED/dfp/svd/CIU32L051x8.svd` | 外设寄存器定义 |
| `tools/flash.ps1` | 单独烧录 |

`.vscode/launch.json` 与 `.vscode/tasks.json` 随仓库保存（`.gitignore` 只忽略 `.vscode` 下的日志与缓存），换机器拉取代码即可直接 F5；其中的绝对路径（pyocd、GDB、工具链）与本机绑定，换机器需要改这三处。

### 4.3 操作

1. `cmake --build firmware/OBJ`；
2. F5 → 选「CIU32L051（自动启动 pyOCD）」；
3. 任务终端出现 `gdbserver ready on port 3333` 后，GDB 连接并 halt；
4. 左侧 **PERIPHERALS**：`GPIOB.ODR` 的 bit14 随闪灯 0/1 跳变，`RCC` 可看时钟源，**CORTEX PERIPHERALS** 里是 `SysTick`/`NVIC`；
5. 停止调试后 gdbserver 仍在（`--persist`），下次 F5 会先按端口清掉再重启。

## 5. 命令行调试（不依赖 IDE）

```powershell
python -m pyocd gdbserver --port 3333 --telnet-port 4444 --persist `
  --target CIU32L051R8Tx --pack docs\vendor\HED\dfp\HED.CIU32L0xx_DFP.1.2.6.pack -f 100k
```

```gdb
file firmware/OBJ/firmware.elf
set mem inaccessible-by-default off
target extended-remote localhost:3333
p/x *(unsigned int*)0x50000414     # GPIOB_ODR：bit14=1 灭，0 亮
p/x *(unsigned int*)0x20000000     # SystemCoreClock，应为 0x02DC6C00 = 48 MHz
monitor halt
detach
```

`set mem inaccessible-by-default off` 不可省：GDB 默认只允许访问 ELF 覆盖的 Flash/RAM，读外设会报 `Cannot access memory at address 0x50000414`。

## 6. 踩坑记录（均在本机复现过）

| # | 现象 | 原因 | 处理 |
|---|---|---|---|
| 1 | F5 报“启动超时” | Cortex-Debug 用 `/GDB server started (at\|on) port/` 判断 pyOCD 就绪，pyOCD 0.46.1 实际打印 `GDB server listening on port 3333 (core 0)`，永远匹配不上 | 改用 external 模式，不由插件启动服务端 |
| 2 | `Failed to launch GDB: Remote connection closed` | Windows 允许对 `127.0.0.1:3333` 重复 bind，残留的多个 gdbserver 同时监听，GDB 连到失效实例 | 启动前按端口归属 PID 清理（3333 与 4444） |
| 3 | `Remote connection closed` 清理不掉 | 进程名不是 `pyocd.exe` 而是 `python.exe`（setuptools 启动器），`taskkill /IM pyocd.exe` 无效 | 用 `Get-NetTCPConnection -LocalPort 3333 \| % { Stop-Process -Id $_.OwningProcess }`；不可按 `python.exe` 批量杀（本机还有 KiCad MCP 服务） |
| 4 | 清理任务 `exit code 1`，后续任务不执行 | PowerShell `-Command` 管道里存在被 `SilentlyContinue` 抑制的错误记录时，进程退出码仍为 1 | 脚本内 `try/catch` 并显式 `exit 0` |
| 5 | `could not connect (error 138)`，端口无监听 | `Start-Process -ArgumentList` 不替参数加引号，`C:\My Documents\...` 被空格拆开，pyocd 报 `unrecognized arguments` 后退出 | `--pack` 路径显式加引号；日志落 `firmware/LIST/gdbserver.err.log` |
| 6 | GDB 读外设报 `Cannot access memory` | GDB 默认 `mem inaccessible-by-default on`，只认 ELF 段 | `set mem inaccessible-by-default off`（Cortex-Debug 会自动设置） |
| 7 | 断点、单步不按行生效 | 早期构建没有 `-g` | CMake 已固定 Debug 用 `-Og -g3` |

## 7. 验证记录

| 日期 | 项目 | 结果 |
|---|---|---|
| 2026-11-04 | 编译（Debug/Release） | 通过，体积见 §2 |
| 2026-11-04 | 烧录 + 闪灯 | 通过，PB14 亮灭各 500 ms |
| 2026-11-04 | 运行态时钟 | `SystemCoreClock = 0x02DC6C00`（48 MHz），`s_fault_code = 0` |
| 2026-11-04 | halt 位置 | `main.c:67` 主循环（`sch_dispatch`/`sch_idle`） |
| 2026-11-04 | GDB 连接与外设读 | `GPIOB_ODR` 读到 `0x4000`/`0x0000` 交替；`SysTick_LOAD = 0xBB7F` |
| 2026-11-04 | F5 图形化调试 | 用户实机确认可用 |

## 8. 版本库与厂商资料

`.gitignore` 只保留工程自身的构建与调试闭环所需文件；`docs/vendor/` 与 `references/` 整体不入库，但对“器件包 + SVD”两个运行期依赖单独放行。

| 范围 | 是否入库 | 说明 |
|---|---|---|
| `firmware/` 源码、`firmware/cmake/`、链接脚本、启动文件 | 入库 | 约 1.9 MB |
| `firmware/OBJ/`、`firmware/LIST/` | 不入库 | 构建产物与 map，含 `gdbserver*.log` |
| `.vscode/launch.json`、`.vscode/tasks.json` | 入库 | 共用调试配置 |
| `docs/vendor/HED/dfp/HED.CIU32L0xx_DFP.1.2.6.pack` | 入库 | 0.6 MB，烧录与 F5 调试的器件定义 |
| `docs/vendor/HED/dfp/svd/CIU32L051x8.svd` | 入库 | 0.5 MB，外设寄存器视图 |
| `docs/vendor/` 其余全部（PDF、rar、原理图/PCB 源文件、解压的 SDK） | 不入库 | 约 59 MB，均从厂商渠道获取 |
| `references/` | 不入库 | `sch_firmware` 母本 |
| `.codegraph/` | 不入库 | 代码索引缓存，约 31.5 MB |

克隆后即可编译、烧录、F5 调试；只缺手册与 SDK 源码，需要查阅时按下面命令恢复。

新环境恢复厂商资料（本机 7z 不可用，用 WinRAR 的 `UnRAR.exe`）：

```powershell
& 'C:\Program Files\WinRAR\UnRAR.exe' x docs\vendor\HED\sdk\CIU32L051_STDLib_V1.0.11.rar docs\vendor\HED\sdk\
& 'C:\Program Files\WinRAR\UnRAR.exe' x docs\vendor\HED\dfp\HED.CIU32L0xx_DFP_MDK_V1.2.6.rar "$env:TEMP\dfp\"
Copy-Item "$env:TEMP\dfp\HED.CIU32L0xx_DFP_MDK.1.2.6\HED.CIU32L0xx_DFP.1.2.6.pack" docs\vendor\HED\dfp\ -Force
```

从 `.pack` 重新提取 SVD（pack 本质是 zip）：

```powershell
Copy-Item docs\vendor\HED\dfp\HED.CIU32L0xx_DFP.1.2.6.pack "$env:TEMP\dfp.zip" -Force
Expand-Archive "$env:TEMP\dfp.zip" "$env:TEMP\dfp_pack" -Force
Copy-Item "$env:TEMP\dfp_pack\CMSIS\SVD\CIU32L051x8.svd" docs\vendor\HED\dfp\svd\ -Force
```

## 9. 未验证 / 待办

- 外设寄存器的**写入**（如直接改 `GPIOB_ODR`）未验证，只有只读验证。
- `docs/rules/irq-map.md` 模板里的中断响应、关中断区间、主循环最坏耗时仍为 `needs-info`，需要示波器/逻辑分析仪实测。
- Release 构建覆盖了 `CMAKE_C_FLAGS_RELEASE`，默认的 `-DNDEBUG` 不再生效；将来接入带 `assert` 的库需显式加回。
- `cppcheck` 基线与 `--project=compile_commands.json` 静态检查尚未执行（本机未安装）。
