#include <QCoreApplication>
#include "xmodem.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    XMODEM x_is;
    x_is.runCalculate();

    return a.exec();
}
