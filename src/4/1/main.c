#include <REGX52.H>

#define uchar unsigned char

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

void main() {
    /// 激活 `Y4`，选中 `LED5`
    nixie(4);
    
    /// 设置数码管，显示数字 `6`
    P0 = nixie_nums_table[6];
    
    while (1);
}
