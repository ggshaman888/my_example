#ifndef CLASS1_H
#define CLASS1_H

#include <QDebug>

class Class1
{
public:
    Class1() = delete ;
    const static int x = 1;
    static struct ZZ {
        const static int z1 = 1;
        const static QString z2 = "word";
    } z;
};

#endif // CLASS1_H
