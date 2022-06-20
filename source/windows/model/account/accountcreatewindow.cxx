#include "accountcreatewindow.hxx"
#include "ui_accountcreatewindow.h"

AccountCreateWindow::AccountCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountCreateWindow)
{
    ui->setupUi(this);
}

AccountCreateWindow::~AccountCreateWindow()
{
    delete ui;
}
