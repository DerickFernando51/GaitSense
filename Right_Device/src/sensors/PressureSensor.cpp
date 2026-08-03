#include "sensors/PressureSensor.h"


PressureSensor::PressureSensor(Mux &mux)
{
    _mux = &mux;
}


bool PressureSensor::init()
{
   return true;
}


uint16_t PressureSensor::read(uint8_t channel)
{
    _mux->setChannel(channel);

    return _mux->read();
}