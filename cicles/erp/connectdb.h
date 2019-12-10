#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QObject>
#include <QSqlDatabase>

class ConnectDB : public QObject {
    Q_OBJECT
public:
    explicit ConnectDB(QObject* parent = nullptr);

    void openDB();
    void closeDB();

    void setHostName(QString);
    void setDBName(QString);
    void setPassword(QString);
    void setUserName(QString);

    QSqlDatabase isDB();
    void toBase(QString);

signals:

public slots:

private:
    QSqlDatabase db;
    QString host_name;
    QString db_name;
    QString password;
    QString user_name;
};

#endif // CONNECTDB_H
