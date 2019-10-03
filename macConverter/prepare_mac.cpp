#include <QtDebug>
#include "prepare_mac.h"
#include "convert_mac.h"

PrepareMac::PrepareMac(QObject* parent) : QObject(parent) {}

QStringList PrepareMac::getMacRange(QString start_mac, QString end_mac)
{
    getMacRangeCount(start_mac, end_mac);
    return getMacRange("00:00:00:00:00:00", 1);
}

int_fast64_t PrepareMac::getMacRangeCount(QString start_mac, QString end_mac)
{
    auto convert = new ConvertMAC;
    convert->loadMacAddress(start_mac);
    //   convert->upMac();
    convert->getMac();

    auto start = convert->getMacVector();
    convert->loadMacAddress(end_mac);
    convert->getMac();

    auto end = convert->getMacVector();

    convert->loadMacAddress(start_mac);
    convert->loadMacAddress(end_mac);


    std::vector<uchar> diff;
    for (ushort i = 5; i < 255; i--) {
        diff.push_back(0);
        if (start.at(i) != end.at(i)) {
            int x                 = start.at(i) - end.at(i);
            diff[diff.size() - 1] = static_cast<uchar>(x < 0 ? x * -1 : x);
        }
    }
    std::reverse(diff.begin(), diff.end());
    convert->loadMacAddress(diff);
    qDebug() << convert->getMac() << convert->getMacToDec();
    return 1;
}

QStringList PrepareMac::getMacRange(QString is_mac, uint count)
{
    auto convert = new ConvertMAC;
    convert->loadMacAddress(is_mac);
    QStringList mac_list;
    for (uint i = 0; i < count; i++) {
        convert->upMac();
        mac_list << convert->getMac();
    }
    return mac_list;
}
