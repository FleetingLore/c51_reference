#include "regx52.h"
#include "delay.h"

/// 无符号整数类型的别名
#define uchar unsigned char
#define uint unsigned int

/// 数据总线
#define LCD_DAAT_PORT P0

/// 控制信号引脚
sbit LCD_RS = 0xA6;
sbit LCD_RW = 0xA5;
sbit LCD_EN = 0xA7;

/// 延时参数
static const uint AWAIT = 1;

/**
 * [ASCII到LCD1602字符集映射]
 * 
 * 静态函数
 * 
 * 将ASCII字符映射到LCD1602字符集的对应编码
 * 对于LCD1602不支持的字符，返回空格(0x20)
 */
static uchar ascii_to_lcd_char(
    char ascii_char /* 要映射的ASCII字符 */
) 
{
    // 确保字符在LCD1602支持的范围内
    if(ascii_char < 0x20) {
        return 0x20; /// 映射到空格
    }
    
    if(ascii_char > 0x7F) {
        return 0x20; /// 映射到空格
    }
    
    /// 特殊字符映射处理
    switch(ascii_char) {
        case '\0': /// 字符串结束符
        case '\n': /// 换行符
        case '\r': /// 回车符
        case '\t': /// 制表符
            return 0x20; /// 映射到空格
        
        default: 
            return ascii_char; /// 大多数ASCII字符在LCD1602中直接支持
    }
}

/**
 * [LCD1602写命令]
 * 
 * 静态函数
 */
static void lcd_write_command(
    uchar command /* 要写入的命令 */
) 
{
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_DAAT_PORT = command;
    LCD_EN = 1;
    delay_ms(AWAIT);
    LCD_EN = 0;
    delay_ms(AWAIT);
}

/**
 * [LCD1602写数据]
 * 
 * 静态函数
 */
static void lcd_write_data(
    uchar input_data /* 要写入的数据 */
) 
{
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_DAAT_PORT = input_data;
    LCD_EN = 1;
    delay_ms(AWAIT);
    LCD_EN = 0;
    delay_ms(AWAIT);
}

/**
 * [LCD1602设置光标位置]
 * 
 * 静态函数
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 */
static void lcd_set_cursor(
    uchar line, /* 行位置 */
    uchar column /* 列位置 */
) 
{
    if(line == 1) {
        lcd_write_command(0x80 | (column - 1));
    }
    else if(line == 2) {
        lcd_write_command(0x80 | (column - 1 + 0x40));
    }
}

/**
 * [LCD1602初始化函数]
 */
void lcd_init() 
{
    lcd_write_command(0x38); /* 8位数据接口，2行显示，5×8点阵 */
    lcd_write_command(0x0C); /* 显示开，光标关，闪烁关 */
    lcd_write_command(0x06); /* 读写后光标右移，显示不移动 */
    lcd_write_command(0x01); /* 清屏 */
}

/**
 * [在LCD1602指定位置上显示一个字符]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 */
void lcd_show_char(
    uchar line, /* 行位置 */
    uchar column, /* 列位置 */
    char input_char /* 要显示的字符 */
) 
{
    uchar lcd_char;
    
    lcd_set_cursor(line, column);
    lcd_char = ascii_to_lcd_char(input_char);
    lcd_write_data(lcd_char);
}

/**
 * [在LCD1602指定位置开始显示所给字符串]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 */
void lcd_show_string(
    uchar line, /* 起始行位置 */
    uchar column, /* 起始列位置 */
    char *input_string /* 要显示的字符串 */
) 
{
    uchar i;
    uchar lcd_char;
    
    lcd_set_cursor(line, column);
    for(i = 0; input_string[i] != '\0'; i++) {
        lcd_char = ascii_to_lcd_char(input_string[i]);
        lcd_write_data(lcd_char);
    }
}

/**
 * [在LCD1602指定位置显示无符号数字]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 * [`number`] = 0..65535
 * [`length`] = 1..5
 */
void lcd_show_num(
    uchar line,     /* 行位置 */
    uchar column,   /* 列位置 */
    uint number,    /* 要显示的数字 */
    uchar length    /* 数字长度 */
) 
{
    uchar i;
    uint divisor = 1;
    uchar digit;
    
    // 计算除数
    for(i = 1; i < length; i++) {
        divisor *= 10;
    }
    
    lcd_set_cursor(line, column);
    for(i = 0; i < length; i++) {
        digit = (number / divisor) % 10;
        lcd_write_data(digit + '0');
        divisor /= 10;
    }
}

/**
 * [在LCD1602指定位置显示有符号数字]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 * [`number`] = -32768..32767
 * [`length`] = 1..5
 */
void lcd_show_signed_num(
    uchar line,     /* 行位置 */
    uchar column,   /* 列位置 */
    int number,     /* 要显示的数字 */
    uchar length    /* 数字长度 */
) 
{
    uchar i;
    uint divisor = 1;
    uchar digit;
    uint number_abs;
    
    lcd_set_cursor(line, column);
    
    // 显示符号
    if(number >= 0) {
        lcd_write_data('+');
        number_abs = number;
    }
    else {
        lcd_write_data('-');
        number_abs = -number;
    }
    
    // 计算除数
    for(i = 1; i < length; i++) {
        divisor *= 10;
    }
    
    // 显示数字
    for(i = 0; i < length; i++) {
        digit = (number_abs / divisor) % 10;
        lcd_write_data(digit + '0');
        divisor /= 10;
    }
}

/**
 * [在LCD1602指定位置显示十六进制数字]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 * [`number`] = 0..65535
 * [`length`] = 1..4
 */
void lcd_show_hex_num(
    uchar line,     /* 行位置 */
    uchar column,   /* 列位置 */
    uint number,    /* 要显示的数字 */
    uchar length    /* 数字长度 */
) 
{
    uchar i;
    uchar digit;
    
    lcd_set_cursor(line, column);
    for(i = 0; i < length; i++) {
        digit = (number >> (4 * (length - 1 - i))) & 0x0F;
        if(digit < 10) {
            lcd_write_data(digit + '0');
        }
        else {
            lcd_write_data(digit - 10 + 'A');
        }
    }
}

/**
 * [在LCD1602指定位置显示二进制数字]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 * [`number`] = 0..65535
 * [`length`] = 1..16
 */
void lcd_show_bin_num(
    uchar line,     /* 行位置 */
    uchar column,   /* 列位置 */
    uint number,    /* 要显示的数字 */
    uchar length    /* 数字长度 */
) 
{
    uchar i;
    
    lcd_set_cursor(line, column);
    for(i = 0; i < length; i++) {
        lcd_write_data(((number >> (length - 1 - i)) & 0x01) + '0');
    }
}