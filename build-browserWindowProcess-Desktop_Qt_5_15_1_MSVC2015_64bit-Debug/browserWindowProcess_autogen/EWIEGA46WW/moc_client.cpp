/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../browserWindowProcess/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_t {
    QByteArrayData data[12];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "client"
QT_MOC_LITERAL(1, 7, 25), // "receivedFromServerChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "windowHeightChanged"
QT_MOC_LITERAL(4, 54, 18), // "windowWidthChanged"
QT_MOC_LITERAL(5, 73, 11), // "readWelcome"
QT_MOC_LITERAL(6, 85, 17), // "receivedFromSever"
QT_MOC_LITERAL(7, 103, 12), // "windowHeight"
QT_MOC_LITERAL(8, 116, 11), // "windowWidth"
QT_MOC_LITERAL(9, 128, 13), // "initialHeight"
QT_MOC_LITERAL(10, 142, 12), // "initialWidth"
QT_MOC_LITERAL(11, 155, 19) // "wrapperWindowHeight"

    },
    "client\0receivedFromServerChanged\0\0"
    "windowHeightChanged\0windowWidthChanged\0"
    "readWelcome\0receivedFromSever\0"
    "windowHeight\0windowWidth\0initialHeight\0"
    "initialWidth\0wrapperWindowHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       6,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495003,
       7, QMetaType::Int, 0x00495103,
       8, QMetaType::Int, 0x00495103,
       9, QMetaType::Int, 0x00095103,
      10, QMetaType::Int, 0x00095103,
      11, QMetaType::Int, 0x00095103,

 // properties: notify_signal_id
       0,
       1,
       2,
       0,
       0,
       0,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedFromServerChanged(); break;
        case 1: _t->windowHeightChanged(); break;
        case 2: _t->windowWidthChanged(); break;
        case 3: _t->readWelcome(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::receivedFromServerChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::windowHeightChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::windowWidthChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getReceivedFromServer(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getWindowHeight(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getWindowWidth(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getInitialHeight(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getInitialWidth(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getWrapperWindowHeight(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setReceivedFromServer(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setWindowHeight(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setWindowWidth(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setInitialHeight(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setInitialWidth(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setWrapperWindowHeight(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_client.data,
    qt_meta_data_client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void client::receivedFromServerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void client::windowHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void client::windowWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
