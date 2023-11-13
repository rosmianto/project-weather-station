#include "Time_DS3231.h"

bool Time_DS3231::init() { return _rtc.begin(); }

bool Time_DS3231::setCurrentTime(uint32_t unixtime) {
  _rtc.adjust(DateTime(unixtime));

  return true;
}

uint32_t Time_DS3231::getCurrentTime() { return _rtc.now().unixtime(); }
