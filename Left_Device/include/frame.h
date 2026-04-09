#pragma once
#include <stdint.h>

typedef struct __attribute__((packed)) {
    uint8_t side;
    uint32_t timestamp_ms;
    uint8_t samples[16];
} frame_t;