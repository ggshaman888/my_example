#include <QDebug>
#include <QtEndian>
#include <QCryptographicHash>
#include "generatefromtlv.h"
#include "./ui_generatefromtlv.h"
#include "crc-master/cyg_crc.h"

GenerateFromTLV::GenerateFromTLV(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::GenerateFromTLV)
{
    ui->setupUi(this);
}

GenerateFromTLV::~GenerateFromTLV()
{
    delete ui;
}

// i2c mw 0x50 X.2 0xXX 0x1
void GenerateFromTLV::on_pushButton_clicked()
{
    clrVariable(); // обнулить все переменные и списки.

    genLineValueTLV(); // собрать линию только из значений, без crc16
    setcrc16(); // генерировать crc16 и записать данные в таблицу

    genLineTLV(); // генерировать линию полность c crc16.
    setHexData(); // генерировать команды для i2c с crc16.
}

void GenerateFromTLV::genLineTLV()
{
    line_tlv.clear();

    line_tlv.append(ui->lineEdit->text())
        .append(ui->lineEdit_2->text())
        .append(ui->lineEdit_3->text());

    line_tlv.append(ui->lineEdit_4->text())
        .append(ui->lineEdit_5->text())
        .append(ui->lineEdit_6->text());

    line_tlv.append(ui->lineEdit_7->text())
        .append(ui->lineEdit_8->text())
        .append(ui->lineEdit_9->text());

    line_tlv.append(ui->lineEdit_10->text())
        .append(ui->lineEdit_11->text())
        .append(ui->lineEdit_12->text());

    line_tlv.append(ui->lineEdit_13->text())
        .append(ui->lineEdit_14->text())
        .append(ui->lineEdit_15->text());

    line_tlv.append(ui->lineEdit_16->text())
        .append(ui->lineEdit_17->text())
        .append(ui->lineEdit_18->text());
}

void GenerateFromTLV::genLineValueTLV()
{
    line_value_tlv.clear();
    line_value_tlv.append(ui->lineEdit_3->text());
    line_value_tlv.append(ui->lineEdit_6->text());
    line_value_tlv.append(ui->lineEdit_9->text());
    line_value_tlv.append(ui->lineEdit_12->text());
    line_value_tlv.append(ui->lineEdit_15->text());

    genListI2cCommand(); // генерировать hex_data, без crc16
}

void GenerateFromTLV::genListI2cCommand()
{
    for (int i = 0; i < line_value_tlv.size(); i++) {
        appendToHex(line_value_tlv.mid(i, 2));
        i++;
    }
}

QString GenerateFromTLV::i2c_comand_line(QString byte_is, int number_byte)
{
    QString i2c_is =
        QString("i2c mw 0x50 %1.2 0x%2 0x1").arg(number_byte).arg(byte_is);
    return i2c_is;
}

void GenerateFromTLV::setHexData()
{
    int j = 0;
    for (int i = 0; i < line_tlv.size(); i++) {
        i2c_command << i2c_comand_line(line_tlv.mid(i, 2), j);
        i++;
        j++;
    }

    for (auto str: i2c_command) {
        ui->textEdit->insertPlainText(str);
        ui->textEdit->insertPlainText("\n");
    }
}

void GenerateFromTLV::appendToHex(QString hex_str)
{
    bool ok;
    qint64 hex           = hex_str.toLongLong(&ok, 16);
    unsigned char buf[1] = {static_cast<uchar>(hex)};
    hex_data.append(QByteArray(reinterpret_cast<char*>(buf), 1));
}

void GenerateFromTLV::setcrc16()
{
    auto buf_hex = hex_data;
    uchar x[buf_hex.size()];
    for (int i = 0; i < buf_hex.size(); i++) {
        x[i] = buf_hex.at(i);
        qDebug() << x[i];
    }
    qDebug() << cyg_crc16(x, hex_data.size()) << hex_data;
    auto crc_is = cyg_crc16(x, hex_data.size());

    buf_hex.clear();
    uchar buf[2];

    buf[0] = ((uchar*)&crc_is)[1];
    buf[1] = ((uchar*)&crc_is)[0];

    buf_hex.append(QByteArray(reinterpret_cast<char*>(buf), 2));

    QString valueInHex = QString("%1").arg(crc_is, 0, 16);
    ui->lineEdit_18->setText(valueInHex);
    qDebug() << valueInHex;
}

void GenerateFromTLV::clrVariable()
{
    hex_data.clear();
    line_tlv.clear();
    line_value_tlv.clear();
}
