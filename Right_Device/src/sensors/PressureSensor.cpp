#include "sensors/PressureSensor.h"


PressureSensor::PressureSensor(Mux &mux)
{
    _mux = &mux;
}


void PressureSensor::init()
{

}


uint16_t PressureSensor::read(uint8_t channel)
{
    _mux->setChannel(channel);

    return _mux->read();
}