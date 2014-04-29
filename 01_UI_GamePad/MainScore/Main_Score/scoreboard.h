#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QMessageBox>

#include <QIcon>

#include <QLabel>
#include <QTimer>
#include <QTime>

#include <QImage>              //QImage를 사용하기 위한 라이브러리

#include <QPixmap>             //QPixmap를 사용하기 위한 라이브러리






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

private:
    Ui::scoreboard *ui;

private slots:

    void on_bt_Stop_clicked();
    void on_bt_Start_clicked();
    void on_bt_Reset_clicked();

    void on_bt_Score_Left_pressed();
    void on_bt_Score_Right_pressed();

public slots:
    void clockTimer();
    void clockStart();
    void clockStop();
    void clockReset();

public:
    int _score_Left;
    int _score_Right;
    QImage *Img;
    QPixmap *buffer;

};

#endif // SCOREBOARD_H
