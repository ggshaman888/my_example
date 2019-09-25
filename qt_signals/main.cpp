#include <QApplication>
#include "middle.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    auto mid = new Middle;
    mid->runIs();
    return a.exec();
}
