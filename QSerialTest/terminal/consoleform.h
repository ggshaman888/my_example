#ifndef CONSOLEFORM_H
#define CONSOLEFORM_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class ConsoleForm : public QObject {
	Q_OBJECT

public:
	explicit ConsoleForm(QObject* parent = nullptr);
	void isRun();

	void testCOM(QString);

public slots:
        void readTest();

private:
	QSerialPort* m_serial_b;
};

#endif // CONSOLEFORM_H
