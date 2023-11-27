#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>
#include <interface/DisplayInterface.h>

class Display_SSD1306 : public DisplayInterface {

public:
  bool init();
  bool setTemperatureValue(float value);
  bool setHumidityValue(float value);
  bool setConnectionStatus(bool connected);
  bool setDatetimeValue(std::string datetimeStr);

private:
  Adafruit_SSD1306 _oled{128, 64, &Wire, -1};
  float _temperature = 0;
  float _humidity = 0;
  bool _connectionStatus = false;
  std::string _datetimeStr;

  void refreshDisplay();
};