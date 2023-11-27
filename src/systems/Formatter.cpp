#include "Formatter.h"

std::string Formatter::formatTime(uint32_t unixtime, int timezone) {
  // Convert the Unix timestamp to a time_t type
  time_t unixTimeT = static_cast<time_t>(unixtime);

  // Adjust for the specified timezone offset in seconds
  unixTimeT += timezone * 3600;

  // Use gmtime to convert the adjusted time_t to a struct tm representing UTC
  // time
  struct tm *timeinfo = gmtime(&unixTimeT);

  if (timeinfo == nullptr) {
    return "Error: Invalid Unix timestamp";
  }

  // Format the datetime as a string
  char buffer[20]; // Buffer to hold the formatted string
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

  // Convert the buffer to a string and return it
  return std::string(buffer);
}