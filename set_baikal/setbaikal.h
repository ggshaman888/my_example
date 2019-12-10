#ifndef SETBAIKAL_H
#define SETBAIKAL_H

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QSettings>
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrentRun>
//#include "prepare_input_console/piconsole.h"
//#include "settings/global_settings.h"

class SetBaikal : public QObject {
    Q_OBJECT
public:
    explicit SetBaikal(QObject* parent = nullptr);
    ~SetBaikal();

    QByteArray to_device;
    int count_repeat = 1;
    int prepareBuffer(const QByteArray& buf = nullptr, const int& step_in = 0);
    void setStep();

    struct Steps {
        bool step_00 = false;
        QString a_00 = "Hit any key to stop autoboot";
        QString s_00 = "\r";

        bool step_30 = false;
        QString a_30 = "#";
        QString s_30 = ""; // строка генерируется. Для i2c.

        bool step_01 = false;
        QString a_01 = "#"; // последний символ
        QString s_01 = "setenv bootargs console=ttyS0,115200,n8 maxcpus=2 "
                       "nohtw stmmaceth=chan_mode:1 "
                       "earlyprintk=uart8250,mmio32,0x1F04A000"
                       ",115200 mtdparts=spi0.0:256k(pad),16m(raw),-(ubifs)\r";
        bool step_02 = false;
        QString a_02 = "#";
        QString s_02 = "saveenv\r";
        bool step_03 = false;
        QString a_03 = "#"; //"Saving Environment to Flash...";
        QString s_03 = "run flash_boot_ram\r";
        QString e_03 = "## Error: \"flash_boot_ram\" not defined";
        bool step_04 = false;
        QString a_04 = "Please press Enter to activate this console.";
        QString s_04 = "\r";
        bool step_05 = false;
        QString a_05 = "#"; // последний символ
        QString s_05 = "\rflash_erase /dev/mtd2 0 0\r";
        bool step_06 = false;
        QString a_06 =
            "Erasing 256 Kibyte"; //Erasing 256 Kibyte @ 2f830000 -- 100 % complete
        QString a_06_1 = "#";
        QString s_06 =
            "ubiformat /dev/mtd2\r"; //ubiformat: formatting eraseblock 190 -- 100 % complete
        bool step_07   = false;
        QString a_07   = "ubiformat: formatting eraseblock";
        QString a_07_1 = "#";
        QString s_07   = "ubiattach -m 2 /dev/ubi_ctrl\r";
        bool step_08   = false;
        QString a_08   = "UBI device number";
        QString a_08_1 = "#"; // последний символ
        QString s_08   = "ubimkvol /dev/ubi0 -N ubifs -s 46MiB\r";
        bool step_09   = false;
        QString a_09   = "#";
        QString s_09   = "mount -t ubifs /dev/ubi0_0 /mnt\r";
        bool step_10   = false;
        QString a_10   = "#";
        QString s_10   = "mkdir -p /mnt/tmp\r";
        bool step_11   = false;
        QString a_11   = "#";
        QString s_11   = "mount -t tmpfs tmpfs /mnt/tmp\r";
        bool step_12   = false;
        QString a_12   = "#";
        QString s_12   = "cd /mnt/tmp\r";
        bool step_13   = false;
        QString a_13   = "#";
        QString s_13   = "SETTINGS";
        bool step_14   = false;
        QString a_14   = "#";
        QString s_14   = "SETTINGS";
        bool step_15   = false;
        QString a_15_x = "Do you want to continue connecting? (y/n)";
        QString s_15_x = "y\r";
        QString a_15   = "password:";
        QString s_15   = "SETTINGS";
        QString e_15   = "SETTINGS";
        bool step_16   = false;
        QString a_16   = "#";
        QString s_16   = "SETTINGS";
        bool step_17   = false;
        QString a_17_x = "Do you want to continue connecting? (y/n)";
        QString s_17_x = "y\r";
        QString a_17   = "password:";
        QString s_17   = "SETTINGS";
        bool step_18   = false;
        QString a_18   = "#";
        QString s_18 =
            "\rflash_erase /dev/mtd1 0 0\r"; //Erasing 256 Kibayte @ 2f830000 -- 100 % complete
        bool step_19   = false;
        QString a_19   = "Erasing 256 Kib";
        QString a_19_1 = "#";
        QString s_19   = "SETTINGS";
        QString e_19   = "SETTINGS";
        bool step_20   = false;
        QString a_20   = "#";
        QString s_20   = "sync\r";
        bool step_21   = false;
        QString a_21   = "#";
        QString s_21   = "mkdir -p /mnt/img && sync\r";
        bool step_22   = false;
        QString a_22   = "#";
        QString s_22   = "SETTINGS";
        bool step_23   = false;
        QString a_23   = "#";
        QString s_23   = "cd /mnt/img/\r";
        bool step_24   = false;
        QString a_24   = "#";
        QString s_24   = "touch active\r"; // в последней редакции - стала лишней
        bool step_25   = false;
        QString a_25   = "#";
        QString s_25   = "touch current\r"; // в последней редакции - стала лишней
        bool step_26   = false;
        QString a_26   = "#";
        QString s_26   = "echo 1 > active && echo 1 > current\r";
        bool step_27   = false;
        QString a_27   = "#";
        QString s_27   = "sync\r";
        bool step_28   = false;
        QString a_28   = "#";
        QString s_28   = "reboot\r";
        bool step_29   = false;
        QString a_29   = "prosweat-rse login";
        QString s_29   = "||||FINISHED||||\r";
        //    QString s_25 = "flashimgload 86000000";
    } step;

signals:
    void toDevice(const QByteArray& data);
    void isSend(QByteArray);
    void resetSerial(QString);

public slots:
    void timer();
    void sendToDevice();

private:
    QByteArray buf_to_device = "";
    QByteArray bufRequestDevice(const QByteArray&, int size = 1000);

    int is_step  = 0;
    bool is_true = true;

    QSettings settings;
};

#endif // SETBAIKAL_H
