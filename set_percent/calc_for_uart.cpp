#include <QList>
#include <QThread>
#include <QDebug>
#include "calc_for_uart.h"
#include "calculate_for_list.h"

CalcPercentUART::CalcPercentUART(QObject* parent) : QObject(parent)
{
    qDebug() << "CalcPercentUART::CalcPercentUART(QObject* parent)";
}

CalcPercentUART::~CalcPercentUART()
{
    qDebug() << "CalcPercentUART::~CalcPercentUART()";
}

void CalcPercentUART::run()
{
    //    is_run = true;
    //    CalculateForList calc;
    //    calc.setListTiming(listTiming());

    //    calc.startCalc();
    //    step = 1;
    //    while (step != 1000 && is_run) {
    //        for (int i = 0; i < 10; i++) {
    //            QThread::msleep(100);
    //            if (!is_run) {
    //                break;
    //            }
    //        }
    //        qDebug() << "___calc";
    //        emit percent(calc.percentTime(static_cast<int>(step)));
    //        qDebug() << "calc.percentTime(step) "
    //                 << "%" << step;
    //    }
    qDebug() << "_____ void CalcPercentUART::run()";
    //    if (step == 1000) {
    //        qDebug() << "100% FINIFHED";
    //        percent(100);
    //    }
}

QList<int> CalcPercentUART::listTiming()
{
    QList<int> is;
    is << IS1 << IS2 << IS3 << IS4 << IS5 << IS6 << IS7 << IS8 << IS9 << IS10
       << IS11 << IS12 << IS13 << IS14 << IS15 << IS16 << IS17 << IS18 << IS19
       << IS20 << IS21 << IS22 << IS23 << IS24 << IS25 << IS26 << IS27 << IS28
       << IS29;
    return is;
}

void CalcPercentUART::setStep(int is_step)
{
    qDebug() << "void CalcPercentUART::setStep(int is_step)" << is_step;
    //  step = is_step + 1;
}

void CalcPercentUART::stopRun()
{
    is_run = false;
}
