#ifndef WAITFORTHEEND_H
#define WAITFORTHEEND_H

#include <QWidget>
#include <QSettings>
#include <QMutex>
#include <QTextCursor>
#include "api_from_ux.h"

namespace Ui {
class WaitForTheEnd;
}

class WaitForTheEnd : public QWidget {
    Q_OBJECT

public:
    explicit WaitForTheEnd(QWidget* parent = nullptr);
    ~WaitForTheEnd();
signals:

public slots:
    void slotAPI(APIFromUX);

private:
    Ui::WaitForTheEnd* ui;
};

#endif // WAITFORTHEEND_H
