#pragma once

#include <QObject>
#include <QDebug>
#include <QString>

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
    StartWindow 					*w_start;
    AuthorizationWindow 			*w_auth;
    FilterWindow					*w_filter;
    RegisterWindow					*w_register;
    ControlAllProfilesWindow		*w_allprofiles;
    ControlCurrentProfilesWindow	*w_currentprofiles;

    bool init();

private slots:
    void moveToStartWindow();
    void moveToAuthWindow();
    void moveToFilterWindow();
    void moveToRegisterWindow();
    void moveToControlAllProfilesWindow();
    void moveToControlCurrentProfilesWindow();
};

