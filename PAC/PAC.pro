#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T14:31:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = PAC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    myscene.cpp \
    maze.cpp

HEADERS  += mainwindow.h \
    myscene.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    sounds.qrc \
    images.qrc

LIBS +=-L"/usr/local/lib/"
