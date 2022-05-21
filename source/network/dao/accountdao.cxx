#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QUrl>

#include "log.hxx"
#include "accountdao.hxx"


AccountDAO::AccountDAO() {
    init();
}


AccountDAO::AccountDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {
    this->create_url = create_url;
    this->read_url = read_url;
    this->update_url = update_url;
    this->remove_url = remove_url;
    this->cookies = cookies;

    init();
}


void AccountDAO::init() {
    this->request = new QNetworkRequest();
    this->manager_create = new QNetworkAccessManager();
    this->manager_read = new QNetworkAccessManager();
    this->manager_update = new QNetworkAccessManager();
    this->manager_remove = new QNetworkAccessManager();

    connect(this->manager_create, &QNetworkAccessManager::finished, this, &AccountDAO::onCreate);
    connect(this->manager_read, &QNetworkAccessManager::finished, this, &AccountDAO::onRead);
    connect(this->manager_update, &QNetworkAccessManager::finished, this, &AccountDAO::onUpdate);
    connect(this->manager_remove, &QNetworkAccessManager::finished, this, &AccountDAO::onRemove);
}


AccountDAO::~AccountDAO() {
    delete request;
    delete manager_create;
    delete manager_read;
    delete manager_update;
    delete manager_remove;
}


bool AccountDAO::init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {
    this->create_url = create_url;
    this->read_url = read_url;
    this->update_url = update_url;
    this->remove_url = remove_url;
    this->cookies = cookies;

    return true;
}


// TODO test me, check status code
bool AccountDAO::create(const Account new_object) {
    QJsonObject jobj;

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

    QJsonDocument jdoc(jobj);
    QByteArray json = jdoc.toJson();
    QString cookies_str = "JSESSIONID=" + this->cookies + "; HttpOnly; path=/";

    request->setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request->setRawHeader("Cookie", cookies_str.toUtf8());
    request->setUrl(QUrl(this->create_url));

    manager_create->post(*request, json);

    return true;
}


// TODO test me, check status code
QList<Account> AccountDAO::read(const QString read_of, QString option) {
    QString 		cookies_str;
    QString			query_url;
    QList<Account> 	return_list;
    Account 		temp_object;
    QJsonObject		jobj;

    cookies_str = "JSESSIONID=" + this->cookies + "; HttpOnly; path=/";
    jobj = QJsonDocument::fromJson(manager_read->get(*request)->readAll()).object();
    query_url = this->read_url + "/" + read_of;

    request->setRawHeader("Cookie", cookies_str.toUtf8());
    request->setUrl(QUrl(query_url));


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

    return return_list;
}


// TODO test me, check status code
bool AccountDAO::update(const QString update_of, const Account updated_object) {
    QJsonObject jobj;

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
    QByteArray json = jdoc.toJson();
    QString cookies_str = "JSESSIONID=" + this->cookies + "; HttpOnly; path=/";

    request->setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request->setRawHeader("Cookie", cookies_str.toUtf8());
    request->setUrl(QUrl(this->update_url));

    manager_update->sendCustomRequest(*request, "PATCH", json);

    return true;
}


// TODO test me, check status code
bool AccountDAO::remove(const QString remove_of) {
    QString cookies_str = "JSESSIONID=" + this->cookies + "; HttpOnly; path=/";
    QString query_url = this->remove_url + "/" + remove_of;

    request->setRawHeader("Cookie", cookies_str.toUtf8());
    request->setUrl(QUrl(query_url));

    manager_remove->sendCustomRequest(*request, "DELETE", "");

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

