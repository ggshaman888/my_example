#include "connectlibpq.h"
#if (defined (LINUX) || defined (__linux__))
#include </usr/include/postgresql/libpq-fe.h>
#elif (defined (_WIN32) || defined (_WIN64))
#else
#endif
//#include "lib"

#include <QDebug>

connectLibPQ::connectLibPQ()
{
//    setHostName("172.22.1.24");
//    setDBName("flasher_db");
//    setPassword("5Q8DnlXZpcvp");
//    setUserName("flasher_user");

    //PGconn pgconn__;
//    conn = PQconnectdb("user=flasher_user password=5Q8DnlXZpcvp host=172.22.1.24 dbname=flasher_db");
//    conn = NULL;
//    res = NULL;
    const char *conninfo;
     PGconn     *conn;
     PGresult   *res;
     int nFields, i, j;


     conninfo = "hostaddr=172.22.1.24 dbname=flasher_db user=flasher_user password=5Q8DnlXZpcvp";

     conn = PQconnectdb(conninfo);
     if (PQstatus(conn) != CONNECTION_OK)
     {
         fprintf(stderr, "Connection to database failed: %s",
                 PQerrorMessage(conn));
//         exit_nicely(conn);
         qDebug() << "10____";
     }
     qDebug() << "010____";

  //  conn = PQconnectdb("dbname=ljdata host=localhost user=dataman");
//    conn = PQsetdbLogin("172.22.1.24",
//                         NULL,
//                         NULL,
//                         NULL,
//                         "flasher_db",
//                         "flasher_user",
//                         "5Q8DnlXZpcvp");
    if(PQstatus(conn) != CONNECTION_OK) {
        qDebug() << "connection false";
    }
    else {
        qDebug() << "connection true";
    }

    res = PQexec(conn, "SELECT id FROM link;");
    if(PQresultStatus(res) != PGRES_TUPLES_OK) {
        qDebug() << "connection false";
    }

    int ncols = PQnfields(res);
    qDebug() << ncols;
//    printf("There are %d columns:", ncols);
    for(int i = 0; i < ncols; i++)
    {
        char *name = PQfname(res, i);
        printf(" %s", name);
    }
    printf("\n");

    int nrows = PQntuples(res);
    for(int i = 0; i < nrows; i++)
    {
//        char* id = PQgetvalue(res, i, 0);
        qDebug() << PQgetvalue(res, i, 0);
//        char* name = PQgetvalue(res, i, 1);
//        char* phone = PQgetvalue(res, i, 2);
//        char* last_changed = PQgetvalue(res, i, 3);
//        printf("Id: %s, Name: %s, Phone: %s, Last changed: %s\n",
//            id);//, name, phone, last_changed);
    }

   // printf("Total: %d rows\n", nrows);

    clearRes();
   // terminate(0);
}

void connectLibPQ::clearRes()
{
    // PQclear(res);
   // res = NULL;
}

void connectLibPQ::terminate()
{
    //  if(code != 0)
       //   fprintf(stderr, "%s\n", PQerrorMessage(conn));

  //    if(res != NULL)
  //        PQclear(res);

  //    if(conn != NULL)
  //        PQfinish(conn);

     // exit(code);
}
