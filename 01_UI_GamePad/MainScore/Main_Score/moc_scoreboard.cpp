/****************************************************************************
** Meta object code from reading C++ file 'scoreboard.h'
**
** Created: Wed Apr 30 01:19:52 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scoreboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scoreboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_scoreboard[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      59,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      85,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     110,   11,   11,   11, 0x0a,
     137,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_scoreboard[] = {
    "scoreboard\0\0on_bt_StartGame_clicked()\0"
    "on_bt_Mute_clicked()\0clockTimer()\0"
    "clockStart()\0clockStop()\0clockReset()\0"
    "on_bt_Score_Left_pressed()\0"
    "on_bt_Score_Right_pressed()\0"
};

const QMetaObject scoreboard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_scoreboard,
      qt_meta_data_scoreboard, 0 }
};

const QMetaObject *scoreboard::metaObject() const
{
    return &staticMetaObject;
}

void *scoreboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_scoreboard))
        return static_cast<void*>(const_cast< scoreboard*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int scoreboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_bt_StartGame_clicked(); break;
        case 1: on_bt_Mute_clicked(); break;
        case 2: clockTimer(); break;
        case 3: clockStart(); break;
        case 4: clockStop(); break;
        case 5: clockReset(); break;
        case 6: on_bt_Score_Left_pressed(); break;
        case 7: on_bt_Score_Right_pressed(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
