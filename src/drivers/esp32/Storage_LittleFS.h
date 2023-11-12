#pragma once

#include <interface/StorageInterface.h>

class Storage_LittleFS : public StorageInterface {

public:
  virtual bool init() = 0;
  virtual bool writeFile(std::string filename, std::string data) = 0;
  virtual std::string readFile(std::string filename) = 0;
  virtual bool deleteFile(std::string filename) = 0;
};