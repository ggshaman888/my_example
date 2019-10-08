#ifndef READEXAMPLE_H
#define READEXAMPLE_H

#include <QObject>
#include <QThread>
#include "tail_main.h"

class ReadExample : public QObject
{
    Q_OBJECT
public:
    explicit ReadExample(QObject *parent = nullptr);

signals:

public slots:
    void readLine(QString);

private:
    TailMain* tail;
    QThread* th;
};

#endif // READEXAMPLE_H
