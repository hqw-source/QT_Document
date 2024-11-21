#include "clinkrobot.h"

#define MSG_HEAD_LEN     20
#define READ_COMMAND     82
#define WRITE_COMMAND    87
#define ERROR_CODE_FLAG  -1


CLinkRobot::CLinkRobot(QObject *parent)
    : QObject{parent} {
}

// 初始化静态成员变量
QString CLinkRobot::s_errIdArr[10] = {
    "报警代码：1，超时未接收到完整报文！",
    "报警代码：2，功能码错误！",
    "报警代码：3，寄存器地址错误!",
    "报警代码：4，寄存器个数错误!",
    "报警代码：5，校验和有误!",
    "报警代码：6，收到无法识别的异常码！",
    "报警代码：7，请求读取或写入的寄存器地址错误!",
    "报警代码：8，报文错误!",
    "报警代码：9，未建立连接！！!",
    "报警代码：10，超时未接收到完整报文"
};

// 初始化静态成员变量
QString CLinkRobot::s_robotErrIdArr[11] = {
    "报警代码：1，非法功能码!",
    "报警代码：2，非法数据地址!",
    "报警代码：3，非法数据类型!",
    "报警代码：4，报文长度错误!",
    "报警代码：5，设备故障!",
    "报警代码：6，读取寄存器失败!",
    "报警代码：7，写入寄存器失败!",
    "报警代码：8，连接中断!",
    "报警代码：9，读取报文失败或未收到报文!",
    "报警代码：10，通讯文件打开失败!",
    "报警代码：11，数据和校验不正确!"
};


/*************************************************
      函数名称：connectRobot(QString ipAddr, quint16 portNUm)
      函数功能：连接机器人
      输入参数：ipAddr 客户端ip地址
              portNum 端口号
      输出参数：无
      返 回 值：无
      备    注：
**************************************************/
void CLinkRobot::connectRobot(QString ipAddr, quint16 portNum)
{
    if (bIsFanucConnected) {
        qDebug() << "已经连接，不需要重复连接";
        return;
    }

    QHostAddress hostAddr(ipAddr); // 将QString转为QHostAddr
    //检查ip的有效性，如果 ipAddr不是有效的 IP 格式，QHostAddr的构造函数会默认为 QHostAddr::Null
    if (hostAddr.isNull()) {
        qDebug() << "无效的IP地址:" << ipAddr;
        return;
    }

    if (!m_pTcpServer) {
        m_pTcpServer = new QTcpServer(this);
    }

    //判断是否已经开启监听
    if (m_pTcpServer->isListening()) {
        qDebug() << "服务器已经在监听中...";
    }
    else if (!m_pTcpServer->listen(hostAddr, portNum)){
        // 如果无法启动服务器（即开始监听TCP连接），则输出错误信息
        qDebug() << "开启服务器监听失败！！！ " << m_pTcpServer->errorString();
        m_pTcpServer->deleteLater(); // 清理资源
        return;
    }

    // 当有连接请求时，执行lambda表达式
    qDebug()<<"正在连接...";
    connect(m_pTcpServer, &QTcpServer::newConnection, this, [this](){

        // 检查是否有新的连接请求
        QTcpSocket* newSocket = m_pTcpServer->nextPendingConnection();
        if (!newSocket) {
            //qDebug() << "没有新的连接请求";
            return;
        }

        //确保只连接一个客户端
        if (m_pTCpSocket && m_pTCpSocket->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "已有客户端连接，拒绝新的连接请求";
            newSocket->disconnectFromHost();
            return;

        }

        m_pTCpSocket = newSocket;
        qDebug()<<"连接成功！！！";
        bIsFanucConnected = true;
        emit connected(); // 发出连接成功信号


        connect(m_pTCpSocket, &QTcpSocket::stateChanged,this,[this](QAbstractSocket::SocketState state)
        {
            // 如果断连，则重置bIsFanucConnected标志位
            // 并发出unConnected信号
            if(state == QAbstractSocket::UnconnectedState)
            {
                qDebug()<<"连接已断开！！！";
                bIsFanucConnected = false;
                emit unConnected();
                m_pTCpSocket->deleteLater(); // 清理 m_pTCpSocket
                m_pTCpSocket = nullptr; // 重置指针为 nullptr
            }
        });
    });
}

/*************************************************
      函数名称：disconnectRobot()
      函数功能：断开与机器人的连接
      输入参数：无
      输出参数：无
      返 回 值：无
      备    注：
**************************************************/
void CLinkRobot::disconnectRobot()
{
    // 检查是否已经有活动的客户端连接
    if (m_pTCpSocket) {
        // 主动断开客户端连接
        m_pTCpSocket->disconnectFromHost();

        // 删除当前socket对象并重置指针
        m_pTCpSocket->deleteLater();
        m_pTCpSocket = nullptr;

        // 更新连接状态标志
        bIsFanucConnected = false;
        emit unConnected(); // 发出断开连接的信号
        qDebug() << "已手动断开连接";
    }

    // 检查是否有正在监听的服务器
    if (m_pTcpServer && m_pTcpServer->isListening()) {
        // 停止监听
        m_pTcpServer->close();
        qDebug() << "服务器监听已关闭";
    }
}

