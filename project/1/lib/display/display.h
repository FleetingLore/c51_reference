/**
 * @file lib/key/display.h
 * @brief 目标效果
 * @date 2025-11-29
 */
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

/**
 * @brief 针对 K1 的按键检测
 * @return 按下 K1 则返回 1，否则返回 0
 */
int mode_1_join();

/**
 * @brief 针对 K2 的按键检测
 * @return 按下 K2 则返回 2，否则返回 0
 */
int mode_2_join();

/**
 * @brief 针对 K3 的按键检测
 * @return 按下 K3 则返回 3，否则返回 0
 */
int mode_3_join();

/**
 * @brief 针对 K4 的按键检测
 * @return 按下 K4 则返回 4，否则返回 0
 */
int k4_on();

#endif