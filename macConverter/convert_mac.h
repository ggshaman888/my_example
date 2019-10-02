#ifndef CONVERTMAC_H
#define CONVERTMAC_H

#include <QObject>

class ConvertMAC : public QObject
{
    Q_OBJECT
public:
    explicit ConvertMAC(QObject *parent = nullptr);

    void setMac();

    void setFromString();
    QString getMAC();

    struct Mac {
        uchar mac_c[6] = {0};
    } mac;

signals:

public slots:

private:
    QString mac_str;
    void clrMAC(QString);
    /**
     * @brief charToHEX Convering dec to hex.
     * @see https://stackoverflow.com/a/29759644
     * @return HEX.
     */
    QString charToHEX(uchar);
    /**
     * @brief upMac Increising mac by 1.
     * @return Increase.
     */
    bool upMac();
};

#endif // CONVERTMAC_H
