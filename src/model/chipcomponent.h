/*********************************************************************
  *
  * Copyright (C) Guus Bonnema, 2014
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

#ifndef CHIPCOMPONENT_H
#define CHIPCOMPONENT_H

#include <QObject>
#include <QPoint>
#include <QQmlListProperty>

#include "port.h"

namespace model {

class Network;

// TODO: Could we use parent to check relationships? How to check types? --> virtual isInport / isOutport

/**
 * @brief The ChipComponent class
 *
 * The ChipComponent on a network. It contains ports (both
 * in ports and out ports).
 *
 * Ports are tightly coupled with ChipComponents: no existance outside components.
 * For that reason ports are an integral part of chipcomponents.
 *
 */
class  ChipComponent : public QObject
{
    Q_OBJECT

    Q_ENUMS(Orientation)
    Q_PROPERTY(model::Network *network READ network WRITE network NOTIFY networkChanged)
    Q_PROPERTY(QString name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(int x READ x WRITE x NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE y NOTIFY yChanged)
    Q_PROPERTY(Orientation orientation READ orientation WRITE orientation NOTIFY orientationChanged)
    Q_PROPERTY(QString func READ func WRITE func NOTIFY funcChanged)
    Q_PROPERTY(QQmlListProperty<model::Port> connectors READ connectors NOTIFY connectorsChanged)

    // TODO: We need InPort and OutPort

public:
    enum Orientation { Up, Down, Left, Right };

    explicit ChipComponent(QObject *parent = 0);
    ~ChipComponent();

    QString name() const {return m_name;}
    void name(const QString &name) {
        m_name = name;
        emit nameChanged();
    }

    Network *network() const { return m_network; }
    void network(Network *network);

    int x() { return m_x; }
    void x(int &x) {
        m_x = x;
        emit xChanged();
    }

    int y() { return m_y; }
    void y(int &y) {
        m_y = y;
        emit yChanged();
    }

    Orientation orientation() {return m_orientation;}
    void orientation(Orientation &orientation) {
        m_orientation = orientation;
        emit orientationChanged();
    }

    QString func() { return m_func; }
    void func(QString &func) {
        m_func = func;
        emit funcChanged();
    }

    QQmlListProperty<Port> connectors();

    Port *at(const int index) { return m_portList[index]; }

    int count_connectors() {
        return m_portList.size();
    }

    Port *port(QString name) {
        foreach (Port *p, m_portList) {
            if (p->name() == name) {
                return p;
            }
        }
    }

    Inport *inport(QString name) {
        foreach(Port *p, m_portList) {
            auto q = qobject_cast<Inport *>(p);
            if ( q && q->name() == name) {
                return q;
            }
        }
    }

    Outport *outport(QString name) {
        foreach(Port *p, m_portList) {
            auto q = qobject_cast<Outport *>(p);
            if ( q && q->name() == name) {
                return q;
            }
        }
    }

signals:
    void nameChanged();
    void networkChanged();
    void xChanged();
    void yChanged();
    void orientationChanged();
    void funcChanged();
    void connectorsChanged();

public slots:

private:

    static void append_port_list(QQmlListProperty<Port> *property, Port *port);
    static int count_port_list(QQmlListProperty<Port> *property);
    static Port *at_port_list(QQmlListProperty<Port> *property, int index);
    static void clear_port_list(QQmlListProperty<Port> *property);

    QString m_name;
    Network *m_network;
    int m_x;
    int m_y;
    Orientation m_orientation;
    QString m_func;
    QList<Port *> m_portList;

public:
};

} // namespace model

#endif // CHIPCOMPONENT_H
