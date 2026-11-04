/*
 * sys.c - 系统时钟与 SysTick 配置
 *
 * 时钟树：RCH 16MHz -> PLL（M=12，N=2，PLLDIV=2）-> SYSCLK 48MHz
 *          HCLK = PCLK1 = PCLK2 = 48MHz，Flash 2 个等待周期。
 * 参数取自数据手册 DS1007（最高 48MHz）与厂商 GPIO 例程的时钟配置。
 */

#include <stdint.h>

#include "board_config.h"
#include "ciu32l051_std.h"
#include "sys.h"

#define SYS_CLOCK_TIMEOUT_LOOPS     (500000u)   /* 时钟就绪轮询上限，约数十毫秒 */
#define SYS_TICK_HZ                 (1000u / BOARD_TICK_MS)
#define SYS_TICK_PRIORITY           (3u)        /* NVIC 2 位优先级，3 为最低 */

/**
 * @brief  配置系统时钟：RCH -> PLL -> 48MHz
 * @retval SYS_OK 成功；SYS_ERR_CLOCK 表示某个时钟源在超时内未就绪
 * @note   切换到 48MHz 前必须先设置 Flash 等待周期，否则取指出错。
 */
sys_status_t sys_clock_init(void)
{
    uint32_t guard = 0u;

    /* 48MHz 时 HCLK > 32MHz，Flash 需要 2 个等待周期 */
    std_flash_set_latency(FLASH_LATENCY_2CLK);

    std_rcc_rch_enable();
    while (!std_rcc_get_rch_ready()) {
        if (++guard > SYS_CLOCK_TIMEOUT_LOOPS) {
            return SYS_ERR_CLOCK;
        }
    }

    /* PLL：16MHz × 12 / 2 / 2 = 48MHz */
    std_rcc_pll_config(RCC_PLLSRC_RCH, RCC_PLLM_MUL12, RCC_PLLN_DIV2, RCC_PLL_DIV2);
    std_rcc_pll_enable();

    guard = 0u;
    while (!std_rcc_get_pll_ready()) {
        if (++guard > SYS_CLOCK_TIMEOUT_LOOPS) {
            return SYS_ERR_CLOCK;
        }
    }

    std_rcc_pll_output_enable();

    std_rcc_set_sysclk_source(RCC_SYSCLK_SRC_PLLCLK);
    guard = 0u;
    while (std_rcc_get_sysclk_source() != RCC_SYSCLK_SRC_STATUS_PLLCLK) {
        if (++guard > SYS_CLOCK_TIMEOUT_LOOPS) {
            return SYS_ERR_CLOCK;
        }
    }

    /* 总线不分频，PCLK1 / PCLK2 与 HCLK 同频 */
    std_rcc_set_ahbdiv(RCC_HCLK_DIV1);
    std_rcc_set_apb1div(RCC_PCLK1_DIV1);
    std_rcc_set_apb2div(RCC_PCLK2_DIV1);

    SystemCoreClockUpdate();

    return SYS_OK;
}

/**
 * @brief  启动 SysTick 周期中断
 * @retval SYS_OK 成功；SYS_ERR_TICK 表示重载值超出 24 位计数范围
 * @note   中断服务函数在 firmware/USER/ciu32l051_it.c，只调用 sch_update()。
 */
sys_status_t sys_tick_init(void)
{
    if (SysTick_Config(SystemCoreClock / SYS_TICK_HZ) != 0u) {
        return SYS_ERR_TICK;
    }

    NVIC_SetPriority(SysTick_IRQn, SYS_TICK_PRIORITY);

    return SYS_OK;
}

/**
 * @brief  读取当前 HCLK 频率
 * @return HCLK 频率，单位 Hz
 */
uint32_t sys_hclk_hz(void)
{
    return SystemCoreClock;
}
