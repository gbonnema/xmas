import QtQuick 2.4
import QtQuick.Layouts 1.1

Rectangle {
    id:toolbox
    z:1
    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightgrey" }
        GradientStop { position: 0.4; color: "white" }
        GradientStop { position: 1.0; color: "lightgrey" }
    }

    RowLayout {
        id: palette
        anchors {left: parent.left ; top: parent.top ; bottom: parent.bottom}
        anchors.margins: {top: 5; bottom: 5}
        spacing: 10
        ToolBarItem {
            componentFile: "../qml/queue.qml"
            image: "images/svgs/queue.svg"
        }
        ToolBarItem {
            componentFile: "../qml/function.qml"
            image: "images/svgs/function.svg"
        }
        ToolBarItem {
            componentFile: "../qml/fork.qml"
            image: "images/svgs/fork.svg"
        }
        ToolBarItem {
            componentFile: "../qml/join.qml"
            image: "images/svgs/join.svg"
        }
        ToolBarItem {
            componentFile: "../qml/switch.qml"
            image: "images/svgs/switch.svg"
        }
        ToolBarItem {
            componentFile: "../qml/merge.qml"
            image: "images/svgs/merge.svg"
        }
        ToolBarItem {
            componentFile: "../qml/sink.qml"
            image: "images/svgs/sink.svg"
        }
        ToolBarItem {
            componentFile: "../qml/source.qml"
            image: "images/svgs/source.svg"
        }
        ToolBarItem {
            componentFile: "../qml/in.qml"
            image: "images/svgs/in.svg"
        }
        ToolBarItem {
            componentFile: "../qml/out.qml"
            image: "images/svgs/out.svg"
        }
        ToolBarItem {
            componentFile: "../qml/spidergon.qml"
            image: "images/svgs/composite.svg"
        }

    }

}
