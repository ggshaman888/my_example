#ifndef MIDLE_H
#define MIDLE_H

#include <QObject>
#include "api_from_ux.h"
#include "first.h"
#include "second.h"
class Middle : public QObject
{
    Q_OBJECT
public:
    explicit Middle(QObject *parent = nullptr);

    void runIs();
    signals:
        void info(APIFromUX);
    public slots:
        void infoSlot(APIFromUX);

    private:
        First* first_is;
        Second* second_is;
};

#endif // MIDLE_H
