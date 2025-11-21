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
            /// `P2_i` 即控制 `D{i+1}` 的接口
            P2_0 = 0;
            delay_ms(AWAIT);
            
            // 亮灯后熄灭
            P2_0 = 1;
        }
        /* 亮灯 D2 */ {
            P2_1 = 0;
            delay_ms(AWAIT);
            
            P2_1 = 1;
        }
        /* 亮灯 D3 */ {
            P2_2 = 0;
            delay_ms(AWAIT);
            
            P2_2 = 1;
        }
        /* 亮灯 D4 */ {
            P2_3 = 0;
            delay_ms(AWAIT);
            
            P2_3 = 1;
        }
        /* 亮灯 D5 */ {
            P2_4 = 0;
            delay_ms(AWAIT);
            
            P2_4 = 1;
        }
        /* 亮灯 D6 */ {
            P2_5 = 0;
            delay_ms(AWAIT);
            
            P2_5 = 1;
        }
        /* 亮灯 D7 */ {
            P2_6 = 0;
            delay_ms(AWAIT);
            
            P2_6 = 1;
        }
        /* 亮灯 D8 */ {
            P2_7 = 0;
            delay_ms(AWAIT);
            
            P2_7 = 1;
        }
    }
}
