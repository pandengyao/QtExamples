cmake_minimum_required(VERSION 3.16)
project(stickman LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/widgets/animation/stickman")

find_package(Qt6 REQUIRED COMPONENTS Core Gui StateMachine Widgets)

qt_add_executable(stickman
    animation.cpp animation.h
    graphicsview.cpp graphicsview.h
    lifecycle.cpp lifecycle.h
    main.cpp
    node.cpp node.h
    rectbutton.cpp rectbutton.h
    stickman.cpp stickman.h
)

set_target_properties(stickman PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(stickman PUBLIC
    Qt::Core
    Qt::Gui
    Qt::StateMachine
    Qt::Widgets
)

# Resources:
set(stickman_resource_files
    "animations/chilling.bin"
    "animations/dancing.bin"
    "animations/dead.bin"
    "animations/jumping.bin"
)

qt6_add_resources(stickman "stickman"
    PREFIX
        "/"
    FILES
        ${stickman_resource_files}
)

install(TARGETS stickman
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
