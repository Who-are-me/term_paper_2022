#include "controlcurrentprofileswindow.hxx"
#include "ui_controlcurrentprofileswindow.h"

ControlCurrentProfilesWindow::ControlCurrentProfilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlCurrentProfilesWindow)
{
    ui->setupUi(this);
}

ControlCurrentProfilesWindow::~ControlCurrentProfilesWindow()
{
    delete ui;
}
