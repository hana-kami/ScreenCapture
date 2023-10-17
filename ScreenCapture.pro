QT       += core gui widgets

include(D:/QT/QHotkey-master/qhotkey.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fullscreenwindow.cpp \
    main.cpp \
    videorecorder.cpp \
    videoscreen.cpp \
    widget.cpp

HEADERS += \
    fullscreenwindow.h \
    videorecorder.h \
    videoscreen.h \
    widget.h

FORMS += \
    videoscreen.ui \
    widget.ui

INCLUDEPATH += $$PWD/ffmpeg-3.4-win32-dev/include


LIBS += -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lavcodec \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lavdevice \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lavfilter \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lavformat \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lavutil \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lpostproc \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lswresample \
        -L$$PWD/"ffmpeg-3.4-win32-dev/lib" -lswscale \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
