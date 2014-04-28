/********************************************************************************
** Form generated from reading ui file 'gamepad.ui'
**
** Created: Mon Apr 28 10:14:43 2014
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
#include <QtGui/QDateEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePad
{
public:
    QWidget *centralWidget;
    QDateEdit *dateEdit;
    QPushButton *Right;
    QPushButton *Down;
    QPushButton *Left;
    QPushButton *Up;
    QPushButton *pushButton_6;
    QTimeEdit *timeEdit;
    QLabel *button_check;
    QLabel *label;
    QToolBar *mainToolBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *GamePad)
    {
        if (GamePad->objectName().isEmpty())
            GamePad->setObjectName(QString::fromUtf8("GamePad"));
        GamePad->resize(827, 521);
        centralWidget = new QWidget(GamePad);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(470, 10, 71, 27));
        Right = new QPushButton(centralWidget);
        buttonGroup = new QButtonGroup(GamePad);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(Right);
        Right->setObjectName(QString::fromUtf8("Right"));
        Right->setGeometry(QRect(310, 140, 141, 101));
        Down = new QPushButton(centralWidget);
        buttonGroup->addButton(Down);
        Down->setObjectName(QString::fromUtf8("Down"));
        Down->setGeometry(QRect(170, 240, 141, 101));
        Left = new QPushButton(centralWidget);
        buttonGroup->addButton(Left);
        Left->setObjectName(QString::fromUtf8("Left"));
        Left->setGeometry(QRect(40, 140, 131, 101));
        Up = new QPushButton(centralWidget);
        buttonGroup->addButton(Up);
        Up->setObjectName(QString::fromUtf8("Up"));
        Up->setGeometry(QRect(170, 50, 141, 91));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(520, 140, 91, 81));
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(390, 10, 71, 27));
        button_check = new QLabel(centralWidget);
        button_check->setObjectName(QString::fromUtf8("button_check"));
        button_check->setGeometry(QRect(340, 80, 151, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 151, 131));
        GamePad->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(GamePad);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GamePad->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(GamePad);
        QObject::connect(Up, SIGNAL(clicked()), GamePad, SLOT(Up()));
        QObject::connect(Left, SIGNAL(clicked()), GamePad, SLOT(Left()));
        QObject::connect(Right, SIGNAL(clicked()), GamePad, SLOT(Down()));
        QObject::connect(Down, SIGNAL(clicked()), GamePad, SLOT(Right()));
        QObject::connect(Up, SIGNAL(clicked()), timeEdit, SLOT(stepUp()));
        QObject::connect(Down, SIGNAL(clicked()), timeEdit, SLOT(stepDown()));
        QObject::connect(Left, SIGNAL(clicked()), dateEdit, SLOT(stepUp()));
        QObject::connect(Right, SIGNAL(clicked()), dateEdit, SLOT(stepDown()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), GamePad, SLOT(PlayAudio()));

        QMetaObject::connectSlotsByName(GamePad);
    } // setupUi

    void retranslateUi(QMainWindow *GamePad)
    {
        GamePad->setWindowTitle(QApplication::translate("GamePad", "GamePad", 0, QApplication::UnicodeUTF8));
        Right->setText(QApplication::translate("GamePad", "Right", 0, QApplication::UnicodeUTF8));
        Down->setText(QApplication::translate("GamePad", "Down", 0, QApplication::UnicodeUTF8));
        Left->setText(QApplication::translate("GamePad", "Left", 0, QApplication::UnicodeUTF8));
        Up->setText(QApplication::translate("GamePad", "Up", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("GamePad", "PushButton", 0, QApplication::UnicodeUTF8));
        button_check->setText(QString());
        label->setText(QString());
        Q_UNUSED(GamePad);
    } // retranslateUi

};

namespace Ui {
    class GamePad: public Ui_GamePad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAD_H
