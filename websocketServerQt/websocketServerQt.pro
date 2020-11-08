#-------------------------------------------------
#
# Project created by QtCreator 2020-11-08T14:35:41
#
#-------------------------------------------------

QT       += core gui network webchannel websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = websocketServerQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    messageserver.cpp \
    logger.cpp \
    generalfunctions.cpp

HEADERS  += mainwindow.h \
    messageserver.h \
    logger.h \
    generalfunctions.h

FORMS    += mainwindow.ui
