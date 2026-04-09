 #include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <string.h>

#include "espnow_comm.h"
#include "config.h"
#include "control.h"

static void onReceive(const uint8_t *mac, const uint8_t *data, int len) {

    if (len == 5 && strncmp((char*)data, "START", 5) == 0) {

        control_start();
        Serial.println("START received");
    }
    else if (len == 4 && strncmp((char*)data, "STOP", 4) == 0) {

        control_stop();
        Serial.println("STOP received");
    }
}

void espnow_init() {

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("ESP-NOW init failed");
        while (true);
    }

    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, RIGHT_MAC, 6);

    esp_now_add_peer(&peer);
    esp_now_register_recv_cb(onReceive);
}

void espnow_send_frame(frame_t* frame) {

    esp_err_t result = esp_now_send(
        RIGHT_MAC,
        (uint8_t*)frame,
        sizeof(frame_t)
    );

    if (result != ESP_OK) {
        Serial.println("ESP-NOW send failed");
    }
}