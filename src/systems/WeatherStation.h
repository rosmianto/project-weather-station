#pragma once

#include <interface/DisplayInterface.h>
#include <interface/NetworkInterface.h>
#include <interface/SensorInterface.h>
#include <interface/StorageInterface.h>
#include <interface/TimeInterface.h>

class WeatherStation {

public:
  WeatherStation(DisplayInterface &disp, NetworkInterface &net,
                 SensorInterface &sens, StorageInterface &stg,
                 TimeInterface &time);

  bool init();
  bool updateSensorData();

private:
  DisplayInterface &_disp;
  NetworkInterface &_net;
  SensorInterface &_sens;
  StorageInterface &_stg;
  TimeInterface &_time;
};