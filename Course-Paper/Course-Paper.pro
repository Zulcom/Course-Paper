#-------------------------------------------------
#
# Project created by QtCreator 2016-10-11T15:25:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Course-Paper
TEMPLATE = app


SOURCES += main.cpp \
    logon.cpp \
    sha256/sha256.cpp \
    Model/User.cpp \
    db/db.cpp \
    search.cpp

HEADERS  += \
    logon.h \
    sha256/sha256.h \
    db/db.h \
    Model/user.h \
    search.h

FORMS    += \
    logon.ui \
    search.ui

DISTFILES += \
    sha256/LICENSE.txt \
    user.png \
    user.txt
