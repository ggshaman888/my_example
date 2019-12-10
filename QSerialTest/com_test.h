#ifndef COMTEST_H
#define COMTEST_H

#include <QObject>

class COMTest : public QObject
{
	Q_OBJECT
public:
	explicit COMTest(QObject *parent = nullptr);

signals:

public slots:
};

#endif // COMTEST_H
