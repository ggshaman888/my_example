#ifndef QSLSETERP_H
#define QSLSETERP_H

#include <QObject>
#include <QSqlDatabase>

class SQLSetERP : public QObject {
    Q_OBJECT
public:
    explicit SQLSetERP(QObject* parent = nullptr);

    void setDB(QSqlDatabase);

    bool createTableLink();
    bool createTableUserFL();
    bool createTableUserAccess();
    bool insertMacRange(QString, QString);

signals:
    void lastError(QString);
    void lastQuery(QString);

public slots:

private:
    void runSignalReqest();
    QSqlDatabase* db;
    QString last_error;
    QString last_query;
};

#endif // QSLSETERP_H
