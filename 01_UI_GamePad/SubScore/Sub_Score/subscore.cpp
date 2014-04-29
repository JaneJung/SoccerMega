#include "subscore.h"
#include "ui_subscore.h"

subscore::subscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::subscore)
{
    ui->setupUi(this);
}

subscore::~subscore()
{
    delete ui;
}
