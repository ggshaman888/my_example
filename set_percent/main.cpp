#include <QCoreApplication>
#include "example/example_uart.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    ExampleUART uart;
    uart.isRun();
    return a.exec();
}
