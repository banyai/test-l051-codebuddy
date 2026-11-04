# CIU32L051 LITE-64 核心板闪灯工程
#
# 构建命令固定从项目根执行：
#   cmake -S firmware -B firmware/OBJ -G Ninja \
#         -DCMAKE_TOOLCHAIN_FILE=<项目根>/firmware/cmake/arm-none-eabi-gcc.cmake \
#         -DARM_TOOLCHAIN_DIR=<工具链根目录>
#   （工具链文件写绝对路径：CMake 对 -DCMAKE_TOOLCHAIN_FILE 的相对路径解析基准是构建目录）
#   cmake --build firmware/OBJ
# 产物：firmware/OBJ/firmware.elf、firmware.hex、firmware.bin，
#       map 在 firmware/LIST/firmware.map。

cmake_minimum_required(VERSION 3.20)

project(ciu32l051_lite64_blink C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/OBJ")
set(CMAKE_EXECUTABLE_SUFFIX "")

# 构建类型：默认 Debug（-Og -g3），发布用 -DCMAKE_BUILD_TYPE=Release（-Os）
# 优化等级按规则 §7 基线固定在此处，不散落到单个源文件
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "构建类型：Debug / Release" FORCE)
endif()
set(CMAKE_C_FLAGS_DEBUG   "-Og -g3" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE "-Os"     CACHE STRING "" FORCE)

# 供 clangd、cppcheck 读取，输出 firmware/OBJ/compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# map 文件按规则落在 firmware/LIST/，构建时自动建立
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/LIST")

# 自研代码警告基线，厂商库单独编译时不受影响
set(SELF_WARN_FLAGS -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-align -Wundef
                    -ffunction-sections -fdata-sections -fstack-usage)

set(LIB_DIR   "${CMAKE_SOURCE_DIR}/LIBRARIES")
set(TICK_MS   1)

add_executable(firmware.elf
    STARTUP/startup_ciu32l051.s

    USER/main.c
    USER/ciu32l051_it.c

    APP/app_blink.c

    HARDWARE/led.c

    SYSTEM/sys.c
    SYSTEM/sch/sch.c

    LIBRARIES/CMSIS/Device/system_ciu32l051.c
    LIBRARIES/CIU32L051_StdPeriph/Source/ciu32l051_std.c
    LIBRARIES/CIU32L051_StdPeriph/Source/ciu32l051_std_flash.c
    LIBRARIES/CIU32L051_StdPeriph/Source/ciu32l051_std_gpio.c
    LIBRARIES/CIU32L051_StdPeriph/Source/ciu32l051_std_rcc.c

    LIBRARIES/ld/ciu32l051_flash.ld
)

target_include_directories(firmware.elf PRIVATE
    USER
    APP
    HARDWARE
    SYSTEM
    SYSTEM/sch
)

# 厂商头文件按系统头处理：其中的告警不计入自研代码告警基线
target_include_directories(firmware.elf SYSTEM PRIVATE
    ${LIB_DIR}/CMSIS/Core
    ${LIB_DIR}/CMSIS/Device
    ${LIB_DIR}/CIU32L051_StdPeriph/Include
)

target_compile_definitions(firmware.elf PRIVATE
    CIU32L051
    SCH_PORT_CMSIS
    SCH_TICK_MS=${TICK_MS}
)

# 自研源码：严格警告；厂商库：沿用其默认编译选项
set(SELF_SOURCES
    USER/main.c
    USER/ciu32l051_it.c
    APP/app_blink.c
    HARDWARE/led.c
    SYSTEM/sys.c
    SYSTEM/sch/sch.c
)

set_source_files_properties(${SELF_SOURCES} PROPERTIES COMPILE_OPTIONS "${SELF_WARN_FLAGS}")

target_link_options(firmware.elf PRIVATE
    -T${LIB_DIR}/ld/ciu32l051_flash.ld
    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_SOURCE_DIR}/LIST/firmware.map
    -Wl,--print-memory-usage
)

add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:firmware.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/firmware.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:firmware.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/firmware.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:firmware.elf>
)
