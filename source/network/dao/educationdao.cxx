#include "educationdao.hxx"


EducationDAO::EducationDAO() {
    init();
}


EducationDAO::EducationDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    init();
}


EducationDAO::~EducationDAO() {
    delete manager;
}


void EducationDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool EducationDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    return true;
}


bool EducationDAO::setCookie(QString cookie) {
    return true;
}


QList<Education> EducationDAO::readAll() {
    return QList<Education>();
}


QList<Education> EducationDAO::readById(const int id) {
    return QList<Education>();

}


QList<Education> EducationDAO::readWithPagination(const int page, const int item_in_page) {
    return QList<Education>();
}


bool EducationDAO::initRequest(QString path) {
    return true;
}


QNetworkReply *EducationDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


bool EducationDAO::create(const Education new_object) {
    return true;
}


QList<Education> EducationDAO::read(const int read_of, int option) {
    return QList<Education>();
}


bool EducationDAO::update(const int update_of, const Education updated_object) {
    return true;
}


bool EducationDAO::remove(const int remove_of) {
    return true;
}
