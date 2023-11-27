#include "Serial_UART.h"

bool Serial_UART::init() {
  Serial.begin(115200);
  return true;
}

std::string Serial_UART::read() {
  if (Serial.available()) {
    return Serial.readString().c_str();
  }

  return "";
}

bool Serial_UART::write(std::string text) {
  Serial.println(text.c_str());
  return true;
}
