#include "resumedao.hxx"


ResumeDAO::ResumeDAO() {
    init();
}


ResumeDAO::ResumeDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    init();
}


ResumeDAO::~ResumeDAO() {
    delete manager;
}


void ResumeDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool ResumeDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    return true;
}


bool ResumeDAO::setCookie(QString cookie) {
    return true;
}


QList<Resume> ResumeDAO::readAll() {
    return QList<Resume>();
}


QList<Resume> ResumeDAO::readById(const int id) {
    return QList<Resume>();
}


QList<Resume> ResumeDAO::readWithPagination(const int page, const int item_in_page) {
    return QList<Resume>();
}


bool ResumeDAO::initRequest(QString path) {
    return true;
}


QNetworkReply *ResumeDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


bool ResumeDAO::create(const Resume new_object) {
    return true;
}


QList<Resume> ResumeDAO::read(const int read_of, int option) {
    return QList<Resume>();
}


bool ResumeDAO::update(const int update_of, const Resume updated_object) {
    return true;
}


bool ResumeDAO::remove(const int remove_of) {
    return true;
}
