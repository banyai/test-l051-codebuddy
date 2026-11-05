# 构建、烧录与调试环境记录

> 记录 CIU32L051 LITE-64 核心板工程的可用工具链、实测命令与踩坑结论。
> 时间：2026-11-04；2026-11-05 补充 LCD 显示实板验证与代码导航配置（§9）。
> 实板相关的“已验证”条目均在实板上完成；§9 属于 IDE 主机侧验证，未验证项在末节单列。

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
| 8 | 光标放在函数/宏定义上不显示定义、跳转为空 | CodeBuddy 扩展目录只装了 clangd 0.6.0，PATH 里没有 clangd 二进制；编译数据库只在 `firmware/OBJ/` 子目录，语言服务找不到 | 指定 `clangd.path`，并由 CMake 同步 `compile_commands.json` 到工作区根，见 §9 |
| 9 | 按 VS Code 习惯配 `C_Cpp.*` 后仍不行 | CodeBuddy 未安装 cpptools，那些设置无效；还误把 clangd 禁用，关掉了唯一语言服务 | 改用 clangd 配置，见 §9；`.vscode/c_cpp_properties.json` 只给 VS Code 场景保留 |

## 7. 验证记录

| 日期 | 项目 | 结果 |
|---|---|---|
| 2026-11-04 | 编译（Debug/Release） | 通过，体积见 §2 |
| 2026-11-04 | 烧录 + 闪灯 | 通过，PB14 亮灭各 500 ms |
| 2026-11-04 | 运行态时钟 | `SystemCoreClock = 0x02DC6C00`（48 MHz），`s_fault_code = 0` |
| 2026-11-04 | halt 位置 | `main.c:67` 主循环（`sch_dispatch`/`sch_idle`） |
| 2026-11-04 | GDB 连接与外设读 | `GPIOB_ODR` 读到 `0x4000`/`0x0000` 交替；`SysTick_LOAD = 0xBB7F` |
| 2026-11-04 | F5 图形化调试 | 用户实机确认可用 |
| 2026-11-05 | LCD 固件烧录与运行 | `Erased/programmed 3584 bytes`；复位后进入 WFI 主循环，`s_fault_code = 0` |
| 2026-11-05 | LCD 控制器寄存器（实板） | `CR=0x00040B81`、`FCR=0x2EFC0000`、`SR=0x3`（ENS/SOF 置位），电荷泵与帧波形正常 |
| 2026-11-05 | LCD 显示刷新（实板） | `LCD_RAM` 依次解出 `0030`→`0083`→`0105`，与 `s_time_ms=0x19DE8`（105.96 s）一致 |
| 2026-11-05 | 代码导航（IDE，主机侧） | clangd 19.1.2 解析 5 个 C 文件 0 errors；用户确认重载后悬停/跳转恢复，见 §9 |

## 8. 版本库与厂商资料

`.gitignore` 只保留工程自身的构建与调试闭环所需文件；`docs/vendor/` 与 `references/` 整体不入库，但对“器件包 + SVD”两个运行期依赖单独放行。

| 范围 | 是否入库 | 说明 |
|---|---|---|
| `firmware/` 源码、`firmware/cmake/`、链接脚本、启动文件 | 入库 | 约 1.9 MB |
| `firmware/OBJ/`、`firmware/LIST/` | 不入库 | 构建产物与 map，含 `gdbserver*.log` |
| `.vscode/launch.json`、`.vscode/tasks.json` | 入库 | 共用调试配置 |
| `.vscode/settings.json`、`.vscode/c_cpp_properties.json` | 入库 | 语言服务配置，见 §9 |
| 根 `compile_commands.json` | 不入库 | CMake 构建时从 `firmware/OBJ/` 同步，供 clangd 自动发现 |
| `docs/vendor/HED/dfp/HED.CIU32L0xx_DFP.1.2.6.pack` | 入库 | 0.6 MB，烧录与 F5 调试的器件定义 |
| `docs/vendor/HED/dfp/svd/CIU32L051x8.svd` | 入库 | 0.5 MB，外设寄存器视图 |
| `docs/vendor/` 其余全部（PDF、rar、原理图/PCB 源文件、解压的 SDK） | 不入库 | 约 59 MB，均从厂商渠道获取 |
| `references/` | 不入库 | `sch_firmware` 母本 |
| `.codegraph/` | 不入库 | 代码索引缓存，约 31.5 MB |
| `.cache/` | 不入库 | clangd 后台索引（`.idx`），由语言服务自动生成 |

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

## 9. 代码导航：定义跳转与悬停（IDE 主机侧，2026-11-05）

> 本节是编辑器环境验证，不涉及实板。现象：光标放在函数或宏定义上不显示定义，Ctrl+点击 / F12 为空。

### 9.1 环境事实

