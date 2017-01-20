/****************************************************************************
** Meta object code from reading C++ file 'temperaturescreen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "temperaturescreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'temperaturescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_temperaturescreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   31,   31,   31, 0x08,
      32,   31,   31,   31, 0x08,
      45,   70,   31,   31, 0x08,
      72,   31,   31,   31, 0x08,
      96,   31,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_temperaturescreen[] = {
    "temperaturescreen\0resettimer()\0\0"
    "tempSensor()\0LcdNumber_2_Display(int)\0"
    "i\0on_pushButton_clicked()\0LogOut()\0"
};

void temperaturescreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        temperaturescreen *_t = static_cast<temperaturescreen *>(_o);
        switch (_id) {
        case 0: _t->resettimer(); break;
        case 1: _t->tempSensor(); break;
        case 2: _t->LcdNumber_2_Display((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->LogOut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData temperaturescreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject temperaturescreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_temperaturescreen,
      qt_meta_data_temperaturescreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &temperaturescreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *temperaturescreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *temperaturescreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_temperaturescreen))
        return static_cast<void*>(const_cast< temperaturescreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int temperaturescreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
