/**
 * @file lib/key/key.h
 * @brief 独立按键检测
 * @date 2025-11-29
 */
#ifndef __KEY_H__
#define __KEY_H__

/**
 * @brief 针对 K1 的按键检测
 * @return 按下 K1 则返回 1，否则返回 0
 */
int k1_on();

/**
 * @brief 针对 K2 的按键检测
 * @return 按下 K2 则返回 2，否则返回 0
 */
int k2_on();

/**
 * @brief 针对 K3 的按键检测
 * @return 按下 K3 则返回 3，否则返回 0
 */
int k3_on();

/**
 * @brief 针对 K4 的按键检测
 * @return 按下 K4 则返回 4，否则返回 0
 */
int k4_on();

#endif