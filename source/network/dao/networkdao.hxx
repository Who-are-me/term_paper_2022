#pragma once

#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QString>

#include "dao.hxx"


// this class implement crud pattern
// T1 working object
// T2 type of value for search
template<typename T1, typename T2>
class NetworkDAO : public DAO<T1, T2> {
public:
    NetworkDAO();
    ~NetworkDAO();

protected:
    QString create_url;
    QString read_url;
    QString update_url;
    QString remove_url;
    QString cookies;

    QNetworkRequest 		*request;
    QNetworkAccessManager 	*manager_create;
    QNetworkAccessManager 	*manager_read;
    QNetworkAccessManager 	*manager_update;
    QNetworkAccessManager 	*manager_remove;
};

