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
