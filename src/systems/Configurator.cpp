#include "Configurator.h"

#include <sstream> // Include the necessary header file

Configurator::Configurator(Settings &cfg, TimeInterface &time)
    : _cfg(cfg), _time(time) {}

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

  if (key == "load") {
    _cfg.load();
    return "OK";
  } else if (key == "store") {
    _cfg.store();
    return "OK";
  }

  if (valueStr.size() > 0) {
    value = std::stoi(valueStr);
  } else {
    return "ERROR";
  }

  printf("key   : %s\r\n", key.c_str());
  printf("value : %d\r\n", value);

  if (key == "timezone") {
    if (-12 <= value && value <= 14) {
      _cfg.setTimezone(value);
      return "OK";
    }
  } else if (key == "interval") {
    if (value >= 100 && value <= 60000) {
      _cfg.setInterval(value);
      return "OK";
    }
  } else if (key == "unixtime") {
    _time.setCurrentTime(value);
    return "OK";
  }

  return "ERROR";
}