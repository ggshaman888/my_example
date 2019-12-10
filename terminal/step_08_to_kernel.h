#ifndef STEP08TOKERNEL_H
#define STEP08TOKERNEL_H

#include <QObject>
#include <QThread>

/**
 * @brief The Step08ToKernel class Прошивание через USB-UART с заранее известным
 * COM портом.
 */
class Step08ToKernel : public QObject {
    Q_OBJECT
public:
    explicit Step08ToKernel(QObject* parent = nullptr);
    void isRun();

signals:

public slots:

private:
    QThread* th;
};

#endif // STEP08TOKERNEL_H
