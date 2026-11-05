/*
 * lcd.c - 板载 YR1213C 段码液晶驱动
 *
 * 硬件：UM1008 Rev1.2 §2.5，4COM×8SEG、1/4 duty、1/3 bias、3.3V，
 *       电荷泵模式；屏的 COM0~3/SEG0~7 经 0Ω 电阻接 MCU。
 * 配置：SDK CIU32L051_STDLib V1.0.11 的 LCD_ChargePump_4COM 例程，
 *       寄存器语义核对 RM1006 Rev2.0 第 17 章。
 */

#include <stddef.h>
#include <stdint.h>

#include "board_config.h"
#include "lcd.h"
#include "lcd_segments.h"
#include "sch.h"

#include "ciu32l051_std.h"

#define LCD_LXTAL_READY_MS (5000u) /* 起振等待上限，取 SDK std_config.h 的 LXTAL_READY_TIMEOUT */

/**
 * @brief  把 COM/SEG 引脚配置为 LCD 复用功能
 * @note   GPIO_MODE_ALTERNATE + GPIO_AF3_LCD、无上下拉、推挽（与 SDK 例程零初始化等价）。
 *         PA13/PA14 是 SWD，PA10~12/PA15 与之不冲突；PB14 的用户 LED 也不在 LCD 脚位内。
 */
static void lcd_gpio_init(void)
{
    std_gpio_init_t cfg = {0};

    std_rcc_gpio_clk_enable(BOARD_LCD_GPIO_CLK);

    cfg.mode = GPIO_MODE_ALTERNATE;
    cfg.pull = GPIO_NOPULL;
    cfg.output_type = GPIO_OUTPUT_PUSHPULL;
    cfg.alternate = BOARD_LCD_AF;

    cfg.pin = BOARD_LCD_PORTA_PINS; /* PA10/11/12 = COM0~2，PA15 = SEG0 */
    std_gpio_init(GPIOA, &cfg);

    cfg.pin = BOARD_LCD_PORTB_PINS; /* PB3~7 = SEG3~7 */
    std_gpio_init(GPIOB, &cfg);

    cfg.pin = BOARD_LCD_PORTC_PINS; /* PC9 = COM3，PC10/11 = SEG1/2 */
    std_gpio_init(GPIOC, &cfg);
}

/**
 * @brief  启动 LXTAL 并选择它作为 RTC/LCD 时钟源
 * @return LCD_OK 成功；LCD_ERR_CLOCK 表示 5s 内 LXTAL 未就绪
 * @note   RCC_AWCR 属备份域，写前须用 std_pmu_vaon_write_enable() 解锁，写完立即恢复保护；
 *         超时也走同一恢复路径。超时用 SysTick 的毫秒时间判断，不用忙等计数换算，
 *         32 位毫秒回绕时差值依然正确；调用前必须已初始化 SysTick 与调度器。
 */
static int32_t lcd_clock_init(void)
{
    uint32_t start_ms = sch_time_ms();

    std_rcc_apb1_clk_enable(RCC_PERIPH_CLK_PMU);
    std_pmu_vaon_write_enable();

    /* 板载 32.768kHz 晶体，驱动能力按 SDK 例程取增强模式、等级 2 */
    std_rcc_lxtal_drive_mode_config(RCC_LXTAL_DRIVE_MODE_ENHANCE);
    std_rcc_lxtal_drive_config(RCC_LXTAL_DRIVE_LEVEL2);
    std_rcc_lxtal_enable(RCC_LXTAL_ON);

    while (!std_rcc_get_lxtal_ready()) {
        if ((sch_time_ms() - start_ms) >= LCD_LXTAL_READY_MS) {
            std_pmu_vaon_write_disable();
            return LCD_ERR_CLOCK;
        }
    }
    std_rcc_set_rtcclk_source(RCC_RTC_ASYNC_CLK_SRC_LXTAL);
    std_pmu_vaon_write_disable();

    return LCD_OK;
}

/**
 * @brief  配置 LCD 控制器并使能电荷泵
 * @note   先设 SCOC=GND 使 COM/SEG 在 LCDEN=1 后仍接 GND（安全初态），
 *         再由 std_lcd_init() 置 LCDEN=1 启动电荷泵；波形输出留给 lcd_start_output()。
 *         PS=8、DIV=31，32768Hz 下帧率约 32Hz（SDK 例程标称值）；
 *         1/4 duty 必须开区段多路复用；1/3 bias 只接 V1/V2/VLCD 三只外部电容。
 *         闪烁、死区、高驱、脉冲持续时间保持复位值（均为禁止/0）。
 */
