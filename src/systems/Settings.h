#pragma once

#include <ArduinoJson.h>
#include <interface/StorageInterface.h>

class Settings {

public:
  Settings(StorageInterface &stg);

  bool load(std::string filename = "/settings.json");
  bool store(std::string filename = "/settings.json");

  bool setInterval(uint32_t milliseconds);
  bool setTimezone(int8_t timezone);

  uint32_t getInterval();
  int8_t getTimezone();

private:
  StorageInterface &_stg;

  int8_t _timezone = 7;
  uint32_t _updateInterval_ms = 2000;
};