######################################################################
# Automatically generated by qmake (3.1) Wed Feb 9 12:05:57 2022
######################################################################

TEMPLATE = app
TARGET = BackseatScreenDemo
INCLUDEPATH += .
QT += gui widgets
QT += qml quick
QMAKE_CXXFLAGS += -std=c++14

#INCLUDEPATH += /usr/lib/x86_64-linux-gnu/
#LIBS += /usr/lib/x86_64-linux-gnu/libcurl.a
LIBS+=-lcurl
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += main.cpp \
    backend/tmdbapicaller.cpp \
    gui/gui.cpp \
    gui/guieventhandler.cpp

DISTFILES +=

RESOURCES += \
    images.qrc \
    qml.qrc

HEADERS += \
    backend/tmdbapicaller.h \
    gui/guieventhandler.h \
    interfaces/IGUI.h \
    gui/gui.h
