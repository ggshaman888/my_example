#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QThread>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>
#include <QSerialPortInfo>
#include <QVariant>
#include <QSerialPort>
#include <QScrollBar>
#include <QTime>
#include "consoleform.h"
#include "setbaikal.h"
#include "runprepare.h"
#include "settings/threadwaitcom.h"
/**
 * @brief ConsoleForm::ConsoleForm
 * Обработка устройства через COM порт. Поиск порта, конфигурирование, закрытие.
 * @param parent
 */
ConsoleForm::ConsoleForm(QObject* parent)
    : QObject(parent),
      m_serial(new QSerialPort(this))
{
    qDebug() << "construct form";
    setFirst();
}

ConsoleForm::~ConsoleForm()
{
    closeSerialPort(true);
}


void ConsoleForm::setFirst()
{
    connect(m_serial, &QSerialPort::errorOccurred, this, &ConsoleForm::handleError);
    connect(m_serial,
            &QSerialPort::readyRead,
            this,
            &ConsoleForm::readData,
            Qt::DirectConnection);
}

void ConsoleForm::closeSerialPort(bool is)
{
    if (is) {
        qDebug() << "close_serial 2";
        m_serial->close();
    }
}

void ConsoleForm::setSerialAndStart(QString is_com)
{
    openSerialPort(is_com);
}

void ConsoleForm::isRun()
{
    openSerialPort("COM3");
}

void ConsoleForm::openSerialPort(const QString& is)
{
    static QString buf_com = "com";
    if (!is.isEmpty() && buf_com != is) {
        buf_com = is;
        m_serial->close();
        m_serial->setPortName(is);
        m_serial->setBaudRate(static_cast<QSerialPort::BaudRate>(115200));
        m_serial->setDataBits(static_cast<QSerialPort::DataBits>(8));
        m_serial->setParity(QSerialPort::NoParity);
        m_serial->setStopBits(QSerialPort::OneStop);
        m_serial->setFlowControl(QSerialPort::NoFlowControl);

        if (m_serial->open(QIODevice::ReadWrite)) {
            qDebug() << is << "com_+_+_";
        }
        else {
            qDebug() << QString("error: don't open serial ")
                            .append(m_serial->errorString());
        }
    }
}

void ConsoleForm::readData()
{
    const QByteArray data = m_serial->readAll();
    qDebug() << data << "void ConsoleForm::readData()";
}
void ConsoleForm::writeData(const QByteArray& data)
{
    qDebug() << data << "hit";
    m_serial->write(data);
}
void ConsoleForm::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        //        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort(true);
    }
}
