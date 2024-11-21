#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clinkrobot.h"
#include "workerthread.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initAllWidget();  //初始化界面
    linkRobot = new CLinkRobot; //实例化CLinkRobot对象

    /********************mytest************/
    WorkerThread *workerThread = new WorkerThread();
    connect(workerThread, &WorkerThread::triggerSendMsg, this, &MainWindow::sendandrec);  // 连接信号和槽

    // 连接信号和槽
    connect(ui->regComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::selectRegWidget);

    //连接客户端
    connect(ui->connectBtn,&QPushButton::clicked,this,[=](){
        quint16 port = ui->portLineEdit->text().toUInt();    //获取需要连接的端口号
        QString ipAddress = ui->ipLineEdit->text(); // 从QLineEdit获取IP地址
        linkRobot->connectRobot(ipAddress,port);
        QThread::sleep(4);
        workerThread->start();
    });

    //断开客户端
    connect(ui->disconnectBtn,&QPushButton::clicked,this,[=](){
        linkRobot->disconnectRobot();
    });


    connect(linkRobot,&CLinkRobot::connected,this,[=](){
        ui->connectBtn->setEnabled(false);
        ui->sendBtn->setEnabled(true);
    });
    connect(linkRobot,&CLinkRobot::unConnected,this,[=](){
        ui->connectBtn->setEnabled(true);
        ui->sendBtn->setEnabled(false);
    });


    connect(ui->R_Widget,&QTableWidget::cellChanged,this,&MainWindow::updateRArr);  //R界面的值改动时，更新R
    connect(ui->PR_Widget,&QTableWidget::cellChanged,this,&MainWindow::updatePRArr);    //PR界面的值改动时，更新PR
    connect(ui->SR_Widget,&QTableWidget::cellChanged,this,&MainWindow::updateSRArr);    //SR界面的值改动时，更新SR
    connect(ui->DI_DO_Widget,&QTableWidget::cellChanged,this,&MainWindow::updateDI_DO_Arr);    //DIO界面的值改动时，更新DIO
    connect(ui->UI_UO_Widget,&QTableWidget::cellChanged,this,&MainWindow::updateUI_UO_Arr);    //UIO界面的值改动时，更新UIO

    connect(ui->sendBtn,&QPushButton::clicked,this,&MainWindow::sendMsg);
}
void MainWindow::sendandrec()
{
    SPRReg myxyzwpr;
    auto bIsSuccessful=linkRobot->readPR(1,1,&myxyzwpr);
    if ( !bIsSuccessful)
        return;
    qDebug()<<"test"<<myxyzwpr.X<<myxyzwpr.Y<<myxyzwpr.Z<<myxyzwpr.W<<myxyzwpr.P<<myxyzwpr.R;
    myxyzwpr.X=1;
    myxyzwpr.Y=0;
    myxyzwpr.Z=1;
    myxyzwpr.W=0;
    myxyzwpr.P=1;
    myxyzwpr.R=0;
    linkRobot->writePR(1,1,&myxyzwpr);
}
/*************************************************
  函数名称：sendMsg()
  函数功能：获取调试界面的命令信息，调用相应读写函数
  输入参数：无
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::sendMsg()
{
    // 获取当前选择的读写类型（即与其关联的值）
    int nCmadType = ui->RWComboBox->currentData().toInt();
    qDebug() << "当前选择的读写类型为:" << nCmadType <<": "<< ui->RWComboBox->currentText();
    // 获取当前选择的寄存器类型（即与其关联的值）
    int nRegType = ui->regComboBox->currentData().toInt();
    qDebug() << "当前选择的寄存器类型为:" << nRegType <<": " << ui->regComboBox->currentText();
    // 获取寄存器的起始地址
    int nStartRegNum = ui->startSB->value();
    qDebug() << "寄存器起始地址为:" << nStartRegNum;
    // 获取需要操作的寄存器个数
    int nRegNums = ui->numSB->value();
    qDebug() << "需要操作的寄存器个数为:" << nRegNums;

    int nValue = 0;
    double dValue = 0.0;
    bool bValue = false;

    if('R' == nCmadType)   //读
    {
        switch (nRegType) {
        case NR_REG: //整形R
            if(nRegNums == 1) {   //读单个整形R
                bIsSuccessful = linkRobot->readR(nStartRegNum, &nValue);
                if ( !bIsSuccessful)
                    return;
                qDebug()<< "行：" << nStartRegNum-1 << "值为："<< nValue;
                updateR_Widget(nStartRegNum, nValue);
            }
            else{   //读多个整形R
                bIsSuccessful = linkRobot->readR(nStartRegNum, nRegNums, nR_Arr);
                if ( !bIsSuccessful)
                    return;
                for(int i=0; i<nRegNums; ++i){
                    qDebug()<< "行："<< nStartRegNum-1 << "值为："<< nR_Arr[i];
                    updateR_Widget(nStartRegNum, nR_Arr[i]);
                    nStartRegNum += 1;
                }
            }
            break;

        case FR_REG: //浮点型R
            if(nRegNums == 1) {   //读单个浮点R
                bIsSuccessful = linkRobot->readR(nStartRegNum,&dValue);
                if ( !bIsSuccessful)
                    return;
                qDebug()<< "行："<< nStartRegNum-1 << "值为："<< dValue;
                updateR_Widget(nStartRegNum, dValue);
            }
            else{   //读多个浮点R
                bIsSuccessful = linkRobot->readR(nStartRegNum, nRegNums, dR_Arr);
                if ( !bIsSuccessful)
                    return;
                for(int i=0; i<nRegNums; ++i){
                    qDebug()<<"行："<<nStartRegNum-1 <<"值为："<<dR_Arr[i];
                    updateR_Widget(nStartRegNum, dR_Arr[i]);
                    nStartRegNum += 1;
                }
            }
            break;
        case SR_REG: //SR
            bIsSuccessful = linkRobot->readSR(nStartRegNum,&qStrValue);
            if ( !bIsSuccessful)
                return;
            updateSR_Widget(nStartRegNum,qStrValue);
            break;
        case PR_REG: //PR
            if(nRegNums == 1) {   //读单个PR
                bIsSuccessful = linkRobot->readPR(nStartRegNum,fPRValueArr);
            }
            else{   //读多个PR
                bIsSuccessful = linkRobot->readPR(nStartRegNum, nRegNums, fPRValueArr);
            }
            if ( !bIsSuccessful)
                return;

            for(int i=0; i<nRegNums; ++i){
                updatePR_Widget(nStartRegNum, 1, fPRValueArr[i].X);
                updatePR_Widget(nStartRegNum, 2, fPRValueArr[i].Y);
                updatePR_Widget(nStartRegNum, 3, fPRValueArr[i].Z);
                updatePR_Widget(nStartRegNum, 4, fPRValueArr[i].W);
                updatePR_Widget(nStartRegNum, 5, fPRValueArr[i].P);
                updatePR_Widget(nStartRegNum, 6, fPRValueArr[i].R);
                nStartRegNum += 1;
                qDebug()<<"行："<<nStartRegNum-1 <<"值为："<<fPRValueArr[i].X<<" ,"<<fPRValueArr[i].Y<<" ,"<<
                    fPRValueArr[i].Z<<" ,"<<fPRValueArr[i].W<<" ,"<<fPRValueArr[i].P<<" ,"<<fPRValueArr[i].R;
            }
            break;
        case DI_REG: //DI
            if(nRegNums == 1) {   //读单个DI
                bIsSuccessful = linkRobot->readDI(nStartRegNum, &bValue);
                if ( !bIsSuccessful)
                    return;
                qDebug()<< "行：" << nStartRegNum-1 << "值为："<< bValue;
                updateDIO_UIO_Widget(DI_REG,nStartRegNum, bValue);
            }
            else{   //读多个DI
                bIsSuccessful = linkRobot->readDI(nStartRegNum, nRegNums, DIO_UIO_Arr);
                if ( !bIsSuccessful)
                    return;
                for(int i=0; i<nRegNums; ++i){
                    qDebug()<< "行："<< nStartRegNum-1 << "值为："<< DIO_UIO_Arr[i];
                    updateDIO_UIO_Widget(DI_REG,nStartRegNum, DIO_UIO_Arr[i]);
                    nStartRegNum += 1;
                }
            }
            break;
        case DO_REG: //DO
            if(nRegNums == 1) {   //读单个DO
                bIsSuccessful = linkRobot->readDO(nStartRegNum, &bValue);
                if ( !bIsSuccessful)
                    return;
                qDebug()<< "行：" << nStartRegNum-1 << "值为："<< bValue;
                updateDIO_UIO_Widget(DO_REG,nStartRegNum, bValue);
            }
            else{   //读多个DO
                bIsSuccessful = linkRobot->readDO(nStartRegNum, nRegNums, DIO_UIO_Arr);
                if ( !bIsSuccessful)
                    return;
                for(int i=0; i<nRegNums; ++i){
                    qDebug()<< "行："<< nStartRegNum-1 << "值为："<< DIO_UIO_Arr[i];
                    updateDIO_UIO_Widget(DO_REG,nStartRegNum, DIO_UIO_Arr[i]);
                    nStartRegNum += 1;
                }
            }
            break;
        case UI_REG: //UI
            if(nRegNums == 1) {   //读单个UI
                bIsSuccessful = linkRobot->readUI(nStartRegNum, &bValue);
                if ( !bIsSuccessful)
                    return;
                qDebug()<< "行：" << nStartRegNum-1 << "值为："<< bValue;
                updateDIO_UIO_Widget(UI_REG,nStartRegNum, bValue);
            }
            else{   //读多个UI
                bIsSuccessful = linkRobot->readUI(nStartRegNum, nRegNums, DIO_UIO_Arr);
                if ( !bIsSuccessful)
                    return;
                for(int i=0; i<nRegNums; ++i){
                    qDebug()<< "行："<< nStartRegNum-1 << "值为："<< DIO_UIO_Arr[i];
                    updateDIO_UIO_Widget(UI_REG,nStartRegNum, DIO_UIO_Arr[i]);
                    nStartRegNum += 1;
                }
            }
            break;
        case UO_REG: //UO
            if(nRegNums == 1) {   //读单个UO
                bIsSuccessful = linkRobot->readUO(nStartRegNum, &bValue);
                if ( !bIsSuccessful)
                    return;
                qDebug()<< "行：" << nStartRegNum-1 << "值为："<< bValue;
                updateDIO_UIO_Widget(UO_REG,nStartRegNum, bValue);
            }
            else{   //读多个UO
                bIsSuccessful = linkRobot->readUO(nStartRegNum, nRegNums, DIO_UIO_Arr);
                if ( !bIsSuccessful)
                    return;
                for(int i=0; i<nRegNums; ++i){
                    qDebug()<< "行："<< nStartRegNum-1 << "值为："<< DIO_UIO_Arr[i];
                    updateDIO_UIO_Widget(UO_REG,nStartRegNum, DIO_UIO_Arr[i]);
                    nStartRegNum += 1;
                }
            }
            break;
        }
    }
    else{   //写报文
        switch (nRegType) {
        case NR_REG: //整形R寄存器
            if(nRegNums == 1) {   //写单个整形R寄存器
                nValue = static_cast<int>(dR_Arr[nStartRegNum-1]);
                linkRobot->writeR(nStartRegNum, nValue);
            }
            else{   //写多个整形R寄存器
                int j = nStartRegNum-1;
                for(int i=0; i<nRegNums; ++i){
                    nR_Arr[i] = static_cast<int>(dR_Arr[j]);
                    ++j;
                }
                linkRobot->writeR(nStartRegNum,nRegNums,nR_Arr);
            }

            break;
        case FR_REG: //浮点R寄存器
            if(nRegNums == 1) {   //写单个浮点R寄存器
                linkRobot->writeR(nStartRegNum,dR_Arr[nStartRegNum-1]);
            }
            else{   //写多个浮点R寄存器
                linkRobot->writeR(nStartRegNum,nRegNums,&dR_Arr[nStartRegNum-1]);
            }


            break;
        case SR_REG: //SR
            linkRobot->writeSR(nStartRegNum,&qStrValue);
            break;
        case PR_REG: //PR
            if(nRegNums == 1) {   //写单个PR
                linkRobot->writePR(nStartRegNum,&fPRValueArr[nStartRegNum-1]);
            }
            else{   //写多个PR
                linkRobot->writePR(nStartRegNum,nRegNums,&fPRValueArr[nStartRegNum-1]);
            }
            break;
        case DI_REG: //DI
            if(nRegNums == 1) {   //写单个DI
                linkRobot->writeDI(nStartRegNum, DIO_UIO_Arr[nStartRegNum-1]);
            }
            else{   //写多个DI
                linkRobot->writeDI(nStartRegNum,nRegNums,&DIO_UIO_Arr[nStartRegNum-1]);
            }
            break;
        case DO_REG: //DO
            if(nRegNums == 1) {   //写单个DO
                linkRobot->writeDO(nStartRegNum, DIO_UIO_Arr[nStartRegNum-1]);
            }
            else{   //写多个DO
                linkRobot->writeDO(nStartRegNum,nRegNums,&DIO_UIO_Arr[nStartRegNum-1]);
            }
            break;
        case UI_REG: //UI
            if(nRegNums == 1) {   //写单个UI
                linkRobot->writeUI(nStartRegNum, DIO_UIO_Arr[nStartRegNum-1]);
            }
            else{   //写多个UI
                linkRobot->writeUI(nStartRegNum,nRegNums,&DIO_UIO_Arr[nStartRegNum-1]);
            }
            break;
        case UO_REG: //UO
            if(nRegNums == 1) {   //写单个UO
                linkRobot->writeUO(nStartRegNum, DIO_UIO_Arr[nStartRegNum-1]);
            }
            else{   //写多个UO
                linkRobot->writeUO(nStartRegNum,nRegNums,&DIO_UIO_Arr[nStartRegNum-1]);
            }
            break;
        }
    }
}

/*************************************************
  函数名称：initAllWidget()
  函数功能：初试化所有寄存器值界面
  输入参数：无
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::initAllWidget()
{
    //设置ui界面的一些东西
    ui->RWComboBox->addItem("读（R）",82);
    ui->RWComboBox->addItem("写（W）",87);

    ui->regComboBox->addItem("整型R寄存器",1);
    ui->regComboBox->addItem("浮点R寄存器",2);
    ui->regComboBox->addItem("SR寄存器",3);
    ui->regComboBox->addItem("PR寄存器",4);
    ui->regComboBox->addItem("DI寄存器",5);
    ui->regComboBox->addItem("DO寄存器",6);
    ui->regComboBox->addItem("UI寄存器",7);
    ui->regComboBox->addItem("UO寄存器",8);

    //设置能够选择R寄存器的范围
    ui->startSB->setRange(1,200);
    ui->numSB->setRange(1,57);

    //将发送按钮置为false
    ui->sendBtn->setEnabled(false);

    initRWidget();

    initWidget(ui->SR_Widget,"SR",SR_NUM,0);

    initPRWidget();

    initWidget(ui->DI_DO_Widget,"DI",DI_NUM,0);
    initWidget(ui->DI_DO_Widget,"DO",DO_NUM,2);

    initWidget(ui->UI_UO_Widget,"UI",UI_NUM,0);
    initWidget(ui->UI_UO_Widget,"UO",UO_NUM,2);

}

/*************************************************
  函数名称：initRWidget()
  函数功能：初试化R寄存器值界面
  输入参数：无
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::initRWidget()
{
    //设置R寄存器表格
    ui->R_Widget->setColumnCount(4);
    ui->R_Widget->setRowCount(50);
    ui->R_Widget->setColumnWidth(0,100);
    ui->R_Widget->setColumnWidth(1,150);
    ui->R_Widget->setColumnWidth(2,100);
    ui->R_Widget->setColumnWidth(3,150);
    ui->R_Widget->verticalHeader()->setVisible(false);
    //设置表头
    QStringList headerText;
    headerText << "名称"<<"当前值"<<"名称"<<"当前值";
    ui->R_Widget->setHorizontalHeaderLabels(headerText);
    //表格行交替不同颜色
    ui->R_Widget->setAlternatingRowColors(true);
    QString str0,str2;
    for (int var = 0; var < 50; ++var)
    {
        str0= "R["+QString::number(var+1)+"]";
        str2= "R["+QString::number(var+51)+"]";
        QTableWidgetItem *item0 = new QTableWidgetItem(str0);
        QTableWidgetItem *item2 = new QTableWidgetItem(str2);
        item0->setTextAlignment(Qt::AlignCenter);//设置文本对齐方式居中
        item2->setTextAlignment(Qt::AlignCenter);//设置文本对齐方式居中

        ui->R_Widget->setItem(var,0,item0);
        ui->R_Widget->setItem(var,2,item2);
        //设置不可选择不可编辑，~为取反
        item0->setFlags(item0->flags() & ~Qt::ItemIsSelectable);
        item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);

        item2->setFlags(item2->flags() & ~Qt::ItemIsSelectable);
        item2->setFlags(item2->flags() & ~Qt::ItemIsEditable);

        QTableWidgetItem *item1 = new QTableWidgetItem("0");
        QTableWidgetItem *item3 = new QTableWidgetItem("0");
        item1->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        ui->R_Widget->setItem(var, 1, item1);
        ui->R_Widget->setItem(var, 3, item3);
    }
}

/*************************************************
  函数名称：initWidget(QTableWidget *theWidget, const QString &Type, int length, int startColumn)
  函数功能：初试化SR、DIO、UIO寄存器值界面
  输入参数：QTableWidget *theWidget，相应寄存器界面 const QString &Type,寄存器类型 int length,寄存器行数 int startColumn 开始列
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::initWidget(QTableWidget *theWidget, const QString &Type, int length, int startColumn)
{
    //qDebug()<<"initWidget！";
    theWidget->setRowCount(120);
    //    theWidget.setColumnWidth();
    if(Type == "SR")
    {
        ui->SR_Widget->setColumnCount(2);
        theWidget->setColumnWidth(startColumn, 120);
        theWidget->setColumnWidth(startColumn+1, 400);
        //初始化SR的第2列值为空字符串
        for (int var = 0; var < length; ++var) {
            QTableWidgetItem *item1 = new QTableWidgetItem(""); // 设置默认值为空字符串
            item1->setTextAlignment(Qt::AlignCenter);
            theWidget->setItem(var, startColumn + 1, item1);
        }
    }
    else    //UI/UO/DI/DO
    {
        ui->DI_DO_Widget->setColumnCount(4);
        ui->UI_UO_Widget->setColumnCount(4);
        theWidget->setColumnWidth(startColumn, 100);
        theWidget->setColumnWidth(startColumn+1, 160);
    }
    //隐藏垂直表头
    theWidget->verticalHeader()->setVisible(false);
    //设置表头
    QStringList headerText;
    headerText << "名称"<<"当前值"<< "名称"<<"当前值";
    theWidget->setHorizontalHeaderLabels(headerText);
    //表格行交替不同颜色
    theWidget->setAlternatingRowColors(true);
    QString str0;
    for (int var = 0; var < length; ++var)
    {
        str0= Type+"["+QString::number(var+1)+"]";
        QTableWidgetItem *item0 = new QTableWidgetItem(str0);
        item0->setTextAlignment(Qt::AlignCenter);
        theWidget->setItem(var,startColumn,item0);
        item0->setFlags(item0->flags() & ~Qt::ItemIsSelectable);
        item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
        if(Type != "SR")//Type != "R"&&
        {
            QTableWidgetItem *item1 = new QTableWidgetItem("0");
            item1->setTextAlignment(Qt::AlignCenter);
            theWidget->setItem(var,startColumn+1, item1);
        }
    }

}

/*************************************************
  函数名称：initPRWidget()
  函数功能：初试化PR寄存器值界面
  输入参数：无
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::initPRWidget()
{
    ui->PR_Widget->setColumnCount(7);
    ui->PR_Widget->setRowCount(PR_NUM);
    for (int i = 0; i < 7; ++i) {
        ui->PR_Widget->setColumnWidth(i, 80);
    }
    ui->PR_Widget->verticalHeader()->setVisible(false);
    QStringList headerText;
    headerText << "名称"<<"X"<<"Y"<< "Z"<<"W"<<"P"<<"R";
    ui->PR_Widget->setHorizontalHeaderLabels(headerText);
    //表格行交替不同颜色
    ui->PR_Widget->setAlternatingRowColors(true);
    QString str0;

    for (int var = 0; var < PR_NUM; ++var)
    {
        str0= "PR["+QString::number(var+1)+"]";
        QTableWidgetItem *item0 = new QTableWidgetItem(str0);
        ui->PR_Widget->setItem(var,0,item0);
        item0->setTextAlignment(Qt::AlignCenter);
        item0->setFlags(item0->flags() & ~Qt::ItemIsSelectable);
        item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
        QTableWidgetItem *item[6];     //将每一组XYZWPR以及J1-6创建新的QTableWidgetItem
        for(int i = 0; i < 6; ++i)
        {
            item[i] = new QTableWidgetItem("0");        //XYZWPR组
            item[i]->setTextAlignment(Qt::AlignCenter);
            ui->PR_Widget->setItem(var, 1+i, item[i]);
        }
    }
}

/*************************************************
  函数名称：updateRArr(int row, int column)
  函数功能：当R寄存器界面值发生变化后，更新R寄存器数组
  输入参数：int row, int column，表格里数据改变的行号、列号
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::updateRArr(int row, int column) {

    if (column == 1 || column == 3) { // 只处理需要更新的列
        bool ok;
        double newValue = ui->R_Widget->item(row, column)->text().toDouble(&ok);

        if (ok) { // 转换成功
            int index = (column == 1) ? row : 50 + row; // 计算数组索引
            dR_Arr[index] = newValue;
            qDebug() << "更新 R 寄存器 " << index << " 的值为:" << newValue;
        } else {
            qWarning() << "输入值无效，未更新数组。";
        }
    }
}

void MainWindow::updateSRArr(int row, int column)
{
    qStrValue = ui->SR_Widget->item(row, column)->text();
}

/*************************************************
  函数名称：updatePRArr(int row, int column)
  函数功能：当PR寄存器界面值发生变化后，更新PR寄存器数组
  输入参数：int row, int column，表格里数据改变的行号、列号
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::updatePRArr(int row, int column)
{
    bool ok;
    float newValue = ui->PR_Widget->item(row, column)->text().toFloat(&ok);
    if (ok) { // 转换成功
        switch (column) {
        case NR_REG:
            fPRValueArr[row].X = newValue;
            break;
        case FR_REG:
            fPRValueArr[row].Y = newValue;
            break;
        case SR_REG:
            fPRValueArr[row].Z = newValue;
            break;
        case PR_REG:
            fPRValueArr[row].W = newValue;
            break;
        case DI_REG:
            fPRValueArr[row].P = newValue;
            break;
        case DO_REG:
            fPRValueArr[row].R = newValue;
            break;
        default:
            qWarning() << "输入值无效，未更新数组。";
            break;
        }

        qDebug() << "更新 PR 寄存器[ " << row+1 << " ]的第"<<column<<"值为:" << newValue;
    } else {
        qWarning() << "输入值无效，未更新数组。";
    }
}

void MainWindow::updateDI_DO_Arr(int row, int column)
{
    bool ok;
    int newValue = ui->DI_DO_Widget->item(row, column)->text().toInt(&ok);
    if (ok) { // 转换成功
        if (newValue != 0) {
            newValue = 1;
            ui->DI_DO_Widget->item(row, column)->setText(QString::number(newValue));
            qDebug() << "更新 UIO 寄存器 " << row+1 << " 的值为:" << newValue;
            DIO_UIO_Arr[row] = true;
        }
        else{
            DIO_UIO_Arr[row] = false;
        }
    } else {
        qWarning() << "输入值无效，未更新数组。";
    }
}

void MainWindow::updateUI_UO_Arr(int row, int column)
{
    bool ok;
    int newValue = ui->UI_UO_Widget->item(row, column)->text().toInt(&ok);
    if (ok) { // 转换成功
        if (newValue != 0) {
            newValue = 1;
            ui->DI_DO_Widget->item(row, column)->setText(QString::number(newValue));
            qDebug() << "更新 UIO 寄存器 " << row+1 << " 的值为:" << newValue;
            DIO_UIO_Arr[row] = true;
        }
        else{
            DIO_UIO_Arr[row] = false;
        }
    } else {
        qWarning() << "输入值无效，未更新数组。";
    }
}

/*************************************************
  函数名称：updateR_Widget(int index, float newValue)
  函数功能：当接收到机器人R值后，更新R界面
  输入参数：int index, float newValue，R寄存器的编号和值
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::updateR_Widget(int index, float newValue)
{
    qDebug()<<"正在更新R表格……";
    if(index<50){
        ui->R_Widget->item(index-1, 1)->setText(QString::number(newValue));
    }
    else{
        ui->R_Widget->item(index-51, 3)->setText(QString::number(newValue));
    }
}

void MainWindow::updateSR_Widget(int index, QString newValue)
{
    qDebug()<<"正在更新SR表格……";
    ui->SR_Widget->item((index-1), 1)->setText(newValue);
}
/*************************************************
  函数名称：updatePR_Widget(int row,int cloum, float newValue)
  函数功能：当接收到机器人PR值后，更新PR界面
  输入参数：int row,int cloum, float newValue 行号、列号、值
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::updatePR_Widget(int row, int cloum, float newValue)
{
    qDebug()<<"正在更新PR表格……";
    ui->PR_Widget->item((row-1), cloum)->setText(QString::number(newValue));
}

void MainWindow::updateDIO_UIO_Widget(int regType, int row, bool newValue)
{
    qDebug()<<"正在更新DIO/UIO表格……";
    int temp = newValue ? 1 : 0;
    switch (regType) {
    case DI_REG:
        ui->DI_DO_Widget->item(row-1,1)->setText(QString::number(temp));
        break;
    case DO_REG:
        ui->DI_DO_Widget->item(row-1,3)->setText(QString::number(temp));
        break;
    case UI_REG:
        ui->UI_UO_Widget->item(row-1,1)->setText(QString::number(temp));
        break;
    case UO_REG:
        ui->UI_UO_Widget->item(row-1,3)->setText(QString::number(temp));
        break;
    }
}

/*************************************************
  函数名称：selectRegWidget(int index)
  函数功能：选择不同寄存器类型时，显示相应界面
  输入参数：int index 寄存器类型索引值
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void MainWindow::selectRegWidget(int index)
{
    switch (index+1) {
    case NR_REG: // 整型R寄存器
    case FR_REG: // 浮点R寄存器
        ui->stackedWidget->setCurrentIndex(0); // 显示R_Widget
        break;
    case SR_REG: // SR寄存器
        ui->stackedWidget->setCurrentIndex(1); // 显示SR_Widget
        break;
    case PR_REG: // PR寄存器
        ui->stackedWidget->setCurrentIndex(2); // 显示PR_Widget
        break;
    case DI_REG: // DI寄存器
    case DO_REG: // DO寄存器
        ui->stackedWidget->setCurrentIndex(3); // 根据需要显示相应界面
        break;
    case UI_REG: // UI寄存器
    case UO_REG: // UO寄存器
        ui->stackedWidget->setCurrentIndex(4); // 根据需要显示相应界面
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
