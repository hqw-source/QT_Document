/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "selectRegWidget"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "index"
QT_MOC_LITERAL(4, 34, 14), // "updateR_Widget"
QT_MOC_LITERAL(5, 49, 8), // "newValue"
QT_MOC_LITERAL(6, 58, 15), // "updateSR_Widget"
QT_MOC_LITERAL(7, 74, 15), // "updatePR_Widget"
QT_MOC_LITERAL(8, 90, 3), // "row"
QT_MOC_LITERAL(9, 94, 5), // "cloum"
QT_MOC_LITERAL(10, 100, 20), // "updateDIO_UIO_Widget"
QT_MOC_LITERAL(11, 121, 7), // "regType"
QT_MOC_LITERAL(12, 129, 10), // "updateRArr"
QT_MOC_LITERAL(13, 140, 6), // "column"
QT_MOC_LITERAL(14, 147, 11), // "updateSRArr"
QT_MOC_LITERAL(15, 159, 11), // "updatePRArr"
QT_MOC_LITERAL(16, 171, 15), // "updateDI_DO_Arr"
QT_MOC_LITERAL(17, 187, 15), // "updateUI_UO_Arr"
QT_MOC_LITERAL(18, 203, 7) // "sendMsg"

    },
    "MainWindow\0selectRegWidget\0\0index\0"
    "updateR_Widget\0newValue\0updateSR_Widget\0"
    "updatePR_Widget\0row\0cloum\0"
    "updateDIO_UIO_Widget\0regType\0updateRArr\0"
    "column\0updateSRArr\0updatePRArr\0"
    "updateDI_DO_Arr\0updateUI_UO_Arr\0sendMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   69,    2, 0x08 /* Private */,
       4,    2,   72,    2, 0x08 /* Private */,
       6,    2,   77,    2, 0x08 /* Private */,
       7,    3,   82,    2, 0x08 /* Private */,
      10,    3,   89,    2, 0x08 /* Private */,
      12,    2,   96,    2, 0x08 /* Private */,
      14,    2,  101,    2, 0x08 /* Private */,
      15,    2,  106,    2, 0x08 /* Private */,
      16,    2,  111,    2, 0x08 /* Private */,
      17,    2,  116,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    3,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Float,    8,    9,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   11,    8,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   13,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectRegWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateR_Widget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: _t->updateSR_Widget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->updatePR_Widget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 4: _t->updateDIO_UIO_Widget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->updateRArr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateSRArr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->updatePRArr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->updateDI_DO_Arr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->updateUI_UO_Arr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->sendMsg(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
