#ifndef RUNPREPARE_H
#define RUNPREPARE_H

#include <QObject>
#include <QThread>
#include <QByteArray>
#include "setbaikal.h"

class RunPrepare : public QThread {
    Q_OBJECT
public:
    explicit RunPrepare(QThread* parent = nullptr);

    void run();

signals:
    void writeToDevice(QByteArray);
    void infoStep(int);

public slots:
    void readToBuffer(const QByteArray&);

private:
    int prepareStep(int);
    QByteArray buffer;
    SetBaikal* sb;
};

#endif // RUNPREPARE_H
