#include "gamepad.h"
#include <QApplication>
#include <QPixmap>
#include <QWSServer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GamePad w;
    w.show();
    QWSServer::setCursorVisible(FALSE);

    return a.exec();

}
