/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *ipLineEdit;
    QLabel *label;
    QLineEdit *portLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *connectBtn;
    QPushButton *sendBtn;
    QPushButton *disconnectBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QComboBox *RWComboBox;
    QLabel *label_3;
    QComboBox *regComboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpinBox *startSB;
    QLabel *label_5;
    QSpinBox *numSB;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QStackedWidget *stackedWidget;
    QWidget *R;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *R_Widget;
    QWidget *SR;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *SR_Widget;
    QWidget *PR;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *PR_Widget;
    QWidget *DIDO;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *DI_DO_Widget;
    QWidget *UIUO;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *UI_UO_Widget;
    QMenuBar *menubar;
    QMenu *menuR;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(714, 491);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        ipLineEdit = new QLineEdit(widget);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));

        horizontalLayout->addWidget(ipLineEdit);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        connectBtn = new QPushButton(widget);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));

        horizontalLayout->addWidget(connectBtn);

        sendBtn = new QPushButton(widget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        disconnectBtn = new QPushButton(widget);
        disconnectBtn->setObjectName(QString::fromUtf8("disconnectBtn"));

        horizontalLayout->addWidget(disconnectBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        RWComboBox = new QComboBox(widget_3);
        RWComboBox->setObjectName(QString::fromUtf8("RWComboBox"));

        horizontalLayout_6->addWidget(RWComboBox);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        regComboBox = new QComboBox(widget_3);
        regComboBox->setObjectName(QString::fromUtf8("regComboBox"));

        horizontalLayout_6->addWidget(regComboBox);

        horizontalSpacer_2 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        startSB = new QSpinBox(widget_3);
        startSB->setObjectName(QString::fromUtf8("startSB"));

        horizontalLayout_6->addWidget(startSB);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        numSB = new QSpinBox(widget_3);
        numSB->setObjectName(QString::fromUtf8("numSB"));

        horizontalLayout_6->addWidget(numSB);


        verticalLayout_2->addWidget(widget_3);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        R = new QWidget();
        R->setObjectName(QString::fromUtf8("R"));
        horizontalLayout_3 = new QHBoxLayout(R);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        R_Widget = new QTableWidget(R);
        R_Widget->setObjectName(QString::fromUtf8("R_Widget"));

        horizontalLayout_3->addWidget(R_Widget);

        stackedWidget->addWidget(R);
        SR = new QWidget();
        SR->setObjectName(QString::fromUtf8("SR"));
        horizontalLayout_5 = new QHBoxLayout(SR);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        SR_Widget = new QTableWidget(SR);
        SR_Widget->setObjectName(QString::fromUtf8("SR_Widget"));

        horizontalLayout_5->addWidget(SR_Widget);

        stackedWidget->addWidget(SR);
        PR = new QWidget();
        PR->setObjectName(QString::fromUtf8("PR"));
        horizontalLayout_4 = new QHBoxLayout(PR);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        PR_Widget = new QTableWidget(PR);
        PR_Widget->setObjectName(QString::fromUtf8("PR_Widget"));

        horizontalLayout_4->addWidget(PR_Widget);

        stackedWidget->addWidget(PR);
        DIDO = new QWidget();
        DIDO->setObjectName(QString::fromUtf8("DIDO"));
        horizontalLayout_7 = new QHBoxLayout(DIDO);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        DI_DO_Widget = new QTableWidget(DIDO);
        DI_DO_Widget->setObjectName(QString::fromUtf8("DI_DO_Widget"));

        horizontalLayout_7->addWidget(DI_DO_Widget);

        stackedWidget->addWidget(DIDO);
        UIUO = new QWidget();
        UIUO->setObjectName(QString::fromUtf8("UIUO"));
        horizontalLayout_8 = new QHBoxLayout(UIUO);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        UI_UO_Widget = new QTableWidget(UIUO);
        UI_UO_Widget->setObjectName(QString::fromUtf8("UI_UO_Widget"));

        horizontalLayout_8->addWidget(UI_UO_Widget);

        stackedWidget->addWidget(UIUO);

        verticalLayout_3->addWidget(stackedWidget);


        verticalLayout_2->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 714, 21));
        menuR = new QMenu(menubar);
        menuR->setObjectName(QString::fromUtf8("menuR"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuR->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FANUC\346\234\272\345\231\250\344\272\272\345\257\204\345\255\230\345\231\250\351\200\232\350\256\257\350\275\257\344\273\266", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "IP: ", nullptr));
        ipLineEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", nullptr));
        portLineEdit->setText(QApplication::translate("MainWindow", "8000", nullptr));
        connectBtn->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        sendBtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        disconnectBtn->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\257\273\345\206\231\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\347\261\273\345\236\213\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\225\260\351\207\217\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\345\200\274\350\241\250\346\240\274", nullptr));
        menuR->setTitle(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
