#ifndef WAITFORTHEEND_H
#define WAITFORTHEEND_H

#include <QWidget>
#include <QSettings>
#include <QMutex>
#include <QTextCursor>
#include "set_ux/set_interface/set_progress_bar_wait_for_the_end.h"
#include "set_ux/set_interface/setwaitfortheend.h"
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
    void next(bool);
    void nextButton();
    void isPercentMain(int);
    void setQPushButtonEnable(bool);
    void _insertPlainText(QString);
    void _clearPlainText();
    void runTimerDead();
    //   void _moveCursor(QTextCursor);
    void startTimerLCDNumber(int);
    void quitAppUser();
    void restartProgram(bool);

public slots:
    void restart(bool);
    void restart_();
    void setRequestFromKernel(APIFromUX);
    void slotString(QString);

private slots:
    void on_next_button_clicked();
    void setFinishedSucsess();
    void setStatusFlasher(QString);
    //   void setProgressMain(int);
    void setError(const QString&);
    void infoPercent(int);
    void on_stop_button_clicked();
    void on_lock_button_clicked();
    void infoWarning(const QString&);
    void setLCDNumber(int);

private:
    Ui::WaitForTheEnd* ui;
    void setWidgets();
    QSettings settings;
    SetProgressBarWaitForTheEnd* percent_time;
    SetWaitForTheEnd* set_if;

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
};

#endif // WAITFORTHEEND_H
