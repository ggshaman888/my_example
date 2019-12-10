#ifndef THREADWAITCOM_H
#define THREADWAITCOM_H

#include <QObject>
#include <QThread>
#include <atomic>

using namespace std;

/**
 * @brief The ThreadWaitCOM class Поиск нового COM порта.
 */
class ThreadWaitCOM : public QThread {
    Q_OBJECT
public:
    explicit ThreadWaitCOM(QThread* = nullptr);
    ~ThreadWaitCOM();
    void run();

signals:
    void newCOM(QString);

public slots:
    void infoNewCOM(bool);
    void stopListened(bool);

private:
    QStringList readListCOMPorts();
    QStringList com_list;
    QString setNewPort(QStringList);


    QString new_com = nullptr;
    atomic_bool port_is_true;

    bool setNewPortList(QStringList);
    bool newPort_undefended_(const QStringList&);

    QStringList diffListCOMPorts(const QStringList&);

    void emitNewCOM();
    bool breakWhileRun();
    /**
     * @brief firstPreapare Первичная обработка.
     */
    void firstPreapare();
};

#endif // THREADWAITCOM_H
