/// 无符号整数类型的别名
#define uchar unsigned char
#define uint unsigned int

/**
 * [毫秒级延时函数]
 * 
 * 静态函数
 * 
 * 只是用循环来简单模拟，缺陷是对于不同的设备表现不一致。
 */
void delay_ms(
    uint t /* 延时时间 */
) 
{
    uchar j;  // 在函数开头定义变量
    
    while(t--) {
        j = 85;
        while (j--);
    }
}