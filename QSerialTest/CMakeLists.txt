project(QSerialTest)

cmake_minimum_required(VERSION 3.10.0)
if(CMAKE_VERSION VERSION_LESS "3.15.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

add_compile_options(-Wall)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core Sql Gui REQUIRED)
include_directories(terminal)


add_executable(${PROJECT_NAME}
    main.cpp
)

add_subdirectory(terminal)


target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Sql Qt5::Gui
     terminal )