/*************************************************
      函数名称：readR(int regAddr, int *nValue)
      函数功能：读机器人的单个整型R寄存器值
      输入参数：regAddr 寄存器地址    1...R_NUM
      输出参数：nValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readR(int regAddr, int *nValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, NR_REG, regAddr, 1, nValue)) {
        return false;
    }
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *nValue = m_RecvMsgData.nValueArr[0];
    return true;
}

/*************************************************
      函数名称：readR(int regAddr, double *dValue)
      函数功能：读机器人的单个浮点型R寄存器值
      输入参数：regAddr 寄存器地址    1...R_NUM
      输出参数：dValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readR(int regAddr, double *dValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, FR_REG, regAddr, 1, dValue) ) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *dValue = m_RecvMsgData.fValueArr[0];
    return true;
}

/*************************************************
      函数名称：readR(int regAddr, int regNums, int *nArray)
      函数功能：读机器人的多个整型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              regNums 寄存器个数     1...57
      输出参数：nArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readR(int regAddr, int regNums, int *nArray)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, NR_REG, regAddr, regNums, nArray) ) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    memcpy(nArray, m_RecvMsgData.nValueArr, regNums*4);
    return true;
}

/*************************************************
      函数名称：readR(int regAddr, int regNums, double *dArray)
      函数功能：读机器人的多个浮点型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              regNums 寄存器个数     1...57
      输出参数：dArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readR(int regAddr, int regNums, double *dArray)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, FR_REG, regAddr, regNums, dArray)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    //memcpy(dArray, m_RecvMsgData.fValueArr, regNums*4);
    for (int i = 0; i < regNums; i++) {
        dArray[i] = m_RecvMsgData.fValueArr[i];
    }
    return true;
}

/*************************************************
      函数名称：writeR(int regAddr, int nValue)
      函数功能：向机器人写入单个整型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              nValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeR(int regAddr, int nValue)
{
    m_SendMsgData.nValueArr[0] = nValue;
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, NR_REG, regAddr, 1, m_SendMsgData.nValueArr)) {
        return false;
    }
    
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：writeR(int regAddr, double dValue)
      函数功能：向机器人写入单个浮点型R寄存器值
      输入参数：regAddr  起始寄存器地址  1...R_NUM
              dValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeR(int regAddr, double dValue)
{
    m_SendMsgData.fValueArr[0] = dValue;
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, FR_REG, regAddr, 1, m_SendMsgData.fValueArr)) {
        return false;
    }
    
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：writeR(int regAddr, int regNums, int *nArray)
      函数功能：向机器人写入多个整型R寄存器值
      输入参数：regAddr  起始寄存器地址  1...R_NUM
              regNums 寄存器个数 1...57
              nArray 寄存器值数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeR(int regAddr, int regNums, int *nArray)
{
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, NR_REG, regAddr, regNums, nArray)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}

/*************************************************
      函数名称：writeR(int regAddr, int regNums, double *dArray)
      函数功能：向机器人写入多个浮点型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              regNums 寄存器个数 1...57
              dArray 寄存器值数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeR(int regAddr, int regNums, double *dArray)
{
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, FR_REG, regAddr, regNums, dArray)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：readSR(int regAddr, QString *strValue)
      函数功能：读取机器人单个SR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
      输出参数：strValue 存放SR寄存器值的字符串
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readSR(int regAddr, QString *strValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, SR_REG, regAddr, 1, m_RecvMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *strValue = QString::fromUtf8(reinterpret_cast<const char*>(m_RecvMsgData.ucValueArr + 1), m_RecvMsgData.nRegNums - 1);
    return true;
}

/*************************************************
      函数名称：writeSR(int regAddr, QString *strValue)
      函数功能：向机器人写入单个SR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              strValue SR寄存器值的字符串
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeSR(int regAddr, QString *strValue)
{
    QByteArray byteArray = strValue->toUtf8(); // 转换为 UTF-8 字节数组
    // 确保不超过 ucValueArr 的大小
    m_SendMsgData.nRegNums = qMin(byteArray.size(), 239); // 预留一个位置用于结尾的 '\0'

    // 拷贝字节数据
    memcpy(m_SendMsgData.ucValueArr, byteArray.constData(), m_SendMsgData.nRegNums);

    // 添加结束符
    m_SendMsgData.ucValueArr[m_SendMsgData.nRegNums] = '\0';

    sendMsgToFaunc(WRITE_COMMAND, SR_REG, regAddr, m_SendMsgData.nRegNums, m_SendMsgData.ucValueArr);

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}

/*************************************************
      函数名称：readPR(int regAddr, SPRReg *fPR_RegArr)
      函数功能：读机器人单个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
      输出参数：fPR_RegArr PR寄存器值的结构体数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readPR(int regAddr, SPRReg *fPRArray)
{
    //发送报文
    sendMsgToFaunc(READ_COMMAND, PR_REG, regAddr, 1, m_RecvMsgData.fValueArr);

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    memcpy(fPRArray, m_RecvMsgData.fValueArr, 6*4);
    return true;
}

/*************************************************
      函数名称：readPR(int regAddr, int regNums, SPRReg *fPRArray)
      函数功能：读机器人多个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              regNums   寄存器数量   1...9
      输出参数：fPR_RegArr PR寄存器值的结构体数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readPR(int regAddr, int regNums, SPRReg *fPRArray)
{

    //发送报文
    sendMsgToFaunc(READ_COMMAND, PR_REG, regAddr, regNums, m_RecvMsgData.fValueArr);

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    memcpy(fPRArray, m_RecvMsgData.fValueArr, 6*4*regNums);
    return true;
}

/*************************************************
      函数名称：writePR(int regAddr, SPRReg *fPRArray)
      函数功能：向机器人写入单个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              fPR_RegArr PR寄存器值的结构体数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writePR(int regAddr, SPRReg *fPRArray)
{
    float readValue[6];
    memcpy(readValue, fPRArray, sizeof(SPRReg));
    //发送报文
    sendMsgToFaunc(WRITE_COMMAND, PR_REG, regAddr, 1, readValue);

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}

/*************************************************
      函数名称：writePR(int regAddr, int regNums, SPRReg *fPRArray)
      函数功能：向机器人写入多个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              regNums   寄存器数量   1...9
              fPR_RegArr PR寄存器值的结构体数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writePR(int regAddr, int regNums, SPRReg *fPRArray)
{
    //float readValue[6*regNums];   //这样定义会有错！
    float* readValue = new float[6 * regNums];  //动态分配内存
    memcpy(readValue, fPRArray, sizeof(SPRReg)*regNums);
    //发送报文
    sendMsgToFaunc(WRITE_COMMAND, PR_REG, regAddr, regNums, readValue);

    delete[] readValue; // 使用完毕后释放内存

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}



/*************************************************
      函数名称：readDI(int regAddr, bool *bValue)
      函数功能：读机器人的单个DI寄存器值
      输入参数：regAddr 寄存器地址    1...DI_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readDI(int regAddr, bool *bValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, DI_REG, regAddr, 1, bValue)) {   //读报文的第5个参数是没用到的
        return false;
    }
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *bValue = (m_RecvMsgData.ucValueArr[1] == '1'); //m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    return true;
}

/*************************************************
      函数名称：readDO(int regAddr, bool *bValue)
      函数功能：读机器人的单个DO寄存器值
      输入参数：regAddr 寄存器地址    1...DO_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readDO(int regAddr, bool *bValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, DO_REG, regAddr, 1, bValue)) {   //读报文的第5个参数是没用到的
        return false;
    }
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *bValue = (m_RecvMsgData.ucValueArr[1] == '1'); //m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    return true;
}

/*************************************************
      函数名称：readUI(int regAddr, bool *bValue)
      函数功能：读机器人的单个UI寄存器值
      输入参数：regAddr 寄存器地址    1...UI_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readUI(int regAddr, bool *bValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, UI_REG, regAddr, 1, bValue)) {   //读报文的第5个参数是没用到的
        return false;
    }
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *bValue = (m_RecvMsgData.ucValueArr[1] == '1'); //m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    return true;
}

/*************************************************
      函数名称：readUO(int regAddr, bool *bValue)
      函数功能：读机器人的单个UO寄存器值
      输入参数：regAddr 寄存器地址    1...UO_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readUO(int regAddr, bool *bValue)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, UO_REG, regAddr, 1, bValue)) {   //读报文的第5个参数是没用到的
        return false;
    }
    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    *bValue = (m_RecvMsgData.ucValueArr[1] == '1'); //m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    return true;
}

/*************************************************
      函数名称：readDI(int regAddr, int regNums, bool *bArray)
      函数功能：读机器人的多个DI寄存器值
      输入参数：regAddr 起始寄存器地址  1...DI_NUM
              regNums 寄存器个数     1...240
      输出参数：bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readDI(int regAddr, int regNums, bool *bArray)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, DI_REG, regAddr, regNums, bArray) ) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    for (int i = 0; i < regNums; ++i) {
        bArray[i] = (m_RecvMsgData.ucValueArr[i+1] == '1'); //m_RecvMsgData.ucValueArr[0]为机器人自动回复的字节数
    }
    return true;
}

/*************************************************
      函数名称：readDO(int regAddr, int regNums, bool *bArray)
      输入参数：regAddr 起始寄存器地址  1...DO_NUM
              regNums 寄存器个数     1...240
      输出参数：bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readDO(int regAddr, int regNums, bool *bArray)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, DO_REG, regAddr, regNums, bArray) ) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    for (int i = 0; i < regNums; ++i) {
        bArray[i] = (m_RecvMsgData.ucValueArr[i+1] == '1');//m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    }
    return true;
}

/*************************************************
      函数名称：readUI(int regAddr, int regNums, bool *bArray)
      函数功能：读机器人的多个UI寄存器值
      输入参数：regAddr 起始寄存器地址  1...UI_NUM
              regNums 寄存器个数     1...240
      输出参数： bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readUI(int regAddr, int regNums, bool *bArray)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, UI_REG, regAddr, regNums, bArray) ) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    for (int i = 0; i < regNums; ++i) {
        bArray[i] = (m_RecvMsgData.ucValueArr[i+1] == '1');//m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    }
    return true;
}

/*************************************************
      函数名称：readUO(int regAddr, int regNums, bool *bArray)
      函数功能：读机器人的多个UO寄存器值
      输入参数：regAddr 起始寄存器地址  1...UO_NUM
              regNums 寄存器个数     1...240
      输出参数：bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::readUO(int regAddr, int regNums, bool *bArray)
{
    //发送报文
    if ( !sendMsgToFaunc(READ_COMMAND, UO_REG, regAddr, regNums, bArray) ) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    for (int i = 0; i < regNums; ++i) {
        bArray[i] = (m_RecvMsgData.ucValueArr[i+1] == '1');//m_RecvMsgData.ucValueArr[0]是接收到的机器人默认回复的字符数
    }
    return true;
}

/*************************************************
      函数名称：writeDI(int regAddr, bool bValue)
      函数功能：向机器人写入单个UO寄存器值
      输入参数：regAddr  起始寄存器地址  1...UO_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeDI(int regAddr, bool bValue)
{
    m_SendMsgData.ucValueArr[0] = bValue ? '1' : '0';
    qDebug()<<"aaaaaaaaaaaa"<<bValue;
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, DI_REG, regAddr, 1, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：writeDO(int regAddr, bool bValue)
      函数功能：向机器人写入单个DO寄存器值
      输入参数：regAddr  起始寄存器地址  1...DO_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeDO(int regAddr, bool bValue)
{
    m_SendMsgData.ucValueArr[0] = bValue ? '1' : '0';
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, DO_REG, regAddr, 1, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：writeUI(int regAddr, bool bValue)
      函数功能：向机器人写入单个UI寄存器值
      输入参数：regAddr  起始寄存器地址  1...UI_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeUI(int regAddr, bool bValue)
{
    m_SendMsgData.ucValueArr[0] = bValue ? '1' : '0';
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, UI_REG, regAddr, 1, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：writeUO(int regAddr, bool bValue)
      函数功能：向机器人写入单个UO寄存器值
      输入参数：regAddr  起始寄存器地址  1...UO_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeUO(int regAddr, bool bValue)
{
    m_SendMsgData.ucValueArr[0] = bValue ? '1' : '0';
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, UO_REG, regAddr, 1, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }

    return true;
}

/*************************************************
      函数名称：writeDI(int regAddr, int regNums, bool *bArray)
      函数功能：向机器人写入多个DI寄存器值
      输入参数：regAddr 起始寄存器地址  1...DI_NUM
              regNums 寄存器个数 1...240
              bArray 寄存器值数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeDI(int regAddr, int regNums, bool *bArray)
{
    for (int i = 0; i < regNums; ++i) {
        m_SendMsgData.ucValueArr[i] = bArray[i] ? '1' : '0';
    }
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, DI_REG, regAddr, regNums, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        ////QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}

/*************************************************
      函数名称：writeDO(int regAddr, int regNums, bool *bArray)
      函数功能：向机器人写入多个DO寄存器值
      输入参数：regAddr 起始寄存器地址  1...DO_NUM
              regNums 寄存器个数 1...240
              bArray 寄存器值数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeDO(int regAddr, int regNums, bool *bArray)
{
    for (int i = 0; i < regNums; ++i) {
        m_SendMsgData.ucValueArr[i] = bArray[i] ? '1' : '0';
    }
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, DO_REG, regAddr, regNums, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}

/*************************************************
      函数名称：writeUI(int regAddr, int regNums, bool *bArray)
      函数功能：向机器人写入多个UI寄存器值
      输入参数：regAddr 起始寄存器地址  1...UI_NUM
              regNums 寄存器个数 1...240
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::writeUI(int regAddr, int regNums, bool *bArray)
{
    for (int i = 0; i < regNums; ++i) {
        m_SendMsgData.ucValueArr[i] = bArray[i] ? '1' : '0';
    }
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, UI_REG, regAddr, regNums, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}

/*************************************************
      函数名称：writeUO(int regAddr, int regNums, bool *bArray)
      函数功能：向机器人写入多个UO寄存器值
      输入参数：regAddr 起始寄存器地址  1...UO_NUM
              regNums 寄存器个数 1...240
              bArray 寄存器值数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
bool CLinkRobot::writeUO(int regAddr, int regNums, bool *bArray)
{
    for (int i = 0; i < regNums; ++i) {
        m_SendMsgData.ucValueArr[i] = bArray[i] ? '1' : '0';
    }
    //发送报文
    if ( !sendMsgToFaunc(WRITE_COMMAND, UO_REG, regAddr, regNums, m_SendMsgData.ucValueArr)) {
        return false;
    }

    //接收报文
    if (!recvMsgFromFaunc()) {
        return false;
    }

    //保存并处理报文
    if ( !handleMsg() ){
        return false;
    }

    //如果是异常报文则
    if(ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //QMessageBox::information(nullptr, "异常报文", s_robotErrIdArr[m_RecvMsgData.nErrorCode]);
        return false;
    }
    return true;
}


/*************************************************
      函数名称：recvMsgFromFaunc()
      函数功能：接收机器人发来的报文
      输入参数：无
      输出参数：无
      返 回 值：正确返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::recvMsgFromFaunc()
{
    qDebug() << "进入接收报文……" ;
    m_RecvBuffer.clear();
    m_RecvMsgByteArr.clear();

    // 将接收到的数据添加到缓冲区
    while (true) {
        // 等待接收数据，直到超时
        if (!m_pTCpSocket->waitForReadyRead(500)) {
            qDebug() << "接收超时，退出接收";
            return false; // 超时，返回失败
        }

        qDebug() << "开始接收报文";
        m_RecvBuffer.append(m_pTCpSocket->readAll());

        qDebug() << "缓存区数据长度为：" << m_RecvBuffer.size();

        // 检查缓冲区是否至少有 20 个字节用于读取报文头
        if (m_RecvBuffer.size() < 20) {
            continue; // 缓冲区不够，跳出内循环，继续接收数据
        }

        // 从前 4 个字节中解析报文的长度（按小端字节序）
        memcpy(&m_RecvMsgData.nMsgLen, m_RecvBuffer.constData(), 4);
        //qDebug() << m_RecvMsgData.nMsgLen;
        if(m_RecvMsgData.nMsgLen > 256){
            qDebug() << "报文过长！！！";
            return false;
        }

        // 检查缓冲区中的数据是否已经达到报文长度
        if (m_RecvBuffer.size() < m_RecvMsgData.nMsgLen) {
            qDebug() << "报文未接收完整，当前缓冲区字节数：" << m_RecvBuffer.size();
            continue;//break; // 报文接收不完整，跳出内循环，继续接收数据
        }
        else {
            // 提取完整报文
            m_RecvMsgByteArr = m_RecvBuffer.left(m_RecvMsgData.nMsgLen);
            break;  //跳出循环
        }
    }

    qDebug() << "收到的报文长度为：" << m_RecvMsgData.nMsgLen;// 打印解析出来的报文长度
    qDebug() << "收到的完整报文为：" << m_RecvMsgByteArr.toHex(' ').toUpper();// 打印收到的完整报文（以十六进制形式）

    return true;
}

/*************************************************
      函数名称：handleMsg()
      函数功能：处理报文，保存报文内容
      输入参数：无
      输出参数：无
      返 回 值：正确返回true，否则返回false
      备    注：
**************************************************/
bool CLinkRobot::handleMsg()
{
    qDebug()<<"开始处理报文！！！";
    QBuffer recvbuffer(&m_RecvMsgByteArr);  // 用 QBuffer 包装 m_RecvMsgByteArr
    recvbuffer.open(QIODevice::ReadOnly);         // 设置为只读模式
    m_recvDataStream.setDevice(&recvbuffer);      // 将 QBuffer 关联到 QDataStream
    m_recvDataStream.setByteOrder(QDataStream::LittleEndian);
    m_recvDataStream.setFloatingPointPrecision(QDataStream::SinglePrecision);//设置浮点数的精度为单精度浮点数

    m_recvDataStream >> m_RecvMsgData.nMsgLen;    //报文长度
    m_recvDataStream >> m_RecvMsgData.nCmdType;   //读写类型
    m_recvDataStream >> m_RecvMsgData.nRegType;   //寄存器类型
    m_recvDataStream >> m_RecvMsgData.nRegAddr;   //寄存器地址
    m_recvDataStream >> m_RecvMsgData.nRegNums;   //寄存器数量

    //const uchar* rawData = reinterpret_cast<const uchar*>(m_RecvMsgByteArr.constData());
    qDebug()<<"长度："<<m_RecvMsgData.nCmdType;
    qDebug()<<"读写类型："<<m_RecvMsgData.nCmdType;
    qDebug()<<"寄存器类型："<<m_RecvMsgData.nRegType;
    qDebug()<<"寄存器地址："<<m_RecvMsgData.nRegAddr;
    qDebug()<<"寄存器数量："<<m_RecvMsgData.nRegNums;
    //报文头合法性校验
    if ( !checkMsgHead() ){
        return false;
    }

    //先判断是否收到异常报文
    if (ERROR_CODE_FLAG == m_RecvMsgData.nRegNums) {
        //拷贝异常码
        m_recvDataStream >> m_RecvMsgData.nErrorCode;
        //拷贝异常报文的和校验
        m_recvDataStream >> m_RecvMsgData.nCheckSum;
        //和校验
        return checkMsgSum();
    }

    if (READ_COMMAND == m_RecvMsgData.nCmdType) {    //回复的读报文
        switch (m_RecvMsgData.nRegType) {
        case NR_REG: //整型R
            //拷贝整型R寄存器的值
            for (int i = 0; i < m_RecvMsgData.nRegNums; ++i) {
                m_recvDataStream >> m_RecvMsgData.nValueArr[i];
            }
            //拷贝整型R寄存器的和校验
            m_recvDataStream >> m_RecvMsgData.nCheckSum;
            break;
        case FR_REG: //浮点型R
            //拷贝浮点型R寄存器的值
            for (int i = 0; i < m_RecvMsgData.nRegNums; ++i) {
                m_recvDataStream >> m_RecvMsgData.fValueArr[i];
            }
            //拷贝浮点型R寄存器的和校验
            m_recvDataStream >> m_RecvMsgData.fCheckSum;
            break;
        case PR_REG: //PR
            //拷贝PR寄存器的值
            for (int i = 0; i < (m_RecvMsgData.nRegNums * 6) + 1 ; ++i) {
                m_recvDataStream >> m_RecvMsgData.fValueArr[i];
            }
            //拷贝PR寄存器的和校验
            m_recvDataStream >> m_RecvMsgData.fCheckSum;
            break;
        case SR_REG:
        case DI_REG:
        case DO_REG:
        case UI_REG:
        case UO_REG:
            //拷贝SR/DIO/UIO寄存器值
            //由于机器人发送的报文会多带一个字节表示字符个数，所以需要在加上1
            for (int i = 0; i < m_RecvMsgData.nRegNums + 1 ; ++i) {
                m_recvDataStream >> m_RecvMsgData.ucValueArr[i];
            }
            //拷贝SR/DIO/UIO寄存器的和校验
            m_recvDataStream >> m_RecvMsgData.nCheckSum;
            break;
        }
    }
    else {  //回复的写报文
        m_recvDataStream >> m_RecvMsgData.nCheckSum;
    }
    return checkMsgSum();
}


