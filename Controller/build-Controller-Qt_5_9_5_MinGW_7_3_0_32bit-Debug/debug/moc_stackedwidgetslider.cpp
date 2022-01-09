/****************************************************************************
** Meta object code from reading C++ file 'stackedwidgetslider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../controller/stackedwidgetslider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stackedwidgetslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StackedWidgetSlider_t {
    QByteArrayData data[6];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StackedWidgetSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StackedWidgetSlider_t qt_meta_stringdata_StackedWidgetSlider = {
    {
QT_MOC_LITERAL(0, 0, 19), // "StackedWidgetSlider"
QT_MOC_LITERAL(1, 20, 12), // "getChartDate"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "getAddNewFormData"
QT_MOC_LITERAL(4, 52, 20), // "std::vector<QString>"
QT_MOC_LITERAL(5, 73, 17) // "getUpdateFormData"

    },
    "StackedWidgetSlider\0getChartDate\0\0"
    "getAddNewFormData\0std::vector<QString>\0"
    "getUpdateFormData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StackedWidgetSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       5,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    0x80000000 | 4,
    0x80000000 | 4,

       0        // eod
};

void StackedWidgetSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StackedWidgetSlider *_t = static_cast<StackedWidgetSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getChartDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { std::vector<QString> _r = _t->getAddNewFormData();
            if (_a[0]) *reinterpret_cast< std::vector<QString>*>(_a[0]) = std::move(_r); }  break;
        case 2: { std::vector<QString> _r = _t->getUpdateFormData();
            if (_a[0]) *reinterpret_cast< std::vector<QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject StackedWidgetSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StackedWidgetSlider.data,
      qt_meta_data_StackedWidgetSlider,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StackedWidgetSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StackedWidgetSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StackedWidgetSlider.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StackedWidgetSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
