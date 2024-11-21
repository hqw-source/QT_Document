// workerthread.h
#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QDebug>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    void run() override {
        while (1) {
            emit triggerSendMsg();  // 信号
            int nHz = 5;
            QThread::msleep(static_cast<unsigned long>(1000 / nHz));
        }
    }

signals:
    void triggerSendMsg();  // 定义信号
};

#endif // WORKERTHREAD_H
