/*
 * sch_port.h - 调度器移植层
 *
 * 全文件只有这一处依赖具体芯片，换 MCU 只改这个文件。
 * 真机：定义 SCH_PORT_CMSIS，由 CMSIS 提供 PRIMASK 操作。
 * 宿主测试：定义 SCH_PORT_NONE，临界区与睡眠全部置空。
 * 其他内核（如 RISC-V）：照抄下面两组宏，换成对应 CSR 读写即可。
 */

#ifndef SCH_PORT_H
#define SCH_PORT_H

#include <stdint.h>

#if defined(SCH_PORT_CMSIS)

/* CMSIS 5：cmsis_compiler.h 会带上 cmsis_gcc.h / cmsis_armcc.h。
 * CMSIS 4（旧标准外设库）没有这个头文件，改成 #include "core_cm<?>.h"。 */
#include "cmsis_compiler.h"

typedef uint32_t sch_irq_state_t;

#define SCH_IRQ_SAVE()          __get_PRIMASK()
#define SCH_IRQ_DISABLE()       __disable_irq()
#define SCH_IRQ_RESTORE(state)  __set_PRIMASK(state)
#define SCH_IRQ_ENABLE()        __enable_irq()
#define SCH_IDLE()              __WFI()

#elif defined(SCH_PORT_NONE)

typedef uint32_t sch_irq_state_t;

#define SCH_IRQ_SAVE()          (0u)
#define SCH_IRQ_DISABLE()       ((void)0)
#define SCH_IRQ_RESTORE(state)  ((void)(state))
#define SCH_IRQ_ENABLE()        ((void)0)
#define SCH_IDLE()              ((void)0)

#else
#error "请定义 SCH_PORT_CMSIS 或 SCH_PORT_NONE（见 sch_port.h）"
#endif

#endif /* SCH_PORT_H */
