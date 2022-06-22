#include "vacancyupdatewindow.hxx"
#include "ui_vacancyupdatewindow.h"


VacancyUpdateWindow::VacancyUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyUpdateWindow)
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
//    ui->cb_education->setCurrentIndex(0);
    ui->le_experience->setPlaceholderText("Досвід");
    ui->le_city->setPlaceholderText("Місто");
    ui->le_location->setPlaceholderText("Локація");
    ui->le_phone->setPlaceholderText("Телефон");
    ui->le_company->setPlaceholderText("Компанія");
    ui->le_email->setPlaceholderText("Е-пошта");

    update();
}


VacancyUpdateWindow::~VacancyUpdateWindow() {
    delete ui;
}


void VacancyUpdateWindow::setObject(Vacancy new_vacancy) {
    this->m_vacancy = new_vacancy;
}


void VacancyUpdateWindow::update() {
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


void VacancyUpdateWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void VacancyUpdateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}


Vacancy VacancyUpdateWindow::getObject() {
//    int education = 0;

//    if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Stydying") {
//        education = 6;
//    }
//    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Basic") {
//        education = 1;
//    }
//    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Junior specialist") {
//        education = 2;
//    }
//    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Higher eucation") {
//        education = 3;
//    }
//    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Several higher education") {
//        education = 4;
//    }
//    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Candidate of sciences") {
//        education = 5;
//    }
//    else {
//        education = 0;
//    }

    Vacancy vacancy;
    vacancy.setTitle(ui->le_title->text());
    vacancy.setDescription(ui->te_description->toPlainText());
    vacancy.setSalary(ui->le_salary->text().toInt());
//    vacancy.setEducation(education);
    vacancy.setEducation(ui->cb_education->currentIndex());
    vacancy.setExperience(ui->le_experience->text().toInt());
    vacancy.setCity(ui->le_city->text());
    vacancy.setLocation(ui->le_location->text());
    vacancy.setPhone(ui->le_phone->text());
    vacancy.setEmail(ui->le_email->text());
    vacancy.setCompany(ui->le_company->text());
    vacancy.setOwner(this->m_vacancy.getOwner());

    return vacancy;
}
