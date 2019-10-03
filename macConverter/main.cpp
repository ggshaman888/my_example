#include <QCoreApplication>
#include "convert_mac.h"
#include "prepare_mac.h"

int main(int argc, char* argv[])
{
    //    QCoreApplication a(argc, argv);
    auto conv = new ConvertMAC;
    conv->examplePrepareMac();

    auto prepare = new PrepareMac;
    prepare->getMacRange("00:00:00:00:00:00", "00:00:00:00:00:02");
    //    return a.exec();
}
