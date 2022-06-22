#include "vacancycreatewindow.hxx"
#include "ui_vacancycreatewindow.h"


VacancyCreateWindow::VacancyCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyCreateWindow)
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
    ui->le_salary->setPlaceholderText("Зарплата");
    ui->cb_education->setCurrentIndex(0);
    ui->le_experience->setPlaceholderText("Досвід");
    ui->le_city->setPlaceholderText("Місто");
    ui->le_location->setPlaceholderText("Локація");
    ui->le_phone->setPlaceholderText("Телефон");
    ui->le_company->setPlaceholderText("Компанія");
    ui->le_email->setPlaceholderText("Е-пошта");
}


VacancyCreateWindow::~VacancyCreateWindow() {
    delete ui;
}


Vacancy VacancyCreateWindow::getObject() {
    int education = 0;

    if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Stydying") {
        education = 6;
    }
    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Basic") {
        education = 1;
    }
    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Junior specialist") {
        education = 2;
    }
    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Higher eucation") {
        education = 3;
    }
    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Several higher education") {
        education = 4;
    }
    else if(ui->cb_education->itemText(ui->cb_education->currentIndex()) == "Candidate of sciences") {
        education = 5;
    }
    else {
        education = 0;
    }

    Vacancy vacancy;
    vacancy.setTitle(ui->le_title->text());
    vacancy.setDescription(ui->te_description->toPlainText());
    vacancy.setSalary(ui->le_salary->text().toInt());
    vacancy.setEducation(education);
    vacancy.setExperience(ui->le_experience->text().toInt());
    vacancy.setCity(ui->le_city->text());
    vacancy.setLocation(ui->le_location->text());
    vacancy.setPhone(ui->le_phone->text());
    vacancy.setEmail(ui->le_email->text());
    vacancy.setCompany(ui->le_company->text());

    return vacancy;
}


void VacancyCreateWindow::on_btn_ok_released() {
    emit pushOk();
}


void VacancyCreateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
