/**
 * @file lib/delay/async_delay_ms_for_k2.c
 * @author FleetingLore macro__9@outook.com
 * @brief 针对 K2 的非阻塞延时
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/delay/delay.h"

/**
 * @param t 延时毫秒数
 * @return 按下 K2 则返回 2，否则返回 0
*/
int async_delay_ms_for_k2(unsigned int t)
{
    unsigned int i, j;
    
    for(i = 0; i < t; i++)
    {
        for(j = 0; j < 75; j++)
        {
            if (K2_OFF == 0)
            {
                D_OFF = 0xFF;
                delay_ms(1000); /* 防止重复识别 */
                return 2;
            }
        }
    }
    
    return 0;
}