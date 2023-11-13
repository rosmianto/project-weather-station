#include "Display_SSD1306.h"

bool Display_SSD1306::init() {
  // My OLED I2C address is 0x3C
  if (!_oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    return false;
  }

  _oled.setTextColor(SSD1306_WHITE);
}

bool Display_SSD1306::setTemperatureValue(float value) {
  _temperature = value;
  refreshDisplay();
  return true;
}

bool Display_SSD1306::setHumidityValue(float value) {
  _humidity = value;
  refreshDisplay();
  return true;
}

bool Display_SSD1306::setConnectionStatus(bool connected) {
  _connectionStatus = connected;
  refreshDisplay();
  return true;
}

bool Display_SSD1306::setDatetimeValue(uint32_t unixtime) {
  _unixtime = unixtime;
  refreshDisplay();
  return true;
}

void Display_SSD1306::refreshDisplay() {
  _oled.clearDisplay();
  _oled.setCursor(0, 0);
  _oled.printf("Temp: %.2f\r\n", _temperature);
  _oled.printf("Hum: %.2f\r\n", _humidity);
  _oled.printf("Connected: %d\r\n", _connectionStatus);
  _oled.printf("Time: %d\r\n", _unixtime);
  _oled.display();
}