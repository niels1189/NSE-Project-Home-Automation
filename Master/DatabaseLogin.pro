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
    temperaturescreen.cpp \
    Camera.cpp
    GPIO.cpp
    I22cCom.cpp
    Light.cpp
    Log.cpp
    MotionSensor.cpp
    PressureSensor.cpp
    Sensor.cpp
    

HEADERS  += dialog.h \
    screenafterlogin.h \
    temperatuur.h \
    temperaturescreen.h
    Camera.h
    GPIO.h
    I22cCom.h
    Light.h
    Log.h
    MotionSensor.h
    PressureSensor.h
    Sensor.h

FORMS    += dialog.ui \
    screenafterlogin.ui \
    temperaturescreen.ui

DISTFILES +=
