project(erp)

cmake_minimum_required(VERSION 3.10)
if(CMAKE_VERSION VERSION_LESS "3.15.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS REQUIRED Core Sql)

add_library(${PROJECT_NAME}
    "connectdb.cpp"
#    "connectlibpq.cpp"
    "generatedmacaddres.cpp"
    "globalerp.cpp"
    "sqlseterp.cpp"
    "sqltoerp.cpp"
    )

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Sql )
