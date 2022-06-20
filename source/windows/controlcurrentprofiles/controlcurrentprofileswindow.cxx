#include "controlcurrentprofileswindow.hxx"
#include "ui_controlcurrentprofileswindow.h"


ControlCurrentProfilesWindow::ControlCurrentProfilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlCurrentProfilesWindow)
{
    ui->setupUi(this);

    ui->tab_table->setMinimumSize(300, 200);

    ui->btn_logout->setText("Вийти з акаунта");
    ui->btn_to_main_menu->setText("У головне меню");

    ui->gb->setTitle("Оголошення");
    ui->btn_create->setText("Створити");
    ui->btn_read->setText("Показати");
    ui->btn_update->setText("Оновити");
    ui->btn_delete->setText("Видалити");
}


ControlCurrentProfilesWindow::~ControlCurrentProfilesWindow() {
    delete ui;
}
