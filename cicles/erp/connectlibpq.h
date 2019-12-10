#ifndef CONNECTLIBPQ_H
#define CONNECTLIBPQ_H
#if (defined (LINUX) || defined (__linux__))
#include </usr/include/postgresql/libpq-fe.h>
#elif (defined (_WIN32) || defined (_WIN64))
#include "libpq-fe.h"
#else
#endif

class connectLibPQ
{
public:
    connectLibPQ();

private:
    static void clearRes();
    static void terminate();
    static PGconn* conn;
    static PGresult* res;
};

#endif // CONNECTLIBPQ_H
