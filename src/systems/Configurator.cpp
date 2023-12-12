#include "Configurator.h"

#include <sstream> // Include the necessary header file

Configurator::Configurator(Settings &cfg) : _cfg(cfg) {}

#include <sstream> // Include the necessary header file

std::string Configurator::processInput(std::string input) {
  // Split input with ':' delimiter
  // Example input: "timezone:-7"
  std::string key;
  std::string valueStr;
  int value = 0;

  std::istringstream iss(input);

  std::getline(iss, key, ':');
  std::getline(iss, valueStr, ':');

  if (valueStr.size() > 0) {
    value = std::stoi(valueStr);
  } else {
    return "ERROR";
  }

  printf("key   : %s\r\n", key.c_str());
  printf("value : %d\r\n", value);

  if (key == "timezone") {
    if (-12 <= value && value <= 14) {
      _cfg.timezone = value;
      return "OK";
    }
  } else if (key == "interval") {
    if (value >= 100 && value <= 60000) {
      _cfg.updateInterval_ms = value;
      return "OK";
    }
  }

  return "ERROR";
}