/********************************************************************************
** Form generated from reading ui file 'subscore.ui'
**
** Created: Wed Apr 30 01:27:47 2014
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SUBSCORE_H
#define UI_SUBSCORE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subscore
{
public:
    QWidget *centralWidget;
    QPushButton *sendButton;

    void setupUi(QMainWindow *subscore)
    {
        if (subscore->objectName().isEmpty())
            subscore->setObjectName(QString::fromUtf8("subscore"));
        subscore->resize(800, 480);
        centralWidget = new QWidget(subscore);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(0, 0, 800, 480));
        subscore->setCentralWidget(centralWidget);

        retranslateUi(subscore);

        QMetaObject::connectSlotsByName(subscore);
    } // setupUi

    void retranslateUi(QMainWindow *subscore)
    {
        subscore->setWindowTitle(QApplication::translate("subscore", "subscore", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QString());
        Q_UNUSED(subscore);
    } // retranslateUi

};

namespace Ui {
    class subscore: public Ui_subscore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCORE_H
