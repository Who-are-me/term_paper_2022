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

    // TODO more tables
    void updateTables(QList<Account> a_list, QList<Education> e_list, QList<Resume> r_list, QList<Vacancy> v_list);
    void updateAccountTables(QList<Account> a_list);
    void updateEducationTables(QList<Education> e_list);
    void updateResumeTables(QList<Resume> r_list);
    void updateVacancyTables(QList<Vacancy> v_list);

    QString getCurrentLogin();
    int getCurrentVacancyId();
    int getCurrentEducationId();

private:
    Ui::ControlAllProfilesWindow 	*ui;
    QStandardItemModel 				*a_model;
    QStandardItemModel 				*e_model;
    QStandardItemModel 				*r_model;
    QStandardItemModel 				*v_model;

    void initModels();

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
    void on_lv_vacancy_doubleClicked();

    void on_btn_to_main_menu_released();
    void on_btn_logout_released();

signals:
    void updateTableAccount();
    void updateTableEducation();
    void updateTableResume();
    void updateTableVacancy();

    void createAccount();
    void readAccount();
    void updateAccount();
    void deleteAccount();

    void createEducation();
    void readEducation();
    void updateEducation();
    void deleteEducation();

    void createResume();
    void readResume();
    void updateResume();
    void deleteResume();

    void createVacancy();
    void readVacancy();
    void updateVacancy();
    void deleteVacancy();

    void backScreen();
    void logout();
};

