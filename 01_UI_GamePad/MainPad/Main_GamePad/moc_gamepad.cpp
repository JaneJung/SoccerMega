/****************************************************************************
** Meta object code from reading C++ file 'gamepad.h'
**
** Created: Tue Apr 29 10:15:11 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamepad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamepad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GamePad[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      33,    8,    8,    8, 0x08,
      58,    8,    8,    8, 0x08,
      79,    8,    8,    8, 0x08,
     105,    8,    8,    8, 0x08,
     136,    8,  132,    8, 0x08,
     156,    8,    8,    8, 0x08,
     177,    8,    8,    8, 0x08,
     196,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GamePad[] = {
    "GamePad\0\0on_bt_UP_LEFT_pressed()\0"
    "on_bt_UP_RIGHT_pressed()\0on_bt_DOWN_pressed()\0"
    "on_bt_DOWN_LEFT_pressed()\0"
    "on_bt_DOWN_RIGHT_pressed()\0int\0"
    "set_BT_Initialize()\0on_bt_STOP_pressed()\0"
    "on_bt_UP_pressed()\0on_pushButton_pressed()\0"
};

const QMetaObject GamePad::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GamePad,
      qt_meta_data_GamePad, 0 }
};

const QMetaObject *GamePad::metaObject() const
{
    return &staticMetaObject;
}

void *GamePad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GamePad))
        return static_cast<void*>(const_cast< GamePad*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GamePad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_bt_UP_LEFT_pressed(); break;
        case 1: on_bt_UP_RIGHT_pressed(); break;
        case 2: on_bt_DOWN_pressed(); break;
        case 3: on_bt_DOWN_LEFT_pressed(); break;
        case 4: on_bt_DOWN_RIGHT_pressed(); break;
        case 5: { int _r = set_BT_Initialize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: on_bt_STOP_pressed(); break;
        case 7: on_bt_UP_pressed(); break;
        case 8: on_pushButton_pressed(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
