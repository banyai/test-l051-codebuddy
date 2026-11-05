/*
 * lcd.h - 板载 YR1213C 段码液晶驱动（片内 LCD 控制器，电荷泵模式）
 */

#ifndef LCD_H
#define LCD_H

#include <stdint.h>

#define LCD_OK               (0)    /* 初始化或显示成功 */
#define LCD_ERR_CLOCK        (-1)   /* LXTAL 在超时时间内未就绪 */
#define LCD_ERR_PARAM        (-2)   /* 显示参数无效，屏幕已置全灭 */
#define LCD_STABLE_MS        (100u) /* 电荷泵电压稳定等待，取自 SDK 例程 */

/**
 * @brief  初始化 LCD 控制器与引脚，并使能电荷泵
 * @return LCD_OK 成功；LCD_ERR_CLOCK 表示 LCD 时钟源未就绪
 * @note   须在系统时钟、SysTick 与调度器初始化之后调用。
 *         本函数只让 COM/SEG 保持接 GND 的安全态，波形输出由 lcd_start_output() 开放。
 *         配置来源：SDK LCD_ChargePump_4COM 例程、UM1008 Rev1.2、RM1006 Rev2.0 第 17 章。
 */
int32_t lcd_init(void);

/**
 * @brief  开放 COM/SEG 波形输出（幂等）
 * @note   在 lcd_init() 之后至少 LCD_STABLE_MS 调用，避免电荷泵建立期间误驱动液晶。
 */
void lcd_start_output(void);

/**
 * @brief  熄灭所有段（LCD_RAM0~3 清零）
 */
void lcd_clear(void);

/**
 * @brief  显示最多 4 个字符
 * @param  text 以 '\0' 结尾的文本，支持 '0'~'9'、'-' 与空格
 * @return LCD_OK 成功；LCD_ERR_PARAM 参数无效（屏幕已置全灭）
 */
int32_t lcd_display_text(const char *text);

/**
 * @brief  显示 4 位十进制数（高位补零，超过 9999 回绕）
 * @param  value 待显示数值
 * @return LCD_OK 成功；LCD_ERR_PARAM 转换失败（屏幕已置全灭）
 */
int32_t lcd_display_number(uint32_t value);

#endif /* LCD_H */
