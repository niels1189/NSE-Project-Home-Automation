#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T14:27:24
#
#-------------------------------------------------

QT       += core gui sql
CONFIG += c++11
QMAKE_CXXFLAGS += -lptreads -lwiringPi



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatabaseLogin
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    screenafterlogin.cpp \
    temperatuur.cpp \
    temperaturescreen.cpp

HEADERS  += dialog.h \
    screenafterlogin.h \
    temperatuur.h \
    temperaturescreen.h

FORMS    += dialog.ui \
    screenafterlogin.ui \
    temperaturescreen.ui

DISTFILES +=
