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

  auto writtenBytes = f.print(data.c_str());

  f.close();

  return (writtenBytes == data.length());
}

std::string Storage_LittleFS::readFile(std::string filename) {
  File f = LittleFS.open(filename.c_str(), "r", false);
  if (!f) {
    return "";
  }

  std::string fileContent = f.readString().c_str();

  f.close();

  return fileContent;
}

bool Storage_LittleFS::deleteFile(std::string filename) {
  return LittleFS.remove(filename.c_str());
}

bool Storage_LittleFS::exists(std::string filename) {
  return LittleFS.exists(filename.c_str());
}
