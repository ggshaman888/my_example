cmake_minimum_required(VERSION 3.5)

project(parser_log_chipprogusb LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

add_executable(parser_log_chipprogusb
  main.cpp
  infowindow.cpp
  infowindow.h
  infowindow.ui
  readlog.cpp
)

target_link_libraries(parser_log_chipprogusb PRIVATE Qt5::Core Qt5::Widgets)
