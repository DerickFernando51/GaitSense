#include <Arduino.h>

#include "control.h"
#include "system_state.h"

static uint32_t startTime = 0;

void control_start()
{
    startTime = millis();
    state_set(SystemState::STREAMING);
}

void control_stop()
{
    state_set(SystemState::IDLE);
}

bool control_is_streaming()
{
    return state_get() == SystemState::STREAMING;
}

uint32_t control_get_timestamp()
{
    return millis() - startTime;
}