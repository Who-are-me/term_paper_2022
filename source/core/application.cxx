#include <QFile>
#include <QMessageBox>
#include <QStatusBar>

#include "log.hxx"
#include "application.hxx"


Application::Application() {
    if(!this->init())
        Log::critical("Application: not create windows");

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

    // connects start window
    connect(w_start, &StartWindow::showAuth, this, &Application::moveToAuthWindow);
    connect(w_start, &StartWindow::showFilter, this, &Application::moveToFilterWindow);
    // connects auth window
    connect(w_auth, &AuthorizationWindow::backScreen, this, &Application::moveToStartWindow);
//    connect(w_auth, &AuthorizationWindow::showRegister, this, &Application::moveToRegisterWindow);
    connect(w_auth, &AuthorizationWindow::pushLogin, this, &Application::tryLogin);
    // connects register window
    connect(w_register, &RegisterWindow::backScreen, this, &Application::moveToAuthWindow);

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
//    this->w_start->setWindowTitle("Welcome");
    this->w_start->setWindowTitle("Ласкаво просимо");
    this->w_start->statusBar()->hide();

    this->w_start->setMaximumHeight(300);
    this->w_start->setMinimumHeight(300);
    this->w_start->setMaximumWidth(380);
    this->w_start->setMinimumWidth(380);
}


void Application::configureAuthWindow() {
//    this->w_auth->setWindowTitle("Authorization");
    this->w_auth->setWindowTitle("Форма авторизації");
}


void Application::configureFilterWindow() {
//    this->w_filter->setWindowTitle("Dashboard");
    this->w_filter->setWindowTitle("Панель пошуку");

    this->w_filter->statusBar()->hide();
}


void Application::configureRegisterWindow() {
//    this->w_register->setWindowTitle("Register form");
    this->w_register->setWindowTitle("Форма регістрації");
}


void Application::configureControlAllProfilesWindow() {
//    this->w_allprofiles->setWindowTitle("Admin panel");
    this->w_allprofiles->setWindowTitle("Панель адміністратора");

    this->w_allprofiles->statusBar()->hide();
}


void Application::configureControlCurrentProfilesWindow() {
//    this->w_currentprofiles->setWindowTitle("User panel");
    this->w_currentprofiles->setWindowTitle("Панель користувача");

    this->w_currentprofiles->statusBar()->hide();
}


void Application::justTest() {
    net_conector->account.init("http://localhost", "8080", "/account/create", "/account/get/", "/account/update/", "/account/delete/");
    net_conector->education.init("http://localhost", "8080", "/edu/create", "/edu/", "/edu/", "/edu/");
    net_conector->education.initAdditionalPaths("/edu" , "/edu/p/", "/edu/p/");

    // test account
//    Account acc("just test", "dovgalivka", "home", "0987654321", "justtest@gmail.com", "company", "description", "ROLE_USER", "justTest2", "justTest2", false);
//    QList<Account> acc_list;
//    Log::info("JustTest: run account create test");
//    net_conector->account.create(acc);

//    Log::info("JustTest: run account update test");
//    acc.setPip("updated!!!");
//    net_conector->account.update("justTest2", acc);

//    Log::info("JustTest: run account read test");
//    acc_list = net_conector->account.read("justTest2");

//    for(auto &x : acc_list) {
//        Log::info(x.toString());
//    }

//    Log::info("JustTest: run account delete test");
//    net_conector->account.remove("justTest2");

//    acc_list = net_conector->account.read("justTest");

//    for(auto &x : acc_list) {
//        Log::info(x.toString());
//    }
    // test education
    Education edu("test update again 13", "desc", "2022-06-06", "2023-06-06", "2", "option", "dovgalivka", "home", "0987654312", "justTest@gmail.com", "school", 2, "justTest");
    QList<Education> edu_list;

    Log::info("JustTest: run education create test");
    net_conector->education.create(edu);

    Log::info("JustTest: run education read all test");
    edu_list = net_conector->education.read();

    for(auto &x : edu_list) {
        Log::info(x.toString() + "\n");
    }

    Log::info("JustTest: run education read pagination /p/X/X test");
    // 5 and 6
    edu_list = net_conector->education.read(2, 2);

    for(auto &x : edu_list) {
        Log::info(x.toString() + "\n");
    }

    Log::info("JustTest: run education read pagination /p/X/X/XXXX test");
    // 3 and 5
    edu_list = net_conector->education.read(1, 2, "justTest");

    for(auto &x : edu_list) {
        Log::info(x.toString() + "\n");
    }

    Log::info("JustTest: run education update test");
    net_conector->education.update(13, edu);

    Log::info("JustTest: run education delete test");
    net_conector->education.remove(13);
}


void Application::tryLogin() {
    Log::info("try login");

    net_conector->login(w_auth->getLogin(), w_auth->getPassword());

    // TODO test
//    justTest();

    if(!net_conector->checkIfEnableLoggedUser()) {
        QMessageBox warning;
//        warning.setText("Wrong password or login name, please check this. 'Program will be pause for two seconds'");
//        warning.exec();
        warning.critical(nullptr, "Authorization error", "Wrong password or login name, please check this. 'Program will be pause for two seconds'");

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

