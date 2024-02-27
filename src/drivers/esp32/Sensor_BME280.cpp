#include "Sensor_BME280.h"

bool Sensor_BME280::init() {
  _dht.begin();
  return true;
}

float Sensor_BME280::readTemperature() { return _dht.readTemperature(); }

float Sensor_BME280::readHumidity() { return _dht.readHumidity(); }
