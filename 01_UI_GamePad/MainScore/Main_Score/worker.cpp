/*
   Copyright 2013 Fabien Pierre-Nicolas.
      - Primarily authored by Fabien Pierre-Nicolas

   This file is part of simple-qt-thread-example, a simple example to demonstrate how to use threads.
   This example is explained on http://fabienpn.wordpress.com/qt-thread-simple-and-stable-with-sources/

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This progra is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "worker.h"
#include <QTimer>
#include <QEventLoop>

#include <QThread>
#include <QDebug>
#include <string.h>
#include <QByteArray>
#include "scoreboard.h"




Worker::Worker(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 8282))
    {
            qDebug() << "Server could not start";
    }
    else
    {
            qDebug() << "Server started!";
    }

}

Worker::~Worker()
{
  server->close();
  delete server;
  //delete socket;
}

void Worker::newConnection()
{
     qDebug() << "newConnection started!";
    // need to grab the socket
    socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::QueuedConnection);

}

void Worker::onReadyRead() {
    QByteArray buffer("");

    qDebug() << "read function";
    buffer.append(socket->readAll());
    if (buffer.count() == 3) {
        scoreboard sb;
        if (buffer.at(2) == 'a') {
            qDebug() << "A Board";
            //connect(this, SIGNAL(updateScore()),&sb, SLOT(on_bt_Score_Left_pressed()));
            //emit updateScore();
            scoreboard::getInstancePtr()->on_bt_Score_Left_pressed();
            sleep(5);
            qDebug() << "A updateScore";
        } else if (buffer.at(2) == 'b'){

            qDebug() << "B Board";
            //connect(this, SIGNAL(updateScore()),&sb, SLOT(on_bt_Score_Right_pressed()));
            //emit updateScore();
            scoreboard::getInstancePtr()->on_bt_Score_Right_pressed();
            sleep(5);
            qDebug() << "B updateScore";
            //scoreboard::on_bt_Score_Right_pressed();
        }
    }
    qDebug() << buffer;
    qDebug() << buffer.count();
    socket->close();
}
