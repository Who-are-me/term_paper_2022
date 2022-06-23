#pragma once


#include <QMainWindow>
#include <QStandardItemModel>

#include "models/education.hxx"
#include "models/resume.hxx"
#include "models/vacancy.hxx"


namespace Ui { class FilterWindow; }


class FilterWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit FilterWindow(QWidget *parent = nullptr);
    ~FilterWindow();

    void updateTables(QList<Education> e_list, QList<Resume> r_list, QList<Vacancy> v_list);
    void updateEducationTables(QList<Education> e_list);
    void updateResumeTables(QList<Resume> r_list);
    void updateVacancyTables(QList<Vacancy> v_list);

    int getCurrentEducationId();
    int getCurrentResumeId();
    int getCurrentVacancyId();

private:
    Ui::FilterWindow 	*ui;
    QStandardItemModel 	*e_model;
    QStandardItemModel 	*r_model;
    QStandardItemModel 	*v_model;

signals:
    void pushBack();
    void pushSearch();

    void showEducation();
    void showResume();
    void showVacancy();

public slots:
    void on_btn_back_released();
    void on_btn_search_released();

    void on_lv_education_doubleClicked();
    void on_lv_resume_doubleClicked();
    void on_lv_vacancy_doubleClicked();
};

