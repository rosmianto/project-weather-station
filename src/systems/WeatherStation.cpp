#include "WeatherStation.h"

WeatherStation::WeatherStation(DisplayInterface &disp, NetworkInterface &net,
                               SensorInterface &sens, StorageInterface &stg,
                               TimeInterface &time)
    : _disp(disp), _net(net), _sens(sens), _stg(stg), _time(time) {}

bool WeatherStation::init() {
  _disp.init();
  _net.init();
  _sens.init();
  _stg.init();
  _time.init();

  _time.setCurrentTime(1700793918UL);

  _disp.setConnectionStatus(false);
  _disp.setDatetimeValue(_time.getCurrentTime());
  _disp.setHumidityValue(_sens.readHumidity());
  _disp.setTemperatureValue(_sens.readTemperature());

  return true;
}

bool WeatherStation::updateSensorData() {
  _disp.setDatetimeValue(_time.getCurrentTime());
  _disp.setHumidityValue(_sens.readHumidity());
  _disp.setTemperatureValue(_sens.readTemperature());

  return true;
}
