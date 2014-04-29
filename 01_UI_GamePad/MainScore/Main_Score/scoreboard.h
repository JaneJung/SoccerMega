#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>
#include <QLCDNumber>

#include <QIcon>

#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QProcess> //audio
#include <QDebug>  //audio

#include <QThread>
#include "worker.h"


namespace Ui {
class scoreboard;
}

class scoreboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit scoreboard(QWidget *parent = 0);
    ~scoreboard();

    void setLabels();

    QTimer *timer;
    QTime time;
    unsigned int addMsec;

    /*audio*/
    QString program;
    QStringList arguments;
    QProcess *myProcess;
    int audioFlag;
    QStringList AudioPlayList;
    int AudioPlayListPointer;

private:
    Ui::scoreboard *ui;
    QThread *thread;
    Worker *worker;
    static scoreboard * pInstance;

private slots:

    void on_bt_Stop_clicked();
    void on_bt_Start_clicked();
    void on_bt_Reset_clicked();

public slots:
    void clockTimer();
    void clockStart();
    void clockStop();
    void clockReset();
    void on_bt_Score_Left_pressed();
    void on_bt_Score_Right_pressed();


public:
    int _score_Left;
    int _score_Right;
    /*audio*/
    void AudioInit(void);
    void PlayAudio(void);
    void StopAudio(void);
    void PlayAudio(int m);
    void PlayAudioToggle(int m);

    static scoreboard* getInstancePtr()
     {
      if(pInstance == NULL)
          pInstance = new scoreboard;
       return pInstance;
     };


};

#endif // SCOREBOARD_H
