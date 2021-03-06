#include "gamepad.h"
#include "ui_gamepad.h"


/////////////////////////
#include <stdio.h>

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <linux/fb.h>
#include <string.h>
#include <errno.h>

#include <signal.h>

#define BLUETOOTH_DEV   "/dev/ttyUSB0"
#define BAUDRATE        9600

#define MSG_CARR        0xa
#define MSG_BIT         1


GamePad::GamePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GamePad)
{

    ui->setupUi(this);
    this->showFullScreen();

//    ui->centralWidget->setStyleSheet("background-image:url(img_main.png)");

    ui->GB_Background->setStyleSheet("background-image:url(img_main.png)");
    bool iConnect = false;
    iConnect = set_BT_Initialize();
    if ( iConnect != true ) {

//        QMessageBox(this, "ERROR", "Open Device File");
    }

    ui->bt_UP->setIcon(QIcon("img_arrow_up.png"));
    ui->bt_UP->setIconSize(QSize(120,130));

    ui->bt_UP_LEFT->setIcon(QIcon("img_arrow_upleft.png"));
    ui->bt_UP_LEFT->setIconSize(QSize(120,130));

    ui->bt_UP_RIGHT->setIcon(QIcon("img_arrow_upright.png"));
    ui->bt_UP_RIGHT->setIconSize(QSize(120,130));

    ui->bt_DOWN_LEFT->setIcon(QIcon("img_arrow_downleft.png"));
    ui->bt_DOWN_LEFT->setIconSize(QSize(120,130));

    ui->bt_DOWN_RIGHT->setIcon(QIcon("img_arrow_downright.png"));
    ui->bt_DOWN_RIGHT->setIconSize(QSize(120,130));


    ui->bt_DOWN->setIcon(QIcon("img_arrow_down.png"));
    ui->bt_DOWN->setIconSize(QSize(120,130));



    ui->bt_STOP->setIcon(QIcon("img_stop.png"));
    ui->bt_STOP->setIconSize(QSize(220,130));

    ui->bt_GOAL->setIcon(QIcon("img_goal.png"));
    ui->bt_GOAL->setIconSize(QSize(220,80));

    ui->edit_PlayerInfo->setFontPointSize(25);
    ui->edit_PlayerInfo->insertPlainText("Player 1");


}
//-----------------------------------------------------

GamePad::~GamePad()
{
    delete ui;
}
//-----------------------------------------------------

void GamePad::on_bt_UP_LEFT_pressed()
{

    char sigDataSend    = (char)eUPLEFT;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_bt_UP_pressed()
{

    char sigDataSend    = (char)eUP;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_bt_UP_RIGHT_pressed()
{

    char sigDataSend    = (char)eUPRIGHT;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_bt_DOWN_LEFT_pressed()
{

    char sigDataSend    = (char)eDOWNLEFT;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_bt_DOWN_pressed()
{

    char sigDataSend    = (char)eDOWN;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_bt_DOWN_RIGHT_pressed()
{

    char sigDataSend    = (char)eDOWNRIGHT;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_bt_STOP_pressed()
{

    char sigDataSend    = (char)eSTOP;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------


int GamePad::set_BT_Initialize(void)
{

    fflush(stdin);
    struct termios options;

    signal(SIGIO, SIG_IGN);

    fd = ::open(BLUETOOTH_DEV, O_RDWR | O_NOCTTY );
    if( fd < 0 ) {

  //      QMessageBox::information( this,"ERROR", "open error");
        return -1;
    }

    fcntl(fd, F_SETFL);                     // Configure port reading
    tcgetattr(fd, &options);                // Get the current options for the port
    cfsetispeed(&options, B9600);           // Set the baud rates to 230400
    cfsetospeed(&options, B9600);

    options.c_cflag |= (CLOCAL | CREAD);    // Enable the receiver and set local mode
    options.c_cflag &= ~PARENB;             // No parity bit
    options.c_cflag &= ~CSTOPB;             // 1 stop bit
    options.c_cflag &= ~CSIZE;              // Mask data size
    options.c_cflag |=  CS8;                // Select 8 data bits
    options.c_cflag &= ~CRTSCTS;            // Disable hardware flow control

    // Enable data to be processed as raw input
    options.c_lflag &= ~(ICANON | ECHO | ISIG);

    // Set the new attributes
    tcsetattr(fd, TCSANOW, &options);

    return 0;
}
//-----------------------------------------------------



void GamePad::on_bt_GOAL_clicked()
{

    char sigDataSend    = (char)eCEREMONY;

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdout);

    ui->lcdNumber->display(sigDataSend);

    on_bt_UP_pressed();
    usleep(200000);
    on_bt_DOWN_pressed();
    usleep(200000);
    on_bt_UP_pressed();
    usleep(200000);
    on_bt_DOWN_pressed();
    usleep(200000);
    on_bt_UP_pressed();
    usleep(200000);

    on_bt_UP_RIGHT_pressed();
    usleep(250000);
    on_bt_UP_LEFT_pressed();
    usleep(250000);
    on_bt_UP_RIGHT_pressed();
    usleep(250000);
    on_bt_UP_LEFT_pressed();
    usleep(250000);
    on_bt_UP_RIGHT_pressed();
    usleep(250000);

    on_bt_DOWN_RIGHT_pressed();
    usleep(250000);
    on_bt_DOWN_LEFT_pressed();
    usleep(250000);
    on_bt_DOWN_RIGHT_pressed();
    usleep(250000);
    on_bt_DOWN_LEFT_pressed();
    usleep(250000);


    on_bt_STOP_pressed();
}
