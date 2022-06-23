#include "log.hxx"
#include "educationdao.hxx"


EducationDAO::EducationDAO() {
    init();
}


EducationDAO::EducationDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    init();
}


EducationDAO::~EducationDAO() {
    delete manager;
}


void EducationDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool EducationDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    return true;
}


bool EducationDAO::initAdditionalPaths(QString path_read_all, QString path_read_pag, QString path_read_pag_by_username) {
    this->path_read_all = path_read_all;
    this->path_read_pag = path_read_pag;
    this->path_read_pag_by_username = path_read_pag_by_username;

    return true;
}


bool EducationDAO::setCookie(QString cookie) {
    this->cookie = cookie;

    return true;
}


// TODO test me
QList<Education> EducationDAO::readAll() {
    QList<Education> return_list;
    Education 		temp_object;
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

        QString edu = jobj["req_education"].toString();
        int e = 0;

        if(edu == "BASIC") {
            e = 1;
        }
        else if(edu == "JUNIOR_SPECIALIST") {
            e = 2;
        }
        else if(edu == "HIGHER_EDUCATION") {
            e = 3;
        }
        else if(edu == "SEVERAL_HIGHER_EDUCATION") {
            e = 4;
        }
        else if(edu == "CANDIDATE_OF_SCIENCES") {
            e = 5;
        }
        else if(edu == "STUDYING") {
            e = 6;
        }

        temp_object.setId(jobj["id"].toInt());
        temp_object.setTitle(jobj["title"].toString());
        temp_object.setDescription(jobj["description"].toString());
        temp_object.setFor_time_start(jobj["for_time_start"].toString());
        temp_object.setFor_time_end(jobj["for_time_end"].toString());
        temp_object.setReq_experience(jobj["req_experience"].toInt());
        temp_object.setOption_condition(jobj["option_condition"].toString());
        temp_object.setCity(jobj["city"].toString());
        temp_object.setLocation(jobj["location"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setCompany(jobj["company"].toString());
        temp_object.setReq_education(e);
        temp_object.setOwner(jobj["owner"].toString());

        return_list.append(temp_object);
    }

    Log::info("EducationDAO::readAll status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


// TODO maybe remove this
QList<Education> EducationDAO::readById(const int id) {
    return QList<Education>();

}


// TODO test me
QList<Education> EducationDAO::readWithPagination(const int page, const int item_in_page, const QString username) {
    QList<Education> return_list;
    Education 		temp_object;
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

        QString edu = jobj["req_education"].toString();
        int e = 0;

        if(edu == "BASIC") {
            e = 1;
        }
        else if(edu == "JUNIOR_SPECIALIST") {
            e = 2;
        }
        else if(edu == "HIGHER_EDUCATION") {
            e = 3;
        }
        else if(edu == "SEVERAL_HIGHER_EDUCATION") {
            e = 4;
        }
        else if(edu == "CANDIDATE_OF_SCIENCES") {
            e = 5;
        }
        else if(edu == "STUDYING") {
            e = 6;
        }

        temp_object.setId(jobj["id"].toInt());
        temp_object.setTitle(jobj["title"].toString());
        temp_object.setDescription(jobj["description"].toString());
        temp_object.setFor_time_start(jobj["for_time_start"].toString());
        temp_object.setFor_time_end(jobj["for_time_end"].toString());
        temp_object.setReq_experience(jobj["req_experience"].toInt());
        temp_object.setOption_condition(jobj["option_condition"].toString());
        temp_object.setCity(jobj["city"].toString());
        temp_object.setLocation(jobj["location"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setCompany(jobj["company"].toString());
        temp_object.setReq_education(e);
        temp_object.setOwner(jobj["owner"].toString());

        return_list.append(temp_object);
    }

    Log::info("EducationDAO::read with pagination status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


bool EducationDAO::initRequest(QString path) {
    Log::info("EducationDAO::initRequest URL => " + this->host + ":" + this->port + path);
    Log::info("EducationDAO::initRequest cookie => " + this->cookie);

    this->request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QVariant::fromValue(false));
    this->request.setUrl(QUrl(this->host + ":" + this->port + path));
    this->request.setRawHeader("Cookie", QByteArray::fromStdString("JSESSIONID=" + this->cookie.toStdString() + "; HttpOnly; path=/"));

    return true;
}


QNetworkReply *EducationDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


// TODO test me
bool EducationDAO::create(const Education new_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QNetworkReply* 	reply;
    QByteArray 		json;

    jobj["title"] = new_object.getTitle();
    jobj["description"] = new_object.getDescription();
    jobj["for_time_start"] = new_object.getFor_time_start();
    jobj["for_time_end"] = new_object.getFor_time_end();
    jobj["req_experience"] = new_object.getReq_experience();
    jobj["option_condition"] = new_object.getOption_condition();
    jobj["city"] = new_object.getCity();
    jobj["location"] = new_object.getLocation();
    jobj["phone"] = new_object.getPhone();
    jobj["email"] = new_object.getEmail();
    jobj["company"] = new_object.getCompany();
    jobj["req_education"] = new_object.getReq_education();
    jobj["owner"] = new_object.getOwner();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_create);
    reply = this->send("POST", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("EducationDAO::create status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());
    reply->deleteLater();

    return true;
}


// TODO test me
QList<Education> EducationDAO::read(const int read_of, int option, QString filter) {
    if(read_of == -1) {
        return this->readAll();
    }
    else if(option != -1) {
        return this->readWithPagination(read_of, option, filter);
    }

    QList<Education> return_list;
    Education 		temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;

    this->initRequest(this->path_read + QString::number(read_of));
    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jobj = QJsonDocument::fromJson(reply->readAll()).object();

    QString edu = jobj["req_education"].toString();
    int e = 0;

    if(edu == "BASIC") {
        e = 1;
    }
    else if(edu == "JUNIOR_SPECIALIST") {
        e = 2;
    }
    else if(edu == "HIGHER_EDUCATION") {
        e = 3;
    }
    else if(edu == "SEVERAL_HIGHER_EDUCATION") {
        e = 4;
    }
    else if(edu == "CANDIDATE_OF_SCIENCES") {
        e = 5;
    }
    else if(edu == "STUDYING") {
        e = 6;
    }
    else {
        e = 0;
    }

    temp_object.setId(jobj["id"].toInt());
    temp_object.setTitle(jobj["title"].toString());
    temp_object.setDescription(jobj["description"].toString());
    temp_object.setFor_time_start(jobj["for_time_start"].toString());
    temp_object.setFor_time_end(jobj["for_time_end"].toString());
    temp_object.setReq_experience(jobj["req_experience"].toInt());
    temp_object.setOption_condition(jobj["option_condition"].toString());
    temp_object.setCity(jobj["city"].toString());
    temp_object.setLocation(jobj["location"].toString());
    temp_object.setPhone(jobj["phone"].toString());
    temp_object.setEmail(jobj["email"].toString());
    temp_object.setCompany(jobj["company"].toString());
    temp_object.setReq_education(e);
    temp_object.setOwner(jobj["owner"].toString());

    return_list.append(temp_object);

    Log::info("EducationDAO::read status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


// TODO test me
bool EducationDAO::update(const int update_of, const Education updated_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QByteArray 		json;
    QNetworkReply* 	reply;

    jobj["title"] = updated_object.getTitle();
    jobj["description"] = updated_object.getDescription();
    jobj["for_time_start"] = updated_object.getFor_time_start();
    jobj["for_time_end"] = updated_object.getFor_time_end();
    jobj["req_experience"] = updated_object.getReq_experience();
    jobj["option_condition"] = updated_object.getOption_condition();
    jobj["city"] = updated_object.getCity();
    jobj["location"] = updated_object.getLocation();
    jobj["phone"] = updated_object.getPhone();
    jobj["email"] = updated_object.getEmail();
    jobj["company"] = updated_object.getCompany();
    jobj["req_education"] = updated_object.getReq_education();
    jobj["owner"] = updated_object.getOwner();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_update + QString::number(update_of));
    reply = this->send("PATCH", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("EducationDAO::update status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}


// TODO test me
bool EducationDAO::remove(const int remove_of) {
    QEventLoop 		loop;
    QNetworkReply* 	reply;

    this->initRequest(this->path_remove + QString::number(remove_of));
    reply = this->send("DELETE", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("EducationDAO::delete status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}
