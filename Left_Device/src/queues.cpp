#include "queues.h"
#include "frame.h"

SemaphoreHandle_t sampleSemaphore;
QueueHandle_t espnowQueue;

void queues_init()
{
    sampleSemaphore = xSemaphoreCreateBinary();

    espnowQueue = xQueueCreate(
        4,
        sizeof(frame_t)
    );
}