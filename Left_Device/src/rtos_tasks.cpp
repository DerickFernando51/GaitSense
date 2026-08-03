#include <Arduino.h>

#include "rtos_tasks.h"
#include "queues.h"

#include "sampler.h"
#include "espnow_comm.h"
#include "control.h"

#include "system_state.h"


static frame_t frame;


static void SampleTask(void *pv)
{
    for (;;)
    {
        xSemaphoreTake(
            sampleSemaphore,
            portMAX_DELAY
        );


        if(!control_is_streaming())
            continue;


        sample_left_frame(
            &frame,
            control_get_timestamp()
        );


        if(xQueueSend(
            espnowQueue,
            &frame,
            0
        ) != pdPASS)
        {
            state_set(SystemState::ERROR);
        }
    }
}


static void ESPNOWTask(void *pv)
{
    frame_t rxFrame;


    for (;;)
    {
        xQueueReceive(
            espnowQueue,
            &rxFrame,
            portMAX_DELAY
        );


        if(state_get() == SystemState::STREAMING)
        {
            espnow_send_frame(&rxFrame);
        }
    }
}


void StateTask(void *pv)
{
    while(true)
    {
        if(state_get() == SystemState::ERROR)
        {
            Serial.println("System error");
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


void rtos_tasks_init()
{
    xTaskCreate(
        SampleTask,
        "Sample",
        4096,
        NULL,
        4,
        NULL
    );


    xTaskCreate(
        ESPNOWTask,
        "ESPNOW",
        4096,
        NULL,
        3,
        NULL
    );


    xTaskCreate(
        StateTask,
        "State",
        2048,
        NULL,
        1,
        NULL
    );
}