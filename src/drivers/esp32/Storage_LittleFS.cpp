#include "Storage_LittleFS.h"

bool Storage_LittleFS::init() {
  LittleFS.begin(true);
  return true;
}

bool Storage_LittleFS::writeFile(std::string filename, std::string data) {
  File f = LittleFS.open(filename.c_str(), "w", true);
  if (!f) {
    return false;
  }

  f.write(data);

  f.close();

  return true;
}

std::string Storage_LittleFS::readFile(std::string filename) {}

bool Storage_LittleFS::deleteFile(std::string filename) { return true; }
