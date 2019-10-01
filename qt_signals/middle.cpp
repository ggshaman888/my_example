#include "QDebug"
#include "QThread"
#include "middle.h"
#include "api_from_ux.h"
#include "first.h"
#include "second.h"

#include "ux/wait_for_the_end.h"

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
    //form->show();
    qDebug() << "__middle";
    int count = 2;
    while (count > 0) {
        qDebug() << count << "|||> new cicle <|||";
        first_is->runIs();
        count--;
    }

    qDebug() << "__middle_this to this_ executed first...";
    QThread::sleep(4);
    connect(this, &Middle::info, this, &Middle::infoSlot, Qt::DirectConnection);
    auto is  = new APIFromUX;
    is->mark = APIFromUX::MarkerIs::THIS;
    emit info(*is);
    qDebug() << "__middle_this to this_ end work.";
}

void Middle::infoSlot(APIFromUX is_api)
{
    qDebug() << is_api.mark << "__marker__";
}
