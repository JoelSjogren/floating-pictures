#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T14:25:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = strabismus
TEMPLATE = app


SOURCES += main.cpp\
    pictureform.cpp \
    window.cpp \
    functionalproperty.cpp

HEADERS  += \
    pictureform.h \
    pixmapitem.h \
    window.h \
    exprtk.hpp \
    functionalproperty.h

FORMS    += \
    pictureform.ui \
    window.ui

RESOURCES += \
    res.qrc
