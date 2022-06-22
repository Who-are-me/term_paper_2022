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
    ui->l_password->setText("Пароль");

    ui->le_pip->setPlaceholderText("піп");
    ui->le_city->setPlaceholderText("місто");
    ui->le_location->setPlaceholderText("локація");
    ui->le_phone->setPlaceholderText("телефон");
    ui->le_email->setPlaceholderText("е-пошта");
    ui->le_company->setPlaceholderText("компанія");
    ui->te_description->setPlaceholderText("опис");
    ui->le_login->setPlaceholderText("логін");
    ui->le_password->setPlaceholderText("пароль");
    ui->le_password->setEchoMode(QLineEdit::Password);
    ui->le_password->hide();
    ui->l_password->hide();

    ui->groupBox->setTitle("Дані акаунта");

    update();
}


AccountReadWindow::~AccountReadWindow() {
    delete ui;
}


void AccountReadWindow::setObject(Account new_account) {
    this->m_account = new_account;
}


void AccountReadWindow::update() {
    ui->le_pip->setText(m_account.getPip());
    ui->le_city->setText(m_account.getCity());
    ui->le_location->setText(m_account.getLocation());
    ui->le_phone->setText(m_account.getPhone());
    ui->le_email->setText(m_account.getEmail());
    ui->le_company->setText(m_account.getCompany());
    ui->te_description->setText(m_account.getDescription());
    ui->le_login->setText(m_account.getUsername());
}
