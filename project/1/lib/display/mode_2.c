/**
 * @file lib/display/mode_2.c
 * @author FleetingLore macro__9@outook.com
 * @brief LED 模块从左向右亮，按照先奇后偶的顺序亮起
 *        后灯亮前灯灭，一直循环，时间间隔 0.5 秒
 *        再次按下 K2 停止，跳出循环。（1-3-5-7-2-4-6-8）
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/delay/delay.h"

/**
 * @return 按下 K2 时返回 2
 */
int mode_2_join() {
    while (1)
    {
        /* `D1` 亮 */
        D1_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D1_OFF = 1;
        
        /* `D3` 亮 */
        D3_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D3_OFF = 1;
        
        /* `D5` 亮 */
        D5_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D5_OFF = 1;
        
        /* `D7` 亮 */
        D7_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D7_OFF = 1;
        
        /* `D2` 亮 */
        D2_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D2_OFF = 1;
        
        /* `D4` 亮 */
        D4_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D4_OFF = 1;

        /* `D6` 亮 */
        D6_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D6_OFF = 1;

        /* `D8` 亮 */
        D8_OFF = 0;
        if (async_delay_ms_for_k2(500)) return 2;
        D8_OFF = 1;
    }
}