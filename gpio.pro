TEMPLATE = app

QT += qml quick widgets

SOURCES   += main.cpp\
	gpioclass.cpp
HEADERS   += gpioclass.h \
     main.h
RESOURCES += qml.qrc

#INCLUDEPATH += /usr/include/c++/5.4.0

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

LIBS      += -lsystemd

target.path = /usr/bin

# enable C standard as published in 2011 as ISO/IEC 9899:2011 (known as C11)
CONFIG     += c++11

# Default rules for deployment.
include(deployment.pri)
