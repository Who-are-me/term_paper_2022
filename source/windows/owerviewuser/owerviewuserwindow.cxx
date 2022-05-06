#include "owerviewuserwindow.hxx"
#include "ui_owerviewuserwindow.h"

OwerviewUserWindow::OwerviewUserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OwerviewUserWindow)
{
    ui->setupUi(this);
}

OwerviewUserWindow::~OwerviewUserWindow()
{
    delete ui;
}
