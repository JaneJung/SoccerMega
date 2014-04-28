#include "gamepad.h"
#include "ui_gamepad.h"

GamePad::GamePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GamePad)
{
    ui->setupUi(this);

    ui->Right->setIcon(QIcon("R.PNG"));
    ui->Right->setIconSize(QSize(120,130));


    ui->Left->setIcon(QIcon("L.PNG"));
    ui->Left->setIconSize(QSize(120,130));

    ui->Up->setIcon(QIcon("U.PNG"));
    ui->Up->setIconSize(QSize(120,130));

    ui->Down->setIcon(QIcon("D.PNG"));
    ui->Down->setIconSize(QSize(120,130));
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
