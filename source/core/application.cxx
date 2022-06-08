#include <QFile>
#include <QMessageBox>

#include "log.hxx"
#include "application.hxx"


Application::Application() {
    if(!this->init())
        Log::critical("Application: not create windows");

    // TODO implement me
    // EXAMPLE => connect(w_start, &StartWindow::XXXXXX, this, &Application::moveToXXXXXX);
    connect(w_start, &StartWindow::showAuth, this, &Application::moveToAuthWindow);
    connect(w_start, &StartWindow::showFilter, this, &Application::moveToFilterWindow);

    connect(w_auth, &AuthorizationWindow::backScreen, this, &Application::moveToStartWindow);
    connect(w_auth, &AuthorizationWindow::showRegister, this, &Application::moveToRegisterWindow);

    connect(w_auth, &AuthorizationWindow::pushLogin, this, &Application::tryLogin);

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

    // FIXME check if seccessful login, implement for failed authorization
    // Log::massert(conector->login(w_auth->getLogin(), w_auth->getPassword()), "not can login");

    // TODO check if auth user is admin
    if(false) {
        moveToControlAllProfilesWindow();
    }
    else {
        moveToControlCurrentProfilesWindow();
    }
}


void Application::moveToStartWindow() {
    if(w_auth->isVisible())
        w_auth->close();

    if(w_filter->isVisible())
        w_filter->close();

    if(w_register->isVisible())
        w_register->close();

    if(w_allprofiles->isVisible())
        w_allprofiles->close();

    if(w_currentprofiles->isVisible())
        w_currentprofiles->close();

    w_start->show();
}


void Application::moveToAuthWindow() {
    if(w_start->isVisible())
        w_start->close();

    if(w_filter->isVisible())
        w_filter->close();

    if(w_register->isVisible())
        w_register->close();

    if(w_allprofiles->isVisible())
        w_allprofiles->close();

    if(w_currentprofiles->isVisible())
        w_currentprofiles->close();

    w_auth->show();
}


void Application::moveToFilterWindow() {
    if(w_auth->isVisible())
        w_auth->close();

    if(w_start->isVisible())
        w_start->close();

    if(w_register->isVisible())
        w_register->close();

    if(w_allprofiles->isVisible())
        w_allprofiles->close();

    if(w_currentprofiles->isVisible())
        w_currentprofiles->close();

    w_filter->show();
}

void Application::moveToRegisterWindow() {
    if(w_auth->isVisible())
        w_auth->close();

    if(w_start->isVisible())
        w_start->close();

    if(w_filter->isVisible())
        w_filter->close();

    if(w_allprofiles->isVisible())
        w_allprofiles->close();

    if(w_currentprofiles->isVisible())
        w_currentprofiles->close();

    w_register->show();
}


void Application::moveToControlAllProfilesWindow() {
    if(w_auth->isVisible())
        w_auth->close();

    if(w_filter->isVisible())
        w_filter->close();

    if(w_register->isVisible())
        w_register->close();

    if(w_currentprofiles->isVisible())
        w_currentprofiles->close();

    if(w_start->isVisible())
        w_start->close();

    w_allprofiles->show();
}


void Application::moveToControlCurrentProfilesWindow() {
    if(w_auth->isVisible())
        w_auth->close();

    if(w_filter->isVisible())
        w_filter->close();

    if(w_register->isVisible())
        w_register->close();

    if(w_allprofiles->isVisible())
        w_allprofiles->close();

    if(w_start->isVisible())
        w_start->close();

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

