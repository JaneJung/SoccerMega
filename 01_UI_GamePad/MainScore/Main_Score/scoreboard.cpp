#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <string>
#include <stdio.h>

#include <QFile>
#include <QDebug>

#define PLAY_TIME   3

#define BT_IMG_WIDTH    222
#define BT_IMG_HEIGHT   300


scoreboard::scoreboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scoreboard)
{

    ui->setupUi(this);
    this->showFullScreen();

    timer = new QTimer(this);

    addMsec = 0;

    QObject::connect(timer, SIGNAL(timeout()), SLOT(clockTimer()));



    _score_Left     = 0;
    _score_Right    = 0;
    on_bt_Score_Left_pressed();
    on_bt_Score_Right_pressed();

    Img = new QImage();       //이미지를 로드하기 위한 QImage 선언
    QPixmap *buffer = new QPixmap();  //버퍼로 사용할 QPixmap 선언


/*    if(Img->load("/mnt/nfsdir/img_0.png"))      //이미지를 로드한다.

{

        *buffer = QPixmap::fromImage(*Img);   //이미지를 버퍼에 옮긴다.

        *buffer = buffer->scaled(Img->width(),Img->height()); //이미지 사이즈 조절

    }

    else // 이미지 로드 실패

{

        QMessageBox::about(0, QString::fromAscii("Image load Error"),QString::fromAscii    ("Image load Error"));

    }*/




    QLabel *lbView = new QLabel(this); //이미지를 화면에 출력할 QLabel 선언

    //lbView->setPixmap(*buffer);       //버퍼에 있는 이미지를 QLabel에 출력
    lbView->setPixmap(QPixmap("img_0.png"));       //버퍼에 있는 이미지를 QLabel에 출력

    lbView->resize(buffer->width(),buffer->height()); //QLabel의 크기를 이미지 사이즈에 맞추어 조절한다.


    lbView->move(0,0);                //QLabel위치 조정

    lbView->show();                   //QLabel 를 보여준다.


}
//-----------------------------------------------------

scoreboard::~scoreboard()
{
    delete ui;
}
//-----------------------------------------------------

void scoreboard::setLabels(void)
{

    int time_arr[4];
    int min_tmp     = 0;

    if(addMsec != 0)
    {
        time_arr[0] = (int)( addMsec / 60000 );
        min_tmp     = addMsec - time_arr[0] * 60000;

        time_arr[1] = (int)( min_tmp / 1000  );
        time_arr[2] = (int)( min_tmp - time_arr[1] * 1000) / 10;


        if (time_arr[0] == PLAY_TIME) {

            timer->stop();
            time_arr[1] = 0;
            time_arr[2] = 0;
        }
        ui->lcdNumber_Min->display(  time_arr[0] );
        ui->lcdNumber_Sec->display(  time_arr[1] );
        ui->lcdNumber_mSec->display( time_arr[2] );
    }
}
//-----------------------------------------------------

void scoreboard::clockTimer()
{
    addMsec++;
    setLabels();
}
//-----------------------------------------------------

void scoreboard::clockStart(void)
{
    if( !(timer->isActive()) ) {

        timer->start(1);
    }
}
//-----------------------------------------------------

void scoreboard::clockStop()
{
    if( timer->isActive() ) {

        timer->stop();
    }
}
//-----------------------------------------------------

void scoreboard::clockReset()
{
    if( addMsec != 0 ) {

        addMsec = 0;
        setLabels();
        ui->lcdNumber_Min->display(  0 );
        ui->lcdNumber_Sec->display(  0 );
        ui->lcdNumber_mSec->display( 0 );
    }
}
//-----------------------------------------------------

void scoreboard::on_bt_Start_clicked()
{
    clockStart();
}
//-----------------------------------------------------

void scoreboard::on_bt_Stop_clicked()
{
    clockStop();
}
//-----------------------------------------------------

void scoreboard::on_bt_Reset_clicked()
{
    clockReset();
}
//-----------------------------------------------------

void scoreboard::on_bt_Score_Left_pressed()
{

    switch(_score_Left) {
        case 0:
                ui->bt_Score_Left->setIcon(QIcon("img_num_0.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 1:
                ui->bt_Score_Left->setIcon(QIcon("img_num_1.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 2:
                ui->bt_Score_Left->setIcon(QIcon("img_num_2.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 3:
                ui->bt_Score_Left->setIcon(QIcon("img_num_3.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 4:
                ui->bt_Score_Left->setIcon(QIcon("img_num_4.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 5:
                ui->bt_Score_Left->setIcon(QIcon("img_num_5.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 6:
                ui->bt_Score_Left->setIcon(QIcon("img_num_6.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 7:
                ui->bt_Score_Left->setIcon(QIcon("img_num_7.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 8:
                ui->bt_Score_Left->setIcon(QIcon("img_num_8.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 9:
                ui->bt_Score_Left->setIcon(QIcon("img_num_9.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
    }
    _score_Left++;
    if ( _score_Left == 10 )
        _score_Left = 0;
}
//-----------------------------------------------------

void scoreboard::on_bt_Score_Right_pressed()
{


    QFile testing("img_num_0.jpg");
    qDebug() << testing.exists();
    switch(_score_Right) {
        case 0:
                ui->bt_Score_Right->setIcon(QIcon("img_num_0.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 1:
                ui->bt_Score_Right->setIcon(QIcon("img_num_1.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 2:
                ui->bt_Score_Right->setIcon(QIcon("img_num_2.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 3:
                ui->bt_Score_Right->setIcon(QIcon("img_num_3.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 4:
                ui->bt_Score_Right->setIcon(QIcon("img_num_4.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 5:
                ui->bt_Score_Right->setIcon(QIcon("img_num_5.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 6:
                ui->bt_Score_Right->setIcon(QIcon("img_num_6.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 7:
                ui->bt_Score_Right->setIcon(QIcon("img_num_7.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 8:
                ui->bt_Score_Right->setIcon(QIcon("img_num_8.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 9:
                ui->bt_Score_Right->setIcon(QIcon("img_num_9.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
    }
    _score_Right++;
    if ( _score_Right == 10 )
        _score_Right = 0;
}
//-----------------------------------------------------
