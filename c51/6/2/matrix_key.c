#include <REGX52.H>

#include "delay.h"

/// 无符号整数类型的别名
#define uchar unsigned char
#define uint  unsigned int

/// 延时参数
const uint AWAIT = 20;

/**
 * [矩阵键盘读取按键键码]
 * 
 * 逐列扫描以确定按键
 * 
 * 若无按键被按下，返回 `0`
 * 
 * 否则返回键码
 */
uchar matrix_key() {
    uchar key_number = 0;
    
    P1 = 0xFF;
    P1_3 = 0;
    
    if (P1_7 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 1;
    }
    
    if (P1_6 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 5;
    }
    
    if (P1_5 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 9;
    }
    
    if (P1_4 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 13;
    }
    
    P1 = 0xFF;
    P1_2 = 0;
    
    if (P1_7 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 2;
    }
    
    if (P1_6 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 6;
    }
    
    if (P1_5 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 10;
    }
    
    if (P1_4 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 14;
    }
    
    P1 = 0xFF;
    P1_1 = 0;
    
    if (P1_7 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 3;
    }
    
    if (P1_6 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 7;
    }
    
    if (P1_5 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 11;
    }
    
    if (P1_4 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 15;
    }
    
    P1 = 0xFF;
    P1_0 = 0;
    
    if (P1_7 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 4;
    }
    
    if (P1_6 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 8;
    }
    
    if (P1_5 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 12;
    }
    
    if (P1_4 == 0) {
        delay_ms(AWAIT);
        while (P1_7 == 0);
        delay_ms(AWAIT);
        
        key_number = 16;
    }
    
    return key_number;
}