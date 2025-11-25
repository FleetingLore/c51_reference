#include <REGX52.H>

#include "delay.h"

const int AWAIT = 20;

// 独立按键
#define K1_off P3_1
#define K2_off P3_0
#define K3_off P3_2
#define K4_off P3_3

// LED 灯
#define D_off P2

#define D1_off P2_0
#define D2_off P2_1
#define D3_off P2_2
#define D4_off P2_3
#define D5_off P2_4
#define D6_off P2_5
#define D7_off P2_6
#define D8_off P2_7

/**
 * [按下 `K1`]
 * 
 * LED 模块以两个为一组从左向右移位，按一次移两位
 */
static int on_k1() {
    
    int ROOT = 0x03;

    /// 初始化，偏移为 `0`
    int ip = 0; // index position
        
    /// 初始化，让 `D1` 一开始就亮
    D_off = ~(ROOT << ip);
            
    while (1) {   
        /// 按 `K_1` 右移
        if (K1_off == 0) {
            /* 消抖 */ {
                // 抖动
                delay_ms(AWAIT);
                        
                // 按住时
                while (K1_off == 0);
                        
                // 松手后
                delay_ms(AWAIT);
            }
                    
            /* 饱和返回 */
            if (ip == 6) {
                continue;
            }
                    
            /* 点亮灯位右移 */ {
                ip += 2;
                D_off = ~(ROOT << ip);
            }
        }
           
        /// 按 `K_4` 返回
        if (K4_off == 0) {
            /* 消抖 */ {
                // 抖动
                delay_ms(AWAIT);
                     
                // 按住时
                while (K4_off == 0);
                        
                // 松手后
                delay_ms(AWAIT);
            }

            D_off = 0xff;
            return 1;
        }
    }
}

/**
 * [按下 `K2`]
 * 
 * LED 模块从左向右亮，按照先奇后偶的顺序亮起
 * 后灯亮前灯灭，一直循环，时间间隔 0.5 秒
 * 再次按下 K2 停止，跳出循环。（1-3-5-7-2-4-6-8）
 */
static int on_k2() {
    while (1) {
        /* `D1` 亮 */ {
            D1_off = 0;
            delay_ms(500);
            D1_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
        
        /* `D3` 亮 */ {
            D3_off = 0;
            delay_ms(500);
            D3_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
            
        /* `D5` 亮 */ {
            D5_off = 0;
            delay_ms(500);
            D5_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
            
        /* `D7` 亮 */ {
            D7_off = 0;
            delay_ms(500);
            D7_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
            
        /* `D2` 亮 */ {
            D2_off = 0;
            delay_ms(500);
            D2_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
            
        /* `D4` 亮 */ {
            D4_off = 0;
            delay_ms(500);
            D4_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
            
        /* `D6` 亮 */ {
            D6_off = 0;
            delay_ms(500);
            D6_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
            
        /* `D8` 亮 */ {
            D8_off = 0;
            delay_ms(500);
            D8_off = 1;
            
            // 按下 `K2` 时返回
            if (K2_off == 0) {
                /* 消抖 */ {
                    // 抖动
                    delay_ms(AWAIT);
                
                    // 按住时
                    while (K2_off == 0);
                
                    // 松手后
                    delay_ms(AWAIT);
                }
                
                return 2;
            }
        }
    }
}

/**
 * [按下 `K3`]
 * 
 * 所有灯亮起，3 秒后全部熄灭
 */
static int on_k3() {
    /// 所有灯亮起
    D_off = 0x00; 
    
    /// 两秒后熄灭
    delay_ms(2000);
    D_off = 0xFF;
    
    return 3;
}

static void never() {
    /// 当按下 `K_1` 时
    if (K1_off == 0) {
        /* 消抖 */ {
            // 抖动
            delay_ms(AWAIT);
                
            // 按住时
            while (K1_off == 0);
                
            // 松手后
            delay_ms(AWAIT);
        }
            
        /// 按下 `K1`
        on_k1();
    }
    
    /// 当按下 `K_2` 时
    if (K2_off == 0) {
        /* 消抖 */ {
            // 抖动
            delay_ms(AWAIT);
                
            // 按住时
            while (K2_off == 0);
                
            // 松手后
            delay_ms(AWAIT);
        }
            
        /// 按下 `K2`
        on_k2();
    }
    
    /// 当按下 `K_3` 时
    if (K3_off == 0) {
        /* 消抖 */ {
            // 抖动
            delay_ms(AWAIT);
                
            // 按住时
            while (K3_off == 0);
                
            // 松手后
            delay_ms(AWAIT);
        }
            
        /// 按下 `K3`
        on_k3();
    }
}

void main() {
    while (1) {
        never();
    }
}
