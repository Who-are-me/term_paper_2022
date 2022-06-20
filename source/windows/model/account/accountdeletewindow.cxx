#include "accountdeletewindow.hxx"
#include "ui_accountdeletewindow.h"

AccountDeleteWindow::AccountDeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountDeleteWindow)
{
    ui->setupUi(this);
}

AccountDeleteWindow::~AccountDeleteWindow()
{
    delete ui;
}
