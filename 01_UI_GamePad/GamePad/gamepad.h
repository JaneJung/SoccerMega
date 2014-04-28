#ifndef GAMEPAD_H
#define GAMEPAD_H
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <stdio.h>

/*
#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <phonon/mediasource.h>
#include <phonon/videowidget.h>
*/

//using namespace Phonon;

namespace Ui {
class GamePad;
}

class GamePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit GamePad(QWidget *parent = 0);
    ~GamePad();

private:
    Ui::GamePad *ui;
    QLabel * button_check;
    //Phonon::MediaObject mediaObject;
    QPixmap pm;



private slots:
    void Down();
    void Up();
    void Left();
    void Right();
};

#endif // GAMEPAD_H