#include <REGX52.H>
#include "lcd1602.h"

void main() {
    // lcd 初始化
    lcd_init();
    
    /// 从第一行的第一个位置开始显示字符串 `"hello"`
    lcd_show_string(1, 1, "hello");
    
    while  (1);
}