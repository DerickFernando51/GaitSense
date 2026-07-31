#pragma once

#include "frame.h"
#include "sensors/ISensor.h"

void sampler_init(ISensor &sensor);

void sample_right_frame(
    ble_frame_t* frame,
    uint32_t timestamp
);