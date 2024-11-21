#ifndef WIDGET_H
#define WIDGET_H
#include "dataanalyse.h"
#include <QWidget>
#include <QtCharts>
#include <QGraphicsWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
     QString filename1;
    /***********设置定时器*************/
    QTimer* timer1 = new QTimer(this);
private slots:
    void showWidget();
    void on_dataClearBtn_clicked();
    void on_dataAnlBtn_clicked();
    void on_xAxisMaxSpinBox_valueChanged(int);
    void on_xAxisMinSpinBox_valueChanged(int );
    void on_yAxisMaxSpinBox_valueChanged(int );
    void on_yAxisMinSpinBox_valueChanged(int );
    void on_startSamplingBtn_clicked();
    void on_stopSamplingBtn_clicked();
    void on_Q_CheckBox_stateChanged(int);
    void on_P1_CheckBox_stateChanged(int);
    void on_P2_CheckBox_stateChanged(int);
    void on_W_CheckBox_stateChanged(int);
    void on_T_CheckBox_stateChanged(int);
    void on_N_CheckBox_stateChanged(int);
    void on_onceSamplingBtn_clicked();
    void on_unautoSamplybox_stateChanged(int arg1);
private:
    Ui::Widget *ui;
    dataAnalyse *m_c;
};
#endif // WIDGET_H
