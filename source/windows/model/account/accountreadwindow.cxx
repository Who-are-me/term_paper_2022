#include "accountreadwindow.hxx"
#include "ui_accountreadwindow.h"

AccountReadWindow::AccountReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountReadWindow)
{
    ui->setupUi(this);

    ui->l_pip->setText("Піп");
    ui->l_city->setText("Місто");
    ui->l_location->setText("Локація");
    ui->l_phone->setText("Телефон");
    ui->l_email->setText("Електонна пошта");
    ui->l_company->setText("Компанія");
    ui->l_description->setText("Опис користувача");
    ui->l_login->setText("Логін");
//    ui->l_password->setText("Пароль");

    ui->le_pip->setPlaceholderText("піп");
    ui->le_city->setPlaceholderText("місто");
    ui->le_location->setPlaceholderText("локація");
    ui->le_phone->setPlaceholderText("телефон");
    ui->le_email->setPlaceholderText("е-пошта");
    ui->le_company->setPlaceholderText("компанія");
    ui->te_description->setPlaceholderText("опис");
    ui->le_login->setPlaceholderText("логін");
//    ui->le_password->setPlaceholderText("пароль");
//    ui->le_password->setEchoMode(QLineEdit::Password);
    ui->le_password->hide();
    ui->l_password->hide();

    ui->groupBox->setTitle("Дані акаунта");
}


AccountReadWindow::~AccountReadWindow() {
    delete ui;
}
