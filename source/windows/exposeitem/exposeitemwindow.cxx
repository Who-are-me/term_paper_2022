#include "exposeitemwindow.hxx"
#include "ui_exposeitemwindow.h"

ExposeItemWindow::ExposeItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExposeItemWindow)
{
    ui->setupUi(this);
}

ExposeItemWindow::~ExposeItemWindow()
{
    delete ui;
}
