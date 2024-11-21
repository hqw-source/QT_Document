#ifndef DATAANALYSE_H
#define DATAANALYSE_H
#include "qtimer.h"
#include <QMainWindow>
namespace Ui {
class dataAnalyse;
}
class dataAnalyse : public QMainWindow
{
    Q_OBJECT
public:
    explicit dataAnalyse(QWidget *parent = nullptr);
    ~dataAnalyse();
    void reData_Q(float data);
    void reData_P1(float data);
    void reData_P2(float data);
    QTimer* timer2 = new QTimer(this);
    void clearData();
private slots:
    void on_backWidgetBtn_clicked();
    void on_readDataBtn_clicked();
private:
    Ui::dataAnalyse *ui;
signals:
    void openWidgetSignal();
};
#endif // DATAANALYSE_H
