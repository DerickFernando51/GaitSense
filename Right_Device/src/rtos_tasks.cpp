#include "rtos_tasks.h"

#include "queues.h"
#include "sampler.h"
#include "ble_comm.h"
#include "control.h"
#include "espnow_comm.h"

static ble_frame_t rightFrame;

static void SampleTask(void *pv)
{
    for (;;)
    {
        xSemaphoreTake(sampleSemaphore, portMAX_DELAY);

        if (!ble_is_streaming())
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

        if (xQueuePeek(leftFrameQueue, &left, 0))
        {
            ble_send_frame(&left);
        }
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
}