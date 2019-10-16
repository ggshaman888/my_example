#ifndef CALCULATEFORLIST_H
#define CALCULATEFORLIST_H

#include <QObject>
#include <QTime>
class CalculateForList : public QObject {
    Q_OBJECT
public:
    explicit CalculateForList(QObject* parent = nullptr);
    ~CalculateForList();
    /**
     * @brief setListTiming Settings list a timings for step.
     */
    void setListTiming(QList<int>);
    /**
     * @brief percentTime Calculated percent from timer in limits a current step.
     * @return Проценты.
     */
    int percentTime(int);
    void startCalc();
signals:

public slots:

private:
    QTime start;
    QList<int> list_timing;
    int max_count = 0; ///< Max count tacts in 100%.
    double wt     = 0; ///< The weight is determined by one total percentage.
    int countSecond();
    int countInStep(int);
    int countInStepMin(int);
    int calcPercentInCount(int);
    void setMassProcessOfTime();
    double* mas_process_of_time;
};

#endif // CALCULATEFORLIST_H
