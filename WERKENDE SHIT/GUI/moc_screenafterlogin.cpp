/****************************************************************************
** Meta object code from reading C++ file 'screenafterlogin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "screenafterlogin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenafterlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScreenAfterLogin[] = {

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
      17,   28,   28,   28, 0x08,
      29,   28,   28,   28, 0x08,
      53,   28,   28,   28, 0x08,
      74,   28,   28,   28, 0x08,
      96,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScreenAfterLogin[] = {
    "ScreenAfterLogin\0showTime()\0\0"
    "on_LogSeizure_clicked()\0on_setTemp_clicked()\0"
    "on_openDeur_clicked()\0LogOut()\0"
};

void ScreenAfterLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScreenAfterLogin *_t = static_cast<ScreenAfterLogin *>(_o);
        switch (_id) {
        case 0: _t->showTime(); break;
        case 1: _t->on_LogSeizure_clicked(); break;
        case 2: _t->on_setTemp_clicked(); break;
        case 3: _t->on_openDeur_clicked(); break;
        case 4: _t->LogOut(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ScreenAfterLogin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScreenAfterLogin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScreenAfterLogin,
      qt_meta_data_ScreenAfterLogin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScreenAfterLogin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScreenAfterLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScreenAfterLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenAfterLogin))
        return static_cast<void*>(const_cast< ScreenAfterLogin*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScreenAfterLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
