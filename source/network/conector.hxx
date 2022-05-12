#pragma once


#include <QObject>
#include <QtNetwork/QtNetwork>


// TODO make me
class Conector : public QObject {
    Q_OBJECT

private:
    QNetworkAccessManager   *manager;
    QNetworkRequest         request;

public:
    Conector();
    ~Conector();

    bool login(QString username, QString password);
};

