#include <QCoreApplication>
#include "read_example.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    auto read = new ReadExample;

    return a.exec();
}
