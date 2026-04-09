#include <Arduino.h>
#include "hw_timer.h"
#include "config.h"

static hw_timer_t* timer = NULL;
static volatile bool flag = false;

void IRAM_ATTR onTimer() {
    flag = true;
}

void timer_init() {

    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, TIMER_INTERVAL_US, true);
    timerAlarmEnable(timer);
}

bool timer_flag() {
    return flag;
}

void timer_clear() {
    flag = false;
}