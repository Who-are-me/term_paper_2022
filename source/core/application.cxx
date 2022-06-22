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

    delete w_account_create;
    delete w_account_read;
    delete w_account_update;
    delete w_account_delete;

    delete w_education_create;
    delete w_education_read;
    delete w_education_update;
    delete w_education_delete;

    delete w_resume_create;
    delete w_resume_read;
    delete w_resume_update;
    delete w_resume_delete;

    delete w_vacancy_create;
    delete w_vacancy_read;
    delete w_vacancy_update;
    delete w_vacancy_delete;
}


bool Application::init() {
    net_conector = new Conector();
    w_start = new StartWindow();
    w_auth = new AuthorizationWindow();
    w_filter = new FilterWindow();
    w_register = new RegisterWindow();
    w_allprofiles = new ControlAllProfilesWindow();
    w_currentprofiles = new ControlCurrentProfilesWindow();

    w_account_create = new AccountCreateWindow();
    w_account_read = new AccountReadWindow();
    w_account_update = new AccountUpdateWindow();
    w_account_delete = new AccountDeleteWindow();

    w_education_create = new EducationCreateWindow();
    w_education_read = new EducationReadWindow();
    w_education_update = new EducationUpdateWindow();
    w_education_delete = new EducationDeleteWindow();

    w_resume_create = new ResumeCreateWindow();
    w_resume_read = new ResumeReadWindow();
    w_resume_update = new ResumeUpdateWindow();
    w_resume_delete = new ResumeDeleteWindow();

    w_vacancy_create = new VacancyCreateWindow();
    w_vacancy_read = new VacancyReadWindow();
    w_vacancy_update = new VacancyUpdateWindow();
    w_vacancy_delete = new VacancyDeleteWindow();

    // connects start window
    connect(w_start, &StartWindow::showAuth, this, &Application::moveToAuthWindow);
    connect(w_start, &StartWindow::showFilter, this, &Application::moveToFilterWindow);
    // connects auth window
    connect(w_auth, &AuthorizationWindow::backScreen, this, &Application::moveToStartWindow);
    connect(w_auth, &AuthorizationWindow::pushLogin, this, &Application::tryLogin);
//    connect(w_auth, &AuthorizationWindow::showRegister, this, &Application::moveToRegisterWindow);
    // connects register window
    connect(w_register, &RegisterWindow::backScreen, this, &Application::moveToAuthWindow);
    // connects admin panel window
    connect(w_allprofiles, &ControlAllProfilesWindow::createAccount, this, &Application::showAccountCreateWindow);
//    connect(w_allprofiles, &ControlAllProfilesWindow::readAccount, this, &Application::showAccountReadWindow);
    connect(w_allprofiles, &ControlAllProfilesWindow::readAccount, this, &Application::accountRead);
//    connect(w_allprofiles, &ControlAllProfilesWindow::updateAccount, this, &Application::showAccountUpdateWindow);
    connect(w_allprofiles, &ControlAllProfilesWindow::updateAccount, this, &Application::accountUpdate);
    connect(w_allprofiles, &ControlAllProfilesWindow::deleteAccount, this, &Application::showAccountDeleteWindow);
//    connect(w_allprofiles, &ControlAllProfilesWindow::deleteAccount, this, &Application::accountDelete);

    connect(w_allprofiles, &ControlAllProfilesWindow::createVacancy, this, &Application::showVacancyCreateWindow);
    connect(w_allprofiles, &ControlAllProfilesWindow::readVacancy, this, &Application::vacancyRead);
    connect(w_allprofiles, &ControlAllProfilesWindow::updateVacancy, this, &Application::vacancyUpdate);
    connect(w_allprofiles, &ControlAllProfilesWindow::deleteVacancy, this, &Application::showVacancyDeleteWindow);

    connect(w_allprofiles, &ControlAllProfilesWindow::backScreen, this, &Application::moveToStartWindow);

    connect(w_account_create, &AccountCreateWindow::pushOk, this, &Application::accountCreate);
    connect(w_account_update, &AccountUpdateWindow::pushOk, this, &Application::accountUpdateData);
    connect(w_account_delete, &AccountDeleteWindow::pushOk, this, &Application::accountDelete);

    connect(w_vacancy_create, &VacancyCreateWindow::pushOk, this, &Application::vacancyCreate);
    connect(w_vacancy_update, &VacancyUpdateWindow::pushOk, this, &Application::vacancyUpdateData);
    connect(w_vacancy_delete, &VacancyDeleteWindow::pushOk, this, &Application::vacancyDelete);

    // init path to servise page
    net_conector->account.init("http://localhost", "8080", "/account/create", "/account/get/", "/account/update/", "/account/delete/");
    net_conector->education.init("http://localhost", "8080", "/edu/create", "/edu/", "/edu/", "/edu/");
    net_conector->education.initAdditionalPaths("/edu" , "/edu/p/", "/edu/p/");
    net_conector->resume.init("http://localhost", "8080", "/resume/create", "/resume/", "/resume/", "/resume/");
    net_conector->resume.initAdditionalPaths("/resume" , "/resume/p/", "/resume/p/");
    net_conector->vacancy.init("http://localhost", "8080", "/vacancy/create", "/vacancy/", "/vacancy/", "/vacancy/");
    net_conector->vacancy.initAdditionalPaths("/vacancy" , "/vacancy/p/", "/vacancy/p/");

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


void Application::configureAccountCreateWindow() {
    this->w_account_create->setWindowTitle("Створення користувача");
}


void Application::configureAccountReadWindow() {
    this->w_account_read->setWindowTitle("Дані користувача");
}


void Application::configureAccountUpdateWindow() {
    this->w_account_update->setWindowTitle("Оновлення даних користувача");
}


void Application::configureAccountDeleteWindow() {
    this->w_account_delete->setWindowTitle("Видалення користувача");
    w_account_delete->setLogin(w_allprofiles->getCurrentLogin());
    qDebug() << "Login: " << w_allprofiles->getCurrentLogin();
    w_account_delete->update();
}

void Application::configureEducationCreateWindow()
{

}

void Application::configureEducationReadWindow()
{

}

void Application::configureEducationUpdateWindow()
{

}

void Application::configureEducationDeleteWindow()
{

}

void Application::configureResumeCreateWindow()
{

}

void Application::configureResumeReadWindow()
{

}

void Application::configureResumeUpdateWindow()
{

}

void Application::configureResumeDeleteWindow()
{

}


void Application::configureVacancyCreateWindow() {
    w_vacancy_create->setWindowTitle("Форма створення вакансії");
}


void Application::configureVacancyReadWindow() {
    w_vacancy_read->setWindowTitle("Дані вакансії");
}


void Application::configureVacancyUpdateWindow() {
    w_vacancy_update->setWindowTitle("Оновлення даних вакансії");
}


void Application::configureVacancyDeleteWindow() {
    w_vacancy_delete->setWindowTitle("Видалення вакансії");
    w_vacancy_delete->setVacancyId(w_allprofiles->getCurrentVacancyId());
    qDebug() << "ID: " << w_allprofiles->getCurrentVacancyId();
    w_vacancy_delete->update();
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
    w_allprofiles->updateTables(
                this->net_conector->account.read(),
                this->net_conector->education.read(),
                this->net_conector->resume.read(),
                this->net_conector->vacancy.read());
    w_allprofiles->show();
}


void Application::moveToControlCurrentProfilesWindow() {
    this->closeAllWindowExcept("w_currentprofiles");

    configureControlCurrentProfilesWindow();
    w_currentprofiles->show();
}


void Application::showAccountCreateWindow() {
    configureAccountCreateWindow();
    w_account_create->exec();
}


void Application::showAccountReadWindow() {
    configureAccountReadWindow();
    w_account_read->show();
}


void Application::showAccountUpdateWindow() {
    configureAccountUpdateWindow();
    w_account_update->exec();
}


void Application::showAccountDeleteWindow() {
    configureAccountDeleteWindow();
    w_account_delete->exec();
}

void Application::showEducationCreateWindow()
{

}

void Application::showEducationReadWindow()
{

}

void Application::showEducationUpdateWindow()
{

}

void Application::showEducationDeleteWindow()
{

}

void Application::showResumeCreateWindow()
{

}

void Application::showResumeReadWindow()
{

}

void Application::showResumeUpdateWindow()
{

}

void Application::showResumeDeleteWindow()
{

}


void Application::showVacancyCreateWindow() {
    this->configureVacancyCreateWindow();
    this->w_vacancy_create->exec();
}


void Application::showVacancyReadWindow() {
    this->configureVacancyReadWindow();
    this->w_vacancy_read->show();
}


void Application::showVacancyUpdateWindow() {
    this->configureVacancyUpdateWindow();
    this->w_vacancy_update->exec();
}


void Application::showVacancyDeleteWindow() {
    this->configureVacancyDeleteWindow();
    this->w_vacancy_delete->exec();
}


void Application::accountCreate() {
    Account account = w_account_create->getObject();
    QMessageBox warning;

    if(this->net_conector->account.create(account)) {
        warning.information(nullptr, "Successful", "Акаунт був створений!");
        w_allprofiles->updateAccountTables(this->net_conector->account.read());
    }
    else {
        warning.critical(nullptr, "Failed", "Акаунт НЕ бав створений!");
    }
}


void Application::accountRead() {
    w_account_read->setObject(this->net_conector->account.read(w_allprofiles->getCurrentLogin()).first());
    w_account_read->update();
    showAccountReadWindow();
}


void Application::accountUpdate() {
    w_account_update->setObject(this->net_conector->account.read(w_allprofiles->getCurrentLogin()).first());
    w_account_update->update();
    showAccountUpdateWindow();
}


void Application::accountUpdateData() {
    Account update_account = w_account_update->getObject();
    QMessageBox warning;

    if(this->net_conector->account.update(w_allprofiles->getCurrentLogin(), update_account)) {
        warning.information(nullptr, "Successful", "Акаунт був оновлений!");
        w_allprofiles->updateAccountTables(this->net_conector->account.read());
    }
    else {
        warning.critical(nullptr, "Failed", "Акаунт НЕ бав оновлений!");
    }
}


void Application::accountDelete() {
    this->net_conector->account.remove(w_allprofiles->getCurrentLogin());
    w_allprofiles->updateAccountTables(this->net_conector->account.read());
}


void Application::vacancyCreate() {
    Vacancy vacancy = w_vacancy_create->getObject();
    QMessageBox warning;

    vacancy.setOwner(this->net_conector->getLoggedUser());

    if(this->net_conector->vacancy.create(vacancy)) {
        warning.information(nullptr, "Successful", "Вакансія була створена!");
        w_allprofiles->updateVacancyTables(this->net_conector->vacancy.read());
    }
    else {
        warning.critical(nullptr, "Failed", "Вакансія НЕ була створена!");
    }
}


void Application::vacancyRead() {
    w_vacancy_read->setObject(this->net_conector->vacancy.read(w_allprofiles->getCurrentVacancyId()).first());
    w_vacancy_read->update();
    showVacancyReadWindow();
}


void Application::vacancyUpdate() {
    w_vacancy_update->setObject(this->net_conector->vacancy.read(w_allprofiles->getCurrentVacancyId()).first());
    w_vacancy_update->update();
    showVacancyUpdateWindow();
}


void Application::vacancyUpdateData() {
    Vacancy update_vacancy = w_vacancy_update->getObject();
    QMessageBox warning;

    if(this->net_conector->vacancy.update(w_allprofiles->getCurrentVacancyId(), update_vacancy)) {
        warning.information(nullptr, "Successful", "Вакансія була оновлена!");
        w_allprofiles->updateVacancyTables(this->net_conector->vacancy.read());
    }
    else {
        warning.critical(nullptr, "Failed", "Вакансія НЕ була оновлена!");
    }
}


void Application::vacancyDelete() {
    this->net_conector->vacancy.remove(w_allprofiles->getCurrentVacancyId());
    w_allprofiles->updateVacancyTables(this->net_conector->vacancy.read());
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

