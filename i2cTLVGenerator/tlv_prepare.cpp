#include "tlv_prepare.h"

TLVPrepare::TLVPrepare(QObject* parent) : QObject(parent) {}

void TLVPrepare::getTLV(QStringList is_tlv)
{
    tlv_list = is_tlv;
    tlv.clear();
    for (auto tlv_element: tlv_list) {
        tlv.append(tlv_element);
    }
    readValueTLV();
    setCRC16();
}

void TLVPrepare::addMACInHEX(QString is_mac)
{
    qDebug() << "is_mac______0";
    is_mac.replace(":", "");
    is_mac.replace("-", "");
    is_mac.replace(".", "");
    qDebug() << "is_mac______1" << tlv_list;
    readTLVFromSettings();
    qDebug() << "is_mac______2" << tlv_list;
    getTLV(tlv_list);
    qDebug() << "is_mac______3" << tlv_list;
    readTLV();
    qDebug() << "is_mac______4" << tlv_list;
}

QStringList TLVPrepare::readTLV()
{
    tlv.clear();
    for (auto str: tlv_list) {
        tlv += str;
    }
    tlv_list << tlv;
    qDebug() << tlv_list << "tlv_list";
    setTLVToSettings();
    setI2cCommandMW();
    return tlv_list;
}

bool TLVPrepare::correctly()
{
    bool ok;

    return ok;
}

void TLVPrepare::readValueTLV()
{
    value_tlv.clear();
    int count = 0;
    QString back;
    for (auto str: tlv_list) {
        if (count > 1) {
            value_tlv.append(str);
            back  = str;
            count = 0;
        }
        else {
            count++;
        }
    }
    // записать кроме crc16
    value_tlv = value_tlv.mid(0, value_tlv.size() - back.size());
    for (int i = 0; i < value_tlv; i++) {
        if (!value_tlv.mid(i, 2).isEmpty()) {
            appendToHex(value_tlv.mid(i, 2));
        }
        i++;
    }
}

void TLVPrepare::setCRC16()
{
    hex_tlv.clear();
    r_tlv.readTLV(tlv);
    if (r_tlv.tlvTrue()) {
        tlv_parse = r_tlv.isTLV();
        for (auto is_tlv: tlv_parse) {
            appendTLVElemToHexNotCrcData(is_tlv);
        }
    }
    else {
        qDebug() << "tlv bad: " << tlv;
    }

    //! Получить crc16.
    uchar x[hex_tlv.size()];
    for (int i = 0; i < hex_tlv.size(); i++) {
        x[i] = hex_tlv.at(i);
    }
    auto crc_is = cyg_crc16(x, hex_tlv.size());
    //! Добавить crc16 в TLV лист.
    QString valueInHex = QString("%1").arg(crc_is, 0, 16);
    tlv_list.last().clear();
    tlv_list.last().append(valueInHex);
}

void TLVPrepare::appendToHex(QString str)
{
    bool ok;
    qint64 hex           = str.toLongLong(&ok, 16);
    unsigned char buf[1] = {static_cast<uchar>(hex)};
    hex_tlv.append(QByteArray(reinterpret_cast<char*>(buf), 1));
}

void TLVPrepare::appendTLVElemToHexNotCrcData(ReadTLV::TLV_struct is_tlv)
{
    appendToHex(intToHEXStr(is_tlv.tag));
    appendToHex(intToHEXStr(is_tlv.length));
    if (is_tlv.tag != 0xFE) {
        for (int i = 0; i < is_tlv.data.size();) {
            appendToHex(is_tlv.data.mid(i, 2));
            i += 2;
        }
    }
}

void TLVPrepare::setTLVToSettings() {}

void TLVPrepare::setI2cCommandMW()
{
    int j = 0;
    for (int i = 0; i < tlv.size(); i++) {
        i2cCommandMW
            << QString("i2c mw 0x50 %1.2 0x%2 0x1").arg(j).arg(tlv.mid(i, 2));
        i++;
        j++;
    }
}

void TLVPrepare::setI2cCommandMD()
{
    int j = 0;
    for (int i = 0; i < tlv.size(); i++) {
        i2cCommandMD << QString("i2c md 0x50 %1.2 0x1").arg(j);
        i++;
        j++;
    }
}

void TLVPrepare::readTLVFromSettings()
{
    qDebug() << tlv_list << "get tlv sttings";
    tlv_list.clear();
    //    tlv_list << "tlv";
}
