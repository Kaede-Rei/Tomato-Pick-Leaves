#ifndef _entry_h_
#define _entry_h_

// ! system ! //
#include <assert.h>

// ! app ! //



// ! service ! //



// ! device ! //
#include "rgb_led/rgb_led.h"
#include "rgb_led/ws2812_rgb_led.h"

// ! domain ! //



// ! infra ! //
#include "log.h"


// ! platform ! //
#include "stm32_hal_spi.h"
#include "stm32_hal_uart.h"


// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //

static uint8_t rgb_color_buffer[WS2812_RGB_LED_DEFAULT_PIXEL_COUNT * RGB_LED_COLOR_BYTES];
static uint8_t rgb_tx_buffer[WS2812_RGB_LED_DEFAULT_PIXEL_COUNT * WS2812_RGB_LED_BITS_PER_PIXEL + WS2812_RGB_LED_DEFAULT_RESET_BYTES];

static const RgbLedPortOps rgb_ops = {
    .write = spi_write,
};

static const LogPortOps log_ops = {
    .write = uart_write,
};

// ! ========================= 接 口 函 数 声 明 ========================= ! //

/**
 * @brief 程序初始化入口函数
 */
static inline void entry_init(void) {
    RgbLedConfig rgb_config;
    rgb_led_set_instance(&ws2812_rgb_led_instance);
    assert(ws2812_rgb_led_make_config(&rgb_config, &rgb_ops, rgb_color_buffer, sizeof(rgb_color_buffer), rgb_tx_buffer, sizeof(rgb_tx_buffer)) == RGB_LED_STATUS_OK);

    LogConfig log_config = {
        .ops = &log_ops,
        .level = LOG_LEVEL_INFO,
        .enable_color = true,
        .async_write = true,
    };
    assert(log_init(&log_config) == LOG_STATUS_OK);
    uart_register_tx_complete_callback(&huart1, log_write_complete);

    rgb_led.init(&rgb_config);
    rgb_led.fill(0, 0, 0);
    rgb_led.show();

    log_info("System initialized successfully");
    log_info("Welcome to Tomato Push Aside Leaves!");
}

/**
 * @brief 程序主循环入口函数
 */
static inline void entry_loop(void) {

}

#endif
