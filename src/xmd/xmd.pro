! include( ../common.pri ) {
        error( Could not find the common.pri file)
}

include (defines.pri)

QT += widgets svg quick qml quickwidgets

HEADERS       = mainwindow.h \
                setup.h \
    canvas/complib.h \
    canvas/component.h \
    canvas/connection.h \
    canvas/connector.h \
    canvas/network.h
				
SOURCES       = canvas/complib.cpp \
    canvas/component.cpp \
    canvas/connection.cpp \
    canvas/connector.cpp \
    canvas/network.cpp \
    main.cpp
    
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32 {
    target.path = xmd
    INSTALLS += target
}

INCLUDEPATH += canvas content qml

TEMPLATE = lib

DISTFILES += qml/fork.qml \
    qml/function.qml \
    qml/in.qml \
    qml/join.qml \
    qml/merge.qml \
    qml/out.qml \
    qml/queue.qml \
    qml/sink.qml \
    qml/source.qml \
    qml/spidergon.qml \
    qml/switch.qml \
    qml/Connection.qml \
    qml/Connector.qml \
    qml/QComponent.qml \
    qml/scene.qml \
    dynamicscene.qml \
    content/itemCreation.js \
    content/PaletteItem.qml \
    content/ScrollBar.qml \
    content/Button.qml \
    content/GenericSceneItem.qml

RESOURCES += \
    xmd.qrc
