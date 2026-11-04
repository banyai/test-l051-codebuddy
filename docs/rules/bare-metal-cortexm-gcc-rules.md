# 裸机嵌入式 C 开发规则（Cortex-M + GCC 通用模板）

适用于**无操作系统（bare-metal）**的 ARM Cortex-M 固件开发。本文件与具体芯片型号、厂商无关，落地时先完成 §1 的占位符替换和 §9 的检查清单。

适用范围：Cortex-M0 / M0+ / M3 / M4 / M7 / M23 / M33 内核 MCU，含国产 ARM（GD32、HK32、N32、HC32、MM32、CH32 等）。RISC-V 目标需把编译器换成 `riscv-none-elf-gcc`、调试后端换成对应 OpenOCD 分支，其余条款通用。

工具链基线：VS Code + `arm-none-eabi-gcc` + CMake/Ninja + OpenOCD/pyOCD（前端 Cortex-Debug）。

---

## 1. 技术栈与适用范围

- 目标 MCU：`<型号>`，内核 `<Cortex-M0+/M0/M3/M4/M7/M33>`，最高主频 `<xx>` MHz，Flash `<xx>` KB，SRAM `<xx>` KB。容量须同时容纳程序、NVM 记录、全部静态对象和栈，并留出 ≥20% 余量；小容量器件（SRAM < 8KB）按实测峰值判断，不套用固定比例。
- 编译器：`arm-none-eabi-gcc`（优先 Arm 官方工具链；厂商定制 GCC 须记录版本号与差异点）。语言标准 C11，禁用编译器私有语法；GNU 扩展（`__attribute__`、段属性、内联汇编）集中封装到 `compiler.h`，不散落在业务代码里。
- 构建：CMake ≥ 3.20 + Ninja（或 Makefile）。启动文件、链接脚本、编译选项随工程纳入版本管理，不使用 IDE 私有工程文件作为唯一事实来源。
- 调试：SWD（保留 SWDIO／SWCLK／NRST／GND，不把调试脚挪作普通业务）或 JTAG。调试后端 OpenOCD 或 pyOCD，前端 VS Code + Cortex-Debug；J-Link 可用 J-Link GDB Server。
- 架构：主循环＋中断＋非阻塞状态机，**默认不引入 RTOS**。若项目采用 RTOS，另立规则文件，不复用本文件的"无 OS"假设（本文件不含任务栈隔离、优先级反转、调度器临界区等内容）。
- 烧写与量产工具须可在命令行复现，不依赖图形界面点击：`openocd -c "program <elf> verify reset exit"` / `pyocd flash` / 厂商 CLI。
- 电脑端测试可用独立宿主编译器和测试脚本，测试替身隔离硬件，但不替代固件构建。

### 1.1 目录结构与文件归属

新建文件必须先定位目录再写代码，不在项目根或各层目录根下平铺 `.c`／`.h`。**项目根只放辅助资料，全部固件内容（源码、厂家库、启动文件、构建脚本、生成产物）集中在 `firmware/` 一个目录里**，项目根因此保持整洁，一眼能看出"哪些是要编译的、哪些是资料"。

```text
<项目根>/
├── firmware/             固件工程：唯一参与编译与构建的目录
│   ├── USER/             入口与板级配置：main.c、*_it.c、board_config.h、版本号头、irq-map.md
│   ├── APP/              应用层：业务状态机、协议解析、任务函数
│   ├── HARDWARE/         自研外设驱动：led.c、key.c、timer.c、usart.c、lcd.c
│   ├── SYSTEM/           系统服务与复用：delay.c、sys.c、时钟、嘀嗒、sch/、ringbuf/
│   ├── STARTUP/          厂家启动文件 startup_<型号>.s
│   ├── LIBRARIES/        厂家库
│   │   ├── CMSIS/        core_cm<x>.h、system_<型号>.c
│   │   ├── <厂商>_StdPeriph/ 标准外设库（HAL 工程改名 _HAL/）
│   │   └── ld/           链接脚本 <型号>.ld
│   ├── OBJ/              构建目录：.o／.elf／.hex／CMake 缓存，不入库
│   ├── LIST/             .map／.lst，不入库
│   └── CMakeLists.txt    唯一的构建事实来源
├── references/           跨工程复用只读母本（如 sch_firmware/）
├── docs/                 文档：vendor/<厂商>/ 放手册、笔记、errata，design/ 放自研设计
├── tests/                宿主测试，与被测模块同名，独立于固件构建
├── tools/                烧写、打包、版本生成脚本
└── README.md
```

