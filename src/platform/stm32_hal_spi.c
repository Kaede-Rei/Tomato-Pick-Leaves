#include "stm32_hal_spi.h"

#include "main.h" // IWYU pragma: keep

// ! ========================= 变 量 声 明 ========================= ! //

extern SPI_HandleTypeDef hspi6;
#define SPI_TIMEOUT 10

// ! ========================= 私 有 函 数 声 明 ========================= ! //



// ! ========================= 接 口 函 数 实 现 ========================= ! //

int spi_write(const uint8_t* data, uint32_t len) {
    HAL_SPI_Transmit(&hspi6, data, (uint16_t)len, SPI_TIMEOUT);

    return 0;
}

// ! ========================= 私 有 函 数 实 现 ========================= ! //


