#include "registerwindow.hxx"
#include "ui_registerwindow.h"


RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}


RegisterWindow::~RegisterWindow() {
    delete ui;
}


QString RegisterWindow::getPip() {
    return ui->le_pip->text();
}


QString RegisterWindow::getCity() {
    return ui->le_city->text();
}


QString RegisterWindow::getLocation() {
    return ui->le_location->text();
}


QString RegisterWindow::getPhone() {
    return ui->le_phone->text();
}


QString RegisterWindow::getEmail() {
    return ui->le_email->text();
}


QString RegisterWindow::getCompany() {
    return ui->le_company->text();
}


QString RegisterWindow::getDescription() {
    return ui->le_description->text();
}


QString RegisterWindow::getLogin() {
    return ui->le_login->text();
}


QString RegisterWindow::getPassword() {
    return ui->le_password->text();
}


void RegisterWindow::on_btn_back_released() {
    emit backScreen();
}
