#include <QThread>
#include <QSerialPortInfo>
#include <QDebug>
#include "threadwaitcom.h"
//#include "global.h"

#define PAUSE_MILLISECONDS 500
/**
 * @brief ThreadWaitCOM::ThreadWaitCOM
 * Ожидание и поиск COM порта для соединения с устройством.
 * @param parrent
 */
ThreadWaitCOM::ThreadWaitCOM(QThread* parrent) : QThread(parrent)
{
    port_is_true = false;
}

ThreadWaitCOM::~ThreadWaitCOM()
{
    qDebug() << "ThreadWaitCOM::~ThreadWaitCOM()";
}
/**
 * @brief ThreadWaitCOM::run
 * Циклический поиск нового COM порта и передача его через сигнал.
 */
void ThreadWaitCOM::run()
{
    firstPreapare();
    while (!port_is_true) {
        setNewPortList(readListCOMPorts());
        emitNewCOM();

        if (breakWhileRun()) {
            break;
        }
        // qDebug() << new_com << "||||new_com";
        QThread::msleep(PAUSE_MILLISECONDS);
    }
    qDebug() << com_list << "com list";
}
/**
 * @brief ThreadWaitCOM::infoNewCOM
 * @param is Вызвать сигнал с наименованием COM порта.
 */
void ThreadWaitCOM::infoNewCOM(bool is)
{
    if (is) {
        emit newCOM(new_com);
    }
}
/**
 * @brief ThreadWaitCOM::stopListened
 * @param is Остановить поиск нового порта
 */
void ThreadWaitCOM::stopListened(bool is)
{
    port_is_true = is;
}
/**
 * @brief ThreadWaitCOM::readListCOMPorts
 * @return Список обнаруженных в системе COM портов.
 */
QStringList ThreadWaitCOM::readListCOMPorts()
{
    const auto infos = QSerialPortInfo::availablePorts();
    QStringList ports;
    if (!infos.isEmpty()) {
        for (const QSerialPortInfo& info: infos) {
            ports << info.portName();
        }
    }
    return ports;
}

/**
 * @brief ThreadWaitCOM::setNewPortList
 * Настраивает список сушществующих портов и возвращает один новый,
 * отсутствующий в списке существующих портов.
 * @param port_list Список новых портов. Может быть пустым.
 * @return Новый порт найден.
 */
bool ThreadWaitCOM::setNewPortList(QStringList port_list)
{
    if (port_list.size() < com_list.size()) {
        com_list = port_list;
        return false;
    }
    if (port_list.isEmpty()) {
        new_com.clear();
        com_list.clear();
        return false;
    }
    else {
        if (com_list.isEmpty()) {
            new_com  = port_list.at(0);
            com_list = port_list;
            return true;
        }
        else {
            return newPort_undefended_(port_list);
        }
    }
}
/**
 * @brief ThreadWaitCOM::newPort_undefended_
 * @param port_list Новый список COM портов.
 * @return Обнаружен новый COM порт.
 */
bool ThreadWaitCOM::newPort_undefended_(const QStringList& port_list)
{
    if (diffListCOMPorts(port_list).isEmpty()) {
        return false;
    }
    else {
        return true;
    }
}
/**
 * @brief ThreadWaitCOM::diff
 * Определяет новый COM порт и список COM портов
 * @param port_list Новый список COM портов
 * @return Список новых COM портов.
 */
QStringList ThreadWaitCOM::diffListCOMPorts(const QStringList& port_list)
{
    QStringList result;

    for (auto new_com_: port_list) {
        if (com_list.indexOf(new_com_) < 0) {
            result << new_com_;
        }
    }
    result.removeDuplicates();
    if (!result.isEmpty()) {
        new_com = result.at(0);
    }
    return result;
}
/**
 * @brief ThreadWaitCOM::emitNewCOM
 */
void ThreadWaitCOM::emitNewCOM()
{
    emit newCOM(new_com);
}
/**
 * @brief ThreadWaitCOM::breakWhileRun
 * @return Завершать или нет поиск COM порта
 */
bool ThreadWaitCOM::breakWhileRun()
{
    if (static_cast<bool>(port_is_true)) {
        qDebug() << "breakWhileRun";
        return true;
    }
    return false;
}

void ThreadWaitCOM::firstPreapare()
{
    com_list = readListCOMPorts();
}
