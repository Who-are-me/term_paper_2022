#include "vacancyreadwindow.hxx"
#include "ui_vacancyreadwindow.h"

VacancyReadWindow::VacancyReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyReadWindow)
{
    ui->setupUi(this);
}

VacancyReadWindow::~VacancyReadWindow()
{
    delete ui;
}
