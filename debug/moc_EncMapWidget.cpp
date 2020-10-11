/****************************************************************************
** Meta object code from reading C++ file 'EncMapWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../thirty/include/EncMapWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EncMapWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EncMapWidget_t {
    QByteArrayData data[43];
    char stringdata0[562];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EncMapWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EncMapWidget_t qt_meta_stringdata_EncMapWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EncMapWidget"
QT_MOC_LITERAL(1, 13, 17), // "OnMouseLeftDowned"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "M_POINT"
QT_MOC_LITERAL(4, 40, 5), // "point"
QT_MOC_LITERAL(5, 46, 18), // "OnMouseRightDowned"
QT_MOC_LITERAL(6, 65, 16), // "OnMouseLeftUpped"
QT_MOC_LITERAL(7, 82, 18), // "OnMouseRightUppped"
QT_MOC_LITERAL(8, 101, 22), // "OnLeftMouseDoubleClick"
QT_MOC_LITERAL(9, 124, 12), // "QMouseEvent*"
QT_MOC_LITERAL(10, 137, 5), // "event"
QT_MOC_LITERAL(11, 143, 23), // "OnRightMouseDoubleClick"
QT_MOC_LITERAL(12, 167, 11), // "OnMouseMove"
QT_MOC_LITERAL(13, 179, 12), // "OnMouseWheel"
QT_MOC_LITERAL(14, 192, 12), // "QWheelEvent*"
QT_MOC_LITERAL(15, 205, 21), // "OnAddingNewNodeByTool"
QT_MOC_LITERAL(16, 227, 8), // "layerPos"
QT_MOC_LITERAL(17, 236, 6), // "objPos"
QT_MOC_LITERAL(18, 243, 10), // "M_GEO_TYPE"
QT_MOC_LITERAL(19, 254, 7), // "geoType"
QT_MOC_LITERAL(20, 262, 17), // "SPECIAL_LINE_TYPE"
QT_MOC_LITERAL(21, 280, 11), // "specialType"
QT_MOC_LITERAL(22, 292, 7), // "nodePos"
QT_MOC_LITERAL(23, 300, 9), // "nodeGeoPo"
QT_MOC_LITERAL(24, 310, 20), // "OnEndAddObjectByTool"
QT_MOC_LITERAL(25, 331, 21), // "OnEndEditObjectByTool"
QT_MOC_LITERAL(26, 353, 21), // "OnObjectChangedByTool"
QT_MOC_LITERAL(27, 375, 10), // "nodeGeoPoX"
QT_MOC_LITERAL(28, 386, 11), // "changeState"
QT_MOC_LITERAL(29, 398, 20), // "OnEndAddNewMapByTool"
QT_MOC_LITERAL(30, 419, 13), // "EncMapWidget*"
QT_MOC_LITERAL(31, 433, 9), // "newEncMap"
QT_MOC_LITERAL(32, 443, 5), // "bool&"
QT_MOC_LITERAL(33, 449, 10), // "retInitSuc"
QT_MOC_LITERAL(34, 460, 15), // "OnAfterDrawShip"
QT_MOC_LITERAL(35, 476, 9), // "QPainter*"
QT_MOC_LITERAL(36, 486, 7), // "painter"
QT_MOC_LITERAL(37, 494, 13), // "OnAferDrawMap"
QT_MOC_LITERAL(38, 508, 12), // "OnMapWorking"
QT_MOC_LITERAL(39, 521, 12), // "SelectedShip"
QT_MOC_LITERAL(40, 534, 6), // "shipId"
QT_MOC_LITERAL(41, 541, 15), // "AfterAuthorized"
QT_MOC_LITERAL(42, 557, 4) // "bSuc"

    },
    "EncMapWidget\0OnMouseLeftDowned\0\0M_POINT\0"
    "point\0OnMouseRightDowned\0OnMouseLeftUpped\0"
    "OnMouseRightUppped\0OnLeftMouseDoubleClick\0"
    "QMouseEvent*\0event\0OnRightMouseDoubleClick\0"
    "OnMouseMove\0OnMouseWheel\0QWheelEvent*\0"
    "OnAddingNewNodeByTool\0layerPos\0objPos\0"
    "M_GEO_TYPE\0geoType\0SPECIAL_LINE_TYPE\0"
    "specialType\0nodePos\0nodeGeoPo\0"
    "OnEndAddObjectByTool\0OnEndEditObjectByTool\0"
    "OnObjectChangedByTool\0nodeGeoPoX\0"
    "changeState\0OnEndAddNewMapByTool\0"
    "EncMapWidget*\0newEncMap\0bool&\0retInitSuc\0"
    "OnAfterDrawShip\0QPainter*\0painter\0"
    "OnAferDrawMap\0OnMapWorking\0SelectedShip\0"
    "shipId\0AfterAuthorized\0bSuc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EncMapWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       7,    1,  113,    2, 0x06 /* Public */,
       8,    1,  116,    2, 0x06 /* Public */,
      11,    1,  119,    2, 0x06 /* Public */,
      12,    1,  122,    2, 0x06 /* Public */,
      13,    1,  125,    2, 0x06 /* Public */,
      15,    6,  128,    2, 0x06 /* Public */,
      24,    4,  141,    2, 0x06 /* Public */,
      25,    4,  150,    2, 0x06 /* Public */,
      26,    7,  159,    2, 0x06 /* Public */,
      29,    2,  174,    2, 0x06 /* Public */,
      34,    1,  179,    2, 0x06 /* Public */,
      37,    1,  182,    2, 0x06 /* Public */,
      38,    1,  185,    2, 0x06 /* Public */,
      39,    1,  188,    2, 0x06 /* Public */,
      41,    1,  191,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 14,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 18, 0x80000000 | 20, QMetaType::Int, 0x80000000 | 3,   16,   17,   19,   21,   22,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 18, 0x80000000 | 20,   16,   17,   19,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 18, 0x80000000 | 20,   16,   17,   19,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 18, 0x80000000 | 20, QMetaType::Int, 0x80000000 | 3, QMetaType::Int,   16,   17,   19,   21,   22,   27,   28,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 32,   31,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void, QMetaType::Bool,   42,

       0        // eod
};

void EncMapWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EncMapWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnMouseLeftDowned((*reinterpret_cast< M_POINT(*)>(_a[1]))); break;
        case 1: _t->OnMouseRightDowned((*reinterpret_cast< M_POINT(*)>(_a[1]))); break;
        case 2: _t->OnMouseLeftUpped((*reinterpret_cast< M_POINT(*)>(_a[1]))); break;
        case 3: _t->OnMouseRightUppped((*reinterpret_cast< M_POINT(*)>(_a[1]))); break;
        case 4: _t->OnLeftMouseDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->OnRightMouseDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->OnMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->OnMouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 8: _t->OnAddingNewNodeByTool((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< M_GEO_TYPE(*)>(_a[3])),(*reinterpret_cast< SPECIAL_LINE_TYPE(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< M_POINT(*)>(_a[6]))); break;
        case 9: _t->OnEndAddObjectByTool((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< M_GEO_TYPE(*)>(_a[3])),(*reinterpret_cast< SPECIAL_LINE_TYPE(*)>(_a[4]))); break;
        case 10: _t->OnEndEditObjectByTool((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< M_GEO_TYPE(*)>(_a[3])),(*reinterpret_cast< SPECIAL_LINE_TYPE(*)>(_a[4]))); break;
        case 11: _t->OnObjectChangedByTool((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< M_GEO_TYPE(*)>(_a[3])),(*reinterpret_cast< SPECIAL_LINE_TYPE(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< M_POINT(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 12: _t->OnEndAddNewMapByTool((*reinterpret_cast< EncMapWidget*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->OnAfterDrawShip((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 14: _t->OnAferDrawMap((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 15: _t->OnMapWorking((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 16: _t->SelectedShip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->AfterAuthorized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EncMapWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EncMapWidget::*)(M_POINT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMouseLeftDowned)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(M_POINT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMouseRightDowned)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(M_POINT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMouseLeftUpped)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(M_POINT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMouseRightUppped)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnLeftMouseDoubleClick)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnRightMouseDoubleClick)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMouseMove)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QWheelEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMouseWheel)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(int , int , M_GEO_TYPE , SPECIAL_LINE_TYPE , int , M_POINT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnAddingNewNodeByTool)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(int , int , M_GEO_TYPE , SPECIAL_LINE_TYPE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnEndAddObjectByTool)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(int , int , M_GEO_TYPE , SPECIAL_LINE_TYPE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnEndEditObjectByTool)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(int , int , M_GEO_TYPE , SPECIAL_LINE_TYPE , int , M_POINT , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnObjectChangedByTool)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(EncMapWidget * , bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnEndAddNewMapByTool)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QPainter * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnAfterDrawShip)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QPainter * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnAferDrawMap)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(QPainter * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::OnMapWorking)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::SelectedShip)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (EncMapWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EncMapWidget::AfterAuthorized)) {
                *result = 17;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EncMapWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_EncMapWidget.data,
    qt_meta_data_EncMapWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EncMapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EncMapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EncMapWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "YMEncMapMan"))
        return static_cast< YMEncMapMan*>(this);
    return QWidget::qt_metacast(_clname);
}

int EncMapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void EncMapWidget::OnMouseLeftDowned(M_POINT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EncMapWidget::OnMouseRightDowned(M_POINT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EncMapWidget::OnMouseLeftUpped(M_POINT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EncMapWidget::OnMouseRightUppped(M_POINT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EncMapWidget::OnLeftMouseDoubleClick(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EncMapWidget::OnRightMouseDoubleClick(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EncMapWidget::OnMouseMove(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EncMapWidget::OnMouseWheel(QWheelEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void EncMapWidget::OnAddingNewNodeByTool(int _t1, int _t2, M_GEO_TYPE _t3, SPECIAL_LINE_TYPE _t4, int _t5, M_POINT _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void EncMapWidget::OnEndAddObjectByTool(int _t1, int _t2, M_GEO_TYPE _t3, SPECIAL_LINE_TYPE _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void EncMapWidget::OnEndEditObjectByTool(int _t1, int _t2, M_GEO_TYPE _t3, SPECIAL_LINE_TYPE _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void EncMapWidget::OnObjectChangedByTool(int _t1, int _t2, M_GEO_TYPE _t3, SPECIAL_LINE_TYPE _t4, int _t5, M_POINT _t6, int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void EncMapWidget::OnEndAddNewMapByTool(EncMapWidget * _t1, bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void EncMapWidget::OnAfterDrawShip(QPainter * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void EncMapWidget::OnAferDrawMap(QPainter * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void EncMapWidget::OnMapWorking(QPainter * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void EncMapWidget::SelectedShip(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void EncMapWidget::AfterAuthorized(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
