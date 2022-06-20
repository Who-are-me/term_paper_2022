#include "vacancyupdatewindow.hxx"
#include "ui_vacancyupdatewindow.h"

VacancyUpdateWindow::VacancyUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyUpdateWindow)
{
    ui->setupUi(this);
}

VacancyUpdateWindow::~VacancyUpdateWindow()
{
    delete ui;
}
