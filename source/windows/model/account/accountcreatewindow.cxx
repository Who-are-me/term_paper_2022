#include "accountcreatewindow.hxx"
#include "ui_accountcreatewindow.h"
#include "log.hxx"


AccountCreateWindow::AccountCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountCreateWindow)
{
    ui->setupUi(this);

    ui->l_pip->setText("Піп");
    ui->l_city->setText("Місто");
    ui->l_location->setText("Локація");
    ui->l_phone->setText("Телефон");
    ui->l_email->setText("Електонна пошта");
    ui->l_company->setText("Компанія");
    ui->l_description->setText("Опис користувача");
    ui->l_role->setText("Роль користувача");
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

    ui->groupBox->setTitle("Форма створення акаунта");

    ui->cb_role->addItem("Admin", 0);
    ui->cb_role->addItem("Basic", 1);
}


AccountCreateWindow::~AccountCreateWindow() {
    delete ui;
}


Account AccountCreateWindow::getObject() {
    Log::info(ui->cb_role->itemText(ui->cb_role->currentIndex()));

    Account account(ui->le_pip->text(),
                    ui->le_city->text(),
                    ui->le_location->text(),
                    ui->le_phone->text(),
                    ui->le_email->text(),
                    ui->le_company->text(),
                    ui->te_description->toPlainText(),
                    ui->cb_role->itemText(ui->cb_role->currentIndex()) == "Admin" ? "ROLE_ADMIN" : "ROLE_USER",
                    ui->le_login->text(),
                    ui->le_password->text(),
                    true);

    return account;
}


void AccountCreateWindow::on_btn_ok_released() {
    emit pushOk();
}


void AccountCreateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}


