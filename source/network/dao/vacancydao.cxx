#include "log.hxx"
#include "vacancydao.hxx"


VacancyDAO::VacancyDAO(){
    init();
}


VacancyDAO::VacancyDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    init();
}


VacancyDAO::~VacancyDAO() {
    delete manager;
}


void VacancyDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool VacancyDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    this->host = host;
    this->port = port;
    this->path_create = path_create;
    this->path_read = path_read;
    this->path_update = path_update;
    this->path_remove = path_remove;

    return true;
}


bool VacancyDAO::initAdditionalPaths(QString path_read_all, QString path_read_pag, QString path_read_pag_by_username) {
    this->path_read_all = path_read_all;
    this->path_read_pag = path_read_pag;
    this->path_read_pag_by_username = path_read_pag_by_username;

    return true;
}


bool VacancyDAO::setCookie(QString cookie) {
    this->cookie = cookie;

    return true;
}


// TODO test me
QList<Vacancy> VacancyDAO::readAll() {
    QList<Vacancy> 	return_list;
    Vacancy 		temp_object;
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

        QString edu = jobj["education"].toString();
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
        temp_object.setSalary(jobj["salary"].toInt());
        temp_object.setEducation(e);
        temp_object.setExperience(QString::number(jobj["experience"].toInt()).toInt());
        temp_object.setCity(jobj["city"].toString());
        temp_object.setLocation(jobj["location"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setCompany(jobj["company"].toString());
        temp_object.setOwner(jobj["owner"].toString());

        return_list.append(temp_object);
    }

    Log::info("VacancyDAO::readAll status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


// TODO maybe remove this
QList<Vacancy> VacancyDAO::readById(const int id) {
    return QList<Vacancy>();
}


// TODO test me
QList<Vacancy> VacancyDAO::readWithPagination(const int page, const int item_in_page, QString username) {
    QList<Vacancy> 	return_list;
    Vacancy 		temp_object;
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

        QString edu = jobj["education"].toString();
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
        temp_object.setSalary(jobj["salary"].toInt());
        temp_object.setEducation(e);
        temp_object.setExperience(jobj["experience"].toInt());
        temp_object.setCity(jobj["city"].toString());
        temp_object.setLocation(jobj["location"].toString());
        temp_object.setPhone(jobj["phone"].toString());
        temp_object.setEmail(jobj["email"].toString());
        temp_object.setCompany(jobj["company"].toString());
        temp_object.setOwner(jobj["owner"].toString());

        return_list.append(temp_object);
    }

    Log::info("VacancyDAO::read with pagination status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


bool VacancyDAO::initRequest(QString path) {
    Log::info("VacancyDAO::initRequest URL => " + this->host + ":" + this->port + path);
    Log::info("VacancyDAO::initRequest cookie => " + this->cookie);

    this->request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QVariant::fromValue(false));
    this->request.setUrl(QUrl(this->host + ":" + this->port + path));
    this->request.setRawHeader("Cookie", QByteArray::fromStdString("JSESSIONID=" + this->cookie.toStdString() + "; HttpOnly; path=/"));

    return true;
}


QNetworkReply *VacancyDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


// TODO test me
bool VacancyDAO::create(const Vacancy new_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QNetworkReply* 	reply;
    QByteArray 		json;

    jobj["title"] = new_object.getTitle();
    jobj["description"] = new_object.getDescription();
    jobj["salary"] = new_object.getSalary();
    jobj["education"] = new_object.getEducation();
    jobj["experience"] = new_object.getExperience();
    jobj["city"] = new_object.getCity();
    jobj["location"] = new_object.getLocation();
    jobj["phone"] = new_object.getPhone();
    jobj["email"] = new_object.getEmail();
    jobj["company"] = new_object.getCompany();
    jobj["owner"] = new_object.getOwner();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_create);
    reply = this->send("POST", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("VacancyDAO::create status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());
    reply->deleteLater();

    return true;
}


// TODO test me
QList<Vacancy> VacancyDAO::read(const int read_of, int option, QString filter) {
    if(read_of == -1) {
        return this->readAll();
    }
    else if(option != -1) {
        return this->readWithPagination(read_of, option, filter);
    }

    QList<Vacancy> 	return_list;
    Vacancy 		temp_object;
    QJsonObject		jobj;
    QEventLoop 		loop;
    QNetworkReply* 	reply;

    this->initRequest(this->path_read + QString::number(read_of));
    reply = this->send("GET", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    jobj = QJsonDocument::fromJson(reply->readAll()).object();

    QString edu = jobj["education"].toString();
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
    temp_object.setSalary(jobj["salary"].toInt());
    temp_object.setEducation(e);
    temp_object.setExperience(jobj["experience"].toInt());
    temp_object.setCity(jobj["city"].toString());
    temp_object.setLocation(jobj["location"].toString());
    temp_object.setPhone(jobj["phone"].toString());
    temp_object.setEmail(jobj["email"].toString());
    temp_object.setCompany(jobj["company"].toString());
    temp_object.setOwner(jobj["owner"].toString());

    return_list.append(temp_object);

    Log::info("VacancyDAO::read status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return return_list;
}


// TODO test me
bool VacancyDAO::update(const int update_of, const Vacancy updated_object) {
    QEventLoop 		loop;
    QJsonObject 	jobj;
    QByteArray 		json;
    QNetworkReply* 	reply;

    jobj["title"] = updated_object.getTitle();
    jobj["description"] = updated_object.getDescription();
    jobj["salary"] = updated_object.getSalary();
    jobj["education"] = updated_object.getEducation();
    jobj["experience"] = updated_object.getExperience();
    jobj["city"] = updated_object.getCity();
    jobj["location"] = updated_object.getLocation();
    jobj["phone"] = updated_object.getPhone();
    jobj["email"] = updated_object.getEmail();
    jobj["company"] = updated_object.getCompany();
    jobj["owner"] = updated_object.getOwner();

    QJsonDocument jdoc(jobj);
    json = jdoc.toJson();

    this->request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    this->initRequest(this->path_update + QString::number(update_of));
    reply = this->send("PATCH", this->manager, this->request, json);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("VacancyDAO::update status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}


// TODO test me
bool VacancyDAO::remove(const int remove_of) {
    QEventLoop 		loop;
    QNetworkReply* 	reply;

    this->initRequest(this->path_remove + QString::number(remove_of));
    reply = this->send("DELETE", this->manager, this->request, "");

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    Log::info("VacancyDAO::delete status code: " + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toByteArray());

    reply->deleteLater();

    return true;
}
