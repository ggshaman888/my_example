#include <sstream>
#include <iostream>
#include <QDebug>
#include "convert_mac.h"

using namespace std;

ConvertMAC::ConvertMAC(QObject* parent) : QObject(parent) {}

void ConvertMAC::examplePrepareMac()
{
    loadMacAddress("ff:01:45:67:89:ff");
    upMac();
    mac = getMacVector();
    qDebug() << getMac();
}

void ConvertMAC::loadMacAddress(QString is_mac)
{
    clrMAC(is_mac);
}

void ConvertMAC::clrMAC(QString is_mac)
{
    mac_str = is_mac.replace(":", "");
    mac_str = is_mac.replace("-", "");
    mac_str = is_mac.replace(".", "");
    setFromString();
}

QString ConvertMAC::charToHEX(uchar dec)
{
    int rem;
    string s = "";
    while (dec > 0) // Do this whilst the quotient is greater than 0.
    {
        rem = dec % 16; // Get the remainder.
        if (rem > 9) {
            // Map the character given that the remainder is greater than 9.
            switch (rem) {
            case 10:
                s = "A" + s;
                break;
            case 11:
                s = "B" + s;
                break;
            case 12:
                s = "C" + s;
                break;
            case 13:
                s = "D" + s;
                break;
            case 14:
                s = "E" + s;
                break;
            case 15:
                s = "F" + s;
                break;
            }
        }
        else {
            s = char(rem + 48) + s; // Converts integer (0-9) to ASCII code.
            // x + 48 is the ASCII code for x digit (if 0 <= x <= 9)
        }
        dec = dec / 16;
    }

    if (s == "") // if the number was 0, the string will remain empty
        return "00";
    else {
        auto buf = QString::fromStdString(s);
        if (buf.size() == 1) {
            buf.prepend("0");
        }
        return buf;
    }
}

bool ConvertMAC::upMac()
{
    bool ok      = false;
    ushort digit = 5;
    while (digit < 255) {
        if (mac.at(digit) < 255) {
            mac[digit] = mac.at(digit) + 1;
            ok         = true;
            break;
        }
        else { // upping digits.
            mac[digit] = 0;
            digit--;
        }
    }
    return ok;
}

void ConvertMAC::setFromString()
{
    QString buf;
    int j = 0;
    for (int i = 0; i < 11; i++) {
        buf.clear();
        buf.append(mac_str.at(i)).append(mac_str.at(i + 1));
        if (!(i % 2)) {
            j++;
            std::stringstream ss;
            uint x;
            ss << std::hex << buf.toStdString();
            ss >> x;
            mac.push_back(static_cast<uchar>(x));
        }
    }
}

QString ConvertMAC::getMac()
{
    QString buf;
    for (uint i = 0; i < 6; i++) {
        buf += charToHEX(mac.at(i));
        if (i == 5) {
            break;
        }
        buf += ":";
    }
    return buf;
}

std::vector<uchar> ConvertMAC::getMacVector()
{
    return mac;
}
