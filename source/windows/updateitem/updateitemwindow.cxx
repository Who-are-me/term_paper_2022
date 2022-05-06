#include "updateitemwindow.hxx"
#include "ui_updateitemwindow.h"

UpdateItemWindow::UpdateItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpdateItemWindow)
{
    ui->setupUi(this);
}

UpdateItemWindow::~UpdateItemWindow()
{
    delete ui;
}
