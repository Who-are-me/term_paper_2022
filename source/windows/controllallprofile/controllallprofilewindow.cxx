#include "controllallprofilewindow.hxx"
#include "ui_controllallprofilewindow.h"

ControllAllProfileWindow::ControllAllProfileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControllAllProfileWindow)
{
    ui->setupUi(this);
}

ControllAllProfileWindow::~ControllAllProfileWindow()
{
    delete ui;
}
