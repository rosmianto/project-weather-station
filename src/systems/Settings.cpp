#include "Settings.h"

Settings::Settings(StorageInterface &stg) : _stg(stg) {}

bool Settings::load(std::string filename) {
  std::string settingJson = _stg.readFile(filename);

  StaticJsonDocument<96> doc;

  DeserializationError error = deserializeJson(doc, settingJson);

  if (error) {
    printf("deserializeJson() failed: ");
    printf(error.c_str());
    return false;
  }

  timezone = doc["timezone"];
  updateInterval_ms = doc["updateInterval_ms"];

  return true;
}

bool Settings::store(std::string filename) {
  StaticJsonDocument<32> doc;

  doc["timezone"] = timezone;
  doc["updateInterval_ms"] = updateInterval_ms;

  std::string settingJson;
  serializeJsonPretty(doc, settingJson);

  bool result = _stg.writeFile(filename, settingJson);

  return result;
}
