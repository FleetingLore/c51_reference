#ifndef __LCD1602_H__
#define __LCD1602_H__

#define uchar unsigned char
#define uint  unsigned int

/// LCD 初始化
void lcd_init();

/// LCD 展示字面量
void lcd_show_char(uchar line, uchar column, char input_char);
void lcd_show_string(uchar line, uchar column, char* input_string);

/// LCD 展示数字
void lcd_show_num(uchar line, uchar column, uint number, uchar length);
void lcd_show_signed_num(uchar line, uchar column, int number, uchar length);
void lcd_show_hex_num(uchar line, uchar column, uint number, uchar length);
void lcd_show_bin_num(uchar line, uchar column, uint number, uchar length);

#endif