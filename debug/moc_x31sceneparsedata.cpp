/****************************************************************************
** Meta object code from reading C++ file 'x31sceneparsedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../x31sceneparsedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'x31sceneparsedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_X31SceneCpRunnable_t {
    QByteArrayData data[7];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31SceneCpRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31SceneCpRunnable_t qt_meta_stringdata_X31SceneCpRunnable = {
    {
QT_MOC_LITERAL(0, 0, 18), // "X31SceneCpRunnable"
QT_MOC_LITERAL(1, 19, 11), // "send_cpdata"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "startTime"
QT_MOC_LITERAL(4, 42, 7), // "endTime"
QT_MOC_LITERAL(5, 50, 36), // "QMultiMap<QString,QVector<dou..."
QT_MOC_LITERAL(6, 87, 6) // "values"

    },
    "X31SceneCpRunnable\0send_cpdata\0\0"
    "startTime\0endTime\0"
    "QMultiMap<QString,QVector<double> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31SceneCpRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31SceneCpRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31SceneCpRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_cpdata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31SceneCpRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31SceneCpRunnable::send_cpdata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31SceneCpRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneDoubleRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31SceneCpRunnable.data,
    qt_meta_data_X31SceneCpRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31SceneCpRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31SceneCpRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31SceneCpRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneDoubleRunnable::qt_metacast(_clname);
}

int X31SceneCpRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneDoubleRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31SceneCpRunnable::send_cpdata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_X31SceneLofarRunnable_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31SceneLofarRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31SceneLofarRunnable_t qt_meta_stringdata_X31SceneLofarRunnable = {
    {
QT_MOC_LITERAL(0, 0, 21), // "X31SceneLofarRunnable"
QT_MOC_LITERAL(1, 22, 14), // "send_lofardata"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "startTime"
QT_MOC_LITERAL(4, 48, 7), // "endTime"
QT_MOC_LITERAL(5, 56, 36), // "QMultiMap<QString,QVector<dou..."
QT_MOC_LITERAL(6, 93, 6) // "values"

    },
    "X31SceneLofarRunnable\0send_lofardata\0"
    "\0startTime\0endTime\0"
    "QMultiMap<QString,QVector<double> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31SceneLofarRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31SceneLofarRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31SceneLofarRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_lofardata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31SceneLofarRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31SceneLofarRunnable::send_lofardata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31SceneLofarRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneDoubleRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31SceneLofarRunnable.data,
    qt_meta_data_X31SceneLofarRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31SceneLofarRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31SceneLofarRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31SceneLofarRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneDoubleRunnable::qt_metacast(_clname);
}

int X31SceneLofarRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneDoubleRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31SceneLofarRunnable::send_lofardata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_X31SceneDemonRunnable_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31SceneDemonRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31SceneDemonRunnable_t qt_meta_stringdata_X31SceneDemonRunnable = {
    {
QT_MOC_LITERAL(0, 0, 21), // "X31SceneDemonRunnable"
QT_MOC_LITERAL(1, 22, 14), // "send_demondata"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "startTime"
QT_MOC_LITERAL(4, 48, 7), // "endTime"
QT_MOC_LITERAL(5, 56, 36), // "QMultiMap<QString,QVector<dou..."
QT_MOC_LITERAL(6, 93, 6) // "values"

    },
    "X31SceneDemonRunnable\0send_demondata\0"
    "\0startTime\0endTime\0"
    "QMultiMap<QString,QVector<double> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31SceneDemonRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31SceneDemonRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31SceneDemonRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_demondata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31SceneDemonRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31SceneDemonRunnable::send_demondata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31SceneDemonRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneDoubleRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31SceneDemonRunnable.data,
    qt_meta_data_X31SceneDemonRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31SceneDemonRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31SceneDemonRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31SceneDemonRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneDoubleRunnable::qt_metacast(_clname);
}

int X31SceneDemonRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneDoubleRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31SceneDemonRunnable::send_demondata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_X31ScenePassiveRunnable_t {
    QByteArrayData data[7];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31ScenePassiveRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31ScenePassiveRunnable_t qt_meta_stringdata_X31ScenePassiveRunnable = {
    {
QT_MOC_LITERAL(0, 0, 23), // "X31ScenePassiveRunnable"
QT_MOC_LITERAL(1, 24, 16), // "send_passivedata"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 9), // "startTime"
QT_MOC_LITERAL(4, 52, 7), // "endTime"
QT_MOC_LITERAL(5, 60, 36), // "QMultiMap<QString,QVector<dou..."
QT_MOC_LITERAL(6, 97, 6) // "values"

    },
    "X31ScenePassiveRunnable\0send_passivedata\0"
    "\0startTime\0endTime\0"
    "QMultiMap<QString,QVector<double> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31ScenePassiveRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31ScenePassiveRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31ScenePassiveRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_passivedata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31ScenePassiveRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31ScenePassiveRunnable::send_passivedata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31ScenePassiveRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneDoubleRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31ScenePassiveRunnable.data,
    qt_meta_data_X31ScenePassiveRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31ScenePassiveRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31ScenePassiveRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31ScenePassiveRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneDoubleRunnable::qt_metacast(_clname);
}

int X31ScenePassiveRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneDoubleRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31ScenePassiveRunnable::send_passivedata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_X31SceneMultiLofarRunnable_t {
    QByteArrayData data[7];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31SceneMultiLofarRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31SceneMultiLofarRunnable_t qt_meta_stringdata_X31SceneMultiLofarRunnable = {
    {
QT_MOC_LITERAL(0, 0, 26), // "X31SceneMultiLofarRunnable"
QT_MOC_LITERAL(1, 27, 19), // "send_multilofardata"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 9), // "startTime"
QT_MOC_LITERAL(4, 58, 7), // "endTime"
QT_MOC_LITERAL(5, 66, 36), // "QMultiMap<QString,QVector<dou..."
QT_MOC_LITERAL(6, 103, 6) // "values"

    },
    "X31SceneMultiLofarRunnable\0"
    "send_multilofardata\0\0startTime\0endTime\0"
    "QMultiMap<QString,QVector<double> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31SceneMultiLofarRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31SceneMultiLofarRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31SceneMultiLofarRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_multilofardata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31SceneMultiLofarRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31SceneMultiLofarRunnable::send_multilofardata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31SceneMultiLofarRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneDoubleRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31SceneMultiLofarRunnable.data,
    qt_meta_data_X31SceneMultiLofarRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31SceneMultiLofarRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31SceneMultiLofarRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31SceneMultiLofarRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneDoubleRunnable::qt_metacast(_clname);
}

int X31SceneMultiLofarRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneDoubleRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31SceneMultiLofarRunnable::send_multilofardata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_X31SceneHfmTrackRunnable_t {
    QByteArrayData data[7];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31SceneHfmTrackRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31SceneHfmTrackRunnable_t qt_meta_stringdata_X31SceneHfmTrackRunnable = {
    {
QT_MOC_LITERAL(0, 0, 24), // "X31SceneHfmTrackRunnable"
QT_MOC_LITERAL(1, 25, 17), // "send_hfmtrackdata"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 9), // "startTime"
QT_MOC_LITERAL(4, 54, 7), // "endTime"
QT_MOC_LITERAL(5, 62, 36), // "QMultiMap<QString,QVector<qui..."
QT_MOC_LITERAL(6, 99, 6) // "values"

    },
    "X31SceneHfmTrackRunnable\0send_hfmtrackdata\0"
    "\0startTime\0endTime\0"
    "QMultiMap<QString,QVector<quint8> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31SceneHfmTrackRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31SceneHfmTrackRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31SceneHfmTrackRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_hfmtrackdata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<quint8> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31SceneHfmTrackRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<quint8>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31SceneHfmTrackRunnable::send_hfmtrackdata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31SceneHfmTrackRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneUnitRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31SceneHfmTrackRunnable.data,
    qt_meta_data_X31SceneHfmTrackRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31SceneHfmTrackRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31SceneHfmTrackRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31SceneHfmTrackRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneUnitRunnable::qt_metacast(_clname);
}

int X31SceneHfmTrackRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneUnitRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31SceneHfmTrackRunnable::send_hfmtrackdata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<quint8>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_X31ScenePassiveTrackRunnable_t {
    QByteArrayData data[7];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31ScenePassiveTrackRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31ScenePassiveTrackRunnable_t qt_meta_stringdata_X31ScenePassiveTrackRunnable = {
    {
QT_MOC_LITERAL(0, 0, 28), // "X31ScenePassiveTrackRunnable"
QT_MOC_LITERAL(1, 29, 21), // "send_passivetrackdata"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 9), // "startTime"
QT_MOC_LITERAL(4, 62, 7), // "endTime"
QT_MOC_LITERAL(5, 70, 36), // "QMultiMap<QString,QVector<qui..."
QT_MOC_LITERAL(6, 107, 6) // "values"

    },
    "X31ScenePassiveTrackRunnable\0"
    "send_passivetrackdata\0\0startTime\0"
    "endTime\0QMultiMap<QString,QVector<quint8> >&\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31ScenePassiveTrackRunnable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 5,    3,    4,    6,

       0        // eod
};

void X31ScenePassiveTrackRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31ScenePassiveTrackRunnable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_passivetrackdata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<quint8> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31ScenePassiveTrackRunnable::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<quint8>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31ScenePassiveTrackRunnable::send_passivetrackdata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31ScenePassiveTrackRunnable::staticMetaObject = { {
    QMetaObject::SuperData::link<X31SceneUnitRunnable::staticMetaObject>(),
    qt_meta_stringdata_X31ScenePassiveTrackRunnable.data,
    qt_meta_data_X31ScenePassiveTrackRunnable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31ScenePassiveTrackRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31ScenePassiveTrackRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31ScenePassiveTrackRunnable.stringdata0))
        return static_cast<void*>(this);
    return X31SceneUnitRunnable::qt_metacast(_clname);
}

int X31ScenePassiveTrackRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = X31SceneUnitRunnable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void X31ScenePassiveTrackRunnable::send_passivetrackdata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<quint8>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
