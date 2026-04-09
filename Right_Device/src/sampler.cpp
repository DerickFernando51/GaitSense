#include "sampler.h"
#include "mux.h"
#include "config.h"

void sampler_init() {}

void sample_right_frame(ble_frame_t* frame, uint32_t timestamp) {

    frame->side = 1;
    frame->timestamp_ms = timestamp;

    for (uint8_t i = 0; i < NUM_SAMPLES; i++) {

        mux_setChannel(i);
        frame->samples[i] = mux_read();
    }
}