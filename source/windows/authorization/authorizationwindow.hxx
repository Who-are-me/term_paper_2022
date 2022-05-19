#pragma once

#include <QDialog>

//#include "controlallprofiles/controlallprofileswindow.hxx"
//#include "controlcurrentprofiles/controlcurrentprofileswindow.hxx"
//#include "authorization/register/registerwindow.hxx"


namespace Ui { class AuthorizationWindow; }


class AuthorizationWindow : public QDialog {
    Q_OBJECT

public:
    AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

    QString getLogin();
    QString getPassword();

private:
    Ui::AuthorizationWindow         *ui;
//    ControlAllProfilesWindow        *w_control_all_profiles;
//    ControlCurrentProfilesWindow    *w_control_current_profiles;
//    RegisterWindow	                *w_register;

signals:
    void pushLogin();
    void showRegister();
    void backScreen();

private slots:
    void on_btn_login_released();
    void on_btn_register_released();
    void on_btn_back_released();
};

