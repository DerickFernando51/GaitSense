#pragma once
#include <stdint.h>

void mux_init();
void mux_setChannel(uint8_t ch);
uint8_t mux_read();