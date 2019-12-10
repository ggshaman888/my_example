#include <QtDebug>
#include "runprepare.h"
#include "setbaikal.h"

RunPrepare::RunPrepare(QThread* parent) : QThread(parent)
{
    qDebug() << "Construct RUN_+_+_+_+_";
    sb = new SetBaikal;
}

void RunPrepare::run()
{
    qDebug() << "void RunPrepare::run()";
    int step = 0;
    while (step < 1000) {
        step = prepareStep(step);
        emit infoStep(step);
        QThread::msleep(500);
    }
}

void RunPrepare::readToBuffer(const QByteArray& buf)
{
    buffer.append(buf);
    buffer = buffer.right(1000);
    qDebug() << buffer << "______buffer";
}

int RunPrepare::prepareStep(int step)
{
    step = sb->prepareBuffer(buffer, step);
    if (step == 1000) {
        qDebug() << step << "||||FINISHED||||";
    }
    for (int i = 0; i < sb->count_repeat; i++) {
        QThread::msleep(200);
        if (!sb->to_device.isEmpty()) {
            emit writeToDevice(sb->to_device);
        }
    }

    sb->to_device.clear();
    return step;
}
