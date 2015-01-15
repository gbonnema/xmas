import QtQuick 2.4
import XMAS 1.0

QComponent {
    id: comp
    width: 200
    height: 200
    name: "switch"
    connectors: [
        Connector {
            x: 0; y: 90
            name: "a1"
        },
        Connector {
            x: 180; y:30
            name: "a2"

        },
        Connector {
            x: 180; y:150
            name: "a3"
        }
    ]
    Image {source: "../images/svgs/switch.svg"}
}

