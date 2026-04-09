#include "control.h"
#include <Arduino.h>

static bool streaming = false;
static uint32_t startTime = 0;

void control_start() {

    streaming = true;
    startTime = millis();
}

void control_stop() {
    streaming = false;
}

bool control_is_streaming() {
    return streaming;
}

uint32_t control_get_timestamp() {
    return millis() - startTime;
}