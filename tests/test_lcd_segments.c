/*
 * test_lcd_segments.c - 段码编码层宿主测试（不依赖 MCU）
 *
 * 用独立的七段字符表交叉验证 SDK digit_map，并验证位置移位、
 * 短文本、未知字符、空指针与四位数字格式化。
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "../firmware/HARDWARE/lcd_segments.h"

#define SEG_A (0x01u)
#define SEG_B (0x02u)
#define SEG_C (0x04u)
#define SEG_D (0x08u)
#define SEG_E (0x10u)
#define SEG_F (0x20u)
#define SEG_G (0x40u)

/* 标准七段字形，独立于被测的 digit_map：0~9 的 A~G 段组合 */
static const uint8_t s_seven_seg[10] = {
    (uint8_t)(SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F),
    (uint8_t)(SEG_B | SEG_C),
    (uint8_t)(SEG_A | SEG_B | SEG_D | SEG_E | SEG_G),
    (uint8_t)(SEG_A | SEG_B | SEG_C | SEG_D | SEG_G),
    (uint8_t)(SEG_B | SEG_C | SEG_F | SEG_G),
    (uint8_t)(SEG_A | SEG_C | SEG_D | SEG_F | SEG_G),
    (uint8_t)(SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G),
    (uint8_t)(SEG_A | SEG_B | SEG_C),
    (uint8_t)(SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G),
    (uint8_t)(SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G)
};

static int s_failures;

static void check(int condition, const char *case_name)
{
    if (condition == 0) {
        printf("FAIL: %s\n", case_name);
        ++s_failures;
    }
}

static void check_frame(const lcd_segments_frame_t *frame, uint32_t c0, uint32_t c1,
                        uint32_t c2, uint32_t c3, const char *case_name)
{
    check((frame->com[0] == c0) && (frame->com[1] == c1) &&
          (frame->com[2] == c2) && (frame->com[3] == c3), case_name);
}

/* 按 UM1008 真值表把标准七段字形拆成 4 个 COM 的两位段码 */
static uint32_t com_bits(uint8_t seven, uint32_t com)
{
    uint32_t bits = 0u;

    switch (com) {
    case 0u: /* SEG(2n+1)=D，SEG(2n)=H（本工程不使用） */
        bits = (seven & SEG_D) ? 0x02u : 0u;
        break;
    case 1u: /* SEG(2n)=E，SEG(2n+1)=C */
        bits = ((seven & SEG_E) ? 0x01u : 0u) | ((seven & SEG_C) ? 0x02u : 0u);
        break;
    case 2u: /* SEG(2n)=F，SEG(2n+1)=G */
        bits = ((seven & SEG_F) ? 0x01u : 0u) | ((seven & SEG_G) ? 0x02u : 0u);
        break;
    case 3u: /* SEG(2n)=A，SEG(2n+1)=B */
        bits = ((seven & SEG_A) ? 0x01u : 0u) | ((seven & SEG_B) ? 0x02u : 0u);
        break;
    default:
        bits = 0xFFu; /* 不该出现，故意让断言失败 */
        break;
    }
    return bits;
}

static void test_digit_table(void)
{
    uint32_t digit;
    uint32_t com;

    for (digit = 0u; digit < 10u; ++digit) {
        char text[2] = {(char)('0' + (char)digit), '\0'};
        lcd_segments_frame_t frame;

        check(lcd_segments_build_frame(text, &frame) == LCD_SEGMENTS_OK, "digit build");
        for (com = 0u; com < LCD_SEGMENT_COM_COUNT; ++com) {
            check(frame.com[com] == com_bits(s_seven_seg[digit], com), "digit segment map");
        }
    }
}

static void test_positions(void)
{
    lcd_segments_frame_t frame;

    check(lcd_segments_build_frame("0000", &frame) == LCD_SEGMENTS_OK, "0000 build");
    check_frame(&frame, 0xAAu, 0xFFu, 0x55u, 0xFFu, "0000 positions");

    check(lcd_segments_build_frame("1234", &frame) == LCD_SEGMENTS_OK, "1234 build");
    check_frame(&frame, 0x28u, 0xA6u, 0xE8u, 0xBEu, "1234 positions");

    check(lcd_segments_build_frame("----", &frame) == LCD_SEGMENTS_OK, "minus build");
    check_frame(&frame, 0u, 0u, 0xAAu, 0u, "minus only COM2/G");

    check(lcd_segments_build_frame("12", &frame) == LCD_SEGMENTS_OK, "short build");
    check_frame(&frame, 0x08u, 0x06u, 0x08u, 0x0Eu, "short text leaves rest blank");

    check(lcd_segments_build_frame("A ?", &frame) == LCD_SEGMENTS_OK, "unsupported build");
    check_frame(&frame, 0u, 0u, 0u, 0u, "unsupported chars are blank");
}

static void test_null_and_long_text(void)
{
    lcd_segments_frame_t frame;

    frame.com[0] = 0xFFFFFFFFu;
    check(lcd_segments_build_frame(NULL, &frame) == LCD_SEGMENTS_ERR_PARAM, "null text rc");
    check_frame(&frame, 0u, 0u, 0u, 0u, "null text clears frame");
    check(lcd_segments_build_frame("12345", NULL) == LCD_SEGMENTS_ERR_PARAM, "null frame rc");

    check(lcd_segments_build_frame("12345", &frame) == LCD_SEGMENTS_OK, "long build");
    check_frame(&frame, 0x28u, 0xA6u, 0xE8u, 0xBEu, "long text truncated to 4 digits");
}

static void test_number_format(void)
{
    char text[LCD_SEGMENT_TEXT_SIZE];
    const char *expected;

    check(lcd_segments_format_number(0u, NULL) == LCD_SEGMENTS_ERR_PARAM, "null number buffer");

    check(lcd_segments_format_number(0u, text) == LCD_SEGMENTS_OK, "format 0 rc");
    check((text[0] == '0') && (text[1] == '0') && (text[2] == '0') &&
          (text[3] == '0') && (text[4] == '\0'), "format 0 text");

    check(lcd_segments_format_number(7u, text) == LCD_SEGMENTS_OK, "format 7 rc");
    check((text[0] == '0') && (text[3] == '7'), "format 7 leading zeros");

    check(lcd_segments_format_number(1234u, text) == LCD_SEGMENTS_OK, "format 1234 rc");
    expected = "1234";
    check((text[0] == expected[0]) && (text[1] == expected[1]) &&
          (text[2] == expected[2]) && (text[3] == expected[3]), "format 1234 text");

    check(lcd_segments_format_number(10000u, text) == LCD_SEGMENTS_OK, "wrap rc");
    check((text[0] == '0') && (text[3] == '0'), "format wraps at 10000");

    check(lcd_segments_format_number(UINT32_MAX, text) == LCD_SEGMENTS_OK, "uint32 max rc");
    expected = "7295";
    check((text[0] == expected[0]) && (text[1] == expected[1]) &&
          (text[2] == expected[2]) && (text[3] == expected[3]), "uint32 max text");
}

int main(void)
{
    test_digit_table();
    test_positions();
    test_null_and_long_text();
    test_number_format();

    printf("lcd_segments: %d failure(s)\n", s_failures);
    return (s_failures == 0) ? 0 : 1;
}
