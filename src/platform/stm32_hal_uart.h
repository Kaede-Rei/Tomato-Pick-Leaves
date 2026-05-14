#ifndef _stm32_hal_uart_h_
#define _stm32_hal_uart_h_

#include <stdint.h>
#include <stdbool.h>

#include "main.h" // IWYU pragma: keep

// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //

#define UART_TIMEOUT 10

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart10;

// ! ========================= 接 口 函 数 声 明 ========================= ! //

bool uart1_write(const char* data, uint32_t len);
bool uart10_write(const uint8_t* data, uint16_t len);
int uart10_read(uint8_t* data, uint16_t len);
bool uart10_enable_half_duplex(void);

void uart_register_tx_complete_callback(UART_HandleTypeDef* huart, void (*callback)(void));
void uart_register_rx_complete_callback(UART_HandleTypeDef* huart, void (*callback)(void));

#endif
