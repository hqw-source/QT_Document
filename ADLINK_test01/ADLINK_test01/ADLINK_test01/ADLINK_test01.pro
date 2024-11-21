QT       += core gui
QT += charts
QT += widgets
QT += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    dataanalyse.cpp \
    main.cpp \
    widget.cpp
HEADERS += \
    Dask64.h \
    dataanalyse.h \
    widget.h
FORMS += \
    dataanalyse.ui \
    widget.ui
RC_ICONS= tubiao.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
win32: LIBS += -L$$PWD/../../Lib/ -lPCI-Dask64
INCLUDEPATH += $$PWD/../../Lib
DEPENDPATH += $$PWD/../../Lib
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Lib/PCI-Dask64.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/../../Lib/libPCI-Dask64.a
RESOURCES += \
    images.qrc
DISTFILES +=
