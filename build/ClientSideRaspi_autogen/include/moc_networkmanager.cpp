/****************************************************************************
** Meta object code from reading C++ file 'networkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/networkmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkManager_t {
    QByteArrayData data[34];
    char stringdata0[490];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkManager_t qt_meta_stringdata_NetworkManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NetworkManager"
QT_MOC_LITERAL(1, 15, 23), // "connectionStatusChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 9), // "connected"
QT_MOC_LITERAL(4, 50, 20), // "serverAddressChanged"
QT_MOC_LITERAL(5, 71, 7), // "address"
QT_MOC_LITERAL(6, 79, 17), // "serverPortChanged"
QT_MOC_LITERAL(7, 97, 4), // "port"
QT_MOC_LITERAL(8, 102, 15), // "messageReceived"
QT_MOC_LITERAL(9, 118, 7), // "message"
QT_MOC_LITERAL(10, 126, 13), // "errorOccurred"
QT_MOC_LITERAL(11, 140, 12), // "errorMessage"
QT_MOC_LITERAL(12, 153, 24), // "discoveringStatusChanged"
QT_MOC_LITERAL(13, 178, 11), // "discovering"
QT_MOC_LITERAL(14, 190, 16), // "serverDiscovered"
QT_MOC_LITERAL(15, 207, 15), // "connectToServer"
QT_MOC_LITERAL(16, 223, 20), // "disconnectFromServer"
QT_MOC_LITERAL(17, 244, 11), // "sendCommand"
QT_MOC_LITERAL(18, 256, 9), // "commandId"
QT_MOC_LITERAL(19, 266, 10), // "parameters"
QT_MOC_LITERAL(20, 277, 14), // "sendRawCommand"
QT_MOC_LITERAL(21, 292, 7), // "command"
QT_MOC_LITERAL(22, 300, 14), // "discoverServer"
QT_MOC_LITERAL(23, 315, 13), // "stopDiscovery"
QT_MOC_LITERAL(24, 329, 11), // "onConnected"
QT_MOC_LITERAL(25, 341, 14), // "onDisconnected"
QT_MOC_LITERAL(26, 356, 7), // "onError"
QT_MOC_LITERAL(27, 364, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(28, 393, 11), // "socketError"
QT_MOC_LITERAL(29, 405, 14), // "onDataReceived"
QT_MOC_LITERAL(30, 420, 23), // "processPendingDatagrams"
QT_MOC_LITERAL(31, 444, 20), // "sendDiscoveryRequest"
QT_MOC_LITERAL(32, 465, 13), // "serverAddress"
QT_MOC_LITERAL(33, 479, 10) // "serverPort"

    },
    "NetworkManager\0connectionStatusChanged\0"
    "\0connected\0serverAddressChanged\0address\0"
    "serverPortChanged\0port\0messageReceived\0"
    "message\0errorOccurred\0errorMessage\0"
    "discoveringStatusChanged\0discovering\0"
    "serverDiscovered\0connectToServer\0"
    "disconnectFromServer\0sendCommand\0"
    "commandId\0parameters\0sendRawCommand\0"
    "command\0discoverServer\0stopDiscovery\0"
    "onConnected\0onDisconnected\0onError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "onDataReceived\0processPendingDatagrams\0"
    "sendDiscoveryRequest\0serverAddress\0"
    "serverPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       4,  160, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,
       6,    1,  120,    2, 0x06 /* Public */,
       8,    1,  123,    2, 0x06 /* Public */,
      10,    1,  126,    2, 0x06 /* Public */,
      12,    1,  129,    2, 0x06 /* Public */,
      14,    2,  132,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  137,    2, 0x0a /* Public */,
      16,    0,  138,    2, 0x0a /* Public */,
      17,    2,  139,    2, 0x0a /* Public */,
      17,    1,  144,    2, 0x2a /* Public | MethodCloned */,
      20,    1,  147,    2, 0x0a /* Public */,
      22,    0,  150,    2, 0x0a /* Public */,
      23,    0,  151,    2, 0x0a /* Public */,
      24,    0,  152,    2, 0x08 /* Private */,
      25,    0,  153,    2, 0x08 /* Private */,
      26,    1,  154,    2, 0x08 /* Private */,
      29,    0,  157,    2, 0x08 /* Private */,
      30,    0,  158,    2, 0x08 /* Private */,
      31,    0,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,   18,   19,
    QMetaType::Bool, QMetaType::QString,   18,
    QMetaType::Bool, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495001,
      32, QMetaType::QString, 0x00495103,
      33, QMetaType::Int, 0x00495103,
      13, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       5,

       0        // eod
};

void NetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetworkManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->serverAddressChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->serverPortChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->discoveringStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->serverDiscovered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->connectToServer(); break;
        case 8: _t->disconnectFromServer(); break;
        case 9: { bool _r = _t->sendCommand((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->sendCommand((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->sendRawCommand((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->discoverServer(); break;
        case 13: _t->stopDiscovery(); break;
        case 14: _t->onConnected(); break;
        case 15: _t->onDisconnected(); break;
        case 16: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 17: _t->onDataReceived(); break;
        case 18: _t->processPendingDatagrams(); break;
        case 19: _t->sendDiscoveryRequest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetworkManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::connectionStatusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::serverAddressChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::serverPortChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::messageReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::errorOccurred)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::discoveringStatusChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::serverDiscovered)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<NetworkManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isConnected(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->serverAddress(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->serverPort(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isDiscovering(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<NetworkManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setServerAddress(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setServerPort(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject NetworkManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NetworkManager.data,
    qt_meta_data_NetworkManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NetworkManager::connectionStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkManager::serverAddressChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkManager::serverPortChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkManager::messageReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetworkManager::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NetworkManager::discoveringStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NetworkManager::serverDiscovered(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
