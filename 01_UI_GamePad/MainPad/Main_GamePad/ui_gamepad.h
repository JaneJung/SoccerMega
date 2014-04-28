/********************************************************************************
** Form generated from reading ui file 'gamepad.ui'
**
** Created: Mon Apr 28 14:41:59 2014
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
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePad
{
public:
    QWidget *centralWidget;
    QGroupBox *GB_Control;
    QPushButton *BT_UP;
    QPushButton *BT_Left;
    QPushButton *BT_Right;
    QPushButton *BT_Down;
    QPushButton *BT_Stop;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GamePad)
    {
        if (GamePad->objectName().isEmpty())
            GamePad->setObjectName(QString::fromUtf8("GamePad"));
        GamePad->resize(800, 480);
        centralWidget = new QWidget(GamePad);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GB_Control = new QGroupBox(centralWidget);
        GB_Control->setObjectName(QString::fromUtf8("GB_Control"));
        GB_Control->setGeometry(QRect(10, 10, 761, 401));
        GB_Control->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        BT_UP = new QPushButton(GB_Control);
        BT_UP->setObjectName(QString::fromUtf8("BT_UP"));
        BT_UP->setGeometry(QRect(160, 0, 130, 130));
        BT_Left = new QPushButton(GB_Control);
        BT_Left->setObjectName(QString::fromUtf8("BT_Left"));
        BT_Left->setGeometry(QRect(30, 130, 130, 130));
        BT_Right = new QPushButton(GB_Control);
        BT_Right->setObjectName(QString::fromUtf8("BT_Right"));
        BT_Right->setGeometry(QRect(290, 130, 130, 130));
        BT_Down = new QPushButton(GB_Control);
        BT_Down->setObjectName(QString::fromUtf8("BT_Down"));
        BT_Down->setGeometry(QRect(30, 250, 130, 130));
        BT_Stop = new QPushButton(GB_Control);
        BT_Stop->setObjectName(QString::fromUtf8("BT_Stop"));
        BT_Stop->setGeometry(QRect(490, 240, 130, 130));
        lcdNumber = new QLCDNumber(GB_Control);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(430, 30, 251, 91));
        GamePad->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GamePad);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        GamePad->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GamePad);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GamePad->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GamePad);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GamePad->setStatusBar(statusBar);

        retranslateUi(GamePad);

        QMetaObject::connectSlotsByName(GamePad);
    } // setupUi

    void retranslateUi(QMainWindow *GamePad)
    {
        GamePad->setWindowTitle(QApplication::translate("GamePad", "GamePad", 0, QApplication::UnicodeUTF8));
        GB_Control->setTitle(QApplication::translate("GamePad", "GroupBox", 0, QApplication::UnicodeUTF8));
        BT_UP->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        BT_Left->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        BT_Right->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        BT_Down->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        BT_Stop->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GamePad);
    } // retranslateUi

};

namespace Ui {
    class GamePad: public Ui_GamePad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAD_H
