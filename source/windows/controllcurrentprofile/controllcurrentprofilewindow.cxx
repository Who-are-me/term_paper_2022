#include "controllcurrentprofilewindow.hxx"
#include "ui_controllcurrentprofilewindow.h"

ControllCurrentProfileWindow::ControllCurrentProfileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControllCurrentProfileWindow)
{
    ui->setupUi(this);
}

ControllCurrentProfileWindow::~ControllCurrentProfileWindow()
{
    delete ui;
}
