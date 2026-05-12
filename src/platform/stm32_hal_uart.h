#ifndef _stm32_hal_uart_h_
#define _stm32_hal_uart_h_

#include <stdint.h>
#include <stdbool.h>

#include "main.h" // IWYU pragma: keep

// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //

#define UART_TIMEOUT 10

extern UART_HandleTypeDef huart1;

// ! ========================= 接 口 函 数 声 明 ========================= ! //

bool uart_write(const char* data, uint32_t len);
void uart_register_tx_complete_callback(UART_HandleTypeDef* huart, void (*callback)(void));
void uart_register_rx_complete_callback(UART_HandleTypeDef* huart, void (*callback)(void));

#endif
