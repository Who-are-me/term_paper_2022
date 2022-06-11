#include "log.hxx"
#include "conector.hxx"


Conector::Conector() {
    // TODO load this value from file or database
    setConnectHost("http://localhost");
    setConnectPort("8080");
    setConnectPathToLogin("/login");

    setAccountPathToGet("/account/get/");
    setAccountPathToTestUserConnect("/user");

    net_manager = new QNetworkAccessManager();

//    this->account.init("", "", "", "", "");

    // TODO maybe remove this
    // connect(net_manager, &QNetworkAccessManager::finished, this, &Conector::onCheckIfEnableLoggedUser);
}


Conector::~Conector() {
    delete net_manager;
}

// ----------------------------------------------------------------

const QString &Conector::getConnectHost() const {
    return this->connect_host;
}


void Conector::setConnectHost(const QString &new_connect_host) {
    this->connect_host = new_connect_host;
}

// ----------------------------------------------------------------

const QString &Conector::getConnectPathToLogin() const {
    return this->connect_path_to_login;
}


void Conector::setConnectPathToLogin(const QString &new_connect_path_to_login) {
    this->connect_path_to_login = new_connect_path_to_login;
}

// ----------------------------------------------------------------

const QString &Conector::getConnectPort() const {
    return this->connect_port;
}


void Conector::setConnectPort(const QString &new_connect_port) {
    this->connect_port = new_connect_port;
}

// ----------------------------------------------------------------

const QString &Conector::getLoggedUser() const {
    return logged_user;
}


void Conector::setLoggedUser(const QString &newLogged_user) {
    this->logged_user = newLogged_user;
}

// ----------------------------------------------------------------

const QString &Conector::getIsLoggedUser() const {
    return logged_user;
}


void Conector::setIsLoggedUser(const QString &new_data) {
    this->logged_user = new_data;
}

// ----------------------------------------------------------------

const bool &Conector::getIsAdmin() const {
    return is_admin;
}


void Conector::setIsAdmin(bool &new_data) {
    this->is_admin = new_data;
}

// ----------------------------------------------------------------

// TODO maybe delete this
void Conector::loginInServer() {
    // TODO implement me
}

// ----------------------------------------------------------------

const QString &Conector::getAccountPathToGet() const {
    return account_path_to_get;
}


void Conector::setAccountPathToGet(const QString &new_account_path_to_get) {
    account_path_to_get = new_account_path_to_get;
}

// ----------------------------------------------------------------

const QString &Conector::getAccountPathToTestUserConnect() const {
    return account_path_to_test_user_connect;
}


void Conector::setAccountPathToTestUserConnect(const QString &new_account_path_to_test_user_connect) {
    account_path_to_test_user_connect = new_account_path_to_test_user_connect;
}

// ----------------------------------------------------------------

bool Conector::checkIsAdmin() {
    this->initRequest(this->getConnectHost(), this->getConnectPort(), this->getAccountPathToGet() + this->getLoggedUser());

    Log::info(this->getAccountPathToGet() + this->getLoggedUser());

    QEventLoop loop;
    QNetworkReply* temp_reply = this->send("GET", net_manager, net_request, "");
    connect(temp_reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // wait for end requesting
    loop.exec();

    QByteArray result = temp_reply->readAll();
    Log::info("CheckIsAdmin reply: " + temp_reply->readAll());
    Log::info("Status code: " + temp_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());
    temp_reply->deleteLater();
    QJsonDocument jd = QJsonDocument::fromJson(result);
    QJsonObject jobj = jd.object();

    if(jobj["role"] != "ROLE_ADMIN") {
        Log::info("User isn't admin");
        return false;
    }
    else {
        Log::info("User is admin");
        return true;
    }
}


bool Conector::initRequest(QString host, QString port, QString path) {
    this->net_request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QVariant::fromValue(false));
    this->net_request.setUrl(QUrl(host + ":" + port + path));
    this->net_request.setRawHeader("Cookie", QByteArray::fromStdString("JSESSIONID=" + this->getCookie().toStdString() + "; HttpOnly; path=/"));

    return true;
}


QNetworkReply* Conector::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


// DOTO make production version
bool Conector::login(QString username, QString password) {
    QString command = "curl --silent --output /dev/null --cookie-jar - -L POST " + this->connect_host + ":" + this->connect_port + this->connect_path_to_login + " -d \"username=" + username + "&password=" + password + "\"";

    Log::info("Conector command: " + command);

    this->setCommand(command);

    if(this->tryConnect()) {
        this->setLoggedUser(username);
        this->checkIsAdmin();
        this->account.setCookie(this->getCookie());
        this->education.setCookie(this->getCookie());
        this->resume.setCookie(this->getCookie());
        this->vacancy.setCookie(this->getCookie());

        return true;
    }
    else {
        return false;
    }
}


bool Conector::checkIfEnableLoggedUser() {
    this->initRequest(this->getConnectHost(), this->getConnectPort(), this->getAccountPathToTestUserConnect());

    QEventLoop loop;
    QNetworkReply* temp_reply =  this->send("GET", net_manager, net_request, "");
    connect(temp_reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // wait for end requesting
    loop.exec();

    int status_code = temp_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray().toInt();
    Log::info("Status code: " + QString::number(status_code));
    temp_reply->deleteLater();

    if(status_code == 202) {
        return true;
    }
    else {
        return false;
    }
}


// TODO maybe remove this slot
void Conector::onCheckIfEnableLoggedUser(QNetworkReply *reply) {
    int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray().toInt();
    Log::info("Status code: " + QString::number(status_code));

    reply->deleteLater();
}
