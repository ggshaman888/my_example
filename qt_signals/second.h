#ifndef SECOND_H
#define SECOND_H

#include <QObject>
#include "api_from_ux.h"

class Second : public QObject
{
    Q_OBJECT
public:
    explicit Second(QObject *parent = nullptr);

signals:
    void info(APIFromUX);

public slots:
    void infoSlot(APIFromUX);
};

#endif // SECOND_H
