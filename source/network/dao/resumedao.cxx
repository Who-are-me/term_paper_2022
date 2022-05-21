#include "resumedao.hxx"


ResumeDAO::ResumeDAO() {

}


ResumeDAO::ResumeDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {

}


ResumeDAO::~ResumeDAO() {

}


bool ResumeDAO::init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) {
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
