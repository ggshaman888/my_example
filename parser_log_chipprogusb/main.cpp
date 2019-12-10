#include "infowindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InfoWindow w;
    w.show();
    return a.exec();
}
