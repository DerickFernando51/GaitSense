#include <Arduino.h>

#include "config.h"
#include "frame.h"

#include "mux.h"
#include "sampler.h"

#include "espnow_comm.h"
#include "control.h"

#include "hw_timer.h"

#include "queues.h"
#include "rtos_tasks.h"


void setup()
{
    Serial.begin(115200);

    setCpuFrequencyMhz(80);
    analogReadResolution(8);

    /* Hardware and communication initialization */
    mux_init();
    espnow_init();

    /* FreeRTOS */
    queues_init();
    rtos_tasks_init();

    /* Start sampling timer */
    timer_init();

    Serial.println("Left ESP32-C3 ready");
}


void loop()
{
    vTaskDelay(portMAX_DELAY);
}