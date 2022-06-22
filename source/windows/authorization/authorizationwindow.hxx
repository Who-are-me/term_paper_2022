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
    void clearInput();

private:
    Ui::AuthorizationWindow         *ui;

signals:
    void pushLogin();
    void backScreen();

private slots:
    void on_btn_login_released();
    void on_btn_back_released();
};

