#pragma once

#include "board_common.h"
#include "sdkconfig.h"

#define BOARD_NAME "Apollo CAST-1"
#define BOARD_DESCRIPTION \
  "ESP32-S3 with PCM5122 I2C DAC (3-wire I2S), 3.5mm line out"

// I2C configuration (PCM5122 DAC control)
#define BOARD_I2C_PORT     0
#define BOARD_I2C_SDA_GPIO CONFIG_DAC_I2C_SDA
#define BOARD_I2C_SCL_GPIO CONFIG_DAC_I2C_SCL

// I2S configuration (no MCLK: the PCM5122 PLL runs from BCK)
#define BOARD_I2S_BCK_GPIO CONFIG_I2S_BCK_IO
#define BOARD_I2S_WS_GPIO  CONFIG_I2S_WS_IO
#define BOARD_I2S_DO_GPIO  CONFIG_I2S_DO_IO
#define BOARD_I2S_GND_GPIO CONFIG_I2S_GND_IO
#define BOARD_I2S_VCC_GPIO CONFIG_I2S_VCC_IO

// LED configuration (the CAST-1 has WS2812 LEDs on GPIO4; disabled by
// default in this build)
#define BOARD_LED_STATUS_GPIO CONFIG_LED_STATUS_GPIO
#define BOARD_LED_ERROR_GPIO  CONFIG_LED_ERROR_GPIO
#define BOARD_LED_RGB_GPIO    CONFIG_LED_RGB_GPIO

// No XSMT/mute pin is driven in Apollo's firmware; leave at -1.
#define BOARD_DAC_ENABLE_GPIO CONFIG_DAC_ENABLE_GPIO

// Battery monitoring (not present)
#define BOARD_BAT_CHANNEL CONFIG_BAT_CHANNEL

#ifdef CONFIG_ETH_W5500_ENABLED
// Optional W5500 Ethernet header on SPI
#define BOARD_SPI_HOST      SPI2_HOST
#define BOARD_SPI_CLK_GPIO  CONFIG_SPI_CLK_GPIO
#define BOARD_SPI_MOSI_GPIO CONFIG_SPI_MOSI_GPIO
#define BOARD_SPI_MISO_GPIO CONFIG_SPI_MISO_GPIO

#define BOARD_ETH_CS_GPIO  CONFIG_ETH_W5500_CS_GPIO
#define BOARD_ETH_INT_GPIO CONFIG_ETH_W5500_INT_GPIO
#define BOARD_ETH_RST_GPIO CONFIG_ETH_W5500_RST_GPIO
#endif
