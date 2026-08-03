#include "espnow_comm.h"
#include "config.h"
#include "system_state.h"

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <string.h>


static ble_frame_t leftFrame;
static bool leftAvailable = false;


static void onReceive(
    const uint8_t *mac,
    const uint8_t *data,
    int len
)
{
    if(len != sizeof(ble_frame_t))
    {
        return;
    }


    memcpy(
        &leftFrame,
        data,
        sizeof(ble_frame_t)
    );


    leftAvailable = true;
}


void espnow_init()
{
    WiFi.mode(WIFI_STA);


    if(esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW init failed");

        state_set(SystemState::ERROR);
        return;
    }


    esp_now_peer_info_t peer = {};

    memcpy(
        peer.peer_addr,
        LEFT_MAC,
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



void espnow_send_command(const char* cmd)
{
    esp_err_t result = esp_now_send(
        LEFT_MAC,
        (uint8_t*)cmd,
        strlen(cmd)
    );


    if(result != ESP_OK)
    {
        Serial.println("ESP-NOW command failed");

        state_set(SystemState::ERROR);
    }
}



bool espnow_has_left()
{
    return leftAvailable;
}



void espnow_get_left(ble_frame_t* frame)
{
    if(frame == nullptr)
        return;


    *frame = leftFrame;

    leftAvailable = false;
}