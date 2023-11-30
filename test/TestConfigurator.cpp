#include "fakeit.hpp"
#include <catch2/catch_all.hpp>

#include <drivers/linux/Storage_Linux.h>
#include <systems/Configurator.h>
#include <systems/Settings.h>

Storage_Linux storage;
Settings cfg(storage);
Configurator configurator(cfg);

// This is actually not a unit test, this is a integration test.
TEST_CASE("Configurator::processInput()", "[configurator]") {
  SECTION("should return OK") {
    std::string input = "OK";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
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
    REQUIRE(cfg.timezone == 7);
  }

  SECTION("Updating negative Timezone") {
    std::string input = "timezone:-7";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.timezone == -7);
  }

  SECTION("Incomplete timezone format") {
    std::string input = "timezone:";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
    REQUIRE(cfg.timezone == 7);
  }

  SECTION("Updating Interval") {
    std::string input = "interval:1000";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "OK");
    REQUIRE(cfg.updateInterval_ms == 1000);
  }

  SECTION("Updating Negative Interval") {
    std::string input = "interval:-1000";
    std::string result = configurator.processInput(input);
    REQUIRE(result == "ERROR");
    REQUIRE(cfg.updateInterval_ms == 1000);
  }
}