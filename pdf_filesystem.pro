#-------------------------------------------------
#
# Project created by QtCreator 2019-08-27T13:53:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdf_filesystem
TEMPLATE = app
LIBS += -L/usr/local/lib/ -lpoppler-qt5

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    filewindow.cpp \
    fileconfigure.cpp \
    fileimagebuffer.cpp \
    filethumlabel.cpp \
    filelist.cpp

HEADERS += \
        mainwindow.h \
    filewindow.h \
    fileconfigure.h \
    fileimagebuffer.h \
    filethumlabel.h \
    filelist.h

FORMS +=

RESOURCES += \
    filesys.qrc
