#include "vacancycreatewindow.hxx"
#include "ui_vacancycreatewindow.h"


VacancyCreateWindow::VacancyCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyCreateWindow)
{
    ui->setupUi(this);

    ui->cb_education->addItem("None", 0);
    ui->cb_education->addItem("Basic", 1);
    ui->cb_education->addItem("Junion specialist", 2);
    ui->cb_education->addItem("Higher education", 3);
    ui->cb_education->addItem("Several higher education", 4);
    ui->cb_education->addItem("Candidate of sciences", 5);
    ui->cb_education->addItem("Stydying", 6);
}


VacancyCreateWindow::~VacancyCreateWindow() {
    delete ui;
}
