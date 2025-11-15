/* 3.4 控制 LED 移位 = C:\\code_fleetinglore\c51\3\4 */

#include <REGX52.H>

/// 无符号整数类型的别名
#define uint unsigned int
#define uchar unsigned char

/// 延时参数
const uint AWAIT = 20;

/// 创世灯位
const uchar ROOT = 0x01;

/**
 * [毫秒级延时函数]
 * 
 * 只是用循环来简单模拟，缺陷是对于不同的设备表现不一致。
*/
void delay_ms(uint t) {
    uchar j;
    while(t--) {
        j = 85;
        while (j--);
    }
}

void main() {
    /// 初始化，偏移为 `0`
    uchar ip = 0; // index position
    
    /// 初始化，让 `D1` 一开始就亮
    P2 = ~(ROOT << ip);
        
    while (1) {   
        /* 按 `K_1` 左移 */ {
            if (P3_1 == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                    
                    // 按住时
                    while (P3_1 == 0);
                    
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                /* 饱和返回 */
                if (ip == 0) {
                    continue;
                }
                
                /* 点亮灯位左移 */ {
                    ip--;
                    P2 = ~(ROOT << ip);
                }
            }
        }
        
        /* 按 `K_2` 右移 */ {
            if (P3_0 == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                    
                    // 按住时
                    while (P3_0 == 0);
                    
                    // 松手后
                    delay_ms(AWAIT);
                }

            
                /* 饱和返回 */
                if (ip == 7) {
                    continue;
                }
                /**
                * 若操作直接面向 `P2`，此处可能会有问题，我也不知道是什么情况。
                */
            
                /* 点亮灯位右移 */ {
                    ip++;
                    P2 = ~(ROOT << ip);
                }
            }
        }
    }
}
