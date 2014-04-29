#include "scoreboard.h"
#include <QApplication>
#include <QWSServer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    scoreboard w;
    w.show();
    QWSServer::setCursorVisible(FALSE);

    return a.exec();
}
