#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class InfoWindow; }
QT_END_NAMESPACE

class InfoWindow : public QWidget
{
    Q_OBJECT

public:
    InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow();

private:
    Ui::InfoWindow *ui;
};
#endif // INFOWINDOW_H
