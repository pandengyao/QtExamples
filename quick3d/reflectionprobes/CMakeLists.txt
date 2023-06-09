cmake_minimum_required(VERSION 3.16)
project(reflectionprobes LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/quick3d/reflectionprobes")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Quick3D)

qt_add_executable(reflectionprobes
    main.cpp
)

set_target_properties(reflectionprobes PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(reflectionprobes PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Quick
    Qt::Quick3D
)

qt_add_qml_module(reflectionprobes
    URI Example
    VERSION 1.0
    QML_FILES
        main.qml
        SettingsPanel.qml
    RESOURCES
        res/OpenfootageNET_lowerAustria01-1024.hdr
        res/snowflake.png
    NO_RESOURCE_TARGET_PATH
)

install(TARGETS reflectionprobes
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
