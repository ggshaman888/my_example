#include "generatefromtlv.h"

#include <QApplication>
#include <QByteArray>
#include <QDebug>
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    GenerateFromTLV w;
    w.show();

    return a.exec();
}
