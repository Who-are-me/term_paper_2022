#include <QDebug>

#include "startwindow.hxx"
// #include "build-debug/TermPaper_autogen/include/ui_startwindow.h"
//#include "../../../build-debug/TermPaper_autogen/include/ui_startwindow.h"
#include "ui_startwindow.h"


StartWindow::StartWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::StartWindow) {
    ui->setupUi(this);
    D_SW << "create object";
}


StartWindow::~StartWindow() {
    delete ui;
    delete w_auth;
}


bool StartWindow::createWindowAuthorization() {
    w_auth = new AuthorizationWindow();

    this->configureWindowAuthorization();

    D_SW << "creation and configure authorization window successful";

    w_auth->exec();

    return true;
}


bool StartWindow::createWindowFilter() {
    // TODO implement me
    return true;
}


void StartWindow::configureWindowAuthorization() {
    // TODO make config window
}


void StartWindow::configureWindowFilter() {
    // TODO implement me
}


void StartWindow::on_btn_login_released() {
    D_SW << "start creation login window...";

    this->close();
    this->createWindowAuthorization();
}


void StartWindow::on_btn_filter_released() {
    D_SW << "start creation filter window...";
    // TODO implement me
}
