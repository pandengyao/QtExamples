cmake_minimum_required(VERSION 3.16)
project(weatherinfo LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/positioning/weatherinfo")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Positioning Qml Quick)

qt_add_executable(weatherinfo
    appmodel.cpp appmodel.h
    providerbackend.cpp providerbackend.h
    openweathermapbackend.cpp openweathermapbackend.h
    weatherapibackend.cpp weatherapibackend.h
    main.cpp
)

set_target_properties(weatherinfo PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(weatherinfo PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::Positioning
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(weatherinfo
    URI WeatherInfo
    VERSION 1.0
    QML_FILES
        components/BigForecastIcon.qml
        components/ForecastIcon.qml
        components/WeatherIcon.qml
        weatherinfo.qml
    RESOURCES
        icons/weather-few-clouds.png
        icons/weather-fog.png
        icons/weather-haze.png
        icons/weather-icy.png
        icons/weather-overcast.png
        icons/weather-showers.png
        icons/weather-sleet.png
        icons/weather-snow.png
        icons/weather-storm.png
        icons/weather-sunny-very-few-clouds.png
        icons/weather-sunny.png
        icons/weather-thundershower.png
        icons/weather-showers-scattered.png
    NO_RESOURCE_TARGET_PATH
)

if(IOS)
    set_target_properties(weatherinfo PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/ios/Info.plist"
    )
endif()

install(TARGETS weatherinfo
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
