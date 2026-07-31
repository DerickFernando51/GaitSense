#include "queues.h"
#include "frame.h"

SemaphoreHandle_t sampleSemaphore;

QueueHandle_t bleQueue;
QueueHandle_t leftFrameQueue;

void queues_init()
{
    sampleSemaphore = xSemaphoreCreateBinary();

    bleQueue = xQueueCreate(
        8,
        sizeof(ble_frame_t)
    );

    leftFrameQueue = xQueueCreate(
        1,
        sizeof(ble_frame_t)
    );
}