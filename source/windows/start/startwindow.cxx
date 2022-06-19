#include "startwindow.hxx"
#include "ui_startwindow.h"


StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    QPixmap pix_start_text(":/images/name_program.png");

    ui->l_start_text->setPixmap(pix_start_text.scaled(370, 216, Qt::KeepAspectRatio));

    ui->btn_login->setMinimumSize(120, 24);
    ui->btn_filter->setMinimumSize(120, 24);

//    ui->btn_login->setText("Login");
//    ui->btn_filter->setText("Search");
    ui->btn_login->setText("Авторизуватися");
    ui->btn_filter->setText("Пошук");
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
