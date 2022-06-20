#include "vacancydeletewindow.hxx"
#include "ui_vacancydeletewindow.h"


VacancyDeleteWindow::VacancyDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyDeleteWindow)
{
    ui->setupUi(this);

    ui->l_text->setText("Ви дійсно хочете видалити вакансію?");
    ui->l_login->setText("Робота вoдія");
}


VacancyDeleteWindow::~VacancyDeleteWindow() {
    delete ui;
}
