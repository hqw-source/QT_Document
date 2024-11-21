/**
Copyright (c)
@file clinkrobot.h
@author zlx
@version 1.1.0
@date 2024-11-1
@brief 读写发那科机器人的寄存器值
*/


#ifndef CLINKROBOT_H
#define CLINKROBOT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QtEndian> //处理大小端问题
#include <QTimer>
#include <QDataStream>
#include <QBuffer>
#include <QMessageBox>

//各类寄存器数量
#define R_NUM  200
#define SR_NUM 25
#define PR_NUM 100
#define DI_NUM 512
#define DO_NUM 512
#define UI_NUM 18
#define UO_NUM 20

#define NR_REG 1
#define FR_REG 2
#define SR_REG 3
#define PR_REG 4
#define DI_REG 5
#define DO_REG 6
#define UI_REG 7
#define UO_REG 8

//浮点数比较的精度误差
#define FLOAT_EPSILON 1e-6
//PR寄存器结构体数组
struct SPRReg
{
    float X;
    float Y;
    float Z;
    float W;
    float P;
    float R;
};


class CLinkRobot : public QObject
{
    Q_OBJECT
public:
    explicit CLinkRobot(QObject *parent = nullptr);

    /*************************************************
      函数名称：connectRobot(QString ipAddr, quint16 portNUm)
      函数功能：连接机器人
      输入参数：ipAddr 客户端ip地址
              portNum 端口号
      输出参数：无
      返 回 值：无
      备    注：
    **************************************************/
    void connectRobot(QString ipAddr, quint16 portNUm);  //连接机器人

    /*************************************************
      函数名称：disconnectRobot()
      函数功能：断开与机器人的连接
      输入参数：无
      输出参数：无
      返 回 值：无
      备    注：
    **************************************************/
    void disconnectRobot(); //断开机器人的连接

    /*************************************************
      函数名称：readR(int regAddr, int *nValue)
      函数功能：读机器人的单个整型R寄存器值
      输入参数：regAddr 寄存器地址    1...R_NUM
      输出参数：nValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readR(int regAddr, int *nValue);

    /*************************************************
      函数名称：readR(int regAddr, double *dValue)
      函数功能：读机器人的单个浮点型R寄存器值
      输入参数：regAddr 寄存器地址    1...R_NUM
      输出参数：dValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readR(int regAddr, double *dValue);

    /*************************************************
      函数名称：readR(int regAddr, int regNums, int *nArray)
      函数功能：读机器人的多个整型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              regNums 寄存器个数     1...57
      输出参数：nArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readR(int regAddr,int regNums,int *nArray);

    /*************************************************
      函数名称：readR(int regAddr, int regNums, double *dArray)
      函数功能：读机器人的多个浮点型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              regNums 寄存器个数     1...57
      输出参数：dArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readR(int regAddr, int regNums, double *dArray);

    /*************************************************
      函数名称：writeR(int regAddr, int nValue)
      函数功能：向机器人写入单个整型R寄存器值
      输入参数：regAddr 起始寄存器地址  1...R_NUM
              nValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeR(int regAddr,int nValue);

    /*************************************************
      函数名称：writeR(int regAddr, double dValue)
      函数功能：向机器人写入单个浮点型R寄存器值
      输入参数：regAddr  起始寄存器地址  1...R_NUM
              dValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeR(int regAddr, double dValue);

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
    bool writeR(int regAddr, int regNums, int *nArray);

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
    bool writeR(int regAddr,int regNums,double *dArray);

    /*************************************************
      函数名称：readPR(int regAddr, SPRReg *fPR_RegArr)
      函数功能：读机器人单个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
      输出参数：fPR_RegArr PR寄存器值的结构体数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readPR(int regAddr, SPRReg *fPRArray);

    /*************************************************
      函数名称：readPR(int regAddr, int regNums, SPRReg *fPRArray)
      函数功能：读机器人多个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              regNums   寄存器数量   1...9
      输出参数：fPR_RegArr PR寄存器值的结构体数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readPR(int regAddr, int regNums, SPRReg *fPRArray);

    /*************************************************
      函数名称：writePR(int regAddr, SPRReg *fPRArray)
      函数功能：向机器人写入单个PR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              fPR_RegArr PR寄存器值的结构体数组
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writePR(int regAddr, SPRReg *fPRArray);

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
    bool writePR(int regAddr, int regNums, SPRReg *fPRArray);

    /*************************************************
      函数名称：readSR(int regAddr, QString *strValue)
      函数功能：读取机器人单个SR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
      输出参数：strValue 存放SR寄存器值的字符串
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readSR(int regAddr, QString *strValue);

    /*************************************************
      函数名称：writeSR(int regAddr, QString *strValue)
      函数功能：向机器人写入单个SR寄存器值
      输入参数：regAddr 起始寄存器地址  1...PR_NUM
              strValue SR寄存器值的字符串
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeSR(int regAddr, QString *strValue);

    /*************************************************
      函数名称：readDI(int regAddr, bool *bValue)
      函数功能：读机器人的单个DI寄存器值
      输入参数：regAddr 寄存器地址    1...DI_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readDI(int regAddr, bool *bValue);

    /*************************************************
      函数名称：readDO(int regAddr, bool *bValue)
      函数功能：读机器人的单个DO寄存器值
      输入参数：regAddr 寄存器地址    1...DO_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readDO(int regAddr, bool *bValue);

    /*************************************************
      函数名称：readUI(int regAddr, bool *bValue)
      函数功能：读机器人的单个UI寄存器值
      输入参数：regAddr 寄存器地址    1...UI_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readUI(int regAddr, bool *bValue);

    /*************************************************
      函数名称：readUO(int regAddr, bool *bValue)
      函数功能：读机器人的单个UO寄存器值
      输入参数：regAddr 寄存器地址    1...UO_NUM
      输出参数：bValue 寄存器值
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readUO(int regAddr, bool *bValue);

    /*************************************************
      函数名称：readDI(int regAddr, int regNums, bool *bArray)
      函数功能：读机器人的多个DI寄存器值
      输入参数：regAddr 起始寄存器地址  1...DI_NUM
              regNums 寄存器个数     1...240
      输出参数：bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readDI(int regAddr, int regNums, bool *bArray);

    /*************************************************
      函数名称：readDO(int regAddr, int regNums, bool *bArray)
      输入参数：regAddr 起始寄存器地址  1...DO_NUM
              regNums 寄存器个数     1...240
      输出参数：bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readDO(int regAddr, int regNums, bool *bArray);

    /*************************************************
      函数名称：readUI(int regAddr, int regNums, bool *bArray)
      函数功能：读机器人的多个UI寄存器值
      输入参数：regAddr 起始寄存器地址  1...UI_NUM
              regNums 寄存器个数     1...240
      输出参数： bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readUI(int regAddr, int regNums, bool *bArray);

    /*************************************************
      函数名称：readUO(int regAddr, int regNums, bool *bArray)
      函数功能：读机器人的多个UO寄存器值
      输入参数：regAddr 起始寄存器地址  1...UO_NUM
              regNums 寄存器个数     1...240
      输出参数：bArray 寄存器值数组
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool readUO(int regAddr, int regNums, bool *bArray);

    /*************************************************
      函数名称：writeDI(int regAddr, bool bValue)
      函数功能：向机器人写入单个UO寄存器值
      输入参数：regAddr  起始寄存器地址  1...UO_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeDI(int regAddr, bool bValue);

    /*************************************************
      函数名称：writeDO(int regAddr, bool bValue)
      函数功能：向机器人写入单个DO寄存器值
      输入参数：regAddr  起始寄存器地址  1...DO_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeDO(int regAddr, bool bValue);

    /*************************************************
      函数名称：writeUI(int regAddr, bool bValue)
      函数功能：向机器人写入单个UI寄存器值
      输入参数：regAddr  起始寄存器地址  1...UI_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeUI(int regAddr, bool bValue);

    /*************************************************
      函数名称：writeUO(int regAddr, bool bValue)
      函数功能：向机器人写入单个UO寄存器值
      输入参数：regAddr  起始寄存器地址  1...UO_NUM
              bValue 寄存器值
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeUO(int regAddr, bool bValue);

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
    bool writeDI(int regAddr, int regNums, bool *bArray);

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
    bool writeDO(int regAddr, int regNums, bool *bArray);

    /*************************************************
      函数名称：writeUI(int regAddr, int regNums, bool *bArray)
      函数功能：向机器人写入多个UI寄存器值
      输入参数：regAddr 起始寄存器地址  1...UI_NUM
              regNums 寄存器个数 1...240
      输出参数：无
      返 回 值：成功返回true，否则返回false
      备    注：
    **************************************************/
    bool writeUI(int regAddr, int regNums, bool *bArray);

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
    bool writeUO(int regAddr, int regNums, bool *bArray);

private:

