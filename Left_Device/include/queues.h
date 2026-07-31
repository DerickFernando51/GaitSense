#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>

extern SemaphoreHandle_t sampleSemaphore;
extern QueueHandle_t espnowQueue;

void queues_init();