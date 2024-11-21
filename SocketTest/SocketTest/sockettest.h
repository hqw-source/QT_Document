#ifndef SOCKETTEST_H
#define SOCKETTEST_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QState>
#include <QStateMachine>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class SocketTest;
}

class SocketTest : public QWidget
{
    Q_OBJECT

public:
    explicit SocketTest(QWidget *parent = nullptr);
    ~SocketTest();

private:
    Ui::SocketTest *ui;

    QTcpServer *tcpServer;//监听套接字
    QTcpSocket *tcpSocket;//通信套接字
};

#endif // SOCKETTEST_H
