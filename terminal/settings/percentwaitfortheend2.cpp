#include <QThread>
#include <QDebug>
#include "percentwaitfortheend2.h"

#define MAX_TIME_SECOND 590

PercentWaitForTheEnd2::PercentWaitForTheEnd2(QThread* parrent)
    : QThread(parrent)
{
}
/**
 * @brief PercentWaitForTheEnd2::run
 * Генерация процентов для второго этапа прошивки. Предел до 100% в секундах до
 * MAX_TIME_SECOND..
 */
void PercentWaitForTheEnd2::run()
{
    for (int i = 0; i < MAX_TIME_SECOND; i++) {
        QThread::sleep(5);
        double p1 = 100;
        p1 /= MAX_TIME_SECOND;
        p1 *= i;
        int is_percent = static_cast<int>(p1);
        if (is_percent < 99) {
            emit percent(is_percent);
        }
    }
}
