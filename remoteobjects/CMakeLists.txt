qt_internal_add_example(remoteobjects_server)
qt_internal_add_example(cppclient)
add_subdirectory(simpleswitch)
add_subdirectory(websockets)
if(TARGET Qt::Widgets)
    qt_internal_add_example(modelviewclient)
    qt_internal_add_example(modelviewserver)
endif()
if(QT_FEATURE_ssl)
    add_subdirectory(ssl)
endif()
if(TARGET Qt::Quick)
    qt_internal_add_example(plugins)
    qt_internal_add_example(clientapp)
endif()
if(TARGET Qt::Quick AND UNIX AND NOT ANDROID)
    qt_internal_add_example(qmlmodelviewclient)
endif()
