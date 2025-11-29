/**
 * @file lib/delay/delay_ms.c
 * @author FleetingLore macro__9@outook.com
 * @brief 阻塞延时
 */
#include "prelude.h"

/**
 * @param t 延时毫秒数
*/
void delay_ms(unsigned int t)
{
    unsigned int i, j;
    
    for(i = 0; i < t; i++) for(j = 0; j < 120; j++); /* 根据实际情况调整 */
}
