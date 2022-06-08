#include "log.hxx"
#include "conector.hxx"


Conector::Conector() {
    setConnectHost("http://localhost");
    setConnectPort("8080");
    setConnectPathToLogin("/login");

    net_manager = new QNetworkAccessManager();

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

const QString &Conector::getIsAdmin() const {
    return logged_user;
}


void Conector::setIsAdmin(const QString &new_data) {
    this->logged_user = new_data;
}

// ----------------------------------------------------------------

void Conector::loginInServer() {
    // TODO implement me
}


// DOTO make production version
bool Conector::login(QString username, QString password) {
    QString command = "curl --silent --output /dev/null --cookie-jar - -L POST " + this->connect_host + ":" + this->connect_port + this->connect_path_to_login + " -d \"username=" + username + "&password=" + password + "\"";

    Log::info("Conector command: " + command);

    this->setCommand(command);

    if(this->tryConnect()) {
        this->setLoggedUser(username);

        return true;
    }
    else {
        return false;
    }
}


// TODO check it's simple user or admin
bool Conector::checkIfEnableLoggedUser() {
    this->net_request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QVariant::fromValue(false));
    QString cookie_str = "JSESSIONID=" + this->getCookie() + "; HttpOnly; path=/";
    net_request.setRawHeader("Cookie", cookie_str.toUtf8());
    net_request.setUrl(QUrl(this->getConnectHost() + ":" + this->getConnectPort() + "/user"));

    QEventLoop loop;
    QNetworkReply* temp_reply = net_manager->get(net_request);
    connect(temp_reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // wait for end
    loop.exec();

    int status_code = temp_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray().toInt();
    Log::info("Status code: " + QString::number(status_code));

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
