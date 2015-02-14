import QtQuick 2.4
import "../content"
import XMAS 1.0

XComponent {
    width: 100
    height: 50
    type: "function"
    prefix: "f"
    XPort {x: 0; y: 20; name: "t"; type:Xmas.Target}
    XPort {x: 90; y:20; name: "i"; type:Xmas.Initiator}
    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext('2d')
            ctx.strokeStyle = "black"
            ctx.lineWidth = 3.0
            ctx.moveTo(10 ,25)
            ctx.lineTo(90,25)
            ctx.moveTo(30 ,5)
            ctx.lineTo(70,45)
            ctx.stroke()
        }
    }

    withDialog: true
    onShowDialog: dialog.visible = true
    XDialog {
        id: dialog
        title: name + " properties"

    }
}
