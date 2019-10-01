#include <QMessageBox>
#include <QDebug>
#include <QFuture>
#include <QtEvents>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QTextCursor>
#include <QLCDNumber>
#include <QThreadPool>
#include <QProcess>
#include <atomic>
#include "wait_for_the_end.h"
#include "ui_waitfortheend.h"


using namespace std;
/**
 * @brief WaitForTheEnd::WaitForTheEnd
 * Класс формы.
 * Шаг2. Ожидайте завершения операции.
 * Задача: Индикация процесса прошивания.
 * @param parent
 */
WaitForTheEnd::WaitForTheEnd(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::WaitForTheEnd)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Form");
}


WaitForTheEnd::~WaitForTheEnd()
{
    delete ui;
}

void WaitForTheEnd::slotAPI(APIFromUX is_api)
{
    qDebug() << "is api wait" << is_api.mark;
}
