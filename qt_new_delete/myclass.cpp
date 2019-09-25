#include <QDebug>
#include "myclass.h"

MyClass::MyClass(QObject* parent) : QObject(parent)
{
    close_class = false;
}

void MyClass::runIs()
{
    static int x = 0;
    if (close_class) {
        x = 0;
    }
    else {
        qDebug() << ++x;
    }
}

MyClass::~MyClass()
{
    closeClass();
}

void MyClass::closeClass()
{
    close_class = true;
    runIs();
}
