cmake_minimum_required(VERSION 3.5)

project(i2cTLVGenerator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(i2cTLVGenerator
  main.cpp
  generatefromtlv.cpp
  generatefromtlv.h
  generatefromtlv.ui
  crc-master/crc.cpp
)

target_link_libraries(i2cTLVGenerator PRIVATE Qt5::Widgets)