`firmware/` 这个名字覆盖了整个固件项目（编译单元 + 依赖库 + 产物），比 `src/` 准确——`OBJ/`、`LIST/` 这类生成物放进 `src/` 会自相矛盾。放 `HARDWARE/` 你清单里没提，但它是自研源码的一层，与 `APP`／`SYSTEM` 同级，必须一起进来，否则分层就断了。

| 文件类型 | 目录 | 可改性 |
|---|---|---|
| 程序入口 `main.c`、中断入口 `*_it.c` | `firmware/USER/` | 可改 |
| 板级配置头：`board_config.h`、引脚表、版本号 | `firmware/USER/` | 可改 |
| 中断优先级与延迟预算表 `irq-map.md` | `firmware/USER/` | 可改 |
| 应用源码：业务、协议、任务函数 | `firmware/APP/` | 可改 |
| 驱动源码：自研外设驱动 | `firmware/HARDWARE/` | 可改 |
| 系统源码：`delay.c`、`sys.c`、时钟、嘀嗒 | `firmware/SYSTEM/` | 可改 |
| 复用组件源码：sch、环形缓冲、CRC | `firmware/SYSTEM/<模块>/` | 可改 |
| 厂家启动文件 `startup_*.s` | `firmware/STARTUP/` | 仅可改栈／堆大小 |
| 链接脚本 `.ld` | `firmware/LIBRARIES/ld/` | 可改，段名与起止地址按手册核对 |
| 厂家库源码：CMSIS、标准外设库／HAL | `firmware/LIBRARIES/` | 不改 |
| 构建脚本 `CMakeLists.txt`、`*.cmake` | `firmware/` | 可改 |
| 厂家文档：手册、用户手册、应用笔记、errata | `docs/vendor/<厂商>/` | 只读 |
| 复用母本：`sch_firmware/` 等 | `references/` | 只读 |
| 宿主测试代码 | `tests/` | 可改 |
| 烧写、打包、版本生成脚本 | `tools/` | 可改 |
| 构建产物 `.o`／`.elf`／`.hex`、CMake 缓存 | `firmware/OBJ/` | 不进版本库 |
| 列表文件 `.map`／`.lst` | `firmware/LIST/` | 不进版本库 |

- **项目根不放代码**：根下只允许出现 `firmware/`、`references/`、`docs/`、`tests/`、`tools/` 五个目录与 `README.md`；出现 `.c`／`.h`／`CMakeLists.txt`／`.hex` 一律视为放错位置。新增顶层类别目录须在本节登记。
- **归属判据**：厂家给 → `firmware/STARTUP/`（启动文件）、`firmware/LIBRARIES/`（库）、`docs/vendor/`（文档）；自己写 → `firmware/USER/`（入口与板级配置）、`firmware/APP/`（业务）、`firmware/HARDWARE/`（驱动）、`firmware/SYSTEM/`（系统服务与复用）；测试 → `tests/`。判断不了归属的文件，说明分层没想清楚，先定层再写代码。
- **自研源码不落地在各层根下**：新文件先决定属于哪一层再写第一行代码；`firmware/USER/`、`firmware/APP/`、`firmware/HARDWARE/`、`firmware/SYSTEM/` 内不再按人或按日期建子目录。
- **厂家文件不就地改**：`firmware/LIBRARIES/` 保持原路径与文件名，需要改行为时在 `firmware/HARDWARE/` 包一层并注明来源与版本；升级库整目录替换，不逐个 merge。`firmware/STARTUP/` 的启动文件只允许改 `Stack_Size`／`Heap_Size` 与向量表项名，其余保持原样，改动写在文件头注释里。
- **依赖方向单向**：`firmware/APP` → `firmware/HARDWARE` → `firmware/SYSTEM`；`APP` 不直接 include `LIBRARIES` 里的头文件，寄存器操作集中在 `HARDWARE`／`SYSTEM`。`SYSTEM/sch` 通过 port 文件隔离芯片差异，不 include 任何厂商头文件。
- **一个模块一对文件**：`xxx.c` 与 `xxx.h` 同名同目录；头文件只放声明、宏、类型，不放变量定义。
- `references/` 只读，不放参与编译的源文件；使用时复制到 `firmware/SYSTEM/<模块>/`。
- **目录不超过三层**（`firmware/SYSTEM/sch/` 已在限内），再深就说明分层过细。
- 启动文件与链接脚本必须来自目标芯片自身：启动文件放 `firmware/STARTUP/`，链接脚本 `.ld` 放 `firmware/LIBRARIES/ld/`，不同型号不共用；段名、`ORIGIN`／`LENGTH`、堆栈大小逐项按手册核对。
- 测试放 `tests/`，与被测模块同名（`test_sch.c` 测 `firmware/SYSTEM/sch/sch.c`），编译时以相对路径引用固件源码，不复制一份到 `tests/`。
- **构建事实来源唯一**：源文件清单、宏定义、优化等级全部写在 `firmware/CMakeLists.txt` 与 toolchain 文件里，不引入 IDE 私有工程文件作为第二份清单；新增源文件只改 CMake，不在别处补登记。
- **构建命令固定从项目根执行**：`cmake -S firmware -B firmware/OBJ && cmake --build firmware/OBJ`。产物落在 `firmware/OBJ/`，`MAP` 输出到 `firmware/LIST/`；`.gitignore` 里写 `firmware/OBJ/` 与 `firmware/LIST/` 两行整体忽略，不在其中放任何需要保留的源文件。

