#include "mux.h"


Mux::Mux(
    uint8_t s0,
    uint8_t s1,
    uint8_t s2,
    uint8_t s3,
    uint8_t sig
)
:
_s0(s0),
_s1(s1),
_s2(s2),
_s3(s3),
_sig(sig)
{

}


void Mux::init()
{
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    pinMode(_s3, OUTPUT);

    pinMode(_sig, INPUT);
}


void Mux::setChannel(uint8_t ch)
{
    digitalWrite(_s0, ch & 1);
    digitalWrite(_s1, (ch >> 1) & 1);
    digitalWrite(_s2, (ch >> 2) & 1);
    digitalWrite(_s3, (ch >> 3) & 1);
}


uint16_t Mux::read()
{
    delayMicroseconds(10);

    return analogRead(_sig);
}