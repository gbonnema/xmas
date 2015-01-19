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

#ifndef PORT_H
#define PORT_H

#include <QObject>

namespace model {

class Port : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(QString rdy READ rdy WRITE rdy NOTIFY rdyChanged)
public:
    explicit Port(QObject *parent = 0);
    ~Port();

    Port(const Port &);

    Port &operator=(const Port &);

signals:
    void nameChanged();
    void rdyChanged();

public slots:

public:
    QString name() const { return m_name; }
    void name(QString &name) {m_name = name; }

    QString rdy() const { return m_rdy; }
    void rdy(QString &rdy) { m_rdy = rdy; }

private:

    /**
         * @brief m_name The name of the port, must be unique within Component
         */
    QString m_name;
    /**
         * @brief m_rdy The string indicating when this port is ready.
         *
         * Each component determines when each port is ready in terms of other
         * condition, like the ready statue of other ports, or the status of
         * certain functions.
         *
         * Example:
         *      i.trdy = o1.irdy | o2.irdy
         *      where i is the name of the input port and o1 and o2 are
         *      the names of the outputports of this component.
         *
         * Usage: the cycle checker uses this information.
         *
         */
    QString m_rdy;

};

} // namespace model

#endif // PORT_H