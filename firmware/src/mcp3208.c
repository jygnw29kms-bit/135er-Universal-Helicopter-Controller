#include "mcp3208.h"
#include "hardware/spi.h"
#include "pico/stdlib.h"
#ifndef HELI_SPI
#define HELI_SPI spi0
#endif
#define PIN_SCK 18
#define PIN_MOSI 19
#define PIN_MISO 16
#define PIN_CS 17
void mcp3208_init(void){spi_init(HELI_SPI,2000*1000);gpio_set_function(PIN_SCK,GPIO_FUNC_SPI);gpio_set_function(PIN_MOSI,GPIO_FUNC_SPI);gpio_set_function(PIN_MISO,GPIO_FUNC_SPI);gpio_init(PIN_CS);gpio_set_dir(PIN_CS,GPIO_OUT);gpio_put(PIN_CS,1);}
uint16_t mcp3208_read(uint8_t ch){ch&=7;uint8_t tx[3]={0x06|(uint8_t)(ch>>2),(uint8_t)(ch<<6),0},rx[3]={0};gpio_put(PIN_CS,0);spi_write_read_blocking(HELI_SPI,tx,rx,3);gpio_put(PIN_CS,1);return (uint16_t)(((rx[1]&0x0F)<<8)|rx[2]);}
uint16_t mcp3208_read_oversampled(uint8_t ch){uint32_t sum=0;for(int i=0;i<16;i++)sum+=mcp3208_read(ch);return (uint16_t)(sum>>2);}
