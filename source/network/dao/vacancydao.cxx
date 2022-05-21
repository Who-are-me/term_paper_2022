#include "vacancydao.hxx"


VacancyDAO::VacancyDAO(){

}


VacancyDAO::VacancyDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {

}


bool VacancyDAO::init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {
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
