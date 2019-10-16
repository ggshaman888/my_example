#include <QList>
#include <QThread>
#include <QDebug>
#include "example_uart.h"
#include "calculate_for_list.h"

ExampleUART::ExampleUART() {}

void ExampleUART::isRun()
{
    CalculateForList calc;
    calc.setListTiming(listTiming());

    calc.startCalc();
    for (int i = 1; i < 30; i++) {
        QThread::msleep(3000);
        qDebug() << calc.percentTime(i) << "%" << i;
    }
}

QList<int> ExampleUART::listTiming()
{
    QList<int> is;
    is << IS1 << IS2 << IS3 << IS4 << IS5 << IS6 << IS7 << IS8 << IS9 << IS10
       << IS11 << IS12 << IS13 << IS14 << IS15 << IS16 << IS17 << IS18 << IS19
       << IS20 << IS21 << IS22 << IS23 << IS24 << IS25 << IS26 << IS27 << IS28
       << IS29;
    return is;
}
