cmake_minimum_required(VERSION 3.14)
project(PinVolQt LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Multimedia Widgets)

qt_standard_project_setup()

qt_add_executable(PinVolQt
    src/main.cpp
    src/volumemanager.cpp src/volumemanager.h
)

qt_add_qml_module(PinVolQt
    URI PinVolQt
    VERSION 1.0
    QML_FILES
        qml/main.qml
)

target_link_libraries(PinVolQt PRIVATE Qt6::Core Qt6::Quick Qt6::Multimedia Qt6::Widgets)

install(TARGETS PinVolQt
    BUNDLE DESTINATION .
    RUNTIME DESTINATION bin
)
