#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <string>
#include <stdio.h>

#include <QPixmap>
#include <QLabel>

#define PLAY_TIME   3

#define BT_IMG_WIDTH    222
#define BT_IMG_HEIGHT   300
#define CASE_TIME       5

#define MUSIC_FOLDER "/root/music/"

 scoreboard * scoreboard::pInstance = NULL;

enum effct{    //audio
    StartGame,
    Stadium,
    EndGame,
    Goal,
};



scoreboard::scoreboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scoreboard)
{

    ui->setupUi(this);
    this->showFullScreen();
    ui->centralWidget->setStyleSheet("background-image:url(/root/img_SubScore_bg.png)");


    ui->bt_StartGame->setIcon(QIcon("/root/img_SubScore_but.png"));
    ui->bt_StartGame->setIconSize(QSize(220,90));

    ui->bt_Mute->setIcon(QIcon("/root/img_SubScore_Mute.png"));
    ui->bt_Mute->setIconSize(QSize(70,70));

    ui->lcdNumber_Min->setStyleSheet("*{color:white}");
    ui->lcdNumber_Sec->setStyleSheet("*{color:white}");
    ui->lcdNumber_mSec->setStyleSheet("*{color:white}");


    ui->pt_ScoreD->setIcon(QIcon("/root/img_SubScore_col.png"));
    ui->pt_ScoreD->setIconSize(QSize(40,142));

    timer   = new QTimer(this);
    bTimer  = false;

    addMsec = 0;

    QObject::connect(timer, SIGNAL(timeout()), SLOT(clockTimer()));



    _score_Left     = 0;
    _score_Right    = 0;
    _game_Time      = 0;

    AudioInit();
    on_bt_Score_Left_pressed();
    on_bt_Score_Right_pressed();
    set_label_Time(_game_Time);

    PlayAudio(StartGame);

    worker = new Worker();
}
//-----------------------------------------------------

scoreboard::~scoreboard()
{
    delete ui;
    delete worker;
    delete myProcess;
}
//-----------------------------------------------------

void scoreboard::setLabels(void)
{

    int time_arr[4];
    int min_tmp     = 0;

    if(addMsec != 0)
    {
        time_arr[0] = (int)( addMsec / 36000 );
        min_tmp     = addMsec - time_arr[0] * 36000;

        time_arr[1] = (int)( min_tmp / 600  );
        time_arr[2] = (int)( min_tmp - time_arr[1] * 600) / 10;


        if (time_arr[0] == PLAY_TIME ) {

            timer->stop();
            time_arr[1] = 0;
            time_arr[2] = 0;
            set_label_Time(++_game_Time);

            ui->lcdNumber_Min->display(  time_arr[0] );
            ui->lcdNumber_Sec->display(  0 );
            ui->lcdNumber_mSec->display( 0 );
            PlayAudio(EndGame);
            return;
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

void scoreboard::on_bt_Score_Left_pressed()
{

    qDebug() << " left score";

    switch(_score_Left) {
        case 0:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_0.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 1:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_1.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 2:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_2.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 3:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_3.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 4:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_4.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 5:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_5.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 6:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_6.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 7:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_7.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 8:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_8.png"));
                ui->bt_Score_Left->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 9:
                ui->bt_Score_Left->setIcon(QIcon("/root/img_num_9.png"));
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

    qDebug() << " rightt score";
    switch(_score_Right) {
        case 0:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_0.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 1:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_1.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 2:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_2.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 3:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_3.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 4:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_4.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 5:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_5.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 6:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_6.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 7:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_7.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 8:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_8.png"));
                ui->bt_Score_Right->setIconSize(QSize(BT_IMG_WIDTH,BT_IMG_HEIGHT));
                break;
        case 9:
                ui->bt_Score_Right->setIcon(QIcon("/root/img_num_9.png"));
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
    program = "/root/madplay";

    audioFlag = 1;
    AudioPlayList << "start_music3.mp3" <<"stadium.mp3" << "goal2.mp3" << "goal.mp3";
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
    qDebug() << "Play Audio : " << m;
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
    else if(m == Goal)
    {
         arguments << MUSIC_FOLDER + AudioPlayList.at(AudioPlayListPointer);
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

void scoreboard::on_bt_StartGame_clicked()
{
    // reset and start
    // initializegame score

    if ( bTimer == false ) {
        clockReset();
        if( _game_Time == CASE_TIME-1) {

            _game_Time = 1;
        }
        set_label_Time(++_game_Time);

        clockStart();
     }
     PlayAudio(Stadium);

}

void scoreboard::set_label_Time(int game_Time) {

    switch( game_Time ) {
        case 0:
                ui->Edit_Time->setText("Prepare...");
                bTimer = false;
                break;
        case 1:
                ui->Edit_Time->setText("First Half");
                bTimer = true;
                break;
        case 2:
                ui->Edit_Time->setText("Rest Time");
                bTimer = false;
                break;
        case 3:
                ui->Edit_Time->setText("Second Half");
                bTimer = true;
                break;
        case 4:
                ui->Edit_Time->setText("Set Game");
                bTimer = false;
                break;
        default:
                ui->Edit_Time->setText("");
                bTimer = true;
                break;
    }
}

void scoreboard::on_bt_Mute_clicked()
{
    StopAudio();
}
