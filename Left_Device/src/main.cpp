#include <Arduino.h>

#include "config.h"
#include "frame.h"

#include "sensors/PressureSensor.h"
#include "mux.h"
#include "sampler.h"

#include "espnow_comm.h"
#include "control.h"

#include "hw_timer.h"

#include "queues.h"
#include "rtos_tasks.h"

#include "system_state.h"


/* Create Mux object for pressure sensor */
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
   state_set(SystemState::INIT);
  
    Serial.begin(115200);

    setCpuFrequencyMhz(80);
    analogReadResolution(8);

    /* Hardware and communication initialization */
    pressureMux.init();

    if(!pressureSensor.init())
    {
        state_set(SystemState::ERROR);
        return;
    }

    sampler_init(pressureSensor);
    espnow_init();

    state_set(SystemState::IDLE);

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