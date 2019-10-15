#ifndef SETUART_H
#define SETUART_H

#define IS1	5
#define IS2	1
#define IS3	0
#define IS4	5
#define IS5	46
#define IS6	1
#define IS7	188
#define IS8	191
#define IS9	1
#define IS10	2
#define IS11	1
#define IS12	1
#define IS13	1
#define IS14	0
#define IS15	1
#define IS16	2
#define IS17	1
#define IS18	1
#define IS19	2
#define IS20	58
#define IS21	70
#define IS22	1
#define IS23	0
#define IS24	1
#define IS25	1
#define IS26	1
#define IS27	0
#define IS28	1
#define IS29	1
#define MAX_ELEMENTS 29

#include <QList>
class SetUART
{
public:
    SetUART();
    QList <int> listTiming();
};

#endif // SETUART_H
