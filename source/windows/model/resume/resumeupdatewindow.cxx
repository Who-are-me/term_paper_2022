#include "resumeupdatewindow.hxx"
#include "ui_resumeupdatewindow.h"


ResumeUpdateWindow::ResumeUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeUpdateWindow)
{
    ui->setupUi(this);
}


ResumeUpdateWindow::~ResumeUpdateWindow() {
    delete ui;
}


void ResumeUpdateWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void ResumeUpdateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
