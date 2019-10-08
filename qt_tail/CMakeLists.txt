cmake_minimum_required(VERSION 3.5)

project(qt_tail LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(qt_tail main.cpp tail_main.cpp read_example.cpp README.md)
target_link_libraries(qt_tail Qt5::Core)
