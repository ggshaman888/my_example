#ifndef GENERATEDMACADDRES_H
#define GENERATEDMACADDRES_H

#include <QStringList>
#include <atomic>
#include <QDebug>
#include <random>

using namespace std;

class GeneratedMacAddres {
public:
    explicit GeneratedMacAddres();

    QStringList genRange(const QString&, const QString&);
    QStringList genRange(const QString&, int);
    QString genRandomMAC();

    uint returnRandom()
    {
        std::uniform_int_distribution<uint> range(0, max_part);
        return range(random_generator_);
    }

private:
    const uint max_part = 16777215;
    QString mac_str_buf;

    struct MACInt {
        uint first;
        uint last;

        bool operator>(const GeneratedMacAddres::MACInt& y) const
        {
            if (this->first == y.first) {
                if (this->last > y.last) {
                    return true;
                }
                return false;
            }
            if (this->first > y.first) {
                return true;
            }
            else {
                return false;
            }
        }
    } mac;

    void upMac(QString);
    void upMac();
    QString macToStr(const GeneratedMacAddres::MACInt&);
    MACInt setMacStringToInt(const QString&);
    QString clrMac(QString);
    QString formatedMAC(const QString&);


private:
    std::mt19937 random_generator_;
};

#endif // GENERATEDMACADDRES_H
