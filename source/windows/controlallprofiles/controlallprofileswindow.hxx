#pragma once

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QList>

#include "models/account.hxx"
#include "models/education.hxx"
#include "models/resume.hxx"
#include "models/vacancy.hxx"


namespace Ui {class ControlAllProfilesWindow;}


class ControlAllProfilesWindow : public QMainWindow {
    Q_OBJECT

public:
    ControlAllProfilesWindow(QWidget *parent = nullptr);
    ~ControlAllProfilesWindow();

//    void setAccountList(QList<Account> *list);
//    void setEducationList(QList<Education> *list);
//    void setResumeList(QList<Resume> *list);
//    void setVacancyList(QList<Vacancy> *list);

    // TODO more tables
    void updateTables(QList<Account> a_list);
    void updateAccountTables(QList<Account> a_list);
    void updateEducationTables();
    void updateResumeTables();
    void updateVacancyTables();
    QString getCurrentLogin();

private:
    Ui::ControlAllProfilesWindow 	*ui;
    QStandardItemModel 				*model;
//    QStandardItem 					*model_item;
//    QList<Account> 					*account_list;
//    QList<Education> 				*education_list;
//    QList<Resume> 					*resume_list;
//    QList<Vacancy> 					*vacancy_list;

private slots:
    void on_btn_create_account_released();
    void on_btn_read_account_released();
    void on_btn_update_account_released();
    void on_btn_delete_account_released();

    void on_btn_create_record_released();
    void on_btn_read_record_released();
    void on_btn_update_record_released();
    void on_btn_delete_record_released();

    void on_lv_account_doubleClicked();

signals:
    void updateTableAccount();
    void updateTableEducation();
    void updateTableResume();
    void updateTableVacancy();

    void createAccount();
    void readAccount();
    void updateAccount();
    void deleteAccount();

    void createVacancy();
    void readVacancy();
    void updateVacancy();
    void deleteVacancy();
};

