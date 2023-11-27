#pragma once

#include <stdint.h>
#include <string>

class DisplayInterface {

    public:
        virtual bool init() = 0;
        virtual bool setTemperatureValue(float value) = 0;
        virtual bool setHumidityValue(float value) = 0;
        virtual bool setConnectionStatus(bool connected) = 0;
        virtual bool setDatetimeValue(std::string datetimeStr) = 0;
};