/*
 * lcd_segments.h - 板载 YR1213C 段码屏字符编码（不依赖 MCU 头文件）
 *
 * 依据：UM1008 Rev1.2 图 2-3 真值表，以及 CIU32L051_STDLib V1.0.11 例程
 *       Projects/LCD/LCD_ChargePump_4COM/Source/lcd_segment_yr1213c.c。
 * 一个字符占 SEG(2n)、SEG(2n+1) 两个端子（n = 0~3），
 * 1/4 duty 下 4 个 COM 对应 LCD_RAM0~3，每个字的 bit(2n)/bit(2n+1) 存该字符段码。
 */

#ifndef LCD_SEGMENTS_H
#define LCD_SEGMENTS_H

#include <stdint.h>

#define LCD_SEGMENT_DIGITS      (4u)                      /* 屏上 4 个七段字符位置 */
#define LCD_SEGMENT_COM_COUNT   (4u)                      /* 1/4 duty 只用 LCD_RAM0~3 */
#define LCD_SEGMENT_TEXT_SIZE   (LCD_SEGMENT_DIGITS + 1u) /* 含字符串结束符 */
#define LCD_SEGMENTS_OK         (0)                       /* 转换成功 */
#define LCD_SEGMENTS_ERR_PARAM  (-1)                      /* 参数为空，输出已置全灭 */

typedef struct {
    uint32_t com[LCD_SEGMENT_COM_COUNT]; /* 每个 COM 对应的 32 位显示存储器值 */
} lcd_segments_frame_t;

/**
 * @brief  把最多 4 个字符转换成 4 个 COM 的 LCD_RAM 位图
 * @param  text 以 '\0' 结尾的文本；NULL 视为空文本，输出全灭
 * @param  frame 输出帧；NULL 时只返回错误码
 * @return LCD_SEGMENTS_OK 成功；LCD_SEGMENTS_ERR_PARAM 参数为空
 * @note   支持 '0'~'9'、'-' 与空格；其余字符按熄灭处理。
 *         短文本只影响对应位置，多余位置保持熄灭。
 */
int32_t lcd_segments_build_frame(const char *text, lcd_segments_frame_t *frame);

/**
 * @brief  把无符号数格式化为 4 位十进制文本（高位补零，超过 4 位回绕）
 * @param  value 待显示数值
 * @param  text 输出缓冲，容量 LCD_SEGMENT_TEXT_SIZE，含结束符
 * @return LCD_SEGMENTS_OK 成功；LCD_SEGMENTS_ERR_PARAM 缓冲为空
 * @note   不使用 sprintf 等格式化接口；回绕取模保证不会写出 4 位之外的内容。
 */
int32_t lcd_segments_format_number(uint32_t value, char text[LCD_SEGMENT_TEXT_SIZE]);

#endif /* LCD_SEGMENTS_H */
