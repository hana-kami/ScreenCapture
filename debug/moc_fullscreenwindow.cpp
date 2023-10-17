/****************************************************************************
** Meta object code from reading C++ file 'fullscreenwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fullscreenwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fullscreenwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FullScreenWindow_t {
    QByteArrayData data[5];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FullScreenWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FullScreenWindow_t qt_meta_stringdata_FullScreenWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FullScreenWindow"
QT_MOC_LITERAL(1, 17, 18), // "screenshotSelected"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "screenshot"
QT_MOC_LITERAL(4, 48, 19) // "screenshotCancelled"

    },
    "FullScreenWindow\0screenshotSelected\0"
    "\0screenshot\0screenshotCancelled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FullScreenWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void,

       0        // eod
};

void FullScreenWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FullScreenWindow *_t = static_cast<FullScreenWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->screenshotSelected((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 1: _t->screenshotCancelled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FullScreenWindow::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FullScreenWindow::screenshotSelected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FullScreenWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FullScreenWindow::screenshotCancelled)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FullScreenWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FullScreenWindow.data,
      qt_meta_data_FullScreenWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FullScreenWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FullScreenWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FullScreenWindow.stringdata0))
        return static_cast<void*>(const_cast< FullScreenWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int FullScreenWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void FullScreenWindow::screenshotSelected(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FullScreenWindow::screenshotCancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
