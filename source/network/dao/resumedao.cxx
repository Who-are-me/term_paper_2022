#include "log.hxx"
#include "resumedao.hxx"


ResumeDAO::ResumeDAO() {
    init();
}


ResumeDAO::ResumeDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    init();
}


ResumeDAO::~ResumeDAO() {
    delete manager;
}


void ResumeDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool ResumeDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    return true;
}


bool ResumeDAO::initAdditionalPaths(QString path_read_all, QString path_read_pag, QString path_read_pag_by_username) {
    this->path_read_all = path_read_all;
    this->path_read_pag = path_read_pag;
    this->path_read_pag_by_username = path_read_pag_by_username;

    return true;
}


bool ResumeDAO::setCookie(QString cookie) {
    this->cookie = cookie;

    return true;
}


QList<Resume> ResumeDAO::readAll() {
    QList<Resume> 	return_list;
    Resume 			temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;
    QJsonArray		jarr;

    this->initRequest(this->path_read_all);
    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jarr = QJsonDocument::fromJson(reply->readAll()).array();

    foreach(const QJsonValue &value, jarr) {
        jobj = value.toObject();

        temp_object.setId(jobj["id"].toInt());
        temp_object.setPip(jobj["pip"].toString());
        temp_object.setSoft_skills(jobj["soft_skills"].toString());
        temp_object.setHard_skills(jobj["hard_skills"].toString());
        temp_object.setLanguage(jobj["language"].toString());
        temp_object.setHobbies(jobj["hobbies"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setSkype(jobj["skype"].toString());
        temp_object.setQualification(jobj["qualifications"].toString());
        temp_object.setAbout_myself(jobj["about_myself"].toString());
        temp_object.setOwner(jobj["owner"].toString());

        return_list.append(temp_object);
    }

    Log::info("ResumeDAO::readAll status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


// TODO maybe remove this
QList<Resume> ResumeDAO::readById(const int id) {
    return QList<Resume>();
}


QList<Resume> ResumeDAO::readWithPagination(const int page, const int item_in_page, QString username) {
    QList<Resume> 	return_list;
    Resume 			temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;
    QJsonArray		jarr;

    if(username.isNull()) {
        this->initRequest(this->path_read_pag_by_username + QString::number(page) + "/" + QString::number(item_in_page));
    }
    else {
        this->initRequest(this->path_read_pag_by_username + QString::number(page) + "/" + QString::number(item_in_page) + "/" + username);
    }

    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jarr = QJsonDocument::fromJson(reply->readAll()).array();

    foreach(const QJsonValue &value, jarr) {
        jobj = value.toObject();

        temp_object.setId(jobj["id"].toInt());
        temp_object.setPip(jobj["pip"].toString());
        temp_object.setSoft_skills(jobj["soft_skills"].toString());
        temp_object.setHard_skills(jobj["hard_skills"].toString());
        temp_object.setLanguage(jobj["language"].toString());
        temp_object.setHobbies(jobj["hobbies"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setSkype(jobj["skype"].toString());
        temp_object.setQualification(jobj["qualifications"].toString());
        temp_object.setAbout_myself(jobj["about_myself"].toString());
        temp_object.setOwner(jobj["owner"].toString());

        return_list.append(temp_object);
    }

    Log::info("ResumeDAO::read with pagination status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


bool ResumeDAO::initRequest(QString path) {
    Log::info("ResumeDAO::initRequest URL => " + this->host + ":" + this->port + path);
    Log::info("ResumeDAO::initRequest cookie => " + this->cookie);

    this->request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QVariant::fromValue(false));
    this->request.setUrl(QUrl(this->host + ":" + this->port + path));
    this->request.setRawHeader("Cookie", QByteArray::fromStdString("JSESSIONID=" + this->cookie.toStdString() + "; HttpOnly; path=/"));

    return true;
}


QNetworkReply *ResumeDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


bool ResumeDAO::create(const Resume new_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QNetworkReply* 	reply;
    QByteArray 		json;

    jobj["pip"] = new_object.getPip();
    jobj["soft_skills"] = new_object.getSoft_skills();
    jobj["hard_skills"] = new_object.getHard_skills();
    jobj["language"] = new_object.getLanguage();
    jobj["hobbies"] = new_object.getHobbies();
    jobj["phone"] = new_object.getPhone();
    jobj["email"] = new_object.getEmail();
    jobj["skype"] = new_object.getSkype();
    jobj["qualifications"] = new_object.getQualification();
    jobj["about_myself"] = new_object.getAbout_myself();
    jobj["owner"] = new_object.getOwner();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_create);
    reply = this->send("POST", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("ResumeDAO::create status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());
    reply->deleteLater();

    return true;
}


QList<Resume> ResumeDAO::read(const int read_of, int option, QString filter) {
    if(read_of == -1) {
        return this->readAll();
    }
    else if(option != -1) {
        return this->readWithPagination(read_of, option, filter);
    }

    QList<Resume> 	return_list;
    Resume 			temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;

    this->initRequest(this->path_read + QString::number(read_of));
    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jobj = QJsonDocument::fromJson(reply->readAll()).object();

    temp_object.setId(jobj["id"].toInt());
    temp_object.setPip(jobj["pip"].toString());
    temp_object.setSoft_skills(jobj["soft_skills"].toString());
    temp_object.setHard_skills(jobj["hard_skills"].toString());
    temp_object.setLanguage(jobj["language"].toString());
    temp_object.setHobbies(jobj["hobbies"].toString());
    temp_object.setPhone(jobj["phone"].toString());
    temp_object.setEmail(jobj["email"].toString());
    temp_object.setSkype(jobj["skype"].toString());
    temp_object.setQualification(jobj["qualifications"].toString());
    temp_object.setAbout_myself(jobj["about_myself"].toString());
    temp_object.setOwner(jobj["owner"].toString());

    return_list.append(temp_object);

    Log::info("ResumeDAO::read status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


bool ResumeDAO::update(const int update_of, const Resume updated_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QByteArray 		json;
    QNetworkReply* 	reply;

    jobj["pip"] = updated_object.getPip();
    jobj["soft_skills"] = updated_object.getSoft_skills();
    jobj["hard_skills"] = updated_object.getHard_skills();
    jobj["language"] = updated_object.getLanguage();
    jobj["hobbies"] = updated_object.getHobbies();
    jobj["phone"] = updated_object.getPhone();
    jobj["email"] = updated_object.getEmail();
    jobj["skype"] = updated_object.getSkype();
    jobj["qualifications"] = updated_object.getQualification();
    jobj["about_myself"] = updated_object.getAbout_myself();
    jobj["owner"] = updated_object.getOwner();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_update + QString::number(update_of));
    reply = this->send("PATCH", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("ResumeDAO::update status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}


bool ResumeDAO::remove(const int remove_of) {
    QEventLoop 		loop;
    QNetworkReply* 	reply;

    this->initRequest(this->path_remove + QString::number(remove_of));
    reply = this->send("DELETE", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("ResumeDAO::delete status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}
