#include "Sensor_Dummy.h"

bool Sensor_Dummy::init() { return true; }

float Sensor_Dummy::readTemperature() { return 34.5; }

float Sensor_Dummy::readHumidity() { return 56.7; }
