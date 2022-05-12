#include "createitemwindow.hxx"
#include "ui_createitemwindow.h"


CreateItemWindow::CreateItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateItemWindow)
{
    ui->setupUi(this);
}

CreateItemWindow::~CreateItemWindow() {
    delete ui;
}
