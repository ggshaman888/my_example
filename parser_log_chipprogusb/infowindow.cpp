#include "infowindow.h"
#include "./ui_infowindow.h"

InfoWindow::InfoWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}

