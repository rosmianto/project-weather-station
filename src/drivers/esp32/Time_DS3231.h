#pragma once

#include <RTClib.h>
#include <interface/TimeInterface.h>

class Time_DS3231 : public TimeInterface {
public:
  bool init();
  bool setCurrentTime(uint32_t unixtime);
  uint32_t getCurrentTime();

private:
  RTC_DS3231 _rtc;
};