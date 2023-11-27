cmake_minimum_required(VERSION 3.10)

enable_testing()

project(weather_station)

add_compile_options(-std=gnu++17)

add_subdirectory(../lib/Catch2-3.4.0)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)