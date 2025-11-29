/**
 * @file lib/display/mode_1.c
 * @author FleetingLore macro__9@outook.com
 * @brief LED 模块以两个为一组从左向右移位，按一次移两位
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/key/key.h"

/**
 * @return 按下 K4 时返回 1
 */
int mode_1_join()
{
    int ROOT = 0x03;       /* 创世灯位 */
    int ip = 0;            /* 初始偏移为 0 */
    D_OFF = ~(ROOT << ip); /* D1 和 D2 一开始就亮 */
            
    while (1)
    {
        /* 按下 K1 时移动灯位 */
        if (k1_on())
        {
            /* 饱和返回 */
            if (ip == 6)
            {
                continue;
            }
                    
            /* 点亮灯位右移 */
            ip += 2;
            D_OFF = ~(ROOT << ip);
        }

        /* 按下 K4 时返回 */
        if (k4_on())
        {
            D_OFF = 0xFF;
            return 1;
        }
    }
}
