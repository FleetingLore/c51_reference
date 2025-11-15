/* 3.2 控制 LED 状态 = C:\\code_fleetinglore\c51\3\2 */

#include <REGX52.H>

/// 无符号整数类型的别名
#define uint unsigned int
#define uchar unsigned char

/// 延时参数
const uint AWAIT = 20;

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
    while (1) {
        /// 当按下 `K_1` 时
        if (P3_1 == 0) {
            /* 消抖 */ {
                // 抖动
                delay_ms(AWAIT);
                
                // 按住时
                while (P3_1 == 0);
                
                // 松手后
                delay_ms(AWAIT);
            }
            
            /// D_1 灯状态转换
            P2_0 = ~P2_0;
        }
    }
}
