#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_BT_Left_clicked();

    void on_BT_UP_clicked();

    void on_BT_Right_clicked();

    void on_BT_Down_clicked();

    void on_BT_Stop_clicked();
    void on_BT_Left_pressed();


    int  set_BT_Initialize(void);



    void on_BT_Down_pressed();

private:
    Ui::GamePad *ui;

public:

    int fd;
};


enum DIRECTION {

    eLEFT = 0x61, eRIGHT, eUP, eDOWN, eSTOP
};

#endif // GAMEPAD_H
