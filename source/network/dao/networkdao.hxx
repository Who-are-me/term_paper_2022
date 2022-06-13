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
    NetworkDAO() {};
    virtual ~NetworkDAO() {};

    virtual bool setCookie(QString new_cookie) {};

protected:
    QNetworkAccessManager	*manager;
    QNetworkRequest			request;
    QString 				host;
    QString 				port;
    QString 				path_create;
    QString 				path_read;
    QString 				path_read_all;
    QString 				path_read_pag;
    QString 				path_read_pag_by_username;
    QString 				path_update;
    QString 				path_remove;
    // TODO make maybe static cookie for all children classes
    QString 				cookie;

    virtual bool initRequest(QString path) {};
    virtual QNetworkReply* send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) {};
};

