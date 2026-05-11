#ifndef _entry_h_
#define _entry_h_

// ! app ! //



// ! service ! //



// ! device ! //
#include "rgb_led/rgb_led.h"
#include "rgb_led/ws2812_rgb_led.h"

// ! domain ! //



// ! infra ! //



// ! platform ! //
#include "stm32_hal_spi.h"


// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //

static uint8_t rgb_color_buffer[8 * RGB_LED_COLOR_BYTES];
static uint8_t rgb_tx_buffer[8 * WS2812_RGB_LED_BITS_PER_PIXEL + 80];

static const RgbLedPortOps rgb_ops = {
    .write = spi_write,
};

// ! ========================= 接 口 函 数 声 明 ========================= ! //

/**
 * @brief 程序初始化入口函数
 */
static inline void entry_init(void) {
    RgbLedConfig rgb_config = {
        .ops = &rgb_ops,
        .pixel_count = 8,
        .color_buffer = rgb_color_buffer,
        .color_buffer_size = sizeof(rgb_color_buffer),
        .tx_buffer = rgb_tx_buffer,
        .tx_buffer_size = sizeof(rgb_tx_buffer),
        .reset_bytes = 80,
    };
    rgb_led_set_instance(&ws2812_rgb_led_instance);
    rgb_led.init(&rgb_config);

    rgb_led.fill(255, 255, 255);
    rgb_led.show();
}

/**
 * @brief 程序主循环入口函数
 */
static inline void entry_loop(void) {

}

#endif
