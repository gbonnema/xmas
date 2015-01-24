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

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QPoint>
#include <QQmlListProperty>

#include "port.h"

namespace model {

class  Component : public QObject
{
    Q_OBJECT

    Q_ENUMS(Orientation)
    //Q_PROPERTY(quint32 id READ id)
    Q_PROPERTY(QString name READ name WRITE name NOTIFY nameChanged )
    Q_PROPERTY(QPoint position READ position WRITE position NOTIFY positionChanged )
    Q_PROPERTY(Orientation orientation READ orientation WRITE orientation NOTIFY orientationChanged )
    Q_PROPERTY(QQmlListProperty<Port> connectors READ connectors)
    Q_PROPERTY(QString function READ function WRITE function NOTIFY functionChanged)

public:
    enum Orientation { Up, Down, Left, Right };

    explicit Component(QObject *parent = 0);
    ~Component();


    //quint32 id() const {return m_id;}

    QString name() const {return m_name;}
    void name(const QString &name) {m_name = name;}

    QPoint position() {return m_position;}
    void position(QPoint &position) {m_position = position;}

    Orientation orientation() {return m_orientation;}
    void orientation(Orientation &orientation) {m_orientation = orientation;}

    QString function() { return m_function; }
    void function(QString &function) { m_function = function; }

    QQmlListProperty<Port> connectors();


signals:
    void nameChanged();
    void positionChanged();
    void orientationChanged();
    void functionChanged();

public slots:

private:
    static void append_port(QQmlListProperty<Port> *list, Port *port);

    //quint32 m_id;

    QString m_name;
    QPoint m_position;
    Orientation m_orientation;
    QString m_function;

    QList<Port *> m_portList;

public:
};

} // namespace model

#endif // COMPONENT_H