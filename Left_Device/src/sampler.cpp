#include "sampler.h"
#include "config.h"

static ISensor* sensorPtr = nullptr;


void sampler_init(ISensor &sensor)
{
    sensorPtr = &sensor;
}


void sample_left_frame(
    frame_t* frame,
    uint32_t timestamp
)
{
    frame->timestamp_ms = timestamp;
    frame->side = 0;


    for(uint8_t i = 0; i < NUM_SAMPLES; i++)
    {
        frame->samples[i] = sensorPtr->read(i);
    }
}