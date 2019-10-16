#include <QDebug>
#include "calculate_for_list.h"

CalculateForList::CalculateForList(QObject* parent) : QObject(parent) {}

CalculateForList::~CalculateForList()
{
    qDebug() << "CalculateForList::~CalculateForList() running calculate is "
                "second"
             << countSecond();
}

void CalculateForList::setListTiming(QList<int> list)
{
    list_timing = list;
    setMassProcessOfTime();
}

int CalculateForList::percentTime(int is_step)
{
    auto now_c = countSecond();
    auto max_c = countInStep(is_step);
    auto min_c = countInStepMin(is_step);

    if (now_c <= max_c && now_c > min_c) {
        return calcPercentInCount(now_c);
    }
    else {
        return calcPercentInCount(min_c);
    }
}

void CalculateForList::startCalc()
{
    start = QTime::currentTime();
}

int CalculateForList::countSecond()
{
    return start.secsTo(QTime::currentTime());
}

int CalculateForList::countInStep(int is_step)
{
    int max_count = 0;
    for (int i = 0; i < list_timing.size(); i++) {
        max_count += list_timing.at(i);
        if (is_step == i) {
            break;
        }
    }
    return max_count;
}

int CalculateForList::calcPercentInCount(int count)
{
    return static_cast<int>(count / wt);
}

int CalculateForList::countInStepMin(int is_step)
{
    if (is_step - 1 < 0) {
        return 0;
    }
    int max_count = 0;
    for (int i = 0; i < list_timing.size(); i++) {
        max_count += list_timing.at(i);
        if (is_step - 1 == i) {
            break;
        }
    }
    return max_count;
}

void CalculateForList::setMassProcessOfTime()
{
    mas_process_of_time = new double[list_timing.size()];
    for (int i = 0; i < list_timing.size(); i++) {
        mas_process_of_time[i] = list_timing.at(i);
        wt += list_timing.at(i);
    }
    max_count = static_cast<int>(wt);
    wt /= 100; ///< The weight is determined by one total percentage.
    //! The determination of weight for each stage of the firmware.
    for (auto i = 0; i < list_timing.size(); i++) {
        mas_process_of_time[i] /= wt;
        mas_process_of_time[i] /= 100;
    }
}
