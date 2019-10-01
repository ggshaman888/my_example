#include "QDebug"
#include "QThread"
#include "middle.h"
#include "api_from_ux.h"
#include "first.h"
#include "second.h"

#include "ux/05_wait_for_the_end.h"

Middle::Middle(QObject* parent) : QObject(parent) {}

void Middle::runIs()
{
    first_is  = new First;
    second_is = new Second;
    auto th   = new QThread;
    first_is->moveToThread(th);
    connect(first_is, &First::info, this, &Middle::infoSlot, Qt::QueuedConnection);
    connect(first_is, &First::info, second_is, &Second::infoSlot, Qt::QueuedConnection);
    connect(second_is, &Second::info, this, &Middle::infoSlot, Qt::DirectConnection);
    connect(first_is, &First::info, this, &Middle::info, Qt::QueuedConnection);
    connect(second_is, &Second::info, this, &Middle::info, Qt::DirectConnection);
    connect(th, &QThread::started, first_is, &First::runIs, Qt::QueuedConnection);
    th->start();

    auto form = new WaitForTheEnd;
    connect(this, &Middle::info, form, &WaitForTheEnd::slotAPI, Qt::DirectConnection);
    form->show();
    qDebug() << "__middle";
    int count = 3;
    while (count > 0) {
        first_is->runIs();
        count--;
    }
}

void Middle::infoSlot(APIFromUX is_api)
{
    qDebug() << is_api.mark << "__marker__";
}
