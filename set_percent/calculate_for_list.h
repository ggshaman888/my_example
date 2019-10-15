#ifndef CALCULATEFORLIST_H
#define CALCULATEFORLIST_H

#include <QObject>

class CalculateForList : public QObject
{
    Q_OBJECT
public:
    explicit CalculateForList(QObject *parent = nullptr);

    /**
     * @brief setListTiming Settings list a timings for step.
     */
    void setListTiming(QList<int>);
    int percentForStep(int);

signals:

public slots:

private:
    QList<int> list_timing;
    int percent = 0;
    //! массив с весами на 1 общий процент для каждого этапа прошивки.
    double *mas_process_of_time;
    //! list_timing to mas_process_of_time and preparing.
    void setMassProcessOfTime();
    double wt = 0; ///< The weight is determined by one total percentage.
};

#endif // CALCULATEFORLIST_H
