#include "educationupdatewindow.hxx"
#include "ui_educationupdatewindow.h"


EducationUpdateWindow::EducationUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationUpdateWindow)
{
    ui->setupUi(this);

    ui->cb_education->addItem("None", 0);
    ui->cb_education->addItem("Basic", 1);
    ui->cb_education->addItem("Junior specialist", 2);
    ui->cb_education->addItem("Higher education", 3);
    ui->cb_education->addItem("Several higher education", 4);
    ui->cb_education->addItem("Candidate of sciences", 5);
    ui->cb_education->addItem("Stydying", 6);

    ui->le_title->setPlaceholderText("Заголовок");
    ui->te_description->setPlaceholderText("Опис");
    ui->le_for_time_start->setPlaceholderText("хххх-хх-хх");
    ui->le_for_time_end->setPlaceholderText("хххх-хх-хх");
    ui->le_req_experience->setPlaceholderText("Потрібний досвід у роках");
    ui->le_option_condition->setPlaceholderText("Додаткові умови");
    ui->le_city->setPlaceholderText("Місто");
    ui->le_location->setPlaceholderText("Локація");
    ui->le_phone->setPlaceholderText("Телефон");
    ui->le_email->setPlaceholderText("Е-пошта");
    ui->le_company->setPlaceholderText("Компанія");
    ui->cb_education->setCurrentText(0);
}


EducationUpdateWindow::~EducationUpdateWindow() {
    delete ui;
}


void EducationUpdateWindow::setObject(Education new_vacancy) {
    m_education = new_vacancy;
}


Education EducationUpdateWindow::getObject() {
    QString ed = ui->cb_education->itemText(ui->cb_education->currentIndex());
    int e = 0;

    if(ed == "Basic") {
        e = 1;
    }
    else if(ed == "Junior specialist") {
        e = 2;
    }
    else if(ed == "Higher education") {
        e = 3;
    }
    else if(ed == "Several higher education") {
        e = 4;
    }
    else if(ed == "Candidate of sciences") {
        e = 5;
    }
    else if(ed == "Studying") {
        e = 6;
    }
    else {
        e = 0;
    }

    Education edu;
    edu.setTitle(ui->le_title->text());
    edu.setDescription(ui->te_description->toPlainText());
    edu.setFor_time_start(ui->le_for_time_start->text());
    edu.setFor_time_end(ui->le_for_time_end->text());
    edu.setReq_experience(ui->le_req_experience->text().toInt());
    edu.setOption_condition(ui->le_option_condition->text());
    edu.setCity(ui->le_city->text());
    edu.setLocation(ui->le_location->text());
    edu.setPhone(ui->le_phone->text());
    edu.setEmail(ui->le_email->text());
    edu.setCompany(ui->le_company->text());
    edu.setReq_education(e);
    edu.setOwner(this->m_education.getOwner());

    return edu;
}


void EducationUpdateWindow::update() {
    ui->le_title->setText(m_education.getTitle());
    ui->te_description->setText(m_education.getDescription());
    ui->le_for_time_start->setText(m_education.getFor_time_start());
    ui->le_for_time_end->setText(m_education.getFor_time_end() );
    ui->le_req_experience->setText(QString::number(m_education.getReq_experience()));
    ui->le_option_condition->setText(m_education.getOption_condition());
    ui->le_city->setText(m_education.getCity());
    ui->le_location->setText(m_education.getLocation());
    ui->le_phone->setText(m_education.getPhone());
    ui->le_email->setText(m_education.getEmail());
    ui->le_company->setText(m_education.getCompany());
    ui->cb_education->setCurrentIndex(m_education.getReq_education());
}


void EducationUpdateWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void EducationUpdateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
