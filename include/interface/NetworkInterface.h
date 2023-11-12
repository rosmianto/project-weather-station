#pragma once

class NetworkInterface {

public:
  virtual bool init() = 0;
  virtual bool readTemperature() = 0;
  virtual bool readHumidity() = 0;
};