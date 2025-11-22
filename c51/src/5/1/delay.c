/// 无符号整数类型的别名
#define uint unsigned int
#define uchar unsigned char

/**
 * [毫秒级延时函数]
 * 
 * 只是用循环来简单模拟，缺陷是对于不同的设备表现不一致。
*/
void delay_ms(uint t) {
    uchar j;
    while(t--) {
        j = 85;
        while (j--);
    }
}

