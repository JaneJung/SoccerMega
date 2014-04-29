#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <string>
#include <stdio.h>

#include <QPixmap>
#include <QLabel>

#define PLAY_TIME   3

#define BT_IMG_WIDTH    222
#define BT_IMG_HEIGHT   300

#define MUSIC_FOLDER "./music/"

enum effct{    //audio
    StartGame,
    Stadium,
    EndGame,
    Stop
};

 scoreboard * scoreboard::pInstance = NULL;

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
    AudioInit();
    PlayAudioToggle(StartGame);

    //thread
    //thread = new QThread();
    worker = new Worker();
}
//-----------------------------------------------------

scoreboard::~scoreboard()
{
    delete ui;
    delete worker;
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
    PlayAudioToggle(Stadium);
}
//-----------------------------------------------------

void scoreboard::clockStop()
{
    if( timer->isActive() ) {
        timer->stop();

    }
    PlayAudioToggle(EndGame);
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
    //QString program2;
    //sprintf(program2, "img_num_%d.jpg", _score_Left);
    //ui->bt_Score_Left->setIcon(QIcon(program2));
    //ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));

    qDebug() << " left score";

    switch(_score_Left) {
        case 0:
                //QPixmap pix(":/img_num_1.jpg");
                //ui->label-setPixmap(&pix);
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_0.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 1:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_1.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 2:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_2.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 3:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_3.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 4:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_4.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 5:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_5.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 6:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_6.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 7:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_7.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 8:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_8.jpg"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 9:
                ui->bt_Score_Left->setIcon(QIcon("/mnt/nfsdir/img_num_9.jpg"));
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
    QString program1 = "/mnt/nfsdir/img_num_0.jpg";

     qDebug() << " rightt score";
    switch(_score_Right) {
        case 0:
                ui->bt_Score_Right->setIcon(QIcon(program1));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 1:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_1.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 2:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_2.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 3:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_3.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 4:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_4.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 5:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_5.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 6:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_6.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 7:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_7.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 8:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_8.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 9:
                ui->bt_Score_Right->setIcon(QIcon("/mnt/nfsdir/img_num_9.jpg"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
    }
    _score_Right++;
    if ( _score_Right == 10 )
        _score_Right = 0;
}
//-----------------------------------------------------
void scoreboard::AudioInit()
{
    program = "./madplay";

    audioFlag = 1;
    AudioPlayList << "start_music3.mp3" <<"stadium.mp3" << "goal2.mp3" << "gaol.mp3" << "start_music3.mp3";
    AudioPlayListPointer = 0;
    myProcess= new QProcess(this);
}
//-----------------------------------------------------
void scoreboard::PlayAudioToggle(int m)
{
    if(audioFlag == 1)
    {
        audioFlag = 0;
        PlayAudio(m);
    }
    else
    {
        audioFlag = 1;
        StopAudio();
    }
}
//-----------------------------------------------------
void scoreboard::PlayAudio(int m)
{
     this->AudioPlayListPointer  = m;
    arguments.clear();

    if(m == StartGame)
    {
        arguments << MUSIC_FOLDER + AudioPlayList.at(AudioPlayListPointer);
    }
    else if(m == Stadium)
    {
        arguments << MUSIC_FOLDER + AudioPlayList.at(AudioPlayListPointer) << "-r";
    }
    else if(m == EndGame)
    {
         arguments << "-s" << "00:00:04"<< "-t" << "00:00:03"<< MUSIC_FOLDER + AudioPlayList.at(AudioPlayListPointer);
    }

    myProcess->start(program, arguments);
}

//-----------------------------------------------------
void scoreboard::StopAudio()
{
    arguments.clear();
    myProcess->kill();
}
//-----------------------------------------------------
