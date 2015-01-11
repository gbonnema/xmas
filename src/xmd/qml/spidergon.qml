import QtQuick 1.1
import XMAS 1.0

QComponent {
    id: comp
    width: 200
    height: 400
    name: "test composite"
    connectors: [
        Connector {
            x: 0; y: 40
            name: "a1"
        },
        Connector {
            x: 0; y:80
            name: "a2"

        },
        Connector {
            x: 0; y:120
            name: "a3"
        },
        Connector {
            x: 180; y:40
            name: "a4"

        },
        Connector {
            x: 180; y:80
            name: "a5"
        }
    ]
    Image {source: "../images/svgs/composite.svg"}
}
