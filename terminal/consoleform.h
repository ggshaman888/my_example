#ifndef CONSOLEFORM_H
#define CONSOLEFORM_H
#include <QtSerialPort/QSerialPort>
//#include <QSerialPort>
#include <QByteArray>
#include <QTime>
#include <atomic>
#include "setbaikal.h"
#include "settings/threadwaitcom.h"

using namespace std;

namespace Ui {
class consoleForm;
}

/**
 * @brief The ConsoleForm class Управление прошиванием через COM порт.
 * Поиcк нужного COM порта и запуск операций с COM портом.
 */
class ConsoleForm : public QObject {
    Q_OBJECT

public:
    explicit ConsoleForm(QObject* parent = nullptr);
    ~ConsoleForm();
    QByteArray bufRequestDevice(const QByteArray& data_, int size = 1000);
    void setSerialAndStart(QString);
    void isRun();

public slots:
    void closeSerialPort(bool);

private slots:
    void openSerialPort(const QString&);
    void readData();
    void writeData(const QByteArray& data);
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort* m_serial = nullptr;
    void setFirst();
    ThreadWaitCOM* w_com;
};

#endif // CONSOLEFORM_H
