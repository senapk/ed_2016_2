TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDEPATH += /usr/lib/
CONFIG += c++11

SOURCES += main.cpp

HEADERS += \
    libs/player.h \
    libs/cmat.h \
    libs/matriz.h \
    libs/view.h \
    libs/file_operations.h

OTHER_FILES += \
    input_teste.txt \
    ../Readme.md

