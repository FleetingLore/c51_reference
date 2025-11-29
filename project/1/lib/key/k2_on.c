/**
 * @file lib/key/k2_on.c
 * @author FleetingLore macro__9@outook.com
 * @brief 针对 K2 的独立按键检测
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/delay/delay.h"

/**
 * @return 按下 K2 则返回 2，否则返回 0
*/
int k2_on()
{
    if (K2_OFF == 0)
    {
        /* 消抖 */
        delay_ms(AWAIT); /* 按下后抖动 */
        while (K2_OFF == 0); /* 按住时 */
        delay_ms(AWAIT); /* 松手后抖动 */

        /* 按下时返回 2 */
        return 2;
    }
    else
    {
        /* 否则返回 0 */
        return 0;
    }
}