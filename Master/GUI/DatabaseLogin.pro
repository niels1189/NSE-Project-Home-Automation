#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T14:27:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatabaseLogin
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    screenafterlogin.cpp \
    temperaturescreen.cpp \
    temperatuur.cpp

HEADERS  += dialog.h \
    screenafterlogin.h \
    temperaturescreen.h \
    temperatuur.h

FORMS    += dialog.ui \
    screenafterlogin.ui \
    temperaturescreen.ui

DISTFILES +=
