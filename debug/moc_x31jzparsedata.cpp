/****************************************************************************
** Meta object code from reading C++ file 'x31jzparsedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../x31jzparsedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'x31jzparsedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_X31JzParseData_t {
    QByteArrayData data[17];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31JzParseData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31JzParseData_t qt_meta_stringdata_X31JzParseData = {
    {
QT_MOC_LITERAL(0, 0, 14), // "X31JzParseData"
QT_MOC_LITERAL(1, 15, 9), // "send_data"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 42, 9), // "xkMfmData"
QT_MOC_LITERAL(5, 52, 9), // "sxPwdData"
QT_MOC_LITERAL(6, 62, 13), // "sxMbLofarData"
QT_MOC_LITERAL(7, 76, 12), // "sxTLobarData"
QT_MOC_LITERAL(8, 89, 12), // "sxTDemonData"
QT_MOC_LITERAL(9, 102, 14), // "complete_parse"
QT_MOC_LITERAL(10, 117, 16), // "setRunningEnable"
QT_MOC_LITERAL(11, 134, 7), // "running"
QT_MOC_LITERAL(12, 142, 5), // "reset"
QT_MOC_LITERAL(13, 148, 13), // "setStartPoint"
QT_MOC_LITERAL(14, 162, 10), // "startPoint"
QT_MOC_LITERAL(15, 173, 9), // "setScaleX"
QT_MOC_LITERAL(16, 183, 6) // "scaleX"

    },
    "X31JzParseData\0send_data\0\0QVector<double>\0"
    "xkMfmData\0sxPwdData\0sxMbLofarData\0"
    "sxTLobarData\0sxTDemonData\0complete_parse\0"
    "setRunningEnable\0running\0reset\0"
    "setStartPoint\0startPoint\0setScaleX\0"
    "scaleX"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31JzParseData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   44,    2, 0x06 /* Public */,
       9,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   56,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,
      13,    1,   60,    2, 0x0a /* Public */,
      15,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void X31JzParseData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31JzParseData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_data((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4])),(*reinterpret_cast< QVector<double>(*)>(_a[5]))); break;
        case 1: _t->complete_parse(); break;
        case 2: _t->setRunningEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->reset(); break;
        case 4: _t->setStartPoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setScaleX((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (X31JzParseData::*)(QVector<double> , QVector<double> , QVector<double> , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzParseData::send_data)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (X31JzParseData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzParseData::complete_parse)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31JzParseData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_X31JzParseData.data,
    qt_meta_data_X31JzParseData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31JzParseData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31JzParseData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31JzParseData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int X31JzParseData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void X31JzParseData::send_data(QVector<double> _t1, QVector<double> _t2, QVector<double> _t3, QVector<double> _t4, QVector<double> _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void X31JzParseData::complete_parse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
