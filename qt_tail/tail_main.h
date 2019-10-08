#ifndef TAILMAIN_H
#define TAILMAIN_H

#include <QObject>
#include <atomic>

using namespace std;

class TailMain : public QObject
{
    Q_OBJECT
public:
    explicit TailMain(QObject *parent = nullptr);
    ~TailMain();
    void setListen(QString);
    void listenNew();
    void run();

signals:
    void newString(QString);

public slots:
    void isStop();

private:
    atomic_bool reading;
    QString path;
    int count; ///< Line number read from file.
    void readLine();

};

#endif // TAILMAIN_H