| 项目 | 实测结论 |
|---|---|
| IDE 扩展目录 | `C:\Users\lisa\.codebuddycn\extensions` 中只有 `llvm-vs-code-extensions.vscode-clangd-0.6.0-universal`，**没有 cpptools** |
| 另一套扩展 | `C:\Users\lisa\.vscode\extensions` 里的 `ms-vscode.cpptools` 属 VS Code，CodeBuddy 不加载 |
| clangd 二进制 | PATH 里没有 `clangd`；扩展默认 `clangd.path = "clangd"`，语言服务器未启动（Output → clangd 日志为空） |
| 可用二进制 | `C:\Espressif\tools\esp-clang\esp-19.1.2_20250312\esp-clang\bin\clangd.exe`（19.1.2，实测可独立运行）；另有 Arduino IDE 自带的 14.0.0 可用 |
| 编译数据库 | CMake 只生成 `firmware/OBJ/compile_commands.json`，该目录被 `.gitignore` 忽略；clangd 默认沿源文件父目录向上查找，找不到 |
| CodeGraph | `.codegraph/` 索引有 9 个新增 LCD 文件未同步，`codegraph sync` 后为 80 文件 / 1632 节点；CodeGraph 不为 `#define` 建符号节点，宏定义靠语言服务 |

### 9.2 生效配置

| 文件 | 关键内容 | 作用 |
|---|---|---|
| `.vscode/settings.json` | `clangd.enable=true`、`clangd.path=<本机 clangd 19>`、`clangd.arguments=["--query-driver=**","--background-index"]`、`clangd.detectExtensionConflicts=false`、`files.associations: {"*.c":"c","*.h":"c"}` | 重新启用并指定语言服务器；`--query-driver=**` 让 clangd 查询 `arm-none-eabi-gcc` 的内置头路径 |
| `firmware/CMakeLists.txt` | POST_BUILD 追加 `cmake -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/../compile_commands.json` | 让 clangd 在工作区根自动发现编译数据库，源码与宏定义随之可解析 |
| `.gitignore` | `/compile_commands.json` | 忽略上述生成副本 |
| `.vscode/c_cpp_properties.json` | `compileCommands`、`compilerPath`、`includePath`、`defines` | 仅给 VS Code + cpptools 场景的后备配置，CodeBuddy 中不生效 |
| `.codegraph/` | `codegraph sync` | 让 CodeBuddy 代码索引收录新增的 LCD 文件与函数 |

**换机器必改**：`clangd.path` 与 `c_cpp_properties.json` 的 `compilerPath` 都是本机绝对路径；新环境还需先执行一次 CMake configure + build，才会生成并同步 `compile_commands.json`。

### 9.3 生效步骤与验证

1. 修改 `.vscode/settings.json` 后必须 `Ctrl+Shift+P` → **Developer: Reload Window**（配置是启动时读取的）；
2. Output 面板选 **clangd**，应显示 `clangd version 19.1.2 ...` 与启动日志（修复前该日志为空）；
3. 打开 `firmware/HARDWARE/lcd.c`，悬停 `std_lcd_init`、`LCD_STABLE_MS`，Ctrl+点击 `lcd_display_number`；
4. 命令行复核（不依赖 IDE 是否重载）：

```powershell
& 'C:\Espressif\tools\esp-clang\esp-19.1.2_20250312\esp-clang\bin\clangd.exe' `
  --query-driver=** --check=firmware/HARDWARE/lcd.c
```

实测：`main.c`、`app_display.c`、`lcd.c`、`lcd_segments.c`、`lcd.h` 全部 `All checks completed, 0 errors`，日志含 `Testing features at each token`（悬停 / 定义功能在解析阶段正常）；删掉根目录 `compile_commands.json` 后重新构建，CMake 会自动同步回来。用户确认重载后悬停与跳转恢复。

### 9.4 踩坑要点

- 不要把 CodeBuddy 与 VS Code 的扩展目录混为一谈：按 VS Code 习惯配 `C_Cpp.*` 在 CodeBuddy 里完全无效，禁用 clangd 更会关掉唯一语言服务（第一次修复失败的原因）。
- `clangd.arguments` 里不要写 `${workspaceFolder}`：本机 clangd 0.6.0 扩展未证实支持变量替换；改为把编译数据库放到工作区根，由 clangd 自动发现。
- CodeGraph 索引与语言服务是两套机制：`codegraph sync` 解决新增函数 / 结构体的索引，`#define` 宏的悬停与跳转仍依赖 clangd。

## 10. 未验证 / 待办

- 外设寄存器的**写入**（如直接改 `GPIOB_ODR`）未验证，只有只读验证。
- `docs/rules/irq-map.md` 模板里的中断响应、关中断区间、主循环最坏耗时仍为 `needs-info`，需要示波器/逻辑分析仪实测。
- Release 构建覆盖了 `CMAKE_C_FLAGS_RELEASE`，默认的 `-DNDEBUG` 不再生效；将来接入带 `assert` 的库需显式加回。
- `cppcheck` 基线与 `--project=compile_commands.json` 静态检查尚未执行（本机未安装）。
- 代码导航配置只在本机 CodeBuddy 验证过；换机器需复核 `clangd.path`、`compilerPath` 与 clangd 版本组合（§9）。
- LCD 屏面的目视效果（段完整性、对比度、约 32 Hz 帧率）未验证，实板只做到寄存器 / `LCD_RAM` 级验证。
