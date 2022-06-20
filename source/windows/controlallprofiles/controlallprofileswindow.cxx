#include "controlallprofileswindow.hxx"
#include "ui_controlallprofileswindow.h"


ControlAllProfilesWindow::ControlAllProfilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlAllProfilesWindow)
{
    ui->setupUi(this);

    ui->tab_table->setMinimumSize(300, 200);


    ui->btn_logout->setText("Вийти з акаунта");
    ui->btn_to_main_menu->setText("У головне меню");

    ui->gb_account->setTitle("Акаунт");
    ui->btn_create_account->setText("Створити");
    ui->btn_read_account->setText("Показати");
    ui->btn_update_account->setText("Оновити");
    ui->btn_delete_account->setText("Видалити");

    ui->gb_record->setTitle("Оголошення");
    ui->btn_create_record->setText("Створити");
    ui->btn_read_record->setText("Показати");
    ui->btn_update_record->setText("Оновити");
    ui->btn_delete_record->setText("Видалити");
}


ControlAllProfilesWindow::~ControlAllProfilesWindow() {
    delete ui;
}
