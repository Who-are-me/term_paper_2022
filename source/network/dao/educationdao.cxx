#include "educationdao.hxx"


EducationDAO::EducationDAO() {

}


EducationDAO::EducationDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {

}


EducationDAO::~EducationDAO() {
    delete request;
    delete manager_create;
    delete manager_read;
    delete manager_update;
    delete manager_remove;
}


bool EducationDAO::init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {
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
