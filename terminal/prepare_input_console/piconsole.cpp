#include <QThread>
#include <QByteArray>
#include "piconsole.h"
#include "../setbaikal.h"

#define RETURN_DEFAULT(number, str, str2)        \
    if (data.indexOf(str) > -1) {                \
        QThread::msleep(20);                     \
        to_device = QString(str2).toLocal8Bit(); \
        return number + 1;                       \
    }                                            \
    return number;
#define RETURN_LENGTH(number, str, str2, _length_) \
    if (data.right(_length_).indexOf(str) > -1) {  \
        QThread::msleep(20);                       \
        to_device = QString(str2).toLocal8Bit();   \
        return number + 1;                         \
    }                                              \
    return number;
#define RETURN_LENGTH_X(number, str, str2, _length_) \
    if (data.right(_length_).indexOf(str) > -1) {    \
        QThread::msleep(20);                         \
        to_device = QString(str2).toLocal8Bit();     \
    }                                                \
    return number;

#define RETURN_2IF_RIGHT(number, str, str_1, str2)   \
    if (data.right(200).lastIndexOf(str) > -1) {     \
        if (data.right(2).lastIndexOf(str_1) > -1) { \
            QThread::msleep(20);                     \
            to_device = QString(str2).toLocal8Bit(); \
            return number + 1;                       \
        }                                            \
    }                                                \
    return number;

#include <QDebug>

PIConsole::PIConsole(QObject* parent) : QObject(parent) {}

PIConsole::~PIConsole()
{
    destroyed(this);
}

void PIConsole::setStep(SetBaikal::Steps& step_new)
{
    step = &step_new;
}

int PIConsole::set_00_(const QByteArray& data)
{
    RETURN_DEFAULT(0, step->a_00, step->s_00);
}

int PIConsole::set_01_(const QByteArray& data)
{
    RETURN_LENGTH(1, step->a_01, step->s_01, 2);
}

int PIConsole::set_02_(const QByteArray& data)
{
    RETURN_LENGTH(2, step->a_02, step->s_02, 2);
}

int PIConsole::set_03_(const QByteArray& data)
{
    RETURN_LENGTH(3, step->a_03, step->s_03, 2);
}

int PIConsole::set_04_(const QByteArray& data)
{
    RETURN_DEFAULT(4, step->a_04, step->s_04);
}

int PIConsole::set_05_(const QByteArray& data)
{
    RETURN_LENGTH(5, step->a_05, step->s_05, 2);
}

int PIConsole::set_06_(const QByteArray& data)
{
    RETURN_2IF_RIGHT(6, step->a_06, step->a_06_1, step->s_06);
}

int PIConsole::set_07_(const QByteArray& data)
{
    RETURN_2IF_RIGHT(7, step->a_07, step->a_07_1, step->s_07);
}

int PIConsole::set_08_(const QByteArray& data)
{
    RETURN_2IF_RIGHT(8, step->a_08, step->a_08_1, step->s_08);
}

int PIConsole::set_09_(const QByteArray& data)
{
    RETURN_LENGTH(9, step->a_09, step->s_09, 2);
}

int PIConsole::set_10_(const QByteArray& data)
{
    RETURN_LENGTH(10, step->a_10, step->s_10, 2);
}

int PIConsole::set_11_(const QByteArray& data)
{
    RETURN_LENGTH(11, step->a_11, step->s_11, 2);
}

int PIConsole::set_12_(const QByteArray& data)
{
    RETURN_LENGTH(12, step->a_12, step->s_12, 2);
}

int PIConsole::set_13_(const QByteArray& data)
{
    RETURN_LENGTH(13, step->a_13, step->s_13, 2);
}

int PIConsole::set_14_(const QByteArray& data)
{
    RETURN_LENGTH(14, step->a_14, step->s_14, 2);
}

int PIConsole::set_15_x(const QByteArray& data)
{
    RETURN_LENGTH_X(15, step->a_15_x, step->s_15_x, 45);
}

int PIConsole::set_15_(const QByteArray& data)
{
    RETURN_LENGTH(15, step->a_15, step->s_15, 26);
}

int PIConsole::set_16_(const QByteArray& data)
{
    RETURN_LENGTH(16, step->a_16, step->s_16, 2);
}

int PIConsole::set_17_x(const QByteArray& data)
{
    RETURN_LENGTH_X(17, step->a_17_x, step->s_17_x, 45);
}

int PIConsole::set_17_(const QByteArray& data)
{
    RETURN_LENGTH(17, step->a_17, step->s_17, 20);
}

int PIConsole::set_18_(const QByteArray& data)
{
    RETURN_LENGTH(18, step->a_18, step->s_18, 2);
}

int PIConsole::set_19_(const QByteArray& data)
{
    RETURN_2IF_RIGHT(19, step->a_19, step->a_19_1, step->s_19);
}

int PIConsole::set_20_(const QByteArray& data)
{
    RETURN_LENGTH(20, step->a_20, step->s_20, 2);
}

int PIConsole::set_21_(const QByteArray& data)
{
    RETURN_LENGTH(21, step->a_21, step->s_21, 2);
}

int PIConsole::set_22_(const QByteArray& data)
{
    RETURN_LENGTH(22, step->a_22, step->s_22, 2);
}

int PIConsole::set_23_(const QByteArray& data)
{
    RETURN_LENGTH(23, step->a_23, step->s_23, 2);
}

int PIConsole::set_24_(const QByteArray& data)
{
    RETURN_LENGTH(24, step->a_24, step->s_24, 2);
}

int PIConsole::set_25_(const QByteArray& data)
{
    RETURN_LENGTH(25, step->a_25, step->s_25, 2);
}

int PIConsole::set_26_(const QByteArray& data)
{
    RETURN_LENGTH(26, step->a_26, step->s_26, 2);
}

int PIConsole::set_27_(const QByteArray& data)
{
    RETURN_LENGTH(27, step->a_27, step->s_27, 2);
}

int PIConsole::set_28_(const QByteArray& data)
{
    RETURN_LENGTH(28, step->a_28, step->s_28, 2);
}

int PIConsole::set_29_(const QByteArray& data)
{
    qDebug() << "FINISHED____";
    RETURN_LENGTH_X(1000, step->a_29, step->s_29, 2);
}
