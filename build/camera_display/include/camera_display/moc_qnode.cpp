/****************************************************************************
** Meta object code from reading C++ file 'qnode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/camera_display/include/camera_display/qnode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_camera_display__QNode_t {
    QByteArrayData data[7];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_camera_display__QNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_camera_display__QNode_t qt_meta_stringdata_camera_display__QNode = {
    {
QT_MOC_LITERAL(0, 0, 21), // "camera_display::QNode"
QT_MOC_LITERAL(1, 22, 11), // "rosShutdown"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9), // "image_val"
QT_MOC_LITERAL(4, 45, 14), // "fileNameChange"
QT_MOC_LITERAL(5, 60, 11), // "std::string"
QT_MOC_LITERAL(6, 72, 9) // "finChange"

    },
    "camera_display::QNode\0rosShutdown\0\0"
    "image_val\0fileNameChange\0std::string\0"
    "finChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_camera_display__QNode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void camera_display::QNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QNode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rosShutdown(); break;
        case 1: _t->image_val((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->fileNameChange((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->finChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::rosShutdown)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QNode::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::image_val)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject camera_display::QNode::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_camera_display__QNode.data,
    qt_meta_data_camera_display__QNode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *camera_display::QNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *camera_display::QNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_camera_display__QNode.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int camera_display::QNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void camera_display::QNode::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void camera_display::QNode::image_val(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
