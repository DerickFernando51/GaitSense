#pragma once
#include <stdint.h>

#define DEVICE_NAME       "IPS Left"
#define SAMPLE_RATE_HZ    50
#define NUM_SAMPLES       16

#define TIMER_INTERVAL_US (1000000 / SAMPLE_RATE_HZ)

// MUX pins
#define MUX_S0 5
#define MUX_S1 4
#define MUX_S2 6
#define MUX_S3 7
#define MUX_SIG 3

// RIGHT MAC
static const uint8_t RIGHT_MAC[6] = {0xE8, 0xF6, 0x0A, 0x2E, 0xD2, 0x1C};