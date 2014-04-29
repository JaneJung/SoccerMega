#ifndef SUBSCORE_H
#define SUBSCORE_H
#include <QTcpSocket>
#include <QHostAddress>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <QMainWindow>
#include <QIcon>

namespace Ui {
class subscore;
}
#include <QtNetwork>


class subscore : public QMainWindow
{
    Q_OBJECT

public:
    explicit subscore(QWidget *parent = 0);
    ~subscore();

private slots:

    void on_sendButton_clicked();

private:
    Ui::subscore *ui;



public:
    char _send_signal;

    QTcpSocket client;   //socket
    quint16 nextBlockSize;

    void start(void);



public slots:
    void startTransfer();

};

#endif // SUBSCORE_H
