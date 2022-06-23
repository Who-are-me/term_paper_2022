#include "educationdeletewindow.hxx"
#include "ui_educationdeletewindow.h"


EducationDeleteWindow::EducationDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationDeleteWindow)
{
    ui->setupUi(this);

    ui->l_text->setText("Ви дійсно хочете видалити вакансію?");
    ui->l_login->setText("Робота вoдія");
}


EducationDeleteWindow::~EducationDeleteWindow() {
    delete ui;
}


void EducationDeleteWindow::setEducationId(int new_id) {
    id = new_id;
}


void EducationDeleteWindow::update() {
    ui->l_login->setText(QString::number(this->id));
}


void EducationDeleteWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void EducationDeleteWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
