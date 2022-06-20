#include "resumedeletewindow.hxx"
#include "ui_resumedeletewindow.h"

ResumeDeleteWindow::ResumeDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeDeleteWindow)
{
    ui->setupUi(this);
}

ResumeDeleteWindow::~ResumeDeleteWindow()
{
    delete ui;
}
