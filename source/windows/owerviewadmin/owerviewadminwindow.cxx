#include "owerviewadminwindow.hxx"
#include "ui_owerviewadminwindow.h"

OwerviewAdminWindow::OwerviewAdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OwerviewAdminWindow)
{
    ui->setupUi(this);
}

OwerviewAdminWindow::~OwerviewAdminWindow()
{
    delete ui;
}
