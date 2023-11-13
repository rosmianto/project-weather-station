#pragma once

#include <DHT.h>
#include <interface/SensorInterface.h>

class Sensor_DHT11 : public SensorInterface {
public:
  bool init();
  float readTemperature();
  float readHumidity();

private:
  DHT _dht{DHT22, 23};
};