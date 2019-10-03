cmake_minimum_required(VERSION 3.5)

project(macConverter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(macConverter main.cpp convert_mac.cpp prepare_mac.cpp)
target_link_libraries(macConverter Qt5::Core)
