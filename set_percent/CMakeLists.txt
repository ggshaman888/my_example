cmake_minimum_required(VERSION 3.5)

project(set_percent LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "calculate_for_list.cpp"
    "example/example_uart.cpp"
    "README.md"
    )
target_link_libraries(${PROJECT_NAME} Qt5::Core)
