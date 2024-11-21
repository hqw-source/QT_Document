QT       += core gui
QT      +=quick charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    NIDAQmx.h \
    nilibddc.h \
    widget.h

FORMS += \
    widget.ui

RC_ICONS=logo.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/'../DAQmx ANSI C Dev/lib/msvc/' -lNIDAQmx

INCLUDEPATH += $$PWD/'../DAQmx ANSI C Dev/lib/msvc'
DEPENDPATH += $$PWD/'../DAQmx ANSI C Dev/lib/msvc'


unix|win32: LIBS += -L$$PWD/'../TDM C DLL dev/lib/' -lnilibddc

INCLUDEPATH += $$PWD/'../TDM C DLL dev/include'
DEPENDPATH += $$PWD/'../TDM C DLL dev/include'

RESOURCES += \
    source.qrc
