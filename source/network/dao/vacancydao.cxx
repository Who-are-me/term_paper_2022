#include "vacancydao.hxx"


VacancyDAO::VacancyDAO(){
    init();
}


VacancyDAO::VacancyDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    init();
}


VacancyDAO::~VacancyDAO() {
    delete manager;
}


void VacancyDAO::init() {
    this->manager = new QNetworkAccessManager();
}


bool VacancyDAO::init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) {
    return true;
}


bool VacancyDAO::setCookie(QString cookie) {
    return true;
}


QList<Vacancy> VacancyDAO::readAll() {
    return QList<Vacancy>();
}


QList<Vacancy> VacancyDAO::readById(const int id) {
    return QList<Vacancy>();
}


QList<Vacancy> VacancyDAO::readWithPagination(const int page, const int item_in_page) {
    return QList<Vacancy>();
}


bool VacancyDAO::initRequest(QString path) {
    return true;
}


QNetworkReply *VacancyDAO::send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {
    return manager->sendCustomRequest(request, method.toUtf8(), send_data);
}


bool VacancyDAO::create(const Vacancy new_object) {
    return true;
}


QList<Vacancy> VacancyDAO::read(const int read_of, int option) {
    return QList<Vacancy>();
}


bool VacancyDAO::update(const int update_of, const Vacancy updated_object) {
    return true;
}


bool VacancyDAO::remove(const int remove_of) {
    return true;
}
