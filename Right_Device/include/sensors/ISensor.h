#pragma once

#include <Arduino.h>

class ISensor
{
public:

    virtual void init() = 0;

    virtual uint16_t read(uint8_t channel) = 0;

    virtual ~ISensor() {}
};