#-------------------------------------------------
#
# Project created by QtCreator 2013-07-23T23:32:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spreadsheet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spreadsheet.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    spreadsheet.h \
    cell.h

FORMS    += mainwindow.ui
