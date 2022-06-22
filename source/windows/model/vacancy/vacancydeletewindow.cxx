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


void VacancyDeleteWindow::setVacancyId(int new_id) {
    this->id = new_id;
}


void VacancyDeleteWindow::update() {
    ui->l_login->setText(QString::number(this->id));
}


void VacancyDeleteWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void VacancyDeleteWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
