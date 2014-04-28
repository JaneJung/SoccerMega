#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QIcon>

namespace Ui {

    class GamePad;
}

class GamePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit GamePad(QWidget *parent = 0);
    ~GamePad();

private slots:

    void on_bt_UP_clicked();

    void on_bt_UP_LEFT_pressed();

    void on_bt_UP_RIGHT_pressed();



    void on_bt_DOWN_pressed();

    void on_bt_DOWN_LEFT_pressed();

    void on_bt_DOWN_RIGHT_pressed();



    int  set_BT_Initialize(void);

    void on_bt_STOP_pressed();

    void on_bt_UP_pressed();

private:
    Ui::GamePad *ui;

public:

    int fd;
};


enum DIRECTION {

    eUPLEFT = 0x61, eUP, eUPRIGHT, eDOWNLEFT, eDOWN, eDOWNRIGHT, eSTOP
};

#endif // GAMEPAD_H
