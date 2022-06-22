#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QUrl>

#include "log.hxx"
#include "accountdao.hxx"


AccountDAO::AccountDAO() {
    init();
}


AccountDAO::AccountDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    init();
}


void AccountDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool AccountDAO::initRequest(QString path) {
    Log::info("AccountDAO::initRequest URL => " + this->host + ":" + this->port + path);
    Log::info("AccountDAO::initRequest cookie => " + this->cookie);

    this->request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QVariant::fromValue(false));
    this->request.setUrl(QUrl(this->host + ":" + this->port + path));
    this->request.setRawHeader("Cookie", QByteArray::fromStdString("JSESSIONID=" + this->cookie.toStdString() + "; HttpOnly; path=/"));

    return true;
}


QNetworkReply *AccountDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


QList<Account> AccountDAO::readAll() {
    QList<Account> 	return_list;
    Account 		temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;
    QByteArray 		result;
    QJsonArray		jarr;

    this->initRequest(this->path_read);
    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jarr = QJsonDocument::fromJson(reply->readAll()).array();

    foreach(const QJsonValue &value, jarr) {
        jobj = value.toObject();

        temp_object.setPip(jobj["pip"].toString());
        temp_object.setCity(jobj["city"].toString());
        temp_object.setLocation(jobj["location"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setCompany(jobj["company"].toString());
        temp_object.setDescription(jobj["description"].toString());
        temp_object.setUsername(jobj["login_name"].toString());
        temp_object.setPassword(jobj["login_password"].toString());
        temp_object.setRole(jobj["role"].toString());

        return_list.append(temp_object);
    }

    result = reply->readAll();
    Log::info("AccountDAO::read reply: " + result);
    Log::info("AccountDAO::read status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


AccountDAO::~AccountDAO() {
    delete manager;
}


bool AccountDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    return true;
}


bool AccountDAO::setCookie(QString cookie) {
    this->cookie = cookie;

    return true;
}


// TODO test me, check status code
bool AccountDAO::create(const Account new_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QNetworkReply* 	reply;
    QByteArray 		json;
    QByteArray 		result;

    jobj["pip"] = new_object.getPip();
    jobj["city"] = new_object.getCity();
    jobj["location"] = new_object.getLocation();
    jobj["phone"] = new_object.getPhone();
    jobj["email"] = new_object.getEmail();
    jobj["company"] = new_object.getCompany();
    jobj["description"] = new_object.getDescription();
    jobj["login_name"] = new_object.getUsername();
    jobj["login_password"] = new_object.getPassword();
    jobj["role"] = new_object.getRole();
    jobj["enabled"] = new_object.getEnabled();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_create);
    reply = this->send("POST", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    result = reply->readAll();
    Log::info("AccountDAO::create reply: " + result);
    Log::info("AccountDAO::create status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());
    reply->deleteLater();

    if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray().toInt() == 404) {
        return false;
    }
    else {
        return true;
    }
}


// TODO test me, check status code
QList<Account> AccountDAO::read(const QString read_of, QString option, QString filter) {
    if(read_of.isEmpty()) {
        return this->readAll();
    }

    QList<Account> 	return_list;
    Account 		temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;
    QByteArray 		result;

    this->initRequest(this->path_read + read_of);
    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jobj = QJsonDocument::fromJson(reply->readAll()).object();

    temp_object.setPip(jobj["pip"].toString());
    temp_object.setCity(jobj["city"].toString());
    temp_object.setLocation(jobj["location"].toString());
    temp_object.setPhone(jobj["phone"].toString());
    temp_object.setEmail(jobj["email"].toString());
    temp_object.setCompany(jobj["company"].toString());
    temp_object.setDescription(jobj["description"].toString());
    temp_object.setUsername(jobj["login_name"].toString());
    temp_object.setPassword(jobj["login_password"].toString());
    temp_object.setRole(jobj["role"].toString());

    return_list.append(temp_object);

    result = reply->readAll();
    Log::info("AccountDAO::read reply: " + result);
    Log::info("AccountDAO::read status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


// TODO test me, check status code
bool AccountDAO::update(const QString update_of, const Account updated_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QByteArray 		json;
    QNetworkReply* 	reply;
    QByteArray 		result;

    jobj["pip"] = updated_object.getPip();
    jobj["city"] = updated_object.getCity();
    jobj["location"] = updated_object.getLocation();
    jobj["phone"] = updated_object.getPhone();
    jobj["email"] = updated_object.getEmail();
    jobj["company"] = updated_object.getCompany();
    jobj["description"] = updated_object.getDescription();
    jobj["login_name"] = updated_object.getUsername();
    jobj["login_password"] = updated_object.getPassword();
    jobj["role"] = updated_object.getRole();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_update + update_of);
    reply = this->send("PATCH", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    result = reply->readAll();
    Log::info("AccountDAO::update reply: " + result);
    Log::info("AccountDAO::update status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}


// TODO test me, check status code
bool AccountDAO::remove(const QString remove_of) {
    QEventLoop 		loop;
    QNetworkReply* 	reply;
    QByteArray 		result;

    this->initRequest(this->path_remove + remove_of);
    reply = this->send("DELETE", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    result = reply->readAll();
    Log::info("Account::delete reply: " + result);
    Log::info("Account::delete status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}


void AccountDAO::onCreate(QNetworkReply *reply) {
    Log::info("create reply: " + reply->readAll());
}


void AccountDAO::onRead(QNetworkReply *reply) {
    Log::info("read reply: " + reply->readAll());
}


void AccountDAO::onUpdate(QNetworkReply *reply) {
    Log::info("update reply: " + reply->readAll());
}


void AccountDAO::onRemove(QNetworkReply *reply) {
    Log::info("remove reply: " + reply->readAll());
}

