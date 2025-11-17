#include <REGX52.H>

#define uchar unsigned char
#define uint  unsigned int

/// 引脚
sbit lcd_rs = P2^6;
sbit lcd_rw = P2^5;
sbit lcd_en = P2^7;

#define lcd_data_port P0

/// 延时参数
const uint AWAIT = 1;

/**
 * [毫秒级延时函数]
 * 
 * 只是用循环来简单模拟，缺陷是对于不同的设备表现不一致。
 */
void lcd_delay(uint t) {
    uchar j;
    while(t--) {
        j = 85;
        while (j--);
    }
}

/**
 * [LCD1602写命令]
 */
void lcd_write_command(
    uchar command /* 要写入的命令 */
) {
    lcd_rs = 0;
    lcd_rw = 0;
    lcd_data_port = command;
    lcd_en = 1;
    lcd_delay(AWAIT);
    lcd_en = 0;
    lcd_delay(AWAIT);
}

/**
 * [LCD1602写数据]
 */
void lcd_write_data(
    uchar input_data /* 要写入的数据 */
) {
    lcd_rs = 1;
    lcd_rw = 0;
    lcd_data_port = input_data;
    lcd_en = 1;
    lcd_delay(AWAIT);
    lcd_en = 0;
    lcd_delay(AWAIT);
}

/**
 * [LCD1602设置光标位置]
 * 
 * [`line`] = 1..2
 * [`column`] = 1..16
 */
void lcd_set_cursor(
    uchar line, /* 行位置 */
    uchar column /* 列位置 */
) {
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
void lcd_init() {
    lcd_write_command(0x38);
    lcd_write_command(0x0c);
    lcd_write_command(0x06);
    lcd_write_command(0x01);
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
) {
    lcd_set_cursor(line, column);
    lcd_write_data(input_char);
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
) {
    uchar i;
    lcd_set_cursor(line, column);
    for(i = 0; input_string[i] != '\0'; i++) {
        lcd_write_data(input_string[i]);
    }
}