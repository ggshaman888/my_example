
project(terminal)

cmake_minimum_required(VERSION 3.10.0)
if(CMAKE_VERSION VERSION_LESS "3.15.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core Sql Gui SerialPort REQUIRED)

include_directories(settings)
include_directories(prepare_input_console)

add_executable(${PROJECT_NAME}
    "consoleform.cpp"
    "runprepare.cpp"
    "setbaikal.cpp"
    "settings/percentwaitfortheend2.cpp"
    "settings/threadwaitcom.cpp"
    "prepare_input_console/piconsole.cpp"
    "main.cpp"
    "step_08_to_kernel.cpp"
    "step_kernel.cpp"
    )

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Sql Qt5::Gui
    Qt5::SerialPort)
