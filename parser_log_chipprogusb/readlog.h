#ifndef READLOG_H
#define READLOG_H

#include <QObject>

class ReadLog : public QObject
{
    Q_OBJECT
public:
    explicit ReadLog(QObject *parent = nullptr);

signals:

public slots:
};

#endif // READLOG_H
