/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_openBLE;
    QPushButton *pushButton_closeBLE;
    QPushButton *pushButton_upDateBLE;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QTextBrowser *textBrowser_receive;
    QWidget *widget_6;
    QGridLayout *gridLayout;
    QPushButton *pushButton_lift;
    QPushButton *pushButton_speedUp;
    QPushButton *pushButton_slowDown;
    QPushButton *pushButton_back;
    QPushButton *pushButton_right;
    QPushButton *pushButton_forward;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_clearReceive;
    QPushButton *pushButton_sendtest;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(559, 721);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(widget_7);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 10, -1);
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_6->addWidget(listWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_openBLE = new QPushButton(groupBox);
        pushButton_openBLE->setObjectName(QString::fromUtf8("pushButton_openBLE"));

        verticalLayout_3->addWidget(pushButton_openBLE);

        pushButton_closeBLE = new QPushButton(groupBox);
        pushButton_closeBLE->setObjectName(QString::fromUtf8("pushButton_closeBLE"));

        verticalLayout_3->addWidget(pushButton_closeBLE);

        pushButton_upDateBLE = new QPushButton(groupBox);
        pushButton_upDateBLE->setObjectName(QString::fromUtf8("pushButton_upDateBLE"));

        verticalLayout_3->addWidget(pushButton_upDateBLE);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_7);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        textBrowser_receive = new QTextBrowser(groupBox_2);
        textBrowser_receive->setObjectName(QString::fromUtf8("textBrowser_receive"));
        textBrowser_receive->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_5->addWidget(textBrowser_receive);

        horizontalLayout_5->setStretch(0, 8);

        verticalLayout->addWidget(groupBox_2);

        widget_6 = new QWidget(widget_7);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        gridLayout = new QGridLayout(widget_6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_lift = new QPushButton(widget_6);
        pushButton_lift->setObjectName(QString::fromUtf8("pushButton_lift"));

        gridLayout->addWidget(pushButton_lift, 1, 0, 1, 1);

        pushButton_speedUp = new QPushButton(widget_6);
        pushButton_speedUp->setObjectName(QString::fromUtf8("pushButton_speedUp"));

        gridLayout->addWidget(pushButton_speedUp, 2, 2, 1, 1);

        pushButton_slowDown = new QPushButton(widget_6);
        pushButton_slowDown->setObjectName(QString::fromUtf8("pushButton_slowDown"));

        gridLayout->addWidget(pushButton_slowDown, 2, 0, 1, 1);

        pushButton_back = new QPushButton(widget_6);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));

        gridLayout->addWidget(pushButton_back, 2, 1, 1, 1);

        pushButton_right = new QPushButton(widget_6);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));

        gridLayout->addWidget(pushButton_right, 1, 2, 1, 1);

        pushButton_forward = new QPushButton(widget_6);
        pushButton_forward->setObjectName(QString::fromUtf8("pushButton_forward"));

        gridLayout->addWidget(pushButton_forward, 0, 1, 1, 1);

        pushButton_stop = new QPushButton(widget_6);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout->addWidget(pushButton_stop, 1, 1, 1, 1);

        pushButton_clearReceive = new QPushButton(widget_6);
        pushButton_clearReceive->setObjectName(QString::fromUtf8("pushButton_clearReceive"));

        gridLayout->addWidget(pushButton_clearReceive, 0, 0, 1, 1);

        pushButton_sendtest = new QPushButton(widget_6);
        pushButton_sendtest->setObjectName(QString::fromUtf8("pushButton_sendtest"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_sendtest->sizePolicy().hasHeightForWidth());
        pushButton_sendtest->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_sendtest, 0, 2, 1, 1);


        verticalLayout->addWidget(widget_6);

        label = new QLabel(widget_7);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setOpenExternalLinks(true);

        verticalLayout->addWidget(label);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 2);

        verticalLayout_2->addWidget(widget_7);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 559, 25));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\257\347\224\250\350\256\276\345\244\207", nullptr));
        pushButton_openBLE->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\223\235\347\211\231", nullptr));
        pushButton_closeBLE->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButton_upDateBLE->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\350\256\276\345\244\207", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\227\345\214\272", nullptr));
        pushButton_lift->setText(QCoreApplication::translate("MainWindow", "\345\267\2463", nullptr));
        pushButton_speedUp->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\2376", nullptr));
        pushButton_slowDown->setText(QCoreApplication::translate("MainWindow", "\345\207\217\351\200\2377", nullptr));
        pushButton_back->setText(QCoreApplication::translate("MainWindow", "\345\220\2162", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", "\345\217\2634", nullptr));
        pushButton_forward->setText(QCoreApplication::translate("MainWindow", "\345\211\2151", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\2345", nullptr));
        pushButton_clearReceive->setText(QCoreApplication::translate("MainWindow", "\346\270\205\345\261\217", nullptr));
        pushButton_sendtest->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\265\213\350\257\225", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\276\256\344\277\241\345\205\254\344\274\227\345\217\267\357\274\232\346\236\234\346\236\234\345\260\217\345\270\210\345\274\237</span></p><p><span style=\" font-size:12pt;\">\345\217\257\344\273\245\346\216\245\345\217\227\344\270\213\344\275\215\346\234\272\345\220\221\346\211\213\346\234\272\345\217\221\351\200\201\346\225\260\346\215\256</span></p><p><span style=\" font-size:12pt;\">\345\215\225\345\207\273\345\210\227\350\241\250\345\217\257\351\200\211\344\270\255\350\256\276\345\244\207\357\274\214\345\217\214\345\207\273\345\210\227\350\241\250\350\277\236\346\216\245\345\257\271\345\272\224\350\256\276\345\244\207</span></p><p><span style=\" font-size:12pt;\">\345\211\2151;\345\220\2162;\345\267\2463;\345\217\2634;\345\201\2345;\345\212\240\351\200\2376;\345\207\217\351\200\2377</span></p><p><span style=\" font-size:12pt;\">\345\205\263\346\263\250\345\276\256\344\277\241\345\205\254\344\274\227\345\217\267:\346\236\234\346\236\234\345\260\217"
                        "\345\270\210\345\274\237,\345\220\216\345\217\260\345\233\236\345\244\215\350\223\235\347\211\231\345\260\217\350\275\246,\350\216\267\345\217\226\346\272\220\344\273\243\347\240\201</span></p><p><span style=\" font-size:12pt;\">Copyright @guoguoxiaoshidi</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
