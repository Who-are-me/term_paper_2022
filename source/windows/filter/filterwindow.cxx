#include "filterwindow.hxx"
#include "ui_filterwindow.h"


FilterWindow::FilterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);

    ui->tab_table->setMinimumSize(300, 200);

//    ui->btn_create->setMaximumSize(80, 24);
//    ui->btn_read->setMaximumSize(80, 24);
//    ui->btn_update->setMaximumSize(80, 24);
//    ui->btn_delete->setMaximumSize(80, 24);
    ui->btn_back->setMinimumSize(80, 24);
    ui->btn_search->setMinimumSize(80, 24);

//    ui->btn_create->setText("Створити");
//    ui->btn_read->setText("Показати");
//    ui->btn_update->setText("Оновити");
//    ui->btn_delete->setText("Видалити");
    ui->btn_back->setText("Назад");
    ui->btn_search->setText("Пошук");
    ui->groupBox->setTitle("Параметри пошуку");

    ui->le_title->setPlaceholderText("Заголовок");
    ui->le_description->setPlaceholderText("Опис");
    ui->le_start->setPlaceholderText("Початок");
    ui->le_end->setPlaceholderText("Кінець");
    ui->le_req_exp->setPlaceholderText("Потрібний досвід");
    ui->le_option_condition->setPlaceholderText("Додаткові вимоги");
    ui->le_city->setPlaceholderText("Місто");
    ui->le_location->setPlaceholderText("Локація");
    ui->le_phone->setPlaceholderText("Телефон");
    ui->le_email->setPlaceholderText("Електронна пошта");
    ui->le_company->setPlaceholderText("Компанія");
    ui->cb_education->setPlaceholderText("Рівень освіти");
}


FilterWindow::~FilterWindow() {
    delete ui;
}
