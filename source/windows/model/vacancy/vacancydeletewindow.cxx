#include "vacancydeletewindow.hxx"
#include "ui_vacancydeletewindow.h"

VacancyDeleteWindow::VacancyDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyDeleteWindow)
{
    ui->setupUi(this);
}

VacancyDeleteWindow::~VacancyDeleteWindow()
{
    delete ui;
}
