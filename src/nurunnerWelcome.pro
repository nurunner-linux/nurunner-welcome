#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T13:26:58
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nurunnerWelcome
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    unixcommand.cpp \
    package.cpp \
    settingsmanager.cpp \
    terminal.cpp \
    wmhelper.cpp \
    utils.cpp \
    pacmanexec.cpp \
    searchbar.cpp \
    searchlineedit.cpp \
    readme.cpp

HEADERS  += mainwindow.h \
    unixcommand.h \
    package.h \
    settingsmanager.h \
    constants.h \
    strconstants.h \
    uihelper.h \
    terminal.h \
    wmhelper.h \
    utils.h \
    pacmanexec.h \
    searchbar.h \
    searchlineedit.h \
    readme.h

FORMS    += mainwindow.ui \
    readme.ui
