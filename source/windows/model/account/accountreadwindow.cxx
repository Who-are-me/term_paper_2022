#include "accountreadwindow.hxx"
#include "ui_accountreadwindow.h"

AccountReadWindow::AccountReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountReadWindow)
{
    ui->setupUi(this);
}

AccountReadWindow::~AccountReadWindow()
{
    delete ui;
}
