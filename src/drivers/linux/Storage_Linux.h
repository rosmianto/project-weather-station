#pragma once

#include <interface/StorageInterface.h>
#include <string.h>

class Storage_Linux : public StorageInterface {

public:
  bool init();
  bool writeFile(std::string filename, std::string data);
  std::string readFile(std::string filename);
  bool deleteFile(std::string filename);
  bool exists(std::string filename);
};