## 2. 编码规范

### 2.1 类型与命名

- 协议字段、计数、寄存器值使用 `stdint.h` 定宽类型；布尔使用 `bool`／`true`／`false`。标准入口（如 `int main(void)`）、`size_t` 及厂商 SDK、测试框架接口遵循其规定类型，不改写 SDK 签名。
- 二进制数据用 `uint8_t`，有符号字节用 `int8_t`；不依赖编译器的 plain char 符号性。字符串可使用 `char`。
- 有符号／无符号混用先检查范围再转换。序列化逐字段编码，协议结构不使用位域，不依赖结构体填充或未对齐访问。
- 函数、局部变量 `snake_case`；函数带模块前缀；全局 `g_`、文件静态 `s_`；类型后缀 `_t`；宏和枚举常量大写。
- 函数原则上不超过 80 行、圈复杂度不超过 15、参数不超过 7 个；内部函数 `static`，只读数据参数加 `const`。
- 循环计数类型按范围选择；反向遍历用有符号计数或明确的零终止写法，避免无符号下溢。
- 局部变量声明时即初始化，不从栈上读取未定义值；结构体整体赋值前先清零。
- `switch` 必须写 `default` 分支（即使只是 `break` 或错误处理），不依赖枚举穷举隐式落到末尾。
- 常量优先 `enum` 或 `static const`；预处理、数组编译期尺寸等确需宏时使用宏。多语句宏用 `do { ... } while (0)`，参数加括号，避免重复求值副作用。
- 未启用 FPU 的目标不使用浮点运算；启用 FPU 时统一用 `float`，不混用 `double`（会拖入软浮点库，代码体积和耗时都暴涨）。浮点只用于测量值换算，不参与协议字段、计数和循环条件。
- 结构体大小、寄存器偏移、缓冲区容量等编译期可确定的量用 `_Static_assert` 校验，让错误在构建期暴露，不留到运行时。

### 2.2 格式与空行

缩进与括号：

- 4 空格缩进，禁用 Tab。行宽 ≤ 100 列。
- 函数定义左花括号另起行；控制结构（`if`／`for`／`while`／`switch`）左花括号同行；单行分支也必须加花括号。
- 指针星号靠变量：`uint8_t *buf`，不写 `uint8_t* buf`。

头文件：

- 保护统一用 `#ifndef <模块>_H` / `#define` / `#endif /* <模块>_H */` 三段式。`#pragma once` 虽被 GCC 支持，但为兼容其他工具链，全仓只用一种写法。
- 头文件只放声明、宏、类型定义和 `extern` 变量声明，不放变量定义和函数体（`static inline` 除外），杜绝重复定义。
- `#include` 组内按字母序排列，与空行分组规则配合使用。

空行（这是本规范的硬性要求，逐条执行）：

