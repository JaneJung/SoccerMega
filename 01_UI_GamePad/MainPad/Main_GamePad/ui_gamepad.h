/********************************************************************************
** Form generated from reading ui file 'gamepad.ui'
**
** Created: Tue Apr 29 10:15:09 2014
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GAMEPAD_H
#define UI_GAMEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePad
{
public:
    QWidget *centralWidget;
    QGroupBox *GB_Control;
    QLCDNumber *lcdNumber;
    QPushButton *bt_UP;
    QPushButton *bt_UP_LEFT;
    QPushButton *bt_UP_RIGHT;
    QPushButton *bt_DOWN_LEFT;
    QPushButton *bt_DOWN_RIGHT;
    QPushButton *bt_DOWN;
    QPushButton *bt_STOP;
    QPushButton *pushButton;

    void setupUi(QMainWindow *GamePad)
    {
        if (GamePad->objectName().isEmpty())
            GamePad->setObjectName(QString::fromUtf8("GamePad"));
        GamePad->resize(800, 480);
        centralWidget = new QWidget(GamePad);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::BlankCursor));
        centralWidget->setAutoFillBackground(true);
        GB_Control = new QGroupBox(centralWidget);
        GB_Control->setObjectName(QString::fromUtf8("GB_Control"));
        GB_Control->setGeometry(QRect(10, 10, 780, 460));
        GB_Control->setAutoFillBackground(false);
        GB_Control->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lcdNumber = new QLCDNumber(GB_Control);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(450, 30, 251, 91));
        bt_UP = new QPushButton(GB_Control);
        bt_UP->setObjectName(QString::fromUtf8("bt_UP"));
        bt_UP->setGeometry(QRect(140, 50, 130, 130));
        bt_UP->setAutoFillBackground(true);
        bt_UP_LEFT = new QPushButton(GB_Control);
        bt_UP_LEFT->setObjectName(QString::fromUtf8("bt_UP_LEFT"));
        bt_UP_LEFT->setGeometry(QRect(10, 110, 130, 130));
        bt_UP_LEFT->setAutoFillBackground(true);
        bt_UP_RIGHT = new QPushButton(GB_Control);
        bt_UP_RIGHT->setObjectName(QString::fromUtf8("bt_UP_RIGHT"));
        bt_UP_RIGHT->setGeometry(QRect(270, 110, 130, 130));
        bt_UP_RIGHT->setAutoFillBackground(true);
        bt_DOWN_LEFT = new QPushButton(GB_Control);
        bt_DOWN_LEFT->setObjectName(QString::fromUtf8("bt_DOWN_LEFT"));
        bt_DOWN_LEFT->setGeometry(QRect(10, 240, 130, 130));
        bt_DOWN_LEFT->setAutoFillBackground(true);
        bt_DOWN_RIGHT = new QPushButton(GB_Control);
        bt_DOWN_RIGHT->setObjectName(QString::fromUtf8("bt_DOWN_RIGHT"));
        bt_DOWN_RIGHT->setGeometry(QRect(270, 240, 130, 130));
        bt_DOWN_RIGHT->setAutoFillBackground(true);
        bt_DOWN = new QPushButton(GB_Control);
        bt_DOWN->setObjectName(QString::fromUtf8("bt_DOWN"));
        bt_DOWN->setGeometry(QRect(140, 300, 130, 130));
        bt_DOWN->setAutoFillBackground(true);
        bt_STOP = new QPushButton(GB_Control);
        bt_STOP->setObjectName(QString::fromUtf8("bt_STOP"));
        bt_STOP->setGeometry(QRect(440, 290, 130, 130));
        pushButton = new QPushButton(GB_Control);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 200, 99, 27));
        GamePad->setCentralWidget(centralWidget);

        retranslateUi(GamePad);

        QMetaObject::connectSlotsByName(GamePad);
    } // setupUi

    void retranslateUi(QMainWindow *GamePad)
    {
        GamePad->setWindowTitle(QApplication::translate("GamePad", "GamePad", 0, QApplication::UnicodeUTF8));
        GB_Control->setTitle(QString());
        bt_UP->setText(QString());
        bt_UP_LEFT->setText(QString());
        bt_UP_RIGHT->setText(QString());
        bt_DOWN_LEFT->setText(QString());
        bt_DOWN_RIGHT->setText(QString());
        bt_DOWN->setText(QString());
        bt_STOP->setText(QString());
        pushButton->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GamePad);
    } // retranslateUi

};

namespace Ui {
    class GamePad: public Ui_GamePad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAD_H
