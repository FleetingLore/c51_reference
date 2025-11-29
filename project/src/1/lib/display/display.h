/**
 * @file lib/key/display.h
 * @brief 目标效果
 * @date 2025-11-29
 */
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

/**
 * @brief LED 模块以两个为一组从左向右移位，按一次移两位
 */
int mode_1_join();

/**
 * @brief LED 模块从左向右亮，按照先奇后偶的顺序亮起
 *        后灯亮前灯灭，一直循环，时间间隔 0.5 秒
 *        再次按下 K2 停止，跳出循环。（1-3-5-7-2-4-6-8）
 */
int mode_2_join();

/**
 * @brief 所有灯亮起，3 秒后全部熄灭
 */
int mode_3_join();

#endif