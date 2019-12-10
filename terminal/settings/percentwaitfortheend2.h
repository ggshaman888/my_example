#ifndef PERCENTWAITFORTHEEND2_H
#define PERCENTWAITFORTHEEND2_H

#include <QObject>
#include <QThread>

class PercentWaitForTheEnd2 : public QThread {
    Q_OBJECT
public:
    explicit PercentWaitForTheEnd2(QThread* parent = nullptr);
    void run();

signals:
    void percent(int);
};

#endif // PERCENTWAITFORTHEEND2_H
