#include <QCoreApplication>
#include "convert_mac.h"

int main(int argc, char* argv[])
{
    //    QCoreApplication a(argc, argv);
    auto conv = new ConvertMAC;
    conv->examplePrepareMac();
    //    return a.exec();
}