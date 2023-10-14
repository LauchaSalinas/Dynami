#include "Dynami_Bluetooth.h"

Dynami_Bluetooth::Dynami_Bluetooth() {}

void Dynami_Bluetooth::BTSetup()
{
    // Serial.begin(115200);
    // // Create the BLE Device
    // BLEDevice::init("ESP32");

    // // Create the BLE Server
    // pServer = BLEDevice::createServer();
    // SCB = new MyServerCallbacks();
    // pServer->setCallbacks(SCB);

    // // Create the BLE Service
    // BLEService *pService = pServer->createService(SERVICE_UUID);

    // // Create a BLE Characteristic
    // pCharacteristic = pService->createCharacteristic(
    //     CHARACTERISTIC_UUID,
    //     BLECharacteristic::PROPERTY_NOTIFY);

    // // Create a BLE Descriptor

    // pDescr = new BLEDescriptor((uint16_t)0x2901);
    // pDescr->setValue("A very interesting variable");
    // pCharacteristic->addDescriptor(pDescr);

    // pBLE2902 = new BLE2902();
    // pBLE2902->setNotifications(true);
    // pCharacteristic->addDescriptor(pBLE2902);

    // // Start the service
    // pService->start();

    // // Start advertising
    // BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    // pAdvertising->addServiceUUID(SERVICE_UUID);
    // pAdvertising->setScanResponse(false);
    // pAdvertising->setMinPreferred(0x0); // set value to 0x00 to not advertise this parameter
    // BLEDevice::startAdvertising();
    // dynamiMediator->bluetoothStartAdvertising();
}

/**
 * @brief Advertises a Text Value.
 * @note We can manage different interrupt service for each unit.
 *       This function will use the default ISR handle service, Calling pcnt_isr_service_uninstall to
 *       uninstall the default service if needed. Please do not use pcnt_isr_register if this function was called.
 *
 * @param txString String formated as char * to be sent
 *
 * @return
 *     // DEVELOP THIS LATER (enum list of Dynami Returns)
 *     - DYNAMI_OK Success
 *     - ESP_ERR_INVALID_STATE pcnt driver has not been initialized
 *     - ESP_ERR_NO_MEM No memory to install this service
 *     - ESP_ERR_INVALID_STATE ISR service already installed
 */
void Dynami_Bluetooth::BTSendValue(char * txString)
{
    // if (SCB->deviceConnected) //(this->SCB->deviceConnected)
    // {
    //     pCharacteristic->setValue(txString);
    //     pCharacteristic->notify();
    // }
}

void Dynami_Bluetooth::BTLoop()
{

    // // disconnecting
    // if (!SCB->deviceConnected && SCB->oldDeviceConnected)
    // {
    //     dynamiMediator->bluetoothDeviceDisconnected();
    //     SCB->oldDeviceConnected = SCB->deviceConnected;
    // }
    // // connecting
    // if (SCB->deviceConnected && !SCB->oldDeviceConnected)
    // {
    //     dynamiMediator->bluetoothDeviceConnected();
    //     SCB->oldDeviceConnected = SCB->deviceConnected;
    // }

    // if (millis() > lastTimeSerialCheck + serialCheckTimeOut)
    // {
    //     if (Serial.available())
    //     {
    //         SerialBT.write(Serial.read());
    //     }
    //     if (SerialBT.available())
    //     {
    //         Serial.write(SerialBT.read());
    //     }
    //     lastTimeSerialCheck = millis();
    // }
}

void Dynami_Bluetooth::startAdvertising()
{
    // pServer->startAdvertising(); // restart advertising
}