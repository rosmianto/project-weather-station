#pragma once

#include <interface/TimeInterface.h>
#include <stdint.h>

class Time_Dummy : public TimeInterface {
public:
  bool init();
  bool setCurrentTime(uint32_t unixtime);
  uint32_t getCurrentTime();

private:
  uint32_t _currentTime = 0;
};