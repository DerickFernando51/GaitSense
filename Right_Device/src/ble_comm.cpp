#include "ble_comm.h"
#include "config.h"
#include "control.h"
#include "espnow_comm.h"

#include <NimBLEDevice.h>

static NimBLECharacteristic* dataChar;
static NimBLECharacteristic* controlChar;

class ControlCB : public NimBLECharacteristicCallbacks {

    void onWrite(NimBLECharacteristic* c) override {

        std::string cmd = c->getValue();

        if (cmd == "START") {

            control_start();
            espnow_send_command("START");
        }
        else if (cmd == "STOP") {

            control_stop();
            espnow_send_command("STOP");
        }
    }
};

void ble_init() {

    NimBLEDevice::init(DEVICE_NAME);

    auto server = NimBLEDevice::createServer();
    auto service = server->createService(SERVICE_UUID);

    dataChar = service->createCharacteristic(DATA_CHAR_UUID, NIMBLE_PROPERTY::NOTIFY);
    controlChar = service->createCharacteristic(CONTROL_CHAR_UUID, NIMBLE_PROPERTY::WRITE);

    controlChar->setCallbacks(new ControlCB());

    service->start();
    NimBLEDevice::getAdvertising()->start();
}

void ble_send_frame(ble_frame_t* frame) {

    dataChar->setValue((uint8_t*)frame, sizeof(ble_frame_t));
    dataChar->notify();
}

bool ble_is_streaming() {
    return control_is_streaming();
}