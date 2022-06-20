#include "resumereadwindow.hxx"
#include "ui_resumereadwindow.h"

ResumeReadWindow::ResumeReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeReadWindow)
{
    ui->setupUi(this);
}

ResumeReadWindow::~ResumeReadWindow()
{
    delete ui;
}
