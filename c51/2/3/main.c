#include <REGX52.H>

/// 无符号整数类型的别名
#define uint unsigned int
#define uchar unsigned char

/// 延时参数
const uint AWAIT = 200;

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
    while(1) {
        /* 亮灯 D1 */ {
            // `~a` 表示对 `a` 按位取反
            P2 = ~0x01;
            delay_ms(AWAIT);
        }
        /* 亮灯 D2 */ {
            P2 = ~0x02;
            delay_ms(AWAIT);
        }
        /* 亮灯 D3 */ {
            P2 = ~0x04;
            delay_ms(AWAIT);
        }
        /* 亮灯 D4 */ {
            P2 = ~0x08;
            delay_ms(AWAIT);
        }
        /* 亮灯 D5 */ {
            P2 = ~0x10;
            delay_ms(AWAIT);
        }
        /* 亮灯 D6 */ {
            P2 = ~0x20;
            delay_ms(AWAIT);
        }
        /* 亮灯 D7 */ {
            P2 = ~0x40;
            delay_ms(AWAIT);
        }
        /* 亮灯 D8 */ {
            P2 = ~0x80;
            delay_ms(AWAIT);
        }
    }
}
