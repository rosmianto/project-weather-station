#include <Arduino.h>

#include <drivers/esp32/Display_SSD1306.h>
#include <drivers/esp32/Network_WiFi.h>
#include <drivers/esp32/Sensor_DHT22.h>
#include <drivers/esp32/Storage_LittleFS.h>
#include <drivers/esp32/Time_DS3231.h>
#include <systems/WeatherStation.h>

Display_SSD1306 ssd1306;
Sensor_DHT22 dht22;
Storage_LittleFS lfs;
Time_DS3231 ds3231;
Network_WiFi wifi;

WeatherStation ws(ssd1306, wifi, dht22, lfs, ds3231);

void setup() {
  Serial.begin(115200);

  ws.init();

  Serial.println("Weather Station Initialized.");
}

void loop() {
  ws.updateSensorData();

  delay(2000);
}