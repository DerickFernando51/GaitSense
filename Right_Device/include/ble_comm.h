#pragma once
#include "frame.h"

void ble_init();
void ble_send_frame(ble_frame_t* frame);

bool ble_is_streaming();