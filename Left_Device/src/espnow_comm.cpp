#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <string.h>

#include "espnow_comm.h"
#include "config.h"
#include "control.h"
#include "system_state.h"


static void onReceive(
    const uint8_t *mac,
    const uint8_t *data,
    int len
)
{
    if (len == 5 && strncmp((char*)data, "START", 5) == 0)
    {
        control_start();

        Serial.println("START received");
    }
    else if (len == 4 && strncmp((char*)data, "STOP", 4) == 0)
    {
        control_stop();

        Serial.println("STOP received");
    }
}



void espnow_init()
{
    WiFi.mode(WIFI_STA);


    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW init failed");

        state_set(SystemState::ERROR);
        return;
    }


    esp_now_peer_info_t peer = {};

    memcpy(
        peer.peer_addr,
        RIGHT_MAC,
        6
    );


    if(esp_now_add_peer(&peer) != ESP_OK)
    {
        Serial.println("ESP-NOW peer add failed");

        state_set(SystemState::ERROR);
        return;
    }


    esp_now_register_recv_cb(onReceive);
}



void espnow_send_frame(frame_t* frame)
{
    if(frame == nullptr)
    {
        state_set(SystemState::ERROR);
        return;
    }


    esp_err_t result = esp_now_send(
        RIGHT_MAC,
        (uint8_t*)frame,
        sizeof(frame_t)
    );


    if(result != ESP_OK)
    {
        Serial.println("ESP-NOW send failed");

        state_set(SystemState::ERROR);
    }
}