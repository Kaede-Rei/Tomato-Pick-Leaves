#ifndef _entry_h_
#define _entry_h_

// ! system ! //



// ! app ! //



// ! service ! //
#include "assemble.h"


// ! device ! //
#include "servo/servo.h"


// ! domain ! //



// ! infra ! //
#include "log.h"
#include "delay.h"

// ! platform ! //



// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //



// ! ========================= 接 口 函 数 声 明 ========================= ! //

/**
 * @brief 程序初始化入口函数
 */
static inline void entry_init(void) {
    assemble_init();
    log_info("Welcome to Tomato Push Aside Leaves!");

    // servo.set_speed(1, 3.14f);
    // servo.set_pos_spd(1, 3.14f, 3.14f);
    servo.set_pos_spd_tor(1, 3.14f, 1.57f, 1.0f);
}

/**
 * @brief 程序主循环入口函数
 */
static inline void entry_loop(void) {
    static ms_t servo_task = 0;
    static ServoFeedback feedback = { 0 };
    if(s_nb_delay_ms(&servo_task, 1000)) {
        ServoStatus status = servo.update_feedback(1, &feedback);
        if(status == SERVO_STATUS_OK) {
            log_info("Servo feedback - position: %.2f rad, speed: %.2f rad/s, torque: %.2f", feedback.position, feedback.speed, feedback.torque);
        } else {
            log_error("Failed to update servo feedback: %s", servo.status_str(status));
        }
    }
}

#endif
