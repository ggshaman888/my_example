#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "set/setuart.h"
#include "calculate_for_list.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    SetUART uart;
    CalculateForList calc;
    calc.setListTiming(uart.listTiming());

    for (int i = 1; i < 30; i++) {
        QThread::msleep(100);
        calc.percentForStep(i);
    }

    return a.exec();
}
