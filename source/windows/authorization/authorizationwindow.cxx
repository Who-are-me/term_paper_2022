#include "authorizationwindow.hxx"
#include "ui_authorizationwindow.h"


AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);

    this->setMinimumSize(270, 150);
    this->setMaximumSize(270, 150);


    ui->btn_login->setText("Авторизуватися");
    ui->btn_back->setText("Назад");

    ui->btn_login->setMinimumSize(120, 24);
    ui->btn_back->setMinimumSize(80, 24);

    ui->label->setText("");
    ui->label_2->setText("");

    ui->le_login->setPlaceholderText("Логін");
    ui->le_password->setPlaceholderText("Пароль");

    ui->le_password->setEchoMode(QLineEdit::Password);

    QPixmap pix_login(":/images/user_icon.png");
    QPixmap pix_password(":/images/password_icon.png");

    ui->label->setPixmap(pix_login.scaled(26, 26, Qt::KeepAspectRatio));
    ui->label_2->setPixmap(pix_password.scaled(26, 26, Qt::KeepAspectRatio));
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


//void AuthorizationWindow::on_btn_register_released() {
//    // TODO make registration
//    emit showRegister();
//}


void AuthorizationWindow::on_btn_back_released() {
    // TODO make me
    emit backScreen();
}
