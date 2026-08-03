#include "rtos_tasks.h"

#include "queues.h"
#include "sampler.h"
#include "ble_comm.h"
#include "control.h"
#include "espnow_comm.h"

#include "system_state.h"


static ble_frame_t rightFrame;


static void SampleTask(void *pv)
{
    for (;;)
    {
        xSemaphoreTake(
            sampleSemaphore,
            portMAX_DELAY
        );


        if(state_get() != SystemState::STREAMING)
            continue;


        sample_right_frame(
            &rightFrame,
            control_get_timestamp()
        );


        xQueueSend(
            bleQueue,
            &rightFrame,
            0
        );
    }
}


static void BLETask(void *pv)
{
    ble_frame_t right;
    ble_frame_t left;


    for (;;)
    {
        xQueueReceive(
            bleQueue,
            &right,
            portMAX_DELAY
        );


        ble_send_frame(&right);


        if(xQueuePeek(leftFrameQueue, &left, 0))
        {
            ble_send_frame(&left);
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
        BLETask,
        "BLE",
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