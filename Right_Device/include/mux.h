#pragma once

#include <Arduino.h>

class Mux
{
public:

    Mux(
        uint8_t s0,
        uint8_t s1,
        uint8_t s2,
        uint8_t s3,
        uint8_t sig
    );


    void init();

    void setChannel(uint8_t channel);

    uint16_t read();


private:

    uint8_t _s0;
    uint8_t _s1;
    uint8_t _s2;
    uint8_t _s3;
    uint8_t _sig;
};