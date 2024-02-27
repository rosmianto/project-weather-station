#pragma once

#include <interface/SensorInterface.h>

class Sensor_Dummy : public SensorInterface {
public:
  bool init();
  // TODO: readTemperature() isn't a good function name. Better add unit like C
  // or F to denote the correct value unit.
  float readTemperature();
  float readHumidity();
};