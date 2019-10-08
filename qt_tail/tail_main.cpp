#include <QFile>
#include <QDate>
#include <QDebug>
#include <QThread>
#include "tail_main.h"

TailMain::TailMain(QObject* parent) : QObject(parent) {}

TailMain::~TailMain()
{
    qDebug() << "TailMain::~TailMain()";
    //isStop();
}

void TailMain::setListen(QString is_path)
{
    path = is_path;
}

void TailMain::listenNew()
{
    reading = true;
    count   = 0;
    while (reading) {
        QThread::msleep(100);
        readLine();
    }
    qDebug() << "void TailMain::listenNew()";
    this->~TailMain();
}

void TailMain::run()
{
    listenNew();
}

void TailMain::isStop()
{
    qDebug() << "void TailMain::isStop()";
    reading = false;
}

void TailMain::readLine()
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray ba = file.readAll();

        QString str(ba);
        str.replace("\r", "");
        QStringList list = str.split("\n");

        static int xx;
        if (xx != list.size()) {
            xx = list.size();
            for (; count < list.size(); count++) {
                if (count != 0) {
                    emit newString(list.at(count - 1));
                }
            }
        }
        file.close();
    }
}
