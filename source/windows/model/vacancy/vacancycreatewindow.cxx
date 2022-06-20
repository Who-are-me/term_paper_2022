#include "vacancycreatewindow.hxx"
#include "ui_vacancycreatewindow.h"

VacancyCreateWindow::VacancyCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyCreateWindow)
{
    ui->setupUi(this);
}

VacancyCreateWindow::~VacancyCreateWindow()
{
    delete ui;
}
