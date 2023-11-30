#pragma once

#include <string>
#include <systems/Settings.h>

class Configurator {

public:
  Configurator(Settings &cfg);
  std::string processInput(std::string input);

private:
  Settings &_cfg;
};