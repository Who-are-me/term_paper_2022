#include <QFile>
#include <QMessageBox>

#include "log.hxx"
#include "application.hxx"


Application::Application() {
    if(!this->init())
        Log::critical("Application: not create windows");

    // TODO implement me
    // EXAMPLE => connect(w_start, &StartWindow::XXXXXX, this, &Application::moveToXXXXXX);
    // connects start window
    connect(w_start, &StartWindow::showAuth, this, &Application::moveToAuthWindow);
    connect(w_start, &StartWindow::showFilter, this, &Application::moveToFilterWindow);
    // connects auth window
    connect(w_auth, &AuthorizationWindow::backScreen, this, &Application::moveToStartWindow);
    connect(w_auth, &AuthorizationWindow::showRegister, this, &Application::moveToRegisterWindow);
    connect(w_auth, &AuthorizationWindow::pushLogin, this, &Application::tryLogin);
    // connects register window
    connect(w_register, &RegisterWindow::backScreen, this, &Application::moveToAuthWindow);

    Log::info("Appication: was successful created");
}


Application::~Application() {
    delete net_conector;
    delete w_start;
    delete w_auth;
    delete w_filter;
    delete w_register;
    delete w_allprofiles;
    delete w_currentprofiles;
}


bool Application::init() {
    net_conector = new Conector();
    w_start = new StartWindow();
    w_auth = new AuthorizationWindow();
    w_filter = new FilterWindow();
    w_register = new RegisterWindow();
    w_allprofiles = new ControlAllProfilesWindow();
    w_currentprofiles = new ControlCurrentProfilesWindow();

    return true;
}


bool Application::closeAllWindowExcept(QString name_window) {
    if(name_window != "w_start")
        if(w_start->isVisible())
            w_start->close();

    if(name_window != "w_auth")
        if(w_auth->isVisible())
            w_auth->close();

    if(name_window != "w_filter")
        if(w_filter->isVisible())
            w_filter->close();

    if(name_window != "w_register")
        if(w_register->isVisible())
            w_register->close();

    if(name_window != "w_allprofiles")
        if(w_allprofiles->isVisible())
            w_allprofiles->close();

    if(name_window != "w_currentprofiles")
        if(w_currentprofiles->isVisible())
            w_currentprofiles->close();

    return true;
}


void Application::configureStartWindow() {
    this->w_start->setWindowTitle("Welcome");
}


void Application::configureAuthWindow() {
    this->w_auth->setWindowTitle("Authorization");
}


void Application::configureFilterWindow() {
    this->w_filter->setWindowTitle("Dashboard");
}


void Application::configureRegisterWindow() {
    this->w_register->setWindowTitle("Register form");
}


void Application::configureControlAllProfilesWindow() {
    this->w_allprofiles->setWindowTitle("Admin panel");
}


void Application::configureControlCurrentProfilesWindow() {
    this->w_currentprofiles->setWindowTitle("User panel");
}


void Application::justTest() {
    Log::info("JustTest: login => " + w_auth->getLogin() + ", password => " + w_auth->getPassword());
}


void Application::tryLogin() {
    Log::info("try login");

    net_conector->login(w_auth->getLogin(), w_auth->getPassword());

    if(!net_conector->checkIfEnableLoggedUser()) {
        QMessageBox warning;
        warning.setText("Wrong password or login name, please check this. 'Program will be pause for two seconds'");
        warning.exec();

        QObject().thread()->usleep(1000 * 1000 * 2);

        return;
    }

    if(net_conector->getIsAdmin()) {
        moveToControlAllProfilesWindow();
    }
    else {
        moveToControlCurrentProfilesWindow();
    }
}


void Application::moveToStartWindow() {
    this->closeAllWindowExcept("w_start");

    this->configureStartWindow();
    w_start->show();
}


void Application::moveToAuthWindow() {
    this->closeAllWindowExcept("w_auth");

    configureAuthWindow();
    w_auth->show();
}


void Application::moveToFilterWindow() {
    this->closeAllWindowExcept("w_filter");

    configureFilterWindow();
    w_filter->show();
}


void Application::moveToRegisterWindow() {
    this->closeAllWindowExcept("w_register");

    configureRegisterWindow();
    w_register->show();
}


void Application::moveToControlAllProfilesWindow() {
    this->closeAllWindowExcept("w_allprofiles");

    configureControlAllProfilesWindow();
    w_allprofiles->show();
}


void Application::moveToControlCurrentProfilesWindow() {
    this->closeAllWindowExcept("w_currentprofiles");

    configureControlCurrentProfilesWindow();
    w_currentprofiles->show();
}


bool Application::run() {
    moveToStartWindow();

    return true;
}


QString Application::loadStyle(QString path) {
    QFile file_style(path);
    file_style.open(QFile::ReadOnly);

    return QLatin1String(file_style.readAll());
}

