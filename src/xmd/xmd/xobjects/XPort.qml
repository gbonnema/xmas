/************************************************************************
 *
 * Copyright Stefan Versluys, 2014
 *
 * This file is part of the xmas-design tool.
 *
 *  The xmas-design tool is free software: you can redistribute it
 *  and/or modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation, either version 3 of
 *  the License, or (at your option) any later version.
 *
 *  The xmas-design tool is distributed in the hope that it will be
 *  useful,  but WITHOUT ANY WARRANTY; without even the implied warranty
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the xmas-design tool.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 *
 * Parts of this code were copied from Qt examples with following copyright
 * and license notices:
 *
 * Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies)
 *
 * under BSD license.
 *
 *
 **************************************************************************/
import QtQuick 2.4
import XMAS 1.0
import "xchannel.js" as Code


Item {
    id:port
    objectName: "port"
    width: 10; height:10
    x:-5; y:-5
    property int id: 0
    property bool connected: false
    property string name: "a"
    property int type: Xmas.Target
    property alias orientation: port.rotation

    orientation: (port.type == Xmas.Target) ? Xmas.West : Xmas.East

    signal update()
    signal removed()

    Rectangle{
        id:portShape
        color: connected ? "black" : "red"
        anchors.fill: parent
        border.color: "black"
        border.width: mousearea.containsMouse && sheet.isValidPort(port) ? 2 : 0
        radius: port.type === Xmas.Target ? 0 : port.width * 0.5
    }

    onConnectedChanged: connected ? 0 : Code.abortConnecting(port)

    Component.onDestruction: removed()

    Connections {
        target: parent
        onUpdate: update()
    }

    MouseArea {
        id: mousearea
        anchors.fill: parent
        anchors.margins: -10 // magic port :)
        hoverEnabled: !connected && sheet.isValidPort(port)
        preventStealing: true
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onPressed: {
            if (mouse.button === Qt.LeftButton
                    && !connected) {
                connected = true
                sheet.wiring(port)
            } else {mouse.accepted=false}
        }
        onContainsMouseChanged: {
            sheet.checkTarget(port)
        }
    }
}


