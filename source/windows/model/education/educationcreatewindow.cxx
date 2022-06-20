#include "educationcreatewindow.hxx"
#include "ui_educationcreatewindow.h"

EducationCreateWindow::EducationCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationCreateWindow)
{
    ui->setupUi(this);
}

EducationCreateWindow::~EducationCreateWindow()
{
    delete ui;
}
