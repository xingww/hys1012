/****************************************************************************
** Meta object code from reading C++ file 'x31jzform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../x31jzform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'x31jzform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_X31JzForm_t {
    QByteArrayData data[25];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X31JzForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X31JzForm_t qt_meta_stringdata_X31JzForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "X31JzForm"
QT_MOC_LITERAL(1, 10, 18), // "enableTaskComboBox"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "enable"
QT_MOC_LITERAL(4, 37, 11), // "start_parse"
QT_MOC_LITERAL(5, 49, 18), // "set_running_enable"
QT_MOC_LITERAL(6, 68, 7), // "running"
QT_MOC_LITERAL(7, 76, 14), // "reset_runnable"
QT_MOC_LITERAL(8, 91, 15), // "set_start_point"
QT_MOC_LITERAL(9, 107, 3), // "pos"
QT_MOC_LITERAL(10, 111, 11), // "set_scale_x"
QT_MOC_LITERAL(11, 123, 6), // "scaleX"
QT_MOC_LITERAL(12, 130, 19), // "on_btnStart_clicked"
QT_MOC_LITERAL(13, 150, 18), // "on_btnStop_clicked"
QT_MOC_LITERAL(14, 169, 19), // "on_rbActive_toggled"
QT_MOC_LITERAL(15, 189, 7), // "checked"
QT_MOC_LITERAL(16, 197, 20), // "on_rbPassive_toggled"
QT_MOC_LITERAL(17, 218, 10), // "updateData"
QT_MOC_LITERAL(18, 229, 15), // "QVector<double>"
QT_MOC_LITERAL(19, 245, 6), // "cpData"
QT_MOC_LITERAL(20, 252, 7), // "pwdData"
QT_MOC_LITERAL(21, 260, 11), // "mbLofarData"
QT_MOC_LITERAL(22, 272, 9), // "lofarData"
QT_MOC_LITERAL(23, 282, 9), // "demonData"
QT_MOC_LITERAL(24, 292, 18) // "completedParseFile"

    },
    "X31JzForm\0enableTaskComboBox\0\0enable\0"
    "start_parse\0set_running_enable\0running\0"
    "reset_runnable\0set_start_point\0pos\0"
    "set_scale_x\0scaleX\0on_btnStart_clicked\0"
    "on_btnStop_clicked\0on_rbActive_toggled\0"
    "checked\0on_rbPassive_toggled\0updateData\0"
    "QVector<double>\0cpData\0pwdData\0"
    "mbLofarData\0lofarData\0demonData\0"
    "completedParseFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X31JzForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,
      10,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,
      17,    5,   96,    2, 0x08 /* Private */,
      24,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 18, 0x80000000 | 18, 0x80000000 | 18, 0x80000000 | 18,   19,   20,   21,   22,   23,
    QMetaType::Void,

       0        // eod
};

void X31JzForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X31JzForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enableTaskComboBox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->start_parse(); break;
        case 2: _t->set_running_enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->reset_runnable(); break;
        case 4: _t->set_start_point((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_scale_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btnStart_clicked(); break;
        case 7: _t->on_btnStop_clicked(); break;
        case 8: _t->on_rbActive_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_rbPassive_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->updateData((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4])),(*reinterpret_cast< QVector<double>(*)>(_a[5]))); break;
        case 11: _t->completedParseFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
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
            using _t = void (X31JzForm::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzForm::enableTaskComboBox)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (X31JzForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzForm::start_parse)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (X31JzForm::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzForm::set_running_enable)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (X31JzForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzForm::reset_runnable)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (X31JzForm::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzForm::set_start_point)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (X31JzForm::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&X31JzForm::set_scale_x)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X31JzForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_X31JzForm.data,
    qt_meta_data_X31JzForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X31JzForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X31JzForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X31JzForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int X31JzForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void X31JzForm::enableTaskComboBox(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void X31JzForm::start_parse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void X31JzForm::set_running_enable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void X31JzForm::reset_runnable()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void X31JzForm::set_start_point(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void X31JzForm::set_scale_x(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
