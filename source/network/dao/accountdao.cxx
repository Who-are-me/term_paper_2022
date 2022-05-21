#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QUrl>

#include "log.hxx"
#include "accountdao.hxx"


AccountDAO::AccountDAO() {
    init();
}


AccountDAO::AccountDAO(QString url, QString cookies) {
    this->url = url;
    this->cookies = cookies;
    init();
}


void AccountDAO::init() {
    this->request = new QNetworkRequest();
    this->manager = new QNetworkAccessManager();
    QObject::connect(this->manager, &QNetworkAccessManager::finished, this,
            [&](QNetworkReply *reply) {
                Log::info("Reply of create account: " + reply->readAll());
            }
    );
}


AccountDAO::~AccountDAO() {
    delete request;
    delete manager;
}


bool AccountDAO::init(QString url, QString cookies) {
    this->url = url;
    this->cookies = cookies;

    return true;
}


// DOTO test me
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
    request->setUrl(QUrl(this->url));

    manager->post(*request, json);

    return true;
}


QList<Account> AccountDAO::read(const QString read_of, QString option) {
    return QList<Account>();
}


bool AccountDAO::update(const QString update_of, const Account updated_object) {
    return true;
}


bool AccountDAO::remove(const QString remove_of) {
    return true;
}

