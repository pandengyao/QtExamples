/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../undo/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[14];
    char stringdata5[12];
    char stringdata6[9];
    char stringdata7[12];
    char stringdata8[14];
    char stringdata9[11];
    char stringdata10[9];
    char stringdata11[6];
    char stringdata12[8];
    char stringdata13[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "openDocument"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "saveDocument"
        QT_MOC_LITERAL(38, 13),  // "closeDocument"
        QT_MOC_LITERAL(52, 11),  // "newDocument"
        QT_MOC_LITERAL(64, 8),  // "addShape"
        QT_MOC_LITERAL(73, 11),  // "removeShape"
        QT_MOC_LITERAL(85, 13),  // "setShapeColor"
        QT_MOC_LITERAL(99, 10),  // "addSnowman"
        QT_MOC_LITERAL(110, 8),  // "addRobot"
        QT_MOC_LITERAL(119, 5),  // "about"
        QT_MOC_LITERAL(125, 7),  // "aboutQt"
        QT_MOC_LITERAL(133, 13)   // "updateActions"
    },
    "MainWindow",
    "openDocument",
    "",
    "saveDocument",
    "closeDocument",
    "newDocument",
    "addShape",
    "removeShape",
    "setShapeColor",
    "addSnowman",
    "addRobot",
    "about",
    "aboutQt",
    "updateActions"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x0a,    1 /* Public */,
       3,    0,   87,    2, 0x0a,    2 /* Public */,
       4,    0,   88,    2, 0x0a,    3 /* Public */,
       5,    0,   89,    2, 0x0a,    4 /* Public */,
       6,    0,   90,    2, 0x0a,    5 /* Public */,
       7,    0,   91,    2, 0x0a,    6 /* Public */,
       8,    0,   92,    2, 0x0a,    7 /* Public */,
       9,    0,   93,    2, 0x0a,    8 /* Public */,
      10,    0,   94,    2, 0x0a,    9 /* Public */,
      11,    0,   95,    2, 0x0a,   10 /* Public */,
      12,    0,   96,    2, 0x0a,   11 /* Public */,
      13,    0,   97,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'openDocument'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveDocument'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeDocument'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'newDocument'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addShape'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeShape'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setShapeColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addSnowman'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addRobot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'about'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aboutQt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateActions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openDocument(); break;
        case 1: _t->saveDocument(); break;
        case 2: _t->closeDocument(); break;
        case 3: _t->newDocument(); break;
        case 4: _t->addShape(); break;
        case 5: _t->removeShape(); break;
        case 6: _t->setShapeColor(); break;
        case 7: _t->addSnowman(); break;
        case 8: _t->addRobot(); break;
        case 9: _t->about(); break;
        case 10: _t->aboutQt(); break;
        case 11: _t->updateActions(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
