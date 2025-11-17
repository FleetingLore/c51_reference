#define uchar unsigned char

#ifndef __lcd1602_h__
#define __lcd1602_h__

void lcd_init();
void lcd_show_char(uchar line, uchar column, char input_char);
void lcd_show_string(uchar line, uchar column, char* input_string);
#endif
