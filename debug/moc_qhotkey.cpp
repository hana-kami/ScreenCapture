/****************************************************************************
** Meta object code from reading C++ file 'qhotkey.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QT/QHotkey-master/QHotkey/qhotkey.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhotkey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QHotkey_t {
    QByteArrayData data[17];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QHotkey_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QHotkey_t qt_meta_stringdata_QHotkey = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QHotkey"
QT_MOC_LITERAL(1, 8, 9), // "activated"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 17), // "registeredChanged"
QT_MOC_LITERAL(4, 37, 10), // "registered"
QT_MOC_LITERAL(5, 48, 13), // "setRegistered"
QT_MOC_LITERAL(6, 62, 11), // "setShortcut"
QT_MOC_LITERAL(7, 74, 8), // "shortcut"
QT_MOC_LITERAL(8, 83, 12), // "autoRegister"
QT_MOC_LITERAL(9, 96, 7), // "Qt::Key"
QT_MOC_LITERAL(10, 104, 7), // "keyCode"
QT_MOC_LITERAL(11, 112, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(12, 134, 9), // "modifiers"
QT_MOC_LITERAL(13, 144, 13), // "resetShortcut"
QT_MOC_LITERAL(14, 158, 17), // "setNativeShortcut"
QT_MOC_LITERAL(15, 176, 14), // "NativeShortcut"
QT_MOC_LITERAL(16, 191, 14) // "nativeShortcut"

    },
    "QHotkey\0activated\0\0registeredChanged\0"
    "registered\0setRegistered\0setShortcut\0"
    "shortcut\0autoRegister\0Qt::Key\0keyCode\0"
    "Qt::KeyboardModifiers\0modifiers\0"
    "resetShortcut\0setNativeShortcut\0"
    "NativeShortcut\0nativeShortcut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHotkey[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,  100, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   68,    2, 0x0a /* Public */,
       6,    2,   71,    2, 0x0a /* Public */,
       6,    1,   76,    2, 0x2a /* Public | MethodCloned */,
       6,    3,   79,    2, 0x0a /* Public */,
       6,    2,   86,    2, 0x2a /* Public | MethodCloned */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    2,   92,    2, 0x0a /* Public */,
      14,    1,   97,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Bool, QMetaType::Bool,    4,
    QMetaType::Bool, QMetaType::QKeySequence, QMetaType::Bool,    7,    8,
    QMetaType::Bool, QMetaType::QKeySequence,    7,
    QMetaType::Bool, 0x80000000 | 9, 0x80000000 | 11, QMetaType::Bool,   10,   12,    8,
    QMetaType::Bool, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 15, QMetaType::Bool,   16,    8,
    QMetaType::Bool, 0x80000000 | 15,   16,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00495103,
       7, QMetaType::QKeySequence, 0x00095107,

 // properties: notify_signal_id
       1,
       0,

       0        // eod
};

void QHotkey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHotkey *_t = static_cast<QHotkey *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activated(QPrivateSignal()); break;
        case 1: _t->registeredChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: { bool _r = _t->setRegistered((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->setShortcut((*reinterpret_cast< const QKeySequence(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->setShortcut((*reinterpret_cast< const QKeySequence(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->setShortcut((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->setShortcut((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->resetShortcut();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->setNativeShortcut((*reinterpret_cast< NativeShortcut(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->setNativeShortcut((*reinterpret_cast< NativeShortcut(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QHotkey::*_t)(QPrivateSignal);
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHotkey::activated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QHotkey::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHotkey::registeredChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QHotkey *_t = static_cast<QHotkey *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isRegistered(); break;
        case 1: *reinterpret_cast< QKeySequence*>(_v) = _t->shortcut(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QHotkey *_t = static_cast<QHotkey *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRegistered(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setShortcut(*reinterpret_cast< QKeySequence*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        QHotkey *_t = static_cast<QHotkey *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 1: _t->resetShortcut(); break;
        default: break;
        }
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QHotkey::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QHotkey.data,
      qt_meta_data_QHotkey,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QHotkey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHotkey::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QHotkey.stringdata0))
        return static_cast<void*>(const_cast< QHotkey*>(this));
    return QObject::qt_metacast(_clname);
}

int QHotkey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QHotkey::activated(QPrivateSignal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHotkey::registeredChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
