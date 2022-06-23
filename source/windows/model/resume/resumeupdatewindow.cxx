#include "resumeupdatewindow.hxx"
#include "ui_resumeupdatewindow.h"


ResumeUpdateWindow::ResumeUpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResumeUpdateWindow)
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


ResumeUpdateWindow::~ResumeUpdateWindow() {
    delete ui;
}


void ResumeUpdateWindow::setObject(Resume new_object) {
    m_resume = new_object;
}


Resume ResumeUpdateWindow::getObject() {
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
    res.setOwner(m_resume.getOwner());

    return res;
}


void ResumeUpdateWindow::update() {
    ui->le_pip->setText(m_resume.getPip());
    ui->le_soft_skills->setText(m_resume.getSoft_skills());
    ui->le_hard_skills->setText(m_resume.getHard_skills());
    ui->le_language->setText(m_resume.getLanguage());
    ui->le_hobbies->setText(m_resume.getHobbies());
    ui->le_phone->setText(m_resume.getPhone());
    ui->le_email->setText(m_resume.getEmail());
    ui->le_skype->setText(m_resume.getSkype());
    ui->le_qualification->setText(m_resume.getQualification());
    ui->te_about_myself->setText(m_resume.getAbout_myself());
}


void ResumeUpdateWindow::on_btn_ok_released() {
    emit pushOk();
    this->close();
}


void ResumeUpdateWindow::on_btn_cancel_released() {
    emit pushCancel();
    this->close();
}
