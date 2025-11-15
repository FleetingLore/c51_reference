/* 3.3 控制 LED 显示二进制 = C:\\code_fleetinglore\c51\3\3 */

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
    /// 按键次数统计
    uchar count = 0;
    
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
            
            /// 计数自增
            count++;
            
            /// 点灯
            P2 = ~count;
            
            /**
             * 当然，这里可以用
             *
             * ```c
             * P2--;
             * ```
             * 
             * 代替
             * 
             * ```c
             * count++;
             * P2 = ~count;
             * ```
             * 
             * 这两行，但这样写的话可读性很不好。
             * 
             * 毕竟不是搞开发，写的代码应当含义直观一些。
            */
        }
    }
}
