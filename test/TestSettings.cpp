// #include "fakeit.hpp"
#include <catch2/catch_all.hpp>

#include <drivers/linux/Storage_Linux.h>
#include <interface/StorageInterface.h>
#include <systems/Settings.h>

Storage_Linux stg;
Settings settings(stg);

void removeWhitespace(std::string &str);

TEST_CASE("Settings::store()", "[settings]") {
  SECTION("Store settings to file") {
    REQUIRE(settings.store("test_settings.json"));

    REQUIRE(stg.exists("test_settings.json"));

    std::string settingJson = stg.readFile("test_settings.json");

    removeWhitespace(settingJson);

    REQUIRE(settingJson == "{\"timezone\":7,\"updateInterval_ms\":2000}");
  }
}

TEST_CASE("Settings::load()", "[settings]") {
  SECTION("Load settings from file") {
    REQUIRE(settings.load("test_settings.json"));
    REQUIRE(settings.getTimezone() == 7);
    REQUIRE(settings.getInterval() == 2000);
  }
}

void removeWhitespace(std::string &str) {
  str.erase(std::remove_if(str.begin(), str.end(),
                           [](unsigned char ch) { return std::isspace(ch); }),
            str.end());
}