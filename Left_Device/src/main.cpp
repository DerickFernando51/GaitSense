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

/* Create Mux object for pressure sensor */
Mux pressureMux(
    MUX_S0,
    MUX_S1,
    MUX_S2,
    MUX_S3,
    MUX_SIG
);


void setup()
{
    Serial.begin(115200);

    setCpuFrequencyMhz(80);
    analogReadResolution(8);

    /* Hardware and communication initialization */
    pressureMux.init();
    sampler_init(pressureMux);
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