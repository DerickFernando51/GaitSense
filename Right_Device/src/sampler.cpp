#include "sampler.h"
#include "config.h"


static ISensor* sensorPtr = nullptr;


void sampler_init(ISensor &sensor)
{
    sensorPtr = &sensor;
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
        frame->samples[i] = sensorPtr->read(i);
    }
}