| 位置                                              | 空行数        |
| ------------------------------------------------- | ------------- |
| 文件头注释块 ↔ 首个 `#include`                    | 1             |
| `#include` 三大组之间（标准库／厂商 SDK／本项目） | 1             |
| `#include` 区 ↔ `#define` 区                      | 1             |
| 同一逻辑组内的 `#define` 连续书写                 | 0             |
| 不同语义组的 `#define` 之间                       | 1             |
| `#define` 区 ↔ `typedef`／`struct`／`enum` 区     | 1             |
| 各类型定义之间                                    | 1             |
| 类型定义区 ↔ 全局／文件静态变量区                 | 1             |
| 全局变量按语义分组，组之间                        | 1             |
| 变量区 ↔ 函数声明区                               | 1             |
| 函数声明区 ↔ 首个函数定义                         | 1             |
| 两个函数定义之间                                  | 1             |
| 函数内局部变量声明 ↔ 首个可执行语句               | 1             |
| 函数内逻辑段之间（初始化／主循环／错误处理）      | 1             |
| `return` 语句 ↔ 其前一条语句（非函数唯一语句时）  | 1             |
| 单行注释 ↔ 它所说明的代码                         | 0             |
| 文件末尾                                          | 保留 1 个换行 |

- 全文任何位置最多 1 个空行，不出现连续 2 个及以上空行；函数定义之间也不额外留白，靠花括号与函数注释自然分隔。

示例（同时示范命名、括号与空行位置）：

```c
/*
 * uart_port.c - 串口端口层
 */

#include <stdint.h>
#include <string.h>

#include "board.h"
#include "uart_port.h"

#define UART_RX_BUF_SIZE    256u
#define UART_TX_BUF_SIZE    256u

#define UART_EVT_RX_READY   (1u << 0)
#define UART_EVT_TX_IDLE    (1u << 1)

typedef enum {
    UART_OK        =  0,
    UART_ERR_PARAM = -1,
    UART_ERR_FULL  = -2,
} uart_status_t;

typedef struct {
    uint8_t  *buf;
    uint16_t  cap;
    uint16_t  head;
    uint16_t  tail;
} uart_ring_t;

static uart_ring_t          s_rx_ring;
static uart_ring_t          s_tx_ring;

static volatile uint32_t    s_rx_events;

static void uart_ring_init(uart_ring_t *ring, uint8_t *buf, uint16_t cap);
static int32_t uart_tx_enqueue(uint8_t port, const uint8_t *data, uint16_t length);

static void uart_ring_init(uart_ring_t *ring, uint8_t *buf, uint16_t cap)
{
    ring->buf  = buf;
    ring->cap  = cap;
    ring->head = 0u;
    ring->tail = 0u;
}

static uint16_t uart_ring_used(const uart_ring_t *ring)
{
    uint16_t head = ring->head;
    uint16_t tail = ring->tail;

    if (head >= tail) {
        return (uint16_t)(head - tail);
    }

    return (uint16_t)(ring->cap - tail + head);
}
```

- 建议用 `.clang-format` 固化（`MaxEmptyLinesToKeep: 1`、`SeparateDefinitionBlocks: Always`），格式争议交给工具，不做人工仲裁。

### 2.3 注释

- 每个自研 C 函数使用中文 Doxygen 注释说明用途；有参数或返回值时说明范围、语义、所有权、调用上下文、异步／超时及错误行为。无参数无返回值的不机械添加空条目。
- 重要语句就近解释用途、边界或原因，至少覆盖：时钟与 Flash 等待、外设／中断配置、临界区保存与恢复、共享数据发布、长度与 CRC 范围、字节序、溢出／回绕、超时、整帧提交及错误退出。普通连续赋值可按逻辑块统一说明，不逐行翻译代码。
- 严格区分"已入队"与"已发送完成"、"代码已配置"与"实板已验证"。调试初值注明来源及待定事项，不把未来功能写成当前已实现。
- Magic number 命名并说明来源；临时禁用内容注明原因，失效草稿删除。
- 新建注释使用 UTF-8 无 BOM。厂商 SDK、启动文件保留原文件、版权、编码并记录哈希，不为补注释批量改写。

### 2.4 main.c 工程信息头

`main.c` 在所有 `#include` 之前保留一段固定格式的工程信息头，只写"这块板子上什么资源被谁占用"，不写设计说明：

