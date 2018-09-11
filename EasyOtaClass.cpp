#include "EasyOta.h"


void EasyOtaClass::setup() {
#if !defined(ESP_NAME) || !defined(ESP_PW) // TODO: more proper checks?
#warning It seems like your platformio.ini isnt configured properly. \
           Please checkout hw1_ota.h for informations on how to use this lib
#else
    ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
            type = "sketch";
        else // U_SPIFFS
            type = "filesystem";

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS
        // using SPIFFS.end()
        Serial.println("Start updating " + type);
    });
    ArduinoOTA.onEnd([]() { Serial.println("\nEnd"); });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
            Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR)
            Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR)
            Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR)
            Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR)
            Serial.println("End Failed");
    });

    ArduinoOTA.setPassword(ESP_PW);
    ArduinoOTA.begin();
    MDNS.begin(ESP_NAME);
    MDNS.addService("ota", "tcp", 8266);
    Serial.println("OTA is setup " ESP_NAME);
    Serial.println(WiFi.localIP());
#endif //_platformio.ini configured
}

void EasyOtaClass::checkForUpload(){
    /**
    * @brief small wrapper function that calls ArduinoOTA.handle()
    * You should call this method in the loop or maybe on boot?
    */
    ArduinoOTA.handle();
}
EasyOtaClass EasyOta = EasyOtaClass();