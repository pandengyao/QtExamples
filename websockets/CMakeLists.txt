qt_internal_add_example(echoclient)
qt_internal_add_example(echoserver)
qt_internal_add_example(simplechat)
if(TARGET Qt::Quick)
    qt_internal_add_example(qmlwebsocketclient)
    qt_internal_add_example(qmlwebsocketserver)
endif()
if(QT_FEATURE_ssl)
    qt_internal_add_example(sslechoserver)
    qt_internal_add_example(sslechoclient)
endif()
