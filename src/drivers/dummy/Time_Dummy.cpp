#include "Time_Dummy.h"

bool Time_Dummy::init() { return true; }

bool Time_Dummy::setCurrentTime(uint32_t unixtime) {
  _currentTime = unixtime;
  return true;
}

uint32_t Time_Dummy::getCurrentTime() { return _currentTime; }
