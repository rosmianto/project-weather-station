// #include "fakeit.hpp"
#include <catch2/catch_all.hpp>

#include <drivers/dummy/Time_Dummy.h>
#include <drivers/linux/Storage_Linux.h>
#include <systems/Configurator.h>
#include <systems/Settings.h>

Time_Dummy time_dummy;
Storage_Linux storage;
Settings cfg(storage);
Configurator configurator(cfg, time_dummy);

// This is actually not a unit test, this is a integration test.
TEST_CASE("Configurator::processInput()", "[configurator]") {

  SECTION("should return ERROR") {
    std::string input = "OK";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
  }

  SECTION("should return ERROR") {
    std::string input = "ERROR";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
  }

  SECTION("Updating Timezone") {
    std::string input = "timezone:+7";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.getTimezone() == 7);
  }

  SECTION("Updating negative Timezone") {
    std::string input = "timezone:-7";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.getTimezone() == -7);
  }

  SECTION("Incomplete timezone format") {
    std::string input = "timezone:";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
    REQUIRE(cfg.getTimezone() == -7);
  }

  SECTION("Updating Interval") {
    std::string input = "interval:1000";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.getInterval() == 1000);
  }

  SECTION("Updating Negative Interval") {
    std::string input = "interval:-1000";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
    REQUIRE(cfg.getInterval() == 1000);
  }

  SECTION("Invalid Field Name") {
    std::string input = "intervaaa:1000";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
    REQUIRE(cfg.getInterval() == 1000);
  }

  SECTION("Store current Settings") {
    std::string input = "store";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.getInterval() == 1000);
    REQUIRE(cfg.getTimezone() == -7);
  }

  SECTION("Load current Settings") {
    std::string input = "load";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.getInterval() == 1000);
    REQUIRE(cfg.getTimezone() == -7);
  }

  SECTION("Update Datetime") {
    std::string input = "unixtime:1700793918";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(time_dummy.getCurrentTime() == 1700793918);
  }
}