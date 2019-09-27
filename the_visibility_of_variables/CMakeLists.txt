cmake_minimum_required(VERSION 3.5)

project(the_visibility_of_variables LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(the_visibility_of_variables main.cpp myclass1.cpp)
target_link_libraries(the_visibility_of_variables Qt5::Core)
