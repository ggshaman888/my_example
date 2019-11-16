#ifndef TLVPREPARE_H
#define TLVPREPARE_H

#include <QObject>
#include <QByteArray>
#include <QSettings>
#include <QString>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include "crc-master/cyg_crc.h"
#include "read_tlv.h"

using namespace std;
class TLVPrepare : public QObject {
    Q_OBJECT
public:
    explicit TLVPrepare(QObject* parent = nullptr);
    /**
     * @brief getTLV получить новый TLV и пересчитать и записать его в настройки.
     */
    void getTLV(QStringList);
    /**
     * @brief addMACInHEX добавить MAC в HEX формате в TLV. Пересчитать TLV.
     */
    void addMACInHEX(QString);
    /**
     * @brief readTLV прочитать текущий TLV.
     * @return
     */
    QStringList readTLV();
    /**
     * @brief correctly Проверка TLV данных на корректность.
     * @return
     */
    bool correctly();
signals:

public slots:
private:
    template<typename T>
    QString intToHEXStr(T i)
    {
        std::stringstream stream;
        stream << std::hex << static_cast<int>(i);
        auto str = QString::fromStdString(stream.str());
        if (i < 0x10) {
            str.prepend("0");
        }
        return str;
    }
    QStringList tlv_list; //< TLV в виде списка.
    QString tlv; //< TLV в виде строки.
    QString value_tlv; //< только значения из TLV.
    QByteArray hex_tlv; //< tlv в hex формате.
    QStringList i2cCommandMW; //< список команд для записи на eeprom.
    QStringList i2cCommandMD; //< список команд для чтения с eeprom.
    void readValueTLV(); //< собрать строку только из значений без crc16.
    void setCRC16(); //< посчитать контрольную сумму, только для значений.
    void appendToHex(QString); //< преобразовать два символа в HEX и прирастить.
    /**
     * @brief appendTLVElemToHexNotCrcData Преобразовать элемент структуры TLV
     * в HEX, кроме data-crc16.
     */
    void appendTLVElemToHexNotCrcData(ReadTLV::TLV_struct);
    void setTLVToSettings(); //< добавить в глобальные настройки значения TLV.
    void setI2cCommandMW(); //< сконфигурировать i2cCommandMW.
    void setI2cCommandMD(); //< сконфигурировать i2cCommandMd.
    void readTLVFromSettings(); //< заполнить текущий класс данными из QSettings.
    ReadTLV r_tlv; //< Парсер TLV.
    QList<ReadTLV::TLV_struct> tlv_parse; //< Спарсенный TLV.
};

#endif // TLVPREPARE_H
