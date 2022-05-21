#include "networkdao.hxx"


// it's abstract class
template<typename T1, typename T2>
NetworkDAO<T1, T2>::NetworkDAO() {
    this->request = new QNetworkRequest();
    this->manager_create = new QNetworkAccessManager();
    this->manager_read = new QNetworkAccessManager();
    this->manager_update = new QNetworkAccessManager();
    this->manager_remove = new QNetworkAccessManager();
}


template<typename T1, typename T2>
NetworkDAO<T1, T2>::~NetworkDAO() {
    delete request;
    delete manager_create;
    delete manager_read;
    delete manager_update;
    delete manager_remove;
}
