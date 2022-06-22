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

    a_model = new QStandardItemModel(1, 9, this);
    e_model = new QStandardItemModel(1, 11, this);
    r_model = new QStandardItemModel(1, 9, this);
    v_model = new QStandardItemModel(0, 12, this);
}


ControlAllProfilesWindow::~ControlAllProfilesWindow() {
    delete ui;
    delete a_model;
    delete e_model;
    delete r_model;
    delete v_model;
}


void ControlAllProfilesWindow::updateTables(QList<Account> a_list, QList<Education> e_list, QList<Resume> r_list, QList<Vacancy> v_list) {
    ui->lv_account->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_education->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_resume->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_vacancy->setEditTriggers(QAbstractItemView::NoEditTriggers);

    updateAccountTables(a_list);
    updateEducationTables(e_list);
    updateResumeTables(r_list);
    updateVacancyTables(v_list);
}


void ControlAllProfilesWindow::updateAccountTables(QList<Account> a_list) {
    emit updateTableAccount();

    a_model->removeRows(0, a_model->rowCount());

    a_model->setHeaderData(0,Qt::Horizontal,  tr("Піп"));
    a_model->setHeaderData(1,Qt::Horizontal,  tr("Місто"));
    a_model->setHeaderData(2,Qt::Horizontal,  tr("Локація"));
    a_model->setHeaderData(3,Qt::Horizontal,  tr("Телефон"));
    a_model->setHeaderData(4,Qt::Horizontal,  tr("Е-пошта"));
    a_model->setHeaderData(5,Qt::Horizontal,  tr("Компанія"));
    a_model->setHeaderData(6,Qt::Horizontal,  tr("Опис"));
    a_model->setHeaderData(7,Qt::Horizontal,  tr("Роль"));
    a_model->setHeaderData(8,Qt::Horizontal,  tr("Логін"));

    int index = 0;

    foreach(const Account &acc, a_list) {
        a_model->setItem(index, 0, new QStandardItem(acc.getPip()));
        a_model->setItem(index, 1, new QStandardItem(acc.getCity()));
        a_model->setItem(index, 2, new QStandardItem(acc.getLocation()));
        a_model->setItem(index, 3, new QStandardItem(acc.getPhone()));
        a_model->setItem(index, 4, new QStandardItem(acc.getEmail()));
        a_model->setItem(index, 5, new QStandardItem(acc.getCompany()));
        a_model->setItem(index, 6, new QStandardItem(acc.getDescription()));
        a_model->setItem(index, 7, new QStandardItem(acc.getRole()));
        a_model->setItem(index, 8, new QStandardItem(acc.getUsername()));
        ++index;
    }

    ui->lv_account->setModel(a_model);
}


void ControlAllProfilesWindow::updateEducationTables(QList<Education> e_list) {

}


void ControlAllProfilesWindow::updateResumeTables(QList<Resume> e_list) {

}


void ControlAllProfilesWindow::updateVacancyTables(QList<Vacancy> v_list) {
    emit updateTableVacancy();

    v_model->removeRows(0, v_model->rowCount());

    v_model->setHeaderData(0,Qt::Horizontal,  tr("ID"));
    v_model->setHeaderData(1,Qt::Horizontal,  tr("Заголовок"));
    v_model->setHeaderData(2,Qt::Horizontal,  tr("Опис"));
    v_model->setHeaderData(3,Qt::Horizontal,  tr("Зарплата"));
    v_model->setHeaderData(4,Qt::Horizontal,  tr("Освіта"));
    v_model->setHeaderData(5,Qt::Horizontal,  tr("Досвід"));
    v_model->setHeaderData(6,Qt::Horizontal,  tr("Місто"));
    v_model->setHeaderData(7,Qt::Horizontal,  tr("Локація"));
    v_model->setHeaderData(8,Qt::Horizontal,  tr("Телефон"));
    v_model->setHeaderData(9,Qt::Horizontal,  tr("Е-пошта"));
    v_model->setHeaderData(10,Qt::Horizontal, tr("Компанія"));
    v_model->setHeaderData(11,Qt::Horizontal, tr("Власник"));

    int index = 0;

    foreach(const Vacancy &vac, v_list) {
        QString education_type = "None";

        if(vac.getEducation() == 1) {
            education_type = "Basic";
        }
        else if(vac.getEducation() == 2) {
            education_type = "Junior specialist";
        }
        else if(vac.getEducation() == 3) {
            education_type = "Higher education";
        }
        else if(vac.getEducation() == 4) {
            education_type = "Several higher education";
        }
        else if(vac.getEducation() == 5) {
            education_type = "Candidate of sciences";
        }
        else if(vac.getEducation() == 6) {
            education_type = "Stydying";
        }

        v_model->setItem(index, 0, new QStandardItem(QString::number(vac.getId())));
        v_model->setItem(index, 1, new QStandardItem(vac.getTitle()));
        v_model->setItem(index, 2, new QStandardItem(vac.getDescription()));
        v_model->setItem(index, 3, new QStandardItem(QString::number(vac.getSalary())));
        v_model->setItem(index, 4, new QStandardItem(education_type));
        v_model->setItem(index, 5, new QStandardItem(QString::number(vac.getExperience())));
        v_model->setItem(index, 6, new QStandardItem(vac.getCity()));
        v_model->setItem(index, 7, new QStandardItem(vac.getLocation()));
        v_model->setItem(index, 8, new QStandardItem(vac.getPhone()));
        v_model->setItem(index, 9, new QStandardItem(vac.getEmail()));
        v_model->setItem(index, 10, new QStandardItem(vac.getCompany()));
        v_model->setItem(index, 11, new QStandardItem(vac.getOwner()));
        ++index;
    }

    ui->lv_vacancy->setModel(v_model);

    ui->lv_vacancy->setColumnHidden(0, true);
}


