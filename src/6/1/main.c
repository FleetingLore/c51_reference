#include <REGX52.H>

#include "delay.h"
#include "lcd1602.h"
#include "matrix_key.h"

/// 无符号整数类型的别名
#define uchar unsigned char

uchar key_num;

void main() {
    lcd_init();
    lcd_show_string(1, 1, "Matrix Key");
    
    while (1) {
        key_num = matrix_key();
        
        if (key_num) {
            lcd_show_num(2, 1, key_num, 2);
        }
    }
}