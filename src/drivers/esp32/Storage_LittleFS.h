#pragma once

#include <LittleFS.h>
#include <interface/StorageInterface.h>

class Storage_LittleFS : public StorageInterface {

public:
  bool init();
  bool writeFile(std::string filename, std::string data);
  std::string readFile(std::string filename);
  bool deleteFile(std::string filename);
  bool exists(std::string filename);
};