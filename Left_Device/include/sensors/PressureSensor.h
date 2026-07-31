#pragma once

#include "sensors/ISensor.h"
#include "mux.h"


class PressureSensor : public ISensor
{
public:

    PressureSensor(Mux &mux);

    void init() override;

    uint16_t read(uint8_t channel) override;   


private:

    Mux* _mux;

};