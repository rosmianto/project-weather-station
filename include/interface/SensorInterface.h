#pragma once

class SensorInterface {

public:
  virtual bool init() = 0;
  virtual float readTemperature() = 0;
  virtual float readHumidity() = 0;
};