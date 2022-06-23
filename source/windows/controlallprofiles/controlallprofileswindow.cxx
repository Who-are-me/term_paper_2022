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

    a_model = new QStandardItemModel(0, 9, this);
    e_model = new QStandardItemModel(0, 14, this);
    r_model = new QStandardItemModel(0, 12, this);
    v_model = new QStandardItemModel(0, 12, this);

    is_admin = true;
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
    emit updateTableEducation();

    e_model->removeRows(0, e_model->rowCount());

    e_model->setHeaderData(0,Qt::Horizontal,  tr("ID"));
    e_model->setHeaderData(1,Qt::Horizontal,  tr("Заголовок"));
    e_model->setHeaderData(2,Qt::Horizontal,  tr("Опис"));
    e_model->setHeaderData(3,Qt::Horizontal,  tr("Початок у"));
    e_model->setHeaderData(4,Qt::Horizontal,  tr("Кінець у"));
    e_model->setHeaderData(5,Qt::Horizontal,  tr("Потрібний досвід"));
    e_model->setHeaderData(6,Qt::Horizontal,  tr("Додаткові умови"));
    e_model->setHeaderData(7,Qt::Horizontal,  tr("Місто"));
    e_model->setHeaderData(8,Qt::Horizontal,  tr("Локація"));
    e_model->setHeaderData(9,Qt::Horizontal,  tr("Телефон"));
    e_model->setHeaderData(10,Qt::Horizontal, tr("Е-пошта"));
    e_model->setHeaderData(11,Qt::Horizontal, tr("Компанія"));
    e_model->setHeaderData(12,Qt::Horizontal, tr("Потрібна освіта"));
    e_model->setHeaderData(13,Qt::Horizontal, tr("Власник"));

    int index = 0;

    foreach(const Education &vac, e_list) {
        QString education_type = "None";

        if(!is_admin) {
            if(vac.getOwner() != username) {
                continue;
            }
        }

        if(vac.getReq_education() == 1) {
            education_type = "Basic";
        }
        else if(vac.getReq_education() == 2) {
            education_type = "Junior specialist";
        }
        else if(vac.getReq_education() == 3) {
            education_type = "Higher education";
        }
        else if(vac.getReq_education() == 4) {
            education_type = "Several higher education";
        }
        else if(vac.getReq_education() == 5) {
            education_type = "Candidate of sciences";
        }
        else if(vac.getReq_education() == 6) {
            education_type = "Stydying";
        }

        e_model->setItem(index, 0, new QStandardItem(QString::number(vac.getId())));
        e_model->setItem(index, 1, new QStandardItem(vac.getTitle()));
        e_model->setItem(index, 2, new QStandardItem(vac.getDescription()));
        e_model->setItem(index, 3, new QStandardItem(vac.getFor_time_start()));
        e_model->setItem(index, 4, new QStandardItem(vac.getFor_time_end()));
        e_model->setItem(index, 5, new QStandardItem(QString::number(vac.getReq_experience())));
        e_model->setItem(index, 6, new QStandardItem(vac.getOption_condition()));
        e_model->setItem(index, 7, new QStandardItem(vac.getCity()));
        e_model->setItem(index, 8, new QStandardItem(vac.getLocation()));
        e_model->setItem(index, 9, new QStandardItem(vac.getPhone()));
        e_model->setItem(index, 10,new QStandardItem(vac.getEmail()));
        e_model->setItem(index, 11,new QStandardItem(vac.getCompany()));
        e_model->setItem(index, 12,new QStandardItem(education_type));
        e_model->setItem(index, 13,new QStandardItem(vac.getOwner()));
        ++index;
    }

    ui->lv_education ->setModel(e_model);

    ui->lv_education->setColumnHidden(0, true);
}


void ControlAllProfilesWindow::updateResumeTables(QList<Resume> r_list) {
    emit updateTableResume();

    r_model->removeRows(0, r_model->rowCount());

    r_model->setHeaderData(0,Qt::Horizontal,  tr("ID"));
    r_model->setHeaderData(1,Qt::Horizontal,  tr("Піп"));
    r_model->setHeaderData(2,Qt::Horizontal,  tr("Комунікативні навики"));
    r_model->setHeaderData(3,Qt::Horizontal,  tr("Професійні навики"));
    r_model->setHeaderData(4,Qt::Horizontal,  tr("Знання мов"));
    r_model->setHeaderData(5,Qt::Horizontal,  tr("Хоббі"));
    r_model->setHeaderData(6,Qt::Horizontal,  tr("Телефон"));
    r_model->setHeaderData(7,Qt::Horizontal,  tr("Е-пошта"));
    r_model->setHeaderData(8,Qt::Horizontal,  tr("Skype"));
    r_model->setHeaderData(9,Qt::Horizontal,  tr("Клаліфікація"));
    r_model->setHeaderData(10,Qt::Horizontal, tr("Про себе"));
    r_model->setHeaderData(11,Qt::Horizontal, tr("Власник"));

    int index = 0;

    foreach(const Resume &vac, r_list) {
        if(!is_admin) {
            if(vac.getOwner() != username) {
                continue;
            }
        }

        r_model->setItem(index, 0, new QStandardItem(QString::number(vac.getId())));
        r_model->setItem(index, 1, new QStandardItem(vac.getPip()));
        r_model->setItem(index, 2, new QStandardItem(vac.getSoft_skills()));
        r_model->setItem(index, 3, new QStandardItem(vac.getHard_skills()));
        r_model->setItem(index, 4, new QStandardItem(vac.getLanguage()));
        r_model->setItem(index, 5, new QStandardItem(vac.getHobbies()));
        r_model->setItem(index, 6, new QStandardItem(vac.getPhone()));
        r_model->setItem(index, 7, new QStandardItem(vac.getEmail()));
        r_model->setItem(index, 8, new QStandardItem(vac.getSkype()));
        r_model->setItem(index, 9, new QStandardItem(vac.getQualification()));
        r_model->setItem(index, 10,new QStandardItem(vac.getAbout_myself()));
        r_model->setItem(index, 11,new QStandardItem(vac.getOwner()));
        ++index;
    }

    ui->lv_resume ->setModel(r_model);

    ui->lv_resume->setColumnHidden(0, true);
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
        if(!is_admin) {
            if(vac.getOwner() != username) {
                continue;
            }
        }

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


void ControlAllProfilesWindow::noAdmin() {
    ui->btn_create_account->setEnabled(false);
    ui->btn_read_account->setEnabled(false);
    ui->btn_update_account->setEnabled(false);
    ui->btn_delete_account->setEnabled(false);
    ui->tab_table->setTabEnabled(0, false);
    is_admin = false;
}


const QString &ControlAllProfilesWindow::getUsername() const {
    return username;
}


void ControlAllProfilesWindow::setUsername(const QString &newUsername) {
    username = newUsername;
}


int ControlAllProfilesWindow::getCurrentEducationId() {
    Log::info(e_model->data(e_model->index(ui->lv_education->currentIndex().row(), 0)).toString());
    return e_model->data(e_model->index(ui->lv_education->currentIndex().row(), 0)).toInt();
}


int ControlAllProfilesWindow::getCurrentResumeId() {
    Log::info(r_model->data(r_model->index(ui->lv_resume->currentIndex().row(), 0)).toString());
    return r_model->data(r_model->index(ui->lv_resume->currentIndex().row(), 0)).toInt();
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





