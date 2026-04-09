#include <Arduino.h>

#include "config.h"
#include "frame.h"

#include "mux.h"
#include "sampler.h"

#include "espnow_comm.h"
#include "ble_comm.h"

#include "hw_timer.h"
#include "control.h"

ble_frame_t rightFrame;
ble_frame_t leftFrame;

void setup() {

    Serial.begin(115200);

    setCpuFrequencyMhz(41);
    analogReadResolution(8);

    mux_init();
    sampler_init();

    espnow_init();
    ble_init();

    timer_init();

    Serial.println("System ready");
}

void loop() {

    if (!ble_is_streaming()) return;

    if (timer_flag()) {

        timer_clear();

        sample_right_frame(&rightFrame, control_get_timestamp());
        ble_send_frame(&rightFrame);

        if (espnow_has_left()) {

            espnow_get_left(&leftFrame);
            ble_send_frame(&leftFrame);
        }
    }
}