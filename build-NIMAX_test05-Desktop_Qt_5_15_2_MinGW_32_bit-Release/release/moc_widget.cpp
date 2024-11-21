/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NIMAX_test05/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[14];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 21), // "on_stopSample_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 22), // "on_startSample_clicked"
QT_MOC_LITERAL(4, 53, 26), // "on_startSaveSample_clicked"
QT_MOC_LITERAL(5, 80, 25), // "on_stopSaveSample_clicked"
QT_MOC_LITERAL(6, 106, 25), // "on_timeSaveSample_clicked"
QT_MOC_LITERAL(7, 132, 28), // "on_cDAQ1Mod1ai1_stateChanged"
QT_MOC_LITERAL(8, 161, 28), // "on_cDAQ1Mod2ai0_stateChanged"
QT_MOC_LITERAL(9, 190, 28), // "on_cDAQ1Mod2ai1_stateChanged"
QT_MOC_LITERAL(10, 219, 28), // "on_cDAQ1Mod2ai2_stateChanged"
QT_MOC_LITERAL(11, 248, 19), // "on_filePath_clicked"
QT_MOC_LITERAL(12, 268, 23), // "on_setTime_valueChanged"
QT_MOC_LITERAL(13, 292, 4) // "arg1"

    },
    "Widget\0on_stopSample_clicked\0\0"
    "on_startSample_clicked\0"
    "on_startSaveSample_clicked\0"
    "on_stopSaveSample_clicked\0"
    "on_timeSaveSample_clicked\0"
    "on_cDAQ1Mod1ai1_stateChanged\0"
    "on_cDAQ1Mod2ai0_stateChanged\0"
    "on_cDAQ1Mod2ai1_stateChanged\0"
    "on_cDAQ1Mod2ai2_stateChanged\0"
    "on_filePath_clicked\0on_setTime_valueChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       8,    1,   77,    2, 0x08 /* Private */,
       9,    1,   80,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_stopSample_clicked(); break;
        case 1: _t->on_startSample_clicked(); break;
        case 2: _t->on_startSaveSample_clicked(); break;
        case 3: _t->on_stopSaveSample_clicked(); break;
        case 4: _t->on_timeSaveSample_clicked(); break;
        case 5: _t->on_cDAQ1Mod1ai1_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cDAQ1Mod2ai0_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_cDAQ1Mod2ai1_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_cDAQ1Mod2ai2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_filePath_clicked(); break;
        case 10: _t->on_setTime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
