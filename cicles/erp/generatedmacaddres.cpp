#include <QDebug>
#include <QRandomGenerator>
#include "generatedmacaddres.h"
//#include "../global/random.hpp"

GeneratedMacAddres::GeneratedMacAddres()
{
    std::random_device device;
    random_generator_.seed(device());
}

QStringList GeneratedMacAddres::genRange(const QString& start, const QString& end)
{
    QStringList list_mac;
    auto end_mac = setMacStringToInt(clrMac(end));

    mac = setMacStringToInt(clrMac(start));
    while (end_mac > mac) {
        upMac();
        list_mac << formatedMAC(mac_str_buf);
    }
    return list_mac;
}

QStringList GeneratedMacAddres::genRange(const QString& start, int count)
{
    QStringList list_mac;

    mac = setMacStringToInt(clrMac(start));
    while (count > 0) {
        count--;
        upMac();
        list_mac << formatedMAC(mac_str_buf);
    }
    return list_mac;
}

QString GeneratedMacAddres::genRandomMAC()
{
    QRandomGenerator random_is;

    GeneratedMacAddres::MACInt mac_is;
    //    mac_is.first = Random::get(static_cast<uint>(random_is.bounded(0, static_cast<int>(max_part))));
    //    mac_is.last = Random::get(static_cast<uint>(random_is.bounded(0, static_cast<int>(max_part))));
    mac_is.first = returnRandom();
    mac_is.last  = returnRandom();

    return formatedMAC(macToStr(mac_is));
}

void GeneratedMacAddres::upMac(QString is_mac)
{
    setMacStringToInt(clrMac(is_mac));
    upMac();
}

void GeneratedMacAddres::upMac()
{
    if (mac.last >= max_part) {
        mac.last = max_part;
        if (mac.first >= max_part) {
            mac.first = max_part;
        }
        else {
            mac.first++;
        }
    }
    else {
        mac.last++;
    }
    mac_str_buf = macToStr(mac);
}

QString GeneratedMacAddres::macToStr(const GeneratedMacAddres::MACInt& mac_is)
{
    QString buf;
    buf = QString::number(mac_is.first, 16);
    buf += QString::number(mac_is.last, 16);

    while (buf.size() < 12) {
        buf += QString::number(QRandomGenerator::global()->bounded(9));
    }
    return buf.mid(0, 12);
}

GeneratedMacAddres::MACInt
GeneratedMacAddres::setMacStringToInt(const QString& mac_is)
{
    GeneratedMacAddres::MACInt mac;
    bool ok;
    uchar mac_ch[6] = {0};
    QString x       = mac_is.mid(0, 2);
    mac_ch[0]       = static_cast<uchar>(x.prepend("0x").toUInt(&ok, 16));
    x               = mac_is.mid(2, 2);
    mac_ch[1]       = static_cast<uchar>(x.prepend("0x").toUInt(&ok, 16));
    x               = mac_is.mid(4, 2);
    mac_ch[2]       = static_cast<uchar>(x.prepend("0x").toUInt(&ok, 16));
    x               = mac_is.mid(6, 2);
    mac_ch[3]       = static_cast<uchar>(x.prepend("0x").toUInt(&ok, 16));
    x               = mac_is.mid(8, 2);
    mac_ch[4]       = static_cast<uchar>(x.prepend("0x").toUInt(&ok, 16));
    x               = mac_is.mid(10, 2);
    mac_ch[5]       = static_cast<uchar>(x.prepend("0x").toUInt(&ok, 16));

    mac.first = static_cast<uint>(mac_ch[0] << 8 * 2 | mac_ch[1] << 8 | mac_ch[2]);
    mac.last = static_cast<uint>(mac_ch[3] << 8 * 2 | mac_ch[4] << 8 | mac_ch[5]);

    return mac;
}

QString GeneratedMacAddres::clrMac(QString is_mac)
{
    is_mac = is_mac.toLower();
    is_mac.replace(" ", "");
    is_mac.replace(".", "");
    is_mac.replace(";", "");
    is_mac.replace(":", "");
    is_mac.replace("-", "");
    return is_mac;
}

QString GeneratedMacAddres::formatedMAC(const QString& mac_is)
{
    QString mac_buf = mac_is;
    mac_buf.insert(2, ":");
    mac_buf.insert(5, ":");
    mac_buf.insert(8, ":");
    mac_buf.insert(11, ":");
    mac_buf.insert(14, ":");
    qDebug() << mac_is << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << mac_buf;

    return mac_buf; //.mid(0, 17); // for genRandomMAC();
}
