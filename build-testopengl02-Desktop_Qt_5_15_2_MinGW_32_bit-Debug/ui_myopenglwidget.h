/********************************************************************************
** Form generated from reading UI file 'myopenglwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYOPENGLWIDGET_H
#define UI_MYOPENGLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myopenglwidget
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myopenglwidget)
    {
        if (myopenglwidget->objectName().isEmpty())
            myopenglwidget->setObjectName(QString::fromUtf8("myopenglwidget"));
        myopenglwidget->resize(800, 600);
        centralwidget = new QWidget(myopenglwidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myopenglwidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myopenglwidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        myopenglwidget->setMenuBar(menubar);
        statusbar = new QStatusBar(myopenglwidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myopenglwidget->setStatusBar(statusbar);

        retranslateUi(myopenglwidget);

        QMetaObject::connectSlotsByName(myopenglwidget);
    } // setupUi

    void retranslateUi(QMainWindow *myopenglwidget)
    {
        myopenglwidget->setWindowTitle(QCoreApplication::translate("myopenglwidget", "myopenglwidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myopenglwidget: public Ui_myopenglwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYOPENGLWIDGET_H
