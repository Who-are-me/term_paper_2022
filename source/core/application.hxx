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

    bool init();
    bool closeAllWindowExcept(QString name_window);
    // configure windows
    void configureStartWindow();
    void configureAuthWindow();
    void configureFilterWindow();
    void configureRegisterWindow();
    void configureControlAllProfilesWindow();
    void configureControlCurrentProfilesWindow();

private slots:
    // it's test slot
    void justTest();

    void tryLogin();

    // move to next windows
    void moveToStartWindow();
    void moveToAuthWindow();
    void moveToFilterWindow();
    void moveToRegisterWindow();
    void moveToControlAllProfilesWindow();
    void moveToControlCurrentProfilesWindow();
};

