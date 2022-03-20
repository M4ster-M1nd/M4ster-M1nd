/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../alarm-clock-gui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "stopSoundEffect"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 28), // "pushButtonSetSysTime_clicked"
QT_MOC_LITERAL(4, 57, 13), // "timer_timeout"
QT_MOC_LITERAL(5, 71, 19), // "hours_buttonPressed"
QT_MOC_LITERAL(6, 91, 5), // "value"
QT_MOC_LITERAL(7, 97, 21), // "minutes_buttonPressed"
QT_MOC_LITERAL(8, 119, 21), // "seconds_buttonPressed"
QT_MOC_LITERAL(9, 141, 26), // "radioButtonSetTime_toggled"
QT_MOC_LITERAL(10, 168, 7), // "checked"
QT_MOC_LITERAL(11, 176, 27), // "radioButtonSetAlarm_toggled"
QT_MOC_LITERAL(12, 204, 33), // "checkBoxAlarmEnabled_stateCha..."
QT_MOC_LITERAL(13, 238, 5), // "state"
QT_MOC_LITERAL(14, 244, 26) // "soundEffect_playingChanged"

    },
    "MainWindow\0stopSoundEffect\0\0"
    "pushButtonSetSysTime_clicked\0timer_timeout\0"
    "hours_buttonPressed\0value\0"
    "minutes_buttonPressed\0seconds_buttonPressed\0"
    "radioButtonSetTime_toggled\0checked\0"
    "radioButtonSetAlarm_toggled\0"
    "checkBoxAlarmEnabled_stateChanged\0"
    "state\0soundEffect_playingChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stopSoundEffect(); break;
        case 1: _t->pushButtonSetSysTime_clicked(); break;
        case 2: _t->timer_timeout(); break;
        case 3: _t->hours_buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->minutes_buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->seconds_buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->radioButtonSetTime_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->radioButtonSetAlarm_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->checkBoxAlarmEnabled_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->soundEffect_playingChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
