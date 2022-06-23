#pragma once

#include <QObject>
#include <QDebug>
#include <QString>

#include "conector.hxx"
#include "start/startwindow.hxx"
#include "filter/filterwindow.hxx"
#include "authorization/authorizationwindow.hxx"
#include "authorization/register/registerwindow.hxx"
#include "controlallprofiles/controlallprofileswindow.hxx"
#include "controlcurrentprofiles/controlcurrentprofileswindow.hxx"

#include "model/account/accountcreatewindow.hxx"
#include "model/account/accountreadwindow.hxx"
#include "model/account/accountupdatewindow.hxx"
#include "model/account/accountdeletewindow.hxx"

#include "model/education/educationcreatewindow.hxx"
#include "model/education/educationreadwindow.hxx"
#include "model/education/educationupdatewindow.hxx"
#include "model/education/educationdeletewindow.hxx"

#include "model/resume/resumecreatewindow.hxx"
#include "model/resume/resumereadwindow.hxx"
#include "model/resume/resumeupdatewindow.hxx"
#include "model/resume/resumedeletewindow.hxx"

#include "model/vacancy/vacancycreatewindow.hxx"
#include "model/vacancy/vacancyreadwindow.hxx"
#include "model/vacancy/vacancyupdatewindow.hxx"
#include "model/vacancy/vacancydeletewindow.hxx"


class Application : public QObject {
    Q_OBJECT

public:
    Application();
    ~Application();

    bool run();
    QString loadStyle(QString path);

private:
    // network
    Conector						*net_conector;
    // windows
    StartWindow 					*w_start;
    AuthorizationWindow 			*w_auth;
    FilterWindow					*w_filter;
    RegisterWindow					*w_register;
    ControlAllProfilesWindow		*w_allprofiles;
    ControlCurrentProfilesWindow	*w_currentprofiles;

    AccountCreateWindow				*w_account_create;
    AccountReadWindow				*w_account_read;
    AccountUpdateWindow				*w_account_update;
    AccountDeleteWindow				*w_account_delete;

    EducationCreateWindow			*w_education_create;
    EducationReadWindow				*w_education_read;
    EducationUpdateWindow			*w_education_update;
    EducationDeleteWindow			*w_education_delete;

    ResumeCreateWindow				*w_resume_create;
    ResumeReadWindow				*w_resume_read;
    ResumeUpdateWindow				*w_resume_update;
    ResumeDeleteWindow				*w_resume_delete;

    VacancyCreateWindow				*w_vacancy_create;
    VacancyReadWindow				*w_vacancy_read;
    VacancyUpdateWindow				*w_vacancy_update;
    VacancyDeleteWindow				*w_vacancy_delete;

    bool init();
    bool closeAllWindowExcept(QString name_window);
    // configure windows
    void configureStartWindow();
    void configureAuthWindow();
    void configureFilterWindow();
    void configureRegisterWindow();
    void configureControlAllProfilesWindow();
    void configureControlCurrentProfilesWindow();

    void configureAccountCreateWindow();
    void configureAccountReadWindow();
    void configureAccountUpdateWindow();
    void configureAccountDeleteWindow();

    void configureEducationCreateWindow();
    void configureEducationReadWindow();
    void configureEducationUpdateWindow();
    void configureEducationDeleteWindow();

    void configureResumeCreateWindow();
    void configureResumeReadWindow();
    void configureResumeUpdateWindow();
    void configureResumeDeleteWindow();

    void configureVacancyCreateWindow();
    void configureVacancyReadWindow();
    void configureVacancyUpdateWindow();
    void configureVacancyDeleteWindow();

private slots:
    // it's test slot
    void justTest();

    void tryLogin();

    // move to next windows
    void moveToStartWindow();
    void moveLogoutToStartWindow();
    void moveToAuthWindow();
    void moveToFilterWindow();
    void moveToRegisterWindow();
    void moveToControlAllProfilesWindow(bool is_admin);
    void moveToControlCurrentProfilesWindow();

    // show another window
    void showAccountCreateWindow();
    void showAccountReadWindow();
    void showAccountUpdateWindow();
    void showAccountDeleteWindow();

    void showEducationCreateWindow();
    void showEducationReadWindow();
    void showEducationUpdateWindow();
    void showEducationDeleteWindow();

    void showResumeCreateWindow();
    void showResumeReadWindow();
    void showResumeUpdateWindow();
    void showResumeDeleteWindow();

    void showVacancyCreateWindow();
    void showVacancyReadWindow();
    void showVacancyUpdateWindow();
    void showVacancyDeleteWindow();

    void accountCreate();
    void accountRead();
    void accountUpdate();
    void accountUpdateData();
    void accountDelete();

    void educationCreate();
    void educationRead();
    void educationUpdate();
    void educationUpdateData();
    void educationDelete();

    void resumeCreate();
    void resumeRead();
    void resumeUpdate();
    void resumeUpdateData();
    void resumeDelete();

    void vacancyCreate();
    void vacancyRead();
    void vacancyUpdate();
    void vacancyUpdateData();
    void vacancyDelete();

    void filterUpdate();

    void showEducation();
    void showResume();
    void showVacancy();
};

