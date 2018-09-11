# EasyOTA
This is a small wrapper lib for the underlaying ArduinoOTA lib.
To use this library please modify your platformio.ini the following way:
```
[ota]
esp_name = <a name>
esp_pw = <a password>
```
Notes: the name must be lowercase, try to avoid hyphons, underscores seems to
be working fine.
```
[env:<your env>]
build_flags = -DESP_NAME=\"${ota.esp_name}\" -DESP_PW=\"${ota.esp_pw}\"
upload_flags = --auth=${ota.esp_pw}    ;#uncomment after initial flash
upload_port = ${ota.esp_name}.local    ;#uncomment after initial flash
```
The two bottom lines set the upload mode, if uncommented platformio will
flash over OTA otherwise over usb.

Additionally you can add a second environment like following:
```
[env:<your env>_ota]
platform = espressif8266
board = nodemcuv2
framework = arduino
build_flags = -DESP_NAME=\"${ota.esp_name}\" -DESP_PW=\"${ota.esp_pw}\"
upload_flags = --auth=${ota.esp_pw}    ;#uncomment after initial flash
upload_port = ${ota.esp_name}.local    ;#uncomment after initial flash
```
In vscode you can choose which environment you want to flash aka. to choose
if you want to flash over usb or ota.
 

After the initial flash you must reset the esp once.