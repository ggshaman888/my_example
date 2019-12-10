#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include "connectdb.h"

#define HOST_NAME "172.22.1.24"
#define DATABASE "PostgreSQL35W" //#define DATABASE "flasher_db"
#define PASSWORD "5Q8DnlXZpcvp"
#define USERNAME "flasher_user"

ConnectDB::ConnectDB(QObject* parent) : QObject(parent)
{
    // настроить ODBC в Администраторе источников данных ODBC
    // в поле setDatabaseName вписать имя Источника данных (Data source)

    setHostName(HOST_NAME);
    setDBName(DATABASE);
    setPassword(PASSWORD);
    setUserName(USERNAME);
    //    setHostName("172.22.1.24");
    //    setDBName("flasher_db");
    //    setPassword("5Q8DnlXZpcvp");
    //    setUserName("flasher_user");
}

void ConnectDB::openDB()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(db_name);
    db.setHostName(host_name);
    db.setUserName(user_name);
    db.setPassword(password);
    if (!db.open()) {
        qDebug() << "Not Connected";
    }
    else {
        qDebug() << "Connected";
    }
    // прочие реализации подключения к postgresql

    //    db = QSqlDatabase::addDatabase("QPSQL");
    //    db.setHostName(host_name);
    //    db.setDatabaseName(db_name);
    //    db.setPassword(password);
    //    db.setUserName(user_name);
    //    if(db.open()) {
    //        qDebug() <<"opened" ;
    //    }
    //    else {
    //        qDebug() << db.lastError().text();
    //    }
}

void ConnectDB::closeDB()
{
    db.close();
}

void ConnectDB::setHostName(QString is_host)
{
    host_name = is_host;
}

void ConnectDB::setDBName(QString is_db_name)
{
    db_name = is_db_name;
}

void ConnectDB::setPassword(QString is_password)
{
    password = is_password;
}

void ConnectDB::setUserName(QString is_user_name)
{
    user_name = is_user_name;
}

void ConnectDB::toBase(QString str)
{
    QSqlQuery query;
    query.exec(str);
}

QSqlDatabase ConnectDB::isDB()
{
    return db;
}
