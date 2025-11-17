#include "nixie.h"

#define uchar unsigned char
#define uint unsigned int

void main() {
    
    while (1) {
        /// 在第一个灯显示数字 `1`
        display_nixie(7, 1);
        
        /// 在第二个灯显示数字 `2`
        display_nixie(6, 2);
        
        /// 在第三个灯显示数字 `3`
        display_nixie(5, 3);
    }
}
