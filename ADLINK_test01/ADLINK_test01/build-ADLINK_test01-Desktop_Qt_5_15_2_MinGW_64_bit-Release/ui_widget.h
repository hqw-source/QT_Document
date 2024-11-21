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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *QDisplayLabel;
    QLabel *label;
    QLCDNumber *LCD_Q;
    QLabel *label_2;
    QLabel *P1DisplayLabel;
    QLabel *label_3;
    QLCDNumber *LCD_P1;
    QLabel *label_4;
    QLabel *P2DisplayLabel;
    QLabel *label_6;
    QLCDNumber *LCD_P2;
    QLabel *label_5;
    QLabel *WDisplayLabel;
    QLabel *label_8;
    QLCDNumber *LCD_W;
    QLabel *label_7;
    QLabel *TDisplayLabel;
    QLabel *label_9;
    QLCDNumber *LCD_T;
    QLabel *label_10;
    QLabel *NDisplayLabel;
    QLabel *label_13;
    QLCDNumber *LCD_L;
    QLabel *label_14;
    QFrame *frame_2;
    QLabel *label_15;
    QLCDNumber *samplingTimeLCD_ms;
    QLCDNumber *samplingTimeLCD_s;
    QLabel *label_19;
    QLabel *label_12;
    QLabel *label_24;
    QSpinBox *SampliePeriodSpinBox;
    QLabel *label_18;
    QLabel *label_11;
    QLabel *startLabel;
    QPushButton *startSamplingBtn;
    QLabel *stopLabel;
    QPushButton *stopSamplingBtn;
    QLabel *clearDataLabel;
    QPushButton *dataClearBtn;
    QCheckBox *unautoSamplybox;
    QPushButton *onceSamplingBtn;
    QLabel *startLabel_once;
    QLCDNumber *samplyCountDisplay;
    QLabel *label_16;
    QFrame *frame_7;
    QCheckBox *Q_CheckBox;
    QCheckBox *P1_CheckBox;
    QCheckBox *P2_CheckBox;
    QCheckBox *W_CheckBox;
    QCheckBox *T_CheckBox;
    QCheckBox *N_CheckBox;
    QLabel *label_22;
    QLabel *P1labelColor;
    QLabel *P2labelColor;
    QLabel *QlabelColor;
    QLabel *WlabelColor;
    QLabel *TlabelColor;
    QLabel *NlabelColor;
    QLabel *curveDisplayLabel;
    QFrame *frame_6;
    QLabel *label_20;
    QSpinBox *yAxisMaxSpinBox;
    QLabel *label_21;
    QSpinBox *yAxisMinSpinBox;
    QLabel *label_30;
    QLabel *label_31;
    QSpinBox *xAxisMinSpinBox;
    QSpinBox *xAxisMaxSpinBox;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QSlider *xAxisMaxSlider;
    QSlider *xAxisMiniSlider;
    QSlider *yAxisMaxSlider;
    QSlider *yAxisMiniSlider;
    QLabel *tableSetLabel;
    QLabel *xAxisTableLabel;
    QLabel *yAxisTableLabel;
    QFrame *frame_8;
    QLabel *GDUTlabel;
    QLabel *dataAnalysisLabel;
    QPushButton *dataAnlBtn;
    QLabel *label_23;
    QLabel *realTimeDisplayIabel;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QSplitter *splitter;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1900, 900);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(191, 815, 1701, 81));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        QDisplayLabel = new QLabel(frame);
        QDisplayLabel->setObjectName(QString::fromUtf8("QDisplayLabel"));
        QDisplayLabel->setMinimumSize(QSize(52, 0));
        QDisplayLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(QDisplayLabel);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        LCD_Q = new QLCDNumber(frame);
        LCD_Q->setObjectName(QString::fromUtf8("LCD_Q"));
        LCD_Q->setMinimumSize(QSize(74, 0));
        LCD_Q->setMaximumSize(QSize(55, 16777215));
        QFont font1;
        font1.setPointSize(14);
        LCD_Q->setFont(font1);
        LCD_Q->setFrameShape(QFrame::StyledPanel);
        LCD_Q->setFrameShadow(QFrame::Plain);
        LCD_Q->setLineWidth(1);
        LCD_Q->setSmallDecimalPoint(false);
        LCD_Q->setDigitCount(4);
        LCD_Q->setSegmentStyle(QLCDNumber::Flat);
        LCD_Q->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout->addWidget(LCD_Q, 0, Qt::AlignRight);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        P1DisplayLabel = new QLabel(frame);
        P1DisplayLabel->setObjectName(QString::fromUtf8("P1DisplayLabel"));
        P1DisplayLabel->setMinimumSize(QSize(52, 0));
        P1DisplayLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(P1DisplayLabel);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        LCD_P1 = new QLCDNumber(frame);
        LCD_P1->setObjectName(QString::fromUtf8("LCD_P1"));
        LCD_P1->setMinimumSize(QSize(74, 0));
        LCD_P1->setMaximumSize(QSize(55, 16777215));
        LCD_P1->setFont(font1);
        LCD_P1->setFrameShape(QFrame::StyledPanel);
        LCD_P1->setFrameShadow(QFrame::Plain);
        LCD_P1->setLineWidth(1);
        LCD_P1->setSmallDecimalPoint(false);
        LCD_P1->setDigitCount(4);
        LCD_P1->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCD_P1, 0, Qt::AlignRight);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        P2DisplayLabel = new QLabel(frame);
        P2DisplayLabel->setObjectName(QString::fromUtf8("P2DisplayLabel"));
        P2DisplayLabel->setMinimumSize(QSize(52, 0));
        P2DisplayLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(P2DisplayLabel);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        LCD_P2 = new QLCDNumber(frame);
        LCD_P2->setObjectName(QString::fromUtf8("LCD_P2"));
        LCD_P2->setMinimumSize(QSize(73, 0));
        LCD_P2->setMaximumSize(QSize(55, 16777215));
        QFont font2;
        font2.setPointSize(13);
        LCD_P2->setFont(font2);
        LCD_P2->setFrameShape(QFrame::StyledPanel);
        LCD_P2->setFrameShadow(QFrame::Plain);
        LCD_P2->setLineWidth(1);
        LCD_P2->setSmallDecimalPoint(false);
        LCD_P2->setDigitCount(4);
        LCD_P2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCD_P2, 0, Qt::AlignRight);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        WDisplayLabel = new QLabel(frame);
        WDisplayLabel->setObjectName(QString::fromUtf8("WDisplayLabel"));
        WDisplayLabel->setMinimumSize(QSize(52, 0));
        WDisplayLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(WDisplayLabel);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        LCD_W = new QLCDNumber(frame);
        LCD_W->setObjectName(QString::fromUtf8("LCD_W"));
        LCD_W->setMinimumSize(QSize(74, 0));
        LCD_W->setMaximumSize(QSize(55, 16777215));
        LCD_W->setFont(font1);
        LCD_W->setFrameShape(QFrame::StyledPanel);
        LCD_W->setFrameShadow(QFrame::Plain);
        LCD_W->setLineWidth(1);
        LCD_W->setSmallDecimalPoint(false);
        LCD_W->setDigitCount(4);
        LCD_W->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCD_W, 0, Qt::AlignRight);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        TDisplayLabel = new QLabel(frame);
        TDisplayLabel->setObjectName(QString::fromUtf8("TDisplayLabel"));
        TDisplayLabel->setMinimumSize(QSize(52, 0));
        TDisplayLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(TDisplayLabel);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout->addWidget(label_9);

        LCD_T = new QLCDNumber(frame);
        LCD_T->setObjectName(QString::fromUtf8("LCD_T"));
        LCD_T->setMinimumSize(QSize(74, 0));
        LCD_T->setMaximumSize(QSize(55, 55));
        LCD_T->setFont(font1);
        LCD_T->setFrameShape(QFrame::StyledPanel);
        LCD_T->setFrameShadow(QFrame::Plain);
        LCD_T->setLineWidth(1);
        LCD_T->setSmallDecimalPoint(false);
        LCD_T->setDigitCount(4);
        LCD_T->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCD_T, 0, Qt::AlignRight);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        horizontalLayout->addWidget(label_10);

        NDisplayLabel = new QLabel(frame);
        NDisplayLabel->setObjectName(QString::fromUtf8("NDisplayLabel"));
        NDisplayLabel->setMinimumSize(QSize(52, 0));
        NDisplayLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(NDisplayLabel);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        horizontalLayout->addWidget(label_13);

        LCD_L = new QLCDNumber(frame);
        LCD_L->setObjectName(QString::fromUtf8("LCD_L"));
        LCD_L->setEnabled(true);
        LCD_L->setMinimumSize(QSize(92, 0));
        LCD_L->setFont(font1);
        LCD_L->setFrameShape(QFrame::StyledPanel);
        LCD_L->setFrameShadow(QFrame::Plain);
        LCD_L->setLineWidth(1);
        LCD_L->setSmallDecimalPoint(false);
        LCD_L->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCD_L, 0, Qt::AlignRight);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        horizontalLayout->addWidget(label_14);

        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(1460, 85, 431, 321));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(5, 4, 421, 51));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/labRoomName.png")));
        label_15->setScaledContents(true);
        samplingTimeLCD_ms = new QLCDNumber(frame_2);
        samplingTimeLCD_ms->setObjectName(QString::fromUtf8("samplingTimeLCD_ms"));
        samplingTimeLCD_ms->setGeometry(QRect(120, 105, 61, 41));
        samplingTimeLCD_ms->setFont(font2);
        samplingTimeLCD_ms->setFrameShape(QFrame::StyledPanel);
        samplingTimeLCD_ms->setFrameShadow(QFrame::Plain);
        samplingTimeLCD_ms->setLineWidth(1);
        samplingTimeLCD_ms->setSmallDecimalPoint(false);
        samplingTimeLCD_ms->setDigitCount(3);
        samplingTimeLCD_ms->setSegmentStyle(QLCDNumber::Flat);
        samplingTimeLCD_ms->setProperty("value", QVariant(0.000000000000000));
        samplingTimeLCD_s = new QLCDNumber(frame_2);
        samplingTimeLCD_s->setObjectName(QString::fromUtf8("samplingTimeLCD_s"));
        samplingTimeLCD_s->setGeometry(QRect(39, 105, 61, 41));
        samplingTimeLCD_s->setFont(font2);
        samplingTimeLCD_s->setFrameShape(QFrame::StyledPanel);
        samplingTimeLCD_s->setFrameShadow(QFrame::Plain);
        samplingTimeLCD_s->setLineWidth(1);
        samplingTimeLCD_s->setSmallDecimalPoint(false);
        samplingTimeLCD_s->setDigitCount(3);
        samplingTimeLCD_s->setSegmentStyle(QLCDNumber::Flat);
        samplingTimeLCD_s->setProperty("value", QVariant(0.000000000000000));
        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 65, 151, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(16);
        label_19->setFont(font3);
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 60, 40, 40));
        label_12->setFrameShape(QFrame::NoFrame);
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/sampleTimeImg.png")));
        label_12->setScaledContents(true);
        label_24 = new QLabel(frame_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(110, 103, 21, 41));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        label_24->setFont(font4);
        SampliePeriodSpinBox = new QSpinBox(frame_2);
        SampliePeriodSpinBox->setObjectName(QString::fromUtf8("SampliePeriodSpinBox"));
        SampliePeriodSpinBox->setGeometry(QRect(260, 105, 111, 41));
        SampliePeriodSpinBox->setFont(font1);
        SampliePeriodSpinBox->setMinimum(5);
        SampliePeriodSpinBox->setMaximum(1000);
        SampliePeriodSpinBox->setSingleStep(100);
        SampliePeriodSpinBox->setValue(300);
        label_18 = new QLabel(frame_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(250, 60, 181, 41));
        label_18->setFont(font3);
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(210, 61, 40, 40));
        label_11->setFrameShape(QFrame::NoFrame);
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/samplyPeriodImg.png")));
        label_11->setScaledContents(true);
        startLabel = new QLabel(frame_2);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));
        startLabel->setGeometry(QRect(10, 190, 52, 52));
        startLabel->setFrameShape(QFrame::Box);
        startSamplingBtn = new QPushButton(frame_2);
        startSamplingBtn->setObjectName(QString::fromUtf8("startSamplingBtn"));
        startSamplingBtn->setGeometry(QRect(67, 190, 100, 50));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(13);
        startSamplingBtn->setFont(font5);
        stopLabel = new QLabel(frame_2);
        stopLabel->setObjectName(QString::fromUtf8("stopLabel"));
        stopLabel->setGeometry(QRect(260, 193, 40, 40));
        stopLabel->setFrameShape(QFrame::Box);
        stopSamplingBtn = new QPushButton(frame_2);
        stopSamplingBtn->setObjectName(QString::fromUtf8("stopSamplingBtn"));
        stopSamplingBtn->setGeometry(QRect(317, 190, 100, 50));
        stopSamplingBtn->setFont(font5);
        clearDataLabel = new QLabel(frame_2);
        clearDataLabel->setObjectName(QString::fromUtf8("clearDataLabel"));
        clearDataLabel->setGeometry(QRect(260, 267, 40, 40));
        clearDataLabel->setFrameShape(QFrame::Box);
        dataClearBtn = new QPushButton(frame_2);
        dataClearBtn->setObjectName(QString::fromUtf8("dataClearBtn"));
        dataClearBtn->setGeometry(QRect(317, 260, 100, 50));
        dataClearBtn->setFont(font5);
        unautoSamplybox = new QCheckBox(frame_2);
        unautoSamplybox->setObjectName(QString::fromUtf8("unautoSamplybox"));
        unautoSamplybox->setGeometry(QRect(60, 140, 351, 51));
        unautoSamplybox->setFont(font);
        onceSamplingBtn = new QPushButton(frame_2);
        onceSamplingBtn->setObjectName(QString::fromUtf8("onceSamplingBtn"));
        onceSamplingBtn->setGeometry(QRect(67, 260, 100, 50));
        onceSamplingBtn->setFont(font5);
        startLabel_once = new QLabel(frame_2);
        startLabel_once->setObjectName(QString::fromUtf8("startLabel_once"));
        startLabel_once->setGeometry(QRect(11, 260, 52, 52));
        startLabel_once->setFrameShape(QFrame::Box);
        samplyCountDisplay = new QLCDNumber(frame_2);
        samplyCountDisplay->setObjectName(QString::fromUtf8("samplyCountDisplay"));
        samplyCountDisplay->setGeometry(QRect(171, 265, 61, 41));
        QFont font6;
        font6.setPointSize(11);
        samplyCountDisplay->setFont(font6);
        samplyCountDisplay->setFrameShape(QFrame::StyledPanel);
        samplyCountDisplay->setFrameShadow(QFrame::Plain);
        samplyCountDisplay->setLineWidth(1);
        samplyCountDisplay->setSmallDecimalPoint(false);
        samplyCountDisplay->setDigitCount(3);
        samplyCountDisplay->setSegmentStyle(QLCDNumber::Flat);
        samplyCountDisplay->setProperty("value", QVariant(0.000000000000000));
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(234, 244, 31, 81));
        label_16->setFont(font);
        frame_7 = new QFrame(Widget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(1460, 410, 141, 401));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Raised);
        Q_CheckBox = new QCheckBox(frame_7);
        Q_CheckBox->setObjectName(QString::fromUtf8("Q_CheckBox"));
        Q_CheckBox->setGeometry(QRect(11, 88, 91, 23));
        Q_CheckBox->setFont(font5);
        Q_CheckBox->setChecked(true);
        P1_CheckBox = new QCheckBox(frame_7);
        P1_CheckBox->setObjectName(QString::fromUtf8("P1_CheckBox"));
        P1_CheckBox->setGeometry(QRect(11, 138, 91, 23));
        P1_CheckBox->setFont(font5);
        P1_CheckBox->setChecked(true);
        P2_CheckBox = new QCheckBox(frame_7);
        P2_CheckBox->setObjectName(QString::fromUtf8("P2_CheckBox"));
        P2_CheckBox->setGeometry(QRect(11, 187, 91, 23));
        P2_CheckBox->setFont(font5);
        P2_CheckBox->setChecked(true);
        W_CheckBox = new QCheckBox(frame_7);
        W_CheckBox->setObjectName(QString::fromUtf8("W_CheckBox"));
        W_CheckBox->setGeometry(QRect(11, 236, 91, 23));
        W_CheckBox->setFont(font5);
        W_CheckBox->setChecked(true);
        T_CheckBox = new QCheckBox(frame_7);
        T_CheckBox->setObjectName(QString::fromUtf8("T_CheckBox"));
        T_CheckBox->setGeometry(QRect(11, 288, 81, 23));
        T_CheckBox->setFont(font5);
        T_CheckBox->setChecked(true);
        N_CheckBox = new QCheckBox(frame_7);
        N_CheckBox->setObjectName(QString::fromUtf8("N_CheckBox"));
        N_CheckBox->setGeometry(QRect(11, 340, 91, 23));
        N_CheckBox->setFont(font5);
        N_CheckBox->setChecked(true);
        label_22 = new QLabel(frame_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(72, 15, 61, 51));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font7.setPointSize(15);
        label_22->setFont(font7);
        P1labelColor = new QLabel(frame_7);
        P1labelColor->setObjectName(QString::fromUtf8("P1labelColor"));
        P1labelColor->setGeometry(QRect(109, 139, 20, 20));
        P1labelColor->setFrameShape(QFrame::Box);
        P2labelColor = new QLabel(frame_7);
        P2labelColor->setObjectName(QString::fromUtf8("P2labelColor"));
        P2labelColor->setGeometry(QRect(109, 189, 20, 20));
        P2labelColor->setFrameShape(QFrame::Box);
        QlabelColor = new QLabel(frame_7);
        QlabelColor->setObjectName(QString::fromUtf8("QlabelColor"));
        QlabelColor->setGeometry(QRect(109, 90, 20, 20));
        QlabelColor->setFrameShape(QFrame::Box);
        WlabelColor = new QLabel(frame_7);
        WlabelColor->setObjectName(QString::fromUtf8("WlabelColor"));
        WlabelColor->setGeometry(QRect(109, 237, 20, 20));
        WlabelColor->setFrameShape(QFrame::Box);
        TlabelColor = new QLabel(frame_7);
        TlabelColor->setObjectName(QString::fromUtf8("TlabelColor"));
        TlabelColor->setGeometry(QRect(109, 290, 20, 20));
        TlabelColor->setFrameShape(QFrame::Box);
        NlabelColor = new QLabel(frame_7);
        NlabelColor->setObjectName(QString::fromUtf8("NlabelColor"));
        NlabelColor->setGeometry(QRect(109, 342, 20, 20));
        NlabelColor->setFrameShape(QFrame::Box);
        curveDisplayLabel = new QLabel(frame_7);
        curveDisplayLabel->setObjectName(QString::fromUtf8("curveDisplayLabel"));
        curveDisplayLabel->setGeometry(QRect(13, 13, 46, 46));
        curveDisplayLabel->setFrameShape(QFrame::Box);
        frame_6 = new QFrame(Widget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(1610, 410, 281, 401));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(13, 270, 111, 21));
        label_20->setFont(font5);
        yAxisMaxSpinBox = new QSpinBox(frame_6);
        yAxisMaxSpinBox->setObjectName(QString::fromUtf8("yAxisMaxSpinBox"));
        yAxisMaxSpinBox->setGeometry(QRect(184, 300, 81, 31));
        QFont font8;
        font8.setPointSize(12);
        yAxisMaxSpinBox->setFont(font8);
        yAxisMaxSpinBox->setMaximum(200);
        yAxisMaxSpinBox->setValue(45);
        label_21 = new QLabel(frame_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(13, 339, 91, 21));
        label_21->setFont(font5);
        yAxisMinSpinBox = new QSpinBox(frame_6);
        yAxisMinSpinBox->setObjectName(QString::fromUtf8("yAxisMinSpinBox"));
        yAxisMinSpinBox->setGeometry(QRect(184, 360, 81, 31));
        yAxisMinSpinBox->setFont(font8);
        yAxisMinSpinBox->setMinimum(-100);
        yAxisMinSpinBox->setMaximum(0);
        yAxisMinSpinBox->setValue(-15);
        label_30 = new QLabel(frame_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(72, 11, 111, 51));
        label_30->setFont(font7);
        label_31 = new QLabel(frame_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(50, 230, 161, 31));
        label_31->setFont(font);
        xAxisMinSpinBox = new QSpinBox(frame_6);
        xAxisMinSpinBox->setObjectName(QString::fromUtf8("xAxisMinSpinBox"));
        xAxisMinSpinBox->setGeometry(QRect(184, 200, 81, 31));
        xAxisMinSpinBox->setFont(font8);
        xAxisMinSpinBox->setMinimum(0);
        xAxisMinSpinBox->setMaximum(10000);
        xAxisMinSpinBox->setValue(0);
        xAxisMaxSpinBox = new QSpinBox(frame_6);
        xAxisMaxSpinBox->setObjectName(QString::fromUtf8("xAxisMaxSpinBox"));
        xAxisMaxSpinBox->setGeometry(QRect(185, 140, 81, 31));
        xAxisMaxSpinBox->setFont(font8);
        xAxisMaxSpinBox->setMinimum(5000);
        xAxisMaxSpinBox->setMaximum(100000);
        xAxisMaxSpinBox->setValue(20000);
        label_32 = new QLabel(frame_6);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(50, 71, 191, 31));
        label_32->setFont(font);
        label_33 = new QLabel(frame_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(13, 111, 81, 21));
        label_33->setFont(font5);
        label_34 = new QLabel(frame_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(12, 179, 81, 21));
        label_34->setFont(font5);
        xAxisMaxSlider = new QSlider(frame_6);
        xAxisMaxSlider->setObjectName(QString::fromUtf8("xAxisMaxSlider"));
        xAxisMaxSlider->setGeometry(QRect(7, 148, 171, 16));
        xAxisMaxSlider->setMinimum(5000);
        xAxisMaxSlider->setMaximum(100000);
        xAxisMaxSlider->setValue(20000);
        xAxisMaxSlider->setOrientation(Qt::Horizontal);
        xAxisMiniSlider = new QSlider(frame_6);
        xAxisMiniSlider->setObjectName(QString::fromUtf8("xAxisMiniSlider"));
        xAxisMiniSlider->setGeometry(QRect(7, 209, 171, 16));
        xAxisMiniSlider->setMinimum(0);
        xAxisMiniSlider->setMaximum(10000);
        xAxisMiniSlider->setOrientation(Qt::Horizontal);
        yAxisMaxSlider = new QSlider(frame_6);
        yAxisMaxSlider->setObjectName(QString::fromUtf8("yAxisMaxSlider"));
        yAxisMaxSlider->setGeometry(QRect(7, 308, 171, 16));
        yAxisMaxSlider->setMinimum(10);
        yAxisMaxSlider->setMaximum(200);
        yAxisMaxSlider->setValue(45);
        yAxisMaxSlider->setOrientation(Qt::Horizontal);
        yAxisMiniSlider = new QSlider(frame_6);
        yAxisMiniSlider->setObjectName(QString::fromUtf8("yAxisMiniSlider"));
        yAxisMiniSlider->setGeometry(QRect(8, 367, 171, 16));
        yAxisMiniSlider->setMinimum(-100);
        yAxisMiniSlider->setMaximum(-10);
        yAxisMiniSlider->setValue(-15);
        yAxisMiniSlider->setOrientation(Qt::Horizontal);
        tableSetLabel = new QLabel(frame_6);
        tableSetLabel->setObjectName(QString::fromUtf8("tableSetLabel"));
        tableSetLabel->setGeometry(QRect(10, 12, 50, 50));
        tableSetLabel->setFrameShape(QFrame::Box);
        xAxisTableLabel = new QLabel(frame_6);
        xAxisTableLabel->setObjectName(QString::fromUtf8("xAxisTableLabel"));
        xAxisTableLabel->setGeometry(QRect(10, 69, 33, 33));
        xAxisTableLabel->setFrameShape(QFrame::Box);
        yAxisTableLabel = new QLabel(frame_6);
        yAxisTableLabel->setObjectName(QString::fromUtf8("yAxisTableLabel"));
        yAxisTableLabel->setGeometry(QRect(10, 228, 33, 33));
        yAxisTableLabel->setFrameShape(QFrame::Box);
        frame_8 = new QFrame(Widget);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(1460, 10, 431, 71));
        frame_8->setFrameShape(QFrame::Box);
        frame_8->setFrameShadow(QFrame::Raised);
        GDUTlabel = new QLabel(frame_8);
        GDUTlabel->setObjectName(QString::fromUtf8("GDUTlabel"));
        GDUTlabel->setGeometry(QRect(0, 0, 251, 71));
        GDUTlabel->setFrameShape(QFrame::Box);
        dataAnalysisLabel = new QLabel(frame_8);
        dataAnalysisLabel->setObjectName(QString::fromUtf8("dataAnalysisLabel"));
        dataAnalysisLabel->setGeometry(QRect(264, 10, 50, 50));
        dataAnalysisLabel->setFrameShape(QFrame::Box);
        dataAnlBtn = new QPushButton(frame_8);
        dataAnlBtn->setObjectName(QString::fromUtf8("dataAnlBtn"));
        dataAnlBtn->setGeometry(QRect(320, 10, 100, 50));
        dataAnlBtn->setFont(font5);
        label_23 = new QLabel(Widget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(75, 820, 131, 71));
        label_23->setFont(font);
        label_23->setFrameShape(QFrame::NoFrame);
        label_23->setFrameShadow(QFrame::Raised);
        label_23->setAlignment(Qt::AlignCenter);
        realTimeDisplayIabel = new QLabel(Widget);
        realTimeDisplayIabel->setObjectName(QString::fromUtf8("realTimeDisplayIabel"));
        realTimeDisplayIabel->setGeometry(QRect(10, 823, 61, 61));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font9.setPointSize(11);
        realTimeDisplayIabel->setFont(font9);
        realTimeDisplayIabel->setFrameShape(QFrame::Box);
        realTimeDisplayIabel->setAlignment(Qt::AlignCenter);
        splitter_3 = new QSplitter(Widget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(1000, 90, 0, 291));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter_2->addWidget(splitter);
        splitter_3->addWidget(splitter_2);
        frame->raise();
        frame_2->raise();
        frame_7->raise();
        frame_8->raise();
        label_23->raise();
        frame_6->raise();
        realTimeDisplayIabel->raise();
        splitter_3->raise();

        retranslateUi(Widget);
        QObject::connect(yAxisMinSpinBox, SIGNAL(valueChanged(int)), yAxisMiniSlider, SLOT(setValue(int)));
        QObject::connect(xAxisMiniSlider, SIGNAL(valueChanged(int)), xAxisMinSpinBox, SLOT(setValue(int)));
        QObject::connect(yAxisMiniSlider, SIGNAL(valueChanged(int)), yAxisMinSpinBox, SLOT(setValue(int)));
        QObject::connect(xAxisMaxSlider, SIGNAL(valueChanged(int)), xAxisMaxSpinBox, SLOT(setValue(int)));
        QObject::connect(yAxisMaxSlider, SIGNAL(valueChanged(int)), yAxisMaxSpinBox, SLOT(setValue(int)));
        QObject::connect(yAxisMaxSpinBox, SIGNAL(valueChanged(int)), yAxisMaxSlider, SLOT(setValue(int)));
        QObject::connect(xAxisMaxSpinBox, SIGNAL(valueChanged(int)), xAxisMaxSlider, SLOT(setValue(int)));
        QObject::connect(xAxisMinSpinBox, SIGNAL(valueChanged(int)), xAxisMiniSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        QDisplayLabel->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "\346\265\201\351\207\217Q:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "L/min", nullptr));
        P1DisplayLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("Widget", "\345\216\213\345\212\233P1:", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "MPa", nullptr));
        P2DisplayLabel->setText(QString());
        label_6->setText(QCoreApplication::translate("Widget", "\345\216\213\345\212\233P2:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "MPa", nullptr));
        WDisplayLabel->setText(QString());
        label_8->setText(QCoreApplication::translate("Widget", "\345\212\237\347\216\207W:", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "kw", nullptr));
        TDisplayLabel->setText(QString());
        label_9->setText(QCoreApplication::translate("Widget", "\346\262\271\346\270\251T:", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\342\204\203", nullptr));
        NDisplayLabel->setText(QString());
        label_13->setText(QCoreApplication::translate("Widget", "\344\275\215\347\247\273L:", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "mm", nullptr));
        label_15->setText(QString());
        label_19->setText(QCoreApplication::translate("Widget", "\351\207\207\346\240\267\346\227\266\351\227\264(s)", nullptr));
        label_12->setText(QString());
        label_24->setText(QCoreApplication::translate("Widget", ":", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "\351\207\207\346\240\267\345\221\250\346\234\237T(ms)", nullptr));
        label_11->setText(QString());
        startLabel->setText(QString());
        startSamplingBtn->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\351\207\207\346\240\267", nullptr));
        stopLabel->setText(QString());
        stopSamplingBtn->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\351\207\207\346\240\267", nullptr));
        clearDataLabel->setText(QString());
        dataClearBtn->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        unautoSamplybox->setText(QCoreApplication::translate("Widget", "\345\215\225\346\254\241\351\207\207\346\240\267(\346\234\252\345\213\276\351\200\211\344\270\272\350\207\252\345\212\250\351\207\207\346\240\267)", nullptr));
        onceSamplingBtn->setText(QCoreApplication::translate("Widget", "\345\215\225\346\254\241\351\207\207\346\240\267", nullptr));
        startLabel_once->setText(QString());
        label_16->setText(QCoreApplication::translate("Widget", "\346\254\241", nullptr));
        Q_CheckBox->setText(QCoreApplication::translate("Widget", "\346\265\201\351\207\217Q", nullptr));
        P1_CheckBox->setText(QCoreApplication::translate("Widget", "\345\216\213\345\212\233P1", nullptr));
        P2_CheckBox->setText(QCoreApplication::translate("Widget", "\345\216\213\345\212\233P2", nullptr));
        W_CheckBox->setText(QCoreApplication::translate("Widget", "\345\212\237\347\216\207W", nullptr));
        T_CheckBox->setText(QCoreApplication::translate("Widget", "\346\262\271\346\270\251T", nullptr));
        N_CheckBox->setText(QCoreApplication::translate("Widget", "\344\275\215\347\247\273L", nullptr));
        label_22->setText(QCoreApplication::translate("Widget", "\346\233\262\347\272\277\n"
"\346\230\276\347\244\272", nullptr));
        P1labelColor->setText(QString());
        P2labelColor->setText(QString());
        QlabelColor->setText(QString());
        WlabelColor->setText(QString());
        TlabelColor->setText(QString());
        NlabelColor->setText(QString());
        curveDisplayLabel->setText(QString());
        label_20->setText(QCoreApplication::translate("Widget", "Y\350\275\264max", nullptr));
        label_21->setText(QCoreApplication::translate("Widget", "Y\350\275\264min", nullptr));
        label_30->setText(QCoreApplication::translate("Widget", "\345\233\276\350\241\250\350\256\276\347\275\256", nullptr));
        label_31->setText(QCoreApplication::translate("Widget", "\345\233\276\350\241\250Y\350\275\264\350\256\276\347\275\256:", nullptr));
        label_32->setText(QCoreApplication::translate("Widget", "\345\233\276\350\241\250X\350\275\264\350\256\276\347\275\256:", nullptr));
        label_33->setText(QCoreApplication::translate("Widget", "X\350\275\264max", nullptr));
        label_34->setText(QCoreApplication::translate("Widget", "X\350\275\264min", nullptr));
        tableSetLabel->setText(QString());
        xAxisTableLabel->setText(QString());
        yAxisTableLabel->setText(QString());
        GDUTlabel->setText(QString());
        dataAnalysisLabel->setText(QString());
        dataAnlBtn->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        label_23->setText(QCoreApplication::translate("Widget", "\345\256\236\346\227\266\346\230\276\347\244\272\357\274\232", nullptr));
        realTimeDisplayIabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
