#include <Arduino.h>

#include "config.h"
#include "frame.h"

#include "mux.h"
#include "sampler.h"
#include "espnow_comm.h"
#include "control.h"
#include "hw_timer.h"

frame_t leftFrame;

void setup() {

    Serial.begin(115200);

    setCpuFrequencyMhz(41);
    analogReadResolution(8);

    mux_init();

    espnow_init();
    timer_init();

    Serial.println("Left device ready");
}

void loop() {

    if (!control_is_streaming()) return;

    if (timer_flag()) {

        timer_clear();

        sample_left_frame(&leftFrame, control_get_timestamp());
        espnow_send_frame(&leftFrame);
    }
}