cmake_minimum_required(VERSION 3.16)
project(contactlist LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/quickcontrols2/contactlist")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick)

qt_add_executable(contactlistexample WIN32 MACOSX_BUNDLE
    contactmodel.cpp contactmodel.h
    main.cpp
)

qt_add_qml_module(contactlistexample
    URI contactlist
    VERSION 1.0
    NO_RESOURCE_TARGET_PATH
    QML_FILES
        "ContactDelegate.ui.qml"
        "ContactDialog.qml"
        "ContactForm.ui.qml"
        "ContactView.ui.qml"
        "SectionDelegate.ui.qml"
        "contactlist.qml"
        "designer/Backend/ContactModel.qml"
)

target_link_libraries(contactlistexample PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Quick
)

install(TARGETS contactlistexample
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
