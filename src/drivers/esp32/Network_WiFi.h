#pragma once

#include <WiFi.h>
#include <interface/NetworkInterface.h>

class Network_WiFi : public NetworkInterface {
public:
  bool init();
};
