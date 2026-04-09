#include "sampler.h"
#include "mux.h"
#include "config.h"

void sample_left_frame(frame_t* frame, uint32_t timestamp) {

    frame->side = 0;
    frame->timestamp_ms = timestamp;

    for (uint8_t i = 0; i < NUM_SAMPLES; i++) {

        mux_set_channel(i);
        frame->samples[i] = mux_read();
    }
}