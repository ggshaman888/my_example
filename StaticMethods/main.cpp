#include <QCoreApplication>
#include <QDebug>
#include "class1.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << Class1::z.z2;
    return a.exec();
}
