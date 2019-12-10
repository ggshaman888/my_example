#ifndef PICONSOLE_H
#define PICONSOLE_H

#include <QObject>
#include <QByteArray>
#include "../setbaikal.h"

class PIConsole : public QObject {
    Q_OBJECT
public:
    explicit PIConsole(QObject* parent = nullptr);
    ~PIConsole();

    void setStep(SetBaikal::Steps&);

    QByteArray to_device;
    int set_00_(const QByteArray&);
    int set_01_(const QByteArray&);
    int set_02_(const QByteArray&);
    int set_03_(const QByteArray&);
    int set_04_(const QByteArray&);
    int set_05_(const QByteArray&);
    int set_06_(const QByteArray&);
    int set_07_(const QByteArray&);
    int set_08_(const QByteArray&);
    int set_09_(const QByteArray&);
    int set_10_(const QByteArray&);
    int set_11_(const QByteArray&);
    int set_12_(const QByteArray&);
    int set_13_(const QByteArray&);
    int set_14_(const QByteArray&);
    int set_15_x(const QByteArray&);
    int set_15_(const QByteArray&);
    int set_16_(const QByteArray&);
    int set_17_x(const QByteArray&);
    int set_17_(const QByteArray&);
    int set_18_(const QByteArray&);
    int set_19_(const QByteArray&);
    int set_20_(const QByteArray&);
    int set_21_(const QByteArray&);
    int set_22_(const QByteArray&);
    int set_23_(const QByteArray&);
    int set_24_(const QByteArray&);
    int set_25_(const QByteArray&);
    int set_26_(const QByteArray&);
    int set_27_(const QByteArray&);
    int set_28_(const QByteArray&); // reboot
    int set_29_(const QByteArray&);

private:
    SetBaikal::Steps* step;
};

#endif // PICONSOLE_H
