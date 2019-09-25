#include <QDebug>
#include "myclass.h"

MyClass::MyClass(QObject* parent) : QObject(parent) {}

void MyClass::runIs()
{
    static int x = 0;
    qDebug() << ++x;
}
