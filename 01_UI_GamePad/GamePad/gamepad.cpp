#include "gamepad.h"
#include "ui_gamepad.h"

GamePad::GamePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GamePad)
{
    ui->setupUi(this);

  //  mediaObject.setCurrentSource(Phonon::MediaSource("196461__paulw2k__football-crowd-goal.wav"));
   // mediaObject.play();
}

GamePad::~GamePad()
{
    delete ui;
}

void GamePad::Right()
{
    ui->button_check->setText("Right");
    printf("Right");

}

void GamePad::Up()
{
    ui->button_check->setText("Up");
    printf("Up");

}

void GamePad::Left()
{
    ui->button_check->setText("Left");
    printf("Left");

}

void GamePad::Down()
{
    ui->button_check->setText("DoWn");
    printf("Down");

}
