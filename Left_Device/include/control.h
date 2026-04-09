#pragma once
#include <stdint.h>

void control_start();
void control_stop();

bool control_is_streaming();
uint32_t control_get_timestamp();