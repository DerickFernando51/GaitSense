#include <Arduino.h>

#include "config.h"
#include "frame.h"

#include "sensors/PressureSensor.h"
#include "mux.h"
#include "sampler.h"

#include "espnow_comm.h"
#include "ble_comm.h"

#include "control.h"

#include "hw_timer.h"

#include "queues.h"
#include "rtos_tasks.h"


Mux pressureMux(
    MUX_S0,
    MUX_S1,
    MUX_S2,
    MUX_S3,
    MUX_SIG
);

PressureSensor pressureSensor(pressureMux);


void setup()
{
    Serial.begin(115200);

    setCpuFrequencyMhz(80);
    analogReadResolution(8);

    /* Hardware and communication initialization */
    pressureMux.init();
    pressureSensor.init();
    sampler_init(pressureSensor);
    espnow_init();
    ble_init();

    /* RTOS*/
    queues_init();
    rtos_tasks_init();

    /* Start timer */
    timer_init();

    Serial.println("Right ESP32-C3 ready");
}


void loop()
{
    vTaskDelay(portMAX_DELAY);
}