```c
/*
** <产品名> <型号>
** MCU: <型号>(<Flash>KB FLASH, <RAM>KB RAM)
** 时钟: HCLK = <xx>MHz，PCLK1 = <xx>MHz，PCLK2 = <xx>MHz，嘀嗒 = <1>ms
** 定时器: <TIMx> = <用途>，<TIMx> = <用途>
** 串口: <USARTx> = <用途>，<UARTx> = <用途>
** DMA/总线: <DMAx_Ch> = <用途>，<SPIx+DMAx_Ch> = <用途>
** 模拟: <ADCx> = <用途>，<COMPx> = <用途>
** 编译器: <工具链及版本>
** 支持库: <SDK / CMSIS 版本>
** 创建日期: <yyyy.m.d>  V<x.y>
** 修改记录: <yyyy.m.d>
*/
```

- **外设一律按实际使用填写**：只列工程里真正启用的外设和通道，某类资源没有就整行删掉，不留空占位；未分配或暂不用的外设不要先写进来占位。填写形如 `定时器: TIM2 = 回路接收，TIM3 = 蜂鸣器`。
- 时钟按芯片实际的总线命名写（HCLK／PCLK、AHB／APB、AHB1~4／APB1~2 等），该芯片不存在的总线不写；频率写**配置后的实际值**，不写晶振频率，也不写手册上限。嘀嗒需写明周期与来源（SysTick 还是某个定时器），例如 `嘀嗒 = 1ms（SysTick）`。
- 一行一类资源，同类合并到同一行，用中文顿号或逗号分隔；排序固定为时钟 → 定时器 → 串口 → DMA／SPI／其他总线 → 模拟外设，便于扫读。
- 编译器与支持库写**实际使用**的版本，不写"最新版"。GCC 路线填 `arm-none-eabi-gcc <x.y.z>` 加器件包／SDK 版本，不沿用旧工程 IDE 的版本号。
- 修改记录只保留最近一次修改日期，必要时补一句短语，不逐个版本累积历史。
- 型号、封装、容量和版本号都按实物与实物对应文档填写，不猜填；外设分配或工具链变化时同次更新。
- 信息头记录的是标称配置，不能替代实测。

## 3. 内存与共享数据

- 全部静态分配：缓冲、事件队列、工作区均在编译期确定；不使用动态分配、递归、VLA 或大栈数组。
- 缓冲区接口同时给出长度与容量，验证索引、NULL、零长度、重叠和溢出；所有权明确。重叠拷贝使用 `memmove`。
- 不使用 `strcpy`、`strcat`、`sprintf`、`gets`、`scanf`；确需格式化时使用有界接口并核算代码体积。
- ISR 与主循环共享值按可见性使用 `volatile`；它不提供复合操作原子性或事件顺序保证。即使单次对齐读写可原子完成，读改写和多字段快照仍须短临界区或已验证的单生产者单消费者协议。
- 临界区保存并恢复原中断状态，测量最坏关闭时间。队列满、溢出或丢边沿有明确计数和失败处理，不静默覆盖有效数据。
- 用 map 文件、`arm-none-eabi-size` 和实板栈水印检查 SRAM、栈及中断嵌套余量；栈保护选项须先确认工具链支持与空间成本再启用。
- NVM／校准区的大小、数量、地址、擦写约束和掉电恢复由资源设计定稿，并与链接脚本同步；链接脚本必须把该区域从代码段中显式排除，不能让链接器把代码或常量放进去。

## 4. 中断与时间

