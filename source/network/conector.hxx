#pragma once


#include <QObject>
#include <QtNetwork/QtNetwork>
#include "cookiesmanager.hxx"


// TODO make me
class Conector : public QObject {
    Q_OBJECT

private:
    QNetworkAccessManager   *manager;
    QNetworkRequest         request;
    CookiesManager			cookies_manager;

public:
    Conector();
    ~Conector();

    bool login(QString username, QString password);
};

