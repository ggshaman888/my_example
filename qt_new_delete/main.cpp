#include <QCoreApplication>
#include "myclass.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    auto my = new MyClass;

    for (int i = 0; i < 3; i++) {
        delete my;
        my = new MyClass;
        my->runIs();
    }
    return a.exec();
}
