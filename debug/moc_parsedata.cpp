/****************************************************************************
** Meta object code from reading C++ file 'parsedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../parsedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parsedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParseData_t {
    QByteArrayData data[35];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParseData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParseData_t qt_meta_stringdata_ParseData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ParseData"
QT_MOC_LITERAL(1, 10, 12), // "parse_status"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "status"
QT_MOC_LITERAL(4, 31, 4), // "text"
QT_MOC_LITERAL(5, 36, 15), // "update_taskinfo"
QT_MOC_LITERAL(6, 52, 11), // "send_cpdata"
QT_MOC_LITERAL(7, 64, 9), // "startTime"
QT_MOC_LITERAL(8, 74, 7), // "endTime"
QT_MOC_LITERAL(9, 82, 36), // "QMultiMap<QString,QVector<dou..."
QT_MOC_LITERAL(10, 119, 6), // "values"
QT_MOC_LITERAL(11, 126, 11), // "send_eddata"
QT_MOC_LITERAL(12, 138, 15), // "send_noiseldata"
QT_MOC_LITERAL(13, 154, 15), // "send_noisesdata"
QT_MOC_LITERAL(14, 170, 12), // "send_fsddata"
QT_MOC_LITERAL(15, 183, 14), // "send_lofardata"
QT_MOC_LITERAL(16, 198, 14), // "send_demondata"
QT_MOC_LITERAL(17, 213, 13), // "send_echodata"
QT_MOC_LITERAL(18, 227, 36), // "QMultiMap<QString,QVector<qui..."
QT_MOC_LITERAL(19, 264, 11), // "send_nodata"
QT_MOC_LITERAL(20, 276, 5), // "parse"
QT_MOC_LITERAL(21, 282, 6), // "taskId"
QT_MOC_LITERAL(22, 289, 8), // "targetId"
QT_MOC_LITERAL(23, 298, 8), // "dataCate"
QT_MOC_LITERAL(24, 307, 8), // "fileName"
QT_MOC_LITERAL(25, 316, 4), // "read"
QT_MOC_LITERAL(26, 321, 6), // "cpData"
QT_MOC_LITERAL(27, 328, 6), // "edData"
QT_MOC_LITERAL(28, 335, 10), // "noiselData"
QT_MOC_LITERAL(29, 346, 10), // "noisesData"
QT_MOC_LITERAL(30, 357, 7), // "fsdData"
QT_MOC_LITERAL(31, 365, 9), // "lofarData"
QT_MOC_LITERAL(32, 375, 9), // "demonData"
QT_MOC_LITERAL(33, 385, 8), // "echoData"
QT_MOC_LITERAL(34, 394, 6) // "noData"

    },
    "ParseData\0parse_status\0\0status\0text\0"
    "update_taskinfo\0send_cpdata\0startTime\0"
    "endTime\0QMultiMap<QString,QVector<double> >&\0"
    "values\0send_eddata\0send_noiseldata\0"
    "send_noisesdata\0send_fsddata\0"
    "send_lofardata\0send_demondata\0"
    "send_echodata\0QMultiMap<QString,QVector<quint8> >&\0"
    "send_nodata\0parse\0taskId\0targetId\0"
    "dataCate\0fileName\0read\0cpData\0edData\0"
    "noiselData\0noisesData\0fsdData\0lofarData\0"
    "demonData\0echoData\0noData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParseData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    0,   84,    2, 0x06 /* Public */,
       6,    3,   85,    2, 0x06 /* Public */,
      11,    3,   92,    2, 0x06 /* Public */,
      12,    3,   99,    2, 0x06 /* Public */,
      13,    3,  106,    2, 0x06 /* Public */,
      14,    3,  113,    2, 0x06 /* Public */,
      15,    3,  120,    2, 0x06 /* Public */,
      16,    3,  127,    2, 0x06 /* Public */,
      17,    3,  134,    2, 0x06 /* Public */,
      19,    3,  141,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    4,  148,    2, 0x0a /* Public */,
      25,   13,  157,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 18,    7,    8,   10,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 18,    7,    8,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 18, 0x80000000 | 18,   21,   22,   23,   24,   26,   27,   28,   29,   30,   31,   32,   33,   34,

       0        // eod
};

void ParseData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParseData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parse_status((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->update_taskinfo(); break;
        case 2: _t->send_cpdata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 3: _t->send_eddata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 4: _t->send_noiseldata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 5: _t->send_noisesdata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 6: _t->send_fsddata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 7: _t->send_lofardata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 8: _t->send_demondata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[3]))); break;
        case 9: _t->send_echodata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<quint8> >(*)>(_a[3]))); break;
        case 10: _t->send_nodata((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< QMultiMap<QString,QVector<quint8> >(*)>(_a[3]))); break;
        case 11: _t->parse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 12: _t->read((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[5])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[6])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[7])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[8])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[9])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[10])),(*reinterpret_cast< QMultiMap<QString,QVector<double> >(*)>(_a[11])),(*reinterpret_cast< QMultiMap<QString,QVector<quint8> >(*)>(_a[12])),(*reinterpret_cast< QMultiMap<QString,QVector<quint8> >(*)>(_a[13]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ParseData::*)(const int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::parse_status)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ParseData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::update_taskinfo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_cpdata)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_eddata)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_noiseldata)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_noisesdata)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_fsddata)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_lofardata)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<double>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_demondata)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<quint8>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_echodata)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ParseData::*)(const QDateTime , const QDateTime , QMultiMap<QString,QVector<quint8>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParseData::send_nodata)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParseData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ParseData.data,
    qt_meta_data_ParseData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ParseData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParseData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParseData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ParseData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ParseData::parse_status(const int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParseData::update_taskinfo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ParseData::send_cpdata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ParseData::send_eddata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ParseData::send_noiseldata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ParseData::send_noisesdata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ParseData::send_fsddata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ParseData::send_lofardata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ParseData::send_demondata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<double>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ParseData::send_echodata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<quint8>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ParseData::send_nodata(const QDateTime _t1, const QDateTime _t2, QMultiMap<QString,QVector<quint8>> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
