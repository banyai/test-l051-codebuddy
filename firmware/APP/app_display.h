/*
 * app_display.h - 板载段码液晶显示应用
 */

#ifndef APP_DISPLAY_H
#define APP_DISPLAY_H

#define APP_DISPLAY_REFRESH_MS (20u) /* 显示状态刷新周期 */

/* 启动时写入 "0000"，并记录电荷泵开始建立的时间 */
void app_display_init(void);

/* 周期任务：开放波形输出后显示运行秒数（4 位，模 10000） */
void app_display_task(void);

#endif /* APP_DISPLAY_H */
