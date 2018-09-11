/**
 * @brief Example ino for EasyOta
 * 
 * @file EasyOta.ino
 * @author regenbogencode
 * @date 2018-09-11
 */
#include "EasyOta.h"
#include <Arduino.h>
const char *WIFI_NAME = "<your wifi>";
const char *WIFI_PW = "<your pw>";
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    Serial.println();
    Serial.println("Booting... ");
    WiFi.begin(WIFI_NAME, WIFI_PW);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        WiFi.begin(WIFI_NAME, WIFI_PW);
        Serial.println("WiFi failed, retrying.");
    }
    Serial.println("Booted");
    EasyOta.setup();
}
void loop() {
    EasyOta.checkForUpload();
    delay(1000 / 10);
    digitalWrite(LED_BUILTIN, 1);
    delay(1000 / 10);
    digitalWrite(LED_BUILTIN, 0);
}