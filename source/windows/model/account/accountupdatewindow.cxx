#include "accountupdatewindow.hxx"
#include "ui_accountupdatewindow.h"

AccountUpdateWindow::AccountUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountUpdateWindow)
{
    ui->setupUi(this);
}

AccountUpdateWindow::~AccountUpdateWindow()
{
    delete ui;
}
