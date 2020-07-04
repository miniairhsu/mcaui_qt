/****************************************************************************
** Meta object code from reading C++ file 'mcawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mcawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mcawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MCAWindow_t {
    QByteArrayData data[15];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MCAWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MCAWindow_t qt_meta_stringdata_MCAWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MCAWindow"
QT_MOC_LITERAL(1, 10, 32), // "on_scaleXBox_currentIndexChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "index"
QT_MOC_LITERAL(4, 50, 32), // "on_scaleYBox_currentIndexChanged"
QT_MOC_LITERAL(5, 83, 24), // "on_commandButton_clicked"
QT_MOC_LITERAL(6, 108, 28), // "on_commandEdit_returnPressed"
QT_MOC_LITERAL(7, 137, 21), // "on_ledButton1_clicked"
QT_MOC_LITERAL(8, 159, 21), // "on_ledButton2_clicked"
QT_MOC_LITERAL(9, 181, 21), // "on_ledButton3_clicked"
QT_MOC_LITERAL(10, 203, 21), // "on_ledButton4_clicked"
QT_MOC_LITERAL(11, 225, 16), // "on_ledOn_clicked"
QT_MOC_LITERAL(12, 242, 17), // "on_ledOff_clicked"
QT_MOC_LITERAL(13, 260, 21), // "on_plotButton_pressed"
QT_MOC_LITERAL(14, 282, 21) // "on_stopButton_pressed"

    },
    "MCAWindow\0on_scaleXBox_currentIndexChanged\0"
    "\0index\0on_scaleYBox_currentIndexChanged\0"
    "on_commandButton_clicked\0"
    "on_commandEdit_returnPressed\0"
    "on_ledButton1_clicked\0on_ledButton2_clicked\0"
    "on_ledButton3_clicked\0on_ledButton4_clicked\0"
    "on_ledOn_clicked\0on_ledOff_clicked\0"
    "on_plotButton_pressed\0on_stopButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MCAWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    0,   80,    2, 0x08 /* Private */,
       6,    0,   81,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MCAWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MCAWindow *_t = static_cast<MCAWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_scaleXBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_scaleYBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_commandButton_clicked(); break;
        case 3: _t->on_commandEdit_returnPressed(); break;
        case 4: _t->on_ledButton1_clicked(); break;
        case 5: _t->on_ledButton2_clicked(); break;
        case 6: _t->on_ledButton3_clicked(); break;
        case 7: _t->on_ledButton4_clicked(); break;
        case 8: _t->on_ledOn_clicked(); break;
        case 9: _t->on_ledOff_clicked(); break;
        case 10: _t->on_plotButton_pressed(); break;
        case 11: _t->on_stopButton_pressed(); break;
        default: ;
        }
    }
}

const QMetaObject MCAWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MCAWindow.data,
      qt_meta_data_MCAWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MCAWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MCAWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MCAWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MCAWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
