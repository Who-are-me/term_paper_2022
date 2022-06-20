#include "resumeupdatewindow.hxx"
#include "ui_resumeupdatewindow.h"

ResumeUpdateWindow::ResumeUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeUpdateWindow)
{
    ui->setupUi(this);
}

ResumeUpdateWindow::~ResumeUpdateWindow()
{
    delete ui;
}
