#include <QStringListModel>
#include <QStandardItemModel>

#include "controlallprofileswindow.hxx"
#include "ui_controlallprofileswindow.h"
#include "log.hxx"


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

    model = new QStandardItemModel(1, 9, this);
//    model_item = new QStandardItem();
//    account_list = new QList<Account>();





//    QStringListModel *model = new QStringListModel();

//    QStringList list;
//    list << "one" << "two" << "tree";

//QStandardItemModel *models = new QStandardItemModel(3, 7);
//models->setHeaderData(0,Qt::Horizontal,  tr("id"));
//int row = 0, column = 0;
//QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
//models->setItem(7, column, item);
//ui->lv_account->setModel(models);


////    ui->lv_account->setModel(model);
//    model->setHeaderData(0,Qt::Horizontal,  tr("id"));
//    model->setHeaderData(1,Qt::Horizontal,  tr("city"));
//    model->setHeaderData(2,Qt::Horizontal,  tr("position"));
//    model->setHeaderData(3,Qt::Horizontal,  tr("number"));
//    model->setHeaderData(4,Qt::Horizontal,  tr("experiense"));
//    model->setHeaderData(5,Qt::Horizontal,  tr("salary"));
//    model->setHeaderData(6,Qt::Horizontal,  tr("information"));
//    model->setHeaderData(7,Qt::Horizontal,  tr("account"));
//    model->setStringList(list);

    // set editable
//    ui->lv_account->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

//    updateTables();
}


ControlAllProfilesWindow::~ControlAllProfilesWindow() {
    delete ui;
    delete model;
//    delete model_item;
//    delete account_list;
}


//void ControlAllProfilesWindow::setAccountList(QList<Account> *list) {
//    Log::info("===> " + list->first().getUsername());
//    this->account_list = list;
//}


//void ControlAllProfilesWindow::setEducationList(QList<Education> *list) {
//    this->education_list = list;
//}


//void ControlAllProfilesWindow::setResumeList(QList<Resume> *list) {
//    this->resume_list = list;
//}


//void ControlAllProfilesWindow::setVacancyList(QList<Vacancy> *list) {
//    this->vacancy_list = list;
//}


void ControlAllProfilesWindow::updateTables(QList<Account> a_list) {
    ui->lv_account->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_education->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_resume->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_vacancy->setEditTriggers(QAbstractItemView::NoEditTriggers);

    updateAccountTables(a_list);
    updateEducationTables();
    updateResumeTables();
    updateVacancyTables();
}


void ControlAllProfilesWindow::updateAccountTables(QList<Account> a_list) {
    emit updateTableAccount();

    model->setHeaderData(0,Qt::Horizontal,  tr("Піп"));
    model->setHeaderData(1,Qt::Horizontal,  tr("Місто"));
    model->setHeaderData(2,Qt::Horizontal,  tr("Локація"));
    model->setHeaderData(3,Qt::Horizontal,  tr("Телефон"));
    model->setHeaderData(4,Qt::Horizontal,  tr("Е-пошта"));
    model->setHeaderData(5,Qt::Horizontal,  tr("Компанія"));
    model->setHeaderData(6,Qt::Horizontal,  tr("Опис"));
    model->setHeaderData(7,Qt::Horizontal,  tr("Роль"));
    model->setHeaderData(8,Qt::Horizontal,  tr("Логін"));

    int index = 0;


    foreach(const Account &acc, a_list) {
        model->setItem(index, 0, new QStandardItem(acc.getPip()));
        model->setItem(index, 1, new QStandardItem(acc.getCity()));
        model->setItem(index, 2, new QStandardItem(acc.getLocation()));
        model->setItem(index, 3, new QStandardItem(acc.getPhone()));
        model->setItem(index, 4, new QStandardItem(acc.getEmail()));
        model->setItem(index, 5, new QStandardItem(acc.getCompany()));
        model->setItem(index, 6, new QStandardItem(acc.getDescription()));
        model->setItem(index, 7, new QStandardItem(acc.getRole()));
        model->setItem(index, 8, new QStandardItem(acc.getUsername()));
        ++index;
    }

    ui->lv_account->setModel(model);
}


void ControlAllProfilesWindow::updateEducationTables() {

}


void ControlAllProfilesWindow::updateResumeTables() {

}


void ControlAllProfilesWindow::updateVacancyTables() {

}


QString ControlAllProfilesWindow::getCurrentLogin() {
    Log::info(model->data(model->index(ui->lv_account->currentIndex().row(), 8)).toString());
    return model->data(model->index(ui->lv_account->currentIndex().row(), 8)).toString();
}


void ControlAllProfilesWindow::on_btn_create_account_released() {
    emit createAccount();
}


void ControlAllProfilesWindow::on_btn_read_account_released() {
    emit readAccount();
}


void ControlAllProfilesWindow::on_btn_update_account_released() {
    emit updateAccount();
}


void ControlAllProfilesWindow::on_btn_delete_account_released() {
    emit deleteAccount();
}


void ControlAllProfilesWindow::on_btn_create_record_released() {
    emit createVacancy();
}


void ControlAllProfilesWindow::on_btn_read_record_released() {
    emit readVacancy();
}


void ControlAllProfilesWindow::on_btn_update_record_released() {
    emit updateVacancy();
}


void ControlAllProfilesWindow::on_btn_delete_record_released() {
    emit deleteVacancy();
}


void ControlAllProfilesWindow::on_lv_account_doubleClicked() {
    // TODO read account
    Log::info(QString::number(ui->lv_account->currentIndex().row()));
}





