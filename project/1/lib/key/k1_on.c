/**
 * @file lib/key/k1_on.c
 * @author FleetingLore macro__9@outook.com
 * @brief 针对 K1 的独立按键检测
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/delay/delay.h"

/**
 * @return 按下 K1 则返回 1，否则返回 0
*/
int k1_on()
{
    if (K1_OFF == 0)
    {
        /* 消抖 */
        delay_ms(AWAIT); /* 按下后抖动 */
        while (K1_OFF == 0); /* 按住时 */
        delay_ms(AWAIT); /* 松手后抖动 */

        /* 按下时返回 1 */
        return 1;
    }
    else
    {
        /* 否则返回 0 */
        return 0;
    }
}