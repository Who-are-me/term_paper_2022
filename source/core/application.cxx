#include <QDebug>

#include "start/startwindow.hxx"
#include "application.hxx"


Application::Application() {
    this->init();
    D_APP << "was successful created";
}

Application::~Application() {
    delete w_start;
}

bool Application::init() {
    w_start = new StartWindow();

    return true;
}

bool Application::run() {
    w_start->show();

    return true;
}