/*************************************************
      函数名称：sendMsgToFaunc(int commandType, int regType, int regAddr, int regNums, T* regArray)
      函数功能：发送报文给机器人
      输入参数：commandType  读或写命令
              regType   寄存器类型   1...8
              regAddr   起始寄存器地址
              regNums    寄存器数量
              regArray  寄存器值数组  类型为int、float、SPRReg等
      输出参数：无
      返 回 值：正确返回true，否则返回false
      备    注：
    **************************************************/
template <typename T>
bool CLinkRobot::sendMsgToFaunc(int commandType, int regType, int regAddr, int regNums, T *regArray)
{
    // 连接未建立
    if(!bIsFanucConnected) {
        alarm(8);
        return false;
    }

    //地址有效性判断
    if(!checkRegAddr(regType, regAddr, regNums)) {
        return false;
    }

    //创建发送的报文
    m_SendMsgByteArr.clear();
    QBuffer sendbuffer(&m_SendMsgByteArr);  // 用 QBuffer 包装 m_RecvMsgByteArr
    sendbuffer.open(QIODevice::WriteOnly);         // 设置为只读模式
    m_sendDataStream.setDevice(&sendbuffer);      // 将 QBuffer 关联到 QDataStream
    m_sendDataStream.setByteOrder(QDataStream::LittleEndian);  //设置大端模式
    m_sendDataStream.setFloatingPointPrecision(QDataStream::SinglePrecision);//设置浮点数的精度为单精度浮点数

    if (READ_COMMAND == commandType) { //读报文
        m_SendMsgData.nMsgLen = MSG_HEAD_LEN + 4;
        m_SendMsgData.nCmdType = commandType;
        m_SendMsgData.nRegType = regType;
        m_SendMsgData.nRegAddr = regAddr;
        m_SendMsgData.nRegNums = regNums;
        m_SendMsgData.nCheckSum = m_SendMsgData.nMsgLen + m_SendMsgData.nCmdType + m_SendMsgData.nRegType + m_SendMsgData.nRegAddr + m_SendMsgData.nRegNums;
        m_sendDataStream << m_SendMsgData.nMsgLen << m_SendMsgData.nCmdType << m_SendMsgData.nRegType
                         << m_SendMsgData.nRegAddr << m_SendMsgData.nRegNums << m_SendMsgData.nCheckSum;

        qDebug()<<"发送读的校验和为："<< m_SendMsgData.nCheckSum;
        qDebug()<<"发送读报文的大小size()为："<< m_SendMsgByteArr.size();
        qDebug() << "发送的读R报文为：" << m_SendMsgByteArr.toHex(' ').toUpper();
    }
    else { //写报文
        m_SendMsgData.nCmdType = commandType;
        m_SendMsgData.nRegType = regType;
        m_SendMsgData.nRegAddr = regAddr;
        m_SendMsgData.nRegNums = regNums;
        switch (regType) {
        case NR_REG:
        case FR_REG:
        {
            m_SendMsgData.nMsgLen = MSG_HEAD_LEN + 4*regNums + 4;
            auto sendSum = regArray[0];
            sendSum = m_SendMsgData.nMsgLen + m_SendMsgData.nCmdType + m_SendMsgData.nRegType + m_SendMsgData.nRegAddr + m_SendMsgData.nRegNums;
            m_sendDataStream << m_SendMsgData.nMsgLen << m_SendMsgData.nCmdType << m_SendMsgData.nRegType
                             << m_SendMsgData.nRegAddr << m_SendMsgData.nRegNums;

            //组装数据和和校验
            for(int i=0; i<m_SendMsgData.nRegNums; ++i){
                sendSum += regArray[i];
                qDebug() << "bool值为：" << regArray[i];
                m_sendDataStream << regArray[i];
            }
            qDebug() << "发送写R的校验和为：" << sendSum;
            m_sendDataStream << sendSum;
            break;
        }
        case SR_REG:
        case DI_REG:
        case DO_REG:
        case UI_REG:
        case UO_REG:
        {
            m_SendMsgData.nMsgLen = MSG_HEAD_LEN + regNums + 4;
            int sendSum = m_SendMsgData.nMsgLen + m_SendMsgData.nCmdType + m_SendMsgData.nRegType + m_SendMsgData.nRegAddr + m_SendMsgData.nRegNums;
            m_sendDataStream << m_SendMsgData.nMsgLen << m_SendMsgData.nCmdType << m_SendMsgData.nRegType
                             << m_SendMsgData.nRegAddr << m_SendMsgData.nRegNums;

            for(int i=0; i<m_SendMsgData.nRegNums; ++i){
                sendSum += regArray[i];
                m_sendDataStream << regArray[i];
            }
            qDebug() << "发送写SR/DIO/UIO的校验和为：" << sendSum;
            m_sendDataStream << sendSum;
            break;
        }
        case PR_REG:
        {
            m_SendMsgData.nMsgLen = MSG_HEAD_LEN + 4*6*regNums + 4;
            float sendSum = m_SendMsgData.nMsgLen + m_SendMsgData.nCmdType + m_SendMsgData.nRegType + m_SendMsgData.nRegAddr + m_SendMsgData.nRegNums;
            m_sendDataStream << m_SendMsgData.nMsgLen << m_SendMsgData.nCmdType << m_SendMsgData.nRegType
                             << m_SendMsgData.nRegAddr << m_SendMsgData.nRegNums;

            for (int i=0; i<m_SendMsgData.nRegNums*6; ++i) {
                sendSum += regArray[i];
                m_sendDataStream << regArray[i];
            }
            qDebug()<<"发送写PR的校验和为："<< sendSum;
            m_sendDataStream << sendSum;
            break;
        }
        }
        qDebug()<<"发送写报文的大小size()为："<< m_SendMsgByteArr.size();
        qDebug() << "发送的写报文为：" << m_SendMsgByteArr.toHex(' ').toUpper();
    }

    //发送报文
    m_pTCpSocket->write(m_SendMsgByteArr);
    return m_pTCpSocket->waitForBytesWritten(100);
}


