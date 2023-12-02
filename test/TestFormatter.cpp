// #include "fakeit.hpp"
#include <catch2/catch_all.hpp>

#include <systems/Formatter.h>

uint32_t unixtime = 1672506000UL;

TEST_CASE("Formatter::FormatTime", "[formatter]") {
  SECTION("Format unixtime to UTC+0") {
    REQUIRE(Formatter::formatTime(unixtime, 0) == "2022-12-31 17:00:00");
  }

  SECTION("Format unixtime to UTC+7") {
    REQUIRE(Formatter::formatTime(unixtime, 7) == "2023-01-01 00:00:00");
  }

  SECTION("Format unixtime to UTC-7") {
    REQUIRE(Formatter::formatTime(unixtime, -7) == "2022-12-31 10:00:00");
  }

  SECTION("Format unixtime to UTC+14") {
    REQUIRE(Formatter::formatTime(unixtime, 14) == "2023-01-01 07:00:00");
  }

  SECTION("Format unixtime to UTC-14") {
    REQUIRE(Formatter::formatTime(unixtime, -14) == "2022-12-31 03:00:00");
  }

  SECTION("Format unixtime to UTC+30") {
    REQUIRE(Formatter::formatTime(unixtime, 30) == "2023-01-01 23:00:00");
  }
}