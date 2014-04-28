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

    bool iConnect = false;
    iConnect = set_BT_Initialize();
    if ( iConnect != true ) {

//        QMessageBox(this, "ERROR", "Open Device File");
    }
}
//-----------------------------------------------------

GamePad::~GamePad()
{
    delete ui;
}
//-----------------------------------------------------

void GamePad::on_BT_Left_clicked()
{

  /*  char sigDataSend    = (char)eLEFT;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);


    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);*/

 /*   while( sigDataRecv != MSG_CARR ) {

        (void)read(fd, &sigDataRecv, MSG_BIT);
    }*/
}
//-----------------------------------------------------

void GamePad::on_BT_Right_clicked()
{

    char sigDataSend    = (char)eRIGHT;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);


    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);

/*    while( sigDataRecv != MSG_CARR ) {

        (void)read(fd, &sigDataRecv, MSG_BIT);
    }*/
    ui->lcdNumber->display(sigDataSend);
}
//-----------------------------------------------------

void GamePad::on_BT_UP_clicked()
{

    char sigDataSend    = (char)eUP;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);


    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);

 /*   while( sigDataRecv != MSG_CARR ) {

        (void)read(fd, &sigDataRecv, MSG_BIT);
    }*/
}
//-----------------------------------------------------

void GamePad::on_BT_Down_clicked()
{

/*    char sigDataSend    = (char)eDOWN;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);*/

  /*  while( sigDataRecv != MSG_CARR ) {

        (void)read(fd, &sigDataRecv, MSG_BIT);
    }*/

}
//-----------------------------------------------------

void GamePad::on_BT_Stop_clicked()
{

    char sigDataSend    = (char)eSTOP;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);


    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);

  /*  while( sigDataRecv != MSG_CARR ) {

        (void)read(fd, &sigDataRecv, MSG_BIT);
    }*/
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
    ui->lcdNumber->display(fd);

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

void GamePad::on_BT_Left_pressed()
{

    char sigDataSend    = (char)eLEFT;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);


    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);
}

void GamePad::on_BT_Down_pressed()
{

    char sigDataSend    = (char)eDOWN;
    char sigDataRecv    = -1;

    ui->lcdNumber->display(sigDataSend);

    (void)write(fd, &sigDataSend, MSG_BIT);
    fflush(stdin);
}
