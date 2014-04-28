#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <string>
#include <stdio.h>

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
