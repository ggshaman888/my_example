/****************************************************************************
** Meta object code from reading C++ file 'setbaikal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../terminal/setbaikal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setbaikal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetBaikal_t {
    QByteArrayData data[9];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetBaikal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetBaikal_t qt_meta_stringdata_SetBaikal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SetBaikal"
QT_MOC_LITERAL(1, 10, 8), // "toDevice"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "data"
QT_MOC_LITERAL(4, 25, 6), // "isSend"
QT_MOC_LITERAL(5, 32, 11), // "resetSerial"
QT_MOC_LITERAL(6, 44, 4), // "test"
QT_MOC_LITERAL(7, 49, 5), // "timer"
QT_MOC_LITERAL(8, 55, 12) // "sendToDevice"

    },
    "SetBaikal\0toDevice\0\0data\0isSend\0"
    "resetSerial\0test\0timer\0sendToDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetBaikal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SetBaikal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SetBaikal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toDevice((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->isSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->resetSerial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->test(); break;
        case 4: _t->timer(); break;
        case 5: _t->sendToDevice(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SetBaikal::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetBaikal::toDevice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SetBaikal::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetBaikal::isSend)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SetBaikal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetBaikal::resetSerial)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SetBaikal::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetBaikal::test)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SetBaikal::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SetBaikal.data,
    qt_meta_data_SetBaikal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SetBaikal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetBaikal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetBaikal.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SetBaikal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SetBaikal::toDevice(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetBaikal::isSend(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SetBaikal::resetSerial(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SetBaikal::test()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
