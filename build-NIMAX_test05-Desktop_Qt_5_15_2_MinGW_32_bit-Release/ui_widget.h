/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QLabel *label_2;
    QSpinBox *setTime;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *timeSamplyProgressBar;
    QPushButton *timeSaveSample;
    QLabel *label_7;
    QLabel *label_15;
    QPlainTextEdit *fileName;
    QLabel *label;
    QPlainTextEdit *fileNameEdit;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLCDNumber *saveTimeDisplayMs;
    QLCDNumber *saveTimeDisplaySec;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *filePath;
    QPushButton *stopSample;
    QPushButton *startSample;
    QPushButton *stopSaveSample;
    QPushButton *startSaveSample;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QCheckBox *cDAQ1Mod2ai2;
    QCheckBox *cDAQ1Mod1ai1;
    QCheckBox *cDAQ1Mod2ai1;
    QCheckBox *cDAQ1Mod2ai0;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_27;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *huoerSpeedDisplay;
    QLabel *cidianSpeedDisplay;
    QLabel *dianganSpeedDisplay;
    QLabel *guangdianSpeedDisplay;
    QFrame *frame_2;
    QLabel *label_20;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_22;
    QLabel *motorSpeedDisplay;
    QLabel *label_13;
    QLabel *label_38;
    QFrame *frame_3;
    QLabel *label_45;
    QLabel *label_46;
    QFrame *frame_4;
    QFrame *frame_5;
    QFrame *frame_6;
    QFrame *frame_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1900, 900);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/source/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1090, 288, 481, 522));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        frame->setFont(font);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(98, 2, 321, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(false);
        label_2->setFont(font1);
        setTime = new QSpinBox(frame);
        setTime->setObjectName(QString::fromUtf8("setTime"));
        setTime->setGeometry(QRect(133, 271, 51, 31));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        setTime->setFont(font2);
        setTime->setMinimum(1);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(47, 271, 81, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(false);
        label_4->setFont(font3);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(186, 271, 21, 31));
        label_5->setFont(font3);
        timeSamplyProgressBar = new QProgressBar(frame);
        timeSamplyProgressBar->setObjectName(QString::fromUtf8("timeSamplyProgressBar"));
        timeSamplyProgressBar->setGeometry(QRect(350, 277, 131, 23));
        timeSamplyProgressBar->setValue(0);
        timeSaveSample = new QPushButton(frame);
        timeSaveSample->setObjectName(QString::fromUtf8("timeSaveSample"));
        timeSaveSample->setGeometry(QRect(23, 309, 180, 30));
        timeSaveSample->setFont(font3);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(258, 272, 81, 31));
        label_7->setFont(font3);
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(393, 420, 111, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(13);
        font4.setBold(false);
        label_15->setFont(font4);
        fileName = new QPlainTextEdit(frame);
        fileName->setObjectName(QString::fromUtf8("fileName"));
        fileName->setGeometry(QRect(368, 449, 101, 61));
        fileName->setFont(font);
        fileName->setReadOnly(true);
        fileName->setBackgroundVisible(false);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(52, 421, 161, 21));
        label->setFont(font4);
        fileNameEdit = new QPlainTextEdit(frame);
        fileNameEdit->setObjectName(QString::fromUtf8("fileNameEdit"));
        fileNameEdit->setGeometry(QRect(14, 450, 341, 61));
        fileNameEdit->setFont(font);
        fileNameEdit->setReadOnly(true);
        fileNameEdit->setBackgroundVisible(false);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(49, 230, 221, 31));
        label_8->setFont(font4);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(46, 344, 191, 31));
        label_9->setFont(font4);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(52, 163, 191, 31));
        label_10->setFont(font4);
        saveTimeDisplayMs = new QLCDNumber(frame);
        saveTimeDisplayMs->setObjectName(QString::fromUtf8("saveTimeDisplayMs"));
        saveTimeDisplayMs->setGeometry(QRect(405, 336, 61, 41));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        saveTimeDisplayMs->setFont(font5);
        saveTimeDisplayMs->setAutoFillBackground(false);
        saveTimeDisplayMs->setFrameShape(QFrame::Box);
        saveTimeDisplayMs->setFrameShadow(QFrame::Raised);
        saveTimeDisplayMs->setLineWidth(1);
        saveTimeDisplayMs->setDigitCount(3);
        saveTimeDisplayMs->setSegmentStyle(QLCDNumber::Flat);
        saveTimeDisplaySec = new QLCDNumber(frame);
        saveTimeDisplaySec->setObjectName(QString::fromUtf8("saveTimeDisplaySec"));
        saveTimeDisplaySec->setGeometry(QRect(345, 336, 51, 41));
        saveTimeDisplaySec->setFont(font5);
        saveTimeDisplaySec->setAutoFillBackground(false);
        saveTimeDisplaySec->setFrameShape(QFrame::Box);
        saveTimeDisplaySec->setFrameShadow(QFrame::Raised);
        saveTimeDisplaySec->setLineWidth(1);
        saveTimeDisplaySec->setDigitCount(2);
        saveTimeDisplaySec->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(395, 346, 16, 31));
        label_6->setFont(font2);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(245, 345, 101, 31));
        label_3->setFont(font4);
        filePath = new QPushButton(frame);
        filePath->setObjectName(QString::fromUtf8("filePath"));
        filePath->setGeometry(QRect(255, 416, 95, 30));
        sizePolicy.setHeightForWidth(filePath->sizePolicy().hasHeightForWidth());
        filePath->setSizePolicy(sizePolicy);
        filePath->setFont(font3);
        stopSample = new QPushButton(frame);
        stopSample->setObjectName(QString::fromUtf8("stopSample"));
        stopSample->setGeometry(QRect(255, 202, 137, 30));
        stopSample->setFont(font3);
        startSample = new QPushButton(frame);
        startSample->setObjectName(QString::fromUtf8("startSample"));
        startSample->setGeometry(QRect(50, 200, 137, 30));
        startSample->setFont(font3);
        stopSaveSample = new QPushButton(frame);
        stopSaveSample->setObjectName(QString::fromUtf8("stopSaveSample"));
        stopSaveSample->setGeometry(QRect(255, 382, 180, 30));
        stopSaveSample->setFont(font3);
        startSaveSample = new QPushButton(frame);
        startSaveSample->setObjectName(QString::fromUtf8("startSaveSample"));
        startSaveSample->setGeometry(QRect(23, 382, 180, 30));
        startSaveSample->setFont(font3);
        label_33 = new QLabel(frame);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(67, 10, 25, 25));
        label_33->setPixmap(QPixmap(QString::fromUtf8(":/source/kongzhiImg.png")));
        label_33->setScaledContents(true);
        label_34 = new QLabel(frame);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(17, 46, 20, 20));
        label_34->setPixmap(QPixmap(QString::fromUtf8(":/source/quxianImg.png")));
        label_34->setScaledContents(true);
        label_35 = new QLabel(frame);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(17, 75, 20, 20));
        label_35->setPixmap(QPixmap(QString::fromUtf8(":/source/quxianImg.png")));
        label_35->setScaledContents(true);
        label_36 = new QLabel(frame);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(17, 105, 20, 20));
        label_36->setPixmap(QPixmap(QString::fromUtf8(":/source/quxianImg.png")));
        label_36->setScaledContents(true);
        label_37 = new QLabel(frame);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(17, 135, 20, 20));
        label_37->setPixmap(QPixmap(QString::fromUtf8(":/source/quxianImg.png")));
        label_37->setScaledContents(true);
        label_39 = new QLabel(frame);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(19, 419, 25, 25));
        label_39->setPixmap(QPixmap(QString::fromUtf8(":/source/wenjianImg.png")));
        label_39->setScaledContents(true);
        label_40 = new QLabel(frame);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(364, 419, 25, 25));
        label_40->setPixmap(QPixmap(QString::fromUtf8(":/source/wenjianmingImg.png")));
        label_40->setScaledContents(true);
        label_41 = new QLabel(frame);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(220, 420, 25, 25));
        label_41->setPixmap(QPixmap(QString::fromUtf8(":/source/dakaiwenjianImg.png")));
        label_41->setScaledContents(true);
        label_43 = new QLabel(frame);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(16, 165, 25, 25));
        label_43->setPixmap(QPixmap(QString::fromUtf8(":/source/realTimeImg.png")));
        label_43->setScaledContents(true);
        label_44 = new QLabel(frame);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(15, 233, 25, 25));
        label_44->setPixmap(QPixmap(QString::fromUtf8(":/source/dingshiImg.png")));
        label_44->setScaledContents(true);
        label_47 = new QLabel(frame);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(15, 346, 25, 25));
        label_47->setPixmap(QPixmap(QString::fromUtf8(":/source/kaishibaocunImg.png")));
        label_47->setScaledContents(true);
        label_48 = new QLabel(frame);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(205, 345, 30, 30));
        label_48->setPixmap(QPixmap(QString::fromUtf8(":/source/caiyangshijianImg.png")));
        label_48->setScaledContents(true);
        label_49 = new QLabel(frame);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(222, 275, 25, 25));
        label_49->setPixmap(QPixmap(QString::fromUtf8(":/source/baocunjinduImg.png")));
        label_49->setScaledContents(true);
        label_50 = new QLabel(frame);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(14, 274, 25, 25));
        label_50->setPixmap(QPixmap(QString::fromUtf8(":/source/shezhishijianImg.png")));
        label_50->setScaledContents(true);
        cDAQ1Mod2ai2 = new QCheckBox(frame);
        cDAQ1Mod2ai2->setObjectName(QString::fromUtf8("cDAQ1Mod2ai2"));
        cDAQ1Mod2ai2->setGeometry(QRect(55, 137, 401, 22));
        cDAQ1Mod2ai2->setFont(font3);
        cDAQ1Mod2ai2->setChecked(true);
        cDAQ1Mod1ai1 = new QCheckBox(frame);
        cDAQ1Mod1ai1->setObjectName(QString::fromUtf8("cDAQ1Mod1ai1"));
        cDAQ1Mod1ai1->setGeometry(QRect(55, 44, 401, 22));
        cDAQ1Mod1ai1->setFont(font3);
        cDAQ1Mod1ai1->setChecked(true);
        cDAQ1Mod2ai1 = new QCheckBox(frame);
        cDAQ1Mod2ai1->setObjectName(QString::fromUtf8("cDAQ1Mod2ai1"));
        cDAQ1Mod2ai1->setGeometry(QRect(55, 106, 401, 22));
        cDAQ1Mod2ai1->setFont(font3);
        cDAQ1Mod2ai1->setChecked(true);
        cDAQ1Mod2ai0 = new QCheckBox(frame);
        cDAQ1Mod2ai0->setObjectName(QString::fromUtf8("cDAQ1Mod2ai0"));
        cDAQ1Mod2ai0->setGeometry(QRect(55, 75, 401, 22));
        cDAQ1Mod2ai0->setFont(font3);
        cDAQ1Mod2ai0->setChecked(true);
        label_14 = new QLabel(Widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(637, 355, 191, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font6.setPointSize(14);
        font6.setBold(false);
        label_14->setFont(font6);
        label_16 = new QLabel(Widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(955, 356, 41, 31));
        label_16->setFont(font6);
        label_17 = new QLabel(Widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1010, 350, 40, 40));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/source/zhuansuImg.png")));
        label_17->setScaledContents(true);
        label_18 = new QLabel(Widget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(415, 356, 41, 31));
        label_18->setFont(font6);
        label_19 = new QLabel(Widget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(97, 355, 191, 31));
        label_19->setFont(font6);
        label_21 = new QLabel(Widget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(470, 350, 40, 40));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/source/zhuansuImg.png")));
        label_21->setScaledContents(true);
        label_23 = new QLabel(Widget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(50, 350, 40, 40));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/source/cidianImg.png")));
        label_23->setScaledContents(true);
        label_24 = new QLabel(Widget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(590, 350, 40, 40));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/source/huoerImg.png")));
        label_24->setScaledContents(true);
        label_25 = new QLabel(Widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(50, 760, 40, 40));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/source/dianganImg.png")));
        label_25->setScaledContents(true);
        label_26 = new QLabel(Widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(415, 766, 41, 31));
        label_26->setFont(font6);
        label_28 = new QLabel(Widget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(97, 765, 191, 31));
        label_28->setFont(font6);
        label_29 = new QLabel(Widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(470, 760, 40, 40));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/source/zhuansuImg.png")));
        label_29->setScaledContents(true);
        label_27 = new QLabel(Widget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(590, 760, 40, 40));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/source/guangdianImg.png")));
        label_27->setScaledContents(true);
        label_30 = new QLabel(Widget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(955, 766, 41, 31));
        label_30->setFont(font6);
        label_31 = new QLabel(Widget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(637, 765, 191, 31));
        label_31->setFont(font6);
        label_32 = new QLabel(Widget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(1010, 760, 40, 40));
        label_32->setPixmap(QPixmap(QString::fromUtf8(":/source/zhuansuImg.png")));
        label_32->setScaledContents(true);
        huoerSpeedDisplay = new QLabel(Widget);
        huoerSpeedDisplay->setObjectName(QString::fromUtf8("huoerSpeedDisplay"));
        huoerSpeedDisplay->setGeometry(QRect(820, 348, 111, 41));
        QFont font7;
        font7.setPointSize(13);
        huoerSpeedDisplay->setFont(font7);
        huoerSpeedDisplay->setFrameShape(QFrame::Box);
        huoerSpeedDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cidianSpeedDisplay = new QLabel(Widget);
        cidianSpeedDisplay->setObjectName(QString::fromUtf8("cidianSpeedDisplay"));
        cidianSpeedDisplay->setGeometry(QRect(280, 348, 111, 41));
        cidianSpeedDisplay->setFont(font7);
        cidianSpeedDisplay->setFrameShape(QFrame::Box);
        cidianSpeedDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dianganSpeedDisplay = new QLabel(Widget);
        dianganSpeedDisplay->setObjectName(QString::fromUtf8("dianganSpeedDisplay"));
        dianganSpeedDisplay->setGeometry(QRect(280, 760, 111, 41));
        dianganSpeedDisplay->setFont(font7);
        dianganSpeedDisplay->setFrameShape(QFrame::Box);
        dianganSpeedDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        guangdianSpeedDisplay = new QLabel(Widget);
        guangdianSpeedDisplay->setObjectName(QString::fromUtf8("guangdianSpeedDisplay"));
        guangdianSpeedDisplay->setGeometry(QRect(820, 760, 111, 41));
        guangdianSpeedDisplay->setFont(font7);
        guangdianSpeedDisplay->setFrameShape(QFrame::Box);
        guangdianSpeedDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(1090, 167, 481, 111));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(70, 9, 391, 41));
        label_20->setFont(font6);
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(377, 66, 41, 31));
        label_12->setFont(font6);
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(59, 65, 191, 31));
        label_11->setFont(font6);
        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 60, 40, 40));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/source/bianmaqiImg.png")));
        label_22->setScaledContents(true);
        motorSpeedDisplay = new QLabel(frame_2);
        motorSpeedDisplay->setObjectName(QString::fromUtf8("motorSpeedDisplay"));
        motorSpeedDisplay->setGeometry(QRect(240, 60, 111, 41));
        motorSpeedDisplay->setFont(font7);
        motorSpeedDisplay->setFrameShape(QFrame::Box);
        motorSpeedDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(430, 60, 40, 40));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/source/zhuansuImg.png")));
        label_13->setScaledContents(true);
        label_38 = new QLabel(frame_2);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(20, 10, 40, 40));
        label_38->setPixmap(QPixmap(QString::fromUtf8(":/source/signalImg.png")));
        label_38->setScaledContents(true);
        frame_3 = new QFrame(Widget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(1090, 8, 481, 151));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Plain);
        label_45 = new QLabel(frame_3);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(70, 10, 291, 71));
        label_45->setPixmap(QPixmap(QString::fromUtf8(":/source/GDUTlogo.png")));
        label_45->setScaledContents(true);
        label_46 = new QLabel(frame_3);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(51, 95, 391, 51));
        label_46->setPixmap(QPixmap(QString::fromUtf8(":/source/labRoomName.png")));
        label_46->setScaledContents(true);
        frame_4 = new QFrame(Widget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(9, 9, 531, 391));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(2);
        frame_5 = new QFrame(Widget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(9, 410, 531, 401));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Plain);
        frame_5->setLineWidth(2);
        frame_6 = new QFrame(Widget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(550, 9, 531, 391));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Plain);
        frame_6->setLineWidth(2);
        frame_7 = new QFrame(Widget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(550, 410, 531, 401));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Plain);
        frame_7->setLineWidth(2);
        frame_6->raise();
        frame_7->raise();
        frame_5->raise();
        frame_4->raise();
        frame->raise();
        label_14->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_21->raise();
        label_23->raise();
        label_24->raise();
        label_25->raise();
        label_26->raise();
        label_28->raise();
        label_29->raise();
        label_27->raise();
        label_30->raise();
        label_31->raise();
        label_32->raise();
        huoerSpeedDisplay->raise();
        cidianSpeedDisplay->raise();
        dianganSpeedDisplay->raise();
        guangdianSpeedDisplay->raise();
        frame_2->raise();
        frame_3->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "NI\346\225\260\346\215\256\351\207\207\351\233\206\350\275\257\344\273\266\345\212\237\350\203\275\346\216\247\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\350\256\276\345\256\232\346\227\266\351\227\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\347\247\222", nullptr));
        timeSaveSample->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\344\277\235\345\255\230\351\207\207\346\240\267\346\225\260\346\215\256", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\350\277\233\345\272\246:", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        fileName->setPlainText(QString());
        label->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\344\277\235\345\255\230\346\225\260\346\215\256\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\211\213\345\212\250\344\277\235\345\255\230\346\225\260\346\215\256\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\345\256\236\346\227\266\351\207\207\346\240\267\346\225\260\346\215\256\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\351\207\207\346\240\267\346\227\266\351\227\264\357\274\232", nullptr));
        filePath->setText(QCoreApplication::translate("Widget", "\350\256\276\345\256\232\350\267\257\345\276\204", nullptr));
        stopSample->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\345\256\236\346\227\266\351\207\207\346\240\267", nullptr));
        startSample->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\345\256\236\346\227\266\351\207\207\346\240\267", nullptr));
        stopSaveSample->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\277\235\345\255\230\351\207\207\346\240\267\346\225\260\346\215\256", nullptr));
        startSaveSample->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\344\277\235\345\255\230\351\207\207\346\240\267\346\225\260\346\215\256", nullptr));
        label_33->setText(QString());
        label_34->setText(QString());
        label_35->setText(QString());
        label_36->setText(QString());
        label_37->setText(QString());
        label_39->setText(QString());
        label_40->setText(QString());
        label_41->setText(QString());
        label_43->setText(QString());
        label_44->setText(QString());
        label_47->setText(QString());
        label_48->setText(QString());
        label_49->setText(QString());
        label_50->setText(QString());
        cDAQ1Mod2ai2->setText(QCoreApplication::translate("Widget", "cDAQ1Mod2/ai2\346\225\260\346\215\256\351\200\232\351\201\223-\345\205\211\347\224\265\345\274\217\344\274\240\346\204\237\345\231\250", nullptr));
        cDAQ1Mod1ai1->setText(QCoreApplication::translate("Widget", "cDAQ1Mod1/ai1\346\225\260\346\215\256\351\200\232\351\201\223-\347\243\201\347\224\265\345\274\217\344\274\240\346\204\237\345\231\250", nullptr));
        cDAQ1Mod2ai1->setText(QCoreApplication::translate("Widget", "cDAQ1Mod2/ai1\346\225\260\346\215\256\351\200\232\351\201\223-\351\234\215\345\260\224\345\274\217\344\274\240\346\204\237\345\231\250", nullptr));
        cDAQ1Mod2ai0->setText(QCoreApplication::translate("Widget", "cDAQ1Mod2/ai0\346\225\260\346\215\256\351\200\232\351\201\223-\347\224\265\346\204\237\345\274\217\344\274\240\346\204\237\345\231\250", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "\351\234\215\345\260\224\344\274\240\346\204\237\345\231\250\350\275\254\351\200\237\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "RPM", nullptr));
        label_17->setText(QString());
        label_18->setText(QCoreApplication::translate("Widget", "RPM", nullptr));
        label_19->setText(QCoreApplication::translate("Widget", "\347\243\201\347\224\265\344\274\240\346\204\237\345\231\250\350\275\254\351\200\237\357\274\232", nullptr));
        label_21->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QString());
        label_26->setText(QCoreApplication::translate("Widget", "RPM", nullptr));
        label_28->setText(QCoreApplication::translate("Widget", "\347\224\265\346\204\237\344\274\240\346\204\237\345\231\250\350\275\254\351\200\237\357\274\232", nullptr));
        label_29->setText(QString());
        label_27->setText(QString());
        label_30->setText(QCoreApplication::translate("Widget", "RPM", nullptr));
        label_31->setText(QCoreApplication::translate("Widget", "\345\205\211\347\224\265\344\274\240\346\204\237\345\231\250\350\275\254\351\200\237\357\274\232", nullptr));
        label_32->setText(QString());
        huoerSpeedDisplay->setText(QString());
        cidianSpeedDisplay->setText(QString());
        dianganSpeedDisplay->setText(QString());
        guangdianSpeedDisplay->setText(QString());
        label_20->setText(QCoreApplication::translate("Widget", "cDAQ1Mod3/ctr0  \347\274\226\347\240\201\345\231\250\346\225\260\345\255\227\344\277\241\345\217\267", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "RPM", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\250\345\256\236\346\227\266\350\275\254\351\200\237\357\274\232", nullptr));
        label_22->setText(QString());
        motorSpeedDisplay->setText(QString());
        label_13->setText(QString());
        label_38->setText(QString());
        label_45->setText(QString());
        label_46->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H