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
#include "05_wait_for_the_end.h"
#include "ui_waitfortheend.h"
#include "set_ux/set_interface/set_progress_bar_wait_for_the_end.h"
#include "set_ux/set_interface/setwaitfortheend.h"
#include "set_ux/guiparametrs.h"
#include "settings/global_settings.h"
#include "api_from_ux.h"

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
    setWidgets();
    QWidget::setWindowTitle("Автоматизация прошивания");
    ui->lineEdit->hide();
    ui->lcdNumber->hide();
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    ui->radioButton_3->hide();
}


WaitForTheEnd::~WaitForTheEnd()
{
    delete ui;
}
/**
 * @brief WaitForTheEnd::restart
 * Запуск процесса прошивки и настройка формы.
 */
void WaitForTheEnd::restart(bool is)
{
    if (is) {
        restart_();
    }
}
void WaitForTheEnd::restart_()
{
    auto settings = SETTINGS_USER;
    if (settings->value("admin_version").toString() == "release") {
        ui->next_button->installEventFilter(this);
        this->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->showFullScreen();
    }
    else {
        move(0, 0);
        this->show();
    }
    //    pr_ch_pr->start();
    //    //ui->next_button->setEnabled(true);
    //    ui->lcdNumber->setDecMode();
    //    wt->setStartLCDNumberWaitReduction(100);
    //    wt->start();

    percent_time = new SetProgressBarWaitForTheEnd;
    connect(percent_time,
            &SetProgressBarWaitForTheEnd::percent,
            this,
            &WaitForTheEnd::infoPercent);
    percent_time->start();
}

void WaitForTheEnd::setRequestFromKernel(APIFromUX is_api)
{
    qDebug() << is_api.mark << "Marker"
             << "void WaitForTheEnd::setRequestFromKernel(APIFromUX is_api)";
}

void WaitForTheEnd::slotString(QString str)
{
    qDebug() << "is string" << str;
}

void WaitForTheEnd::on_next_button_clicked()
{
    // back is form_add_firmware
    // next to form_shutdown_the_programmer
    emit nextButton();
    emit next(true);
    this->hide();
}

void WaitForTheEnd::setFinishedSucsess()
{
    emit setQPushButtonEnable(true);
    static int x = 0;
    if (x == 0) {
        QProcess::execute("taskkill /im UprogNT2.exe /f");
    }
    x++;
    ui->status_process->setText("Все операции успешно завершенны");
    emit _insertPlainText("Все операции успешно завершенны\n\n\n\n\n");
    setError("Все операции успешно завершенны");
}

void WaitForTheEnd::setStatusFlasher(QString str)
{
    QString status = QString("Операция: %1").arg(str);
    ui->status_process->setText(status);
}

void WaitForTheEnd::setError(const QString& error)
{
    static QString is;
    if (is != error) {
        connect(this,
                &WaitForTheEnd::_insertPlainText,
                ui->infoText,
                &QPlainTextEdit::insertPlainText,
                Qt::QueuedConnection);
        connect(this,
                &WaitForTheEnd::_clearPlainText,
                ui->infoText,
                &QPlainTextEdit::clear,
                Qt::QueuedConnection);
        static QString buf_x;
        if (buf_x != error) {
            buf_x = error;
            buf_x.append("\n\n\n\n\n");
            emit _clearPlainText();
            emit _insertPlainText(buf_x);
        }
    }
}
/**
 * @brief WaitForTheEnd::infoPercent
 * Подача процентов в индикатор процентов в порядке увеличения.
 * @param value Берётся из разных источников, поэтому может быть меньше
 * предыдущего значения. Иногда значения теряются, например в OFControl не
 * поступают значения от UprogNT2.
 * @see void OFControl::outProgress(bool &run_progress, QString &out)
 * */
void WaitForTheEnd::infoPercent(int value)
{
    static int value_ = 0;
    if (value > value_) {
        value_ = value;
        if (value == 100) {
            setFinishedSucsess();
        }
        else {
            emit isPercentMain(value_);
        }
    }
    //    if (static_cast<bool>(global_user::chp_verify_end)) {
    //        isPercentMain(100);
    //        setError("");
    //        QProcess::execute("taskkill /im UprogNT2.exe /f");
    //        //qDebug() << "100%_____";
    //    }
}

