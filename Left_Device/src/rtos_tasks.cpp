#include "rtos_tasks.h"

#include "queues.h"
#include "sensors/ISensor.h"
#include "sampler.h"
#include "espnow_comm.h"
#include "control.h"

static frame_t frame;

static void SampleTask(void *pv)
{
    for (;;)
    {
        xSemaphoreTake(sampleSemaphore, portMAX_DELAY);

        if (!control_is_streaming())
            continue;

        sample_left_frame(
            &frame,
            control_get_timestamp()
        );

        xQueueSend(
            espnowQueue,
            &frame,
            0
        );
    }
}

static void ESPNOWTask(void *pv)
{
    frame_t frame;

    for (;;)
    {
        xQueueReceive(
            espnowQueue,
            &frame,
            portMAX_DELAY
        );

        espnow_send_frame(&frame);
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
}