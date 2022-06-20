#include "educationupdatewindow.hxx"
#include "ui_educationupdatewindow.h"

EducationUpdateWindow::EducationUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationUpdateWindow)
{
    ui->setupUi(this);
}

EducationUpdateWindow::~EducationUpdateWindow()
{
    delete ui;
}
