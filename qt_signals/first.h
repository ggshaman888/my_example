#ifndef FIRST_H
#define FIRST_H

#include <QObject>
#include "api_from_ux.h"
class First : public QObject
{
    Q_OBJECT
public:
    explicit First(QObject *parent = nullptr);

    void runIs();
signals:
    void info(APIFromUX);

public slots:
};

#endif // FIRST_H
