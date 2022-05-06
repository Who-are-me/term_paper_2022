#include "removeitemwindow.hxx"
#include "ui_removeitemwindow.h"

RemoveItemWindow::RemoveItemWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveItemWindow)
{
    ui->setupUi(this);
}

RemoveItemWindow::~RemoveItemWindow()
{
    delete ui;
}
