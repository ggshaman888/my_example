#include <QDebug>
#include <QThread>
#include "step_kernel.h"
#include "step_08_to_kernel.h"

StepKernel::StepKernel(QObject* parent) : QObject(parent) {}

StepKernel::~StepKernel()
{
    qDebug() << "StepKernel::~StepKernel()";
}

bool StepKernel::step_08()
{
    qDebug() << "bool StepKernel::step_08()";
    is_step_08.isRun();
    int x = 1000;
    while (x > 0) {
        QThread::msleep(1000);
    }
    qDebug() << "bool StepKernel::step_08() end";
}
