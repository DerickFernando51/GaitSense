#pragma once

#include "frame.h"
#include "mux.h"


void sampler_init(Mux &mux);

void sample_left_frame(
    frame_t* frame,
    uint32_t timestamp
);