/*************************************************
      函数名称：checkRegAddr(int regType, int regAddr, int regNums)
      函数功能：检查发送报文的寄存器地址合法性
      输入参数：无
      输出参数：无
      返 回 值：正确返回true，否则返回false
      备    注：
    **************************************************/
bool CLinkRobot::checkRegAddr(int regType, int regAddr, int regNums)
{
    switch (regType) {
    case NR_REG:
    case FR_REG:
        //判断寄存器地址是否合法
        if (regAddr>R_NUM || regAddr<1) {
            alarm(2);
            return false;
        }
        if (regAddr+regNums > R_NUM+1 || regNums>57) {
            alarm(3);
            return false;
        }
        break;
    case SR_REG:
        //判断寄存器地址是否合法
        if (regAddr>SR_NUM || regAddr<1) {
            alarm(2);
            return false;
        }
        if (regNums > 240) {    //字节数大于240，则错误
            alarm(3);
            return false;
        }
        break;
    case PR_REG:
        //判断寄存器地址是否合法
        if (regAddr>PR_NUM || regAddr<1){
            alarm(2);
            return false;
        }
        if (regAddr+regNums>PR_NUM+1 || regNums>9){
            alarm(3);
            return false;
        }
        break;
    case DI_REG:
    case DO_REG:
        //判断寄存器地址是否合法
        if (regAddr>DI_NUM || regAddr<1) {
            alarm(2);
            return false;
        }
        if(regAddr+regNums>DI_NUM+1 || regNums>240){
            alarm(3);
            return false;
        }
        break;
    case UI_REG:
        //判断寄存器地址是否合法
        if (regAddr>UI_NUM || regAddr<1) {
            alarm(2);
            return false;
        }
        if(regAddr+regNums>UI_NUM+1 || regNums>240){
            alarm(3);
            return false;
        }
        break;
    case UO_REG:
        //判断寄存器地址是否合法
        if (regAddr>UO_NUM || regAddr<1) {
            alarm(2);
            return false;
        }
        if(regAddr+regNums>UO_NUM+1 || regNums>240){
            alarm(3);
            return false;
        }
        break;
    default:
        alarm(2);
        return false;
    }
    return true;
}

