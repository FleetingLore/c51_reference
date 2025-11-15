/* 2.2 LED 闪烁 = C:\\code_fleetinglore\c51\2\2 */

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
        /* 亮一个灯 */ {
            P2 = ~0x01;
            delay_ms(AWAIT);
        }
        
        /* 灭灯 */ {
            P2 = ~0x00;
            delay_ms(AWAIT);
        }
    }
}
