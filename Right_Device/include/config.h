#pragma once
#include <stdint.h>  

#define DEVICE_NAME        "IPS Right"
#define SAMPLE_RATE_HZ     50
#define NUM_SAMPLES        16

#define TIMER_INTERVAL_US  (1000000 / SAMPLE_RATE_HZ)

// MUX pins
#define MUX_S0 5
#define MUX_S1 4
#define MUX_S2 6
#define MUX_S3 7
#define MUX_SIG 3

// Left ESP MAC
static const uint8_t LEFT_MAC[6] = {0x80, 0xB5, 0x4E, 0x1A, 0xAB, 0x7C};

// BLE UUIDs
#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890ab"
#define DATA_CHAR_UUID      "abcdefab-1234-5678-1234-abcdefabcdef"
#define CONTROL_CHAR_UUID   "fedcba98-4321-4321-4321-fedcbafedcba"