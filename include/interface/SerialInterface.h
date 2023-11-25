#pragma once

#include <string>

class SerialInterface {

public:
  virtual bool init() = 0;
  virtual std::string read() = 0;
  virtual bool write(std::string text) = 0;
};