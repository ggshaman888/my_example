#include <QDebug>
#include <QDate>
#include <QThread>
#include "read_example.h"
#include "tail_main.h"

ReadExample::ReadExample(QObject* parent) : QObject(parent)
{
    QString path_chipprog = "C:/Phyton/ChipProgUSB/";
    QDate date            = QDate::currentDate();
    path_chipprog.append("6_17_01")
        .append("/Log/")
        .append(date.toString("yyyy-MM-dd"))
        .append(".log");

    tail = new TailMain;
    th   = new QThread;

    tail->setListen(path_chipprog);
    tail->moveToThread(th);

    connect(tail, &TailMain::newString, this, &ReadExample::readLine, Qt::DirectConnection);
    connect(th, &QThread::started, tail, &TailMain::run, Qt::DirectConnection);
    connect(th, &QThread::finished, tail, &TailMain::deleteLater, Qt::QueuedConnection);
    connect(this, &ReadExample::is_Stop, tail, &TailMain::isStop, Qt::DirectConnection);

    th->start();

    //emit is_Stop(); ///< For example.
}

void ReadExample::readLine(QString str)
{
    qDebug() << str;
}
