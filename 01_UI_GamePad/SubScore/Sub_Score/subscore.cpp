#include "subscore.h"
#include "ui_subscore.h"

#define BACKLOG     10
#define SERV_PORT	8282
#define MAXLINE     8192


//#define Board26
#define SubScore26   0x51
#define Board03
#define SubScore03   0x41
//#define SubScore3    0x41

#define SERVER_ADDR "192.168.0.23"

subscore::subscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::subscore)
{
    ui->setupUi(this);
    this->showFullScreen();

    ui->sendButton->setIcon(QIcon("img_score_mang.png"));
    ui->sendButton->setIconSize(QSize(800,480));
#ifdef Board26
    _send_signal = SubScore26;

#endif
#ifdef Board03
    _send_signal = SubScore03;
#endif

}

subscore::~subscore()
{
    delete ui;
}

void subscore::start()
{
    client.connectToHost(SERVER_ADDR, SERV_PORT);
}

void subscore::startTransfer()
{
#ifdef Board26
    QByteArray test("bda");
#endif
#ifdef Board03
    QByteArray test("bdb");
#endif

    client.write(test);
    test.clear();

}

void subscore::on_sendButton_clicked()
{
    start();
    usleep(100000);

    startTransfer();
    printf("send\n");
    //sleep(2);
}
