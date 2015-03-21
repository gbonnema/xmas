/*********************************************************************
  *
  * Copyright (C) <name>, <year>
  *
  * This file is part of the xmas-design tool.
  *
  * The xmas-design tool is free software: you can redistribute it
  * and/or modify it under the terms of the GNU General Public License
  * as published by the Free Software Foundation, either version 3 of
  * the License, or (at your option) any later version.
  *
  * The xmas-design tool is distributed in the hope that it will be
  * useful,  but WITHOUT ANY WARRANTY; without even the implied warranty
  * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with the xmas-design tool.  If not, see
  * <http://www.gnu.org/licenses/>.
  *
  **********************************************************************/
#ifndef NETWORK_H
#define NETWORK_H

#include <QQuickItem>

#include "export.h"
#include "component.h"

namespace model {

class Network : public QQuickItem
{
    Q_OBJECT
//    Q_PROPERTY(QQmlListProperty<model::Component> compList READ compList NOTIFY compListChanged)

private:

signals:
//    void compListChanged();


    void writeLog(QString message, QColor color = Qt::blue);

public slots:
    /**
     * @brief connect
     *
     * Connect the specified outport to the specified
     * inport. If one of the ports is already
     * connected the results are unspecified.
     *
     * @param port_out The output XPort
     * @param port_in The input XPort
     * @return true if the operation is successful, false otherwise
     */
    bool connect(XPort *port_out, XPort *port_in);
    /**
     * @brief disconnect
     *
     * Disconnect an output port from an input port.
     *
     * @param outport The outport that needs disconnection
     * @param inport The inport connected to the outport
     * @return true if the disconnect was successful, false otherwise
     */
    bool disconnect(XPort *outport, XPort *inport);
    /**
     * @brief toJson
     *
     *  Transfrom a given network of Component classes to
     *  a QString containing JSON for the network.
     *
     * @param allComponents A QList of Component pointers
     * @return a QString containing the json for the network.
     *
     */
    QString toJson(QList<Component *> allComponents);
        std::set<XMASComponent *> allComp;
        for (Component *comp : allComponents) {
            auto c = comp->getXMASComponent();
            allComp.insert(c);
        }
        result = ::Export(allComp,globals,mp);
        QString jsonString = QString(result.stl().c_str());
        return jsonString;
    }

//QQmlListProperty<Component> compList();

//#################################################################################################
// instead of qmllist we can use this simple loop to read all components on the canvas
// (linking a qmllist directly needs a slightly different approach at qml side too,can be done later if time left)
QList<Component *> getAllComponents(){
    m_compList.clear();

    for(QQuickItem *item : this->childItems()){
        Component *c = qobject_cast<Component *>(item);
        if(c){
            m_compList.append(c);
        }
    }
    qDebug() << "Total comps in list = " << m_compList.count();
    return m_compList;
}

//#################################################################################################

    QQmlListProperty<Component> compList();

private:
//    static void append_compList(QQmlListProperty<Component> *property, Component *comp);
//    static int count_compList(QQmlListProperty<Component> *property);
//    static Component *at_compList(QQmlListProperty<Component> *property, int index);
//    static void clear_compList(QQmlListProperty<Component> *property);

public:
    explicit Network(QQuickItem *parent = 0);
    ~Network();

    virtual void childItemsChanged();

private:

    QList<Component *> m_compList;
};

} // namespace model
#endif // NETWORK_H
