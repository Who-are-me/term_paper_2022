#include "resumecreatewindow.hxx"
#include "ui_resumecreatewindow.h"


ResumeCreateWindow::ResumeCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeCreateWindow)
{
    ui->setupUi(this);

    ui->le_pip->setPlaceholderText("Піп");
    ui->le_soft_skills->setPlaceholderText("Комунікативні навики");
    ui->le_hard_skills->setPlaceholderText("Професійні навики");
    ui->le_language->setPlaceholderText("Мови якими ви володієте");
    ui->le_hobbies->setPlaceholderText("Хоббі");
    ui->le_phone->setPlaceholderText("Телефон");
    ui->le_email->setPlaceholderText("Е-пошта");
    ui->le_skype->setPlaceholderText("Skype");
    ui->le_qualification->setPlaceholderText("Клаліфікація");
    ui->te_about_myself->setPlaceholderText("Про себе");
}


ResumeCreateWindow::~ResumeCreateWindow() {
    delete ui;
}


Resume ResumeCreateWindow::getObject() {
    Resume res;

    res.setPip(ui->le_pip->text());
    res.setSoft_skills(ui->le_soft_skills->text());
    res.setHard_skills(ui->le_hard_skills->text());
    res.setLanguage(ui->le_language->text());
    res.setHobbies(ui->le_hobbies->text());
    res.setPhone(ui->le_phone->text());
    res.setEmail(ui->le_email->text());
    res.setSkype(ui->le_skype->text());
    res.setQualification(ui->le_qualification->text());
    res.setAbout_myself(ui->te_about_myself->toPlainText());

    return res;
}


void ResumeCreateWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void ResumeCreateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
