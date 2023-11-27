#pragma once

#include <string>

class StorageInterface {

public:
  virtual bool init() = 0;
  virtual bool writeFile(std::string filename, std::string data) = 0;
  virtual std::string readFile(std::string filename) = 0;
  virtual bool deleteFile(std::string filename) = 0;
  virtual bool exists(std::string filename) = 0;
};