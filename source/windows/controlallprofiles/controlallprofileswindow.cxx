#include "controlallprofileswindow.hxx"
#include "ui_controlallprofileswindow.h"

ControlAllProfilesWindow::ControlAllProfilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlAllProfilesWindow)
{
    ui->setupUi(this);
}

ControlAllProfilesWindow::~ControlAllProfilesWindow()
{
    delete ui;
}
