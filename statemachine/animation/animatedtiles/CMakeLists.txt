cmake_minimum_required(VERSION 3.16)
project(animatedtiles LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/widgets/animation/animatedtiles")

find_package(Qt6 REQUIRED COMPONENTS Core Gui StateMachine Widgets)

qt_add_executable(animatedtiles
    main.cpp
)

set_target_properties(animatedtiles PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(animatedtiles PUBLIC
    Qt::Core
    Qt::Gui
    Qt::StateMachine
    Qt::Widgets
)

# Resources:
set(animatedtiles_resource_files
    "images/Time-For-Lunch-2.jpg"
    "images/centered.png"
    "images/ellipse.png"
    "images/figure8.png"
    "images/kinetic.png"
    "images/random.png"
    "images/tile.png"
)

qt6_add_resources(animatedtiles "animatedtiles"
    PREFIX
        "/"
    FILES
        ${animatedtiles_resource_files}
)

install(TARGETS animatedtiles
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
