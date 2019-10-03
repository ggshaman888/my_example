#ifndef CONVERTMAC_H
#define CONVERTMAC_H

#include <QObject>

using namespace std;
class ConvertMAC : public QObject {
    Q_OBJECT
public:
    explicit ConvertMAC(QObject* parent = nullptr);


    void examplePrepareMac();

    void loadMacAddress(std::vector<uchar>);
    void loadMacAddress(QString);
    /**
     * @brief upMac Increising mac by 1.
     * @return Increase.
     */
    bool upMac();
    QString getMac();
    /**
     * @brief getMacToDec Glues the uchar vector by converting to a decimal
     * number.
     * @return Decimail number;
     */
    int_fast64_t getMacToDec();
    std::vector<uchar> getMacVector();



signals:

public slots:

private:
    std::vector<uchar> mac;
    QString mac_str;
    void clrMAC(const QString);
    /**
     * @brief charToHEX Convering dec to hex.
     * @see https://stackoverflow.com/a/29759644
     * @return HEX.
     */
    QString charToHEX(uchar);
    void setFromString();
};

#endif // CONVERTMAC_H
