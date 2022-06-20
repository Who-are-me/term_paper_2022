#include "resumecreatewindow.hxx"
#include "ui_resumecreatewindow.h"

ResumeCreateWindow::ResumeCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeCreateWindow)
{
    ui->setupUi(this);
}

ResumeCreateWindow::~ResumeCreateWindow()
{
    delete ui;
}
