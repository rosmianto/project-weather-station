#pragma once

#include <DHT.h>
#include <interface/SensorInterface.h>

class Sensor_DHT22 : public SensorInterface {
public:
  bool init();
  // TODO: readTemperature() isn't a good function name. Better add unit like C
  // or F to denote the correct value unit.
  float readTemperature();
  float readHumidity();

private:
  DHT _dht{23, DHT22};
};