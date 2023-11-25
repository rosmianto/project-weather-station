#pragma once

#include <ArduinoJson.h>
#include <interface/StorageInterface.h>

class Settings {

public:
  Settings(StorageInterface &stg);

  uint8_t timezone = 7;
  uint8_t updateInterval_ms = 2000;

  bool load(std::string filename = "/settings.json");
  bool store(std::string filename = "/settings.json");

private:
  StorageInterface &_stg;
};