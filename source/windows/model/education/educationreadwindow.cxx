#include "educationreadwindow.hxx"
#include "ui_educationreadwindow.h"

EducationReadWindow::EducationReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationReadWindow)
{
    ui->setupUi(this);
}

EducationReadWindow::~EducationReadWindow()
{
    delete ui;
}
