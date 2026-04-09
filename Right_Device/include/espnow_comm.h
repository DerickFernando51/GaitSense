#pragma once
#include "frame.h"

void espnow_init();
void espnow_send_command(const char* cmd);

bool espnow_has_left();
void espnow_get_left(ble_frame_t* frame);