static void lcd_controller_init(void)
{
    std_lcd_init_t cfg = {0};

    std_rcc_apb1_clk_enable(RCC_PERIPH_CLK_LCD);
    std_lcd_set_anti_polar(LCD_ANTIPOLAR_GND);
    std_lcd_set_scoc(LCD_SCOC_GND);
    std_lcd_v1_cap_enable();
    std_lcd_v2_cap_enable();
    std_lcd_vlcd_cap_enable();
    std_lcd_set_chargepump_clock(LCD_CPCLK_DIV16);

    cfg.mux_segment = LCD_MUX_SEGMENT_ENABLE;
    cfg.bias = LCD_BIAS_1_3;
    cfg.duty = LCD_DUTY_1_4;
    cfg.driver_mode = LCD_DRIVER_MODE_CHARGE_PUMP;
    cfg.prescaler = LCD_PRESCALER_8;
    cfg.divider = LCD_DIVIDER_31;
    cfg.vlcd_voltage = LCD_CHAGE_PUMP_1_3_BIAS_3_30V;
    cfg.high_drive = LCD_LOW_DRIVE;
    cfg.pulse_on_duration = LCD_PULSE_ON_DURATION_0;

    std_lcd_init(&cfg);
}

/**
 * @brief  初始化 LCD 控制器与引脚，并使能电荷泵
 * @return LCD_OK 成功；LCD_ERR_CLOCK 表示 LCD 时钟源未就绪
 * @note   须在系统时钟、SysTick 与调度器初始化之后调用。
 *         本函数只让 COM/SEG 保持接 GND 的安全态，波形输出由 lcd_start_output() 开放。
 */
int32_t lcd_init(void)
{
    lcd_gpio_init();
    if (lcd_clock_init() != LCD_OK) {
        return LCD_ERR_CLOCK;
    }
    lcd_controller_init();
    lcd_clear();

    return LCD_OK;
}

/**
 * @brief  开放 COM/SEG 波形输出（幂等）
 * @note   在 lcd_init() 之后至少 LCD_STABLE_MS 调用，避免电荷泵建立期间误驱动液晶。
 */
void lcd_start_output(void)
{
    std_lcd_set_scoc(LCD_SCOC_OUT);
}

/**
 * @brief  熄灭所有段（LCD_RAM0~3 清零）
 */
void lcd_clear(void)
{
    uint32_t com;

    for (com = 0u; com < LCD_SEGMENT_COM_COUNT; ++com) {
        /* mask=0 表示整字替换；本板只接 SEG0~7，其余位一并清零 */
        std_lcd_write(LCD_RAM_REGISTER0 + com, 0u, 0u);
    }
}

/**
 * @brief  显示最多 4 个字符
 * @param  text 以 '\0' 结尾的文本，支持 '0'~'9'、'-' 与空格
 * @return LCD_OK 成功；LCD_ERR_PARAM 参数无效（屏幕已置全灭）
 * @note   整帧一次提交：先由纯逻辑层算出 4 个 COM 字，再逐字写 LCD_RAM。
 */
int32_t lcd_display_text(const char *text)
{
    lcd_segments_frame_t frame;
    uint32_t com;

    if (lcd_segments_build_frame(text, &frame) != LCD_SEGMENTS_OK) {
        lcd_clear();
        return LCD_ERR_PARAM;
    }
    for (com = 0u; com < LCD_SEGMENT_COM_COUNT; ++com) {
        /* mask=0 表示整字替换，避免残留上一条文本的点亮段 */
        std_lcd_write(LCD_RAM_REGISTER0 + com, 0u, frame.com[com]);
    }
    return LCD_OK;
}

/**
 * @brief  显示 4 位十进制数（高位补零，超过 9999 回绕）
 * @param  value 待显示数值
 * @return LCD_OK 成功；LCD_ERR_PARAM 转换失败（屏幕已置全灭）
 */
int32_t lcd_display_number(uint32_t value)
{
    char text[LCD_SEGMENT_TEXT_SIZE];

    if (lcd_segments_format_number(value, text) != LCD_SEGMENTS_OK) {
        lcd_clear();
        return LCD_ERR_PARAM;
    }
    return lcd_display_text(text);
}
