/****************************************************************************
** Meta object code from reading C++ file 'subscore.h'
**
** Created: Wed Apr 30 01:27:49 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "subscore.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subscore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_subscore[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      34,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_subscore[] = {
    "subscore\0\0on_sendButton_clicked()\0"
    "startTransfer()\0"
};

const QMetaObject subscore::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_subscore,
      qt_meta_data_subscore, 0 }
};

const QMetaObject *subscore::metaObject() const
{
    return &staticMetaObject;
}

void *subscore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_subscore))
        return static_cast<void*>(const_cast< subscore*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int subscore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_sendButton_clicked(); break;
        case 1: startTransfer(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
