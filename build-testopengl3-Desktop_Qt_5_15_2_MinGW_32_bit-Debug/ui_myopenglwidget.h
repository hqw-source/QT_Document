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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyOpenGLWidget
{
public:

    void setupUi(QWidget *MyOpenGLWidget)
    {
        if (MyOpenGLWidget->objectName().isEmpty())
            MyOpenGLWidget->setObjectName(QString::fromUtf8("MyOpenGLWidget"));
        MyOpenGLWidget->resize(800, 600);

        retranslateUi(MyOpenGLWidget);

        QMetaObject::connectSlotsByName(MyOpenGLWidget);
    } // setupUi

    void retranslateUi(QWidget *MyOpenGLWidget)
    {
        MyOpenGLWidget->setWindowTitle(QCoreApplication::translate("MyOpenGLWidget", "MyOpenGLWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyOpenGLWidget: public Ui_MyOpenGLWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYOPENGLWIDGET_H
