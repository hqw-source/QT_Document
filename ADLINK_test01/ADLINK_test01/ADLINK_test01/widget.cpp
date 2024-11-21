#include "widget.h"
#include "ui_widget.h"
#include "dataanalyse.h"
#include "Dask64.h"
#include <QChart>
#include <QtCharts>
#include <QGraphicsWidget>
#include <QProcess>
#include <conio.h>
static QChart *chart0;
static QValueAxis *axsisX0;
static QValueAxis *axsisY0;
static QLineSeries *seriesQ;
static QLineSeries *seriesP1;
static QLineSeries *seriesP2;
static QLineSeries *seriesW;
static QLineSeries *seriesT;
static QLineSeries *seriesL;
static QChartView *cview0;
//单次采样按钮
bool onceSam_flag=0;
int onceSamCount=0;
//采样时间值
static int timeCount_ms=0;
static int timeCount_s=0;
static U16 cardifo=PCI_9111DG;//HR
static int timeCount=0;
//表格数据
QString data_Q;
QString data_P1;
QString data_P2;
//表格行数
int tableRowCount=0;
//采集数据
int Err=0,card=0;
U16 voltage_Q=0,voltage_P1=0,voltage_P2=0;
U16 voltage_W=0,voltage_L=0,voltage_T=0;
float float_Q,float_P1,float_P2;
float float_W,float_L,float_T;
//采集卡注册标志位
bool Register_flag=0;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置数据分析和参数设置信号与槽
    m_c = new dataAnalyse(this);
    connect(m_c,QOverload<>::of(&dataAnalyse::openWidgetSignal),this,QOverload<>::of(&Widget::showWidget));
    /*******************数据初始化*************************/
    ui->stopSamplingBtn->setEnabled(false);
    ui->onceSamplingBtn->setEnabled(false);
    /********************软件界面*************************/
    setWindowTitle("当前状态：液压综合实验装置采集系统软件V1.0");
    //设置窗口大小
    setFixedSize(1900,900);
    ui->GDUTlabel->setStyleSheet("border-image: url(:/resource/images/GDUTlogo.png);");
    ui->startLabel->setStyleSheet("border-image: url(:/resource/images/startImg.png);");
    ui->stopLabel->setStyleSheet("border-image: url(:/resource/images/stopImg.png);");
    ui->dataAnalysisLabel->setStyleSheet("border-image: url(:/resource/images/dataAnalysisImg.png);");
    ui->clearDataLabel->setStyleSheet("border-image: url(:/resource/images/clearDataImg.png);");
    ui->tableSetLabel->setStyleSheet("border-image: url(:/resource/images/curveSetImg.png);");
    ui->curveDisplayLabel->setStyleSheet("border-image: url(:/resource/images/curveDisplayImg.png);");
    ui->QDisplayLabel->setStyleSheet("border-image: url(:/resource/images/qImg.png);");
    ui->P1DisplayLabel->setStyleSheet("border-image: url(:/resource/images/pImg1.png);");
    ui->P2DisplayLabel->setStyleSheet("border-image: url(:/resource/images/pImg2.png);");
    ui->WDisplayLabel->setStyleSheet("border-image: url(:/resource/images/wImg.png);");
    ui->TDisplayLabel->setStyleSheet("border-image: url(:/resource/images/tImg.png);");
    ui->NDisplayLabel->setStyleSheet("border-image: url(:/resource/images/sImg.png);");
    ui->realTimeDisplayIabel->setStyleSheet("border-image: url(:/resource/images/realTimePisplayImg.png);");
    ui->xAxisTableLabel->setStyleSheet("border-image: url(:/resource/images/xAxisImg.png);");
    ui->yAxisTableLabel->setStyleSheet("border-image: url(:/resource/images/yAxisImg.png);");
    ui->startLabel_once->setStyleSheet("border-image: url(:/resource/images/once.png);");
    /******************软件参数初始化*********************/
    // 曲线颜色提示
    QPalette palette = ui->P1labelColor->palette();
    // 将调色板的背景角色（background role）设置为红色
    palette.setColor(QPalette::Window, Qt::red);
    // 压力P1
    ui->P1labelColor->setAutoFillBackground(true);
    ui->P1labelColor->setPalette(palette);
    // 压力P2
    palette.setColor(QPalette::Window, Qt::blue);
    ui->P2labelColor->setAutoFillBackground(true);
    ui->P2labelColor->setPalette(palette);
    // 流量Q
    palette.setColor(QPalette::Window, Qt::black);
    ui->QlabelColor->setAutoFillBackground(true);
    ui->QlabelColor->setPalette(palette);
    // 功率W
    palette.setColor(QPalette::Window, Qt::green);
    ui->WlabelColor->setAutoFillBackground(true);
    ui->WlabelColor->setPalette(palette);
    // 油温T
    palette.setColor(QPalette::Window, QColor(255,165,0));
    ui->TlabelColor->setAutoFillBackground(true);
    ui->TlabelColor->setPalette(palette);
    // 位移L
    palette.setColor(QPalette::Window, QColor(0,255,255));//天蓝
    ui->NlabelColor->setAutoFillBackground(true);
    ui->NlabelColor->setPalette(palette);
    /********************图表界面************************/
    /***********采集通道0的曲线图显示界面*************/
    cview0=new QChartView(this);
    chart0 = new QChart();
    chart0->setTitle("数据采集实时曲线图");
    chart0->setTitleFont(QFont("楷体",20,QFont::Black,false));
    cview0->setChart(chart0);
    cview0->setRenderHint(QPainter::Antialiasing);
    cview0->resize(1461,816);
    axsisX0=new QValueAxis();
    axsisY0=new QValueAxis();
    axsisX0->setTitleFont(QFont("黑体",16,QFont::Medium,false));
    axsisX0->setTitleText("时间/ms");
    axsisX0->setLabelsFont(QFont("黑体",13,QFont::Medium,false));
    axsisX0->setRange(0,ui->xAxisMaxSlider->value());
    axsisY0->setLabelsFont(QFont("黑体",13,QFont::Medium,false));
    axsisY0->setRange(ui->yAxisMinSpinBox->value(), ui->yAxisMaxSpinBox->value());
    axsisY0->setTitleFont(QFont("黑体",16,QFont::Medium,false));
    axsisY0->setTitleText("数值");
    axsisX0->setTickCount(9);
    axsisY0->setTickCount(9);
    //添加流量Q曲线到图表中
    seriesQ=new QLineSeries();
    seriesQ->setName("流量Q");
    chart0->addSeries(seriesQ);
    chart0->addAxis(axsisX0,Qt::AlignBottom);
    chart0->addAxis(axsisY0,Qt::AlignLeft);
    seriesQ->attachAxis(axsisX0);
    seriesQ->attachAxis(axsisY0);
    seriesQ->setColor(Qt::black);
    //添加压力P1曲线到图表中
    seriesP1=new QLineSeries();
    seriesP1->setName("压力P1");
    chart0->addSeries(seriesP1);
    seriesP1->attachAxis(axsisX0);
    seriesP1->attachAxis(axsisY0);
    seriesP1->setColor(Qt::red);
    //添加压力P2曲线到图表中
    seriesP2=new QLineSeries();
    seriesP2->setName("压力P2");
    chart0->addSeries(seriesP2);
    seriesP2->attachAxis(axsisX0);
    seriesP2->attachAxis(axsisY0);
    seriesP2->setColor(Qt::blue);
    //添加功率W曲线到图表中
    seriesW=new QLineSeries();
    seriesW->setName("功率W");
    chart0->addSeries(seriesW);
    seriesW->attachAxis(axsisX0);
    seriesW->attachAxis(axsisY0);
    seriesW->setColor(Qt::green);
    //添加油温C曲线到图表中
    seriesT=new QLineSeries();
    seriesT->setName("油温T");
    chart0->addSeries(seriesT);
    seriesT->attachAxis(axsisX0);
    seriesT->attachAxis(axsisY0);
    seriesT->setColor(QColor(255,145,0));
    //添加位位移L曲线到图表中
    seriesL=new QLineSeries();
    seriesL->setName("位移L");
    chart0->addSeries(seriesL);
    seriesL->attachAxis(axsisX0);
    seriesL->attachAxis(axsisY0);
    seriesL->setColor(QColor(0,255,255));
    /**************功能控制区显示*************/
    data_Q=QString::fromStdString("数据通道0");
    data_P1=QString::fromStdString("数据通道1");
    data_P2=QString::fromStdString("数据通道2");
    /**********开始保存采样数据时间显示*********/
    connect(timer1,&QTimer::timeout,this,[=](){
        timeCount_ms++;
        if(timeCount_ms==1000) {
        timeCount_ms=0;
        timeCount_s++;
        }
        ui->samplingTimeLCD_ms->display(timeCount_ms);
        ui->samplingTimeLCD_s->display(timeCount_s);
        //读取0通道的数据,流量Q数据
        Err = AI_ReadChannel(card, 0, AD_B_10_V, &voltage_Q);
        if(Err<0){
         QMessageBox::critical(this,"error code",QString::number(Err));
         timer1->stop();
         return;
        }
        //读取1通道的数据,流量P1数据
        Err = AI_ReadChannel(card, 1, AD_B_10_V, &voltage_P1);
        if(Err<0){
         QMessageBox::critical(this,"error code",QString::number(Err));
         timer1->stop();
         return;
        }
        //读取2通道的数据,流量P2数据
        Err = AI_ReadChannel(card, 2, AD_B_10_V, &voltage_P2);
        if(Err<0){
         QMessageBox::critical(this,"error code",QString::number(Err));
         timer1->stop();
         return;
        }
        //读取3通道的数据,功率W数据
        Err = AI_ReadChannel(card, 3, AD_B_10_V, &voltage_W);
        if(Err<0){
         QMessageBox::critical(this,"error code",QString::number(Err));
         timer1->stop();
         return;
        }
        //读取4通道的数据,油温C数据
        Err = AI_ReadChannel(card, 4, AD_B_10_V, &voltage_T);
        if(Err<0){
         QMessageBox::critical(this,"error code",QString::number(Err));
         timer1->stop();
         return;
        }
        //读取5通道的数据,位移L数据
        Err = AI_ReadChannel(card, 5, AD_B_10_V, &voltage_L);
        if(Err<0){
         QMessageBox::critical(this,"error code",QString::number(Err));
         timer1->stop();
         return;
        }
        //0通道的数据,流量Q数据
        if(voltage_Q<=3265)
        {
            float_Q=0;
        }
        else if(voltage_Q>3265)
        {
            float_Q=float(voltage_Q-3265)/874;
        }
        //1通道的数据,流量P1数据
        if(voltage_P1<=3300)
        {
            float_P1=0;
        }
        else if(voltage_P1>3300)
        {
            float_P1=float(voltage_P1-3300)/1274;
        }
        //2通道的数据,流量P2数据
        if(voltage_P2<=3300)
        {
            float_P2=0;
        }
        else if(voltage_P2>3300)
        {
            float_P2=float(voltage_P2-3300)/1274;
        }
        //3通道的数据,功率W数据
        if(voltage_W<=3350)
        {
            float_W=0;
        }
        else if(voltage_W>3350)
        {
            float_W=float(voltage_W-3350)/2535;
        }
        //4通道的数据,油温C数据
        if(voltage_T<=4400)
        {
            float_T=0;
        }
        else if(voltage_T>4400)
        {
            float_T=float(voltage_T-4400)/73;
        }
        //5通道的数据,位移L数据
        if(voltage_L<=3305)
        {
            float_L=0;
        }
        else if(voltage_L>3305)
        {
            float_L=float(voltage_L-3305)/65.4;
        }
        //以设定采样周期显示数据
        if((timeCount_s*1000+timeCount_ms)%ui->SampliePeriodSpinBox->value()==0)
        {
        if(bool(ui->onceSamplingBtn->isEnabled())==false&&bool(ui->unautoSamplybox->checkState())==true)
        ui->onceSamplingBtn->setEnabled(true);
        timeCount+=ui->SampliePeriodSpinBox->value();
        if(bool(ui->unautoSamplybox->checkState())==false)
            tableRowCount++;
        else
        {
            tableRowCount=onceSamCount+1;
        }
        data_Q=QString::number(double(float_Q),'f',2);
        data_P1=QString::number(double(float_P1),'f',2);
        data_P2=QString::number(double(float_P2),'f',2);
        seriesQ->append(timeCount,float_Q);
        seriesP1->append(timeCount,float_P1);
        seriesP2->append(timeCount,float_P2);
        seriesW->append(timeCount,float_W);
        seriesT->append(timeCount,float_T);
        seriesL->append(timeCount,float_L);
        ui->LCD_Q->display(data_Q);
        ui->LCD_P1->display(data_P1);
        ui->LCD_P2->display(data_P2);
        ui->LCD_W->display(float_W);
        ui->LCD_T->display(float_T);
        ui->LCD_L->display(float_L);
        // qDebug()<<"流量Q="<<QString::number(float_Q,'f',2)<<"压力P1="<<QString::number(float_P1,'f',2)
        //         <<"压力P2="<<QString::number(float_P2,'f',2)<<timeCount_s<<":"<<timeCount_ms;
        }
    });
}
Widget::~Widget()
{
    delete ui;
}
void Widget::showWidget()
{
    m_c->hide();
    this->setEnabled(true);
}
//打开数据分析窗口
void Widget::on_dataAnlBtn_clicked()
{
    //停止定时器
    timer1->stop();
    m_c->timer2->stop();
    // this->hide();
    this->setEnabled(false);
    m_c->show();
    m_c->setEnabled(true);
    ui->startSamplingBtn->setEnabled(true);
    ui->stopSamplingBtn->setEnabled(false);
    ui->onceSamplingBtn->setEnabled(false);
}
//数据清除
void Widget::on_dataClearBtn_clicked()
{
    timer1->stop();
    m_c->clearData();
    seriesQ->clear();
    seriesP1->clear();
    seriesP2->clear();
    seriesL->clear();
    seriesT->clear();
    seriesW->clear();
    data_Q=QString::fromStdString("数据通道0");
    data_P1=QString::fromStdString("数据通道1");
    data_P2=QString::fromStdString("数据通道2");
    timeCount_ms=timeCount_s=0;
    timeCount=0;
    tableRowCount=0;
    ui->samplingTimeLCD_ms->display(0);
    ui->samplingTimeLCD_s->display(0);
    ui->stopSamplingBtn->setEnabled(false);
    ui->startSamplingBtn->setEnabled(true);
    ui->onceSamplingBtn->setEnabled(false);
    onceSamCount=0;
    ui->samplyCountDisplay->display(onceSamCount);
    ui->unautoSamplybox->setEnabled(true);
}
//图表X、Y轴范围设置
//图标X轴最大值
void Widget::on_xAxisMaxSpinBox_valueChanged(int)
{
    axsisX0->setRange(ui->xAxisMinSpinBox->value(), ui->xAxisMaxSpinBox->value());
    if(ui->xAxisMaxSpinBox->value()<ui->xAxisMinSpinBox->value())
    {
        ui->xAxisMaxSlider->setValue(ui->xAxisMinSpinBox->value());
        ui->xAxisMaxSlider->setValue(ui->xAxisMiniSlider->value());
    }
}
//图标X轴最小值
void Widget::on_xAxisMinSpinBox_valueChanged(int)
{
    axsisX0->setRange(ui->xAxisMinSpinBox->value(), ui->xAxisMaxSpinBox->value());
    if(ui->xAxisMinSpinBox->value()>ui->xAxisMaxSpinBox->value())
    {
        ui->xAxisMinSpinBox->setValue(ui->xAxisMaxSlider->value());
        ui->xAxisMiniSlider->setValue(ui->xAxisMaxSlider->value());
    }
}
//图标Y轴最大值
void Widget::on_yAxisMaxSpinBox_valueChanged(int)
{
    axsisY0->setRange(ui->yAxisMinSpinBox->value(), ui->yAxisMaxSpinBox->value());
}
//图表Y轴最小值
void Widget::on_yAxisMinSpinBox_valueChanged(int)
{
    axsisY0->setRange(ui->yAxisMinSpinBox->value(), ui->yAxisMaxSpinBox->value());
}
//开始采样
void Widget::on_startSamplingBtn_clicked()
{
    if(Register_flag==0)
    {
         Register_flag=1;
         //注册采集卡
        card=Register_Card(cardifo,0);
        if((Err=card)<0)
        {
            QMessageBox::critical(this,"error code",QString::number(Err));
            return;
        }
        //初始化采集卡
         Err=AI_9111_Config(card, TRIG_INT_PACER, P9111_TRGMOD_SOFT, 0);
         if(Err<0)
         {
         QMessageBox::critical(this,"error code",QString::number(Err));
             return;
         }
     }
     //启动定时器
    timer1->start(1);
    m_c->timer2->start(1);
    ui->startSamplingBtn->setEnabled(false);
    ui->stopSamplingBtn->setEnabled(true);
    ui->unautoSamplybox->setEnabled(false);
}
//停止采样
void Widget::on_stopSamplingBtn_clicked()
{
    //停止定时器
    timer1->stop();
    m_c->timer2->stop();
    ui->stopSamplingBtn->setEnabled(false);
    ui->startSamplingBtn->setEnabled(true);
    ui->onceSamplingBtn->setEnabled(false);
    ui->unautoSamplybox->setEnabled(true);
}
//流量Q曲线显示/隐藏
void Widget::on_Q_CheckBox_stateChanged(int )
{
    if(bool(ui->Q_CheckBox->checkState())==0)
    seriesQ->hide();
    if(bool(ui->Q_CheckBox->checkState())==1)
    seriesQ->show();
}
//压力P1曲线显示/隐藏
void Widget::on_P1_CheckBox_stateChanged(int )
{
    if(bool(ui->P1_CheckBox->checkState())==0)
    seriesP1->hide();
    if(bool(ui->P1_CheckBox->checkState())==1)
    seriesP1->show();
}
//压力P2曲线显示/隐藏
void Widget::on_P2_CheckBox_stateChanged(int )
{
    if(bool(ui->P2_CheckBox->checkState())==0)
    seriesP2->hide();
    if(bool(ui->P2_CheckBox->checkState())==1)
    seriesP2->show();
}
//功率W曲线显示/隐藏
void Widget::on_W_CheckBox_stateChanged(int )
{
    if(bool(ui->W_CheckBox->checkState())==0)
    seriesW->hide();
    if(bool(ui->W_CheckBox->checkState())==1)
    seriesW->show();
}
//油温T曲线显示/隐藏
void Widget::on_T_CheckBox_stateChanged(int )
{
    if(bool(ui->T_CheckBox->checkState())==0)
    seriesT->hide();
    if(bool(ui->T_CheckBox->checkState())==1)
    seriesT->show();
}
//位移L曲线显示/隐藏
void Widget::on_N_CheckBox_stateChanged(int )
{
    if(bool(ui->N_CheckBox->checkState())==0)
    seriesL->hide();
    if(bool(ui->N_CheckBox->checkState())==1)
    seriesL->show();
}
//单次采样
void Widget::on_onceSamplingBtn_clicked()
{
    ui->onceSamplingBtn->setEnabled(false);
     if(bool(ui->unautoSamplybox->checkState())==true)
    {
        m_c->timer2->start(1);
        onceSam_flag=1;
    }
     onceSamCount++;
    ui->samplyCountDisplay->display(onceSamCount);
}
void Widget::on_unautoSamplybox_stateChanged(int arg1)
{
    if(bool(ui->unautoSamplybox->checkState())==true&&bool(ui->startSamplingBtn->isCheckable())==true)
    ui->onceSamplingBtn->setEnabled(true);
    else
    ui->onceSamplingBtn->setEnabled(false);
}

