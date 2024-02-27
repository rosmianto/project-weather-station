#include <Arduino.h>

#include <WeatherStation.h>
#include <drivers/dummy/Sensor_Dummy.h>
#include <drivers/esp32/Display_SSD1306.h>
#include <drivers/esp32/Network_WiFi.h>
#include <drivers/esp32/Sensor_AHT10.h>
#include <drivers/esp32/Sensor_BME280.h>
#include <drivers/esp32/Sensor_DHT22.h>
#include <drivers/esp32/Serial_UART.h>
#include <drivers/esp32/Storage_LittleFS.h>
#include <drivers/esp32/Time_DS3231.h>

#include <autoconf.h>

// TODO: Add autoformatter for a consistent coding style.
// Feature proposal:
// * Settings store to the storage including timezone info.
// and create timeFormatter(uint32_t unixtime) to follow timezone, for unit
// testing purpose. Edge cases: +- UTC, UTC+24 +36,
// * Download OpenWeather JSON and parse, for unit testing.
// * Settings in JSON, for unit testing.
// * Configuration via UART (or via WebUI for paid content), can be unit tested
// *
Display_SSD1306 ssd1306;
Storage_LittleFS lfs;
Time_DS3231 ds3231;
Network_WiFi wifi;
Serial_UART ser;

#if defined(CONFIG_TEMP_DHT22)
Sensor_DHT22 sensor;
#elif defined(CONFIG_TEMP_AHT10)
Sensor_AHT10 sensor;
#elif defined(CONFIG_TEMP_BME280)
Sensor_BME280 sensor;
#elif defined(CONFIG_TEMP_DUMMY)
Sensor_Dummy sensor;
#endif

WeatherStation ws(ssd1306, wifi, sensor, lfs, ds3231, ser);

uint32_t sensorLastUpdated = 0;

void setup() {
  Serial.begin(115200);

#if defined(CONFIG_TEST_OPTION)
  printf("Hello World!\r\n");
#endif

  ws.init();

  Serial.println("Weather Station Initialized.");

  sensorLastUpdated = millis();
}

void loop() {
  if (millis() - sensorLastUpdated >= ws._cfg.getInterval()) {
    sensorLastUpdated = millis();
    ws.updateSensorData();
  }

  ws.checkSerialConfig();
}