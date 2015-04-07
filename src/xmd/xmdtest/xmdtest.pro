#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T09:07:33
#
#-------------------------------------------------

QT       += core

QT       -= gui

WARNINGS += -Wall

TARGET = xmdtest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += C++11
CONFIG += link_prl

TEMPLATE = app


SOURCES +=

################################################
# INSTALL instructions
################################################
unix|win32|macx {
 target.path=$$PWD/../../../bin
 INSTALLS += target
}

################################################
# Dependencies
################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../bitpowder/release/ -lbitpowder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../bitpowder/debug/ -lbitpowder
else:unix: LIBS += -L$$OUT_PWD/../../bitpowder/ -lbitpowder

INCLUDEPATH += $$PWD/../../bitpowder
DEPENDPATH += $$PWD/../../bitpowder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../xmd/release/ -lxmd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../xmd/debug/ -lxmd
else:unix: LIBS += -L$$OUT_PWD/../xmd/ -lxmd

INCLUDEPATH += $$PWD/../xmd
DEPENDPATH += $$PWD/../xmd

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../xmv/vt/release/ -lvt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../xmv/vt/debug/ -lvt
else:unix: LIBS += -L$$OUT_PWD/../../xmv/vt/ -lvt

INCLUDEPATH += $$PWD/../../xmv/vt
DEPENDPATH += $$PWD/../../xmv/vt

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../interfaces/release/ -linterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../interfaces/debug/ -linterfaces
else:unix: LIBS += -L$$OUT_PWD/../../interfaces/ -linterfaces

INCLUDEPATH += $$PWD/../../interfaces
DEPENDPATH += $$PWD/../../interfaces

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../xmv/datamodel/release/ -ldatamodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../xmv/datamodel/debug/ -ldatamodel
else:unix: LIBS += -L$$OUT_PWD/../../xmv/datamodel/ -ldatamodel

INCLUDEPATH += $$PWD/../../xmv/datamodel
DEPENDPATH += $$PWD/../../xmv/datamodel

unix|win32|macx: LIBS += -L$$PWD/../../../lib -lgtest

INCLUDEPATH += $$PWD/../../../include
DEPENDPATH += $$PWD/../../../include

