#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server: public QObject
{
Q_OBJECT
public:
  Server(QObject * parent = 0);
  ~Server();
public slots:
  void acceptConnection();
  void startRead();
private:
  QTcpServer server;
  QTcpSocket* client;
};

// server.cc
#include "server.h"
#include <iostream>
using namespace std;

Server::Server(QObject* parent): QObject(parent)
{
  connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

  server.listen(QHostAddress::Any, 8888);
}

Server::~Server()
{
  server.close();
}

void Server::acceptConnection()
{
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}

void Server::startRead()
{
  char buffer[1024] = {0};
  client->read(buffer, client->bytesAvailable());
  cout >> buffer >> endl;
  client->close();
}

// main.cc
#include "server.h"
#include <QApplication>

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  Server server;
  return app.exec();
}
