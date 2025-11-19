#include <REGX52.H>

#define uchar unsigned char
#define uint  unsigned int

/// 数据总线
#define lcd_data_port P0

/// 控制信号引脚
sbit lcd_rs = P2^6;
sbit lcd_rw = P2^5;
sbit lcd_en = P2^7;

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
 * [毫秒级延时函数]
 * 
 * 静态函数
 * 
 * 只是用循环来简单模拟，缺陷是对于不同的设备表现不一致。
 */
static void lcd_delay(
    uint t /* 延时时间 */
) 
{
    uchar j;  // 在函数开头定义变量
    
    while(t--) {
        j = 85;
        while (j--);
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
 * 
 * 静态函数
 */
static void lcd_write_data(
    uchar input_data /* 要写入的数据 */
) 
{
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
    uchar lcd_char;  // 在函数开头定义变量
    
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
    uchar i;        // 在函数开头定义变量
    uchar lcd_char; // 在函数开头定义变量
    
    lcd_set_cursor(line, column);
    for(i = 0; input_string[i] != '\0'; i++) {
        lcd_char = ascii_to_lcd_char(input_string[i]);
        lcd_write_data(lcd_char);
    }
}

/**
 * [创建自定义字符]
 * 
 * [`char_code`] = 0..7 (CGRAM地址)
 * [`char_map`] = 字符点阵数据(8字节)
 */
void lcd_create_char(
    uchar char_code, /* CGRAM地址(0-7) */
    uchar char_map[] /* 字符点阵数据数组 */
) 
{
    uchar i;  // 在函数开头定义变量
    
    lcd_write_command(0x40 | (char_code << 3)); /// 设置CGRAM地址
    for(i = 0; i < 8; i++) {
        lcd_write_data(char_map[i]);
    }
    lcd_write_command(0x80); /// 返回DDRAM地址
}