#pragma once

#include <interface/TimeInterface.h>
#include <string>
#include <systems/Settings.h>

class Configurator {

public:
  Configurator(Settings &cfg, TimeInterface &time);
  std::string processInput(std::string input);

private:
  Settings &_cfg;
  TimeInterface &_time;
};