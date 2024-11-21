#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QLabel>
#include <QMainWindow>
#include <QVector>
#include <QPair>
#include "clinkrobot.h"
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initAllWidget();
    void initRWidget();
    void initWidget(QTableWidget* theWidget, const QString& Type, int length, int startColumn);
    void initPRWidget();
    void sendandrec();



private slots:
    void selectRegWidget(int index);
    //接收到新值后更新界面
    void updateR_Widget(int index, float newValue);
    void updateSR_Widget(int index, QString newValue);
    void updatePR_Widget(int row,int cloum, float newValue);
    void updateDIO_UIO_Widget(int regType, int row, bool newValue);

    //寄存器界面值发生改变时更新相应值
    void updateRArr(int row, int column);
    void updateSRArr(int row, int column);
    void updatePRArr(int row, int column);
    void updateDI_DO_Arr(int row, int column);
    void updateUI_UO_Arr(int row, int column);

    void sendMsg();

private:

    bool isEditing = false;  // 标记是否正在编辑，避免递归
    // 保存修改的单元格及其初始值
    QMap<QPair<int, int>, QVariant> originalValues;


    bool bIsSuccessful =false;  //读写是否成功

    int nR_Arr[R_NUM] = {0};  //用于传递整型R值的数组
    double dR_Arr[R_NUM] = {0.0};  //用于传递浮点型R值的数组

    QString qStrValue = "";

    SPRReg fPRValueArr[PR_NUM] = {};    //存放PR界面的寄存器值数值

    bool DIO_UIO_Arr[240] = {}; //存放DIO/UIO界面的寄存器值数值

    CLinkRobot *linkRobot; // 声明 CLinkRobot 对象的指针
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
