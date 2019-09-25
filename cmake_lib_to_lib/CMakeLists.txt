
project(cmake_lib_to_lib)

cmake_minimum_required(VERSION 3.10.0)
if(CMAKE_VERSION VERSION_LESS "3.16.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(lib1)
include_directories(lib2)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "README.md"
    )

add_subdirectory(lib1)
add_subdirectory(lib2)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets
    lib1 lib2 )
