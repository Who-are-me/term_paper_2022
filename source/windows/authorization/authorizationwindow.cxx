#include "authorizationwindow.hxx"
#include "ui_authorizationwindow.h"


AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);
}


AuthorizationWindow::~AuthorizationWindow() {
    delete ui;
}


QString AuthorizationWindow::getLogin() {
    return ui->le_login->text();
}


QString AuthorizationWindow::getPassword() {
    return ui->le_password->text();
}


void AuthorizationWindow::on_btn_login_released() {
    // TODO make authorization
    emit pushLogin();
}


void AuthorizationWindow::on_btn_register_released() {
    // TODO make registration
    emit showRegister();
}


void AuthorizationWindow::on_btn_back_released() {
    // TODO make me
    emit backScreen();
}
