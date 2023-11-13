#include "Sensor_DHT11.h"

bool Sensor_DHT11::init() {
  _dht.begin();
  return true;
}

float Sensor_DHT11::readTemperature() { return _dht.readTemperature(); }

float Sensor_DHT11::readHumidity() { return _dht.readHumidity(); }
