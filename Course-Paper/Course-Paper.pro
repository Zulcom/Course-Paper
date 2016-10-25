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
    algorithm/User.cpp \
    algorithm/algorithm.cpp

HEADERS  += \
    logon.h \
    sha256/sha256.h \
    db/db.h

FORMS    += \
    logon.ui

DISTFILES += \
    sha256/LICENSE.txt \
    img/user.png
