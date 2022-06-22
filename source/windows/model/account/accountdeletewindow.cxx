#include "accountdeletewindow.hxx"
#include "ui_accountdeletewindow.h"


AccountDeleteWindow::AccountDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountDeleteWindow)
{
    ui->setupUi(this);

    ui->l_text->setText("Ви дійсно хочете видалити акаунт?");
    ui->l_login->setText("12345678");
//    ui->l_login->setText("> LOGIN <");
}


AccountDeleteWindow::~AccountDeleteWindow() {
    delete ui;
}


void AccountDeleteWindow::setLogin(QString new_login) {
    this->login = new_login;
}


void AccountDeleteWindow::update() {
    ui->l_login->setText(this->login);
}


void AccountDeleteWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void AccountDeleteWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