- **NVIC 优先级位宽以芯片手册为准**：Cortex-M0/M0+ 通常 2 位（0～3 级），M3/M4/M7/M33 通常 3～4 位。实现位数用 CMSIS 宏 `__NVIC_PRIO_BITS` 或回读 `SCB->IPR` 确认，不凭内核型号猜。数值越小优先级越高，禁止照搬其他型号的级数或分组配置。
- 多外设共用同一中断向量时（比较器、ADC、共用 USART 等）必须核对向量表，不能分别设置优先级。具体分配须结合最坏延迟验证后记录；故障关断与收发边沿优先，同级中断不能互相抢占。分配结果记入 `firmware/USER/irq-map.md`（与 `main.c` 同目录）：向量名、优先级、最坏执行时间、分配依据，随代码同仓维护，不散落在代码注释里。表内还须覆盖共用向量分派、最长关中断区间、延迟预算和 `SCH_MODE_ISR` 任务清单四项，只写优先级数字的表无法验证实时性。
- ISR 仅清标志、必要时读数据寄存器、打时间戳、短事件入队；明确故障时可直接执行最短安全关断动作，状态上报留到主循环。
- ISR 不打印、不等待、不写 Flash、不做整帧解析或业务流程；共享 IRQ 必须检查所有已启用来源，不因处理某一来源而误清其他来源。
- **定时器／看门狗的预分频语义因外设而异**（有的为 `PSC+1`，有的为 `2^PSC` 或固定分频），必须以参考手册核对，不能假设同族外设一致。在驱动实现前固定时钟树、计数频率、时间换算和溢出算法。
- 用定时器和截止时间管理等待，不用忙等待实现总线、供电或业务延时。有限硬件启动等待也应有上限，不能吞掉保护与串口响应。
- ISR 函数名必须与启动文件向量表中的名字完全一致（Cortex-M 上通常是 `<外设>_IRQHandler`），不手改向量表、不自行重命名。同一个向量被多个外设共用时，ISR 内先读状态寄存器判断来源，再分派。

## 5. 硬件边界与错误处理

- 业务经统一设备操作接口调用总线层，寄存器访问集中在 BSP／驱动；使用厂商头文件或 SVD 的寄存器定义，不硬编码寄存器地址，不混用其他厂商 HAL。
- 引脚集中配置并注明模式、上下拉、复用功能和安全初态。初始化顺序：先确保输出处于安全态（关断、写保护、控制线无效），再建立时钟与外设；清标志并准备好缓冲后再开放对应中断。
- 外设初始化返回可处理的状态；通信和重配置有超时，失败进入安全状态。是否使用 DMA 以实际芯片与 SDK 能力核对为前提，不把模板中的要求当作已具备功能。
- ADC 时钟、采样时间、输入阻抗及勘误按数据手册与勘误表执行；多个模拟外设并行工作需实测。
- 绝对额定值不能用作正常工作范围。时序、保护与检测阈值初值须标注"待实测"，不作为已验证参数。
- 返回值使用模块错误枚举或 `int32_t` 错误码，0 表示成功；负错误码与枚举不得混用同一变量。
- 记录错误来源及必要计数；不用 `assert` 处理运行期错误，不静默忽略外设失败。字符串诊断留在开发配置并核算体积。
- 带 Bootloader／IAP 的工程：APP 链接脚本的 `ORIGIN` 偏移、启动代码写入的 `SCB->VTOR`、实际烧写起始地址三者必须一致。跳转前关闭已使能的中断与 SysTick，跳转后重新初始化时钟和外设，不复用 Boot 的配置。

## 6. 裸机调度与看门狗

