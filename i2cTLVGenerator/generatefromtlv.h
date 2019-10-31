#ifndef GENERATEFROMTLV_H
#define GENERATEFROMTLV_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GenerateFromTLV;
}
QT_END_NAMESPACE

class GenerateFromTLV : public QWidget {
    Q_OBJECT

public:
    GenerateFromTLV(QWidget* parent = nullptr);
    ~GenerateFromTLV();

private slots:
    void on_pushButton_clicked();

private:
    QString line_tlv;
    void genLineTLV();
    QString line_value_tlv;
    void genLineValueTLV();
    QStringList i2c_command;
    void genListI2cCommand();
    QString i2c_comand_line(QString, int);
    QByteArray hex_data;
    void setHexData();
    void appendToHex(QString);
    void setcrc16();
    void clrVariable();
    Ui::GenerateFromTLV* ui;
};
#endif // GENERATEFROMTLV_H
