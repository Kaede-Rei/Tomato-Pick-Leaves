#ifndef _stm32_hal_uart_h_
#define _stm32_hal_uart_h_

#include <stdint.h>
#include <stdbool.h>

// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //

#define UART_TIMEOUT 10

// ! ========================= 接 口 函 数 声 明 ========================= ! //

bool uart_write(const char* data, uint32_t len);

#endif
