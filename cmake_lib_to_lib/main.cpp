#include <QtWidgets/QApplication>
#include "sub/file1.h"
#include "sub/file2.h"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    // this cmake auto-linked lib1 and lib2
    auto f1 = new MyClass1;
    auto my = new MyClass2;
    my->func();

    return a.exec();
}
