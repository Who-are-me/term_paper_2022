#include "log.hxx"
#include "conector.hxx"


Conector::Conector() {
    setConnectHost("http://localhost");
    setConnectPort("8080");
    setConnectPathToLogin("/login");
}


Conector::~Conector() { }


const QString &Conector::getConnectHost() const {
    return this->connect_host;
}


void Conector::setConnectHost(const QString &new_connect_host) {
    this->connect_host = new_connect_host;
}


const QString &Conector::getConnectPathToLogin() const {
    return this->connect_path_to_login;
}


void Conector::setConnectPathToLogin(const QString &new_connect_path_to_login) {
    this->connect_path_to_login = new_connect_path_to_login;
}


const QString &Conector::getConnectPort() const {
    return this->connect_port;
}


void Conector::setConnectPort(const QString &new_connect_port) {
    this->connect_port = new_connect_port;
}


void Conector::loginInServer() {
    // TODO implement me
}


bool Conector::login(QString username, QString password) {
    // DOTO make production version
    QString command = "curl --silent --output /dev/null --cookie-jar - -L POST " + this->connect_host + ":" + this->connect_port + this->connect_path_to_login + " -d \"username=" + username + "&password=" + password + "\"";
    Log::info("Conector command: " + command);
    this->setCommand(command);

    if(this->isExistsCookie()) {
        return true;
    }
    else {
        return false;
    }
}



