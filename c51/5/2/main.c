#include <REGX52.H>
#include "lcd1602.h"

void main() {
    lcd_init();
    
    /// LCD 展示字面量
    lcd_show_string(1, 1, "Hello, world!");
    
    /// LCD 展示数字
    lcd_show_num(2, 1, 12345, 5);
    
    while (1) {
        ;
    }
}
