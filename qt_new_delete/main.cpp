#include <QCoreApplication>
#include "myclass.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    MyClass* my;

    for (int i = 0; i < 3; i++) {
        my = new MyClass;
        my->runIs();
        delete my;
    }
    return a.exec();
}
