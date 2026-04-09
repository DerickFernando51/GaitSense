#include <Arduino.h>
#include "mux.h"
#include "config.h"

void mux_init() {

    pinMode(MUX_S0, OUTPUT);
    pinMode(MUX_S1, OUTPUT);
    pinMode(MUX_S2, OUTPUT);
    pinMode(MUX_S3, OUTPUT);

    pinMode(MUX_SIG, INPUT);
}

void mux_set_channel(uint8_t ch) {

    digitalWrite(MUX_S0, ch & 1);
    digitalWrite(MUX_S1, (ch >> 1) & 1);
    digitalWrite(MUX_S2, (ch >> 2) & 1);
    digitalWrite(MUX_S3, (ch >> 3) & 1);
}

uint8_t mux_read() {

    delayMicroseconds(10);
    return analogRead(MUX_SIG);
}