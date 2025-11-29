/**
 * @file main.c
 * @author FleetingLore macro__9@outook.com
 * @date 2025-11-29
*/
#include "prelude.h"
#include "lib/lib.h"

/**
 * @brief 无初始化事项
 */
void init()
{
    ;
}

/**
 * @brief 注册表
*/
void registry_joined()
{
    /* 当按下 K1 时 */
    if (k1_on()) mode_1_join();
    
    /* 当按下 K2 时 */
    if (k2_on()) mode_2_join();
    
    /* 当按下 K3 时 */
    if (k3_on()) mode_3_join();
}

/**
 * @brief 入口
*/
void main()
{
    init();

    while (1)
    {
        /* 原 神 启 动 */
        registry_joined();
    }
}
