#ifndef PREPAREMAC_H
#define PREPAREMAC_H

#include <QObject>

class PrepareMac : public QObject
{
    Q_OBJECT
public:
    explicit PrepareMac(QObject *parent = nullptr);

    QStringList getMacRange(QString, QString);
    int_fast64_t getMacRangeCount(QString, QString);
    QStringList getMacRange(QString, uint);

signals:

public slots:
};

#endif // PREPAREMAC_H
