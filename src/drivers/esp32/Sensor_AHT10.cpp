#include "Sensor_AHT10.h"

bool Sensor_AHT10::init() {
  _dht.begin();
  return true;
}

float Sensor_AHT10::readTemperature() { return _dht.readTemperature(); }

float Sensor_AHT10::readHumidity() { return _dht.readHumidity(); }
