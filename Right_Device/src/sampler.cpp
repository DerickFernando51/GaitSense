#include "sampler.h"
#include "config.h"


static Mux* muxPtr = nullptr;


void sampler_init(Mux &mux)
{
    muxPtr = &mux;
}


void sample_right_frame(
    ble_frame_t* frame,
    uint32_t timestamp
)
{
    frame->side = 1;
    frame->timestamp_ms = timestamp;


    for(uint8_t i = 0; i < NUM_SAMPLES; i++)
    {
        muxPtr->setChannel(i);

        frame->samples[i] = muxPtr->read();
    }
}