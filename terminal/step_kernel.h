#ifndef STEP_KERNEL_H
#define STEP_KERNEL_H

#include <QObject>
#include <atomic>
#include "step_08_to_kernel.h"


using namespace std;
class StepKernel : public QObject {
    Q_OBJECT
public:
    explicit StepKernel(QObject* parent = nullptr);
    ~StepKernel();
    bool step_08();

private:
    Step08ToKernel is_step_08;
};

#endif // STEP_KERNEL_H
