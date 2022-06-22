#include "vacancyreadwindow.hxx"
#include "ui_vacancyreadwindow.h"


VacancyReadWindow::VacancyReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyReadWindow)
{
    ui->setupUi(this);

    ui->cb_education->addItem("None", 0);
    ui->cb_education->addItem("Basic", 1);
    ui->cb_education->addItem("Junion specialist", 2);
    ui->cb_education->addItem("Higher education", 3);
    ui->cb_education->addItem("Several higher education", 4);
    ui->cb_education->addItem("Candidate of sciences", 5);
    ui->cb_education->addItem("Stydying", 6);

    ui->le_title->setPlaceholderText("Заголовок");
    ui->te_description->setPlaceholderText("Опис");
    ui->le_salary->setPlaceholderText("Зарплата");
    ui->cb_education->setCurrentIndex(0);
    ui->le_experience->setPlaceholderText("Досвід");
    ui->le_city->setPlaceholderText("Місто");
    ui->le_location->setPlaceholderText("Локація");
    ui->le_phone->setPlaceholderText("Телефон");
    ui->le_company->setPlaceholderText("Компанія");
    ui->le_email->setPlaceholderText("Е-пошта");
}


VacancyReadWindow::~VacancyReadWindow() {
    delete ui;
}


void VacancyReadWindow::setObject(Vacancy new_vacancy) {
    this->m_vacancy = new_vacancy;
}


void VacancyReadWindow::update() {
    ui->le_title->setText(m_vacancy.getTitle());
    ui->te_description->setText(m_vacancy.getDescription());
    ui->le_salary->setText(QString::number(m_vacancy.getSalary()));
    ui->cb_education->setCurrentIndex(m_vacancy.getEducation());
    ui->le_experience->setText(QString::number(m_vacancy.getExperience()));
    ui->le_city->setText(m_vacancy.getCity());
    ui->le_location->setText(m_vacancy.getLocation());
    ui->le_phone->setText(m_vacancy.getPhone());
    ui->le_company->setText(m_vacancy.getCompany());
    ui->le_email->setText(m_vacancy.getEmail());
}
