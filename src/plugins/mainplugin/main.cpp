/*********************************************************************
  *
  * Copyright (C) Guus Bonnema, 2015
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

#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "argc = " << argc << ", argv = '" << *argv << "'" << std::endl;

    std::cout << "Thanks for deploying the most recently developed plugins." << std::endl;
    std::cout << "******* Program finishes ********************************" << std::endl;
    exit(0);

//    QCoreApplication app(argc, argv);
//    QCoreApplication::setApplicationName("plugin-main-program");
//    QCoreApplication::setApplicationVersion("1.0");

//    return app.exec();
}