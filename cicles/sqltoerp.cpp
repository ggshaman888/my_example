#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDateTime>
#include <QSqlRecord>
#include "sqltoerp.h"

SQLToERP::SQLToERP(QObject* parent) : QObject(parent) {}

bool SQLToERP::addUser(QString is_login, QString is_password)
{
    QSqlQuery query(db);
    QString request = QString("INSERT INTO user_fl (login_fl , password_fl) "
                              "VALUES ('%1', '%2');")
                          .arg(is_login)
                          .arg(is_password);
    query.exec(request);

    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::openAuthorization(int is_id_user)
{
    QSqlQuery query(db);
    QString request = QString("BEGIN;"
                              "INSERT INTO user_access (user_fl_id, start_fl) "
                              "VALUES ('%1', '%2');"
                              "COMMIT;")
                          .arg(is_id_user)
                          .arg(QDateTime::currentDateTime().toString("yyyy-MM-"
                                                                     "dd "
                                                                     "hh:mm:"
                                                                     "ss"));
    query.exec(request);

    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::closeAuthorization(int is_id_user)
{
    QSqlQuery query(db);
    QString request = QString("BEGIN;"
                              "UPDATE user_access SET end_fl = '%2' "
                              "WHERE user_fl_id = %1 AND end_fl IS NULL;"
                              "COMMIT;")
                          .arg(is_id_user)
                          .arg(QDateTime::currentDateTime().toString("yyyy-MM-"
                                                                     "dd "
                                                                     "hh:mm:"
                                                                     "ss"));
    query.exec(request);

    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::addMacAddress(QString is_mac_address)
{
    qDebug() << "111|||";
    QSqlQuery query(db);
    qDebug() << "222|||";

    QString request = QString("INSERT INTO link (mac_fl) "
                              "VALUES ('%1');")
                          .arg(is_mac_address);
    query.exec(request);
    qDebug() << "333|||";

    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::linkToMac(int is_uid)
{
    if (is_uid == 0) {
        return false;
    }
    QSqlQuery query(db);
    QString request = QString("BEGIN;"
                              "UPDATE link SET uid_fl = '%1', start_fl = '%2' "
                              "WHERE id=("
                              "   SELECT id FROM link "
                              "   WHERE uid_fl IS NULL AND start_fl IS NULL "
                              "       ORDER BY mac_fl ASC LIMIT 1);"
                              "COMMIT;")
                          .arg(is_uid)
                          .arg(QDateTime::currentDateTime().toString("yyyy-MM-"
                                                                     "dd "
                                                                     "hh:mm:"
                                                                     "ss"));
    query.exec(request);

    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::linkToMacEnd(int is_uid)
{
    QSqlQuery query(db);
    QString request = QString("BEGIN;"
                              "UPDATE link SET end_fl = '%2' "
                              "WHERE id=( "
                              "   SELECT id FROM link "
                              "   WHERE uid_fl = '%1' AND end_fl IS NULL "
                              "   ORDER BY id LIMIT 1);"
                              "COMMIT;")
                          .arg(is_uid)
                          .arg(QDateTime::currentDateTime().toString("yyyy-MM-"
                                                                     "dd "
                                                                     "hh:mm:"
                                                                     "ss"));
    query.exec(request);


    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (findLinkOpened(is_uid)) {
        linkToMacEnd(is_uid);
    }

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::isSelectMac(QString is_mac)
{
    QSqlQuery query(db);
    QString request =
        QString("SELECT * FROM link WHERE mac_fl = '%1';").arg(is_mac);
    query.exec(request);

    QStringList results;
    while (query.next()) {
        qDebug() << "id" << query.record().value(0).toString() << "uid"
                 << query.record().value(1).toString();
    }


    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return false;
    }
    return true;
}

bool SQLToERP::findLinkOpened(int is_uid)
{
    QSqlQuery query(db);
    bool is_return  = true;
    QString request = QString("   SELECT end_fl FROM link"
                              "       WHERE uid_fl = %1;")
                          .arg(is_uid);
    query.exec(request);
    while (query.next()) {
        if (query.record().value(0).toString().isEmpty()) {
            is_return = false;
            break;
        }
    }

    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    if (!last_error.isEmpty()) {
        return is_return;
    }
    return is_return;
}

QString SQLToERP::findMAC(int is_uid)
{
    if (is_uid == 0) {
        return nullptr;
    }
    QString mac;
    QSqlQuery query(db);
    QString request = QString("   SELECT mac_fl, start_fl, end_fl FROM link"
                              "       WHERE uid_fl = %1;")
                          .arg(is_uid);
    query.exec(request);
    while (query.next()) {
        if (!query.record().value(1).toString().isEmpty() &&
            query.record().value(2).toString().isEmpty()) {
            mac = query.record().value(0).toString();
            break;
        }
    }
    qDebug() << mac << "_____________________";
    last_error = query.lastError().text();
    last_query = query.lastQuery();

    runSignalReqest();

    return mac;
}

void SQLToERP::runSignalReqest()
{
    if (!last_error.isEmpty()) {
        emit lastError(last_error);
    }
    if (!last_query.isEmpty()) {
        emit lastQuery(last_query);
    }
    qDebug() << last_error << last_query;
}

void SQLToERP::setDB(QSqlDatabase is_db)
{
    db = is_db;
}
