#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>

extern SemaphoreHandle_t sampleSemaphore;

extern QueueHandle_t bleQueue;
extern QueueHandle_t leftFrameQueue;

void queues_init();