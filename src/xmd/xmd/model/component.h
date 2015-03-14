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

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QQuickItem>
#include <QQmlParserStatus>
#include <QQmlListProperty>

#include "xmas.h"
#include "port.h"

/**
 * @brief The Component class
 *
 * A wrapper around XMASComponent from xmas.h to connect to
 * Qml using properties.
 */

namespace model
{
class Component : public QQuickItem //, public QQmlParserStatus
{
public:
    enum Orientation {
        North = 0,
        East = 90,
        South = 180,
        West = 270,
        NorthWest = 45,
        SouthWest = 225,
        NorthEast = 315,
        SouthEast = 135
    };
    enum CompType {Unknown=0, Source, Sink, Function, Queue, Join, Merge, Switch, Fork, In, Out, Composite};

private:
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_ENUMS(Orientation)
    Q_ENUMS(CompType)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(CompType type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QVariant expression READ getExpression WRITE setExpression NOTIFY expressionChanged)
    Q_PROPERTY(bool validExpr READ getValidExpr WRITE setValidExpr NOTIFY validExprChanged)
    Q_PROPERTY(bool valid READ getValid WRITE setValid NOTIFY validChanged)

    //###################################################################################################
    //TODO : to be reviewed with Guus
    Q_PROPERTY(QQmlListProperty<XPort> ports READ getPorts)
    //###################################################################################################
public:
    explicit Component(QQuickItem *parent = 0);
    ~Component();

signals:
    void nameChanged(int result);
    void typeChanged();
    void expressionChanged(int result);
    void validChanged();
    void validExprChanged(int errorPosition, QString errMsg);
    void changeName(QString old_name, QString name);
    void writeLog(QString message, QColor color = Qt::blue);

public slots:

public:

    virtual void classBegin();
    virtual void componentComplete();

    CompType getType() const {return m_type;}
    void setType(CompType type) {
        m_type = type;
        emit typeChanged();
    }

    QString getName() {
        return m_name;
    }

    void setName(QString name) {
        if (name != m_name) {
            m_name = name;
            if (m_component) {
                m_component->name(name.toStdString());
            }
        }
        int result = checkName(name);
        emit nameChanged(result);
    }

    // TODO: find out how to store specifications
    QVariant getExpression() {
        return m_expression;
    }

    void setExpression(QVariant expression) {
        int errorPosition = -1;
        errorPosition = updateExpression(expression);
        emit expressionChanged(errorPosition);
    }

    int updateExpression(QVariant expression);

    bool getValidExpr() {
        return m_validExpr;
    }

    void setValidExpr(bool validExpr) {
        m_validExpr = validExpr;
        emit validExprChanged(-1, QString(""));
    }

    void setValidExpr(bool validExpr, int pos, QString errMsg) {
        m_validExpr = validExpr;
        emit validExprChanged(pos, errMsg);
    }

    bool getValid() {
        return m_valid;
    }

    void setValid(bool valid) {
        m_valid = valid;
        emit validChanged();
	}

    //###################################################################################################
    //TODO : to be reviewed with Guus
    QQmlListProperty<XPort> getPorts();
    //###################################################################################################

private:
    XMASComponent *createComponent(CompType type, QString name);
    int checkName(QString name);

    //###################################################################################################
    //TODO : to be reviewed with Guus
    static void append_port(QQmlListProperty<XPort> *list, XPort *port);
    void extractPorts(void);

    //###################################################################################################

public:
private:
    QString m_name;
    QVariant m_expression;
    CompType m_type;
    bool m_valid;
    bool m_validExpr;
    XMASComponent *m_component;
    //###################################################################################################
    //TODO : to be reviewed with Guus
    QList<XPort *> m_ports;
    //###################################################################################################

    bitpowder::lib::MemoryPool m_mp;
};

} // namespace model

#endif // COMPONENT_H
