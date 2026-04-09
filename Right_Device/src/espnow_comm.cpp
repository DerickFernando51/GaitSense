#include "espnow_comm.h"
#include "config.h"
#include <esp_now.h>
#include <WiFi.h>
#include <string.h>

static ble_frame_t leftFrame;
static bool leftAvailable = false;

static void onReceive(const uint8_t *mac, const uint8_t *data, int len) {

    if (len != NUM_SAMPLES + 5) return;

    leftFrame.side = 0;

    leftFrame.timestamp_ms = (uint32_t)data[1] |
                             ((uint32_t)data[2] << 8) |
                             ((uint32_t)data[3] << 16) |
                             ((uint32_t)data[4] << 24);

    memcpy(leftFrame.samples, data + 5, NUM_SAMPLES);

    leftAvailable = true;
}

void espnow_init() {

    WiFi.mode(WIFI_STA);
    esp_now_init();

    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, LEFT_MAC, 6);

    esp_now_add_peer(&peer);
    esp_now_register_recv_cb(onReceive);
}

void espnow_send_command(const char* cmd) {

    esp_now_send(LEFT_MAC, (uint8_t*)cmd, strlen(cmd));
}

bool espnow_has_left() {
    return leftAvailable;
}

void espnow_get_left(ble_frame_t* frame) {

    *frame = leftFrame;
    leftAvailable = false;
}