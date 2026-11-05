/*
 * lcd_segments.c - YR1213C 段码屏字符到 LCD_RAM 位图的转换
 */

#include <stddef.h>

#include "lcd_segments.h"

#define LCD_SEGMENTS_MINUS_CODE (0x0020u) /* 仅 COM2 的 G 段亮：字段 2 << 4 */
#define LCD_SEGMENTS_BLANK_CODE (0x0000u) /* 空格及不支持字符：全部段熄灭 */
#define LCD_SEGMENTS_BASE       (10000u)  /* 4 位十进制显示容量，用于回绕 */
#define LCD_SEGMENTS_DIV_INIT   (1000u)   /* 最高位的十进制权值 */

/*
 * 字符编码由高到低分 4 个 4bit 字段，依次对应 COM0~COM3；每字段仅低 2 位有效：
 *   bit0 = SEG(2n) 上的段，bit1 = SEG(2n+1) 上的段。
 * 段矩阵：SEG(2n)   = { COM0: H/空, COM1: E, COM2: F, COM3: A }
 *         SEG(2n+1) = { COM0: D,    COM1: C, COM2: G, COM3: B }
 * 0~9 数值取自 SDK LCD_ChargePump_4COM 例程的 digit_map，与 UM1008 真值表一致。
 */
static const uint16_t s_digit_code[10] = {
    0x2313u, 0x0202u, 0x2123u, 0x2223u, 0x0232u,
    0x2231u, 0x2331u, 0x0203u, 0x2333u, 0x2233u
};

/**
 * @brief  查询单个字符的 16 位段码
 * @param  ch 待显示字符
 * @return 对应段码；不支持的字符返回全灭编码
 */
static uint16_t lcd_segments_lookup(char ch)
{
    if ((ch >= '0') && (ch <= '9')) {
        return s_digit_code[(uint32_t)(ch - '0')];
    }
    if (ch == '-') {
        return LCD_SEGMENTS_MINUS_CODE;
    }
    return LCD_SEGMENTS_BLANK_CODE;
}

/**
 * @brief  把最多 4 个字符转换成 4 个 COM 的 LCD_RAM 位图
 * @param  text 以 '\0' 结尾的文本；NULL 视为空文本，输出全灭
 * @param  frame 输出帧；NULL 时只返回错误码
 * @return LCD_SEGMENTS_OK 成功；LCD_SEGMENTS_ERR_PARAM 参数为空
 * @note   先把帧清零再逐字符叠加，保证任何错误路径都落在"全灭"安全态。
 */
int32_t lcd_segments_build_frame(const char *text, lcd_segments_frame_t *frame)
{
    uint32_t com;
    uint32_t pos;

    if (frame == NULL) {
        return LCD_SEGMENTS_ERR_PARAM;
    }
    for (com = 0u; com < LCD_SEGMENT_COM_COUNT; ++com) {
        frame->com[com] = 0u;
    }
    if (text == NULL) {
        return LCD_SEGMENTS_ERR_PARAM;
    }
    for (pos = 0u; (pos < LCD_SEGMENT_DIGITS) && (text[pos] != '\0'); ++pos) {
        uint16_t code = lcd_segments_lookup(text[pos]);

        for (com = 0u; com < LCD_SEGMENT_COM_COUNT; ++com) {
            uint32_t shift = 12u - (4u * com);
            uint32_t bits = ((uint32_t)code >> shift) & 0x03u;

            /* 每个字符占连续两位：SEG(2n) 与 SEG(2n+1) */
            frame->com[com] |= bits << (2u * pos);
        }
    }
    return LCD_SEGMENTS_OK;
}

/**
 * @brief  把无符号数格式化为 4 位十进制文本（高位补零，超过 4 位回绕）
 * @param  value 待显示数值
 * @param  text 输出缓冲，容量 LCD_SEGMENT_TEXT_SIZE，含结束符
 * @return LCD_SEGMENTS_OK 成功；LCD_SEGMENTS_ERR_PARAM 缓冲为空
 * @note   逐位取商，除法权值从 1000 递减到 1；不使用 libc 格式化接口。
 */
int32_t lcd_segments_format_number(uint32_t value, char text[LCD_SEGMENT_TEXT_SIZE])
{
    uint32_t rest = value % LCD_SEGMENTS_BASE;
    uint32_t divisor = LCD_SEGMENTS_DIV_INIT;
    uint32_t pos;

    if (text == NULL) {
        return LCD_SEGMENTS_ERR_PARAM;
    }
    for (pos = 0u; pos < LCD_SEGMENT_DIGITS; ++pos) {
        text[pos] = (char)('0' + (char)(rest / divisor));
        rest %= divisor;
        divisor /= 10u;
    }
    text[LCD_SEGMENT_DIGITS] = '\0';
    return LCD_SEGMENTS_OK;
}
