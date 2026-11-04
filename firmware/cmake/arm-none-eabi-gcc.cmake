# arm-none-eabi-gcc.cmake - CIU32L051 交叉编译工具链
#
# 用法：
#   cmake -G Ninja -B OBJ -DCMAKE_TOOLCHAIN_FILE=cmake/arm-none-eabi-gcc.cmake \
#         -DARM_TOOLCHAIN_DIR=<工具链根目录，其下有 bin/arm-none-eabi-gcc>
# ARM_TOOLCHAIN_DIR 省略时要求 arm-none-eabi-gcc 已在 PATH 中。

set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(WIN32)
    set(_exe_suffix ".exe")
else()
    set(_exe_suffix "")
endif()

if(ARM_TOOLCHAIN_DIR)
    file(TO_CMAKE_PATH "${ARM_TOOLCHAIN_DIR}" _toolchain_dir)
    set(_toolchain_bin "${_toolchain_dir}/bin/")
else()
    set(_toolchain_bin "")
endif()

set(CMAKE_C_COMPILER   "${_toolchain_bin}arm-none-eabi-gcc${_exe_suffix}")
set(CMAKE_ASM_COMPILER "${_toolchain_bin}arm-none-eabi-gcc${_exe_suffix}")
set(CMAKE_OBJCOPY      "${_toolchain_bin}arm-none-eabi-objcopy${_exe_suffix}")
set(CMAKE_SIZE         "${_toolchain_bin}arm-none-eabi-size${_exe_suffix}")

# Cortex-M0+ 只有 Thumb 状态，无 FPU，统一在工具链文件里指定
set(_cpu_flags "-mcpu=cortex-m0plus -mthumb -mfloat-abi=soft")

set(CMAKE_C_FLAGS_INIT   "${_cpu_flags}")
set(CMAKE_ASM_FLAGS_INIT "${_cpu_flags}")

set(CMAKE_EXE_LINKER_FLAGS_INIT "${_cpu_flags} --specs=nano.specs --specs=nosys.specs -nostartfiles")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
