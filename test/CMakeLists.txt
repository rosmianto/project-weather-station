cmake_minimum_required(VERSION 3.10)

enable_testing()

project(weather_station)

add_compile_options(-std=gnu++17)


option(CMAKE_BUILD_TYPE "Build type" Debug)


# We will be using Catch2 v3
add_subdirectory(Catch2-3.4.0)

# Directory where the .h files live
include_directories(../src)
include_directories(../include)
include_directories(../lib/ArduinoJson-6.21.3/src)

# System module
add_library(Configurator   STATIC ../src/systems/Configurator.cpp)
add_library(Formatter      STATIC ../src/systems/Formatter.cpp)
add_library(Settings       STATIC ../src/systems/Settings.cpp)
add_library(WeatherStation STATIC ../src/WeatherStation.cpp)

# Driver module
add_library(Storage_Linux  STATIC ../src/drivers/linux/Storage_Linux.cpp)
add_library(Time_Dummy     STATIC ../src/drivers/dummy/Time_Dummy.cpp)

# Test module
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(TestSettings TestSettings.cpp)
target_link_libraries(TestSettings PRIVATE Catch2::Catch2WithMain Storage_Linux Settings)

add_executable(TestFormatter TestFormatter.cpp)
target_link_libraries(TestFormatter PRIVATE Catch2::Catch2WithMain Formatter)

add_executable(TestConfigurator TestConfigurator.cpp)
target_link_libraries(TestConfigurator PRIVATE Catch2::Catch2WithMain Configurator Settings Storage_Linux Time_Dummy)

add_test(tests tests)
add_test(TestSettings TestSettings)
add_test(TestFormatter TestFormatter)
add_test(TestConfigurator TestConfigurator)

if(CODE_COVERAGE)
    # Location of Code Coverage module
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
    include(code-coverage)

    target_compile_options(Configurator PRIVATE --coverage)
    target_compile_options(Formatter PRIVATE --coverage)
    target_compile_options(Settings PRIVATE --coverage)
    target_compile_options(WeatherStation PRIVATE --coverage)

    add_code_coverage_all_targets(EXCLUDE */lib/* */Catch2-3.4.0/* /usr/include/*)
    target_code_coverage(tests ALL EXCLUDE */lib/* */Catch2-3.4.0/* /usr/include/*)
    target_code_coverage(TestSettings ALL EXCLUDE */lib/* */Catch2-3.4.0/* /usr/include/*)
    target_code_coverage(TestFormatter ALL EXCLUDE */lib/* */Catch2-3.4.0/* /usr/include/*)
    target_code_coverage(TestConfigurator ALL EXCLUDE */lib/* */Catch2-3.4.0/* /usr/include/*)
endif()
