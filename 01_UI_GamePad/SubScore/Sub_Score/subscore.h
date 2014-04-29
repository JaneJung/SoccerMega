#ifndef SUBSCORE_H
#define SUBSCORE_H

#include <QMainWindow>

namespace Ui {
class subscore;
}

class subscore : public QMainWindow
{
    Q_OBJECT

public:
    explicit subscore(QWidget *parent = 0);
    ~subscore();

private:
    Ui::subscore *ui;
};

#endif // SUBSCORE_H
