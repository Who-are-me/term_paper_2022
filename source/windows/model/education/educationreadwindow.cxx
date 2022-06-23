#include "educationreadwindow.hxx"
#include "ui_educationreadwindow.h"


EducationReadWindow::EducationReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EducationReadWindow)
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


EducationReadWindow::~EducationReadWindow() {
    delete ui;
}


void EducationReadWindow::setObject(Education new_vacancy) {
    m_education = new_vacancy;
}


void EducationReadWindow::update() {
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
