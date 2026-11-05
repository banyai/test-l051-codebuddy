# 宿主测试：只编译与 MCU 无关的段码编码层，不参与固件交叉构建
cmake_minimum_required(VERSION 3.20)

project(lcd_segments_host C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

add_executable(test_lcd_segments
    test_lcd_segments.c
    ../firmware/HARDWARE/lcd_segments.c
)

target_include_directories(test_lcd_segments PRIVATE ../firmware/HARDWARE)

add_test(NAME lcd_segments COMMAND test_lcd_segments)