- 周期任务统一使用时间触发调度器。母本存档在项目 `references/sch_firmware/`（`sch.c`／`sch.h`／`sch_port.h`），**只读**，作为跨工程复用与升级来源；开发时复制到 `firmware/SYSTEM/sch/` 参与编译，构建只引用 `firmware/SYSTEM/` 下那份。`references/` 里的文件不直接修改，升级母本后重新复制并核对 `SCH_VERSION_STRING`，避免两处分叉。`sch_update()` 只放在嘀嗒中断里，`sch_dispatch()` 与 `sch_idle()` 放在主循环。不各自用定时器轮询、不自己写 `while` 计数延时、不在 main 里堆 `delay_ms()`。`sch_port.h` 是唯一与芯片相关的文件（`SCH_PORT_CMSIS`／`SCH_PORT_NONE`），`sch.c` 不得 include 任何厂商头文件。
- 任务注册集中在 `main.c`，一处可见全部周期任务；任务表规模由 `SCH_MAX_TASKS` 界定，超出返回 `SCH_ERR_FULL` 并在启动自检中报错，不静默丢弃。
- 时间参数一律用毫秒（`sch_add_task` 内部按节拍向上取整），不在业务代码里换算 tick。`SCH_TICK_MS` 必须与 SysTick 实际周期一致，`sch_init()` 会校验并在不一致时返回错误。
- 任务模式按"漏一次会不会丢东西"选，不按任务长短选。`SCH_MODE_COOP` 用于一次都不能漏的任务（计数、收包、Flash 记录、协议超时判定），错过的周期逐次补跑；`SCH_MODE_COOP_COALESCE` 用于只关心当前状态的任务（显示刷新、LED、状态上报），错过的多个周期合并成一次执行；`SCH_MODE_ISR` 只给极短且必须准时的任务。
- `SCH_MODE_COOP` 的积压超过 255 次才计入 `sch_overrun_count()`；`SCH_MODE_COOP_COALESCE` 被合并掉的触发计入 `sch_merged_count()`，非 0 说明该任务周期相对主循环负载偏短，应拉长周期或拆分任务。
- 合并任务必须是纯状态刷新：不能有"每周期累加一次"的副产物，不能发报文、不能写 Flash，否则被合并掉的周期就是丢数据。合并任务里也不要自己再判断"距上次多久"，那等于绕开调度器另建一套相位。
- 抢占模式（`SCH_MODE_ISR`）只允许放极短任务：无阻塞、无 Flash 写、无外设等待，最坏执行时间记入 `irq-map.md`。放不下就改成合作模式。
- 主循环处理有界工作量；串口、总线、保护、连续任务均通过状态机推进，同一时刻只持有一个设备总线任务。
- 保护逻辑可打断普通流程；安全关断独立于结果上报成功与否，通信拥塞不能延迟关断动作。
- 喂狗建立在主循环及各关键处理正常推进的证据上；等待外部应答只要超时管理与调度正常推进，不应被误判卡死。
- ISR 或单独定时器回调不能无条件喂狗。
- 独立看门狗通常由内部低速 RC 振荡器驱动，标称超时值不精确（常见 ±10% 以上偏差与温漂），最终超时须与最坏正常阻塞时间、时钟漂移一起核算；窗口看门狗还需核对喂狗窗口上下限。
- 调试器 halt 时看门狗仍在计数，单步和断点停留过久会触发复位。调试构建须在初始化时读取 `CoreDebug->DHCSR` 的 `C_DEBUGEN` 位并据此跳过喂狗或干脆不启动看门狗，不依赖"调试时手动拔狗"这类人工约定。
- 复位后回到安全待机，不自动重发写入、不自动恢复连续任务、不把未确认的写入报成功。

## 7. 工具链、调试与交付

- 目标参数（`-mcpu=cortex-m<?> -mthumb`，启用 FPU 时再加 `-mfpu=<型号> -mfloat-abi=hard|softfp`）在 CMake toolchain 文件里按内核统一指定，不零散写在单个 target 上。漏掉 `-mthumb` 会编出 ARM 状态代码，往往到链接阶段才报错。
- 编译选项基线（自研代码）：`-std=c11 -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-align -Wundef -Og -g3 -ffunction-sections -fdata-sections -fstack-usage`；发布用 `-Os`，不加 `-ffast-math`。
- 链接：`-Wl,--gc-sections -Wl,-Map=firmware/LIST/firmware.map -Wl,--print-memory-usage`，`--specs=nano.specs --specs=nosys.specs`（视 newlib 配置调整）；`MAP` 路径以项目根为基准，构建命令必须在项目根执行。
- `nano.specs` 的 `printf` 默认不支持 `%f`，会静默输出空值或 0。确实要打浮点需加 `-u _printf_float` 并核算体积，否则统一用放大整数（毫伏、0.1℃）打印。
- 自研代码警告清零；CI 中对自研文件启用 `-Werror`。厂商 SDK 的警告单独统计，不为消除警告改写 SDK。
- 静态分析基线：`cppcheck --project=compile_commands.json --enable=warning,style,performance --inline-suppr --suppress=missingIncludeSystem`，只扫自研目录。不追求零告警，但新增告警要么修掉，要么就地 `// cppcheck-suppress <id>` 并注明理由，不允许用全局 suppression 掩盖。
- 资源核查三件套：`arm-none-eabi-size` 看 text/data/bss，`.su` 文件看单函数栈用量，map 文件看最大栈链与段布局。
- 启动文件、链接脚本、器件包（DFP `.pack`）必须来自目标芯片自身，不从其他型号复制。器件包中的 SVD 用于外设寄存器视图。
- 启动代码必须完成 `.data` 从 Flash 到 SRAM 的初值复制和 `.bss` 清零，且在栈指针建立之后、进入 `main()` 之前执行。链接脚本新增或调整段（CCM／DTCM、备份域 SRAM、外部 RAM、不初始化段）时，同步检查启动代码是否需要处理该段，否则变量初值会是随机值。
- 不手改厂商库与生成文件以掩盖业务问题；必要适配放用户层并记录来源。
- 用 GPIO、定时器和示波器测时间；RTT／SWO 的能力与开销先核对。HardFault 诊断只访问该内核实际具备的故障寄存器，按 AAPCS 正确取得 MSP／PSP 栈帧，不复制其他内核的通用示例。
- 提交信息用 `type(scope): description`，排除 `firmware/OBJ/`、`firmware/LIST/` 构建产物与 `.vscode` 本地布局；版本使用语义化编号。验收证据（测试记录、实测波形、烧写日志）另行归档。