bool WaitForTheEnd::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::WindowDeactivate) {
        this->activateWindow();
        return true;
    }
    else { // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

void WaitForTheEnd::on_stop_button_clicked()
{
    //    global_user::run_app = 0;
    QProcess::execute("taskkill /im UprogNT2.exe /t /f");
    QProcess::execute("taskkill /im OFControl.exe /t /f");
    //   emit restartProgram(true);
    ui->next_button->setEnabled(false);
    //    pr_ch_pr->wait();
    //    delete pr_ch_pr;
    //    pr_ch_pr->terminate();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

    ui->progressBar->setValue(0);
    this->hide();
}

void WaitForTheEnd::on_lock_button_clicked()
{
    if (ui->stop_button->isEnabled()) {
        ui->stop_button->setEnabled(false);
        ui->lock_button->setText("Заблокировать кнопку завершения");
    }
    else {
        ui->stop_button->setEnabled(true);
        ui->lock_button->setText("Разблокировать кнопку завершения");
    }
}

void WaitForTheEnd::infoWarning(const QString& warning)
{
    qDebug() << warning << "warning___";
    if (warning.indexOf("_erasing") > -1) {
        if (warning.indexOf("1") > -1) {
            ui->radioButton->setChecked(true);
        }
        if (warning.indexOf("2") > -1) {
            ui->radioButton_2->setChecked(true);
        }
        if (warning.indexOf("3") > -1) {
            ui->radioButton_3->setChecked(true);
            ui->lineEdit->setText("Возможно программа зависла...");
        }
    }
}

void WaitForTheEnd::setLCDNumber(int count)
{
    ui->lcdNumber->display(count);
}

void WaitForTheEnd::setWidgets()
{
    set_if = new SetWaitForTheEnd;
    QSettings settings;
    connect(this,
            &WaitForTheEnd::setQPushButtonEnable,
            ui->next_button,
            &QPushButton::setEnabled,
            Qt::QueuedConnection);
    //  emit setQPushButtonEnable(false);

    //    pr_ch_pr = new ProgramChipProg;
    //    connect(this,
    //            &WaitForTheEnd::isPercentMain,
    //            ui->progressBar,
    //            &QProgressBar::setValue,
    //            Qt::QueuedConnection);
    //    connect(pr_ch_pr,
    //            &ProgramChipProg::infoPercent,
    //            this,
    //            &WaitForTheEnd::infoPercent,
    //            Qt::QueuedConnection);
    //    connect(pr_ch_pr,
    //            &ProgramChipProg::isStatusFlasher,
    //            this,
    //            &WaitForTheEnd::setStatusFlasher,
    //            Qt::DirectConnection);
    //    connect(pr_ch_pr,
    //            &ProgramChipProg::infoError,
    //            this,
    //            &WaitForTheEnd::setError,
    //            Qt::DirectConnection);
    //    connect(pr_ch_pr,
    //            &ProgramChipProg::infoWarning,
    //            this,
    //            &WaitForTheEnd::infoWarning,
    //            Qt::QueuedConnection);

    //    wt = new WhileTimer;
    //    connect(wt,
    //            &WhileTimer::isLCDNumber,
    //            this,
    //            &WaitForTheEnd::setLCDNumber,
    //            Qt::QueuedConnection);

    ui->verticalLayout->layout()->setMargin(GUI_user::layoutMargin.load());
    ui->verticalLayout->layout()->setSpacing(GUI_user::layoutMargin.load() + 15);


    QString is_style = set_if->setMainStyleSheet();
    ui->guide->setStyleSheet(is_style);
    ui->next_button->setStyleSheet(is_style);
    ui->lock_button->setStyleSheet(is_style);
    ui->textEdit->setStyleSheet(is_style);
    ui->status_process->setStyleSheet(is_style);
    ui->progressBar->setStyleSheet(set_if->setProgressbarStyleSheet());

    ui->stop_button->setStyleSheet(is_style);

    ui->step->setStyleSheet(set_if->setStepStyleSheet());

    ui->stop_button->setEnabled(false);
    ui->textEdit->setHidden(true);
}
