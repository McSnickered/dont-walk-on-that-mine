#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T14:48:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineSweeper
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    square.cpp

HEADERS  += dialog.h \
    square.h

FORMS    += dialog.ui
