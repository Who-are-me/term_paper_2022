#include "filterwindow.hxx"
#include "ui_filterwindow.h"


FilterWindow::FilterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);

    ui->tab_table->setMinimumSize(300, 200);

    ui->btn_back->setMinimumSize(80, 24);
    ui->btn_search->setMinimumSize(80, 24);

    ui->btn_back->setText("Назад");
    ui->btn_search->setText("Пошук");
    ui->groupBox->setTitle("Параметри пошуку");

    ui->statusbar->hide();

    ui->le_title_e->setPlaceholderText("Заголовок");
    ui->le_description_e->setPlaceholderText("Опис");
    ui->le_start_e->setPlaceholderText("Початок");
    ui->le_end_e->setPlaceholderText("Кінець");
    ui->le_req_exp_e->setPlaceholderText("Потрібний досвід");
    ui->le_option_condition_e->setPlaceholderText("Додаткові вимоги");
    ui->le_city_e->setPlaceholderText("Місто");
    ui->le_location_e->setPlaceholderText("Локація");
    ui->le_phone_e->setPlaceholderText("Телефон");
    ui->le_email_e->setPlaceholderText("Електронна пошта");
    ui->le_company_e->setPlaceholderText("Компанія");
    ui->cb_education_e->setPlaceholderText("Рівень освіти");

    e_model = new QStandardItemModel(0, 14, this);
    r_model = new QStandardItemModel(0, 12, this);
    v_model = new QStandardItemModel(0, 12, this);

    ui->lv_education->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_resume->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lv_vacancy->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->cb_education_e->addItem("None", 0);
    ui->cb_education_e->addItem("Basic", 1);
    ui->cb_education_e->addItem("Junion specialist", 2);
    ui->cb_education_e->addItem("Higher education", 3);
    ui->cb_education_e->addItem("Several higher education", 4);
    ui->cb_education_e->addItem("Candidate of sciences", 5);
    ui->cb_education_e->addItem("Stydying", 6);

    ui->cb_education_e->hide();
}


FilterWindow::~FilterWindow() {
    delete ui;
    delete e_model;
    delete r_model;
    delete v_model;
}


void FilterWindow::updateTables(QList<Education> e_list, QList<Resume> r_list, QList<Vacancy> v_list) {
    updateEducationTables(e_list);
    updateResumeTables(r_list);
    updateVacancyTables(v_list);
}


void FilterWindow::updateEducationTables(QList<Education> e_list) {
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
        if(!ui->le_title_e->text().isEmpty()) {
            if(!vac.getTitle().contains(ui->le_title_e->text())) {
                continue;
            }
        }
        if(!ui->le_description_e->text().isEmpty()) {
            if(!vac.getDescription().contains(ui->le_description_e->text())) {
                continue;
            }
        }
        if(!ui->le_start_e->text().isEmpty()) {
            if(!vac.getFor_time_start().contains(ui->le_start_e->text())) {
                continue;
            }
        }
        if(!ui->le_end_e->text().isEmpty()) {
            if(!vac.getFor_time_end().contains(ui->le_end_e->text())) {
                continue;
            }
        }
        if(!ui->le_req_exp_e->text().isEmpty()) {
            if(vac.getReq_experience() <= ui->le_req_exp_e->text().toInt()) {
                continue;
            }
        }
        if(!ui->le_option_condition_e->text().isEmpty()) {
            if(!vac.getOption_condition().contains(ui->le_option_condition_e->text())) {
                continue;
            }
        }
        if(!ui->le_city_e->text().isEmpty()) {
            if(!vac.getCity().contains(ui->le_city_e->text())) {
                continue;
            }
        }
        if(!ui->le_location_e->text().isEmpty()) {
            if(!vac.getLocation().contains(ui->le_location_e->text())) {
                continue;
            }
        }
        if(!ui->le_phone_e->text().isEmpty()) {
            if(!vac.getPhone().contains(ui->le_phone_e->text())) {
                continue;
            }
        }
        if(!ui->le_email_e->text().isEmpty()) {
            if(!vac.getEmail().contains(ui->le_company_e->text())) {
                continue;
            }
        }
        if(!ui->le_company_e->text().isEmpty()) {
            if(!vac.getCompany().contains(ui->le_company_e->text())) {
                continue;
            }
        }

        QString education_type = "None";

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
    ui->lv_education->setColumnHidden(13, true);
}


void FilterWindow::updateResumeTables(QList<Resume> r_list) {
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
        if(!ui->le_pip_r->text().isEmpty()) {
            if(!vac.getPip().contains(ui->le_pip_r->text())) {
                continue;
            }
        }
        if(!ui->le_s_r->text().isEmpty()) {
            if(!vac.getSoft_skills().contains(ui->le_s_r->text())) {
                continue;
            }
        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }
//        if(!ui->le_pip_r->text().isEmpty()) {
//            if(!vac.getPip().contains(ui->le_pip_r->text())) {
//                continue;
//            }
//        }

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
    ui->lv_resume->setColumnHidden(11, true);
}


void FilterWindow::updateVacancyTables(QList<Vacancy> v_list) {
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
        if(!ui->le_title_v->text().isEmpty()) {
            if(!vac.getTitle().contains(ui->le_title_v->text())) {
                continue;
            }
        }
        if(!ui->le_description_v->text().isEmpty()) {
            if(!vac.getDescription().contains(ui->le_description_v->text())) {
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
    ui->lv_vacancy->setColumnHidden(11, true);
}


int FilterWindow::getCurrentEducationId() {
    return e_model->data(e_model->index(ui->lv_education->currentIndex().row(), 0)).toInt();
}


int FilterWindow::getCurrentResumeId() {
    return r_model->data(r_model->index(ui->lv_resume->currentIndex().row(), 0)).toInt();
}


int FilterWindow::getCurrentVacancyId() {
    return v_model->data(v_model->index(ui->lv_vacancy->currentIndex().row(), 0)).toInt();
}


void FilterWindow::on_btn_back_released() {
    emit pushBack();
}


void FilterWindow::on_btn_search_released() {
    emit pushSearch();
}


void FilterWindow::on_lv_education_doubleClicked() {
    emit showEducation();
}


void FilterWindow::on_lv_resume_doubleClicked() {
    emit showResume();
}


void FilterWindow::on_lv_vacancy_doubleClicked() {
    emit showVacancy();
}