    //TCP连接
    QTcpServer *m_pTcpServer = nullptr;
    QTcpSocket *m_pTCpSocket = nullptr;
    bool bIsFanucConnected = false; //连接是否成功标志位

    //报文的接收
    QByteArray m_RecvBuffer;        //接收缓存区的报文
    QByteArray m_RecvMsgByteArr;    //接收的完整报文
    QByteArray m_SendMsgByteArr;    //发送请求报文的字节数组

    QDataStream m_recvDataStream;   //以字节流处理接收报文数据
    QDataStream m_sendDataStream;   //以字节流处理发送报文数据

    struct SRecvFanucMsgData
    {
        int     nMsgLen;        //报文长度
        int     nCmdType;       //读写类型
        int     nRegType;       //寄存器类型
        int     nRegAddr;       //寄存器地址
        int     nRegNums;       //寄存器数量 or 异常报文标记（用数100来做标记）
        int     nErrorCode;     //报警代码
        int     nCheckSum;      //和校验
        float   fCheckSum;      //和校验

        int              nValueArr[60] = {};
        float            fValueArr[60] = {};
        unsigned char    ucValueArr[240] = {};
    };
    SRecvFanucMsgData m_SendMsgData;    //发送给机器人的数据的结构体
    SRecvFanucMsgData m_RecvMsgData;    //接收机器人发送数据的结构体

    static QString s_errIdArr[10];       // QT的一些报警信息
    static QString s_robotErrIdArr[11];  // 机器人的一些报警信息


    /// @brief 向发那科发送报文
    template <typename T>
    bool sendMsgToFaunc(int commandType, int regType, int regAddr, int regNums, T* regArray);


    /// @brief 检查发送报文的寄存器地址合法性
    bool checkRegAddr(int regType, int regAddr, int regNums);

    /// @brief 接收发那科发来的报文
    bool recvMsgFromFaunc();

    /// @brief 处理发那科发来的报文
    bool handleMsg();

    /// @brief 接收到的报文头合法性检查
    bool checkMsgHead();

    /// @brief 接收到的报文和校验
    bool checkMsgSum();

    /// @brief 打印报警信息
    void alarm(int errCode);

signals:
    void connected();
    void unConnected();
};

#endif // CLINKROBOT_H
