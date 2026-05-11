#ifndef _stm32_hal_spi_h_
#define _stm32_hal_spi_h_

#include <stdint.h>

// ! ========================= 接 口 变 量 / Typedef 声 明 ========================= ! //



// ! ========================= 接 口 函 数 声 明 ========================= ! //

int spi_write(const uint8_t* data, uint32_t len);

#endif