## 8. 测试与完成条件

- 电脑端可用 Unity 等轻量测试框架；从串口入口或公开模块边界注入设备事件、虚拟时间和 ADC 值，通过结果与输出验证，不绑定内部调用顺序。
- 核心协议／业务模块行覆盖率 > 80%，自研驱动 > 50%（驱动只要求关键路径与错误分支有覆盖，IO 时序类分支允许以实板验证替代）。分母排除厂商库、生成文件和测试代码，并列明排除原因。分支覆盖率记录但不另设门槛，关键故障路径必须有场景覆盖。覆盖率用 `gcov` + `lcov`／`gcovr` 在宿主编译配置下采集，不污染固件构建产物。
- 测试名 `test_模块_场景_期望结果`。测试替身参数明确为夹具，不写回实板配置；代码覆盖率不替代硬件验收。
- 软件测试、构建资源检查、实板验证证据分别记录；未执行项明确标记，待测阈值保持 needs-info。全部验收通过后才能宣称该项完成。

## 9. 落地检查清单

- [ ] §1 占位符已按实际型号填完，未填项标注 needs-info
- [ ] 新建文件已按 §1.1 归位（`firmware/` 下 `USER`／`APP`／`HARDWARE`／`SYSTEM`／`tests`），项目根只有 `firmware/`、`references/`、`docs/`、`tests/`、`tools/` 五个目录与 `README.md`
- [ ] 厂家文件未被就地修改，所有改动都在 `firmware/HARDWARE/` 或 `firmware/SYSTEM/` 层，并注明来源与版本
- [ ] `arm-none-eabi-gcc -v` 版本已写入 `main.c` 工程信息头
- [ ] 编译参数含 `-mcpu=<内核>` 与 `-mthumb`，已从 `compile_commands.json` 核实，不靠记忆
- [ ] 链接脚本中 Flash／SRAM 起止地址与芯片手册一致，已跑通一次完整链接
- [ ] 调试链路可用：`pyocd list` 或 `openocd -f <interface> -f <target>` 能连上并读到内核
- [ ] 器件包与 SVD 就位，VS Code 能显示外设寄存器
- [ ] NVIC 优先级位数已用 `__NVIC_PRIO_BITS` 或回读 `SCB->IPR` 确认
- [ ] IAP／Bootloader 工程：`ORIGIN` 偏移、`VTOR`、实际烧写地址三者已对齐
- [ ] 调试构建下看门狗不会误复位（`C_DEBUGEN` 判断已生效）
- [ ] `irq-map.md` 已建立，优先级分配与代码中的 NVIC 配置一致
- [ ] `references/sch_firmware/` 母本已存档，`firmware/SYSTEM/sch/` 副本已就位并进构建，两份 `SCH_VERSION_STRING` 一致
- [ ] `sch_init(SCH_TICK_MS)` 返回 `SCH_OK`，嘀嗒中断周期与 `SCH_TICK_MS` 一致
- [ ] 所有周期任务已集中注册在 `main.c`，没有漏网的定时器轮询
- [ ] 任务模式已按"漏一次会不会丢东西"分类；`SCH_MODE_COOP_COALESCE` 任务里没有累加、发报文、写 Flash；满负载压测下 `sch_merged_count()` 计数符合预期
- [ ] 全局变量初值已验证（`.data` 复制与 `.bss` 清零生效，不是随机值）
- [ ] `.clang-format` 已按 §2.2 空行规则配置，全仓格式化后 diff 干净
- [ ] `cppcheck` 基线已跑过一遍，告警已处理或就地标注理由
- [ ] 首次跑通"点灯 + 断点 + 单步 + 复位"四件事，再开始写业务
