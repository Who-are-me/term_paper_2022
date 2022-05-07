#include "authorizationwindow.hxx"
#include "ui_authorizationwindow.h"


AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);
    D_AW << "create object";
}


AuthorizationWindow::~AuthorizationWindow() {
    delete ui;
    delete w_control_all_profiles;
    delete w_control_current_profiles;
    delete w_register;
}


bool AuthorizationWindow::createWindowRegister() {
    w_register = new RegisterWindow();

    this->configureWindowRegister();

    D_AW << "create and configuration register window successful";

    w_register->exec();

    return true;
}


bool AuthorizationWindow::createWindowLogin() {
    w_control_current_profiles = new ControlCurrentProfilesWindow();

    this->configureWindowLogin();

    D_AW << "create and configuration login(current) window successful";

    this->close();

    w_control_current_profiles->show();

    return true;
}


bool AuthorizationWindow::createWindowAdminLogin() {
    // TODO implement this
    return true;
}


void AuthorizationWindow::configureWindowRegister() {
    // TODO configure register window
}


bool AuthorizationWindow::configureWindowAdminLogin() {
    w_control_all_profiles = new ControlAllProfilesWindow();

    this->configureWindowAdminLogin();

    D_AW << "create and configuration login(all) window successful";

    w_control_all_profiles->show();

    return true;
}


void AuthorizationWindow::configureWindowLogin() {
    // TODO implement this
}


void AuthorizationWindow::on_btn_login_released() {
    // TODO make authorization
    if(true) {
        createWindowLogin();
    }
    else {
        createWindowAdminLogin();
    }
}


void AuthorizationWindow::on_btn_register_released() {
    createWindowRegister();
}
