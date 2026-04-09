#pragma once
#include "frame.h"

void espnow_init();
void espnow_send_frame(frame_t* frame);

bool espnow_is_streaming();