#include "subscore.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    subscore w;
    w.show();

    return a.exec();
}
