/**
 * @file lib/display/mode_3.c
 * @author FleetingLore macro__9@outook.com
 * @brief 所有灯亮起，3 秒后全部熄灭
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/delay/delay.h"

/**
 * @return 正常退出时返回 3
 */
int mode_3_join() {
    /* 所有灯亮起 */
    D_OFF = 0x00;

    /* 两秒后熄灭 */
    delay_ms(2000);
    D_OFF = 0xFF;
    
    /* 正常退出 */
    return 3;
}