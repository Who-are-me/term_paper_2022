#include "registerwindow.hxx"
#include "ui_registerwindow.h"


RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
//    D_RW << "create object";
}

RegisterWindow::~RegisterWindow() {
    delete ui;
}
