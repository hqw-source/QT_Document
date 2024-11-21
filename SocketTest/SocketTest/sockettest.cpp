#include "sockettest.h"
#include "ui_sockettest.h"

SocketTest::SocketTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketTest)
{
    ui->setupUi(this);
    QPushButton *button1 = new QPushButton("1", this);
    QPushButton *button2 = new QPushButton("2", this);
    QPushButton *button3 = new QPushButton("3", this);
    button1->resize(80, 30);
    button1->move(10, 10);
    button2->resize(80, 30);
    button2->move(120, 10);
    button3->resize(80, 30);
    button3->move(70, 60);

    QLabel *label = new QLabel("In state s1", this);
    label->move(70, 120);
    label->resize(80, 80);

    // 创建状态机和状态
    QStateMachine *machine = new QStateMachine;
    QState *s1 = new QState();
    QState *s2 = new QState();
    QState *s3 = new QState();

    s1->assignProperty(label, "text", "In state s1");
    s2->assignProperty(label, "text", "In state s2");
    s3->assignProperty(label, "text", "In state s3");

    s1->addTransition(button1, &QPushButton::clicked, s2);
    s2->addTransition(button2, &QPushButton::clicked, s3);
    s3->addTransition(button3, &QPushButton::clicked, s1);

    machine->addState(s1);
    machine->addState(s2);
    machine->addState(s3);
    machine->setInitialState(s1);

    // 连接调试信息
    connect(s1, &QState::entered, [] { qDebug() << "Entered state s1"; });
    connect(s2, &QState::entered, [] { qDebug() << "Entered state s2"; });
    connect(s3, &QState::entered, [] { qDebug() << "Entered state s3"; });

    machine->start();



}

SocketTest::~SocketTest()
{
    delete ui;
}
//    tcpServer = new QTcpServer(this);
//    tcpServer->listen( QHostAddress("127.0.0.1"),8000);
//    connect(tcpServer,&QTcpServer::newConnection,[=](){
//            //取出建立好连接的套接字
//            tcpSocket = tcpServer->nextPendingConnection();

//            //获取对方的IP和端口
//            QString ip = tcpSocket->peerAddress().toString();
//            qint16 port = tcpSocket->peerPort();

//            QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
//            qDebug()<<"IP"<<temp;

//            connect(tcpSocket,&QTcpSocket::readyRead,[=](){
//            //从通信套接字中取出内容
//            QByteArray array = tcpSocket->readAll();

//            qDebug()<<"收到的信息"<<array;
//            });

//        });
