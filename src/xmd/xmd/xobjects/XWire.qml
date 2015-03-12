import QtQuick 2.4

Rectangle {
    id: l
    property alias x1: l.x
    property alias y1: l.y

    property real x2: l.x
    property real y2: l.y

    property alias size: l.height

    color: "black"
    height: 2

    transformOrigin: Item.Left
    transform: Translate { y:-size/2 }

    width: getWidth(x1,y1,x2,y2);
    rotation: getSlope(x1,y1,x2,y2);

    function getWidth(sx1,sy1,sx2,sy2)
    {
        var w=Math.sqrt(Math.pow((sx2-sx1),2)+Math.pow((sy2-sy1),2));
        return w;
    }

    function getSlope(sx1,sy1,sx2,sy2)
     {
         var a
         var dx=sx2-sx1
         var dy=sy2-sy1
         if (dx===0)
             return dy > 0 ? 90 : -90
         a=Math.atan(dy/dx)*180/Math.PI
         if (dy<0 && dx<0)
             return a+180
         else if (dy>=0 && dx>=0)
             return a
         else if (dy<0 && dx>=0)
             return a
         else if (dy>=0 && dx<0)
             return a+180
         else
             return 0
     }
}

