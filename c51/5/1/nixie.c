#include <REGX52.H>

#include "delay.h"

/// 无符号整数类型的别名
#define uchar unsigned char
#define uint unsigned int
    
/// 延时参数
const uint AWAIT = 1;

/// 激活 `Y{ip}`，选中 `LED{ip + 1}`
void nixie(uchar ip) {
    P2_2 = ip & 0x01; // `ip` 的第 `0` 位
    P2_3 = ip & 0x02; // `ip` 的第 `1` 位
    P2_4 = ip & 0x04; // `ip` 的第 `2` 位
}

/// 数码管显示的每一个个位数字对应的编码
uchar nixie_nums_table[] = {
    0x3F, // 0
    0X06, // 1
    0X5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F, // 9
};

/// 在第{8-ip}个灯显示数字 `{num}`
void display_nixie(uchar ip, uchar num) {
    /// 激活 `Y{ip}`，选中 `LED{ip+1}`
    nixie(ip);
    /// 设置数码管，显示数字 `1`
    P0 = nixie_nums_table[num];
    
    delay_ms(AWAIT); // 消影
}
