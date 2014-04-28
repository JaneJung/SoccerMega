#include "gamepad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GamePad w;
    w.show();

    return a.exec();
}