/*************************************************
  函数名称：checkMsg()
  函数功能：检查报文头的合法性
  输入参数：
  输出参数：无
  返 回 值：正确返回true，否则返回false
  备    注：
**************************************************/
bool CLinkRobot::checkMsgHead()
{
    //判断接收到的返回报文，是否与发送的请求报文的读写类型、寄存器类型、起始地址、检验和
    qDebug() << "进入报文头的检查！！！";

    //检查读写类型
    qDebug() << "收到的读写类型为：" << m_RecvMsgData.nCmdType;
    if (m_RecvMsgData.nCmdType != m_SendMsgData.nCmdType) {
        alarm(1);
        return false;
    }
    //检查寄存器类型
    qDebug() << "收到的寄存器类型为：" << m_RecvMsgData.nRegType;
    if (m_RecvMsgData.nRegType != m_SendMsgData.nRegType) {
        alarm(1);
        return false;
    }

    //检查寄存器起始地址
    qDebug() << "收到的寄存器起始地址为：" << m_RecvMsgData.nRegAddr;
    if (m_RecvMsgData.nRegAddr != m_SendMsgData.nRegAddr) {
        alarm(2);
        return false;
    }

    //检查是否为异常报文
    if (ERROR_CODE_FLAG == m_RecvMsgData.nRegNums) {
        //检查异常码
        qDebug() << "收到的异常码了！！！" ;
        return true;
    }

    //检查需要操作的寄存器数量
    if (SR_REG == m_RecvMsgData.nRegType) { //SR不检查寄存器数量
        qDebug()<<"进入SR报文头检查....";
        return true;
    }

    if (m_RecvMsgData.nRegNums != m_SendMsgData.nRegNums) {
        alarm(3);
        return false;
    }
    qDebug()<<"报文头检查完毕！！！";
    return true;
}

