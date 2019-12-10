#include "consoleform.h"

ConsoleForm::ConsoleForm(QObject* parent) : QObject(parent)
{
	qDebug() << "construct form ConsoleForm::ConsoleForm";
}


void ConsoleForm::isRun()
{
	testCOM("COM4");
}

void ConsoleForm::testCOM(QString is_com)
{
	m_serial_b = new QSerialPort;
	connect(m_serial_b, &QSerialPort::readyRead, this, &ConsoleForm::readTest);

	m_serial_b->setPortName(is_com);
	m_serial_b->setBaudRate(static_cast<QSerialPort::BaudRate>(115200));
	m_serial_b->setDataBits(static_cast<QSerialPort::DataBits>(8));
	m_serial_b->setParity(QSerialPort::NoParity);
	m_serial_b->setStopBits(QSerialPort::OneStop);
	m_serial_b->setFlowControl(QSerialPort::NoFlowControl);
	qDebug() << "ConsoleForm::openSerialPort _1_b";
	if (m_serial_b->open(QIODevice::ReadWrite)) {
		qDebug() << "com_+_+_" << m_serial_b->isReadable();
		m_serial_b->write("\n");
	}
}

void ConsoleForm::readTest()
{
	qDebug() << "test" << m_serial_b->readAll();
}
