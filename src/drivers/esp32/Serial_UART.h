#pragma once

#include <Arduino.h>
#include <interface/SerialInterface.h>
#include <string>

class Serial_UART : public SerialInterface {

public:
  bool init();
  std::string read();
  bool write(std::string text);
};