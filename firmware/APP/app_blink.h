/*
 * app_blink.h - 闪灯应用
 */

#ifndef APP_BLINK_H
#define APP_BLINK_H

#define APP_BLINK_REFRESH_MS      (10u)     /* LED 状态刷新周期 */
#define APP_BLINK_HALF_PERIOD_MS  (500u)    /* 亮、灭各持续 500ms */

/* 启动时把 LED 置为当前相位对应的状态 */
void app_blink_init(void);

/* 周期任务：按系统时间计算 LED 应处的相位并刷新输出 */
void app_blink_task(void);

#endif /* APP_BLINK_H */
