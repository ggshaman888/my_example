#include <QDebug>
#include "calculate_for_list.h"

CalculateForList::CalculateForList(QObject* parent) : QObject(parent) {}

void CalculateForList::setListTiming(QList<int> list)
{
    list_timing = list;
    setMassProcessOfTime();
}

int CalculateForList::percentForStep(int step)
{
    if (step < 0) {
        return 0;
    }
    for (int i = step - 1; i > -1; i--) {
        if (step == i + 1) {
            percent = static_cast<int>(step * mas_process_of_time[i]);
        }
        else {
            percent += static_cast<int>(mas_process_of_time[i] * 100);
        }
    }
    static int x;
    if (x != percent) {
        x = percent;
        qDebug() << percent << "percent" << step;
    }
    return percent;
}

void CalculateForList::setMassProcessOfTime()
{
    mas_process_of_time = new double[list_timing.size()];
    for (int i = 0; i < list_timing.size(); i++) {
        mas_process_of_time[i] = list_timing.at(i);
        wt += list_timing.at(i);
    }
    wt /= 100; ///< The weight is determined by one total percentage.
    //! The determination of weight for each stage of the firmware.
    for (auto i = 0; i < list_timing.size(); i++) {
        mas_process_of_time[i] /= wt;
        mas_process_of_time[i] /= 100;
    }
}
