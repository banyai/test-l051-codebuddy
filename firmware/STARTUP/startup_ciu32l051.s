/*
 * startup_ciu32l051.s - CIU32L051 GCC 启动文件
 *
 * 来源：按 docs/vendor/HED/sdk/CIU32L051_STDLib_V1.0.11.rar 中
 *       Drivers/CMSIS/Device/Startup/arm/startup_ciu32l051.s 的向量表顺序与复位流程
 *       改写为 GNU as 语法；厂商未提供 GCC 版启动文件。
 * 约束：向量表项名与厂商启动文件逐项一致，不增删、不重排；
 *       仅栈大小按本工程需要调整（Stack_Size）。
 */

    .syntax unified
    .cpu cortex-m0plus
    .thumb

    .section .isr_vector, "a", %progbits
    .align  7
    .globl  __vector_table
    .type   __vector_table, %object
__vector_table:
    .word   _estack                         /* 初始 MSP */
    .word   Reset_Handler
    .word   NMI_Handler
    .word   HardFault_Handler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   SVC_Handler
    .word   0
    .word   0
    .word   PendSV_Handler
    .word   SysTick_Handler

    /* 外部中断，IRQ0 ~ IRQ31，与厂商启动文件顺序一致 */
    .word   WWDG_IRQHandler
    .word   PVD_IRQHandler
    .word   RTC_TAMP_IRQHandler
    .word   FLASH_IRQHandler
    .word   RCC_IRQHandler
    .word   EXTI0_1_IRQHandler
    .word   EXTI2_3_IRQHandler
    .word   EXTI4_15_IRQHandler
    .word   LCD_IRQHandler
    .word   DMA_Channel0_IRQHandler
    .word   DMA_Channel1_IRQHandler
    .word   0
    .word   ADC_COMP_IRQHandler
    .word   0
    .word   0
    .word   TIM3_IRQHandler
    .word   TIM4_IRQHandler
    .word   TIM5_IRQHandler
    .word   TIM8_IRQHandler
    .word   AES_IRQHandler
    .word   LPTIM1_IRQHandler
    .word   I2C1_IRQHandler
    .word   0
    .word   SPI1_IRQHandler
    .word   SPI2_IRQHandler
    .word   USART1_IRQHandler
    .word   UART2_IRQHandler
    .word   UART3_4_IRQHandler
    .word   LPUART1_IRQHandler
    .word   TRNG_IRQHandler
    .word   LPTIM2_IRQHandler
    .word   LPUART2_IRQHandler
    .size   __vector_table, . - __vector_table

    .text
    .thumb_func
    .globl  Reset_Handler
    .type   Reset_Handler, %function
Reset_Handler:
    /* .data 初值从 Flash 复制到 SRAM */
    ldr     r0, =_sidata
    ldr     r1, =_sdata
    ldr     r2, =_edata
    b       .L_copy_check
.L_copy:
    ldr     r3, [r0]
    str     r3, [r1]
    adds    r0, r0, #4
    adds    r1, r1, #4
.L_copy_check:
    cmp     r1, r2
    bcc     .L_copy

    /* .bss 清零 */
    ldr     r0, =_sbss
    ldr     r1, =_ebss
    movs    r2, #0
    b       .L_zero_check
.L_zero:
    str     r2, [r0]
    adds    r0, r0, #4
.L_zero_check:
    cmp     r0, r1
    bcc     .L_zero

    /* VTOR 指向向量表，并在进入 main 前完成 C 运行环境初始化 */
    bl      SystemInit
    bl      __libc_init_array
    bl      main

.L_hang:
    b       .L_hang
    .size   Reset_Handler, . - Reset_Handler

    .thumb_func
    .globl  Default_Handler
    .type   Default_Handler, %function
Default_Handler:
    b       Default_Handler
    .size   Default_Handler, . - Default_Handler

/* -nostartfiles 链接时 crt0 不参与，newlib 的 __libc_init_array 仍需这两个符号 */
    .thumb_func
    .globl  _init
    .type   _init, %function
