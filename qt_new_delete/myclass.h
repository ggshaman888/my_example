#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject {
    Q_OBJECT
public:
    explicit MyClass(QObject* parent = nullptr);
    void runIs();
    ~MyClass();
    void closeClass();
signals:

public slots:
private:
    bool close_class;
};

#endif // MYCLASS_H
