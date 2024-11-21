#include "dataanalyse.h"
#include "qmessagebox.h"
#include "ui_dataanalyse.h"
#include <QFileDialog>
#include <QDebug>
#include <QAxObject>
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QTableWidget>
#include <QString>
#include <QWidget>
#include <QMessageBox>
extern QString data_Q;
extern QString data_P1;
extern QString data_P2;
extern int tableRowCount;
extern bool onceSam_flag;
dataAnalyse::dataAnalyse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dataAnalyse)
{
    ui->setupUi(this);
    /********************软件界面*************************/
    setWindowTitle("当前状态:液压综合实验装置采集系统软件V1.0->数据分析");
    //设置窗口大小
    setFixedSize(1600,900);
    setWindowFlag(Qt::WindowCloseButtonHint, false); //不显示右上角关闭
    setWindowFlag(Qt::WindowMinMaxButtonsHint,false);//不显示最小化
    //表格数据初始化
    ui->tableWidget->setRowCount(1000);
    connect(timer2,&QTimer::timeout,this,[=](){
    ui->tableWidget->setItem(tableRowCount,0,new QTableWidgetItem(data_Q));
    ui->tableWidget->item(tableRowCount, 0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(tableRowCount,1,new QTableWidgetItem(data_P1));
    ui->tableWidget->item(tableRowCount, 1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(tableRowCount,2,new QTableWidgetItem(data_P2));
    ui->tableWidget->item(tableRowCount, 2)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(tableRowCount,3,new QTableWidgetItem("无"));
    ui->tableWidget->item(tableRowCount, 3)->setTextAlignment(Qt::AlignCenter);
    if(onceSam_flag==1)
    {
        timer2->stop();
        onceSam_flag=0;
        ui->tableWidget->setItem(tableRowCount,0,new QTableWidgetItem(data_Q));
        ui->tableWidget->item(tableRowCount, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(tableRowCount,1,new QTableWidgetItem(data_P1));
        ui->tableWidget->item(tableRowCount, 1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(tableRowCount,2,new QTableWidgetItem(data_P2));
        ui->tableWidget->item(tableRowCount, 2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(tableRowCount,3,new QTableWidgetItem("无"));
        ui->tableWidget->item(tableRowCount, 3)->setTextAlignment(Qt::AlignCenter);
    }
    });
    for(int i=0;i<7;i++)
    ui->tableWidget->setColumnWidth(i,280);
}
dataAnalyse::~dataAnalyse()
{
    delete ui;
}
void dataAnalyse::clearData()
{
    //清除曲线数据和表格数据
    timer2->stop();
    ui->tableWidget->clearContents();
}
//返回Widget窗口
void dataAnalyse::on_backWidgetBtn_clicked()
{
    this->hide();
    emit openWidgetSignal();
}
//保存数据按钮
void dataAnalyse::on_readDataBtn_clicked()
{
    ui->tableWidget->setRowCount(tableRowCount);
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Excle 保存路径"),QString("./test.xlsx"),tr("Excel Files(*.xlsx)"));
    qDebug()<<fileName;
    ui->filePathText->setText(fileName);
    if(fileName != nullptr)
    {
        QAxObject *excel = new QAxObject;
        if(excel->setControl("Excel.Application"))
        {
            excel->dynamicCall("SetVisible (bool Visible)",false);
            excel->setProperty("DisplayAlerts",false);
            QAxObject *workbooks = excel->querySubObject("WorkBooks");
            workbooks->dynamicCall("Add");
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
            QAxObject *cell;
            int rowCount = ui->tableWidget->rowCount();
            int columnCount = ui->tableWidget->columnCount();
            qDebug()<<"columnCount"<<columnCount<<"rowCount"<<rowCount;
            //保存水平和垂直方向上的表格头
            for(int i=1;i <= columnCount ; i++)
            {
                cell = worksheet->querySubObject("Cells(int,int)", 1, i);
                cell->dynamicCall("SetValue(const QString&)", ui->tableWidget->horizontalHeaderItem(i-1)->data(0).toString());
            }
            //无数据或缺少数据会崩溃
            for(int i=1;i <= rowCount ; i++)
            {
                for(int j=1;j <= columnCount ; j++)
                {
                    cell = worksheet->querySubObject("Cells(int,int)", i+1, j);
                    cell->dynamicCall("SetValue(const QString&)", ui->tableWidget->item(i-1,j-1)->data(0).toString());
                }
            }
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));
            workbook->dynamicCall("Close()");
            excel->dynamicCall("Quit()");
            delete excel;
            excel = NULL;
            ui->tableWidget->setRowCount(1000);
            QMessageBox::information(this,"提示","保存成功");
        }
    }
    else  ui->tableWidget->setRowCount(1000);
}

