/********************************************************************************
** Form generated from reading ui file 'scoreboard.ui'
**
** Created: Tue Apr 29 01:59:49 2014
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SCOREBOARD_H
#define UI_SCOREBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scoreboard
{
public:
    QWidget *centralWidget;
    QPushButton *bt_Start;
    QPushButton *bt_Reset;
    QPushButton *bt_Stop;
    QGroupBox *groupBox;
    QLCDNumber *lcdNumber_mSec;
    QLCDNumber *lcdNumber_Sec;
    QLCDNumber *lcdNumber_Min;
    QPushButton *bt_Score_Right;
    QPushButton *bt_Score_Left;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *scoreboard)
    {
        if (scoreboard->objectName().isEmpty())
            scoreboard->setObjectName(QString::fromUtf8("scoreboard"));
        scoreboard->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scoreboard->sizePolicy().hasHeightForWidth());
        scoreboard->setSizePolicy(sizePolicy);
        scoreboard->setCursor(QCursor(Qt::SplitVCursor));
        scoreboard->setAutoFillBackground(false);
        centralWidget = new QWidget(scoreboard);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bt_Start = new QPushButton(centralWidget);
        bt_Start->setObjectName(QString::fromUtf8("bt_Start"));
        bt_Start->setGeometry(QRect(690, 0, 99, 27));
        bt_Reset = new QPushButton(centralWidget);
        bt_Reset->setObjectName(QString::fromUtf8("bt_Reset"));
        bt_Reset->setGeometry(QRect(690, 60, 99, 27));
        bt_Stop = new QPushButton(centralWidget);
        bt_Stop->setObjectName(QString::fromUtf8("bt_Stop"));
        bt_Stop->setGeometry(QRect(690, 30, 99, 27));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, -10, 671, 151));
        lcdNumber_mSec = new QLCDNumber(groupBox);
        lcdNumber_mSec->setObjectName(QString::fromUtf8("lcdNumber_mSec"));
        lcdNumber_mSec->setGeometry(QRect(350, 20, 150, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber_mSec->sizePolicy().hasHeightForWidth());
        lcdNumber_mSec->setSizePolicy(sizePolicy1);
        lcdNumber_mSec->setCursor(QCursor(Qt::BlankCursor));
        lcdNumber_mSec->setFrameShape(QFrame::NoFrame);
        lcdNumber_mSec->setSmallDecimalPoint(false);
        lcdNumber_mSec->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber_Sec = new QLCDNumber(groupBox);
        lcdNumber_Sec->setObjectName(QString::fromUtf8("lcdNumber_Sec"));
        lcdNumber_Sec->setGeometry(QRect(270, 20, 150, 100));
        sizePolicy1.setHeightForWidth(lcdNumber_Sec->sizePolicy().hasHeightForWidth());
        lcdNumber_Sec->setSizePolicy(sizePolicy1);
        lcdNumber_Sec->setCursor(QCursor(Qt::BlankCursor));
        lcdNumber_Sec->setFrameShape(QFrame::NoFrame);
        lcdNumber_Sec->setSmallDecimalPoint(false);
        lcdNumber_Sec->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber_Min = new QLCDNumber(groupBox);
        lcdNumber_Min->setObjectName(QString::fromUtf8("lcdNumber_Min"));
        lcdNumber_Min->setGeometry(QRect(180, 20, 150, 100));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(lcdNumber_Min->sizePolicy().hasHeightForWidth());
        lcdNumber_Min->setSizePolicy(sizePolicy2);
        lcdNumber_Min->setCursor(QCursor(Qt::BlankCursor));
        lcdNumber_Min->setFrameShape(QFrame::NoFrame);
        lcdNumber_Min->setSmallDecimalPoint(false);
        lcdNumber_Min->setSegmentStyle(QLCDNumber::Filled);
        bt_Score_Right = new QPushButton(centralWidget);
        bt_Score_Right->setObjectName(QString::fromUtf8("bt_Score_Right"));
        bt_Score_Right->setGeometry(QRect(450, 90, 222, 300));
        bt_Score_Left = new QPushButton(centralWidget);
        bt_Score_Left->setObjectName(QString::fromUtf8("bt_Score_Left"));
        bt_Score_Left->setGeometry(QRect(120, 100, 222, 300));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 351, 401));
        label->setPixmap(QPixmap(QString::fromUtf8(":/hi/hi.png")));
        scoreboard->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(scoreboard);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        scoreboard->setMenuBar(menuBar);
        mainToolBar = new QToolBar(scoreboard);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        scoreboard->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(scoreboard);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        scoreboard->setStatusBar(statusBar);

        retranslateUi(scoreboard);

        QMetaObject::connectSlotsByName(scoreboard);
    } // setupUi

    void retranslateUi(QMainWindow *scoreboard)
    {
        scoreboard->setWindowTitle(QApplication::translate("scoreboard", "scoreboard", 0, QApplication::UnicodeUTF8));
        bt_Start->setText(QApplication::translate("scoreboard", "start", 0, QApplication::UnicodeUTF8));
        bt_Reset->setText(QApplication::translate("scoreboard", "reset", 0, QApplication::UnicodeUTF8));
        bt_Stop->setText(QApplication::translate("scoreboard", "stop", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        bt_Score_Right->setText(QString());
        bt_Score_Left->setText(QString());
        label->setText(QString());
        Q_UNUSED(scoreboard);
    } // retranslateUi

};

namespace Ui {
    class scoreboard: public Ui_scoreboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARD_H
