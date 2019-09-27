#include <QTime>
#include <QThread>
#include <QDebug>
#include "myclass1.h"

MyClass1::MyClass1() {}

int MyClass1::first(int count)
{
    auto is_time = QTime::currentTime();
    while (count > 0) {
        QThread::sleep(1);

        static int sec_static = is_time.secsTo(QTime::currentTime());
        int sec               = is_time.secsTo(QTime::currentTime());

        qDebug() << "sec" << sec << "sec_static" << sec_static;
        count--;
    }
}
