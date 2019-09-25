project(lib2)

cmake_minimum_required(VERSION 3.10)
if(CMAKE_VERSION VERSION_LESS "3.16.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_library(${PROJECT_NAME}
    "sub/file2.cpp"
    )

target_link_libraries(${PROJECT_NAME} )
