/****************************************************************************
** Meta object code from reading C++ file 'CustomVacation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CustomVacation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomVacation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomVacation_t {
    QByteArrayData data[15];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomVacation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomVacation_t qt_meta_stringdata_CustomVacation = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomVacation"
QT_MOC_LITERAL(1, 15, 36), // "on_listWidgetFirst_itemDouble..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 70, 4), // "item"
QT_MOC_LITERAL(5, 75, 7), // "resetUI"
QT_MOC_LITERAL(6, 83, 23), // "pushButtonFirst_clicked"
QT_MOC_LITERAL(7, 107, 24), // "pushButtonSecond_clicked"
QT_MOC_LITERAL(8, 132, 23), // "pushButtonSouv1_clicked"
QT_MOC_LITERAL(9, 156, 23), // "pushButtonSouv2_clicked"
QT_MOC_LITERAL(10, 180, 17), // "populateStartTeam"
QT_MOC_LITERAL(11, 198, 11), // "updateTotal"
QT_MOC_LITERAL(12, 210, 27), // "on_thirteenTeamPlan_clicked"
QT_MOC_LITERAL(13, 238, 23), // "on_bookYourTrip_clicked"
QT_MOC_LITERAL(14, 262, 31) // "on_NumberTripPushButton_clicked"

    },
    "CustomVacation\0on_listWidgetFirst_itemDoubleClicked\0"
    "\0QListWidgetItem*\0item\0resetUI\0"
    "pushButtonFirst_clicked\0"
    "pushButtonSecond_clicked\0"
    "pushButtonSouv1_clicked\0pushButtonSouv2_clicked\0"
    "populateStartTeam\0updateTotal\0"
    "on_thirteenTeamPlan_clicked\0"
    "on_bookYourTrip_clicked\0"
    "on_NumberTripPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomVacation[] = {

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
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustomVacation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomVacation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listWidgetFirst_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->resetUI(); break;
        case 2: _t->pushButtonFirst_clicked(); break;
        case 3: _t->pushButtonSecond_clicked(); break;
        case 4: _t->pushButtonSouv1_clicked(); break;
        case 5: _t->pushButtonSouv2_clicked(); break;
        case 6: _t->populateStartTeam((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->updateTotal(); break;
        case 8: _t->on_thirteenTeamPlan_clicked(); break;
        case 9: _t->on_bookYourTrip_clicked(); break;
        case 10: _t->on_NumberTripPushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CustomVacation::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CustomVacation.data,
    qt_meta_data_CustomVacation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomVacation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomVacation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomVacation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CustomVacation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
