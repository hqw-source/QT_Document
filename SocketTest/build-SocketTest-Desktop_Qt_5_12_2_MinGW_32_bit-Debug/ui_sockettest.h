/********************************************************************************
** Form generated from reading UI file 'sockettest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETTEST_H
#define UI_SOCKETTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocketTest
{
public:

    void setupUi(QWidget *SocketTest)
    {
        if (SocketTest->objectName().isEmpty())
            SocketTest->setObjectName(QString::fromUtf8("SocketTest"));
        SocketTest->resize(400, 300);

        retranslateUi(SocketTest);

        QMetaObject::connectSlotsByName(SocketTest);
    } // setupUi

    void retranslateUi(QWidget *SocketTest)
    {
        SocketTest->setWindowTitle(QApplication::translate("SocketTest", "SocketTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocketTest: public Ui_SocketTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETTEST_H
