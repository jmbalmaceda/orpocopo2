/****************************************************************************
** Meta object code from reading C++ file 'fnuevoentrenamiento.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fnuevoentrenamiento.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fnuevoentrenamiento.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FnuevoEntrenamiento_t {
    QByteArrayData data[11];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FnuevoEntrenamiento_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FnuevoEntrenamiento_t qt_meta_stringdata_FnuevoEntrenamiento = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FnuevoEntrenamiento"
QT_MOC_LITERAL(1, 20, 19), // "on_selVideo_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 21), // "on_siguiente1_clicked"
QT_MOC_LITERAL(4, 63, 10), // "updateText"
QT_MOC_LITERAL(5, 74, 19), // "on_entrenar_clicked"
QT_MOC_LITERAL(6, 94, 21), // "on_iAgregarBg_clicked"
QT_MOC_LITERAL(7, 116, 2), // "np"
QT_MOC_LITERAL(8, 119, 21), // "on_siguiente2_clicked"
QT_MOC_LITERAL(9, 141, 2), // "cs"
QT_MOC_LITERAL(10, 144, 16) // "on_salir_clicked"

    },
    "FnuevoEntrenamiento\0on_selVideo_clicked\0"
    "\0on_siguiente1_clicked\0updateText\0"
    "on_entrenar_clicked\0on_iAgregarBg_clicked\0"
    "np\0on_siguiente2_clicked\0cs\0"
    "on_salir_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FnuevoEntrenamiento[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void FnuevoEntrenamiento::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FnuevoEntrenamiento *_t = static_cast<FnuevoEntrenamiento *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_selVideo_clicked(); break;
        case 1: _t->on_siguiente1_clicked(); break;
        case 2: _t->updateText(); break;
        case 3: _t->on_entrenar_clicked(); break;
        case 4: _t->on_iAgregarBg_clicked(); break;
        case 5: _t->np(); break;
        case 6: _t->on_siguiente2_clicked(); break;
        case 7: _t->cs(); break;
        case 8: _t->on_salir_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FnuevoEntrenamiento::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FnuevoEntrenamiento.data,
      qt_meta_data_FnuevoEntrenamiento,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FnuevoEntrenamiento::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FnuevoEntrenamiento::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FnuevoEntrenamiento.stringdata0))
        return static_cast<void*>(const_cast< FnuevoEntrenamiento*>(this));
    return QDialog::qt_metacast(_clname);
}

int FnuevoEntrenamiento::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
