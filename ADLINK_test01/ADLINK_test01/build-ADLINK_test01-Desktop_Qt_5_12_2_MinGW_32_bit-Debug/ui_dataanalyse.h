/********************************************************************************
** Form generated from reading UI file 'dataanalyse.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAANALYSE_H
#define UI_DATAANALYSE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataAnalyse
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QFrame *frame;
    QPushButton *readDataBtn;
    QLabel *label_2;
    QPushButton *backWidgetBtn;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_3;
    QTextEdit *filePathText;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dataAnalyse)
    {
        if (dataAnalyse->objectName().isEmpty())
            dataAnalyse->setObjectName(QString::fromUtf8("dataAnalyse"));
        dataAnalyse->resize(1600, 900);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("accessories-character-map");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("tubiao.ico"), QSize(), QIcon::Normal, QIcon::Off);
        }
        dataAnalyse->setWindowIcon(icon);
        centralwidget = new QWidget(dataAnalyse);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 110, 1321, 731));
        tableWidget->setFrameShape(QFrame::Box);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1340, 60, 251, 221));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        readDataBtn = new QPushButton(frame);
        readDataBtn->setObjectName(QString::fromUtf8("readDataBtn"));
        readDataBtn->setGeometry(QRect(73, 81, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(13);
        readDataBtn->setFont(font);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(51, 10, 201, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setAlignment(Qt::AlignCenter);
        backWidgetBtn = new QPushButton(frame);
        backWidgetBtn->setObjectName(QString::fromUtf8("backWidgetBtn"));
        backWidgetBtn->setGeometry(QRect(73, 160, 101, 41));
        backWidgetBtn->setFont(font);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(21, 78, 40, 45));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/saveDataImg.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(19, 157, 45, 45));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/backImg.png")));
        label_6->setScaledContents(true);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 7, 40, 45));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/shujushezhiImg.png")));
        label_8->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(466, 11, 381, 39));
        label->setFont(font1);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 61, 1320, 39));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);
        filePathText = new QTextEdit(centralwidget);
        filePathText->setObjectName(QString::fromUtf8("filePathText"));
        filePathText->setGeometry(QRect(1340, 470, 251, 181));
        QFont font2;
        font2.setPointSize(12);
        filePathText->setFont(font2);
        filePathText->setFrameShape(QFrame::Box);
        filePathText->setFrameShadow(QFrame::Raised);
        filePathText->setReadOnly(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1375, 423, 241, 39));
        label_4->setFont(font1);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1340, 420, 40, 40));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/filePathImg.png")));
        label_7->setScaledContents(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(570, 68, 25, 25));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/biaogeImg.png")));
        label_9->setScaledContents(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(426, 18, 25, 25));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/shiyanshujuImg.png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1329, 291, 271, 101));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(12);
        label_11->setFont(font3);
        label_11->setFrameShape(QFrame::NoFrame);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(1337, 281, 81, 31));
        label_12->setFont(font3);
        label_12->setFrameShape(QFrame::NoFrame);
        label_12->setAlignment(Qt::AlignCenter);
        dataAnalyse->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dataAnalyse);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 25));
        dataAnalyse->setMenuBar(menubar);
        statusbar = new QStatusBar(dataAnalyse);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dataAnalyse->setStatusBar(statusbar);

        retranslateUi(dataAnalyse);

        QMetaObject::connectSlotsByName(dataAnalyse);
    } // setupUi

    void retranslateUi(QMainWindow *dataAnalyse)
    {
        dataAnalyse->setWindowTitle(QApplication::translate("dataAnalyse", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dataAnalyse", "\346\265\201\351\207\217Q(L/min)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dataAnalyse", "\345\216\213\345\212\233P1(MPa)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("dataAnalyse", "\345\216\213\345\212\233P2(MPa)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("dataAnalyse", "\345\244\207\346\263\250", nullptr));
        readDataBtn->setText(QApplication::translate("dataAnalyse", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label_2->setText(QApplication::translate("dataAnalyse", "\345\256\236\351\252\214\346\225\260\346\215\256\350\256\276\347\275\256\357\274\232", nullptr));
        backWidgetBtn->setText(QApplication::translate("dataAnalyse", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
        label->setText(QApplication::translate("dataAnalyse", "\347\224\265\346\266\262\346\257\224\344\276\213\347\273\274\345\220\210\346\216\247\345\210\266\347\263\273\347\273\237\345\256\236\351\252\214", nullptr));
        label_3->setText(QApplication::translate("dataAnalyse", "\345\256\236\351\252\214\346\225\260\346\215\256\350\241\250\346\240\274", nullptr));
        label_4->setText(QApplication::translate("dataAnalyse", "\344\277\235\345\255\230\347\232\204\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        label_7->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QApplication::translate("dataAnalyse", "<html><head/><body><p><span style=\" color:#ff0000;\">\342\221\240\345\256\236\351\252\214\346\225\260\346\215\256\350\256\260\345\275\225\345\256\214\346\225\264\345\220\216\345\206\215\347\202\271\345\207\273</span></p><p><span style=\" color:#ff0000;\">\344\277\235\345\255\230\346\225\260\346\215\256\346\214\211\351\222\256\345\257\274\345\207\272EXCEL\346\226\207\344\273\266</span></p></body></html>", nullptr));
        label_12->setText(QApplication::translate("dataAnalyse", "<html><head/><body><p><span style=\" color:#ff0000;\">\346\263\250\346\204\217\357\274\232 </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataAnalyse: public Ui_dataAnalyse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAANALYSE_H
