#include "Settings.h"

Settings::Settings(StorageInterface &stg) : _stg(stg) {}

bool Settings::load(std::string filename) {
  if (_stg.exists(filename) == false) {
    store();
    return true;
  }

  std::string settingJson = _stg.readFile(filename);

  printf("Setting JSON: %s\r\n", settingJson.c_str());

  StaticJsonDocument<96> doc;

  DeserializationError error = deserializeJson(doc, settingJson);

  if (error) {
    printf("deserializeJson() failed: %s\r\n", error.c_str());
    return false;
  }

  _timezone = doc["timezone"];
  _updateInterval_ms = doc["updateInterval_ms"];

  return true;
}

bool Settings::store(std::string filename) {
  StaticJsonDocument<64> doc;

  doc["timezone"] = _timezone;
  doc["updateInterval_ms"] = _updateInterval_ms;

  std::string settingJson;
  serializeJsonPretty(doc, settingJson);

  bool result = _stg.writeFile(filename, settingJson);

  return result;
}

bool Settings::setInterval(uint32_t milliseconds) {
  _updateInterval_ms = milliseconds;
}

bool Settings::setTimezone(int8_t timezone) { _timezone = timezone; }

uint32_t Settings::getInterval() { return _updateInterval_ms; }

int8_t Settings::getTimezone() { return _timezone; }
