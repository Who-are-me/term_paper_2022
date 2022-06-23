#include "resumedeletewindow.hxx"
#include "ui_resumedeletewindow.h"


ResumeDeleteWindow::ResumeDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeDeleteWindow)
{
    ui->setupUi(this);

    ui->l_text->setText("Ви дійсно хочете видалити вакансію?");
    ui->l_login->setText("Робота вoдія");
}


ResumeDeleteWindow::~ResumeDeleteWindow() {
    delete ui;
}


void ResumeDeleteWindow::setResumeId(int new_id) {
    id = new_id;
}


void ResumeDeleteWindow::update() {
    ui->l_login->setText(QString::number(this->id));
}


void ResumeDeleteWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void ResumeDeleteWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
