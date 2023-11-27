#pragma once

#include <stdint.h>
#include <string>

class Formatter {

public:
  static std::string formatTime(uint32_t unixtime, int timezone);
};