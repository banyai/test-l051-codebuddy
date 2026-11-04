/*
 * sys.h - 系统时钟与嘀嗒中断配置
 */

#ifndef SYS_H
#define SYS_H

#include <stdint.h>

typedef enum {
    SYS_OK        =  0,
    SYS_ERR_CLOCK = -1,     /* 时钟源未在限定时间内就绪 */
    SYS_ERR_TICK  = -2,     /* SysTick 重载值非法 */
} sys_status_t;

/* 切换系统时钟到 PLL 输出，成功返回 SYS_OK */
sys_status_t sys_clock_init(void);

/* 启动 SysTick 周期中断，周期为 BOARD_TICK_MS */
sys_status_t sys_tick_init(void);

/* 当前 HCLK 频率（Hz），时钟切换后调用 SystemCoreClockUpdate 得到 */
uint32_t sys_hclk_hz(void);

#endif /* SYS_H */
