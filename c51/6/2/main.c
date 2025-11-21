#include <REGX52.H>

#include "delay.h"
#include "lcd1602.h"
#include "matrix_key.h"

/// 无符号整数类型的别名
#define uchar unsigned char
#define uint  unsigned int

uchar key_num;
uint password;
uint count;

void main() {
    lcd_init();
    lcd_show_string(1, 1, "Password");
    
    count = 0;
    
    lcd_show_num(2, 1, password, 4);
    
    while (1) {
        key_num = matrix_key();
        
        if (key_num) {
            /// key_num = 0..9
            if (key_num <= 10) {
                /// count = 0..3
                if (count < 4) {
                    password *= 10;
                    password += key_num % 10;
                    count++;
                }

                lcd_show_num(2, 1, password, 4);
            } else if (key_num == 11) {
                /// 密码为 `2345`
                if (password == 2345) {
                    lcd_show_string(1, 14, "Ok");

                    password = 0;
                    count = 0;
                    lcd_show_num(2, 1, password, 4);
                } else {
                    lcd_show_string(1, 14, "Err");
                    
                    password = 0;
                    count = 0;
                    lcd_show_num(2, 1, password, 4);
                }
            } else if (key_num == 12) {
                password = 0;
                count = 0;
                lcd_show_num(2, 1, password, 4);
            }
        }
    }
}