#pragma once

#include "frame.h"
#include "sensors/ISensor.h"


void sampler_init(ISensor &sensor);


void sample_left_frame(
    frame_t* frame,
    uint32_t timestamp
);