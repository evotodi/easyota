/**
 * @brief This is a small wrapper lib for the underlaying ArduinoOTA lib.
 *
 *  Please modify your platformio.ini the following way:
 *
 *  [ota]
 *  esp_name = <a name>
 *  esp_pw = <a password>
 *
 *  Notes: the name must be lowercase, try to avoid hyphons, underscore seems to
 *  be working fine
 *
 *  [env:<your env>]
 *  build_flags = -DESP_NAME=\"${ota.esp_name}\" -DESP_PW=\"${ota.esp_pw}\"
 *  upload_flags = --auth=${ota.esp_pw}    ;#uncomment after initial flash
 *  upload_port = ${ota.esp_name}.local    ;#uncomment after initial flash
 *
 *  the two bottom lines set the upload mode, if uncommented platformio will
 *  flash over OTA otherwise over usb
 * 
 *  additionally you can add a second environment like following:
 *  
 *  [env:<your env>_ota]
 *  platform = espressif8266
 *  board = nodemcuv2
 *  framework = arduino
 *  build_flags = -DESP_NAME=\"${ota.esp_name}\" -DESP_PW=\"${ota.esp_pw}\"
 *  upload_flags = --auth=${ota.esp_pw}    ;#uncomment after initial flash
 *  upload_port = ${ota.esp_name}.local    ;#uncomment after initial flash
 *  
 *  in vscode you can choose which environment you want to flash aka. to choose
 *  if you want to flash over usb or ota
 * 
 * 
 * after the initial flash you must reset the esp once
 *
 * @file hw1_ota.h
 * @author regenbogencode
 * @date 2018-09-11
 */

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>


class EasyOtaClass{
    public:
    void setup();
    void checkForUpload();
};
extern EasyOtaClass EasyOta;