QString ControlAllProfilesWindow::getCurrentLogin() {
    Log::info(a_model->data(a_model->index(ui->lv_account->currentIndex().row(), 8)).toString());
    return a_model->data(a_model->index(ui->lv_account->currentIndex().row(), 8)).toString();
}


int ControlAllProfilesWindow::getCurrentVacancyId() {
    Log::info(v_model->data(v_model->index(ui->lv_vacancy->currentIndex().row(), 0)).toString());
    return v_model->data(v_model->index(ui->lv_vacancy->currentIndex().row(), 0)).toInt();
}


// TODO maybe remove it
void ControlAllProfilesWindow::initModels() {
    // account
    a_model->setHeaderData(0,Qt::Horizontal,  tr("Піп"));
    a_model->setHeaderData(1,Qt::Horizontal,  tr("Місто"));
    a_model->setHeaderData(2,Qt::Horizontal,  tr("Локація"));
    a_model->setHeaderData(3,Qt::Horizontal,  tr("Телефон"));
    a_model->setHeaderData(4,Qt::Horizontal,  tr("Е-пошта"));
    a_model->setHeaderData(5,Qt::Horizontal,  tr("Компанія"));
    a_model->setHeaderData(6,Qt::Horizontal,  tr("Опис"));
    a_model->setHeaderData(7,Qt::Horizontal,  tr("Роль"));
    a_model->setHeaderData(8,Qt::Horizontal,  tr("Логін"));
    // vacancy
    v_model->setHeaderData(0,Qt::Horizontal,  tr("ID"));
    v_model->setHeaderData(1,Qt::Horizontal,  tr("Заголовок"));
    v_model->setHeaderData(2,Qt::Horizontal,  tr("Опис"));
    v_model->setHeaderData(3,Qt::Horizontal,  tr("Зарплата"));
    v_model->setHeaderData(4,Qt::Horizontal,  tr("Освіта"));
    v_model->setHeaderData(5,Qt::Horizontal,  tr("Досвід"));
    v_model->setHeaderData(6,Qt::Horizontal,  tr("Місто"));
    v_model->setHeaderData(7,Qt::Horizontal,  tr("Локація"));
    v_model->setHeaderData(8,Qt::Horizontal,  tr("Телефон"));
    v_model->setHeaderData(9,Qt::Horizontal,  tr("Е-пошта"));
    v_model->setHeaderData(10,Qt::Horizontal, tr("Компанія"));
    v_model->setHeaderData(11,Qt::Horizontal, tr("Власник"));
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
    if(ui->tab_table->currentIndex() == 1) {
        emit createEducation();
    }
    else if(ui->tab_table->currentIndex() == 2) {
        emit createResume();
    }
    else if(ui->tab_table->currentIndex() == 3) {
        emit createVacancy();
    }
}


void ControlAllProfilesWindow::on_btn_read_record_released() {
    if(ui->tab_table->currentIndex() == 1) {
        emit readEducation();
    }
    else if(ui->tab_table->currentIndex() == 2) {
        emit readResume();
    }
    else if(ui->tab_table->currentIndex() == 3) {
        emit readVacancy();
    }
}


void ControlAllProfilesWindow::on_btn_update_record_released() {
    if(ui->tab_table->currentIndex() == 1) {
        emit updateEducation();
    }
    else if(ui->tab_table->currentIndex() == 2) {
        emit updateResume();
    }
    else if(ui->tab_table->currentIndex() == 3) {
        emit updateVacancy();
    }
}


void ControlAllProfilesWindow::on_btn_delete_record_released() {
    if(ui->tab_table->currentIndex() == 1) {
        emit deleteEducation();
    }
    else if(ui->tab_table->currentIndex() == 2) {
        emit deleteResume();
    }
    else if(ui->tab_table->currentIndex() == 3) {
        emit deleteVacancy();
    }
}


void ControlAllProfilesWindow::on_lv_account_doubleClicked() {
    // TODO read account
    Log::info(QString::number(ui->lv_account->currentIndex().row()));
    Log::info(QString::number(ui->lv_account->currentIndex().column()));
    getCurrentLogin();
}


void ControlAllProfilesWindow::on_lv_vacancy_doubleClicked() {
    // TODO read vacancy
    Log::info(QString::number(ui->lv_vacancy->currentIndex().row()));
    Log::info(v_model->data(v_model->index(0, 0)).toString());
}


void ControlAllProfilesWindow::on_btn_to_main_menu_released() {
    emit backScreen();
}


void ControlAllProfilesWindow::on_btn_logout_released() {
    emit logout();
}





