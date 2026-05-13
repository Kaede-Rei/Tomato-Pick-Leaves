#ifndef ENTRY_H
#define ENTRY_H

// ! service ! //
#include "assemble.h"

// ! infra ! //
#include "log.h"

// ! ========================= Interface Functions ========================= ! //

/**
 * @brief 程序初始化入口函数
 */
static inline void entry_init(void) {
    assemble_init();
    log_info("Welcome to Tomato Push Aside Leaves!");
}

/**
 * @brief 程序主循环入口函数
 */
static inline void entry_loop(void) {

}

#endif
