#pragma once


#include <QObject>
#include <QtNetwork/QtNetwork>


// TODO make me
class Conector : public QObject {
private:
    Q_OBJECT

    QNetworkAccessManager   *manager;
    QNetworkRequest         request;

public:
    Conector();
    ~Conector();
};

