#include <QList>
#include "setuart.h"

SetUART::SetUART() {}

QList<int> SetUART::listTiming()
{
    QList<int> is;
    is << IS1 << IS2 << IS3 << IS4 << IS5 << IS6 << IS7 << IS8 << IS9 << IS10
       << IS11 << IS12 << IS13 << IS14 << IS15 << IS16 << IS17 << IS18 << IS19
       << IS20 << IS21 << IS22 << IS23 << IS24 << IS25 << IS26 << IS27 << IS28
       << IS29;
    return is;
}
