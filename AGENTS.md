# 项目说明

CIU32L051 LITE-64核心板测试软件。

## 目录

- `firmware/`：唯一参与编译的固件工程（`USER`／`APP`／`HARDWARE`／`SYSTEM`／`STARTUP`／`LIBRARIES`），构建产物在 `firmware/OBJ/` 与 `firmware/LIST/`。
- `docs/`：资料。`docs/rules/` 开发规则，`docs/requirements/` 需求，`docs/design/` 自研设计，`docs/vendor/HED/` 厂商手册、核心板原理图、SDK、DFP。
- `references/`：跨工程复用母本（`sch_firmware/`），只读。
- `tests/`：宿主测试，独立于固件构建。
- `tools/`：烧写（`flash.ps1`）、调试服务端（`start-gdbserver.ps1`）等辅助脚本。

## 项目资料

- 开发嵌入式软件时查阅 `docs/rules/`。
- 涉及电路、引脚或器件时查阅 `docs/vendor/HED/hardware/`（原理图、PCB）与 `docs/vendor/HED/manuals/`（数据手册、参考手册、应用笔记）。
- 参考的软件查阅 `references/`。
- 厂商开发包位于 `docs/vendor/HED/sdk/` 与 `docs/vendor/HED/dfp/`，尽量保持原样；确需修改时记录原因和版本。

## 构建与烧录

在项目根执行：

```powershell
cmake -S firmware -B firmware/OBJ -G Ninja `
      "-DCMAKE_TOOLCHAIN_FILE=<项目根>/firmware/cmake/arm-none-eabi-gcc.cmake" `
      "-DARM_TOOLCHAIN_DIR=<工具链根目录>"
cmake --build firmware/OBJ
```

- 产物：`firmware/OBJ/firmware.elf|hex|bin`，map 在 `firmware/LIST/firmware.map`。
- 烧录：`powershell -ExecutionPolicy Bypass -File tools\flash.ps1`（pyOCD + 板载 CMSIS-DAP，需 DAPEN 跳线置 ON）。

## 调试

- 图形化：F5 选「CIU32L051（自动启动 pyOCD）」，由任务 `pyocd-gdbserver` 启动 pyOCD（端口 3333）后以 external 方式连接；外设视图用 `docs/vendor/HED/dfp/svd/CIU32L051x8.svd`。
- 服务端日志：`firmware/LIST/gdbserver.log`、`gdbserver.err.log`。
- 命令行：`python -m pyocd commander --pack docs\vendor\HED\dfp\HED.CIU32L0xx_DFP.1.2.6.pack -t CIU32L051R8Tx -f 100k -c "read32 0x50000414 4" -c "exit"`（GPIOB_ODR，bit14 为 LED 电平）。
- 工具路径、构建参数、踩坑记录与验证结果见 `docs/design/debug-environment.md`。

## 开发与验证

- 根据相关资料确认引脚、电气时序和协议细节；资料冲突或关键细节缺失时指出并请求确认。
- 修改后执行适合改动的构建和测试；明确区分软件测试与实板验证，说明未完成的验证。
- 已确认事实：MCU 为 CIU32L051x8（Cortex-M0+，64KB Flash，16KB SRAM，48MHz）；SDK 为 CIU32L051_STDLib V1.0.11；用户 LED1 为 PB14、低电平点亮（VDD → R14 510Ω → LED → PB14）；用户按键 B2 为 PC13。

<!-- CODEGRAPH_START -->

## CodeGraph

在仓库根目录存在 `.codegraph/` 时，理解或定位代码应先使用 CodeGraph，再使用文本搜索或读取文件。优先调用可用的 `codegraph_explore` MCP 工具，或运行 `codegraph explore "<符号或问题>"`。不存在 `.codegraph/` 时跳过 CodeGraph。

<!-- CODEGRAPH_END -->
