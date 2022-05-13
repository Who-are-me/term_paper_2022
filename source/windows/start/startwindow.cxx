#include "startwindow.hxx"
#include "ui_startwindow.h"


StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}


StartWindow::~StartWindow() {
    delete ui;
}


void StartWindow::on_btn_login_released() {
    emit showAuth();
}


void StartWindow::on_btn_filter_released() {
    emit showFilter();
}
