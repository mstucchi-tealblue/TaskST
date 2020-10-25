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
    QByteArrayData data[19];
    char stringdata0[433];
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
QT_MOC_LITERAL(3, 34, 23), // "windowVisibilityChanged"
QT_MOC_LITERAL(4, 58, 28), // "internalProcessWindowChanged"
QT_MOC_LITERAL(5, 87, 34), // "internalProcessWindowHeightCh..."
QT_MOC_LITERAL(6, 122, 33), // "internalProcessWindowWidthCha..."
QT_MOC_LITERAL(7, 156, 29), // "internalProcessWindowXChanged"
QT_MOC_LITERAL(8, 186, 29), // "internalProcessWindowYChanged"
QT_MOC_LITERAL(9, 216, 21), // "readContentFromServer"
QT_MOC_LITERAL(10, 238, 21), // "setLocalGeometry_slot"
QT_MOC_LITERAL(11, 260, 14), // "windowGeometry"
QT_MOC_LITERAL(12, 275, 17), // "receivedFromSever"
QT_MOC_LITERAL(13, 293, 16), // "windowVisibility"
QT_MOC_LITERAL(14, 310, 21), // "internalProcessWindow"
QT_MOC_LITERAL(15, 332, 27), // "internalProcessWindowHeight"
QT_MOC_LITERAL(16, 360, 26), // "internalProcessWindowWidth"
QT_MOC_LITERAL(17, 387, 22), // "internalProcessWindowX"
QT_MOC_LITERAL(18, 410, 22) // "internalProcessWindowY"

    },
    "client\0receivedFromServerChanged\0\0"
    "windowVisibilityChanged\0"
    "internalProcessWindowChanged\0"
    "internalProcessWindowHeightChanged\0"
    "internalProcessWindowWidthChanged\0"
    "internalProcessWindowXChanged\0"
    "internalProcessWindowYChanged\0"
    "readContentFromServer\0setLocalGeometry_slot\0"
    "windowGeometry\0receivedFromSever\0"
    "windowVisibility\0internalProcessWindow\0"
    "internalProcessWindowHeight\0"
    "internalProcessWindowWidth\0"
    "internalProcessWindowX\0internalProcessWindowY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       7,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect,   11,

 // properties: name, type, flags
      12, QMetaType::QByteArray, 0x00495003,
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::QRect, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::Int, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      18, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedFromServerChanged(); break;
        case 1: _t->windowVisibilityChanged(); break;
        case 2: _t->internalProcessWindowChanged(); break;
        case 3: _t->internalProcessWindowHeightChanged(); break;
        case 4: _t->internalProcessWindowWidthChanged(); break;
        case 5: _t->internalProcessWindowXChanged(); break;
        case 6: _t->internalProcessWindowYChanged(); break;
        case 7: _t->readContentFromServer(); break;
        case 8: _t->setLocalGeometry_slot((*reinterpret_cast< QRect(*)>(_a[1]))); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::windowVisibilityChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::internalProcessWindowChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::internalProcessWindowHeightChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::internalProcessWindowWidthChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::internalProcessWindowXChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::internalProcessWindowYChanged)) {
                *result = 6;
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
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->getReceivedFromServer(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getWindowVisibility(); break;
        case 2: *reinterpret_cast< QRect*>(_v) = _t->getInternalProcessWindow(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getInternalProcessWindowHeight(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getInternalProcessWindowWidth(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getInternalProcessWindowX(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getInternalProcessWindowY(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setReceivedFromServer(*reinterpret_cast< QByteArray*>(_v)); break;
        case 1: _t->setWindowVisibility(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setInternalProcessWindow(*reinterpret_cast< QRect*>(_v)); break;
        case 3: _t->setInternalProcessWindowHeight(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setInternalProcessWindowWidth(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setInternalProcessWindowX(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setInternalProcessWindowY(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
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
void client::windowVisibilityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void client::internalProcessWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void client::internalProcessWindowHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void client::internalProcessWindowWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void client::internalProcessWindowXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void client::internalProcessWindowYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
