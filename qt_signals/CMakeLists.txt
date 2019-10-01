cmake_minimum_required(VERSION 3.5)

project(qt_signals_slots LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

add_executable(untitled
  main.cpp
  api_from_ux.cpp
  first.cpp
  middle.cpp
  second.cpp
  readme.md
  ux/wait_for_the_end.cpp
  ux/waitfortheend.ui

)

target_link_libraries(untitled PRIVATE Qt5::Widgets Qt5::Core)
