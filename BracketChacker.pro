#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T17:53:48
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BracketChacker
TEMPLATE = app


SOURCES += main.cpp
SOURCES += helpdialog.cpp
SOURCES += mainwindow.cpp

HEADERS  += mainwindow.h
HEADERS  += helpdialog.h
HEADERS  += fileinfo.h

FORMS    += mainwindow.ui
FORMS    += helpdialog.ui

RESOURCES += icons.qrc
