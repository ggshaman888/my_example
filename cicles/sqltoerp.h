#ifndef SQLTOERP_H
#define SQLTOERP_H

#include <QObject>
#include <QSqlDatabase>

class SQLToERP : public QObject {
    Q_OBJECT
public:
    explicit SQLToERP(QObject* parent = nullptr);

    void setDB(QSqlDatabase);
    bool addUser(QString, QString);
    bool addMacAddress(QString);

    bool linkToMac(int);
    bool linkToMacEnd(int);
    bool findLinkOpened(int);
    QString findMAC(int);

    bool openAuthorization(int);
    bool closeAuthorization(int);
    bool isSelectMac(QString);

signals:
    void lastError(QString);
    void lastQuery(QString);

public slots:

private:
    void runSignalReqest();
    QSqlDatabase db;
    QString last_error;
    QString last_query;
};

#endif // SQLTOERP_H
