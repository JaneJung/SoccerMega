/********************************************************************************
** Form generated from reading ui file 'scoreboard.ui'
**
** Created: Wed Apr 30 01:19:49 2014
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
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scoreboard
{
public:
    QWidget *centralWidget;
    QGroupBox *GB_Timer;
    QLCDNumber *lcdNumber_mSec;
    QLCDNumber *lcdNumber_Sec;
    QLCDNumber *lcdNumber_Min;
    QLineEdit *Edit_Time;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *bt_Score_Left;
    QPushButton *bt_Score_Right;
    QPushButton *bt_StartGame;
    QPushButton *bt_Mute;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QPushButton *pt_ScoreD;

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
        scoreboard->setAutoFillBackground(true);
        centralWidget = new QWidget(scoreboard);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GB_Timer = new QGroupBox(centralWidget);
        GB_Timer->setObjectName(QString::fromUtf8("GB_Timer"));
        GB_Timer->setGeometry(QRect(-30, 18, 521, 101));
        GB_Timer->setStyleSheet(QString::fromUtf8("border: none;"));
        lcdNumber_mSec = new QLCDNumber(GB_Timer);
        lcdNumber_mSec->setObjectName(QString::fromUtf8("lcdNumber_mSec"));
        lcdNumber_mSec->setGeometry(QRect(230, 3, 150, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber_mSec->sizePolicy().hasHeightForWidth());
        lcdNumber_mSec->setSizePolicy(sizePolicy1);
        lcdNumber_mSec->setCursor(QCursor(Qt::BlankCursor));
        lcdNumber_mSec->setFrameShape(QFrame::NoFrame);
        lcdNumber_mSec->setSmallDecimalPoint(false);
        lcdNumber_mSec->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber_Sec = new QLCDNumber(GB_Timer);
        lcdNumber_Sec->setObjectName(QString::fromUtf8("lcdNumber_Sec"));
        lcdNumber_Sec->setGeometry(QRect(140, 3, 150, 100));
        sizePolicy1.setHeightForWidth(lcdNumber_Sec->sizePolicy().hasHeightForWidth());
        lcdNumber_Sec->setSizePolicy(sizePolicy1);
        lcdNumber_Sec->setCursor(QCursor(Qt::BlankCursor));
        lcdNumber_Sec->setFrameShape(QFrame::NoFrame);
        lcdNumber_Sec->setSmallDecimalPoint(false);
        lcdNumber_Sec->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber_Min = new QLCDNumber(GB_Timer);
        lcdNumber_Min->setObjectName(QString::fromUtf8("lcdNumber_Min"));
        lcdNumber_Min->setGeometry(QRect(50, 3, 150, 100));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(lcdNumber_Min->sizePolicy().hasHeightForWidth());
        lcdNumber_Min->setSizePolicy(sizePolicy2);
        lcdNumber_Min->setCursor(QCursor(Qt::BlankCursor));
        lcdNumber_Min->setFrameShape(QFrame::NoFrame);
        lcdNumber_Min->setSmallDecimalPoint(false);
        lcdNumber_Min->setSegmentStyle(QLCDNumber::Filled);
        Edit_Time = new QLineEdit(GB_Timer);
        Edit_Time->setObjectName(QString::fromUtf8("Edit_Time"));
        Edit_Time->setGeometry(QRect(392, 54, 113, 27));
        QFont font;
        font.setPointSize(15);
        Edit_Time->setFont(font);
        Edit_Time->setStyleSheet(QString::fromUtf8("color: white;"));
        lineEdit = new QLineEdit(GB_Timer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(198, 29, 31, 41));
        QFont font1;
        font1.setPointSize(30);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("color: white;"));
        lineEdit_2 = new QLineEdit(GB_Timer);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(290, 30, 31, 41));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: white;"));
        bt_Score_Left = new QPushButton(centralWidget);
        bt_Score_Left->setObjectName(QString::fromUtf8("bt_Score_Left"));
        bt_Score_Left->setGeometry(QRect(110, 150, 222, 300));
        bt_Score_Left->setStyleSheet(QString::fromUtf8("border:none;"));
        bt_Score_Right = new QPushButton(centralWidget);
        bt_Score_Right->setObjectName(QString::fromUtf8("bt_Score_Right"));
        bt_Score_Right->setGeometry(QRect(470, 150, 222, 300));
        bt_Score_Right->setStyleSheet(QString::fromUtf8("border:none;"));
        bt_StartGame = new QPushButton(centralWidget);
        bt_StartGame->setObjectName(QString::fromUtf8("bt_StartGame"));
        bt_StartGame->setGeometry(QRect(470, 30, 220, 90));
        bt_StartGame->setStyleSheet(QString::fromUtf8("border:none;"));
        bt_Mute = new QPushButton(centralWidget);
        bt_Mute->setObjectName(QString::fromUtf8("bt_Mute"));
        bt_Mute->setGeometry(QRect(710, 40, 70, 70));
        bt_Mute->setStyleSheet(QString::fromUtf8("border:none;"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(320, 130, 65, 331));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(670, 130, 31, 331));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(90, 430, 621, 31));
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(90, 120, 31, 341));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(90, 130, 621, 41));
        groupBox_5->setStyleSheet(QString::fromUtf8(""));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(413, 130, 68, 330));
        groupBox_6->setStyleSheet(QString::fromUtf8(""));
        pt_ScoreD = new QPushButton(centralWidget);
        pt_ScoreD->setObjectName(QString::fromUtf8("pt_ScoreD"));
        pt_ScoreD->setEnabled(true);
        pt_ScoreD->setGeometry(QRect(377, 230, 40, 142));
        pt_ScoreD->setStyleSheet(QString::fromUtf8("border:none;"));
        scoreboard->setCentralWidget(centralWidget);

        retranslateUi(scoreboard);

        QMetaObject::connectSlotsByName(scoreboard);
    } // setupUi

    void retranslateUi(QMainWindow *scoreboard)
    {
        scoreboard->setWindowTitle(QApplication::translate("scoreboard", "scoreboard", 0, QApplication::UnicodeUTF8));
        GB_Timer->setTitle(QString());
        lineEdit->setText(QApplication::translate("scoreboard", ":", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("scoreboard", ":", 0, QApplication::UnicodeUTF8));
        bt_Score_Left->setText(QString());
        bt_Score_Right->setText(QString());
        bt_StartGame->setText(QString());
        bt_Mute->setText(QString());
        groupBox->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("scoreboard", "GroupBox", 0, QApplication::UnicodeUTF8));
        pt_ScoreD->setText(QString());
        Q_UNUSED(scoreboard);
    } // retranslateUi

};

namespace Ui {
    class scoreboard: public Ui_scoreboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARD_H
