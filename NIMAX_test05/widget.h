#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <NIDAQmx.h>
#include <QtCharts>
#include <QHBoxLayout>
using namespace QtCharts;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
int32 CVICALLBACK EveryNCallback(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData);
int32 CVICALLBACK EveryNCallback1(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData);
int32 CVICALLBACK EveryNCallbackctr(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData);
int32 CVICALLBACK EveryNCallback_save(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData);
int32 CVICALLBACK EveryNCallback_save1(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData);
class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int32       error=0;
    int32       read,read1;
    float64     data[100000],data1[100000];
    char        errBuff[2048]={'\0'};
    int sample;
    int sec,ms;
    int count;
    void del_file();//清除缓存文件
    void setSaveChannel();//设置保存通道参数
    void setChannel();//设置通道参数
    void clearSample();//清除采样数据
    void addTimedata();//添加时间数据
     /***********设置定时器*************/
    QTimer* timer = new QTimer(this);
    QTimer* timer1 = new QTimer(this);
    QTimer* timer2 = new QTimer(this);
    QTimer* timer3 = new QTimer(this);
private slots:
    void on_stopSample_clicked();
    void on_startSample_clicked();
    void on_startSaveSample_clicked();
    void on_stopSaveSample_clicked();
    void on_timeSaveSample_clicked();
    // void on_clearSample_clicked();
    void on_cDAQ1Mod1ai1_stateChanged(int);
    void on_cDAQ1Mod2ai0_stateChanged(int );
    void on_cDAQ1Mod2ai1_stateChanged(int);
    void on_cDAQ1Mod2ai2_stateChanged(int );
    void on_filePath_clicked();
    void on_setTime_valueChanged(int arg1);

private:
    Ui::Widget *ui;
    //定义采集通道0
    QChartView *cview0;
    QChart *chart0;
    QValueAxis *axsisX0;
    QValueAxis *axsisY0;
    //定义采集通道1
    QChartView *cview1;
    QChart *chart1;
    QValueAxis *axsisX1;
    QValueAxis *axsisY1;
    //定义采集通道2
    QChartView *cview2;
    QChart *chart2;
    QValueAxis *axsisX2;
    QValueAxis *axsisY2;
    //定义采集通道3
    QChartView *cview3;
    QChart *chart3;
    QValueAxis *axsisX3;
    QValueAxis *axsisY3;
    //定义采集通道4 数字信号
    QChartView *cview4;
    QChart *chart4;
    QValueAxis *axsisX4;
    QValueAxis *axsisY4;
};
#endif // WIDGET_H
