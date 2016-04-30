#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T16:01:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = roofu
TEMPLATE = app

win32 {
    RC_FILE = roofu.rc
}

unix {
    ICON = roofu.icns
}

SOURCES += main.cpp\
        roofu.cpp \
    formulas.cpp

HEADERS  += roofu.h \
    formulas.h

FORMS    += roofu.ui

RESOURCES += \
    roofu.qrc

TRANSLATIONS += roofu_bg.ts

DISTFILES += \
    roofu.rc
