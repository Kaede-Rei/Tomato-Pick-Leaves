#include "stm32_hal_uart.h"

#include "main.h" // IWYU pragma: keep

// ! ========================= 变 量 声 明 ========================= ! //

extern UART_HandleTypeDef huart1;

// ! ========================= 私 有 函 数 声 明 ========================= ! //



// ! ========================= 接 口 函 数 实 现 ========================= ! //

bool uart_write(const char* data, uint32_t len) {
    HAL_UART_Transmit(&huart1, (uint8_t*)data, (uint16_t)len, UART_TIMEOUT);

    return true;
}

// ! ========================= 私 有 函 数 实 现 ========================= ! //


