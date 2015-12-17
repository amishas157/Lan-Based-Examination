#-------------------------------------------------
#
# Project created by QtCreator 2014-10-17T02:15:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = app

CONFIG += qt
SOURCES += main.cpp\
    test.cpp \
    mainwindow.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    test.h \
    result.h

FORMS    += mainwindow.ui \
    test.ui \
    result.ui
