#include "Sensor_DHT22.h"

bool Sensor_DHT22::init() {
  _dht.begin();
  return true;
}

float Sensor_DHT22::readTemperature() { return _dht.readTemperature(); }

float Sensor_DHT22::readHumidity() { return _dht.readHumidity(); }
