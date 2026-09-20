#pragma once
#include <stdint.h>
void mcp3208_init(void);
uint16_t mcp3208_read(uint8_t channel);
uint16_t mcp3208_read_oversampled(uint8_t channel);
