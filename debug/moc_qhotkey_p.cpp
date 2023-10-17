/****************************************************************************
** Meta object code from reading C++ file 'qhotkey_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QT/QHotkey-master/QHotkey/qhotkey_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhotkey_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QHotkeyPrivate_t {
    QByteArrayData data[12];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QHotkeyPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QHotkeyPrivate_t qt_meta_stringdata_QHotkeyPrivate = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QHotkeyPrivate"
QT_MOC_LITERAL(1, 15, 18), // "addShortcutInvoked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "QHotkey*"
QT_MOC_LITERAL(4, 44, 6), // "hotkey"
QT_MOC_LITERAL(5, 51, 21), // "removeShortcutInvoked"
QT_MOC_LITERAL(6, 73, 21), // "nativeShortcutInvoked"
QT_MOC_LITERAL(7, 95, 23), // "QHotkey::NativeShortcut"
QT_MOC_LITERAL(8, 119, 7), // "Qt::Key"
QT_MOC_LITERAL(9, 127, 7), // "keycode"
QT_MOC_LITERAL(10, 135, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(11, 157, 9) // "modifiers"

    },
    "QHotkeyPrivate\0addShortcutInvoked\0\0"
    "QHotkey*\0hotkey\0removeShortcutInvoked\0"
    "nativeShortcutInvoked\0QHotkey::NativeShortcut\0"
    "Qt::Key\0keycode\0Qt::KeyboardModifiers\0"
    "modifiers"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHotkeyPrivate[] = {

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

 // methods: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x00 /* Private */,
       5,    1,   32,    2, 0x00 /* Private */,
       6,    2,   35,    2, 0x00 /* Private */,

 // methods: parameters
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 3,    4,
    0x80000000 | 7, 0x80000000 | 8, 0x80000000 | 10,    9,   11,

       0        // eod
};

void QHotkeyPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHotkeyPrivate *_t = static_cast<QHotkeyPrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->addShortcutInvoked((*reinterpret_cast< QHotkey*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->removeShortcutInvoked((*reinterpret_cast< QHotkey*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { QHotkey::NativeShortcut _r = _t->nativeShortcutInvoked((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QHotkey::NativeShortcut*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHotkey* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHotkey* >(); break;
            }
            break;
        }
    }
}

const QMetaObject QHotkeyPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QHotkeyPrivate.data,
      qt_meta_data_QHotkeyPrivate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QHotkeyPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHotkeyPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QHotkeyPrivate.stringdata0))
        return static_cast<void*>(const_cast< QHotkeyPrivate*>(this));
    if (!strcmp(_clname, "QAbstractNativeEventFilter"))
        return static_cast< QAbstractNativeEventFilter*>(const_cast< QHotkeyPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int QHotkeyPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
