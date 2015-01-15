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

#include "component.h"
#include "connector.h"

/**
 * @brief Component::Component
 */
Component::Component(QQuickItem * parent): QQuickItem(parent),
    m_orientation(Up)
{
}

/**
 * @brief Component::~Component
 */
Component::~Component()
{

}


/**
 * @brief Component::connectors
 * @return
 */
QQmlListProperty<Connector> Component::connectors()
{
    return QQmlListProperty<Connector>(this, 0,
                                               &Component::append_connector,
                                               0,
                                               0,
                                               0);
}

/**
 * @brief Component::append_connector
 * @param list
 * @param connector
 */
void Component::append_connector(QQmlListProperty<Connector> *list, Connector *connector)
{
    Component *component = qobject_cast<Component *>(list->object);
    if (component) {
        connector->setParentItem(component);
        component->m_connectors.append(connector);
    }
}



