#include "educationdeletewindow.hxx"
#include "ui_educationdeletewindow.h"

EducationDeleteWindow::EducationDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationDeleteWindow)
{
    ui->setupUi(this);
}

EducationDeleteWindow::~EducationDeleteWindow()
{
    delete ui;
}
