#ifndef CONVERTMAC_H
#define CONVERTMAC_H

#include <QObject>

class ConvertMAC : public QObject
{
    Q_OBJECT
public:
    explicit ConvertMAC(QObject *parent = nullptr);


    void examplePrepareMac();

    void loadMacAddress(QString);
    /**
     * @brief upMac Increising mac by 1.
     * @return Increase.
     */
    bool upMac();
    QString getMAC();



signals:

public slots:

private:
    uchar mac[6] = {0};
    QString mac_str;
    void clrMAC(QString);
    /**
     * @brief charToHEX Convering dec to hex.
     * @see https://stackoverflow.com/a/29759644
     * @return HEX.
     */
    QString charToHEX(uchar);
    void setFromString();
};

#endif // CONVERTMAC_H