_init:
    bx      lr
    .size   _init, . - _init

    .thumb_func
    .globl  _fini
    .type   _fini, %function
_fini:
    bx      lr
    .size   _fini, . - _fini

/* 全部中断入口按厂商向量表命名，未实现的处理函数落到 Default_Handler */
    .weak   NMI_Handler
    .thumb_set NMI_Handler, Default_Handler
    .weak   HardFault_Handler
    .thumb_set HardFault_Handler, Default_Handler
    .weak   SVC_Handler
    .thumb_set SVC_Handler, Default_Handler
    .weak   PendSV_Handler
    .thumb_set PendSV_Handler, Default_Handler
    .weak   SysTick_Handler
    .thumb_set SysTick_Handler, Default_Handler
    .weak   WWDG_IRQHandler
    .thumb_set WWDG_IRQHandler, Default_Handler
    .weak   PVD_IRQHandler
    .thumb_set PVD_IRQHandler, Default_Handler
    .weak   RTC_TAMP_IRQHandler
    .thumb_set RTC_TAMP_IRQHandler, Default_Handler
    .weak   FLASH_IRQHandler
    .thumb_set FLASH_IRQHandler, Default_Handler
    .weak   RCC_IRQHandler
    .thumb_set RCC_IRQHandler, Default_Handler
    .weak   EXTI0_1_IRQHandler
    .thumb_set EXTI0_1_IRQHandler, Default_Handler
    .weak   EXTI2_3_IRQHandler
    .thumb_set EXTI2_3_IRQHandler, Default_Handler
    .weak   EXTI4_15_IRQHandler
    .thumb_set EXTI4_15_IRQHandler, Default_Handler
    .weak   LCD_IRQHandler
    .thumb_set LCD_IRQHandler, Default_Handler
    .weak   DMA_Channel0_IRQHandler
    .thumb_set DMA_Channel0_IRQHandler, Default_Handler
    .weak   DMA_Channel1_IRQHandler
    .thumb_set DMA_Channel1_IRQHandler, Default_Handler
    .weak   ADC_COMP_IRQHandler
    .thumb_set ADC_COMP_IRQHandler, Default_Handler
    .weak   TIM3_IRQHandler
    .thumb_set TIM3_IRQHandler, Default_Handler
    .weak   TIM4_IRQHandler
    .thumb_set TIM4_IRQHandler, Default_Handler
    .weak   TIM5_IRQHandler
    .thumb_set TIM5_IRQHandler, Default_Handler
    .weak   TIM8_IRQHandler
    .thumb_set TIM8_IRQHandler, Default_Handler
    .weak   AES_IRQHandler
    .thumb_set AES_IRQHandler, Default_Handler
    .weak   LPTIM1_IRQHandler
    .thumb_set LPTIM1_IRQHandler, Default_Handler
    .weak   I2C1_IRQHandler
    .thumb_set I2C1_IRQHandler, Default_Handler
    .weak   SPI1_IRQHandler
    .thumb_set SPI1_IRQHandler, Default_Handler
    .weak   SPI2_IRQHandler
    .thumb_set SPI2_IRQHandler, Default_Handler
    .weak   USART1_IRQHandler
    .thumb_set USART1_IRQHandler, Default_Handler
    .weak   UART2_IRQHandler
    .thumb_set UART2_IRQHandler, Default_Handler
    .weak   UART3_4_IRQHandler
    .thumb_set UART3_4_IRQHandler, Default_Handler
    .weak   LPUART1_IRQHandler
    .thumb_set LPUART1_IRQHandler, Default_Handler
    .weak   TRNG_IRQHandler
    .thumb_set TRNG_IRQHandler, Default_Handler
    .weak   LPTIM2_IRQHandler
    .thumb_set LPTIM2_IRQHandler, Default_Handler
    .weak   LPUART2_IRQHandler
    .thumb_set LPUART2_IRQHandler, Default_Handler
