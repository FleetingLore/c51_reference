/**
 * @file lib/delay/delay.h
 * @brief 延时
 * @date 2025-11-29
*/
#ifndef __DELAY_H__
#define __DELAY_H__

/**
 * @brief 阻塞延时
 * @param t 延时毫秒数
*/
void delay_ms(unsigned int t);

/**
 * @brief 针对 K2 的非阻塞延时
 * 
 * @param t 延时毫秒数
 * @return 按下 K2 则返回 2，否则返回 0
*/
int async_delay_ms_for_k2(unsigned int t);

#endif