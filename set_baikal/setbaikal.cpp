#include "setbaikal.h"

SetBaikal::SetBaikal(QObject* parent) : QObject(parent)
{
    static int count = 0;
    count++;
    qDebug() << "construct" << count;
    setStep();
}

SetBaikal::~SetBaikal()
{
    qDebug() << "destruct";
}
/**
 * @brief SetBaikal::prepareBuffer
 * Обработка события исходя из данных полученных из консоли и выбранного шага.
 * @param buf Буфер данных из устройства
 * @param step_in Шаг операции.
 * @return Следующий шаг по плану.
 */
int SetBaikal::prepareBuffer(const QByteArray& buf, const int& step_in)
{
    ////    PIConsole* prepare = new PIConsole();
    ////    prepare->setStep(step);
    //    qDebug() << step_in << "step_____";

    //    switch (step_in) {
    //    case 0: {
    //        int step_out = prepare->set_00_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 1: {
    //        int step_out = prepare->set_30_(buf);
    //        to_device    = prepare->to_device;

    //        if (step_out != 1 && step_out != 1001) {
    //            step_out = prepare->set_01_(buf);
    //            qDebug() << step_out << to_device;
    //            to_device = prepare->to_device;
    //        }
    //        qDebug() << step_out << "step out______";
    //        return step_out;
    //    }
    //    case 2: {
    //        int step_out = prepare->set_02_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 3: {
    //        int step_out = prepare->set_03_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 4: {
    //        int step_out = prepare->set_04_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 5: {
    //        int step_out = prepare->set_05_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 6: {
    //        int step_out = prepare->set_06_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 7: {
    //        int step_out = prepare->set_07_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 8: {
    //        int step_out = prepare->set_08_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 9: {
    //        int step_out = prepare->set_09_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 10: {
    //        int step_out = prepare->set_10_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 11: {
    //        int step_out = prepare->set_11_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 12: {
    //        int step_out = prepare->set_12_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 13: {
    //        int step_out = prepare->set_13_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 14: {
    //        int step_out = prepare->set_14_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 15: {
    //        prepare->set_15_x(buf);
    //        int step_out = prepare->set_15_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 16: {
    //        int step_out = prepare->set_16_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 17: {
    //        prepare->set_17_x(buf);
    //        int step_out = prepare->set_17_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 18: {
    //        int step_out = prepare->set_18_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 19: {
    //        int step_out = prepare->set_19_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 20: {
    //        int step_out = prepare->set_20_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 21: {
    //        int step_out = prepare->set_21_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 22: {
    //        int step_out = prepare->set_22_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 23: {
    //        int step_out = prepare->set_23_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 24: {
    //        int step_out = prepare->set_24_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 25: {
    //        int step_out = prepare->set_25_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 26: {
    //        int step_out = prepare->set_26_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 27: {
    //        int step_out = prepare->set_27_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 28: {
    //        int step_out = prepare->set_28_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    case 29: {
    //        int step_out = prepare->set_29_(buf);
    //        to_device    = prepare->to_device;
    //        return step_out;
    //    }
    //    default:
    //        qDebug() << "Error in case setbaikal";
    //        emit toDevice("");
    //        return -1;
    //    }
}

QByteArray SetBaikal::bufRequestDevice(const QByteArray& data_, int size)
{
    static QByteArray data;
    data.push_back(data_);
    data = data.right(size);
    return data;
}
/**
 * @brief SetBaikal::setStep
 * Настройка не стандартных шагов для управления процедурой прошивки.
 * @example
 *    QString s_13 = "ip a a 192.168.1.60/24 dev eth0\r";
 *    QString s_14 =
 * "scp user@192.168.1.20:/home/user/work/baikal-image/img/baikal_image.part
 *  ./\r";
 *    QString s_15 = "123456\r";
 *    QString e_15 =
 * "/usr/bin/dbclient: Connection to user@192.168.1.20:22 exited:
 * Connect failed: No route to host";
 *    QString s_16 =
 * "scp user@192.168.1.20:/home/user/work/baikal-image/img/rootfs.squashfs
 *  ./\r";
 *    QString s_17 = "123456\r";
 *    step.s_13 = QString("ip a a %1%2 dev eth0\r")
 *            .arg(settings.value("ip_ssh").toString())
 *            .arg(settings.value("mask_ssh").toString());
 */
void SetBaikal::setStep()
{
    //    auto settings = SETTINGS_USER;
    //    step.s_13     = QString("\r");
    //    step.s_14     = QString("scp %1@%2:%3 ./\r")
    //                    .arg(settings->value("user_ssh").toString())
    //                    .arg(settings->value("ip_server_ssh").toString())
    //                    .arg(settings->value("path_ssh").toString());
    //    step.s_15 = QString("%1\r").arg(settings->value("pass_ssh").toString());
    //    step.e_15 = QString("/usr/bin/dbclient: Connection to %1@%2 exited: "
    //                        "Connect failed: No route to host")
    //                    .arg(settings->value("user_ssh").toString())
    //                    .arg(settings->value("ip_server_ssh").toString());
    //    step.s_16 = QString("scp %1@%2:%3 ./\r")
    //                    .arg(settings->value("user_ssh").toString())
    //                    .arg(settings->value("ip_server_ssh").toString())
    //                    .arg(settings->value("path_ssh_fs").toString());
    //    step.s_17 = QString("%1\r").arg(settings->value("pass_ssh").toString());

    //    step.s_19 = QString("flashcp -v %1 /dev/mtd1\r")
    //                    .arg(settings->value("file_img_ssh").toString());
    //    step.e_19 = QString("While trying to open %1: No such file "
    //                        "or directory")
    //                    .arg(settings->value("file_img_ssh").toString());
    //    step.s_22 = QString("mv %1 /mnt/img/img-1\r")
    //                    .arg(settings->value("file_squashfs_ssh").toString());
}

void SetBaikal::timer()
{
    QThread::msleep(20);
}

void SetBaikal::sendToDevice()
{
    if (!buf_to_device.isEmpty()) {
        emit toDevice(buf_to_device);
        buf_to_device.clear();
    }
}
