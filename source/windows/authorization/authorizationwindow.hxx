#pragma once

#include <QDialog>
#include <QDebug>

#include "controlallprofiles/controlallprofileswindow.hxx"
#include "controlcurrentprofiles/controlcurrentprofileswindow.hxx"
#include "authorization/register/registerwindow.hxx"

#define D_AW	qDebug() << "AuthorizationWindow: "


namespace Ui { class AuthorizationWindow; }


class AuthorizationWindow : public QDialog {
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

private:
    Ui::AuthorizationWindow         *ui;
    ControlAllProfilesWindow        *w_control_all_profiles;
    ControlCurrentProfilesWindow    *w_control_current_profiles;
    RegisterWindow	                *w_register;

    bool createWindowRegister();
    bool createWindowLogin();
    bool createWindowAdminLogin();
    void configureWindowRegister();
    void configureWindowLogin();
    bool configureWindowAdminLogin();

private slots:
    void on_btn_login_released();
    void on_btn_register_released();
};