/*************************************************
      函数名称：checkMsgSum()
      函数功能：对报文进行和检验
      输入参数：无
      输出参数：无
      返 回 值：正确返回true，否则返回false
      备    注：
    **************************************************/
bool CLinkRobot::checkMsgSum()
{
    qDebug()<<"进入和校验";
    //校验和
    int nSum = 0;
    float fSum = 0.0;
    //异常报文的和校验
    if (ERROR_CODE_FLAG == m_RecvMsgData.nRegNums){
        //异常码校验
        if (m_RecvMsgData.nErrorCode < 1 || m_RecvMsgData.nErrorCode > 11) {
            alarm(6);
            return false;
        }
        //和校验
        nSum = m_RecvMsgData.nMsgLen + m_RecvMsgData.nCmdType + m_RecvMsgData.nRegType +
               m_RecvMsgData.nRegAddr + m_RecvMsgData.nRegNums + m_RecvMsgData.nErrorCode;

        qDebug()<< "接收到的异常报文校验和为：" << m_RecvMsgData.nCheckSum;
        qDebug()<< "计算得到的异常报文校验和为：" << nSum;
        if (m_RecvMsgData.nCheckSum != nSum) {
            alarm(4);
            return false;
        }
        return true;
    }

    nSum = m_RecvMsgData.nMsgLen + m_RecvMsgData.nCmdType + m_RecvMsgData.nRegType +
           m_RecvMsgData.nRegAddr + m_RecvMsgData.nRegNums;
    fSum = nSum;
    if (READ_COMMAND == m_RecvMsgData.nCmdType) {    //回复的读报文
        switch (m_RecvMsgData.nRegType) {
        case NR_REG: //整型R
            qDebug()<<"recvRegNum的值为："<<m_RecvMsgData.nRegNums;
            for (int i=0; i<m_RecvMsgData.nRegNums; ++i) {
                nSum += m_RecvMsgData.nValueArr[i];
                qDebug() << "整型R寄存器的下标为：" << i << " 值为：" << m_RecvMsgData.nValueArr[i];
            }
            qDebug() << "收到的整型R寄存器的和校验值为：" << m_RecvMsgData.nCheckSum;
            qDebug() << "计算得到的整型R和为：" << nSum;
            if (m_RecvMsgData.nCheckSum != nSum) {
                alarm(4);
                return false;
            }
            break;
        case FR_REG: //浮点型R
            qDebug() << "recvRegNum的值为：" << m_RecvMsgData.nRegNums;
            for (int i=0; i<m_RecvMsgData.nRegNums; ++i) {
                fSum += m_RecvMsgData.fValueArr[i];
                qDebug() << "浮点型R寄存器下标为：" << i << " 值为：" << m_RecvMsgData.fValueArr[i];
            }
            qDebug() << "收到的浮点R寄存器的和校验值为：" << m_RecvMsgData.fCheckSum;
            qDebug() << "计算得到的浮点R和为：" << fSum;
            if (m_RecvMsgData.fCheckSum - fSum > FLOAT_EPSILON) {
                alarm(4);
                return false;
            }
            break;
        case SR_REG:
        case DI_REG:
        case DO_REG:
        case UI_REG:
        case UO_REG:
            for (int i=0; i<(m_RecvMsgData.nRegNums + 1); ++i) {
                nSum += m_RecvMsgData.ucValueArr[i];
            }
            qDebug() << "收到的SR/寄存器的和校验值为：" << m_RecvMsgData.nCheckSum;
            qDebug() << "计算得到的整型R和为：" << nSum;
            if (m_RecvMsgData.nCheckSum != nSum) {
                alarm(4);
                return false;
            }
            break;
        case PR_REG: //PR
            for (int i=0; i<m_RecvMsgData.nRegNums * 6; ++i) {
                fSum += m_RecvMsgData.fValueArr[i];
                qDebug() << "浮点型R寄存器下标为：" << i << " 值为：" << m_RecvMsgData.fValueArr[i];
            }
            qDebug() << "收到的浮点R寄存器的和校验值为：" << m_RecvMsgData.fCheckSum;
            qDebug() << "计算得到的浮点R和为：" << fSum;
            if (m_RecvMsgData.fCheckSum - fSum > FLOAT_EPSILON) {
                alarm(4);
                return false;
            }
            break;
        }
    }
    else{   //回复的写报文
        qDebug()<<"收到的整型R寄存器的和校验值为："<<m_RecvMsgData.nCheckSum;
        qDebug()<<"计算得到的和为："<<nSum;
        if(m_RecvMsgData.nCheckSum != nSum){
            alarm(4);
            return false;
        }
    }
    return true;
}


/*************************************************
  函数名称：alarm(int errCode)
  函数功能：打印错误的信息
  输入参数：int errCode
  输出参数：无
  返 回 值：无
  备    注：
**************************************************/
void CLinkRobot::alarm(int errCode)
{
    QMessageBox::information(nullptr, "发生错误", s_errIdArr[errCode]);
    //qDebug() << s_errIdArr[errCode];
}
