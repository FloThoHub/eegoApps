/****************************************************************************
** Meta object code from reading C++ file 'impedancecheck_test.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../impedancecheck_test.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'impedancecheck_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImpedanceCheck_test_t {
    QByteArrayData data[10];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImpedanceCheck_test_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImpedanceCheck_test_t qt_meta_stringdata_ImpedanceCheck_test = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ImpedanceCheck_test"
QT_MOC_LITERAL(1, 20, 9), // "setButton"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "set64Button"
QT_MOC_LITERAL(4, 43, 15), // "updateFramesize"
QT_MOC_LITERAL(5, 59, 12), // "newframesize"
QT_MOC_LITERAL(6, 72, 17), // "updateSpacerValue"
QT_MOC_LITERAL(7, 90, 14), // "newspacervalue"
QT_MOC_LITERAL(8, 105, 14), // "updateFontSize"
QT_MOC_LITERAL(9, 120, 11) // "newfontsize"

    },
    "ImpedanceCheck_test\0setButton\0\0"
    "set64Button\0updateFramesize\0newframesize\0"
    "updateSpacerValue\0newspacervalue\0"
    "updateFontSize\0newfontsize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImpedanceCheck_test[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void ImpedanceCheck_test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImpedanceCheck_test *_t = static_cast<ImpedanceCheck_test *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setButton(); break;
        case 1: _t->set64Button(); break;
        case 2: _t->updateFramesize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateSpacerValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ImpedanceCheck_test::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImpedanceCheck_test.data,
      qt_meta_data_ImpedanceCheck_test,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImpedanceCheck_test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImpedanceCheck_test::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImpedanceCheck_test.stringdata0))
        return static_cast<void*>(const_cast< ImpedanceCheck_test*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImpedanceCheck_test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
