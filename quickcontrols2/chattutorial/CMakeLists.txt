qt_internal_add_example(chapter1)
qt_internal_add_example(chapter2)
qt_internal_add_example(chapter3)
if (TARGET Qt::Sql)
    qt_internal_add_example(chapter4)
    qt_internal_add_example(chapter5)
endif()
