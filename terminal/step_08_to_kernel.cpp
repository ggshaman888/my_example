#include <QDebug>
#include "step_08_to_kernel.h"
#include "consoleform.h"

Step08ToKernel::Step08ToKernel(QObject* parent) : QObject(parent) {}


void Step08ToKernel::isRun()
{
    qDebug() << "void Step08ToKernel::isRun()";
    th           = new QThread;
    auto console = new ConsoleForm;

    connect(th, &QThread::started, console, &ConsoleForm::isRun, Qt::QueuedConnection);
    console->moveToThread(th);
    th->start();
}
