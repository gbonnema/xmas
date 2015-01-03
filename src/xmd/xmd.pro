! include( ../common.pri ) {
        error( Could not find the common.pri file)
}

include (defines.pri)

QT += widgets svg

HEADERS       = mainwindow.h \
                modelwindow.h \
                projectmanager.h \
                setup.h \
                component.h \
                connector.h \
                connection.h \
                complib.h \
                positioncomponentextension.h \
                network.h \
                designercontroller.h \
                checker/xmas.h
SOURCES       = main.cpp \
                mainwindow.cpp \
                modelwindow.cpp \
                projectmanager.cpp \
                component.cpp \
                connector.cpp \
                connection.cpp \
                complib.cpp \
                network.cpp \
                designercontroller.cpp \
                checker/xmas.cpp
RESOURCES     = xmd.qrc


unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32 {
    target.path = xmd
    INSTALLS += target
}

# install
# target.path = xmd
# INSTALLS += target

DISTFILES +=
